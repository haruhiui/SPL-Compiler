; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@i = global i32 0
@.str = constant [4 x i8] c"%d\0A\00"
@.str.1 = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  store i32 1, i32* @i
  br label %cond

cond:                                             ; preds = %loop, %entrypoint
  %tmp = load i32, i32* @i
  %0 = icmp sle i32 %tmp, 3
  %forCond = icmp ne i1 %0, false
  br i1 %forCond, label %loop, label %afterLoop

loop:                                             ; preds = %cond
  %tmp1 = load i32, i32* @i
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp1)
  %1 = add i32 %tmp, 1
  store i32 %1, i32* @i
  br label %cond

afterLoop:                                        ; preds = %cond
  br label %cond2

cond2:                                            ; preds = %loop3, %afterLoop
  %tmp5 = load i32, i32* @i
  %tmpSGT = icmp sgt i32 %tmp5, 0
  %whileCond = icmp ne i1 %tmpSGT, false
  br i1 %whileCond, label %loop3, label %afterLoop4

loop3:                                            ; preds = %cond2
  %tmp6 = load i32, i32* @i
  %printf7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %tmp6)
  %tmp8 = load i32, i32* @i
  %subtmpi = sub i32 %tmp8, 1
  store i32 %subtmpi, i32* @i
  br label %cond2

afterLoop4:                                       ; preds = %cond2
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
