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
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define internal void @test_if(i32 %0) {
entrypoint:
  %j = alloca i32
  %i = alloca i32
  %a = alloca i32
  store i32 %0, i32* %a
  %tmp = load i32, i32* %a
  %tmpEQ = icmp eq i32 %tmp, 0
  %ifCond = icmp ne i1 %tmpEQ, false
  br i1 %ifCond, label %then, label %else

then:                                             ; preds = %entrypoint
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8 48)
  br label %merge

else:                                             ; preds = %entrypoint
  %tmp1 = load i32, i32* %a
  %tmpEQ2 = icmp eq i32 %tmp1, 1
  %ifCond3 = icmp ne i1 %tmpEQ2, false
  br i1 %ifCond3, label %then4, label %else5

merge:                                            ; preds = %then4, %else5, %then
  ret void

then4:                                            ; preds = %else
  %printf7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i8 49)
  br label %merge

else5:                                            ; preds = %else
  %printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.2, i32 0, i32 0), i8 111, i8 116, i8 104, i8 101, i8 114)
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
  %tmpEQ = icmp eq i32 %tmp, %tmp5
  br i1 %tmpEQ, label %case, label %switch1

case:                                             ; preds = %switch
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i32 0)
  br label %afterCase

switch1:                                          ; preds = %switch
  %tmpEQ6 = icmp eq i32 %tmp, 1
  br i1 %tmpEQ6, label %case2, label %switch3

case2:                                            ; preds = %switch1
  %printf7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i32 0, i32 0), i32 1)
  br label %afterCase

switch3:                                          ; preds = %switch1
  %tmpEQ8 = icmp eq i32 %tmp, 2
  br i1 %tmpEQ8, label %case4, label %afterCase

case4:                                            ; preds = %switch3
  store i32 1, i32* @i
  store i32 2, i32* @j
  %printf9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.5, i32 0, i32 0), i32 2)
  br label %afterCase
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
