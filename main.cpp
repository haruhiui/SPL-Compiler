#include <fstream>
#include "Ast.hpp" 
#include "Generator.hpp"
#include "y.tab.hpp"
extern int yyparse();

// Defined in spl.y
extern Program *root;

int main(int argc, char **argv) 
{
    // spl test.spl
    if (argc < 2) {
        cout << "Please specify the target file name, such as ***.spl" << endl;
        return 0;
    } else if (argc > 2){
        cout << "It's ok, but only '" << argv[1] << "' will be complied" << endl;
    }
    // redirect stdin to file
    freopen(argv[1],"r",stdin);

    yyparse();
    
    // generate parseTree json for visualization
    ofstream os("parseTree.json");

    os << root->jsonGen() << endl;

    Generator generator;

    generator.generate(*root);
    
    try {
        system("llc -filetype=obj output.ll"); 
        system("clang output.o");
        cout << "[+] Successfully generate a.out from '"<< argv[1] <<"', now you can directly run ./a.out" << endl;
    } catch (exception e){
        cout << "[x] Somthing wrong when generating a.out" << endl;
    }
        
    return 0;
}
