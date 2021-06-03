# SPL-Compiler 

lex + yacc + llvm 

environment: 
* Ubuntu 20.04 
* flex 2.6.4 
* bison 3.5.1 
* llvm 10.0.0 

## Compile compiler

```
make
```

## Compile SPL programs and Execute 

```
./spl test.spl

// execute IR directly: 
lli output.ll 

// execute the file
./a.out
```

## DAG visualization 

```
llvm-as < spl.ll | opt -analyze -view-cfg
dot *.dot -T png -o dag.png
```

## AST visualization 

```
python ParseTreeVisualizer.py parseTree.json 
# 'parseTree.json' is set as the default file name

```

## Reference 

[llvm tutorila](https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html) 

[SPL-Compiler by czyxm](https://github.com/czyxm/SPL-Compiler)

## TODO

* Allow function be defined in a function.
* Writeln() should support newline.

## Time Line

* 5.26 
    * able to run 
* 5.27 
    * generate object file 
* 5.28 
    * solved: support comments by adding '//' at the start of the comments 
    * solved: procedure must not return anything 
* 5.30
    * add: able to generate parse tree picture
* 6.2
    * add: string type now available when draw pic, but something wrong with write.