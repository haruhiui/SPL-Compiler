; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a = global i32 0
@d = global i32 0
@b = global i32 0
@c = global double 0.000000e+00
@e = global double 0.000000e+00
@.str = constant [4 x i8] c"%d\0A\00"
@.str.1 = constant [5 x i8] c"%lf\0A\00"

define void @main() {
entrypoint:
  store i32 -338, i32* @a
  store i32 -2, i32* @b
  store i32 4, double* @c
  %tmp = load i32, i32* @b
  %sqr = call i32 @sqr(i32 %tmp)
  store i32 %sqr, i32* @d
  store double 7.200000e+00, double* @e
  %tmp1 = load i32, i32* @d
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp1)
  %tmp2 = load double, double* @e
  %sqrr = call double @sqrr(double %tmp2)
  store double %sqrr, double* @c
  %tmp3 = load double, double* @c
  %printf4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i32 0, i32 0), double %tmp3)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

declare i32 @abs(i32)

declare i8 @chr(i32)

declare i32 @odd(i32)

declare i32 @ord(i32)

declare i32 @pred(i32)

define i32 @sqr(i32 %tmpa) {
entrypoint:
  %multmpi = mul i32 %tmpa, %tmpa
  ret i32 %multmpi
}

declare double @sqrt(double)

declare i32 @succ(i32)

define double @sqrr(double %tmpa) {
entrypoint:
  %multmpr = fmul double %tmpa, %tmpa
  ret double %multmpr
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
