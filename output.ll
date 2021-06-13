; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a = global i32 0
@e = global i32 0
@.str = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  store i32 3, i32* @a
  %tmp = load i32, i32* @a
  %sqr = call i32 @sqr(i32 %tmp)
  store i32 %sqr, i32* @e
  %tmp1 = load i32, i32* @e
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp1)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

declare i32 @abs(i32)

define i8 @chr(i32 %tmpa) {
entrypoint:
  %l8bits = trunc i32 %tmpa to i8
  ret i8 %l8bits
}

define i1 @odd(i32 %tmpa) {
entrypoint:
  %odd = and i32 %tmpa, 1
  %isodd = icmp eq i32 %odd, 1
  ret i1 %isodd
}

define i32 @ord(i8 %tmpa) {
entrypoint:
  %to32bits = zext i8 %tmpa to i32
  ret i32 %to32bits
}

define i32 @pred(i32 %tmpa) {
entrypoint:
  %succ = sub i32 %tmpa, 1
  ret i32 %succ
}

define i32 @sqr(i32 %tmpa) {
entrypoint:
  %multmpi = mul i32 %tmpa, %tmpa
  ret i32 %multmpi
}

define double @sqrt(double %0) {
startSqrt:
  %1 = alloca double
  store double %0, double* %1
  %2 = load double, double* %1
  br label %condSqrt

condSqrt:                                         ; preds = %loopSqrt, %startSqrt
  %3 = load double, double* %1
  %4 = fmul double %3, 1.000000e-13
  %5 = fdiv double %2, %3
  %6 = fsub double %3, %5
  %7 = fsub double %5, %3
  %8 = fcmp ogt double %6, %4
  %9 = fcmp ogt double %7, %4
  %10 = or i1 %8, %9
  br i1 %10, label %loopSqrt, label %afterLoopSqrt

loopSqrt:                                         ; preds = %condSqrt
  %11 = fadd double %5, %3
  %12 = fdiv double %11, 2.000000e+00
  store double %12, double* %1
  br label %condSqrt

afterLoopSqrt:                                    ; preds = %condSqrt
  %13 = load double, double* %1
  ret double %13
}

define i32 @succ(i32 %tmpa) {
entrypoint:
  %succ = add i32 %tmpa, 1
  ret i32 %succ
}

define double @sqrr(double %tmpa) {
entrypoint:
  %multmpr = fmul double %tmpa, %tmpa
  ret double %multmpr
}
