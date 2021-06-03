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
@0 = private unnamed_addr constant [5 x i8] c"asdf\00", align 1
@.str = constant [4 x i8] c"%d\0A\00"
@.str.1 = constant [5 x i8] c"%lf\0A\00"
@.str.2 = constant [4 x i8] c"%d\0A\00"
@.str.3 = constant [4 x i8] c"%c\0A\00"
@.str.4 = constant [4 x i8] c"%d\0A\00"
@.str.5 = constant [5 x i8] c"%lf\0A\00"
@.str.6 = constant [4 x i8] c"%d\0A\00"
@.str.7 = constant [4 x i8] c"%c\0A\00"
@.str.8 = constant [4 x i8] c"%s\0A\00"
@1 = private unnamed_addr constant [5 x i8] c"qwer\00", align 1
@.str.9 = constant [4 x i8] c"%s\0A\00"

define void @main() {
entrypoint:
  store i32 5, i32* @iv
  store double 3.124000e+00, double* @rv
  store i1 false, i1* @bv
  store i8 97, i8* @cv
  store i8* getelementptr inbounds ([5 x i8], [5 x i8]* @0, i32 0, i32 0), i8** @sv
  %tmp = load i32, i32* @ic
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp)
  %tmp1 = load double, double* @rc
  %printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i32 0, i32 0), double %tmp1)
  %tmp3 = load i1, i1* @bc
  %printf4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), i1 %tmp3)
  %tmp5 = load i8, i8* @cc
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i8 %tmp5)
  %tmp7 = load i32, i32* @iv
  %printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i32 0, i32 0), i32 %tmp7)
  %tmp9 = load double, double* @rv
  %printf10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.5, i32 0, i32 0), double %tmp9)
  %tmp11 = load i1, i1* @bv
  %printf12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.6, i32 0, i32 0), i1 %tmp11)
  %tmp13 = load i8, i8* @cv
  %printf14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.7, i32 0, i32 0), i8 %tmp13)
  %tmp15 = load i8*, i8** @sv
  %printf16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.8, i32 0, i32 0), i8* %tmp15)
  %printf17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.9, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @1, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
