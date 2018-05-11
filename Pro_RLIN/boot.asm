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

	USE_TABLE_REFERENCE_METHOD .set 1

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
	.dw	#_TAUD0CH0IntHandler; INT0
	.dw	#_Dummy_EI ; INT1
	.dw	#_Dummy_EI ; INT2
	.dw #_Dummy_EI ; INT3
	.dw #_Dummy_EI ; INT4
	.dw #_Dummy_EI ; INT5
	.dw #_Dummy_EI ; INT6
	.dw #_Dummy_EI ; INT7
	.dw #_Dummy_EI ; INT8
	.dw #_Dummy_EI ; INT9
	.dw #_Dummy_EI ; INT10
	.dw #_Dummy_EI ; INT11
	.dw #_Dummy_EI ; INT12
	.dw #_Dummy_EI ; INT13
	.dw #_RSCAN0GlobalErrorIntHandler ; INT14
	.dw #_RSCAN0RecvFIFOIntHandler ; INT15
	.dw #_RSCAN0CH0ErrorIntHandler ; INT16
	.dw #_RSCAN0CH0TrFIFORecvCompletionIntHandler ; INT17
	.dw #_RSCAN0CH0SendCompleteIntHandler ; INT18
	.dw #_Dummy_EI ; INT19
	.dw #_Dummy_EI ; INT20
	.dw #_Dummy_EI ; INT21
	.dw #_Dummy_EI ; INT22
	.dw #_Dummy_EI ; INT23
	.dw #_Dummy_EI ; INT24
	.dw #_Dummy_EI ; INT25
	.dw #_RLIN30SendIntHandler ; INT26
	.dw #_RLIN30RecvCompleteIntHandler ; INT27
	.dw #_RLIN30StatusIntHandler ; INT28
	.dw #_Dummy_EI ; INT29
	.dw #_Dummy_EI ; INT30
	.dw #_Dummy_EI ; INT31
	.dw #_WDTA0IntHandler ; INT32
	.dw #_WDTA1IntHandler ; INT33
	.dw #_Dummy_EI ; INT34
	.dw #_Dummy_EI ; INT35
	.dw #_Dummy_EI ; INT36
	.dw #_Dummy_EI ; INT37
	.dw #_Dummy_EI ; INT38
	.dw #_TAUD0CH1IntHandler ; INT39
	.dw #_Dummy_EI ; INT40
	.dw #_Dummy_EI ; INT41
	.dw #_Dummy_EI ; INT42
	.dw #_Dummy_EI ; INT43
	.dw #_Dummy_EI ; INT44
	.dw #_Dummy_EI ; INT45
	.dw #_Dummy_EI ; INT46
	.dw #_Dummy_EI ; INT47
	.dw #_Dummy_EI ; INT48
	.dw #_Dummy_EI ; INT49
	.dw #_RLIN20IntHandler ; INT50
	.dw #_RLIN21IntHandler ; INT51
	.dw #_Dummy_EI ; INT52
	.dw #_Dummy_EI ; INT53
	.dw #_Dummy_EI ; INT54
	.dw #_Dummy_EI ; INT55
	.dw #_Dummy_EI ; INT56
	.dw #_Dummy_EI ; INT57
	.dw #_Dummy_EI ; INT58
	.dw #_Dummy_EI ; INT59
	.dw #_Dummy_EI ; INT60
	.dw #_Dummy_EI ; INT61
	.dw #_Dummy_EI ; INT62
	.dw #_Dummy_EI ; INT63
	.dw #_Dummy_EI ; INT64
	.dw #_Dummy_EI ; INT65
	.dw #_Dummy_EI ; INT66
	.dw #_Dummy_EI ; INT67
	.dw #_Dummy_EI ; INT68
	.dw #_Dummy_EI ; INT69
	.dw #_Dummy_EI ; INT70
	.dw #_Dummy_EI ; INT71
	.dw #_Dummy_EI ; INT72
	.dw #_Dummy_EI ; INT73
	.dw #_Dummy_EI ; INT74
	.dw #_Dummy_EI ; INT75
	.dw #_OSTMIntHandler ; INT76
	.dw #_Dummy_EI ; INT77
	.dw #_Dummy_EI ; INT78
	.dw #_Dummy_EI ; INT79
	.dw #_Dummy_EI ; INT80
	.dw #_Dummy_EI ; INT81
	.dw #_Dummy_EI ; INT82
	.dw #_Dummy_EI ; INT83
	.dw #_Dummy_EI ; INT84
	.dw #_Dummy_EI ; INT85
	.dw #_Dummy_EI ; INT86
	.dw #_Dummy_EI ; INT87
	.dw #_Dummy_EI ; INT88
	.dw #_Dummy_EI ; INT89
	.dw #_Dummy_EI ; INT90
	.dw #_Dummy_EI ; INT91
	.dw #_Dummy_EI ; INT92
	.dw #_Dummy_EI ; INT93
	.dw #_Dummy_EI ; INT94
	.dw #_Dummy_EI ; INT95
	.dw #_Dummy_EI ; INT96
	.dw #_Dummy_EI ; INT97
	.dw #_Dummy_EI ; INT98
	.dw #_Dummy_EI ; INT99
	.dw #_Dummy_EI ; INT100
	.dw #_Dummy_EI ; INT101
	.dw #_Dummy_EI ; INT102
	.dw #_Dummy_EI ; INT103
	.dw #_Dummy_EI ; INT104
	.dw #_RSCAN0CH1ErrorIntHandler ; INT105
	.dw #_RSCAN0CH1TrFIFORecvCompletionIntHandler ; INT106
	.dw #_RSCAN0CH1SendCompleteIntHandler ; INT107
	.dw #_Dummy_EI ; INT108
	.dw #_Dummy_EI ; INT109
	.dw #_Dummy_EI ; INT110
	.dw #_Dummy_EI ; INT111
	.dw #_Dummy_EI ; INT112
	.dw #_RLIN31SendIntHandler ; INT113
	.dw #_RLIN31RecvCompleteIntHandler ; INT114
	.dw #_RLIN31StatusIntHandler ; INT115
	.dw #_Dummy_EI ; INT116
	.dw #_Dummy_EI ; INT117
	.dw #_Dummy_EI ; INT118
	.dw #_Dummy_EI ; INT119
	.dw #_Dummy_EI ; INT120
	.dw #_Dummy_EI ; INT121
	.dw #_Dummy_EI ; INT122
	.dw #_Inp12Handler ; INT123
	.dw #_Dummy_EI ; INT124
	.dw #_Dummy_EI ; INT125
	.dw #_Dummy_EI ; INT126
	.dw #_Dummy_EI ; INT127
	.dw #_Dummy_EI ; INT128
	.dw #_Dummy_EI ; INT129
	.dw #_Dummy_EI ; INT130
	.dw #_Dummy_EI ; INT131
	.dw #_Dummy_EI ; INT132
	.dw #_Dummy_EI ; INT133
	.dw #_TAUB0CH0IntHandler ; INT134
	.dw #_TAUB0CH1IntHandler ; INT135
	.dw #_TAUB0CH2IntHandler ; INT136
	.dw #_Dummy_EI ; INT137
	.dw #_Dummy_EI ; INT138
	.dw #_Dummy_EI ; INT139
	.dw #_Dummy_EI ; INT140
	.dw #_Dummy_EI ; INT141
	.dw #_Dummy_EI ; INT142
	.dw #_Dummy_EI ; INT143
	.dw #_Dummy_EI ; INT144
	.dw #_Dummy_EI ; INT145
	.dw #_Dummy_EI ; INT146
	.dw #_Dummy_EI ; INT147
	.dw #_Dummy_EI ; INT148
	.dw #_Dummy_EI ; INT149
	.dw #_Dummy_EI ; INT150
	.dw #_Dummy_EI ; INT151
	.dw #_Dummy_EI ; INT152
	.dw #_Dummy_EI ; INT153
	.dw #_RLIN22IntHandler ; INT154
	.dw #_RLIN23IntHandler ; INT155
	.dw #_Dummy_EI ; INT156
	.dw #_Dummy_EI ; INT157
	.dw #_Dummy_EI ; INT158
	.dw #_Dummy_EI ; INT159
	.dw #_Dummy_EI ; INT160
	.dw #_Dummy_EI ; INT161
	.dw #_Dummy_EI ; INT162
	.dw #_Dummy_EI ; INT163
	.dw #_Dummy_EI ; INT164
	.dw #_Dummy_EI ; INT165
	.dw #_Dummy_EI ; INT166
	.dw #_Dummy_EI ; INT167
	.dw #_Dummy_EI ; INT168
	.dw #_Dummy_EI ; INT169
	.dw #_Dummy_EI ; INT170
	.dw #_Dummy_EI ; INT171
	.dw #_Dummy_EI ; INT172
	.dw #_Dummy_EI ; INT173
	.dw #_Dummy_EI ; INT174
	.dw #_Dummy_EI ; INT175
	.dw #_Dummy_EI ; INT176
	.dw #_Dummy_EI ; INT177
	.dw #_Dummy_EI ; INT178
	.dw #_Dummy_EI ; INT179
	.dw #_Dummy_EI ; INT180
	.dw #_Dummy_EI ; INT181
	.dw #_Dummy_EI ; INT182
	.dw #_Dummy_EI ; INT183
	.dw #_Dummy_EI ; INT184
	.dw #_Dummy_EI ; INT185
	.dw #_Dummy_EI ; INT186
	.dw #_Dummy_EI ; INT187
	.dw #_Dummy_EI ; INT188
	.dw #_Dummy_EI ; INT189
	.dw #_Dummy_EI ; INT190
	.dw #_Dummy_EI ; INT191
	.dw #_Dummy_EI ; INT192
	.dw #_Dummy_EI ; INT193
	.dw #_Dummy_EI ; INT194
	.dw #_Dummy_EI ; INT195
	.dw #_Dummy_EI ; INT196
	.dw #_Dummy_EI ; INT197
	.dw #_Dummy_EI ; INT198
	.dw #_Dummy_EI ; INT199
	.dw #_Dummy_EI ; INT200
	.dw #_RTCA01SIntHandler ; INT201
	.dw #_Dummy_EI ; INT202
	.dw #_Dummy_EI ; INT203
	.dw #_Dummy_EI ; INT204
	.dw #_Dummy_EI ; INT205
	.dw #_Dummy_EI ; INT206
	.dw #_Dummy_EI ; INT207
	.dw #_Dummy_EI ; INT208
	.dw #_RSCAN0CH2ErrorIntHandler ; INT209
	.dw #_RSCAN0CH2TrFIFORecvCompletionIntHandler ; INT210
	.dw #_RSCAN0CH2SendCompleteIntHandler ; INT211
	.dw #_RSCAN0CH3ErrorIntHandler ; INT212
	.dw #_RSCAN0CH3TrFIFORecvCompletionIntHandler ; INT213
	.dw #_RSCAN0CH3SendCompleteIntHandler ; INT214
	.dw #_Dummy_EI ; INT215
	.dw #_Dummy_EI ; INT216
	.dw #_Dummy_EI ; INT217
	.dw #_RLIN24IntHandler ; INT218
	.dw #_RLIN25IntHandler ; INT219
	.dw #_Dummy_EI ; INT220
	.dw #_Dummy_EI ; INT221
	.dw #_Dummy_EI ; INT222
	.dw #_Dummy_EI ; INT223
	.dw #_Dummy_EI ; INT224
	.dw #_Dummy_EI ; INT225
	.dw #_Dummy_EI ; INT226
	.dw #_Dummy_EI ; INT227
	.dw #_Dummy_EI ; INT228
	.dw #_Dummy_EI ; INT229
	.dw #_Dummy_EI ; INT230
	.dw #_Dummy_EI ; INT231
	.dw #_Dummy_EI ; INT232
	.dw #_Dummy_EI ; INT233
	.dw #_Dummy_EI ; INT234
	.dw #_Dummy_EI ; INT235
	.dw #_Dummy_EI ; INT236
	.dw #_Dummy_EI ; INT237
	.dw #_Dummy_EI ; INT238
	.dw #_Dummy_EI ; INT239
	.dw #_Dummy_EI ; INT240
	.dw #_Dummy_EI ; INT241
	.dw #_Dummy_EI ; INT242
	.dw #_Dummy_EI ; INT243
	.dw #_Dummy_EI ; INT244
	.dw #_Dummy_EI ; INT245
	.dw #_Dummy_EI ; INT246
	.dw #_Dummy_EI ; INT247
	.dw #_Dummy_EI ; INT248
	.dw #_Dummy_EI ; INT249
	.dw #_Dummy_EI ; INT250
	.dw #_Dummy_EI ; INT251
	.dw #_Dummy_EI ; INT252
	.dw #_Dummy_EI ; INT253
	.dw #_Dummy_EI ; INT254
	.dw #_Dummy_EI ; INT255
	.dw #_Dummy_EI ; INT256
	.dw #_Dummy_EI ; INT257
	.dw #_Dummy_EI ; INT258
	.dw #_Dummy_EI ; INT259
	.dw #_Dummy_EI ; INT260
	.dw #_Dummy_EI ; INT261
	.dw #_Dummy_EI ; INT262
	.dw #_Dummy_EI ; INT263
	.dw #_RSCAN0CH4ErrorIntHandler ; INT264
	.dw #_RSCAN0CH4TrFIFORecvCompletionIntHandler ; INT265
	.dw #_RSCAN0CH4SendCompleteIntHandler ; INT266
	.dw #_RLIN26IntHandler ; INT267
	.dw #_RLIN27IntHandler ; INT268
	.dw #_Dummy_EI ; INT269
	.dw #_Dummy_EI ; INT270
	.dw #_Dummy_EI ; INT271
	.dw #_Dummy_EI ; INT272
	.dw #_Dummy_EI ; INT273
	.dw #_Dummy_EI ; INT274
	.dw #_Dummy_EI ; INT275
	.dw #_Dummy_EI ; INT276
	.dw #_RLIN28IntHandler ; INT277
	.dw #_RLIN29IntHandler ; INT278
	.dw #_RSCAN0CH5ErrorIntHandler ; INT279
	.dw #_RSCAN0CH5TrFIFORecvCompletionIntHandler ; INT280
	.dw #_RSCAN0CH5SendCompleteIntHandler ; INT281
	.dw #_Dummy_EI ; INT282
	.dw #_Dummy_EI ; INT283
	.dw #_Dummy_EI ; INT284
	.dw #_Dummy_EI ; INT285
	.dw #_Dummy_EI ; INT286
	.dw #_Dummy_EI ; INT287

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
