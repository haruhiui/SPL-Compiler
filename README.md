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

[llvm structure](https://blog.csdn.net/qq_42570601/article/details/107979539)

[llvm tutorila](https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html) 

[llvm developer reference: include/llvm/IR](https://llvm.org/doxygen/dir_c3e93f23a4a31c717998b98ce143b7c0.html)
[llvm developer reference: lib/IR](https://llvm.org/doxygen/dir_bfcfa2223a05221bedc89835a6573260.html)

[SPL-Compiler by czyxm](https://github.com/czyxm/SPL-Compiler)

[Example](https://blog.csdn.net/qq_42570601/article/details/108059403)

## TODO

* Allow function be defined in a function.

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
* 6.11
    * add: able to generate all system functions
    * feature: using Newton-Raphson method to solve sqrt

## bug fix 

* test_logical.spl: and、not、or 显示错误
    * 原文件中在 if 后面需要加 begin... end，或者将 if 后面的语句的分号去掉才能正常运行，否则会 syntax error 
    * stmt 后面不能加分号，而 stmt_list 才表示用分号区分开的语句组

```
// 原文件
if (((m mod 2) = 0) and ((n mod 2) = 0) or ((m mod 2) = 1) and ((n mod 2) = 1)) then 
    writeln("m and n are both even number or odd number", m); 
else
    writeln("one of m and n is odd while the other is even"); 
```

* fix: div for float, including float div float, float div int, int div float 
    * Ast.cpp: 166, if one of the para is int, convert it to float 

* fix: LLVM: Instruction does not dominate all uses
    * label确定了llvm的参数域，不能跨域访问变量
    * 使用createLoad和createStore的方法实现跨域获取变量

* fix: a.out和lli output.ll 运行结果不一致
    * 换用llvm自带的llc进行目标文件的生成

* fix: 使用const定义数组会出现segment fault的问题
    * 更新constrange的实现
    
* fix: const values in array 

* fix: able to assign integer value to a real type 
    * Ast.hpp:481, lhsValue->getType()->getPointerElementType()->isDoubleTy() 

* fix: support real and integer mixed operation 
    * Ast.hpp:136, if one of the operator is real and the other is integer, then convert the integer one to real 

* fix: support writeln; 
    * Ast.cpp:1065, add size == 0 
