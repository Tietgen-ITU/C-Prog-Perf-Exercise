	.file	"kernels.c"
	.text
	.globl	naive_rotate
	.type	naive_rotate, @function
naive_rotate:
.LFB39:
	.cfi_startproc
	endbr64
	testl	%edi, %edi
	jle	.L7
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
	movslq	%edi, %rax
	leaq	(%rax,%rax,2), %rdi
	addq	%rdi, %rdi
	movq	%rsi, %r11
	leal	-1(%rbx), %eax
	movl	%eax, %ecx
	imull	%ebx, %ecx
	movslq	%ecx, %rcx
	leaq	(%rcx,%rcx,2), %rcx
	leaq	(%rdx,%rcx,2), %r10
	movl	%eax, %eax
	leaq	(%rax,%rax,2), %rax
	leaq	6(%rsi,%rax,2), %rsi
	movl	%ebx, %eax
	negl	%eax
	cltq
	leaq	(%rax,%rax,2), %r8
	addq	%r8, %r8
	movl	$0, %r9d
	jmp	.L3
.L10:
	addl	$1, %r9d
	addq	%rdi, %r11
	addq	$6, %r10
	addq	%rdi, %rsi
	cmpl	%r9d, %ebx
	je	.L1
.L3:
	movq	%r10, %rdx
	movq	%r11, %rax
.L4:
	movl	(%rax), %ecx
	movl	%ecx, (%rdx)
	movzwl	4(%rax), %ecx
	movw	%cx, 4(%rdx)
	addq	$6, %rax
	addq	%r8, %rdx
	cmpq	%rsi, %rax
	jne	.L4
	jmp	.L10
.L1:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L7:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE39:
	.size	naive_rotate, .-naive_rotate
	.globl	rotate
	.type	rotate, @function
rotate:
.LFB40:
	.cfi_startproc
	endbr64
	call	naive_rotate
	ret
	.cfi_endproc
.LFE40:
	.size	rotate, .-rotate
	.globl	naive_smooth
	.type	naive_smooth, @function
naive_smooth:
.LFB48:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, -56(%rsp)
	testl	%edi, %edi
	jle	.L12
	movslq	%edi, %rax
	leaq	(%rax,%rax,2), %rax
	addq	%rax, %rax
	movq	%rax, -8(%rsp)
	movq	%rdx, -24(%rsp)
	movl	%edi, -60(%rsp)
	movl	$-1, -12(%rsp)
	movl	$1, -40(%rsp)
	leal	-1(%rdi), %eax
	addq	$2, %rax
	movq	%rax, -32(%rsp)
	leal	-1(%rdi), %r13d
	leaq	6(%rsi), %rax
	movq	%rax, -48(%rsp)
	movl	%r13d, %r15d
	jmp	.L14
.L17:
	movzwl	(%rsi), %edi
	addl	%edi, %eax
	movzwl	2(%rsi), %edi
	addl	%edi, %r10d
	movzwl	4(%rsi), %edi
	addl	%edi, %r9d
	addq	$6, %rsi
	cmpq	%rdx, %rsi
	jne	.L17
	subl	-64(%rsp), %ecx
	leal	1(%rcx,%rbx), %ecx
.L16:
	addl	$1, %ebp
	addl	-60(%rsp), %r12d
	cmpl	%r14d, %ebp
	je	.L15
.L18:
	movl	%r8d, %edx
	subl	$2, %edx
	movl	$0, %ebx
	cmovs	%ebx, %edx
	cmpl	%r8d, %r15d
	movl	%r8d, %ebx
	cmovl	%r15d, %ebx
	cmpl	%ebx, %edx
	jg	.L16
	movslq	%r12d, %rdi
	movslq	%edx, %r13
	movq	%rdi, -72(%rsp)
	leaq	(%rdi,%r13), %rsi
	leaq	(%rsi,%rsi,2), %rsi
	movq	-56(%rsp), %rdi
	leaq	(%rdi,%rsi,2), %rsi
	movl	%edx, -64(%rsp)
	movl	%ebx, %edi
	subl	%edx, %edi
	movq	%rdi, %rdx
	addq	%r13, %rdx
	movq	-72(%rsp), %rdi
	addq	%rdx, %rdi
	leaq	(%rdi,%rdi,2), %rdx
	movq	-48(%rsp), %rdi
	leaq	(%rdi,%rdx,2), %rdx
	jmp	.L17
.L20:
	movl	$0, %ecx
	movl	$0, %r9d
	movl	$0, %r10d
	movl	$0, %eax
.L15:
	cltd
	idivl	%ecx
	movw	%ax, (%r11)
	movl	%r10d, %eax
	cltd
	idivl	%ecx
	movw	%ax, 2(%r11)
	movl	%r9d, %eax
	cltd
	idivl	%ecx
	movw	%ax, 4(%r11)
	addq	$1, %r8
	addq	$6, %r11
	cmpq	%r8, -32(%rsp)
	je	.L25
.L19:
	movl	-40(%rsp), %eax
	cmpl	%r15d, %eax
	cmovg	%r15d, %eax
	movl	-36(%rsp), %ebp
	cmpl	%ebp, %eax
	jl	.L20
	leal	1(%rax), %r14d
	movl	-16(%rsp), %r12d
	movl	$0, %ecx
	movl	$0, %r9d
	movl	$0, %r10d
	movl	$0, %eax
	jmp	.L18
.L25:
	movl	-40(%rsp), %esi
	leal	1(%rsi), %eax
	movq	-8(%rsp), %rbx
	addq	%rbx, -24(%rsp)
	addl	$1, -12(%rsp)
	cmpl	-60(%rsp), %esi
	je	.L12
	movl	%eax, -40(%rsp)
.L14:
	movl	-12(%rsp), %esi
	testl	%esi, %esi
	movl	$0, %eax
	cmovns	%esi, %eax
	movl	%eax, -36(%rsp)
	imull	-60(%rsp), %eax
	movl	%eax, -16(%rsp)
	movq	-24(%rsp), %r11
	movl	$1, %r8d
	jmp	.L19
.L12:
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE48:
	.size	naive_smooth, .-naive_smooth
	.globl	smooth
	.type	smooth, @function
smooth:
.LFB49:
	.cfi_startproc
	endbr64
	call	naive_smooth
	ret
	.cfi_endproc
.LFE49:
	.size	smooth, .-smooth
	.globl	register_rotate_functions
	.type	register_rotate_functions, @function
register_rotate_functions:
.LFB41:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	naive_rotate_descr(%rip), %rsi
	leaq	naive_rotate(%rip), %rdi
	call	add_rotate_function@PLT
	leaq	rotate_descr(%rip), %rsi
	leaq	rotate(%rip), %rdi
	call	add_rotate_function@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	register_rotate_functions, .-register_rotate_functions
	.globl	register_smooth_functions
	.type	register_smooth_functions, @function
register_smooth_functions:
.LFB50:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	smooth_descr(%rip), %rsi
	leaq	smooth(%rip), %rdi
	call	add_smooth_function@PLT
	leaq	naive_smooth_descr(%rip), %rsi
	leaq	naive_smooth(%rip), %rdi
	call	add_smooth_function@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE50:
	.size	register_smooth_functions, .-register_smooth_functions
	.globl	smooth_descr
	.data
	.align 32
	.type	smooth_descr, @object
	.size	smooth_descr, 32
smooth_descr:
	.string	"smooth: Current working version"
	.globl	naive_smooth_descr
	.align 32
	.type	naive_smooth_descr, @object
	.size	naive_smooth_descr, 44
naive_smooth_descr:
	.string	"naive_smooth: Naive baseline implementation"
	.globl	rotate_descr
	.align 32
	.type	rotate_descr, @object
	.size	rotate_descr, 32
rotate_descr:
	.string	"rotate: Current working version"
	.globl	naive_rotate_descr
	.align 32
	.type	naive_rotate_descr, @object
	.size	naive_rotate_descr, 44
naive_rotate_descr:
	.string	"naive_rotate: Naive baseline implementation"
	.globl	team
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"anti"
.LC1:
	.string	"Andreas Nicolaj Tietgen"
.LC2:
	.string	"anti@itu.dk"
.LC3:
	.string	""
	.section	.data.rel.local,"aw"
	.align 32
	.type	team, @object
	.size	team, 40
team:
	.quad	.LC0
	.quad	.LC1
	.quad	.LC2
	.quad	.LC3
	.quad	.LC3
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
