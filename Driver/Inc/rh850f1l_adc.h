/**
  ******************************************************************************
  * @file    rh850f1l_adc.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    12-April-2018
  * @brief   Header file of ADCA module.
  ******************************************************************************
  */

#ifndef RH850F1L_ADC_H
#define RH850F1L_ADC_H
#include "rh850f1l.h"

/*****************************ADCAn Configuration Area*************************/

#ifdef RH850f1l_176PIN_USED

//ADCAn n = 0 or 1
#define ADCA_0								0
#define ADCA_1								1

#define _ADCA0_VAL         					ADCA0 //defined in iodefine.h
#define _ADCA1_VAL          				ADCA1 //defined in iodefine.h

#define _ADCA0_ADDR         				((volatile struct __tag49 *)&ADCA0) //defined in iodefine.h
#define _ADCA1_ADDR         				((volatile struct __tag50 *)&ADCA1)	//defined in iodefine.h

#define ADCA_SG_INDEX_MIN					1	// Scan Group smallest index
#define ADCA_SG_INDEX_MAX					3	// Scan Group largest index

#define ADCA0_PHY_CH_NUM_MAX           		36	//the number of physical channel in ANCA0
#define ADCA0_VIR_CH_NUM_MAX            	50	//the number of virtual channel in ANCA0
#define ADCA1_PHY_CH_NUM_MAX           		24	//the number of physical channel in ANCA1
#define ADCA1_VIR_CH_NUM_MAX            	24  //the number of virtual channel in ANCA1

#define ADCA_UNIT_NUM_MAX                   2 	//ADCA0 and ADCA1
#define ADCAn_PHY_CH_NUM_MAX				ADCA0_PHY_CH_NUM_MAX //used for define the array
#define ADCAn_VIR_CH_NUM_MAX				ADCA0_VIR_CH_NUM_MAX //used for define the array

#endif

/*************************ADCA Specific Registers Label************************/
#define _VCR00              VCR00.UINT32
#define _DR00               DR00.UINT32
#define _DIR00              DIR00
#define _PWDVCR             PWDVCR.UINT32
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
#define _ECR                ECR.UINT32
#define _ULER               ULER.UINT32
#define _OWER               OWER.UINT32
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
#define _SGTSEL_BASE        SGTSEL1

/************************Self-Diagnosis Specific Registers*********************/
#define _DGCTL0             DGCTL0.UINT32
#define _DGCTL1             DGCTL1.UINT32
#define _PDCTL1             PDCTL1.UINT32
#define _PDCTL2             PDCTL2.UINT32


/*ADCAnVCRj - Virtual Channel Register j*/
/*ADCAnPWDVCR - PWM-Diag Virtual Channel Register,Note that bit8 and bit9 not defined*/
#define ADC_VCR_MPXE_OFFSET     15  //MPX Enable,only supported for ADCA0
#define ADC_VCR_MPXV_OFFSET     12  //set the MPX value to be transferred to an external analog multiplexer,only supported for ADCA0
#define ADC_CNVCLS_OFFSET       9   //A/D Conversion Type Select for Self-Diagnosis,only supported when j = 33 to 35
#define ADC_VCR_ADIE_OFFSET     8   //A/D Conversion End Interrupt Enable
#define ADC_ULS_OFFSET          6   //Upper Limit/Lower Limit Table Select

#define ADC_VCR_MPXE_MASK       ((uint32_t)(0x01 << ADC_MPXE_OFFSET))
#define ADC_VCR_MPXV_MASK       ((uint32_t)(0x07 << ADC_MPXV_OFFSET))
#define ADC_CNVCLS_MASK         ((uint32_t)(0x01 << ADC_CNVCLS_OFFSET))
#define ADC_VCR_ADIE_MASK       ((uint32_t)(0x01 << ADC_VCR_ADIE_OFFSET))
#define ADC_ULS_MASK            ((uint32_t)(0x03 << ADC_ULS_OFFSET))
#define ADC_GCTRL_MASK          ((uint32_t)0x03F)//Physical Channel Select

/*ADCAnDRj - Data Register j, 32-/16-bit read-only register*/
#define ADC_DR_H                ((uint32_t)(0xFFFF << 16))
#define ADC_DR_L                ((uint32_t)0xFFFF)

/*ADCAnDIRj - Data Supplementary Information Register j, 32-bit read-only register*/
/*ADCAnPWDDIR - PWM-Diag Data Supplementary Information Register, 32-bit read-only register*/
#define ADC_DIR_MPXE_OFFSET     31  //MPX Enable Flag,only supported for ADCA0
#define ADC_DIR_MPVR_OFFSET     28  //MPX value of the most recent conversion result,only supported for ADCA0
#define ADC_WFLG_OFFSET         25  //Write Flag
#define ADC_ID_OFFSET           16  //store the physical channel number (GCTRL) corresponding to the conversion result

#define ADC_DIR_MPXE_MASK       ((uint32_t)(0x01 << ADC_DIR_MPXE_OFFSET))
#define ADC_DIR_MPVR_MASK       ((uint32_t)(0x07 << ADC_DIR_MPVR_OFFSET))
#define ADC_WFLG_MASK           ((uint32_t)(0x01 << ADC_WFLG_OFFSET))
#define ADC_ID_MASK             ((uint32_t)(0x3F << ADC_ID_OFFSET))
#define ADC_DR_MASK             ((uint32_t)0xFFFF) //used to store the A/D conversion result
#define ADC_PWDDR__MASK         ADC_DR_MASK //used to store the A/D conversion result for PWM-Diag.

/*ADCAnPWDTSNDR - PWM-Diag Data Register,32-/16-bit read-only register*/
#define ADC_PWDTSNDR_MASK       ((uint32_t)(0xFFFF << 16))

/*ADCAnADHALTR - A/D Force Halt Register*/
#define ADC_HALT_MASK           ((uint32_t)0x01) //ADCA Force Halt Trigger


/*ADCAnADCR - A/D Control Register*/
#define ADC_DGON_OFFSET         7   //Self-Diagnostic Voltage Standby Control
#define ADC_CRAC_OFFSET         5   //Alignment Control
#define ADC_CTYP_OFFSET         4   //12/10 Bit Select Mode

#define ADC_DGON_MASK           ((uint32_t)(0x01 << ADC_DGON_OFFSET))
#define ADC_CRAC_MASK           ((uint32_t)(0x01 << ADC_CRAC_OFFSET))
#define ADC_CTYP_MASK           ((uint32_t)(0x01 << ADC_CTYP_OFFSET))
#define ADC_SUSMTD_MASK         ((uint32_t)0x03) //Suspend Mode Select

/*ADCAnMPXCURR - MPX Current Register, read-only register,only ADCA0 supports this function*/
#define ADC_MPXCUR_MASK         ((uint32_t)0x07) // used to store the current MPX value

/*ADCAnTHSMPSTCR - T&H Sampling Start Control Register, write-only register*/
#define ADC_SMPST_MASK         ((uint32_t)0x01) //T&H Sampling Start Control Trigger

/* ADCAnTHCR - T&H Control Register,only ADCA0 supports this function*/
#define ADC_ASMPMSK_MASK       ((uint32_t)0x01) //Automatic Sampling Mask Control

/*ADCAnTHAHLDSTCR - T&H Group A Hold Start Control Register,write-only register
ADCAnTHBHLDSTCR - T&H Group B Hold Start Control Register,write-only register
only ADCA0 supports this function*/
#define ADC_HLDST_MASK         ((uint32_t)0x01) //T&H Group A/B Hold Start Control Trigger

/*ADCAnTHACR - T&H Group A Control Register
ADCAnTHBCR - T&H Group B Control Register*/
#define ADC_HLDCTE_OFFSET       5   //T&H Group A/B Hold Completion Trigger Enable
#define ADC_HLDTE_OFFSETT       4   //T&H Group A/B Hold Trigger Enable

#define ADC_HLDCTE_MASK         ((uint32_t)(0x01 << ADC_HLDCTE_OFFSET))
#define ADC_HLDTE_MASK          ((uint32_t)(0x01 << ADC_HLDTE_OFFSETT))
#define ADC_SGS_MASK            ((uint32_t)0x03) //T&H Group A/B Scan Group Select

/*ADCAnTHER - T&H Enable Register,only ADCA0 supports this function*/
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

/*ADCAnTHGSR - T&H Group Select Register,only ADCA0 supports this function*/
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

/*ADCAnSMPCR - Sampling Control Register*/
#define ADC_SMPT_MASK            ((uint32_t)0xFF) //used to set the sampling time (the number of cycles)

/*ADCAnSFTCR - Safety Control Register*/
#define ADC_RDCLRE_OFFSET       4
#define ADC_ULEIE_OFFSET        3
#define ADC_OWEIE_OFFSET        2

#define ADC_RDCLRE_MASK         ((uint32_t)(0x01 << ADC_RDCLRE_OFFSET))
#define ADC_ULEIE_MASK          ((uint32_t)(0x01 << ADC_ULEIE_OFFSET))
#define ADC_OWEIE_MASK          ((uint32_t)(0x01 << ADC_OWEIE_OFFSET))

/*ADCAnULLMTBR0 to 2 - Upper Limit/Lower Limit Table Registers 0 to 2*/
#define ADC_ULMTB_OFFSET        20 //Upper Limit Table
#define ADC_LLMTB_OFFSET        4  //Lower Limit Table

#define ADC_ULMTB_MASK          ((uint32_t)(0xFFF << ADC_ULMTB_OFFSET))
#define ADC_LLMTB_MASK          ((uint32_t)(0xFFF << ADC_LLMTB_OFFSET))

/*ADCAnECR - Error Clear Register,write-only register*/
#define ADC_ULEC_OFFSET         3 //Upper/Lower Limit Error Flag Clear
#define ADC_OWEC_OFFSET         2 //Overwrite Error Flag Clear

#define ADC_ULEC_MASK           ((uint32_t)(0x01 << ADC_ULEC_OFFSET))
#define ADC_OWEC_MASK           ((uint32_t)(0x01 << ADC_OWEC_OFFSET))

/*ADCAnULER - Upper Limit/Lower Limit Error Register*/
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

/*ADCAnOWER - Overwrite Error Register,  32/16/8-bit read-only register*/
#define ADC_OWE_OFFSET          7 //Overwrite Error Flag

#define ADC_OWE_MASK            ((uint32_t)(0x01 << ADC_OWE_OFFSET))
#define ADC_OWECAP_MASK         ((uint32_t)0x3F) //Overwrite Error Capture

/*ADCAnSGSTCRx - Scan Group x Start Control Register*/
#define ADC_SGST_MASK            ((uint32_t)0x01) //Writing 1 to SGST starts the target SGx.

/*ADCAnSGCRx - Scan Group x Control Register*/
#define ADC_SCANMD_OFFSET       5   //Scan Mode
#define ADC_SGCRx_ADIE_OFFSET   4   //Scan End Interrupt Enable
#define ADC_SCT_OFFSET          2   //Channel Repeat Times Select

#define ADC_SCANMD_MASK         ((uint32_t)(0x01 << ADC_SCANMD_OFFSET))
#define ADC_SGCRx_ADIE_MASK     ((uint32_t)(0x01 << ADC_SGCRx_ADIE_OFFSET))
#define ADC_SCT_MASK            ((uint32_t)(0x03 << ADC_SCT_OFFSET))
#define ADC_TRGMD_MASK          ((uint32_t)0x01) //Trigger Mode

/*ADCAnPWDSGCR - PWM-Diag Scan Group Control Register*/
#define ADC_PWDTRGMD_MASK       ((uint32_t)0x01) //PWM-Diag Trigger Mode Select

/*ADCAnSGVCSPx - Scan Group x Start Virtual Channel Pointer*/
#define ADC_VCSP_MASK           ((uint32_t)0x3F) //Start Virtual Channel Pointer
/*ADCAnSGVCEPx - Scan Group x End Virtual Channel Pointer*/
#define ADC_VCEP_MASK           ((uint32_t)0x3F) //End Virtual Channel Pointer

/*ADCAnSGMCYCRx - Scan Group x Multicycle Register*/
#define ADC_MCYC_MASK           ((uint32_t)0x03) //Multicycle Number Specification

/*ADCAnPWDSGSEFCR - PWM-Diag Scan End Flag Clear Register,write-only*/
#define ADC_PWDSEFC_MASK        ((uint32_t)0x01) //PWM-Diag Scan End Flag Clear Trigger

/*ADCAnSGSEFCRx - Scan Group x Scan End Flag Clear Register, write-only register*/
#define ADC_PWDSEFC_MASK        ((uint32_t)0x01) //Scan End Flag Clear Trigger

/*ADCAnSGSTR - Scan Group Status Register,read-only register*/
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

/*ADCAnSGTSELx - Scan Group x Start Trigger Control Register x*/
#define ADC_TxSELp_MASK(p)      ((uint32_t)0x01 << p) //A/D Conversion Trigger (Hardware Trigger) Select

/*ADCAnDGCTL0 - Self-Diagnosis Control Register 0*/
#define ADC_PSEL_MASK           ((uint32_t)0x07)    //Self-Diagnostic Voltage Level Select

/*ADCAnDGCTL1 - Self-Diagnosis Control Register 1*/
#define ADC_CDGn_MASK(offset)   ((uint32_t)(0x01 << offset)) //Self-Diagnostic Channel Select

/*ADCAnPDCTL1 - Pull Down Control Register 1*/
#define ADC_PDNA_MASK           ((uint32_t)0xFF)    //Pull Down Enable Control

/*ADCAnPDCTL2 - Pull Down Control Register 2*/
#define ADC_PDNB_MASK           ((uint32_t)0xFF)    //Pull Down Enable Control

#define ADCAN_ADDR(_UNIT_)      _ADCA0_ADDR //(_UNIT_ == 0 ?_ADCA0_ADDR :_ADCA1_ADDR)
#define ADCAN_VAL(_UNIT_)       _ADCA0_VAL //(_UNIT_ == 0 ?_ADCA0_VAL : _ADCA1_VAL)

#define ADCA_VCR_ADDR(_N_,_J_)                        (((uint32_t*)&ADCAN_VAL(_N_)._VCR00) + _J_)
#define ADCA_VCR_VAL(_N_,_J_)                         (*ADCA_VCR_ADDR(_N_,_J_))

#define ADCA_DR_ADDR(_N_,_J_)                         (((uint32_t*)&ADCAN_VAL(_N_)._DR00) + _J_)
#define ADCA_DR_VAL(_N_,_J_)                          (*ADCA_DR_ADDR(_N_,_J_))

#define ADCA_DIR_ADDR(_N_,_J_)                        (((uint32_t*)&ADCAN_VAL(_N_)._DIR00) + _J_)
#define ADCA_DIR_VAL(_N_,_J_)                         (*ADCA_DIR_ADDR(_N_,_J_))

/*ADCAnVCRj - Virtual Channel Register j*/
#define __ADCA_SET_VC_CTL(_N_,_J_,_MASK_,_VALUE_)       (MODIFY_REG(ADCA_VCR_ADDR(_N_,_J_),_MASK_,_VALUE_))
#define __ADCA_GET_VC_CTL(_N_,_J_,_MASK_)               (ADCA_VCR_VAL(_N_,_J_) & _MASK_)
/*ADCAnPWDVCR - PWM-Diag Virtual Channel Register,Note that bit8 and bit9 not defined*/
#define __ADCA_SET_PWDVC_CTL(_N_,_MASK_,_VALUE_)        (MODIFY_REG(&ADCAN_VAL(_N_)._PWDVCR,_MASK_,_VALUE_))
#define __ADCA_GET_PWDVC_CTL(_N_,_MASK_)                (ADCAN_VAL(_N_)._PWDVCR & _MASK_)

/*ADCAnDRj - Data Register j, 32-/16-bit read-only register*/
#define __ADCA_READ_DATA(_N_,_J_)                       (ADCA_DR_VAL(_N_,_J_))

/*ADCAnDIRj - Data Supplementary Information Register j,32-bit read-only register
only supported by ADCA0*/
#define __ADCA_READ_DATA_INFO(N_,_J_,_MASK_)            (ADCA_DIR_VAL(_N_,_J_) & _MASK_)

/*ADCAnPWDTSNDR - PWM-Diag Data Register,32-/16-bit read-only,high 16 bits valid*/
#define __ADCA_READ_PWD_DATA(_N_,_J_)                   (ADCAN_VAL(_N_)._PWDTSNDR)

/*ADCAnPWDDIR - PWM-Diag Data Supplementary Information Register*,32-bit read-only register
only supported for ADCA0*/
#define __ADCA_READ_PWD_DATA_INFO(N_,_J_,_MASK_)        (ADCAN_VAL(_N_)._PWDDIR & _MASK_)

/*ADCAnADHALTR - A/D Force Halt Register,write-only register*/
#define __ADCA_FORCE_HALT_TRIGGER(_N_)                  (ADCAN_VAL(_N_)._ADHALTR |= ADC_HALT_MASK)

/*ADCAnADCR - A/D Control Register*/
#define __ADCA_SET_COMMON_CTL(_N_,_MASK_,_VALUE_)       (MODIFY_REG((&ADCAN_VAL(_N_)._ADCR),_MASK_,_VALUE_))
#define __ADCA_GET_COMMON_CTL(_N_,_MASK_)               (ADCAN_VAL(_N_)._ADCR & (_MASK_))
/*ADCAnMPXCURR - MPX Current Register,read-only register
only ADCA0 supports this function*/
#define __ADCA_GET_CURRENT_MPX(_N_)                     (ADCAN_VAL(_N_)._MPXCURR & ADC_MPXCUR_MASK)

/*ADCAnTHSMPSTCR - T&H Sampling Start Control Register, write-only register
control the start of sampling for all T&Hk (k = 0 to 5),only ADCA0 supports this function*/
#define __ADCA_START_TH_SAMPLING_(_N_)                  (_ADCA0_VAL._THSMPSTCR |= ADC_SMPST_MASK)
#define __ADCA_START_TH_SAMPLING()                      __ADCA_START_TH_SAMPLING_(0)

/*ADCAnTHCR - T&H Control Register,only ADCA0 supports this function.*/
#define __ADCA_SET_AUTO_SAMPLING_(_ENABLE_)             do{ \
                                                            if(_ENABLE_) \
                                                                (_ADCA0_VAL._THCR |= ADC_ASMPMSK_MASK); \
                                                            else \
                                                                (_ADCA0_VAL._THCR &= ~ADC_ASMPMSK_MASK); \
                                                        }while(0)
#define __ADCA_SET_AUTO_SAMPLING(_ENABLE_)              __ADCA_SET_AUTO_SAMPLING_(_ENABLE_)

/*ADCAnTHAHLDSTCR - T&H Group A Hold Start Control Register,write-only register
ADCAnTHBHLDSTCR - T&H Group B Hold Start Control Register,write-only register
only ADCA0 supports this function*/
#define __ADCA_START_THA_HOLD_()                     	(_ADCA0_VAL._THAHLDSTCR |= ADC_HLDST_MASK)
#define __ADCA_START_THB_HOLD_()                     	(_ADCA0_VAL._THBHLDSTCR |= ADC_HLDST_MASK)
#define __ADCA_START_THA_HOLD()                         __ADCA_START_THA_HOLD_()
#define __ADCA_START_THB_HOLD()                         __ADCA_START_THB_HOLD_()

/*ADCAnTHACR - T&H Group A Control Register,only ADCA0 supports this function
ADCAnTHBCR - T&H Group B Control Register,only ADCA0 supports this function*/
#define __ADCA_SET_THA_CTL_(_MASK_,_VALUE_)             (MODIFY_REG((&_ADCA0_VAL._THACR),_MASK_,_VALUE_))
#define __ADCA_SET_THB_CTL_(_MASK_,_VALUE_)             (MODIFY_REG((&_ADCA0_VAL._THBCR),_MASK_,_VALUE_))
#define __ADCA_SET_THA_CTL(_MASK_,_VALUE_)              __ADCA_SET_THA_CTL_(_MASK_,_VALUE_)
#define __ADCA_SET_THB_CTL(_MASK_,_VALUE_)              __ADCA_SET_THB_CTL_(_MASK_,_VALUE_)

/*ADCAnTHER - T&H Enable Register,ADCAnTHER - T&H Enable Register,only ADCA0 supports this function*/
#define __ADCA_TH_ENABLE_(_MASK_)                       (MODIFY_REG((&_ADCA0_VAL._THER),_MASK_,_MASK_))
#define __ADCA_TH_DISABLE_(_MASK_)                      (MODIFY_REG((&_ADCA0_VAL._THER),_MASK_,(~_MASK_)))
#define __ADCA_TH_ENABLE(_MASK_)                        __ADCA_TH_ENABLE_(_MASK_)
#define __ADCA_TH_DISABLE(_MASK_)                       __ADCA_TH_DISABLE_(_MASK_)

/*ADCAnTHGSR - T&H Group Select Register,only ADCA0 supports this function*/
#define __ADCA_TH_SELECT_(_MASK_)                       (MODIFY_REG((&_ADCA0_VAL._THGSR),_MASK_,_MASK_))
#define __ADCA_TH_DESELECT_(_MASK_)                     (MODIFY_REG((&_ADCA0_VAL._THGSR),_MASK_,(~_MASK_)))
#define __ADCA_TH_SELECT(_MASK_)                        __ADCA_TH_SELECT_(_MASK_)
#define __ADCA_TH_DESELECT(_MASK_)                      __ADCA_TH_DESELECT_(_MASK_)

/*ADCAnSMPCR - Sampling Control Register,used to set the sampling time (the number of cycles)
12H, or 18H shouled be set,settings other than above are prohibited*/
#define __ADCA_SET_SAMPLING_TIME(_N_,_TIME_ )           (ADCAN_VAL(_N_)._SMPCR = _TIME_ & ADC_SMPT_MASK)
#define __ADCA_GET_SAMPLING_TIME(_N_)                   (ADCAN_VAL(_N_)._SMPCR & ADC_SMPT_MASK)
#define IS_SAMPLING_TIME(_TIME_)                        ( ((_TIME_) == 0x12)|| \
                                                           ((_TIME_) == 0x18) )
/*ADCAnSFTCR - Safety Control Register*/
#define __ADCA_SET_SAFETY_CTL(_N_,_MASK_,_VALUE_)       (MODIFY_REG((&ADCAN_VAL(_N_)._SFTCR),_MASK_,_VALUE_))
#define __ADCA_GET_SAFETY_CTL(_N_,_MASK_)               (ADCAN_VAL(_N_)._SFTCR & _MASK_)

/*ADCAnULLMTBR0 to 2 - Upper Limit/Lower Limit Table Registers 0 to 2
_REG_INDEX:0,1 ,2*/
#define __ADCA_LIMIT_TAB_ADDR(_N_,_REGx_,_TAB_)         (((uint32_t*)&ADCAN_VAL(_N_).##_TAB_) + _REGx_)
#define __ADCA_LIMIT_TAB_VAL(_N_,_REGx_,_TAB_)          (*(((uint32_t*)&ADCAN_VAL(_N_).##_TAB_) + _REGx_))

#define __ADCA_SET_LIMIT_TAB(_N_,_REGx_,_VALUE_)        (__ADCA_LIMIT_TAB_VAL(_N_,_REGx_,_ULLMTBR0) = _VALUE_)

#define __ADCA_GET_LIMIT_TAB(_N_,_REGx_)                (__ADCA_LIMIT_TAB_VAL(_N_,_REGx_,_ULLMTBR0))

/*ADCAnECR - Error Clear Register,control clearing of an error, write-only register*/
#define __ADCA_CLEAR_ERROR(_N_,_MASK_)                  (MODIFY_REG((&ADCAN_VAL(_N_)._ECR),_MASK_,_MASK_))

/*ADCAnULER - Upper Limit/Lower Limit Error Register,read-only register,
several bits are only supported for ADCA0*/
#define __ADCA_GET_ULLIMIT_ERR_INFO(_N_,_MASK_)         (ADCAN_VAL(_N_)._ULER & (_MASK_))

/*ADCAnOWER - Overwrite Error Register,32/16/8-bit read-only register*/
#define __ADCA_GET_OVERWRITE_ERR(_N_,_MASK_)            (ADCAN_VAL(_N_)._OWER & (_MASK_))

/********************Scan Group (SG) Specific Registers Operation**************/
#define ADCAN_SGx_ADDR(_N_,_X_,_REG_BASE_)              (((uint32_t*)&ADCAN_VAL(_N_).##_REG_BASE_) + (_X_- 1) *0x10) //the _X_ from 1 to 3 --> _X_ -1
#define ADCAN_SGx_VAL(_N_,_X_,_REG_BASE_)               (*(((uint32_t*)&ADCAN_VAL(_N_).##_REG_BASE_) + (_X_- 1) *0x10))
/*ADCAnSGSTCRx - Scan Group x Start Control Register,write-only register
_X_: 1 to 3*/
#define __ADCA_START_SGx(_N_,_X_)                       (ADCAN_SGx_VAL(_N_,_X_,_SGSTCR_BASE) |= ADC_SGST_MASK)

/*ADCAnSGCRx - Scan Group x Control Register*/
#define __ADCA_SET_SGx_CTL(_N_,_X_,_MASK_,_VALUE_)      (MODIFY_REG(ADCAN_SGx_ADDR(_N_,_X_,_SGCR_BASE),_MASK_,_VALUE_))
#define __ADCA_GET_SGx_CTL(_N_,_X_,_MASK_)              (ADCAN_SGx_VAL(_N_,_X_,_SGCR_BASE) & (_MASK_))

/*ADCAnPWDSGCR - PWM-Diag Scan Group Control Register*/
#define __ADCA_SELECT_PWD_TRIGGER_MODE(_N_,_BIT_VAL_)   do{ \
                                                            if(_BIT_VAL_) \
                                                                (ADCAN_VAL(_N_)._PWDSGCR |= ADC_PWDTRGMD_MASK); \
                                                            else \
                                                            (ADCAN_VAL(_N_)._PWDSGCR &= ~ADC_PWDTRGMD_MASK); \
                                                        }while(0)
/*ADCAnSGVCSPx - Scan Group x Start Virtual Channel Pointer*/
#define __ADCA_SET_START_POINTER(_N_,_X_,_VALUE_)       (ADCAN_SGx_VAL(_N_,_X_,_SGVCSP_BASE) = _VALUE_ & ADC_VCSP_MASK)
#define __ADCA_GET_START_POINTER(_N_,_X_)               (ADCAN_SGx_VAL(_N_,_X_,_SGVCSP_BASE) & ADC_VCSP_MASK)
/*ADCAnSGVCEPx - Scan Group x End Virtual Channel Pointer*/
#define __ADCA_SET_END_POINTER(_N_,_X_,_VALUE_)         (ADCAN_SGx_VAL(_N_,_X_,_SGVCEP_BASE) = _VALUE_ & ADC_VCEP_MASK)
#define __ADCA_GET_END_POINTER(_N_,_X_)                 (ADCAN_SGx_VAL(_N_,_X_,_SGVCEP_BASE) & ADC_VCEP_MASK)

#define IS_START_POINTER_VALUE(N_,_X_,_VALUE_)          (_VALUE_ <= __ADCA_GET_END_POINTER(_N_,_X_,_VALUE_) )
#define IS_END_POINTER_VALUE(N_,_X_,_VALUE_)            (_VALUE_ >= __ADCA_GET_START_POINTER(_N_,_X_,_VALUE_))

/*ADCAnSGMCYCRx - Scan Group x Multicycle Register*/
#define __ADCA_SET_SCAN_TIME(_N_,_X_,_TIMES_)           (ADCAN_SGx_VAL(_N_,_X_,_SGMCYCR_BASE)  = _TIMES_ & ADC_MCYC_MASK)
#define __ADCA_GET_SCAN_TIME(_N_,_X_)                   (ADCAN_SGx_VAL(_N_,_X_,_SGMCYCR_BASE) & ADC_MCYC_MASK)

/*DCAnPWDSGSEFCR - PWM-Diag Scan End Flag Clear Register,write-only register
to clear of PWM-Diag scan end flag (SEF)*/
#define __ADCA_CLEAR_PWD_SCAN_END_FLAG(_N_)             (ADCAN_VAL(_N_)._PWDSGSEFCR  |= ADC_PWDSEFC_MASK)

/*ADCAnSGSEFCRx - Scan Group x Scan End Flag Clear Register*/
#define __ADCA_CLEAR_SGx_SCAN_END_FLAG(_N_,_X_)         (ADCAN_SGx_VAL(_N_,_X_,_SGSEFCR_BASE)  |= ADC_SEFC_MASK)

/*ADCAnSGSTR - Scan Group Status Register,read-only register*/
#define __ADCA_GET_SG_STAT(_N_,_MASK_)                  (ADCAN_VAL(_N_)._SGSTR & _MASK_)

/******************Hardware Trigger Specific Register Operation****************/
/*ADCAnSGTSELx - Scan Group x Start Trigger Control Register x*/
#define __ADCA_ENABLE_HARDWARE_TRIGGER(_N_,_X_,_P_)     (ADCAN_SGx_VAL(_N_,_X_,_SGTSEL_BASE)  = ADC_TxSELp_MASK(_P_))
#define __ADCA_DISABLE_HARDWARE_TRIGGER(_N_,_X_,_P_)    (ADCAN_SGx_VAL(_N_,_X_,_SGTSEL_BASE)  &= ~ADC_TxSELp_MASK(_P_))

/**************************Self-Diagnosis Specific Registers*******************/
/*ADCAnDGCTL0 - Self-Diagnosis Specific Registers 0,controls the self-diagnostic voltage level*/
#define __ADCA_SELECT_Self_Diag_VOLT_LEVEL(_N_,_VALUE_) (ADCAN_VAL(_N_)._DGCTL0 = _VALUE_ & ADC_PSEL_MASK)

/*ADCAnDGCTL1 - Self-Diagnosis Control Register 1*/
#define __ADCA_SELECT_Self_Diag_CHANNEL(_N_,_VALUE_)    (ADCAN_VAL(_N_)._DGCTL1 = _VALUE_ & 0xFFFF)

/*ADCAnPDCTL1 - Pull Down Control Register 1*/
#define __ADCA_ENABLE_PULL_DOWN_L(_N_,_MASK_,_VALUE_)   (MODIFY_REG(&(ADCAN_VAL(_N_)._PDCTL1),_MASK_,_VALUE_))
#define __ADCA_ENABLE_PULL_DOWN_H(_N_,_MASK_,_VALUE_)   (MODIFY_REG(&(ADCAN_VAL(_N_)._PDCTL2),_MASK_,_VALUE_))

typedef union{
    uint32_t vhset;
    struct{
        uint32_t GCTRL      :6;     //Physical Channel Select
        uint32_t ULS        :2;     //Upper Limit/Lower Limit Table Select
        uint32_t ADIE       :1;     //A/D Conversion End Interrupt Enable
        uint32_t CNVCLS     :1;     //A/D Conversion Type Select for Self-Diagnosis
        uint32_t            :2;     //Reserved
        uint32_t MPXV       :3;     //set the MPX value to be transferred to an external analog multiplexer
        uint32_t MPXE       :1;     //MPX Enable
        uint32_t            :16;    //Reserved
    }reg_bits;
    struct{
        uint32_t phy_ch     :6;     //Physical Channel Select
        uint32_t limit_sel  :2;     //Upper Limit/Lower Limit Table Select
        uint32_t end_int_en :1;     //A/D Conversion End Interrupt Enable
        uint32_t cnv_type   :1;     //A/D Conversion Type Select for Self-Diagnosis
        uint32_t            :2;     //Reserved
        uint32_t mpx_val    :3;     //set the MPX value to be transferred to an external analog multiplexer
        uint32_t mpx_en     :1;     //MPX Enable
        uint32_t            :16;    //Reserved
    }param_bits;
}ADCA_VHSetUnion;

typedef struct{
    uint8_t virtual_ch;         //virtual channel,corresponding to j
    ADCA_VHSetUnion vh_set_un;
}ADCA_VHSetTypeDef;

typedef union{
    uint32_t opctl;
    struct{
        uint32_t SUSMTD     :2;     //Suspend Mode Select
        uint32_t            :2;
        uint32_t CTYP       :1;     //12/10 Bit Select Mode
        uint32_t CRAC       :1;     //Alignment Control
        uint32_t            :1;
        uint32_t DGON       :1;     //Self-Diagnostic Voltage Standby Control
        uint32_t            :24;    //Reserved
    }reg_bits;
    struct{
        uint32_t susp_mode  :2;     //Suspend Mode Select
        uint32_t            :2;
        uint32_t bit_mode   :1;     //12/10 Bit Select Mode
        uint32_t alin_fmt   :1;     //Alignment Control
        uint32_t            :1;     //Reserved
        uint32_t sd_volt    :1;     //Self-Diagnostic Voltage Standby Control
        uint32_t            :24;    //Reserved
    }param_bits;
}ADCA_OptCtlUnion;


typedef union{
    uint32_t safectl;
    struct{
        uint32_t            :2;     //Reserved
        uint32_t OWEIE      :1;      //A/D Error Interrupt (INT_ADE) Enable on Overwrite Error Detection
        uint32_t ULEIE      :1;     //A/D Error Interrupt (INT_ADE) Enable on Upper/Lower Limit Error Detection
        uint32_t RDCLRE     :1;     //Read & Clear Enable
        uint32_t            :27;
    }reg_bits;
    struct{
        uint32_t            :2;     //Reserved
        uint32_t ow_int     :1;      //A/D Error Interrupt (INT_ADE) Enable on Overwrite Error Detection
        uint32_t ul_int     :1;     //A/D Error Interrupt (INT_ADE) Enable on Upper/Lower Limit Error Detection
        uint32_t rc_en      :1;     //Read & Clear Enable
        uint32_t            :27;
    }param_bits;
}ADCA_SafeCtlUnion;

typedef struct{
    uint8_t checked;
    union{
        uint32_t limit_tab;
        struct{
            uint32_t        :4;
            uint32_t llimit :12;//used to set the upper limit table of ADCAnULLMTBR0 to 2
            uint32_t        :4;
            uint32_t ulimit :12;//used to set the lower limit table of ADCAnULLMTBR0 to 2
        }param_bits;
    }limit_un;
}ADCA_ULLimitSetTypeDef;

typedef struct{
    uint8_t sd_volt_level; //Self-Diagnostic Voltage Level Select
    uint16_t sd_ch_select; //Self-Diagnostic Channel Select
}ADCA_SDCtlTypeDef; //Self-Diagnosis Control Register 0 and 1 configuration structure

/** @defgroup auto_sampling_mask
  * @{
  */
#define ADCA_AUTO_SAMP_DISABLE          ((uint32_t)0x0000)
#define ADCA_AUTO_SAMP_ENABLE           (ADC_ASMPMSK_MASK)
/**
  * @}
  */
typedef union{
    uint32_t grp_ctl;
    struct{
        uint32_t SGS        :2;     //T&H Group A/B Scan Group Select
        uint32_t            :2;     //Reserved
        uint32_t HLDTE      :1;     //T&H Group A Hold Trigger Enable
        uint32_t HLDCTE     :1;     //T&H Group A Hold Completion Trigger Enable
        uint32_t            :26;
    }reg_bits;
    struct{
        uint32_t sn_grp_sel :2;     //T&H Group A/B Scan Group Select
        uint32_t            :2;     //Reserved
        uint32_t ht_en      :1;     //T&H Group A Hold Trigger Enable
        uint32_t hct_en     :1;     //T&H Group A Hold Completion Trigger Enable
        uint32_t            :26;
    }param_bits;
}ADCA_THGrpOptCtlUnion;//T&H group A/B operation control setting


typedef union{
    uint32_t sg_ctl;
    struct{
        uint32_t TRGMD    :1;     //Trigger Mode
        uint32_t          :1;     //Reserved
        uint32_t SCT      :2;     //Channel Repeat Times Select
        uint32_t ADIE     :1;     //Scan End Interrupt Enable
        uint32_t SCANMD   :1;     //Scan Mode
        uint32_t          :26;
    }reg_bits;
    struct{
        uint32_t trig_mod :1;     //Trigger Mode
        uint32_t          :1;     //Reserved
        uint32_t rep_time :2;     //Channel Repeat Times Select
        uint32_t se_int   :1;     //Scan End Interrupt Enable
        uint32_t scan_mod :1;     //Scan Mode
        uint32_t          :26;
    }param_bits;
}ADCA_SGCtlUnion;//T&H group A/B operation control setting

/** @defgroup number_of_scans
  * @{
  */
#define ADCA_SCAN_TIME_1                (0)
#define ADCA_SCAN_TIME_2                (1)
#define ADCA_SCAN_TIME_3                (2)
#define ADCA_SCAN_TIME_4                (3)
/**
  * @}
  */

typedef struct{
    uint8_t sg_index;           //the individual scan groups (SG) of ADCAn,corresponding to x(x = 1 to 3)
    ADCA_SGCtlUnion sg_ctl_un;
    uint32_t start_vhp;         /*!< Specifies the start virtual channel pointer setting .
                                    This parameter can be a value from 0 to MAX_ADCA0_VIRTUAL_CH_NUM
                                    or MAX_ADCA1_VIRTUAL_CH_NUM ,Note that the value must be equal to
                                    or smaller than end_vhp*/

    uint32_t end_vhp;           /*!< Specifies the end virtual channel pointer setting .
                                    This parameter can be a value from 0 to MAX_ADCA0_VIRTUAL_CH_NUM
                                    or MAX_ADCA1_VIRTUAL_CH_NUM,Note that the value must be equal to
                                    or larger than start_vhp*/

    uint8_t scan_times;         /*!< Specifies the end multicycle count setting  .
                                    This parameter can be a value of @ref  number_of_scans  */
    uint32_t hw_trig_ctl;       /*!< Specifies the A/D conversion trigger (hardware trigger) for SGx.
                                    This parameter can be a value of @ref hw_trigger_ctl*/
}ADCA_SGOptTypeDef; //SG1-3 operation structure
/** @defgroup th_enable_mask
  * @{
  */
#define TH5_ENABLE_MASK                 ADC_TH5E_MASK
#define TH4_ENABLE_MASK                 ADC_TH4E_MASK
#define TH3_ENABLE_MASK                 ADC_TH3E_MASK
#define TH2_ENABLE_MASK                 ADC_TH2E_MASK
#define TH1_ENABLE_MASK                 ADC_TH1E_MASK
#define TH0_ENABLE_MASK                 ADC_TH0E_MASK
/**
  * @}
  */

/** @defgroup th_group_selection_mask
  * @{
  */
#define TH5_GROUP_SELECT_MASK           ADC_TH5GS_MASK
#define TH4_GROUP_SELECT_MASK           ADC_TH4GS_MASK
#define TH3_GROUP_SELECT_MASK           ADC_TH3GS_MASK
#define TH2_GROUP_SELECT_MASK           ADC_TH2GS_MASK
#define TH1_GROUP_SELECT_MASK           ADC_TH1GS_MASK
#define TH0_GROUP_SELECT_MASK           ADC_TH0GS_MASK
/**
 * @}
 */


typedef struct{
    uint8_t auto_samp;          /*!< Specifies the T&H common operation control setting.
                                    Set the automatic sampling mask control bit.
                                    This parameter can be a value of @ref auto_sampling_mask */
    ADCA_THGrpOptCtlUnion grpa; /*!< Specifies the T&H group A operation control setting.*/
    ADCA_THGrpOptCtlUnion grpb; /*!< Specifies the T&H group B operation control setting.*/

    uint32_t en_mask;           /*!< Specifies the T&H enable setting.
                                    This parameter can be a value of @ref th_enable_mask*/
    uint32_t grp_sel_mask;      /*!< Specifies T&H group selection setting.
                                    This parameter can be a value of @ref th_group_selection_mask*/
}ADCA_THSetTypeDef;

/** @defgroup hw_trigger_ctl
  * @{
  */
#define RIGHT_ALIGN_12BIT_FMT       (0x00) //DCAnADCR.CTYP = 0 and ADCAnADCR.CRAC = 0
#define LEFT_ALIGN_12BIT_FMT        (0x01) //ADCAnADCR.CTYP = 0 and ADCAnADCR.CRAC = 1
#define RIGHT_ALIGN_10BIT_FMT       (0x02) //ADCAnADCR.CTYP = 1 and ADCAnADCR.CRAC = 0
#define LEFT_ALIGN_10BIT_FMT        (0x03) //ADCAnADCR.CTYP = 1 and ADCAnADCR.CRAC = 1
/**
  * @}
  */

/** @defgroup hw_trigger_ctl
  * @{
  */
#define HW_ADCA0TRG0_TRIG             (0)
#define HW_INTTAUJ0I3_TRIG            (1)
#define HW_INTTAUD0I7_TRIG            (2)
#define HW_INTTAUD0I15_TRIG           (3)
#define HW_SEQADTRG_TRIG              (4)
#define HW_INTENCA0I1_TRIG            (5)
#define HW_TAPATADOUT0_TRIG           (6)
#define HW_TAPATADOUT1_TRIG           (7)
#define HW_ADOPA0ADCATTIN00_TRIG      (8)

#define HW_ADCA1TRG0_TRIG             (0)
#define HW_INTTAUJ1I3_TRIG            (1)
#define HW_INTTAUB0I7_TRIG            (2)
#define HW_INTTAUB0I15_TRIG           (3)
/**
  * @}
  */

typedef struct{
    uint8_t adcan;              //0 or 1 optional
    uint8_t vh_set_num;         // the number of ADCA_VHSetTypeDef to be initialized
    ADCA_VHSetTypeDef *vh_set_p;// the pointer to ADCA_VHSetTypeDef
    uint8_t pwd_vh_used;        // 0:set virtual channel 1:PWM-Diag virtual channel
    ADCA_OptCtlUnion opt_ctl_un;//ADC common operation control
    uint8_t conv_data_fmt;      /*!< Specifies the data format of the conversion result stored in ADCAnDRj.
                                    This parameter can be a value of @ref conv_result_fmt*/
    uint8_t samp_time;          //the sampling time (the number of cycles)
    ADCA_SafeCtlUnion safe_ctl_un;
    ADCA_ULLimitSetTypeDef limit[3];
    ADCA_SDCtlTypeDef *sd_ctl_p;
    ADCA_THSetTypeDef *th_set_p;
    uint8_t sg_opt_num;
    ADCA_SGOptTypeDef *sg_opt_p;
}ADCA_InitTypeDef;

/** @defgroup ADC_Exported_Constants
  * @{
  */

#define IS_ADCA_ALL_PERIPH(PERIPH) 	( 	((PERIPH) == ADCA_0) || \
										((PERIPH) == ADCA_1) )

#define IS_ADCA_SG_INDEX(INDEX) 	( 	((INDEX) == 1) || \
										((INDEX) == 2) || \
										((INDEX) == 3) )
/** @defgroup ADC_mode
  * @{
  */


#define ADCA_LOWER_LIMIT_ERR            ((uint8_t)(0x01 << 0)) //A lower limit error is detected.
#define ADCA_UPPER_LIMIT_ERR            ((uint8_t)(0x01 << 1)) //An upper limit error is detected.
#define ADCA_OVERWRITE_ERR              ((uint8_t)(0x01 << 2)) //An overwrite error is detected



void ADCA_Init(ADCA_InitTypeDef *ADCA_InitStruct);

static void ADCA_Set_Virtual_Channel(uint8_t ADCAn,ADCA_VHSetTypeDef *vh_set_p,
	ADCA_ULLimitSetTypeDef *limit_checked,bool pwd_used);

void ADCA_Set_Batch_Virtual_Channel(uint8_t ADCAn,ADCA_VHSetTypeDef *vh_set_p,uint8_t vh_set_num,
    ADCA_ULLimitSetTypeDef *limit_checked,bool pwd_used);

static void ADCA_Set_Operation_Ctl(uint8_t adcan, ADCA_OptCtlUnion ctl_un,uint8_t samp_time);

static void ADCA_Set_Error_Check(uint8_t adcan,ADCA_SafeCtlUnion ctl_un,ADCA_ULLimitSetTypeDef *limit_p);

static void ADCA_Set_Self_Diag(uint8_t adcan,ADCA_SDCtlTypeDef *ctl_p);

static void ADCA_Set_TH_Operation_Ctl(ADCA_THSetTypeDef *set_p);

static void ADCA_Set_SG_Operation(uint8_t adcan,ADCA_SGOptTypeDef *opt_p,bool pwd_used);

static void ADCA_Set_SG_Start_Trigger(uint8_t ADCAn,uint8_t sg_index,uint32_t trig_ctl);

int8_t ADCA_Read_Ch_Conv_Data(uint8_t adcan,uint8_t virtual_ch,uint16_t *data_p,
    uint8_t *phy_ch_p);

int8_t ADCA_Read_SG_Conv_Data(uint8_t adcan,uint8_t sg_index,uint16_t *data_p,
    uint8_t *phy_ch_p);

int8_t ADCA_Get_SG_Status(uint8_t ADCAn,uint8_t sg_index);

void ADCA_Clear_SG_Status(uint8_t ADCAn,uint8_t sg_index);

void ADCA_Err_Handle(uint8_t ADCAn);
int8_t ADCA_Err_Checked(uint8_t ADCAn,uint8_t *src_err_p);

#endif //RH850F1L_ADC_H
