; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@g = global i32 0
@.str = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  call void @varproc(i32* @g)
  %tmp = load i32, i32* @g
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define internal void @add2(i32* nonnull %0) {
entrypoint:
  %a1 = bitcast i32* %0 to i32*
  %tmp = load i32, i32* %a1
  %addtmpi = add i32 %tmp, 6
  store i32 %addtmpi, i32* %a1
  ret void
}

define internal void @varproc(i32* nonnull %0) {
entrypoint:
  %a1 = bitcast i32* %0 to i32*
  call void @add2(i32* %a1)
  ret void
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
