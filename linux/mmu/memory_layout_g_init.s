	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	movl	$0, -4(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_g                      ## @g
	.p2align	2
_g:
	.long	99                      ## 0x63

	.globl	_h                      ## @h
	.p2align	2
_h:
	.long	97                      ## 0x61

	.comm	_k,4,2                  ## @k
	.comm	_c,1,0                  ## @c

.subsections_via_symbols
