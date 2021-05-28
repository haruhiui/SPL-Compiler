	.text
	.file	"main"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entrypoint
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %rbp, -16
	movl	r(%rip), %r14d
	movl	l(%rip), %ebx
	movl	%ebx, iv(%rip)
	.p2align	4, 0x90
.LBB0_1:                                # %cond
                                        # =>This Inner Loop Header: Depth=1
	movl	iv(%rip), %ebp
	cmpl	%r14d, %ebp
	jg	.LBB0_3
# %bb.2:                                # %loop
                                        #   in Loop: Header=BB0_1 Depth=1
	movl	iv(%rip), %esi
	movl	%ebx, %eax
	subl	%ebx, %eax
	cltq
	movl	%esi, a(,%rax,4)
	movl	$.str, %edi
	xorl	%eax, %eax
	callq	printf
	incl	%ebp
	movl	%ebp, iv(%rip)
	jmp	.LBB0_1
.LBB0_3:                                # %afterLoop
	subl	%ebx, %ebx
	incl	%ebx
	movslq	%ebx, %rax
	movl	$8, a(,%rax,4)
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	ic,@object              # @ic
	.section	.rodata,"a",@progbits
	.globl	ic
	.p2align	2
ic:
	.long	1                       # 0x1
	.size	ic, 4

	.type	l,@object               # @l
	.globl	l
	.p2align	2
l:
	.long	1                       # 0x1
	.size	l, 4

	.type	r,@object               # @r
	.globl	r
	.p2align	2
r:
	.long	6                       # 0x6
	.size	r, 4

	.type	rc,@object              # @rc
	.globl	rc
	.p2align	3
rc:
	.quad	4609434218613702656     # double 1.5
	.size	rc, 8

	.type	bc,@object              # @bc
	.globl	bc
bc:
	.byte	0                       # 0x0
	.size	bc, 1

	.type	cc,@object              # @cc
	.globl	cc
cc:
	.byte	97                      # 0x61
	.size	cc, 1

	.type	iv,@object              # @iv
	.bss
	.globl	iv
	.p2align	2
iv:
	.long	0                       # 0x0
	.size	iv, 4

	.type	rv,@object              # @rv
	.globl	rv
	.p2align	3
rv:
	.quad	0                       # double 0
	.size	rv, 8

	.type	bv,@object              # @bv
	.globl	bv
bv:
	.byte	0                       # 0x0
	.size	bv, 1

	.type	cv,@object              # @cv
	.globl	cv
cv:
	.byte	0                       # 0x0
	.size	cv, 1

	.type	p,@object               # @p
	.globl	p
	.p2align	2
p:
	.long	0                       # 0x0
	.size	p, 4

	.type	a,@object               # @a
	.globl	a
	.p2align	4
a:
	.zero	24
	.size	a, 24

	.type	.str,@object            # @.str
	.section	.rodata,"a",@progbits
	.globl	.str
.str:
	.asciz	"%d\n"
	.size	.str, 4

	.section	".note.GNU-stack","",@progbits
