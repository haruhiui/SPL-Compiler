; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@f = global i32 0
@k = global i32 0
@.str = constant [4 x i8] c"%d\0A\00"
@.str.1 = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  store i32 0, i32* @k
  %calltmp = call i32 @go(i32* @k, i32 5)
  store i32 %calltmp, i32* @f
  %tmp = load i32, i32* @f
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp)
  %tmp1 = load i32, i32* @k
  %printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %tmp1)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define internal i32 @go(i32* nonnull %0, i32 %1) {
entrypoint:
  %t = alloca double
  %fk = alloca i32
  %go = alloca i32
  %a = alloca i32
  store i32 %1, i32* %a
  %tmp = load i32, i32* %a
  %tmpSGT = icmp sgt i32 %tmp, 0
  %ifCond = icmp ne i1 %tmpSGT, false
  br i1 %ifCond, label %then, label %else

then:                                             ; preds = %entrypoint
  %2 = bitcast i32* %0 to i32*
  %tmp1 = load i32, i32* %a
  %tmp2 = load i32, i32* %a
  %subtmpi = sub i32 %tmp2, 1
  %calltmp = call i32 @go(i32* %2, i32 %subtmpi)
  %multmpi = mul i32 %tmp1, %calltmp
  store i32 %multmpi, i32* %go
  br label %merge

else:                                             ; preds = %entrypoint
  store i32 1, i32* %go
  br label %merge

merge:                                            ; preds = %else, %then
  %3 = bitcast i32* %0 to i32*
  %tmp3 = load i32, i32* %3
  %tmp4 = load i32, i32* %go
  %addtmpi = add i32 %tmp3, %tmp4
  store i32 %addtmpi, i32* %3
  %tmp5 = load i32, i32* @k
  %tmp6 = load i32, i32* %go
  %addtmpi7 = add i32 %tmp5, %tmp6
  store i32 %addtmpi7, i32* @k
  %tmp8 = load i32, i32* %go
  ret i32 %tmp8
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
