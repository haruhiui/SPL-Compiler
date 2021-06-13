; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@ic = constant i32 0
@cc = constant i8 99
@bc = constant i1 false
@rc = constant double 1.234000e+00
@i = global i32 0
@j = global i32 0
@k = global i32 0
@.str = constant [4 x i8] c"%c\0A\00"
@.str.1 = constant [4 x i8] c"%c\0A\00"
@.str.2 = constant [12 x i8] c"%c%c%c%c%c\0A\00"
@.str.3 = constant [4 x i8] c"%d\0A\00"
@.str.4 = constant [4 x i8] c"%d\0A\00"
@.str.5 = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  call void @test_if(i32 2)
  call void @test_case(i32 0)
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

define internal void @test_if(i32 %0) {
entrypoint:
  %j = alloca i32
  %i = alloca i32
  %a = alloca i32
  store i32 %0, i32* %a
  %tmp = load i32, i32* %a
  %1 = icmp eq i32 %tmp, 0
  %ifCond = icmp ne i1 %1, false
  br i1 %ifCond, label %then, label %else

then:                                             ; preds = %entrypoint
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8 48)
  br label %merge

else:                                             ; preds = %entrypoint
  %tmp1 = load i32, i32* %a
  %2 = icmp eq i32 %tmp1, 1
  %ifCond2 = icmp ne i1 %2, false
  br i1 %ifCond2, label %then3, label %else4

merge:                                            ; preds = %merge5, %then
  ret void

then3:                                            ; preds = %else
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i8 49)
  br label %merge5

else4:                                            ; preds = %else
  %printf7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.2, i32 0, i32 0), i8 111, i8 116, i8 104, i8 101, i8 114)
  br label %merge5

merge5:                                           ; preds = %else4, %then3
  br label %merge
}

define internal void @test_case(i32 %0) {
entrypoint:
  %a = alloca i32
  store i32 %0, i32* %a
  %tmp = load i32, i32* %a
  br label %switch

afterCase:                                        ; preds = %case4, %switch3, %case2, %case
  ret void

switch:                                           ; preds = %entrypoint
  %tmp5 = load i32, i32* @ic
  %1 = icmp eq i32 %tmp, %tmp5
  br i1 %1, label %case, label %switch1

case:                                             ; preds = %switch
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i32 0)
  br label %afterCase

switch1:                                          ; preds = %switch
  %2 = icmp eq i32 %tmp, 1
  br i1 %2, label %case2, label %switch3

case2:                                            ; preds = %switch1
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i32 0, i32 0), i32 1)
  br label %afterCase

switch3:                                          ; preds = %switch1
  %3 = icmp eq i32 %tmp, 2
  br i1 %3, label %case4, label %afterCase

case4:                                            ; preds = %switch3
  store i32 1, i32* @i
  store i32 2, i32* @j
  %printf7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.5, i32 0, i32 0), i32 2)
  br label %afterCase
}
