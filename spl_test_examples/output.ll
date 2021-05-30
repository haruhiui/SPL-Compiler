; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@ans = global i32 0
@.str = constant [4 x i8] c"%d\0A\00"

define void @main() {
entrypoint:
  %calltmp = call i32 @gcd(i32 9, i32 36)
  %calltmp1 = call i32 @gcd(i32 3, i32 6)
  %multmpi = mul i32 %calltmp, %calltmp1
  store i32 %multmpi, i32* @ans
  %tmp = load i32, i32* @ans
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define internal i32 @gcd(i32 %0, i32 %1) {
entrypoint:
  %gcd = alloca i32
  %b = alloca i32
  %a = alloca i32
  store i32 %0, i32* %a
  store i32 %1, i32* %b
  %tmp = load i32, i32* %b
  %tmpEQ = icmp eq i32 %tmp, 0
  %ifCond = icmp ne i1 %tmpEQ, false
  br i1 %ifCond, label %then, label %else

then:                                             ; preds = %entrypoint
  %tmp1 = load i32, i32* %a
  store i32 %tmp1, i32* %gcd
  br label %merge

else:                                             ; preds = %entrypoint
  %tmp2 = load i32, i32* %b
  %tmp3 = load i32, i32* %a
  %tmp4 = load i32, i32* %b
  %tmpSREM = srem i32 %tmp3, %tmp4
  %calltmp = call i32 @gcd(i32 %tmp2, i32 %tmpSREM)
  store i32 %calltmp, i32* %gcd
  br label %merge

merge:                                            ; preds = %else, %then
  %tmp5 = load i32, i32* %gcd
  ret i32 %tmp5
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
