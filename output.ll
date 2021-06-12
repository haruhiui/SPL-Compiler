; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a = global i32 0
@b = global i32 0
@c = global i32 0
@d = global i32 0
@e = global i32 0
@f = global i32 0
@.str = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  br label %Label_1

Label_1:                                          ; preds = %afterLabel_2, %entrypoint
  store i32 5, i32* @a
  br label %afterLabel_1

afterLabel_1:                                     ; preds = %Label_1
  store i32 6, i32* @b
  br label %Label_2
  store i32 7, i32* @c
  br label %Label_2

Label_2:                                          ; preds = %afterLabel_1, %afterLabel_1
  store i32 8, i32* @d
  br label %afterLabel_2

afterLabel_2:                                     ; preds = %Label_2
  store i32 9, i32* @e
  %tmp = load i32, i32* @c
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp)
  br label %Label_1
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
  %resAddr = alloca double
  store double %0, double* %resAddr
  %1 = load double, double* %resAddr
  br label %condSqrt

condSqrt:                                         ; preds = %loopSqrt, %startSqrt
  %2 = load double, double* %resAddr
  %3 = fmul double %2, 1.000000e-13
  %4 = fdiv double %1, %2
  %5 = fsub double %2, %4
  %6 = fsub double %4, %2
  %7 = fcmp ogt double %5, %3
  %8 = fcmp ogt double %6, %3
  %9 = or i1 %7, %8
  br i1 %9, label %loopSqrt, label %afterLoopSqrt

loopSqrt:                                         ; preds = %condSqrt
  %10 = fadd double %4, %2
  %11 = fdiv double %10, 2.000000e+00
  store double %11, double* %resAddr
  br label %condSqrt

afterLoopSqrt:                                    ; preds = %condSqrt
  %12 = load double, double* %resAddr
  ret double %12
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

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
