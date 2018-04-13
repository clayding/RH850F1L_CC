/**
  ******************************************************************************
  * @file    rh850f1l_adc.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    12-April-2018
  * @brief   Header file of ADCA module.
  ******************************************************************************
  */
#define _ADCA0              ADCA0
#define _ADCA1              ADCA1
#define _ADCA0_ADDR         ((volatile struct __tag49 *)&ADCA0)
#define _ADCA1_ADDR         ((volatile struct __tag49 *)&ADCA1)

/*ADCAnVCRj — Virtual Channel Register j*/
/*ADCAnPWDVCR — PWM-Diag Virtual Channel Register,Note that bit8 and bit9 not defined*/
#define ADC_VCR_MPXE_OFFSET     15  //MPX Enable,only supported for ADCA0
#define ADC_VCR_MPXV_OFFSET     12  //set the MPX value to be transferred to an external analog multiplexer,only supported for ADCA0
#define ADC_CNVCLS_OFFSET       9   //A/D Conversion Type Select for Self-Diagnosis,only supported when j = 33 to 35
#define ADC_ADIE_OFFSET         8   //A/D Conversion End Interrupt Enable
#define ADC_ULS_OFFSET          6   //Upper Limit/Lower Limit Table Select

#define ADC_VCR_MPXE_MASK       ((uint32_t)(0x01 << ADC_MPXE_OFFSET))
#define ADC_VCR_MPXV_MASK       ((uint32_t)(0x07 << ADC_MPXV_OFFSET))
#define ADC_CNVCLS_MASK         ((uint32_t)(0x01 << ADC_CNVCLS_OFFSET))
#define ADC_ADIE_MASK           ((uint32_t)(0x01 << ADC_ADIE_OFFSET))
#define ADC_ULS_MASK            ((uint32_t)(0x03 << ADC_ULS_OFFSET))
#define ADC_GCTRL_MASK          ((uint32_t)0x03F)//Physical Channel Select

/*ADCAnDRj — Data Register j, 32-/16-bit read-only register*/
#define ADC_DR_H                ((uint32_t)(0xFFFF << 16))
#define ADC_DR_L                ((uint32_t)0xFFFF)

/*ADCAnDIRj — Data Supplementary Information Register j, 32-bit read-only register*/
/*ADCAnPWDDIR — PWM-Diag Data Supplementary Information Register, 32-bit read-only register*/
#define ADC_DIR_MPXE_OFFSET     31  //MPX Enable Flag,only supported for ADCA0
#define ADC_DIR_MPVR_OFFSET     28  //MPX value of the most recent conversion result,only supported for ADCA0
#define ADC_WFLG_OFFSET         25  //Write Flag
#define ADC_ID_OFFSET           16  //store the physical channel number (GCTRL) corresponding to the conversion result

#define ADC_DIR_MPXE_MASK       ((uint32_t)(0x01 << ADC_DIR_MPXE_OFFSET))
#define ADC_DIR_MPVR_MASK       ((uint32_t)(0x07 << ADC_DIR_MPVR_OFFSET))
#define ADC_WFLG_MASK           ((uint32_t)(0x01 << ADC_WFLG_OFFSET))
#define ADC_ID_MASK             ((uint32_t)(0x3F << ADC_ID_OFFSET))
#define ADC_DR_MASK             ((uint32_t)0xFFFF) //used to store the A/D conversion result
#define ADC_PWDDR_MASK          ADC_DR_MASK //used to store the A/D conversion result for PWM-Diag.

/*ADCAnPWDTSNDR — PWM-Diag Data Register,32-/16-bit read-only register*/
#define ADC_PWDDR_MASK          ((uint32_t)(0xFFFF << 16))

/*ADCAnADHALTR — A/D Force Halt Register*/
#define ADC_HALT_MASK           ((uint32_t)0x01) //ADCA Force Halt Trigger


/*ADCAnADCR — A/D Control Register*/
#define ADC_DGON_OFFSET         7   //Self-Diagnostic Voltage Standby Control
#define ADC_CRAC_OFFSET         5   //Alignment Control
#define ADC_CTYP_OFFSET         4   //12/10 Bit Select Mode

#define ADC_DGON_MASK           ((uint32_t)(0x01 << ADC_DGON_OFFSET))
#define ADC_CRAC_MASK           ((uint32_t)(0x01 << ADC_CRAC_OFFSET))
#define ADC_CTYP_MASK           ((uint32_t)(0x01 << ADC_CTYP_OFFSET))
#define ADC_SUSMTD_MASK         ((uint32_t)0x03) //Suspend Mode Select

/*ADCAnMPXCURR — MPX Current Register, read-only register,only ADCA0 supports this function*/
#define ADC_MPXCUR_MASK         ((uint32_t)0x07) // used to store the current MPX value

/*ADCAnTHSMPSTCR — T&H Sampling Start Control Register, write-only register*/
#define ADC_SMPST_MASK         ((uint32_t)0x01) //T&H Sampling Start Control Trigger

/* ADCAnTHCR — T&H Control Register,only ADCA0 supports this function*/
#define ADC_ASMPMSK_MASK       ((uint32_t)0x01) //Automatic Sampling Mask Control

/*ADCAnTHAHLDSTCR — T&H Group A Hold Start Control Register,write-only register
ADCAnTHBHLDSTCR — T&H Group B Hold Start Control Register,write-only register
only ADCA0 supports this function*/
#define ADC_HLDST_MASK         ((uint32_t)0x01) //T&H Group A/B Hold Start Control Trigger

/*ADCAnTHACR — T&H Group A Control Register
ADCAnTHBCR — T&H Group B Control Register*/
#define ADC_HLDCTE_OFFSET       5   //T&H Group A/B Hold Completion Trigger Enable
#define ADC_HLDTE_OFFSETT       4   //T&H Group A/B Hold Trigger Enable

#define ADC_HLDCTE_MASK         ((uint32_t)(0x01 << ADC_HLDCTE_OFFSET))
#define ADC_HLDTE_MASK          ((uint32_t)(0x01 << ADC_HLDTE_OFFSETT))
#define ADC_SGS_MASK            ((uint32_t)0x03) //T&H Group A/B Scan Group Select

/*ADCAnTHER — T&H Enable Register,only ADCA0 supports this function*/
#define ADC_TH5E_OFFSET         5   //T&H5 Enable
#define ADC_TH4E_OFFSET         4   //T&H4 Enable
#define ADC_TH3E_OFFSET         3   //T&H3 Enable
#define ADC_TH2E_OFFSET         2   //T&H2 Enable
#define ADC_TH1E_OFFSET         1   //T&H1 Enable

#define ADC_TH5E_MASK           ((uint32_t)(0x01 << ADC_TH5E_OFFSET))
#define ADC_TH4E_MASK           ((uint32_t)(0x01 << ADC_TH4E_OFFSET))
#define ADC_TH3E_MASK           ((uint32_t)(0x01 << ADC_TH3E_OFFSET))
#define ADC_TH2E_MASK           ((uint32_t)(0x01 << ADC_TH2E_OFFSET))
#define ADC_TH1E_MASK           ((uint32_t)(0x01 << ADC_TH1E_OFFSET))
#define ADC_TH0E_MASK           ((uint32_t)0x01) //T&H0 Enable

/*ADCAnTHGSR — T&H Group Select Register,only ADCA0 supports this function*/
#define ADC_TH5GS_OFFSET         5   //T&H5 Group Select
#define ADC_TH4GS_OFFSET         4   //T&H4 Group Select
#define ADC_TH3GS_OFFSET         3   //T&H3 Group Select
#define ADC_TH2GS_OFFSET         2   //T&H2 Group Select
#define ADC_TH1GS_OFFSET         1   //T&H1 Group Select

#define ADC_TH5GS_MASK           ((uint32_t)(0x01 << ADC_TH5GS_OFFSET))
#define ADC_TH4GS_MASK           ((uint32_t)(0x01 << ADC_TH4GS_OFFSET))
#define ADC_TH3GS_MASK           ((uint32_t)(0x01 << ADC_TH3GS_OFFSET))
#define ADC_TH2GS_MASK           ((uint32_t)(0x01 << ADC_TH2GS_OFFSET))
#define ADC_TH1GS_MASK           ((uint32_t)(0x01 << ADC_TH1GS_OFFSET))
#define ADC_TH0GS_MASK           ((uint32_t)0x01) //T&H0 Group Select

/*ADCAnSMPCR — Sampling Control Register*/
#define ADC_SMPT_MASK            ((uint32_t)0xFF) //used to set the sampling time (the number of cycles)

/*ADCAnSFTCR — Safety Control Register*/
#define ADC_RDCLRE_OFFSET       4
#define ADC_ULEIE_OFFSET        3
#define ADC_OWEIE_OFFSET        2

#define ADC_RDCLRE_MASK         ((uint32_t)(0x01 << ADC_RDCLRE_OFFSET))
#define ADC_ULEIE_MASK          ((uint32_t)(0x01 << ADC_ULEIE_OFFSET))
#define ADC_OWEIE_MASK          ((uint32_t)(0x01 << ADC_OWEIE_OFFSET))

/*ADCAnULLMTBR0 to 2 — Upper Limit/Lower Limit Table Registers 0 to 2*/
#define ADC_ULMTB_OFFSET        20 //Upper Limit Table
#define ADC_LLMTB_OFFSET        4  //Lower Limit Table

#define ADC_ULMTB_MASK          ((uint32_t)(0xFFF << ADC_ULMTB_OFFSET))
#define ADC_LLMTB_MASK          ((uint32_t)(0xFFF << ADC_LLMTB_OFFSET))

/*ADCAnECR — Error Clear Register,write-only register*/
#define ADC_ULEC_OFFSET         3 //Upper/Lower Limit Error Flag Clear
#define ADC_OWEC_OFFSET         2 //Overwrite Error Flag Clear

#define ADC_ULEC_MASK           ((uint32_t)(0x01 << ADC_ULEC_OFFSET))
#define ADC_OWEC_MASK           ((uint32_t)(0x01 << ADC_OWEC_OFFSET))

/*ADCAnULER — Upper Limit/Lower Limit Error Register*/
#define ADC_UE_OFFSET           15  //Upper Limit Error Flag
#define ADC_LE_OFFSET           14  //Lower Limit Error Flag
#define ADC_ULSG_OFFSET         12  //Scan Group where an Upper Limit/Lower Limit Error Occurs
#define ADC_MPXE_OFFSET         11  //MPX Usage, only supported for ADCA0
#define ADC_MPXV_OFFSET         8   //The value of MPX is stored when the errors of the upper and lower limit occurred
                                    //only supported for ADCA0

#define ADC_UE_MASK             ((uint32_t)(0x01 << ADC_UE_OFFSET))
#define ADC_LE_MASK             ((uint32_t)(0x01 << ADC_LE_OFFSET))
#define ADC_ULSG_MASK           ((uint32_t)(0x03 << ADC_ULSG_OFFSET))
#define ADC_MPXE_MASK           ((uint32_t)(0x01 << ADC_MPXE_OFFSET))
#define ADC_MPXV_MASK           ((uint32_t)(0x07 << ADC_MPXV_OFFSET))
#define ADC_ULECAP_MASK         ((uint32_t)0x3F) //Upper Limit/Lower Limit Error Capture

/*ADCAnOWER — Overwrite Error Register,  32/16/8-bit read-only register*/
#define ADC_OWE_OFFSET          7 //Overwrite Error Flag

#define ADC_OWE_MASK            ((uint32_t)(0x01 << ADC_OWE_OFFSET))
#define ADC_OWECAP_MASK         ((uint32_t)0x3F) //Overwrite Error Capture

/*ADCAnSGSTCRx — Scan Group x Start Control Register*/
#define ADC_SGST_MASK            ((uint32_t)0x01) //Writing 1 to SGST starts the target SGx.

/*ADCAnSGCRx — Scan Group x Control Register*/
#define ADC_SCANMD_OFFSET       5   //Scan Mode
#define ADC_ADIE_OFFSET         4   //Scan End Interrupt Enable
#define ADC_SCT_OFFSET          2   //Channel Repeat Times Select

#define ADC_SCANMD_MASK         ((uint32_t)(0x01 << ADC_SCANMD_OFFSET))
#define ADC_ADIE_MASK           ((uint32_t)(0x01 << ADC_ADIE_OFFSET))
#define ADC_SCT_MASK            ((uint32_t)(0x03 << ADC_SCT_OFFSET))
#define ADC_TRGMD_MASK          ((uint32_t)0x01) //Trigger Mode

/*ADCAnPWDSGCR — PWM-Diag Scan Group Control Register*/
#define ADC_PWDTRGMD_MASK       ((uint32_t)0x01) //PWM-Diag Trigger Mode Select

/*ADCAnSGVCSPx — Scan Group x Start Virtual Channel Pointer*/
#define ADC_VCSP_MASK           ((uint32_t)0x01) //Start Virtual Channel Pointer
/*ADCAnSGVCEPx — Scan Group x End Virtual Channel Pointer*/
#define ADC_VCEP_MASK           ((uint32_t)0x01) //End Virtual Channel Pointer

/*ADCAnSGMCYCRx — Scan Group x Multicycle Register*/
#define ADC_MCYC_MASK           ((uint32_t)0x03) //Multicycle Number Specification

/*ADCAnPWDSGSEFCR — PWM-Diag Scan End Flag Clear Register,write-only*/
#define ADC_PWDSEFC_MASK        ((uint32_t)0x01) //PWM-Diag Scan End Flag Clear Trigger

/*ADCAnSGSEFCRx — Scan Group x Scan End Flag Clear Register, write-only register*/
#define ADC_PWDSEFC_MASK        ((uint32_t)0x01) //Scan End Flag Clear Trigger

/*ADCAnSGSTR — Scan Group Status Register,read-only register*/
#define ADC_TH_STAT_OFFSET      14  //T&H Status Flag
#define ADC_SVSTOP_STAT_OFFSET  13  //SVSTOP Status Flag
#define ADC_SG4_STAT_OFFSET     12  //PWM-Diag Scan Group (SG4) Status Flag
#define ADC_SG3_STAT_OFFSET     11  //Scan Group 3 (SG3) Status Flag
#define ADC_SG2_STAT_OFFSET     10  //Scan Group 2 (SG2) Status Flag
#define ADC_SG1_STAT_OFFSET     9   //Scan Group 1 (SG1) Status Flag
#define ADC_PWD_SCANEND_OFFSET  4   //PWM-Diag Scan End Flag
#define ADC_SG3_SCANEND_OFFSET  3   //SG3 Scan End Flag
#define ADC_SG2_SCANEND_OFFSET  2   //SG2 Scan End Flag
#define ADC_SG1_SCANEND_OFFSET  1   //SG1 Scan End Flag

#define ADC_TH_STAT_MASK        ((uint32_t)(0x01 << ADC_TH_STAT_OFFSET))
#define ADC_SVSTOP_STAT_MASK    ((uint32_t)(0x01 << ADC_SVSTOP_STAT_OFFSET))
#define ADC_SG4_STAT_MASK       ((uint32_t)(0x01 << ADC_SG4_STAT_OFFSET))
#define ADC_SG3_STAT_MASK       ((uint32_t)(0x01 << ADC_SG3_STAT_OFFSET))
#define ADC_SG2_STAT_MASK       ((uint32_t)(0x01 << ADC_SG2_STAT_OFFSET))
#define ADC_SG1_STAT_MASK       ((uint32_t)(0x01 << ADC_SG1_STAT_OFFSET))
#define ADC_PWD_SCANEND_MASK    ((uint32_t)(0x01 << ADC_PWD_SCANEND_OFFSET))
#define ADC_SG3_SCANEND_MASK    ((uint32_t)(0x01 << ADC_SG3_SCANEND_OFFSET))
#define ADC_SG2_SCANEND_MASK    ((uint32_t)(0x01 << ADC_SG2_SCANEND_OFFSET))
#define ADC_SG1_SCANEND_MASK    ((uint32_t)(0x01 << ADC_SG1_SCANEND_OFFSET))

/*ADCAnSGTSELx — Scan Group x Start Trigger Control Register x*/
#define ADC_TxSELp_MASK(p)      ((uint32_t)0x01 << p) //A/D Conversion Trigger (Hardware Trigger) Select

/*ADCAnDGCTL0 — Self-Diagnosis Control Register 0*/
#define ADC_PSEL_MASK           ((uint32_t)0x07)    //Self-Diagnostic Voltage Level Select

/*ADCAnDGCTL1 — Self-Diagnosis Control Register 1*/
#define ADC_CDGn_MASK(n)        ((uint32_t)(0x01 << n)) //Self-Diagnostic Channel Select

/*ADCAnPDCTL1 — Pull Down Control Register 1*/
#define ADC_PDNA_MASK           ((uint32_t)0xFF)    //Pull Down Enable Control

/*ADCAnPDCTL2 — Pull Down Control Register 2*/
#define ADC_PDNB_MASK           ((uint32_t)0xFF)    //Pull Down Enable Control

#define ADCAN_ADDR(_UNIT_)      (_UNIT_ == 0 ?_ADCA0_ADDR :_ADCA1_ADDR)
#define ADCAN_VAL(_UNIT_)       (_UNIT_ == 0 ?_ADCA0 :_ADCA1)

#define ADCA_VCR_ADDR(_N_,_J_)      ((uint32_t*)(&ADCAN_VAL(_N_).VCR00.UINT32) + _J_)
#define ADCA_VCR_VAL(_N_,_J_)       (*ADCA_VCR_ADDR(_N_,_J_))

#define ADCA_DR_ADDR(_N_,_J_)       ((uint32_t*)(&ADCAN_VAL(_N_).DR00.UINT32) + _J_)
#define ADCA_DR_VAL(_N_,_J_)        (*ADCA_DR_ADDR(_N_,_J_))

/*ADCAnVCRj — Virtual Channel Register j*/
#define ADCA_SET_VC_CTL(_N_,_J_,_MASK_,_VALUE_)     (MODIFY_REG(ADCA_VCR_ADDR(_N_,_J_),_MASK_,_VALUE_))
#define ADCA_GET_VC_CTL(_N_,_J_,_MASK_)             (ADCA_VCR_VAL(_N_,_J_) & _MASK_)
/*ADCAnPWDVCR — PWM-Diag Virtual Channel Register,Note that bit8 and bit9 not defined*/
#define ADCA_SET_PWDVC_CTL(_N_)                     (MODIFY_REG((&ADCAN_VAL(_N).PWDVCR),_MASK_,_VALUE_))
#define ADCA_GET_PWDVC_CTL(_N_)                     (DCAN_VAL(_N).PWDVCR & _MASK_)

/*ADCAnDRj — Data Register j, 32-/16-bit read-only register*/
#define ADCA_READ_DATA(_N_,_J_)                     (ADCA_VCR_VAL(_N_,_J_) & _MASK_)
