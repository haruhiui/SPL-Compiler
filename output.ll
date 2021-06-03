; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@ic = constant i32 1
@rc = constant double 1.234000e+00
@bc = constant i1 false
@cc = constant i8 99
@0 = private unnamed_addr constant [4 x i8] c"\90\94]\00", align 1
@sc = constant i8 getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0)
@iv = global i32 0
@rv = global double 0.000000e+00
@bv = global i1 false
@cv = global i8 0
@.str = constant [4 x i8] c"%c\0A\00"

define void @main() {
entrypoint:
  store i32 5, i32* @iv
  store double 3.124000e+00, double* @rv
  store i1 false, i1* @bv
  store i8 97, i8* @cv
  %tmp = load i8, i8* @sc
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8 %tmp)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
