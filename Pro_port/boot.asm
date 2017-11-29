;   Copyright(c) 2013, 2016 Renesas Electronics Corporation
;   RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
;   This program must be used solely for the purpose for which
;   it was furnished by Renesas Electronics Corporation. No part of this
;   program may be reproduced or disclosed to others, in any
;   form, without the prior written permission of Renesas Electronics
;   Corporation.

;   NOTE       : THIS IS A TYPICAL EXAMPLE.
;   DATE       : Mon, Oct 24, 2016

	; if using eiint as table reference method,
	; enable next line's macro.

	;USE_TABLE_REFERENCE_METHOD .set 1

;-----------------------------------------------------------------------------
;	exception vector table
;-----------------------------------------------------------------------------
	.section "RESET", text
	.align	512
	jr32	__start ; RESET

	.align	16
	syncp
	jr32	_Dummy ; SYSERR

	.align	16
	jr32	_Dummy

	.align	16
	jr32	_Dummy ; FETRAP

	.align	16
	jr32	_Dummy_EI ; TRAP0

	.align	16
	jr32	_Dummy_EI ; TRAP1

	.align	16
	jr32	_Dummy ; RIE

	.align	16
	syncp
	jr32	_Dummy_EI ; FPP/FPI

	.align	16
	jr32	_Dummy ; UCPOP

	.align	16
	jr32	_Dummy ; MIP/MDP

	.align	16
	jr32	_Dummy ; PIE

	.align	16
	jr32	_Dummy

	.align	16
	jr32	_Dummy ; MAE

	.align	16
	jr32	_Dummy

	.align	16
	syncp
	jr32	_Dummy ; FENMI

	.align	16
	syncp
	jr32	_Dummy ; FEINT

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority0)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority1)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority2)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority3)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority4)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority5)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority6)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority7)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority8)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority9)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority10)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority11)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority12)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority13)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority14)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority15)

	.section "EIINTTBL", const
	.align	512
	.dw	#_Dummy_EI ; INT0
	.dw	#_Dummy_EI ; INT1
	.dw	#_Dummy_EI ; INT2
	.rept	512 - 3
	.dw	#_Dummy_EI ; INTn
	.endm

	.section ".text", text
	.align	2
_Dummy:
	br	_Dummy

_Dummy_EI:
	br	_Dummy_EI

;-----------------------------------------------------------------------------
;	startup
;-----------------------------------------------------------------------------
	.section	".text", text
	.align	2
__start:
$if 1	; initialize register
	$nowarning
	mov	r0, r1
	$warning
	mov	r0, r2
	mov	r0, r3
	mov	r0, r4
	mov	r0, r5
	mov	r0, r6
	mov	r0, r7
	mov	r0, r8
	mov	r0, r9
	mov	r0, r10
	mov	r0, r11
	mov	r0, r12
	mov	r0, r13
	mov	r0, r14
	mov	r0, r15
	mov	r0, r16
	mov	r0, r17
	mov	r0, r18
	mov	r0, r19
	mov	r0, r20
	mov	r0, r21
	mov	r0, r22
	mov	r0, r23
	mov	r0, r24
	mov	r0, r25
	mov	r0, r26
	mov	r0, r27
	mov	r0, r28
	mov	r0, r29
	mov	r0, r30
	mov	r0, r31
	ldsr	r0, 0, 0		;  EIPC
	ldsr	r0, 16, 0		;  CTPC
$endif

	jarl	_hdwinit, lp	; initialize hardware
$ifdef USE_TABLE_REFERENCE_METHOD
	mov	#__sEIINTTBL, r6
	jarl	_set_table_reference_method, lp ; set table reference method
$endif
	jr32	__cstart

;-----------------------------------------------------------------------------
;	hdwinit
; Specify RAM addresses suitable to your system if needed.
;-----------------------------------------------------------------------------
	GLOBAL_RAM_ADDR	.set	0
	GLOBAL_RAM_END	.set	0
	LOCAL_RAM_ADDR	.set	0
	LOCAL_RAM_END	.set	0

	.align	2
_hdwinit:
	mov	lp, r14			; save return address

	; clear Global RAM
	mov	GLOBAL_RAM_ADDR, r6
	mov	GLOBAL_RAM_END, r7
	jarl	_zeroclr4, lp

	; clear Local RAM
	mov	LOCAL_RAM_ADDR, r6
	mov	LOCAL_RAM_END, r7
	jarl	_zeroclr4, lp

	mov	r14, lp
	jmp	[lp]

;-----------------------------------------------------------------------------
;	zeroclr4
;-----------------------------------------------------------------------------
	.align	2
_zeroclr4:
	br	.L.zeroclr4.2
.L.zeroclr4.1:
	st.w	r0, [r6]
	add	4, r6
.L.zeroclr4.2:
	cmp	r6, r7
	bh	.L.zeroclr4.1
	jmp	[lp]

$ifdef USE_TABLE_REFERENCE_METHOD
;-----------------------------------------------------------------------------
;	set table reference method
;-----------------------------------------------------------------------------
	; interrupt control register address
	ICBASE	.set	0xfffeea00

	.align	2
_set_table_reference_method:
	ldsr	r6, 4, 1		; set INTBP

	; Some interrupt channels use the table reference method.
	mov	ICBASE, r10		; get interrupt control register address
	set1	6, 0[r10]		; set INT0 as table reference
	set1	6, 2[r10]		; set INT1 as table reference
	set1	6, 4[r10]		; set INT2 as table reference

	jmp	[lp]
$endif
;-------------------- end of start up module -------------------;
