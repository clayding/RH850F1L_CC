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

/*************************ADCA Specific Registers Label************************/
#define _VCR00              VCR00.UINT32
#define _DR00               DR00.UINT32
#define _DIR00              DIR00
#define _PWDVCR             PWDVCR
#define _PWDTSNDR           PWDTSNDR.UINT16[1]
#define _PWDDIR             PWDDIR
#define _ADHALTR            ADHALTR
#define _ADCR               ADCR.UINT32
#define _MPXCURR            MPXCURR.UINT32
#define _THSMPSTCR          THSMPSTCR.UINT32
#define _THCR               THCR.UINT32
#define _THAHLDSTCR         THAHLDSTCR.UINT32
#define _THBHLDSTCR         THBHLDSTCR.UINT32
#define _THACR              THACR.UINT32
#define _THBCR              THBCR.UINT32
#define _THER               THER.UINT32
#define _THGSR              THGSR.UINT32
#define _SMPCR              SMPCR.UINT8[0]
#define _SFTCR              SFTCR.UINT32
#define _ULLMTBR0           ULLMTBR0.UINT32
#define _ULLMTBR1           ULLMTBR1.UINT32
#define _ULLMTBR2           ULLMTBR2.UINT32
#define _ULMTBR0            ULLMTBR0.UINT16[1]
#define _ULMTBR1            ULLMTBR1.UINT16[1]
#define _ULMTBR2            ULLMTBR2.UINT16[1]
#define _LLMTBR0            ULLMTBR0.UINT16[0]
#define _LLMTBR1            ULLMTBR1.UINT16[0]
#define _LLMTBR2            ULLMTBR2.UINT16[0]
#define _ECR                ECR
#define _ULER               ULER
#define _OWER               OWER
/************************Scan Group (SG) Specific Registers Label**************/
#define _SGSTCR_BASE        SGSTCR1.UINT32
#define _SGCR_BASE          SGCR1.UINT32
#define _PWDSGCR            PWDSGCR.UINT32
#define _SGVCSP_BASE        SGVCSP1.UINT32
#define _SGVCEP_BASE        SGVCEP1.UINT32
#define _SGMCYCR_BASE       SGMCYCR1.UINT32
#define _PWDSGSEFCR         PWDSGSEFCR.UINT32
#define _SGSEFCR_BASE       SGSEFCR1.UINT32
#define _SGSTR              SGSTR.UINT32
#define _SGTSEL_BASE        _SGTSEL1

/**************************/
#define _DGCTL0             DGCTL0
#define _DGCTL1             DGCTL1
#define _PDCTL1             PDCTL1
#define _PDCTL2             PDCTL2


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
#define ADC_VCSP_MASK           ((uint32_t)0x3F) //Start Virtual Channel Pointer
/*ADCAnSGVCEPx — Scan Group x End Virtual Channel Pointer*/
#define ADC_VCEP_MASK           ((uint32_t)0x3F) //End Virtual Channel Pointer

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
#define ADC_CDGn_MASK(offset)   ((uint32_t)(0x01 << offset)) //Self-Diagnostic Channel Select

/*ADCAnPDCTL1 — Pull Down Control Register 1*/
#define ADC_PDNA_MASK           ((uint32_t)0xFF)    //Pull Down Enable Control

/*ADCAnPDCTL2 — Pull Down Control Register 2*/
#define ADC_PDNB_MASK           ((uint32_t)0xFF)    //Pull Down Enable Control

#define ADCAN_ADDR(_UNIT_)      (_UNIT_ == 0 ?_ADCA0_ADDR :_ADCA1_ADDR)
#define ADCAN_VAL(_UNIT_)       (_UNIT_ == 0 ?_ADCA0 :_ADCA1)

#define ADCA_VCR_ADDR(_N_,_J_)      ((uint32_t*)(&ADCAN_VAL(_N_)._VCR00) + _J_)
#define ADCA_VCR_VAL(_N_,_J_)       (*ADCA_VCR_ADDR(_N_,_J_))

#define ADCA_DR_ADDR(_N_,_J_)       ((uint32_t*)(&ADCAN_VAL(_N_)._DR00) + _J_)
#define ADCA_DR_VAL(_N_,_J_)        (*ADCA_DR_ADDR(_N_,_J_))

#define ADCA_DIR_ADDR(_N_,_J_)       ((uint32_t*)(&ADCAN_VAL(_N_)._DIR00) + _J_)
#define ADCA_DIR_VAL(_N_,_J_)        (*ADCA_DIR_ADDR(_N_,_J_))

/*ADCAnVCRj — Virtual Channel Register j*/
#define ADCA_SET_VC_CTL(_N_,_J_,_MASK_,_VALUE_)     (MODIFY_REG(ADCA_VCR_ADDR(_N_,_J_),_MASK_,_VALUE_))
#define ADCA_GET_VC_CTL(_N_,_J_,_MASK_)             (ADCA_VCR_VAL(_N_,_J_) & _MASK_)
/*ADCAnPWDVCR — PWM-Diag Virtual Channel Register,Note that bit8 and bit9 not defined*/
#define ADCA_SET_PWDVC_CTL(_N_)                     (MODIFY_REG((&ADCAN_VAL(_N_)._PWDVCR),_MASK_,_VALUE_))
#define ADCA_GET_PWDVC_CTL(_N_)                     (ADCAN_VAL(_N_)._PWDVCR & _MASK_)

/*ADCAnDRj — Data Register j, 32-/16-bit read-only register*/
#define ADCA_READ_DATA(_N_,_J_)                     (ADCA_DR_VAL(_N_,_J_))

/*ADCAnDIRj — Data Supplementary Information Register j,32-bit read-only register
only supported by ADCA0*/
#define ADCA_READ_DATA_INFO(N_,_J_,_MASK_)          (ADCA_DIR_VAL(_N_,_J_) & _MASK_)

/*ADCAnPWDTSNDR — PWM-Diag Data Register,32-/16-bit read-only,high 16 bits valid*/
#define ADCA_READ_PWD_DATA(_N_,_J_)                 (ADCAN_VAL(_N_)._PWDTSNDR)

/*ADCAnPWDDIR — PWM-Diag Data Supplementary Information Register*,32-bit read-only register
only supported for ADCA0*/
#define ADCA_READ_PWD_DATA_INFO(N_,_J_,_MASK_)      (ADCAN_VAL(_N_)._PWDDIR & _MASK_)

/*ADCAnADHALTR — A/D Force Halt Register,write-only register*/
#define ADCA_FORCE_HALT_TRIGGER(_N_)                (ADCAN_VAL(_N_)._ADHALTR |= ADC_HALT_MASK)

/*ADCAnADCR — A/D Control Register*/
#define ADCA_SET_COMMON_CTL(_N_,_MASK_,_VALUE_)     (MODIFY_REG((&ADCAN_VAL(_N_)._ADCR),_MASK_,_VALUE_))

/*ADCAnMPXCURR — MPX Current Register,read-only register
only ADCA0 supports this function*/
#define ADCA_GET_CURRENT_MPX(_N_)                   (ADCAN_VAL(_N_)._MPXCURR & ADC_MPXCUR_MASK)

/*ADCAnTHSMPSTCR — T&H Sampling Start Control Register, write-only register
control the start of sampling for all T&Hk (k = 0 to 5),only ADCA0 supports this function*/
#define ADCA_START_TH_SAMPLING_(_N_)                (ADCAN_VAL(_N_)._THSMPSTCR |= ADC_SMPST_MASK)
#define ADCA_START_TH_SAMPLING()                    ADCA_START_TH_SAMPLING_(0)

/*ADCAnTHCR — T&H Control Register,only ADCA0 supports this function.*/
#define ADCA_SET_AUTO_SAMPLING_(_N_,_ENABLE_)       do{ \
                                                        if(_ENABLE_) \
                                                            (ADCAN_VAL(_N_)._THCR |= ADC_ASMPMSK_MASK); \
                                                        else \
                                                            (ADCAN_VAL(_N_)._THCR &= ~ADC_ASMPMSK_MASK); \
                                                    }while(0)
#define ADCA_SET_AUTO_SAMPLING(_ENABLE_)            ADCA_SET_AUTO_SAMPLING_(0,_ENABLE_)

/*ADCAnTHAHLDSTCR — T&H Group A Hold Start Control Register,write-only register
ADCAnTHBHLDSTCR — T&H Group B Hold Start Control Register,write-only register
only ADCA0 supports this function*/
#define ADCA_START_THA_HOLD_(_N_)                   (ADCAN_VAL(_N_)._THAHLDSTCR |= ADC_HLDST_MASK)
#define ADCA_START_THB_HOLD_(_N_)                   (ADCAN_VAL(_N_)._THBHLDSTCR |= ADC_HLDST_MASK)
#define ADCA_START_THA_HOLD()                       ADCA_START_THA_HOLD_(0)
#define ADCA_START_THB_HOLD()                       ADCA_START_THB_HOLD_(0)

/*ADCAnTHACR — T&H Group A Control Register,only ADCA0 supports this function
ADCAnTHBCR — T&H Group B Control Register,only ADCA0 supports this function*/
#define ADCA_SET_THA_CTL_(_N_)                      (MODIFY_REG((&ADCAN_VAL(_N_)._THACR),_MASK_,_VALUE_))
#define ADCA_SET_THB_CTL_(_N_)                      (MODIFY_REG((&ADCAN_VAL(_N_)._THBCR),_MASK_,_VALUE_))
#define ADCA_SET_THA_CTL()                          ADCA_SET_THA_CTL_(0)
#define ADCA_SET_THB_CTL()                          ADCA_SET_THB_CTL_(0)

/*ADCAnTHER — T&H Enable Register,ADCAnTHER — T&H Enable Register,only ADCA0 supports this function*/
#define ADCA_TH_ENABLE_(_N_)                        (ADCAN_VAL(_N_)._THER |= (0x01 << _INDEX_) & 0x3F)
#define ADCA_TH_DISABLE_(_N_)                       (ADCAN_VAL(_N_)._THER &= ~((0x01 << _INDEX_) & 0x3F))
#define ADCA_TH_ENABLE()                            ADCA_TH_ENABLE_(0)
#define ADCA_TH_DISABLE()                           ADCA_TH_DISABLE_(0)

/*ADCAnTHGSR — T&H Group Select Register,only ADCA0 supports this function*/
#define ADCA_TH_SELECT_(_N_)                        (ADCAN_VAL(_N_)._THGSR |= (0x01 << _INDEX_) & 0x3F)
#define ADCA_TH_DESELECT_(_N_)                      (ADCAN_VAL(_N_)._THGSR &= ~((0x01 << _INDEX_) & 0x3F))
#define ADCA_TH_SELECT()                            ADCA_TH_SELECT_(0)
#define ADCA_TH_DESELECT()                          ADCA_TH_DESELECT_(0)

/*ADCAnSMPCR — Sampling Control Register,used to set the sampling time (the number of cycles)
12H, or 18H shouled be set,settings other than above are prohibited*/
#define ADCA_SET_SAMPLING_TIME(_N_)                 (ADCAN_VAL(_N_)._SMPCR |= (0x01 << _INDEX_) & ADC_SMPT_MASK)
#define ADCA_GET_SAMPLING_TIME(_N_)                 (ADCAN_VAL(_N_)._SMPCR |= (0x01 << _INDEX_) & ADC_SMPT_MASK)
#define IS_SAMPLING_TIME(_TIME_)                    ( ((_TIME_) == 0x12)|| \
                                                      ((_TIME_) == 0x18) )
/*ADCAnSFTCR — Safety Control Register*/
#define ADCA_SET_SAFETY_CTL(_N_,_MASK_,_VALUE_)     (MODIFY_REG((&ADCAN_VAL(_N_)._SFTCR),_MASK_,_VALUE_))
#define ADCA_GET_SAFETY_CTL(_N_,_MASK_)             (ADCAN_VAL(_N_)._SFTCR & _MASK_)

/*ADCAnULLMTBR0 to 2 — Upper Limit/Lower Limit Table Registers 0 to 2
_REG_INDEX:0,1 ,2*/
#define ADCA_SET_UPPER_LIMIT(_N_,_REGx_,_VALUE_)    (ADCAN_VAL(_N_)._ULMTBR##_REGx_ = (_VALUE_ << ADC_ULMTB_OFFSET) \
                                                        & ADC_ULMTB_MASK)
#define ADCA_SET_LOWER_LIMIT(_N_,_REGx_,_VALUE_)    (ADCAN_VAL(_N_)._LLMTBR##_REGx_ = (_VALUE_ << ADC_LLMTB_OFFSET) \
                                                        & ADC_LLMTB_MASK)
#define ADCA_GET_LOWER_LIMIT(_N_,_REGx_)            (ADCAN_VAL(_N_)._ULLMTBR##_REGx_)

/*ADCAnECR — Error Clear Register,control clearing of an error, write-only register*/
#define ADCA_CLEAR_ERROR(_N_)                       (MODIFY_REG((&ADCAN_VAL(_N_)._ECR),_MASK_,_VALUE_))

/*ADCAnULER — Upper Limit/Lower Limit Error Register,read-only register,
several bits are only supported for ADCA0*/
#define ADCA_GET_ULLIMIT_ERR_INFO(_N_,_MASK_)       (ADCAN_VAL(_N_)._ULER & _MASK_)

/*ADCAnOWER — Overwrite Error Register,32/16/8-bit read-only register*/
#define ADCA_GET_OVERWRITE_ERR(_N_,_MASK_)          (ADCAN_VAL(_N_)._OWER & _MASK_)

/********************Scan Group (SG) Specific Registers Operation**************/
#define ADCAN_SGx_ADDR(_N_,_X_,_REG_BASE_)          ((uint32_t*)(&ADCAN_VAL(_N_)._REG_BASE_) + ((_X_- 1) *0x10)) //the _X_ from 1 to 3 --> _X_ -1
#define ADCAN_SGx_VAL(_N_,_X_,_REG_BASE_)           (*ADCAN_SGx_ADDR(_X_,_REG_BASE_))
/*ADCAnSGSTCRx — Scan Group x Start Control Register,write-only register
_X_: 1 to 3*/
#define ADCA_START_SGx(_N_,_X_)                     (ADCAN_SGx_VAL(_N_,_X_,_SGSTCR_BASE) |= ADC_SGST_MASK)

/*ADCAnSGCRx — Scan Group x Control Register*/
#define ADCA_SET_SGx_CTL(_N_,_X_,_MASK_,_VALUE_)    (MODIFY_REG(ADCAN_SGx_ADDR(_N_,_X_,_SGCR_BASE),_MASK_,_VALUE_))
#define ADCA_GET_SGx_CTL(_N_,_X_,_MASK_)            (ADCAN_SGx_VAL(_N_,_X_,_SGCR_BASE) & _MASK_)

/*ADCAnPWDSGCR — PWM-Diag Scan Group Control Register*/
#define ADCA_SELECT_PWD_TRIGGER_MODE(_N_,_BIT_VAL_) do{ \
                                                        if(_BIT_VAL_) \
                                                            (ADCAN_VAL(_N_)._PWDSGCR |= ADC_PWDTRGMD_MASK); \
                                                        else \
                                                            (ADCAN_VAL(_N_)._PWDSGCR &= ~ADC_PWDTRGMD_MASK); \
                                                    }while(0)
/*ADCAnSGVCSPx — Scan Group x Start Virtual Channel Pointer*/
#define ADCA_SET_START_POINTER(_N_,_X_,_VALUE_)     (ADCAN_SGx_VAL(_N_,_X_,_SGVCSP_BASE) = _VALUE_ & ADC_VCSP_MASK)
#define ADCA_GET_START_POINTER(_N_,_X_)             (ADCAN_SGx_VAL(_N_,_X_,_SGVCSP_BASE) & ADC_VCSP_MASK)
/*ADCAnSGVCEPx — Scan Group x End Virtual Channel Pointer*/
#define ADCA_SET_END_POINTER(_N_,_X_,_VALUE_)       (ADCAN_SGx_VAL(_N_,_X_,_SGVCEP_BASE) = _VALUE_ & ADC_VCEP_MASK)
#define ADCA_GET_END_POINTER(_N_,_X_,_VALUE_)       (ADCAN_SGx_VAL(_N_,_X_,_SGVCEP_BASE) & ADC_VCEP_MASK)

#define IS_START_POINTER_VALUE(N_,_X_,_VALUE_)      (_VALUE_ <= ADCA_GET_END_POINTER(_N_,_X_,_VALUE_) )
#define IS_END_POINTER_VALUE(N_,_X_,_VALUE_)        (_VALUE_ >= ADCA_GET_START_POINTER(_N_,_X_,_VALUE_))

/*ADCAnSGMCYCRx — Scan Group x Multicycle Register*/
#define ADCA_SET_SCAN_TIME(_N_,_X_,_TIMES_)         (ADCAN_SGx_VAL(_N_,_X_,_SGMCYCR_BASE)  = _TIMES_ & ADC_MCYC_MASK)
#define ADCA_GET_SCAN_TIME(_N_,_X_)                 (ADCAN_SGx_VAL(_N_,_X_,_SGMCYCR_BASE) & ADC_MCYC_MASK)

/*DCAnPWDSGSEFCR — PWM-Diag Scan End Flag Clear Register,write-only register
to clear of PWM-Diag scan end flag (SEF)*/
#define ADCA_CLEAR_PWD_SCAN_END_FLAG(_N_)           (ADCAN_VAL(_N_)._PWDSGSEFCR  |= ADC_PWDSEFC_MASK)

/*ADCAnSGSEFCRx — Scan Group x Scan End Flag Clear Register*/
#define ADCA_CLEAR_SGx_SCAN_END_FLAG(_N_,_X_)       (ADCAN_SGx_VAL(_N_,_X_,_SGSEFCR_BASE)  |= ADC_SEFC_MASK)

/*ADCAnSGSTR — Scan Group Status Register,read-only register*/
#define ADCA_GET_SG_STAT(_N_,_MASK_)                (ADCAN_VAL(_N_)._SGSTR & _MASK_)

/******************Hardware Trigger Specific Register Operation****************/
/*ADCAnSGTSELx — Scan Group x Start Trigger Control Register x*/
#define ADCA_ENABLE_HARDWARE_TRIGGER(_N_,_X_,_P_)   (ADCAN_SGx_VAL(_N_,_X_,_SGTSEL_BASE)  = ADC_TxSELp_MASK(_P_))
#define ADCA_DISABLE_HARDWARE_TRIGGER(_N_,_X_,_P_)  (ADCAN_SGx_VAL(_N_,_X_,_SGTSEL_BASE)  &= ~ADC_TxSELp_MASK(_P_))

/*Self-Diagnosis Specific Registers,controls the self-diagnostic voltage level*/
#define ADCA_SELECT_Self-Diag_VOLT_LEVEL(_N_,_VALUE_)       (ADCAN_VAL(_N_)._DGCTL0 = _VALUE_ & ADC_PSEL_MASK)

/*ADCAnDGCTL1 — Self-Diagnosis Control Register 1*/
#define ADCA_SELECT_Self-Diag_CHANNEL(_N_,_MASK_,_VALUE_)   (MODIFY_REG(&(ADCAN_VAL(_N_)._DGCTL1),_MASK_,_VALUE_))

/*ADCAnPDCTL1 — Pull Down Control Register 1*/
#define ADCA_ENABLE_PULL_DOWN_L(_N_,_MASK_,_VALUE_)  (MODIFY_REG(&(ADCAN_VAL(_N_)._PDCTL1),_MASK_,_VALUE_))
#define ADCA_ENABLE_PULL_DOWN_H(_N_,_MASK_,_VALUE_)  (MODIFY_REG(&(ADCAN_VAL(_N_)._PDCTL2),_MASK_,_VALUE_))

union{
    uint32_t opctl;
    struct{
        uint32_t SUSMTD     :2;     //Suspend Mode Select
        uint32_t            :2
        uint32_t CTYP       :1;     //12/10 Bit Select Mode
        uint32_t CRAC       :1;     //Alignment Control
        uint32_t            :1;
        uint32_t DGON       :1;     //Self-Diagnostic Voltage Standby Control
        uint32_t            :24;    //Reserved
    }reg_bits;
    struct{
        uint32_t susp_mode  :2;     //Suspend Mode Select
        uint32_t            :2
        uint32_t bit_mode   :1;     //Transmit/Receive FIFO Receive Interrupt Enable
        uint32_t alin_fmt   :1;     //Transmit/Receive FIFO Transmit Interrupt Enable
        uint32_t            :1;     //Reserved
        uint32_t sd_volt    :1;     //Transmit/Receive FIFO Buffer Depth Configuration
        uint32_t            :24;    //Reserved
    }param_bits;
}ADCA_OptCtlUnion;


union{
    uint32_t safectl;
    struct{
        uint32_t            :2;     //Reserved
        uint32_t OWEIE      :1      //A/D Error Interrupt (INT_ADE) Enable on Overwrite Error Detection
        uint32_t ULEIE      :1;     //A/D Error Interrupt (INT_ADE) Enable on Upper/Lower Limit Error Detection
        uint32_t RDCLRE     :1;     //Read & Clear Enable
        uint32_t            :27;
    }reg_bits;
    struct{
        uint32_t            :2;     //Reserved
        uint32_t ow_int     :1      //A/D Error Interrupt (INT_ADE) Enable on Overwrite Error Detection
        uint32_t ul_int     :1;     //A/D Error Interrupt (INT_ADE) Enable on Upper/Lower Limit Error Detection
        uint32_t rc_en      :1;     //Read & Clear Enable
        uint32_t            :27;
    }param_bits;
}ADCA_SafeCtlUnion;

typedef struct{
    uint16_t ulimit[3];
    uint16_t llimit[3];
}ADCA_ULLimitSetTypeDef;



typedef struct{
    uint8_t vh;                 //virtual channel
    ADCA_OptCtlUnion opt_ctl;   //ADC common operation control
    uint8_t sampling_time;      //the sampling time (the number of cycles)
    ADCA_SafeCtlUnion safe_ctl;
    ADCA_ULLimitSetTypeDef *ullimit;

}ADCA_InitTypeDef;
