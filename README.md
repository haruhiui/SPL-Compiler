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

// generate executable object file and execute it: 
clang output.o 
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

[llvm developer reference: include/llvm/IR](https://llvm.org/doxygen/dir_c3e93f23a4a31c717998b98ce143b7c0.html)
[llvm developer reference: lib/IR](https://llvm.org/doxygen/dir_bfcfa2223a05221bedc89835a6573260.html)

[SPL-Compiler by czyxm](https://github.com/czyxm/SPL-Compiler)

[Example](https://blog.csdn.net/qq_42570601/article/details/108059403)

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
* 6.2 
    * add: able to write string variable and string constant 


## bug fix 
* test_logical.spl: and、not、or显示错误
    * 原因在于.y中non_label_stmt中分析时选择了compound_stmt而不是proc_stmt，导致if语句的then后面必须要有begin... end