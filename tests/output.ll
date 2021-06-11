; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@m = global i32 0
@n = global i32 0
@a = global i1 false
@0 = private unnamed_addr constant [43 x i8] c"m and n are both even number or odd number\00", align 1
@.str = constant [6 x i8] c"%s%d\0A\00"
@1 = private unnamed_addr constant [46 x i8] c"one of m and n is odd while the other is even\00", align 1
@.str.1 = constant [4 x i8] c"%s\0A\00"
@.str.2 = constant [4 x i8] c"%d\0A\00"
@.str.3 = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  store i32 6, i32* @m
  store i32 8, i32* @n
  %tmp = load i32, i32* @m
  %tmpSREM = srem i32 %tmp, 2
  %tmpEQ = icmp eq i32 %tmpSREM, 0
  %tmp1 = load i32, i32* @n
  %tmpSREM2 = srem i32 %tmp1, 2
  %tmpEQ3 = icmp eq i32 %tmpSREM2, 0
  %tmpAND = and i1 %tmpEQ, %tmpEQ3
  %tmp4 = load i32, i32* @m
  %tmpSREM5 = srem i32 %tmp4, 2
  %tmpEQ6 = icmp eq i32 %tmpSREM5, 1
  %tmp7 = load i32, i32* @n
  %tmpSREM8 = srem i32 %tmp7, 2
  %tmpEQ9 = icmp eq i32 %tmpSREM8, 1
  %tmpAND10 = and i1 %tmpEQ6, %tmpEQ9
  %tmpOR = or i1 %tmpAND, %tmpAND10
  %ifCond = icmp ne i1 %tmpOR, false
  br i1 %ifCond, label %then, label %else

then:                                             ; preds = %entrypoint
  %tmp11 = load i32, i32* @m
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([43 x i8], [43 x i8]* @0, i32 0, i32 0), i32 %tmp11)
  br label %merge

else:                                             ; preds = %entrypoint
  %printf12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i8* getelementptr inbounds ([46 x i8], [46 x i8]* @1, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else, %then
  %tmp13 = load i32, i32* @m
  %tmpEQ14 = icmp eq i32 %tmp13, 6
  %tmpXOR = xor i1 true, %tmpEQ14
  store i1 %tmpXOR, i1* @a
  %tmp15 = load i1, i1* @a
  %printf16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), i1 %tmp15)
  %tmp17 = load i32, i32* @m
  %tmpSGT = icmp sgt i32 %tmp17, 3
  %tmpXOR18 = xor i1 true, %tmpSGT
  store i1 %tmpXOR18, i1* @a
  %tmp19 = load i1, i1* @a
  %printf20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i1 %tmp19)
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
