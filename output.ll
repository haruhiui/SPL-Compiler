; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a = global i32 0
@e = global double 0.000000e+00
@d = global i8 0
@.str = constant [5 x i8] c"%lf\0A\00"

define void @main() {
entrypoint:
  store double 2.000000e+00, double* @e
  %tmp = load double, double* @e
  %sqrt = call double @sqrt(double %tmp) #1
  %0 = fcmp oge double %tmp, 0.000000e+00
  br i1 %0, label %entrypoint.split, label %call.sqrt

call.sqrt:                                        ; preds = %entrypoint
  %1 = call double @sqrt(double %tmp)
  br label %entrypoint.split

entrypoint.split:                                 ; preds = %entrypoint, %call.sqrt
  %2 = phi double [ %sqrt, %entrypoint ], [ %1, %call.sqrt ]
  store double %2, double* @e
  %tmp1 = load double, double* @e
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i32 0, i32 0), double %tmp1)
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

define double @sqrt(double %res) {
entrypoint:
  %resAddr = alloca double
  store double %res, double* %resAddr
  %c = load double, double* %resAddr
  br label %cond

cond:                                             ; preds = %loop, %entrypoint
  %res1 = load double, double* %resAddr
  %delta = fmul double %res1, 1.000000e-08
  %cdivt = fdiv double %c, %res1
  %diff1 = fsub double %res1, %cdivt
  %diff2 = fsub double %cdivt, %res1
  %cmp1 = fcmp ogt double %diff1, %delta
  %cmp2 = fcmp ogt double %diff2, %delta
  %any = or i1 %cmp1, %cmp2
  br i1 %any, label %loop, label %afterLoop

loop:                                             ; preds = %cond
  %add = fadd double %cdivt, %res1
  %newres = fdiv double %add, 2.000000e+00
  store double %newres, double* %resAddr
  br label %cond

afterLoop:                                        ; preds = %cond
  ret double %newres
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
attributes #1 = { readnone }
