; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@month = global i32 0
@days = global i32 0
@0 = private unnamed_addr constant [15 x i8] c"Input month : \00", align 1
@.str = constant [3 x i8] c"%s\00"
@1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@2 = private unnamed_addr constant [11 x i8] c"Days is : \00", align 1
@.str.1 = constant [6 x i8] c"%s%d\0A\00"

define void @main() {
entrypoint:
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([15 x i8], [15 x i8]* @0, i32 0, i32 0))
  %tmp = load i32, i32* @month
  %scanf = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i32* @month)
  %tmp1 = load i32, i32* @month
  br label %switch

afterCase:                                        ; preds = %case23, %switch22, %case21, %case19, %case17, %case15, %case13, %case11, %case9, %case7, %case5, %case3, %case
  %tmp24 = load i32, i32* @days
  %0 = icmp ne i32 %tmp24, 0
  %ifCond = icmp ne i1 %0, false
  br i1 %ifCond, label %then, label %else

switch:                                           ; preds = %entrypoint
  %1 = icmp eq i32 %tmp1, 1
  br i1 %1, label %case, label %switch2

case:                                             ; preds = %switch
  store i32 31, i32* @days
  br label %afterCase

switch2:                                          ; preds = %switch
  %2 = icmp eq i32 %tmp1, 2
  br i1 %2, label %case3, label %switch4

case3:                                            ; preds = %switch2
  store i32 28, i32* @days
  br label %afterCase

switch4:                                          ; preds = %switch2
  %3 = icmp eq i32 %tmp1, 3
  br i1 %3, label %case5, label %switch6

case5:                                            ; preds = %switch4
  store i32 31, i32* @days
  br label %afterCase

switch6:                                          ; preds = %switch4
  %4 = icmp eq i32 %tmp1, 4
  br i1 %4, label %case7, label %switch8

case7:                                            ; preds = %switch6
  store i32 30, i32* @days
  br label %afterCase

switch8:                                          ; preds = %switch6
  %5 = icmp eq i32 %tmp1, 5
  br i1 %5, label %case9, label %switch10

case9:                                            ; preds = %switch8
  store i32 31, i32* @days
  br label %afterCase

switch10:                                         ; preds = %switch8
  %6 = icmp eq i32 %tmp1, 6
  br i1 %6, label %case11, label %switch12

case11:                                           ; preds = %switch10
  store i32 30, i32* @days
  br label %afterCase

switch12:                                         ; preds = %switch10
  %7 = icmp eq i32 %tmp1, 7
  br i1 %7, label %case13, label %switch14

case13:                                           ; preds = %switch12
  store i32 31, i32* @days
  br label %afterCase

switch14:                                         ; preds = %switch12
  %8 = icmp eq i32 %tmp1, 8
  br i1 %8, label %case15, label %switch16

case15:                                           ; preds = %switch14
  store i32 31, i32* @days
  br label %afterCase

switch16:                                         ; preds = %switch14
  %9 = icmp eq i32 %tmp1, 9
  br i1 %9, label %case17, label %switch18

case17:                                           ; preds = %switch16
  store i32 30, i32* @days
  br label %afterCase

switch18:                                         ; preds = %switch16
  %10 = icmp eq i32 %tmp1, 10
  br i1 %10, label %case19, label %switch20

case19:                                           ; preds = %switch18
  store i32 31, i32* @days
  br label %afterCase

switch20:                                         ; preds = %switch18
  %11 = icmp eq i32 %tmp1, 11
  br i1 %11, label %case21, label %switch22

case21:                                           ; preds = %switch20
  store i32 30, i32* @days
  br label %afterCase

switch22:                                         ; preds = %switch20
  %12 = icmp eq i32 %tmp1, 12
  br i1 %12, label %case23, label %afterCase

case23:                                           ; preds = %switch22
  store i32 31, i32* @days
  br label %afterCase

then:                                             ; preds = %afterCase
  %tmp25 = load i32, i32* @days
  %printf26 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.1, i32 0, i32 0), i8* getelementptr inbounds ([11 x i8], [11 x i8]* @2, i32 0, i32 0), i32 %tmp25)
  br label %merge

else:                                             ; preds = %afterCase
  br label %merge

merge:                                            ; preds = %else, %then
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
