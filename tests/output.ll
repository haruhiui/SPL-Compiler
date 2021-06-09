; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@ic = constant i32 1
@rc = constant double 1.234000e+00
@bc = constant i1 false
@cc = constant i8 99
@iv = global i32 0
@rv = global double 0.000000e+00
@bv = global i1 false
@cv = global i8 0
@sv = global i8* 0
@num = global i32 0
@.str = constant [4 x i8] c"%s\0A\00"
@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@1 = private unnamed_addr constant [9 x i8] c"    iv: \00", align 1
@.str.1 = constant [5 x i8] c"%s%d\00"
@2 = private unnamed_addr constant [9 x i8] c"    rv: \00", align 1
@.str.2 = constant [6 x i8] c"%s%lf\00"
@3 = private unnamed_addr constant [9 x i8] c"    bv: \00", align 1
@.str.3 = constant [5 x i8] c"%s%d\00"
@4 = private unnamed_addr constant [9 x i8] c"    cv: \00", align 1
@.str.4 = constant [5 x i8] c"%s%c\00"
@5 = private unnamed_addr constant [9 x i8] c"    sv: \00", align 1
@.str.5 = constant [5 x i8] c"%s%s\00"
@6 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@.str.6 = constant [4 x i8] c"%s\0A\00"
@7 = private unnamed_addr constant [5 x i8] c"asdf\00", align 1
@8 = private unnamed_addr constant [5 x i8] c"ic: \00", align 1
@.str.7 = constant [6 x i8] c"%s%d\0A\00"
@9 = private unnamed_addr constant [5 x i8] c"rc: \00", align 1
@.str.8 = constant [7 x i8] c"%s%lf\0A\00"
@10 = private unnamed_addr constant [5 x i8] c"bc: \00", align 1
@.str.9 = constant [6 x i8] c"%s%d\0A\00"
@11 = private unnamed_addr constant [5 x i8] c"cc: \00", align 1
@.str.10 = constant [6 x i8] c"%s%c\0A\00"
@12 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@.str.11 = constant [4 x i8] c"%s\0A\00"
@13 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@14 = private unnamed_addr constant [4 x i8] c"%lf\00", align 1
@15 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@16 = private unnamed_addr constant [3 x i8] c"%c\00", align 1

define void @main() {
entrypoint:
  store i32 5, i32* @iv
  store double 3.124000e+00, double* @rv
  store i1 false, i1* @bv
  store i8 97, i8* @cv
  store i8* getelementptr inbounds ([5 x i8], [5 x i8]* @7, i32 0, i32 0), i8** @sv
  %tmp = load i32, i32* @ic
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.7, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @8, i32 0, i32 0), i32 %tmp)
  %tmp1 = load double, double* @rc
  %printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.8, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @9, i32 0, i32 0), double %tmp1)
  %tmp3 = load i1, i1* @bc
  %printf4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.9, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @10, i32 0, i32 0), i1 %tmp3)
  %tmp5 = load i8, i8* @cc
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.10, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @11, i32 0, i32 0), i8 %tmp5)
  %printf7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.11, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @12, i32 0, i32 0))
  call void @printAll()
  %tmp8 = load i32, i32* @iv
  %scanf = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @13, i32 0, i32 0), i32* @iv)
  %tmp9 = load double, double* @rv
  %scanf10 = call i32 (...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @14, i32 0, i32 0), double* @rv)
  %tmp11 = load i1, i1* @bv
  %scanf12 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @15, i32 0, i32 0), i1* @bv)
  %tmp13 = load i8, i8* @cv
  %scanf14 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @16, i32 0, i32 0), i8* @cv)
  call void @printAll()
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define internal i32 @inputNum(i8* %0) {
entrypoint:
  %inputNum = alloca i32
  %str = alloca i8*
  store i8* %0, i8** %str
  %tmp = load i8*, i8** %str
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* %tmp)
  %tmp1 = load i32, i32* %inputNum
  %scanf = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32* %inputNum)
  %tmp2 = load i32, i32* %inputNum
  ret i32 %tmp2
}

define internal void @printAll() {
entrypoint:
  %tmp = load i32, i32* @iv
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @1, i32 0, i32 0), i32 %tmp)
  %tmp1 = load double, double* @rv
  %printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @2, i32 0, i32 0), double %tmp1)
  %tmp3 = load i1, i1* @bv
  %printf4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @3, i32 0, i32 0), i1 %tmp3)
  %tmp5 = load i8, i8* @cv
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.4, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @4, i32 0, i32 0), i8 %tmp5)
  %tmp7 = load i8*, i8** @sv
  %printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @5, i32 0, i32 0), i8* %tmp7)
  %printf9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.6, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @6, i32 0, i32 0))
  ret void
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
