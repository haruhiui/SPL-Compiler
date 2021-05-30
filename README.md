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
spl < test.spl 

// execute IR directly: 
lli output.ll 

// generate executable object file: 
clang output.o

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
python ParseTreeVisualizer.py tree.json # tree.json can be omitted, by default

```

## Reference 

[llvm tutorila](https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html) 

[SPL-Compiler by czyxm](https://github.com/czyxm/SPL-Compiler)

## TODO

* Allow function be defined in a function

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