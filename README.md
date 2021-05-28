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
spl < test.pas 

// execute IR directly: 
lli output.ll 

// generate executable object file: 
llc output.o
clang output.s 
```

## DAG visualization 

```
llvm-as < spl.ll | opt -analyze -view-cfg
dot *.dot -T png -o dag.png
```

## AST visualization 

todo

## Reference 

[llvm tutorila](https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html) 

<!-- [SPL-Compiler by czyxm](https://github.com/czyxm/SPL-Compiler) -->
