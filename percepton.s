	.file	"percepton.c"
	.comm	iris,9600,32
	.comm	W,480,32
	.comm	Wn,480,32
	.comm	y,144,32
	.globl	prir
	.bss
	.align 8
	.type	prir, @object
	.size	prir, 8
prir:
	.zero	8
	.comm	obvib,3600,32
	.comm	tvib,2400,32
	.comm	d,2160,32
	.comm	dt,1440,32
	.comm	osh,24,8
	.globl	sosh
	.data
	.align 8
	.type	sosh, @object
	.size	sosh, 8
sosh:
	.long	0
	.long	1079574528
	.globl	kor
	.align 8
	.type	kor, @object
	.size	kor, 8
kor:
	.long	0
	.long	1072693248
	.comm	sigm,80,32
	.comm	lol,8,8
	.globl	tm
	.bss
	.align 4
	.type	tm, @object
	.size	tm, 4
tm:
	.zero	4
	.comm	oy,12,4
	.comm	max,4,4
	.text
	.globl	nu
	.type	nu, @function
nu:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	fldz
	fstpl	prir
	movl	$0, -4(%ebp)
	jmp	.L2
.L5:
	cmpl	$1, 12(%ebp)
	jne	.L3
	cmpl	$3, -4(%ebp)
	jle	.L3
	jmp	.L4
.L3:
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	fldl	W(,%eax,8)
	movl	12(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	-4(%ebp), %edx
	addl	%edx, %eax
	fldl	y(,%eax,8)
	fmulp	%st, %st(1)
	fldl	prir
	faddp	%st, %st(1)
	fstpl	prir
	addl	$1, -4(%ebp)
.L2:
	cmpl	$4, -4(%ebp)
	jle	.L5
.L4:
	fldl	prir
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	nu, .-nu
	.section	.rodata
.LC3:
	.string	"%lf %lf %lf %lf %lf %lf %lf\n"
	.text
	.globl	vvod
	.type	vvod, @function
vvod:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$0, -28(%ebp)
	jmp	.L8
.L9:
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$iris, %eax
	fld1
	fstpl	(%eax)
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$56, %eax
	addl	$iris, %eax
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$48, %eax
	leal	iris(%eax), %edi
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$40, %eax
	leal	iris(%eax), %esi
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$32, %eax
	leal	iris(%eax), %ebx
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$24, %eax
	leal	iris(%eax), %ecx
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$16, %eax
	addl	$iris, %eax
	movl	%eax, -48(%ebp)
	movl	-28(%ebp), %eax
	sall	$6, %eax
	addl	$8, %eax
	addl	$iris, %eax
	movl	%edx, 32(%esp)
	movl	%edi, 28(%esp)
	movl	%esi, 24(%esp)
	movl	%ebx, 20(%esp)
	movl	%ecx, 16(%esp)
	movl	-48(%ebp), %ebx
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$.LC3, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__isoc99_fscanf
	addl	$1, -28(%ebp)
.L8:
	cmpl	$149, -28(%ebp)
	jle	.L9
	movl	$0, -28(%ebp)
	jmp	.L10
.L15:
	movl	$0, -32(%ebp)
	jmp	.L11
.L12:
	movl	-28(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	fldl	iris(,%eax,8)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	obvib(,%eax,8)
	movl	-28(%ebp), %eax
	leal	30(%eax), %edx
	movl	-28(%ebp), %eax
	addl	$50, %eax
	leal	0(,%eax,8), %ecx
	movl	-32(%ebp), %eax
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	obvib(,%eax,8)
	movl	-28(%ebp), %eax
	leal	60(%eax), %edx
	movl	-28(%ebp), %eax
	addl	$100, %eax
	leal	0(,%eax,8), %ecx
	movl	-32(%ebp), %eax
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	obvib(,%eax,8)
	addl	$1, -32(%ebp)
.L11:
	cmpl	$4, -32(%ebp)
	jle	.L12
	movl	$0, -32(%ebp)
	jmp	.L13
.L14:
	movl	-32(%ebp), %eax
	leal	5(%eax), %edx
	movl	-28(%ebp), %eax
	sall	$3, %eax
	addl	%edx, %eax
	fldl	iris(,%eax,8)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	d(,%eax,8)
	movl	-28(%ebp), %eax
	leal	30(%eax), %edx
	movl	-28(%ebp), %eax
	leal	50(%eax), %ecx
	movl	-32(%ebp), %eax
	addl	$5, %eax
	sall	$3, %ecx
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	d(,%eax,8)
	movl	-28(%ebp), %eax
	leal	60(%eax), %edx
	movl	-28(%ebp), %eax
	leal	100(%eax), %ecx
	movl	-32(%ebp), %eax
	addl	$5, %eax
	sall	$3, %ecx
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	d(,%eax,8)
	addl	$1, -32(%ebp)
.L13:
	cmpl	$2, -32(%ebp)
	jle	.L14
	addl	$1, -28(%ebp)
.L10:
	cmpl	$29, -28(%ebp)
	jle	.L15
	movl	$0, -28(%ebp)
	jmp	.L16
.L21:
	movl	$0, -32(%ebp)
	jmp	.L17
.L18:
	movl	-28(%ebp), %eax
	addl	$30, %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	fldl	iris(,%eax,8)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	tvib(,%eax,8)
	movl	-28(%ebp), %eax
	leal	20(%eax), %edx
	movl	-28(%ebp), %eax
	addl	$80, %eax
	leal	0(,%eax,8), %ecx
	movl	-32(%ebp), %eax
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	tvib(,%eax,8)
	movl	-28(%ebp), %eax
	leal	40(%eax), %edx
	movl	-28(%ebp), %eax
	addl	$130, %eax
	leal	0(,%eax,8), %ecx
	movl	-32(%ebp), %eax
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	tvib(,%eax,8)
	addl	$1, -32(%ebp)
.L17:
	cmpl	$4, -32(%ebp)
	jle	.L18
	movl	$0, -32(%ebp)
	jmp	.L19
.L20:
	movl	-28(%ebp), %eax
	leal	30(%eax), %edx
	movl	-32(%ebp), %eax
	addl	$5, %eax
	sall	$3, %edx
	addl	%edx, %eax
	fldl	iris(,%eax,8)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	dt(,%eax,8)
	movl	-28(%ebp), %eax
	leal	20(%eax), %edx
	movl	-28(%ebp), %eax
	leal	80(%eax), %ecx
	movl	-32(%ebp), %eax
	addl	$5, %eax
	sall	$3, %ecx
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	dt(,%eax,8)
	movl	-28(%ebp), %eax
	leal	40(%eax), %edx
	movl	-28(%ebp), %eax
	leal	130(%eax), %ecx
	movl	-32(%ebp), %eax
	addl	$5, %eax
	sall	$3, %ecx
	addl	%ecx, %eax
	fldl	iris(,%eax,8)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	dt(,%eax,8)
	addl	$1, -32(%ebp)
.L19:
	cmpl	$2, -32(%ebp)
	jle	.L20
	addl	$1, -28(%ebp)
.L16:
	cmpl	$19, -28(%ebp)
	jle	.L21
	movl	$0, -28(%ebp)
	jmp	.L22
.L25:
	movl	$0, -32(%ebp)
	jmp	.L23
.L24:
	call	rand
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	fldl	.LC4
	fdivrp	%st, %st(1)
	fldl	.LC5
	fsubrp	%st, %st(1)
	fadd	%st(0), %st
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	fstpl	W(,%eax,8)
	addl	$1, -32(%ebp)
.L23:
	cmpl	$4, -32(%ebp)
	jle	.L24
	addl	$1, -28(%ebp)
.L22:
	cmpl	$2, -28(%ebp)
	jle	.L25
	movl	$0, -28(%ebp)
	jmp	.L26
.L29:
	movl	$0, -32(%ebp)
	jmp	.L27
.L28:
	call	rand
	movl	%eax, -44(%ebp)
	fildl	-44(%ebp)
	fldl	.LC4
	fdivrp	%st, %st(1)
	fldl	.LC5
	fsubrp	%st, %st(1)
	fadd	%st(0), %st
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	-32(%ebp), %edx
	addl	%edx, %eax
	addl	$30, %eax
	fstpl	W(,%eax,8)
	addl	$1, -32(%ebp)
.L27:
	cmpl	$3, -32(%ebp)
	jle	.L28
	addl	$1, -28(%ebp)
.L26:
	cmpl	$2, -28(%ebp)
	jle	.L29
	movl	$0, -28(%ebp)
	jmp	.L30
.L31:
	movl	-28(%ebp), %eax
	movl	$0, oy(,%eax,4)
	addl	$1, -28(%ebp)
.L30:
	cmpl	$2, -28(%ebp)
	jle	.L31
	addl	$76, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	vvod, .-vvod
	.globl	ism
	.type	ism, @function
ism:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	fldz
	fstpl	prir
	movl	$0, -12(%ebp)
	jmp	.L33
.L40:
	movl	$0, -16(%ebp)
	jmp	.L34
.L39:
	movl	$0, -20(%ebp)
	jmp	.L35
.L38:
	cmpl	$1, -12(%ebp)
	jne	.L36
	cmpl	$3, -20(%ebp)
	jle	.L36
	jmp	.L37
.L36:
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	fldl	Wn(,%eax,8)
	movl	-16(%ebp), %edx
	movl	-12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	fldl	W(,%eax,8)
	fsubrp	%st, %st(1)
	fldl	.LC6
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	prir
	faddp	%st, %st(1)
	fstpl	prir
	addl	$1, -20(%ebp)
.L35:
	cmpl	$4, -20(%ebp)
	jle	.L38
.L37:
	addl	$1, -16(%ebp)
.L34:
	cmpl	$2, -16(%ebp)
	jle	.L39
	addl	$1, -12(%ebp)
.L33:
	cmpl	$1, -12(%ebp)
	jle	.L40
	fldl	prir
	fldl	.LC5
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	.LC7
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	.L45
	movl	$1, %eax
	jmp	.L43
.L45:
	movl	$0, %eax
.L43:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	ism, .-ism
	.globl	ksi
	.type	ksi, @function
ksi:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	fldz
	fstpl	-24(%ebp)
	cmpl	$1, 8(%ebp)
	jne	.L47
	movl	12(%ebp), %eax
	fldl	osh(,%eax,8)
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	nu
	fstpl	(%esp)
	call	exp
	fmull	-32(%ebp)
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	nu
	fstpl	(%esp)
	call	exp
	fld1
	faddp	%st, %st(1)
	fldl	.LC6
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fdivrl	-32(%ebp)
	jmp	.L48
.L47:
	movl	$0, -12(%ebp)
	jmp	.L49
.L50:
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	addl	%edx, %eax
	fldl	sigm(,%eax,8)
	movl	8(%ebp), %eax
	leal	1(%eax), %ecx
	movl	12(%ebp), %eax
	leal	1(%eax), %ebx
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	addl	%ecx, %eax
	addl	%ebx, %eax
	fldl	W(,%eax,8)
	fmulp	%st, %st(1)
	fldl	-24(%ebp)
	faddp	%st, %st(1)
	fstpl	-24(%ebp)
	addl	$1, -12(%ebp)
.L49:
	cmpl	$2, -12(%ebp)
	jle	.L50
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	nu
	fstpl	(%esp)
	call	exp
	fmull	-24(%ebp)
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	nu
	fstpl	(%esp)
	call	exp
	fld1
	faddp	%st, %st(1)
	fldl	.LC6
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fdivrl	-32(%ebp)
.L48:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	ksi, .-ksi
	.section	.rodata
	.align 4
.LC8:
	.string	"========================================================"
.LC9:
	.string	"OSH[%d]=%d time=%d\n"
.LC12:
	.string	"oshOBYCH= %lf\n\n"
.LC13:
	.string	"OSH[%d]=%d "
	.align 4
.LC15:
	.string	"oshibok TESTa iz 100 procentov = %lf\n\n"
	.text
	.globl	vivod
	.type	vivod, @function
vivod:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$.LC8, (%esp)
	call	puts
	movl	$0, -12(%ebp)
	jmp	.L52
.L53:
	movl	tm, %edx
	movl	-12(%ebp), %eax
	movl	oy(,%eax,4), %eax
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC9, (%esp)
	call	printf
	addl	$1, -12(%ebp)
.L52:
	cmpl	$2, -12(%ebp)
	jle	.L53
	movl	$.LC8, (%esp)
	call	puts
	fldl	sosh
	fldl	.LC10
	fdivrp	%st, %st(1)
	fldl	.LC11
	fmulp	%st, %st(1)
	fstpl	4(%esp)
	movl	$.LC12, (%esp)
	call	printf
	movl	$0, -20(%ebp)
	jmp	.L54
.L55:
	movl	-20(%ebp), %eax
	movl	$0, oy(,%eax,4)
	addl	$1, -20(%ebp)
.L54:
	cmpl	$2, -20(%ebp)
	jle	.L55
	movl	$0, -12(%ebp)
	jmp	.L56
.L76:
	movl	$0, -24(%ebp)
	jmp	.L57
.L58:
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	-24(%ebp), %edx
	addl	%edx, %eax
	fldl	tvib(,%eax,8)
	movl	-24(%ebp), %eax
	fstpl	y(,%eax,8)
	addl	$1, -24(%ebp)
.L57:
	cmpl	$4, -24(%ebp)
	jle	.L58
	movl	$0, -20(%ebp)
	jmp	.L59
.L63:
	movl	$0, -24(%ebp)
	cmpl	$0, -20(%ebp)
	jne	.L60
	movl	-20(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	addl	$y, %eax
	fld1
	fstpl	(%eax)
	movl	$1, -24(%ebp)
.L60:
	movl	$0, -16(%ebp)
	jmp	.L61
.L62:
	movl	-20(%ebp), %eax
	leal	1(%eax), %ebx
	movl	-24(%ebp), %eax
	movl	-16(%ebp), %edx
	leal	(%edx,%eax), %esi
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	nu
	fchs
	fstpl	(%esp)
	call	exp
	fld1
	faddp	%st, %st(1)
	fld1
	fdivp	%st, %st(1)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	addl	%eax, %eax
	addl	%esi, %eax
	fstpl	y(,%eax,8)
	addl	$1, -16(%ebp)
.L61:
	cmpl	$2, -16(%ebp)
	jle	.L62
	addl	$1, -20(%ebp)
.L59:
	cmpl	$1, -20(%ebp)
	jle	.L63
	fldl	y+96
	fstpl	prir
	movl	$0, max
	movl	$1, -16(%ebp)
	jmp	.L64
.L67:
	movl	-16(%ebp), %eax
	addl	$12, %eax
	fldl	y(,%eax,8)
	fldl	prir
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	.L65
	movl	-16(%ebp), %eax
	addl	$12, %eax
	fldl	y(,%eax,8)
	fstpl	prir
	movl	-16(%ebp), %eax
	movl	%eax, max
.L65:
	addl	$1, -16(%ebp)
.L64:
	cmpl	$2, -16(%ebp)
	jle	.L67
	movl	$0, -16(%ebp)
	jmp	.L68
.L71:
	movl	max, %eax
	cmpl	%eax, -16(%ebp)
	jne	.L69
	movl	-16(%ebp), %eax
	fld1
	fstpl	osh(,%eax,8)
	jmp	.L70
.L69:
	movl	-16(%ebp), %eax
	fldz
	fstpl	osh(,%eax,8)
.L70:
	addl	$1, -16(%ebp)
.L68:
	cmpl	$2, -16(%ebp)
	jle	.L71
	movl	$0, -16(%ebp)
	jmp	.L72
.L75:
	movl	-16(%ebp), %eax
	fldl	osh(,%eax,8)
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	-16(%ebp), %edx
	addl	%edx, %eax
	fldl	dt(,%eax,8)
	fucomi	%st(1), %st
	jp	.L81
	fucomip	%st(1), %st
	fstp	%st(0)
	je	.L73
	jmp	.L80
.L81:
	fstp	%st(0)
	fstp	%st(0)
.L80:
	movl	-16(%ebp), %eax
	movl	oy(,%eax,4), %eax
	leal	1(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, oy(,%eax,4)
.L73:
	addl	$1, -16(%ebp)
.L72:
	cmpl	$2, -16(%ebp)
	jle	.L75
	addl	$1, -12(%ebp)
.L56:
	cmpl	$59, -12(%ebp)
	jle	.L76
	fldz
	fstpl	sosh
	movl	$.LC8, (%esp)
	call	puts
	movl	$0, -12(%ebp)
	jmp	.L77
.L78:
	movl	-12(%ebp), %eax
	movl	oy(,%eax,4), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fldl	sosh
	faddp	%st, %st(1)
	fstpl	sosh
	movl	-12(%ebp), %eax
	movl	oy(,%eax,4), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC13, (%esp)
	call	printf
	addl	$1, -12(%ebp)
.L77:
	cmpl	$2, -12(%ebp)
	jle	.L78
	fldl	sosh
	fldl	.LC14
	fdivrp	%st, %st(1)
	fldl	.LC11
	fmulp	%st, %st(1)
	fstpl	sosh
	movl	$10, (%esp)
	call	putchar
	movl	$.LC8, (%esp)
	call	puts
	fldl	sosh
	fstpl	4(%esp)
	movl	$.LC15, (%esp)
	call	printf
	addl	$48, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	vivod, .-vivod
	.section	.rodata
.LC16:
	.string	"r"
.LC17:
	.string	"init.txt"
.LC20:
	.string	"%lf = %lf \t"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$64, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$.LC16, 4(%esp)
	movl	$.LC17, (%esp)
	call	fopen
	movl	%eax, 44(%esp)
	movl	$0, (%esp)
	call	time
	movl	%eax, (%esp)
	call	srand
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	vvod
.L118:
	fldl	kor
	fldl	.LC18
	fmulp	%st, %st(1)
	fstpl	kor
	movl	$0, 48(%esp)
	jmp	.L83
.L90:
	movl	$0, 60(%esp)
	jmp	.L84
.L89:
	movl	$0, 56(%esp)
	jmp	.L85
.L88:
	cmpl	$1, 48(%esp)
	jne	.L86
	cmpl	$3, 56(%esp)
	jle	.L86
	jmp	.L87
.L86:
	movl	60(%esp), %edx
	movl	48(%esp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	56(%esp), %eax
	addl	%edx, %eax
	fldl	W(,%eax,8)
	movl	60(%esp), %edx
	movl	48(%esp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	56(%esp), %eax
	addl	%edx, %eax
	fstpl	Wn(,%eax,8)
	addl	$1, 56(%esp)
.L85:
	cmpl	$4, 56(%esp)
	jle	.L88
.L87:
	addl	$1, 60(%esp)
.L84:
	cmpl	$2, 60(%esp)
	jle	.L89
	addl	$1, 48(%esp)
.L83:
	cmpl	$1, 48(%esp)
	jle	.L90
	movl	$0, 56(%esp)
	jmp	.L91
.L92:
	movl	56(%esp), %eax
	fldz
	fstpl	osh(,%eax,8)
	movl	56(%esp), %eax
	movl	$0, oy(,%eax,4)
	addl	$1, 56(%esp)
.L91:
	cmpl	$2, 56(%esp)
	jle	.L92
	movl	$0, 60(%esp)
	jmp	.L93
.L115:
	movl	$0, 52(%esp)
	jmp	.L94
.L95:
	movl	60(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	52(%esp), %edx
	addl	%edx, %eax
	fldl	obvib(,%eax,8)
	movl	52(%esp), %eax
	fstpl	y(,%eax,8)
	addl	$1, 52(%esp)
.L94:
	cmpl	$4, 52(%esp)
	jle	.L95
	movl	$0, 48(%esp)
	jmp	.L96
.L100:
	movl	$0, 52(%esp)
	cmpl	$0, 48(%esp)
	jne	.L97
	movl	48(%esp), %eax
	leal	1(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	addl	$y, %eax
	fld1
	fstpl	(%eax)
	movl	$1, 52(%esp)
.L97:
	movl	$0, 56(%esp)
	jmp	.L98
.L99:
	movl	48(%esp), %eax
	leal	1(%eax), %ebx
	movl	52(%esp), %eax
	movl	56(%esp), %edx
	leal	(%edx,%eax), %esi
	movl	48(%esp), %eax
	movl	%eax, 4(%esp)
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	nu
	fchs
	fstpl	(%esp)
	call	exp
	fld1
	faddp	%st, %st(1)
	fld1
	fdivp	%st, %st(1)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	addl	%eax, %eax
	addl	%esi, %eax
	fstpl	y(,%eax,8)
	addl	$1, 56(%esp)
.L98:
	cmpl	$2, 56(%esp)
	jle	.L99
	addl	$1, 48(%esp)
.L96:
	cmpl	$1, 48(%esp)
	jle	.L100
	movl	$0, 56(%esp)
	jmp	.L101
.L102:
	movl	60(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	56(%esp), %edx
	addl	%edx, %eax
	fldl	d(,%eax,8)
	movl	56(%esp), %eax
	addl	$12, %eax
	fldl	y(,%eax,8)
	fsubrp	%st, %st(1)
	movl	56(%esp), %eax
	fstpl	osh(,%eax,8)
	addl	$1, 56(%esp)
.L101:
	cmpl	$2, 56(%esp)
	jle	.L102
	movl	$1, 48(%esp)
	jmp	.L103
.L106:
	movl	$0, 56(%esp)
	jmp	.L104
.L105:
	movl	56(%esp), %eax
	movl	%eax, 4(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	call	ksi
	movl	48(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	56(%esp), %edx
	addl	%edx, %eax
	fstpl	sigm(,%eax,8)
	addl	$1, 56(%esp)
.L104:
	cmpl	$2, 56(%esp)
	jle	.L105
	subl	$1, 48(%esp)
.L103:
	cmpl	$0, 48(%esp)
	jns	.L106
	movl	$0, 48(%esp)
	jmp	.L107
.L114:
	movl	$0, 56(%esp)
	jmp	.L108
.L113:
	movl	$0, 52(%esp)
	jmp	.L109
.L112:
	cmpl	$1, 48(%esp)
	jne	.L110
	cmpl	$3, 52(%esp)
	jle	.L110
	jmp	.L111
.L110:
	movl	56(%esp), %edx
	movl	48(%esp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	52(%esp), %eax
	addl	%edx, %eax
	fldl	W(,%eax,8)
	fldl	kor
	fldl	.LC19
	fmulp	%st, %st(1)
	movl	48(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	56(%esp), %edx
	addl	%edx, %eax
	fldl	sigm(,%eax,8)
	fmulp	%st, %st(1)
	movl	48(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	52(%esp), %edx
	addl	%edx, %eax
	fldl	y(,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	56(%esp), %edx
	movl	48(%esp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	addl	%edx, %edx
	movl	%edx, %ecx
	sall	$4, %ecx
	subl	%edx, %ecx
	leal	(%eax,%ecx), %edx
	movl	52(%esp), %eax
	addl	%edx, %eax
	fstpl	W(,%eax,8)
	addl	$1, 52(%esp)
.L109:
	cmpl	$4, 52(%esp)
	jle	.L112
.L111:
	addl	$1, 56(%esp)
.L108:
	cmpl	$2, 56(%esp)
	jle	.L113
	addl	$1, 48(%esp)
.L107:
	cmpl	$1, 48(%esp)
	jle	.L114
	addl	$1, 60(%esp)
.L93:
	cmpl	$89, 60(%esp)
	jle	.L115
	call	ism
	cmpl	$1, %eax
	jne	.L116
	nop
	fldz
	fstpl	sosh
	movl	$0, 60(%esp)
	jmp	.L119
.L116:
	movl	tm, %eax
	addl	$1, %eax
	movl	%eax, tm
	jmp	.L118
.L139:
	movl	$0, 52(%esp)
	jmp	.L120
.L121:
	movl	60(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	52(%esp), %edx
	addl	%edx, %eax
	fldl	obvib(,%eax,8)
	movl	52(%esp), %eax
	fstpl	y(,%eax,8)
	addl	$1, 52(%esp)
.L120:
	cmpl	$4, 52(%esp)
	jle	.L121
	movl	$0, 48(%esp)
	jmp	.L122
.L126:
	movl	$0, 52(%esp)
	cmpl	$0, 48(%esp)
	jne	.L123
	movl	48(%esp), %eax
	leal	1(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	addl	$y, %eax
	fld1
	fstpl	(%eax)
	movl	$1, 52(%esp)
.L123:
	movl	$0, 56(%esp)
	jmp	.L124
.L125:
	movl	48(%esp), %eax
	leal	1(%eax), %ebx
	movl	52(%esp), %eax
	movl	56(%esp), %edx
	leal	(%edx,%eax), %esi
	movl	48(%esp), %eax
	movl	%eax, 4(%esp)
	movl	56(%esp), %eax
	movl	%eax, (%esp)
	call	nu
	fchs
	fstpl	(%esp)
	call	exp
	fld1
	faddp	%st, %st(1)
	fld1
	fdivp	%st, %st(1)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	addl	%eax, %eax
	addl	%esi, %eax
	fstpl	y(,%eax,8)
	addl	$1, 56(%esp)
.L124:
	cmpl	$2, 56(%esp)
	jle	.L125
	addl	$1, 48(%esp)
.L122:
	cmpl	$1, 48(%esp)
	jle	.L126
	fldl	y+96
	fstpl	prir
	movl	$0, max
	movl	$1, 56(%esp)
	jmp	.L127
.L130:
	movl	56(%esp), %eax
	addl	$12, %eax
	fldl	y(,%eax,8)
	fldl	prir
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	.L128
	movl	56(%esp), %eax
	addl	$12, %eax
	fldl	y(,%eax,8)
	fstpl	prir
	movl	56(%esp), %eax
	movl	%eax, max
.L128:
	addl	$1, 56(%esp)
.L127:
	cmpl	$2, 56(%esp)
	jle	.L130
	movl	$0, 56(%esp)
	jmp	.L131
.L134:
	movl	max, %eax
	cmpl	%eax, 56(%esp)
	jne	.L132
	movl	56(%esp), %eax
	fld1
	fstpl	osh(,%eax,8)
	jmp	.L133
.L132:
	movl	56(%esp), %eax
	fldz
	fstpl	osh(,%eax,8)
.L133:
	addl	$1, 56(%esp)
.L131:
	cmpl	$2, 56(%esp)
	jle	.L134
	movl	$0, 56(%esp)
	jmp	.L135
.L138:
	movl	56(%esp), %eax
	fldl	osh(,%eax,8)
	movl	60(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	56(%esp), %edx
	addl	%edx, %eax
	fldl	d(,%eax,8)
	fucomi	%st(1), %st
	jp	.L145
	fucomip	%st(1), %st
	fstp	%st(0)
	je	.L136
	jmp	.L144
.L145:
	fstp	%st(0)
	fstp	%st(0)
.L144:
	movl	56(%esp), %eax
	movl	oy(,%eax,4), %eax
	leal	1(%eax), %edx
	movl	56(%esp), %eax
	movl	%edx, oy(,%eax,4)
	movl	60(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	56(%esp), %edx
	addl	%edx, %eax
	fldl	d(,%eax,8)
	movl	56(%esp), %eax
	fldl	osh(,%eax,8)
	fxch	%st(1)
	fstpl	12(%esp)
	fstpl	4(%esp)
	movl	$.LC20, (%esp)
	call	printf
	movl	$10, (%esp)
	call	putchar
.L136:
	addl	$1, 56(%esp)
.L135:
	cmpl	$2, 56(%esp)
	jle	.L138
	addl	$1, 60(%esp)
.L119:
	cmpl	$89, 60(%esp)
	jle	.L139
	movl	$0, 60(%esp)
	jmp	.L140
.L141:
	movl	60(%esp), %eax
	movl	oy(,%eax,4), %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fldl	sosh
	faddp	%st, %st(1)
	fstpl	sosh
	addl	$1, 60(%esp)
.L140:
	cmpl	$2, 60(%esp)
	jle	.L141
	call	vivod
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	fclose
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC4:
	.long	-4194304
	.long	1105199103
	.align 8
.LC5:
	.long	0
	.long	1071644672
	.align 8
.LC6:
	.long	0
	.long	1073741824
	.align 8
.LC7:
	.long	-350469331
	.long	1058682594
	.align 8
.LC10:
	.long	0
	.long	1079410688
	.align 8
.LC11:
	.long	0
	.long	1079574528
	.align 8
.LC14:
	.long	0
	.long	1078853632
	.align 8
.LC18:
	.long	-652835029
	.long	1072691150
	.align 8
.LC19:
	.long	-1717986918
	.long	1071225241
	.ident	"GCC: (GNU) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
