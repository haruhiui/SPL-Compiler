
"""
Usage:  python ParseTreeVisualizer.py <json file path>
        
        By default, it will directly find "parseTree.json" in the current path,
        therefore, you can simply use 
            python ParseTreeVisualizer.py
        to generate the png file.
"""
import os
import sys
import json

node_count = 0
def check_file():
    if len(sys.argv) < 2:
        filename = 'parseTree.json'
    else:
        filename = sys.argv[1]
    if os.path.exists(filename):
        return filename
    return None

def c2w(src:str):
    return src.replace('+','PLUS')\
        .replace('-','MINUS')\
        .replace('*','MUL')\
        .replace('/','DIV')\
        .replace('%','MOD')\
        .replace('.','DOT')\
        .replace('<','LEFTLESS')\
        .replace('>','RIGHTGREATER')\
        .replace('=','EQUALS')\
        .replace(':','COLON')\
        .replace(';','SEMICOLON')
        
def w2c(src:str):
    return src.replace('PLUS','+')\
        .replace('MINUS','-')\
        .replace('MUL','*')\
        .replace('DIV','/')\
        .replace('MOD','%')\
        .replace('DOT','.')\
        .replace('LEFTLESS','<')\
        .replace('RIGHTGREATER','>')\
        .replace('EQUALS','=')\
        .replace('COLON',':')\
        .replace('SEMICOLON',';')

def add_node(node_name,children_list,res):
    index = node_name.rfind('_')
    label = f' [label="{node_name[4:index]}"]'
    label = w2c(label)
    res.append(node_name+label)
    for node in children_list:
        raw_name :str = node['name']
        res.append(f'{node_name} -> {raw_name}')
        if 'children' in node.keys():
            add_node(raw_name,node['children'],res)
        else:
            index = raw_name.rfind('_')
            label = f' [label="{raw_name[4:index]}"]'
            label = w2c(label)
            res.append(raw_name+label)

def rename_node(content:dict):
    global node_count
    content['name'] += f'_{node_count}'
    content['name'] = 'Node' + content['name']
    content['name'] = c2w(content['name'])


    node_count+=1
    if 'children' in content.keys():
        for node in content['children']:
            rename_node(node)

def visualize(content:dict):
    try:
        program_name = content['value']
        dot = open(f'{program_name}_ast.dot','w',encoding='utf-8')
        res = []
        res.append(f'digraph "Visulization for ast of {program_name}"{{')
        res.append(f'label="Visulization for ast of {program_name}";')

        # handle children here
        rename_node(content)
        add_node(content['name'],content['children'],res)

        # format res
        res.append(f'}}')
        for i in range(len(res)):
            res[i] += '\n'
            if i != 0 and i != len(res)-1:
                res[i] = '    ' + res[i]
        dot.writelines(res)
        dot.close()
        return program_name
    except:
        exit('Invalid json!')

if __name__ == '__main__':

    filename = check_file()
    if  filename is None:
        exit('Target file not found!')
    
    with open(filename,'r',encoding='utf-8') as file:
        content = json.loads(file.readline())
    
    program_name = visualize(content)


    os.system(f'dot {program_name}_ast.dot -Tpng -o {program_name}_ast.png')
