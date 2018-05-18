/**
  ******************************************************************************
  * @file    rh850f1l_rlin.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    8-March-2018
  * @brief   Header file of RLIN3 module.
  ******************************************************************************
  */
#ifndef RH850F1L_RLIN_H
#define RH850F1L_RLIN_H
#include "rh850f1l.h"

/******************************************************************************/
/**######  #       ### #     #  #####        #     #    #    ######  #######***/ 
/**#     # #        #  ##    # #     #       #     #   # #   #     #    #   ***/ 
/**#     # #        #  # #   #       #       #     #  #   #  #     #    #   ***/ 
/**######  #        #  #  #  #  #####        #     # #     # ######     #   ***/ 
/**#   #   #        #  #   # #       #       #     # ####### #   #      #   ***/ 
/**#    #  #        #  #    ## #     #       #     # #     # #    #     #   ***/ 
/**#     # ####### ### #     #  #####         #####  #     # #     #    #   ***/
/******************************************************************************/

#define MAX_LIN3_NUM     6
#define MAX_UART_NUM    MAX_LIN3_NUM


#define _RLIN30         RLN30
#define _RLIN31         RLN31
#define _RLIN32         RLN32
#define _RLIN33         RLN33
#define _RLIN34         RLN34
#define _RLIN35         RLN35

/*RLN3nLWBR - LIN Wake-Up Baud Rate Select Register*/
#define LIN3_NSPB_OFFSET     4
#define LIN3_LPRS_OFFSET     1
#define LIN3_NSPB_MASK       ((uint8_t)(0x0F << LIN3_NSPB_OFFSET))   //Bit Sampling Count Select
#define LIN3_LPRS_MASK       ((uint8_t)(0x07 << LIN3_LPRS_OFFSET))   //Prescaler Clock Select
#define LIN3_LWBR0_MASK      0x01   //Wake-up Baud Rate Select

/*RLN3nLMD - UART Mode Register*/
#define LIN3_LRDNFS_OFFSET   5
#define LIN3_LIOS_OFFSET     4
#define LIN3_LCKS_OFFSET     2
#define LIN3_LMD_OFFSET      0

#define LIN3_LRDNFS_MASK     ((uint8_t)(0x01 << LIN3_LRDNFS_OFFSET))    //LIN/uart Reception Data Noise Filter Disable
#define LIN3_LIOS_MASK       ((uint8_t)(0x01 << LIN3_LIOS_OFFSET))      //LIN Interrupt Output Select
#define LIN3_LCKS_MASK       ((uint8_t)(0x03 << LIN3_LCKS_OFFSET))      //LIN System Clock Select
#define LIN3_LMD_MASK        ((uint8_t)0x03)                            //LIN/UART Mode Select

/*RLN3nLBFC - UART Configuration Register*/

#define LIN3_UTPS_OFFSET     6
#define LIN3_URPS_OFFSET     5
#define LIN3_UPS_OFFSET      3
#define LIN3_USBLS_OFFSET    2
#define LIN3_UBOS_OFFSET     1
#define LIN3_UBLS_OFFSET     0
#define LIN3_LBLT_OFFSET     0

#define LIN3_UTPS_MASK       ((uint8_t)(0x01 << LIN3_UTPS_OFFSET)) //UART Output Polarity Switch
#define LIN3_URPS_MASK       ((uint8_t)(0x01 << LIN3_URPS_OFFSET)) //UART Input Polarity Switch
#define LIN3_UPS_MASK        ((uint8_t)(0x03 << LIN3_UPS_OFFSET))  //UART Parity Select
#define LIN3_USBLS_MASK      ((uint8_t)(0x01 << LIN3_USBLS_OFFSET))//UART Stop Bit length Select
#define LIN3_UBOS_MASK       ((uint8_t)(0x01 << LIN3_UBOS_OFFSET)) //UART Transfer Format Order Select
#define LIN3_UBLS_MASK       ((uint8_t)0x01) //UART Character Length Select
#define LIN3_LBLT_MASK       ((uint8_t)0x01) //Reception Break (Low-Level) Detection Width Setting

/*RLN3nLBFC - LIN Break Field Configuration Register*/
#define LIN3_BDT_OFFSET      4
#define LIN3_BDT_MASK        ((uint8_t)(0x03 << LIN3_BDT_OFFSET)) //Transmission Break Delimiter (High Level) Width Select
#define LIN3_BLT_MASK        ((uint8_t)0x0F) //Transmission Break (Low Level) Width Select

/*RLIN3nLSC - LIN/UART Space Configuration Register*/
#define LIN3_IBS_OFFSET      4
#define LIN3_IBS_MASK        ((uint8_t)(0x03 << LIN3_IBS_OFFSET)) //Inter-Byte Space Select
#define LIN3_IBHS_MASK       ((uint8_t)0x07) //Inter-Byte Space (Header)/Response Space Select

/*RLN3nLWUP - LIN Wake-Up Configuration Register*/
#define LIN3_WUTL_OFFSET     4
#define LIN3_WUTL_MASK       ((uint8_t)(0x0F << LIN3_WUTL_OFFSET)) //Wake-up Transmission Low Level Width Select

/*RLN3nLIE - LIN Interrupt Enable Register*/
#define LIN3_SHIE_OFFSET     3
#define LIN3_ERRIE_OFFSET    2
#define LIN3_FRCIE_OFFSET    1
#define LIN3_FTCIE_OFFSET    0

#define LIN3_SHIE_MASK       ((uint8_t)(0x01 << LIN3_SHIE_OFFSET)) //Successful Header Transmission Interrupt Request Enable
#define LIN3_ERRIE_MASK      ((uint8_t)(0x01 << LIN3_ERRIE_OFFSET)) //Error Detection Interrupt Request Enable
#define LIN3_FRCIE_MASK      ((uint8_t)(0x01 << LIN3_FRCIE_OFFSET)) //Successful Frame/Wake-up Reception Interrupt Request Enable
#define LIN3_FTCIE_MASK      ((uint8_t)0x01) //Successful Frame/Wake-up Transmission Interrupt Request Enable

/*RLN3nLEDE - LIN/UART Error Detection Enable Register*/
#define LIN3_LTES_OFFSET     7
#define LIN3_IPERE_OFFSET    6
#define LIn3_SFERE_OFFSET    4
#define LIN3_FERE_OFFSET     3
#define LIN3_OERE_OFFSET     2
#define LIN3_FTERE_OFFSET    2
#define LIN3_TERE_OFFSET     2
#define LIN3_PBERE_OFFSET    1

#define LIN3_LTES_MASK      ((uint8_t)(0x01 << LIN3_LTES_OFFSET)) //Timeout Error Select
#define LIN3_IPERE_MASK     ((uint8_t)(0x01 << LIN3_IPERE_OFFSET)) //ID Parity Error Detection Enable
#define LIn3_SFERE_MASK     ((uint8_t)(0x01 << LIn3_SFERE_OFFSET))//Sync Field Error Detection Enable
#define LIN3_FERE_MASK      ((uint8_t)(0x01 << LIN3_FERE_OFFSET)) //Framing Error Detection Enable
#define LIN3_OERE_MASK      ((uint8_t)(0x01 << LIN3_OERE_OFFSET)) //Overrun Error Detection Enable
#define LIN3_FTERE_MASK     ((uint8_t)(0x01 << LIN3_FTERE_OFFSET))//Timeout Error Detection Enable
#define LIN3_TERE_MASK      ((uint8_t)(0x01 << LIN3_TERE_OFFSET)) //Timeout Error Detection Enable
#define LIN3_PBERE_MASK     ((uint8_t)(0x01 << LIN3_PBERE_OFFSET))//Physical Bus Error Detection Enable
#define LIN3_BERE_MASK      ((uint8_t)0x01) //Bit Error Detection Enable

/*RLN3nLCUC - LIN/UART Control Register*/
#define LIN3_OM1_OFFSET      1
#define LIN3_OM1_MASK        ((uint8_t)(0x01 << LIN3_OM1_OFFSET))//LIN Mode Select
#define LIN3_OM0_MASK        0x01 //LIN Reset

/*RLN3nLTRC - LIN/UART Transmission Control Register*/
#define LIN3_LNRR_OFFSET     2
#define LIN3_RTS_OFFSET      1
#define LIN3_LNRR_MASK       ((uint8_t)(0x01 << LIN3_LNRR_OFFSET)) //No LIN Response Request
#define LIN3_RTS_MASK        ((uint8_t)(0x01 << LIN3_RTS_OFFSET)) //Response Transmission/Reception Start
#define LIN3_FTS_MASK        ((uint8_t)0x01)   //Frame Transmission/Wake-up Transmission/Reception Start

/*RLN3nLMST - LIN/UART Mode Status Register read-only register*/
#define LIN3_OMM1_OFFSET    1
#define LIN3_OMM1_MASK      ((uint8_t)(0x01 << LIN3_OMM1_OFFSET))//LIN Mode Status Monitor
#define LIN3_OMM0_MASK      0x01 //LIN Reset Status Monitor

/*RLN3nLST - LIN/UART Status Register*/
#define LIN3_HTRC_OFFSET     7
#define LIN3_D1RC_OFFSET     6
#define LIN3_IPER_OFFSET     6
#define LIN3_URS_OFFSET      5
#define LIN3_UTS_OFFSET      4
#define LIN3_ERR_OFFSET      3
#define LIN3_FRC_OFFSET      1
#define LIN3_FTC_OFFSET      0

#define LIN3_HTRC_MASK       ((uint8_t)(0x01 << LIN3_HTRC_OFFSET)) //Successful Header Transmission Flag
#define LIN3_D1RC_MASK       ((uint8_t)(0x01 << LIN3_D1RC_OFFSET)) //Successful Data 1 Reception Flag
#define LIN3_IPER_MASK       ((uint8_t)(0x01 << LIN3_IPER_OFFSET)) //ID Parity Error Flag
#define LIN3_URS_MASK        ((uint8_t)(0x01 << LIN3_URS_OFFSET))  //Reception Status Flag
#define LIN3_UTS_MASK        ((uint8_t)(0x01 << LIN3_UTS_OFFSET))  //Transmission Status Flag
#define LIN3_ERR_MASK        ((uint8_t)(0x01 << LIN3_ERR_OFFSET))  //Error Detection Flag
#define LIN3_FRC_MASK        ((uint8_t)(0x01 << LIN3_FRC_OFFSET))  //Successful Frame/Wake-up Reception Flag
#define LIN3_FTC_MASK        ((uint8_t)0x01)                      //Successful UART Buffer Transmission Flag

/*RLN3nLEST - LIN/UART Error Status Register*/
#define LIN3_RPER_OFFSET    7
#define LIN3_UPER_OFFSET    6
#define LIN3_IDMT_OFFSET    5
#define LIN3_CSER_OFFSET    5
#define LIN3_EXBT_OFFSET    4
#define LIN3_SFER_OFFSET    4
#define LIN3_FER_OFFSET     3
#define LIN3_OER_OFFSET     2
#define LIN3_FTER_OFFSET    2
#define LIN3_TER_OFFSET     2
#define LIN3_PBER_OFFSET    1
#define LIN3_BER_OFFSET     0

#define LIN3_RPER_MASK      ((uint8_t)(0x01 << LIN3_RPER_OFFSET)) //Response Preparation Error Flag
#define LIN3_UPER_MASK      ((uint8_t)(0x01 << LIN3_UPER_OFFSET)) //Parity Error Flag
#define LIN3_IDMT_MASK      ((uint8_t)(0x01 << LIN3_IDMT_OFFSET)) //ID Match Flag
#define LIN3_CSER_MASK      ((uint8_t)(0x01 << LIN3_CSER_OFFSET)) //Checksum Error Flag
#define LIN3_EXBT_MASK      ((uint8_t)(0x01 << LIN3_EXBT_OFFSET)) //Expansion Bit Detection Flag
#define LIN3_SFER_MASK      ((uint8_t)(0x01 << LIN3_SFER_OFFSET)) //Sync Field Error Flag
#define LIN3_FER_MASK       ((uint8_t)(0x01 << LIN3_FER_OFFSET))  //Framing Error Flag
#define LIN3_OER_MASK       ((uint8_t)(0x01 << LIN3_OER_OFFSET))  //Overrun Error Flag
#define LIN3_FTER_MASK      ((uint8_t)(0x01 << LIN3_FTER_OFFSET)) //Timeout Error Flag
#define LIN3_TER_MASK       ((uint8_t)(0x01 << LIN3_TER_OFFSET)) //Timeout Error Flag
#define LIN3_PBER_MASK      ((uint8_t)(0x01 << LIN3_PBER_OFFSET)) //Physical Bus Error Flag
#define LIN3_BER_MASK       ((uint8_t)0x01)                       //Bit Error Flag

/*RLN3nLDFC - LIN/UART Data Field Configuration Register*/
#define LIN3_LSS_OFFSET     7
#define LIN3_FSM_OFFSET     6
#define LIN3_UTSW_OFFSET    5
#define LIN3_CSM_OFFSET     5
#define LIN3_LCS_OFFSET     5
#define LIN3_RFT_OFFSET     4
#define LIN3_RCDS_OFFSET    4
#define LIN3_MDL_OFFSET     0
#define LIN3_RFDL_OFFSET    0

#define LIN3_LSS_MASK       ((uint8_t)(0x01 << LIN3_LSS_OFFSET)) //Transmission/Reception Continuation Select
#define LIN3_FSM_MASK       ((uint8_t)(0x01 << LIN3_FSM_OFFSET)) //Frame Separate Mode Select
#define LIN3_CSM_MASK       ((uint8_t)(0x01 << LIN3_CSM_OFFSET)) //Checksum Select
#define LIN3_LCS_MASK       ((uint8_t)(0x01 << LIN3_LCS_OFFSET)) //Checksum Select
#define LIN3_UTSW_MASK      ((uint8_t)(0x01 << LIN3_UTSW_OFFSET)) //Transmission Start Wait
#define LIN3_RFT_MASK       ((uint8_t)(0x01 << LIN3_RFT_OFFSET)) //Response Field Communication Direction Select
#define LIN3_RCDS_MASK      ((uint8_t)(0x01 << LIN3_RCDS_OFFSET))//Response Field Communication Direction Select
#define LIN3_MDL_MASK       ((uint8_t)0x0F) //UART Buffer Data Length Select
#define LIN3_RFDL_MASK      ((uint8_t)0x0F) //Response Field Length Select

/*RLN3nLIDB - LIN/UART ID Buffer Register*/
#define LIN3_IDP1_OFFSET    7
#define LIN3_IDP0_OFFSET    6
#define LIN3_IDP_OFFSET     6

#define LIN3_IDP1_MASK      ((uint8_t)(0x01 << LIN3_IDP1_OFFSET)) //Parity Setting (P1)
#define LIN3_IDP0_MASK      ((uint8_t)(0x01 << LIN3_IDP0_OFFSET)) //Parity Setting (P0)
#define LIN3_IDP_MASK       ((uint8_t)(0x03 << LIN3_IDP_OFFSET)) //Parity Setting
#define LIN3_LIN_ID_MASK    0x3F    //LIN ID Setting
#define LIN3_UART_ID_MASK   0xFF    //Specifies the ID value that is referred in expansion bit data comparison


/*RLN3nLUOER - UART Operation Enable Register*/
#define LIN3_UROE_OFFSET    1
#define LIN3_UTOE_OFFSET    0

#define LIN3_UROE_MASK      ((uint8_t)(0x01 << LIN3_UROE_OFFSET)) //Reception Enable
#define LIN3_UTOE_MASK      ((uint8_t)0x01)                       //Transmission Enable

/*RLN3nLUOR1 - UART Option Register 1*/
#define LIN3_UECD_OFFSET    4
#define LIN3_UTIGTS_OFFSET  3
#define LIN3_UEBDCE_OFFSET  2
#define LIN3_UEBDL_OFFSET   1
#define LIN3_UEBE_OFFSET    0

#define LIN3_UECD_MASK      ((uint8_t)(0x01 << LIN3_UECD_OFFSET))
#define LIN3_UTIGTS_MASK    ((uint8_t)(0x01 << LIN3_UTIGTS_OFFSET))
#define LIN3_UEBDCE_MASK    ((uint8_t)(0x01 << LIN3_UEBDCE_OFFSET))
#define LIN3_UEBDL_MASK     ((uint8_t)(0x01 << LIN3_UEBDL_OFFSET))
#define LIN3_UEBE_MASK      ((uint8_t)0x01)


#define LIN3N_ADDR(_UNIT_)          ((volatile struct __tag31 *)(((uint8_t*)(&_RLIN30))+  0x40*(_UNIT_)))
#define LIN3N_VAL(_UNIT_)           (*((volatile struct __tag31 *)(((uint8_t*)(&_RLIN30))+  0x40*(_UNIT_))))


/*RLN3nLWBR - LIN Wake-Up Baud Rate Select Register*/
#define __RLIN3_SELECT_WAKEUP_BAUDRATE(_N_,_MASK_,_VALUE_)    MODIFY_REG(&LIN3N_VAL(_N_).LWBR,_MASK_,_VALUE_)
#define __RLIN3_GET_WAKEUP_BAUDRATE(_N_,_MASK_)               (LIN3N_VAL(_N_).LWBR & (_MASK_))

/*RLN3nLBRP01 - LIN/UART Baud Rate Prescaler 01/0/1 Register*/
#define __RLIN3_SET_BAUDRATE_PRE01(_N_,_VALUE_)             (LIN3N_VAL(_N_).LBRP01.UINT16 = _VALUE_ & 0xFFFF)
#define __RLIN3_GET_BAUDRATE_PRE01(_N_)                     (LIN3N_VAL(_N_).LBRP01.UINT16 & 0xFFFF)
#define __RLIN3_SET_BAUDRATE_PRE0(_N_,_VALUE_)              (LIN3N_VAL(_N_).LBRP01.UINT8[0] = _VALUE_ & 0xFF)
#define __RLIN3_GET_BAUDRATE_PRE0(_N_)                      (LIN3N_VAL(_N_).LBRP01.UINT8[0] & 0xFF)
#define __RLIN3_SET_BAUDRATE_PRE1(_N_,_VALUE_)              (LIN3N_VAL(_N_).LBRP01.UINT8[1] = _VALUE_ & 0xFF)
#define __RLIN3_GET_BAUDRATE_PRE1(_N_)                      (LIN3N_VAL(_N_).LBRP01.UINT8[1] & 0xFF)

/*RLN3nLSTC - LIN Self-Test Control Register*/
#define __RLIN3_ENTER_SELF_TEST(_N_)                        do{ \
                                                                LIN3N_VAL(_N_).LSTC = 0xA7; \
                                                                LIN3N_VAL(_N_).LSTC = 0x58; \
                                                                LIN3N_VAL(_N_).LSTC = 0x01; \
                                                            }while(0)
#define __RLIN3_GET_SELF_TEST_STAT(_N_)                     (LIN3N_VAL(_N_).LSTC & 0x01)

/*RLN3nLMD - LIN/UART Mode Register*/
#define __RLIN3_SET_UART_MODE(_N_,_MASK_,_VALUE_)           MODIFY_REG(&LIN3N_VAL(_N_).LMD,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_MODE(_N_,_MASK_)                   (LIN3N_VAL(_N_).LMD & (_MASK_))
#define __RLIN3_SET_LIN_MODE(_N_,_MASK_,_VALUE_)            __RLIN3_SET_UART_MODE(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_LIN_MODE(_N_,_MASK_)                    __RLIN3_GET_UART_MODE(_N_,_MASK_)

/*RLN3nLBFC - UART Configuration Register*/
/*RLN3nLBFC - LIN Break Field Configuration Register*/
#define __RLIN3_SET_UART_CONFIG(_N_,_MASK_,_VALUE_)         MODIFY_REG(&LIN3N_VAL(_N_).LBFC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_CONFIG(_N_,_MASK_)                 (LIN3N_VAL(_N_).LBFC & (_MASK_))
#define __RLIN3_SET_BREAK_FIELD_CONFIG(_N_,_MASK_,_VALUE_)  __RLIN3_SET_UART_CONFIG(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_BREAK_FIELD_CONFIG(_N_,_MASK_)          __RLIN3_GET_UART_CONFIG(_N_,_MASK_)

/*LN3nLSC - LIN/UART Space Configuration Register*/
#define __RLIN3_SET_UART_SPACE(_N_,_MASK_,_VALUE_)          MODIFY_REG(&LIN3N_VAL(_N_).LSC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_SPACE(_N_,_MASK_)                  (LIN3N_VAL(_N_).LSC & (_MASK_))
#define __RLIN3_SET_LIN_SPACE(_N_,_MASK_,_VALUE_)           __RLIN3_SET_UART_SPACE(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_LIN_SPACE(_N_,_MASK_)                   __RLIN3_GET_UART_SPACE(_N_,_MASK_)

/*RLN3nLWUP - LIN Wake-Up Configuration Register*/
#define __RLIN3_SET_WAKEUP_CONIFG(_N_,_MASK_,_VALUE_)       MODIFY_REG(&LIN3N_VAL(_N_).LWUP,_MASK_,_VALUE_)
#define __RLIN3_GET_WAKEUP_CONIFG(_N_,_MASK_)               (LIN3N_VAL(_N_).LWUP & (_MASK_))

/*RLN3nLIE - LIN Interrupt Enable Register*/
#define __RLIN3_ENABLE_INT(_N_,_MASK_,_VALUE_)              MODIFY_REG(&LIN3N_VAL(_N_).LIE,_MASK_,_VALUE_)
#define __RLIN3_GET_INT_STAT(_N_,_MASK_)                    (LIN3N_VAL(_N_).LIE & (_MASK_))
#define __RLIN3_CONFIG_INT(_N_,_VALUE_)                     (LIN3N_VAL(_N_).LIE  = _VALUE_ & 0xff)
/*RLN3nLEDE - LIN/UART Error Detection Enable Register*/
#define __RLIN3_ENABLE_ERR_DETECT(_N_,_MASK_,_VALUE_)       MODIFY_REG(&LIN3N_VAL(_N_).LEDE,_MASK_,_VALUE_)
#define __RLIN3_GET_ERR_DETECT(_N_,_MASK_)                  (LIN3N_VAL(_N_).LEDE & (_MASK_))
#define __RLIN3_CONFIG_ERR_DETECT(_N_,_VALUE_)              (LIN3N_VAL(_N_).LEDE  = _VALUE_ & 0xff)
/*RLN3nLCUC - LIN/UART Control Register*/
#define __RLIN3_SET_UART_CTL(_N_,_MASK_,_VALUE_)            MODIFY_REG(&LIN3N_VAL(_N_).LCUC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_CTL(_N_,_MASK_)                    (LIN3N_VAL(_N_).LCUC & (_MASK_))
#define __RLIN3_SET_LIN_CTL(_N_,_MASK_,_VALUE_)             __RLIN3_SET_UART_CTL(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_LIN_CTL(_N_,_MASK_)                     __RLIN3_GET_UART_CTL(_N_,_MASK_)

/*RLN3nLTRC - LIN/UART Transmission Control Register*/
#define __RLIN3_SET_UART_TX_CTL(_N_,_MASK_,_VALUE_)         MODIFY_REG(&LIN3N_VAL(_N_).LTRC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_TX_CTL(_N_,_MASK_)                 (LIN3N_VAL(_N_).LTRC & (_MASK_))
#define __RLIN3_SET_LIN_TX_CTL(_N_,_MASK_,_VALUE_)          __RLIN3_SET_UART_TX_CTL(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_LIN_TX_CTL(_N_,_MASK_)                  __RLIN3_GET_UART_TX_CTL(_N_,_MASK_)

/*RLN3nLMST - LIN/UART Mode Status Register read-only register*/
#define __RLIN3_GET_UART_MODE_STAT(_N_,_MASK_)              (LIN3N_VAL(_N_).LMST & (_MASK_))
#define __RLIN3_GET_LIN_MODE_STAT(_N_,_MASK_)               __RLIN3_GET_UART_MODE_STAT(_N_,_MASK_)

/*RLN3nLST - LIN/UART Status Register*/
#define __RLIN3_SET_UART_STAT(_N_,_MASK_,_VALUE_)           MODIFY_REG(&LIN3N_VAL(_N_).LST,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_STAT(_N_,_MASK_)                   (LIN3N_VAL(_N_).LST & (_MASK_))
#define __RLIN3_SET_LIN_STAT(_N_,_MASK_,_VALUE_)            __RLIN3_SET_UART_STAT(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_LIN_STAT(_N_,_MASK_)                    __RLIN3_GET_UART_STAT(_N_,_MASK_)

/*RLN3nLEST - LIN/UART Error Status Register*/
#define __RLIN3_SET_UART_ERR_STAT(_N_,_MASK_,_VALUE_)       MODIFY_REG(&LIN3N_VAL(_N_).LEST,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_ERR_STAT(_N_,_MASK_)               (LIN3N_VAL(_N_).LEST & (_MASK_))
#define __RLIN3_SET_LIN_ERR_STAT(_N_,_MASK_,_VALUE_)        __RLIN3_SET_UART_ERR_STAT(_N_,_MASK_,_VALUE_)
#define __RLIN3_GET_LIN_ERR_STAT(_N_,_MASK_)                __RLIN3_GET_UART_ERR_STAT(_N_,_MASK_)

/*RLN3nLDFC - UART Data Field Configuration Register*/
#define __RLIN3_SET_DATA_FIELD_CONFIG(_N_,_MASK_,_VALUE_)   MODIFY_REG(&LIN3N_VAL(_N_).LDFC,_MASK_,_VALUE_)
#define __RLIN3_GET_DATA_FIELD_CONFIG(_N_,_MASK_)           (LIN3N_VAL(_N_).LDFC & (_MASK_))

/*RLN3nLIDB - LIN/UART ID Buffer Register*/
#define __RLIN3_SET_ID_BUF(_N_,_VALUE_)                     (LIN3N_VAL(_N_).LIDB = _VALUE_ & 0xFF)
#define __RLIN3_GET_ID_BUF(_N_)                             (LIN3N_VAL(_N_).LIDB & 0xFF)

/*RLN3nLCBR - LIN Checksum Buffer Register*/
#define __RLIN3_SET_CHECKSUM_BUF(_N_,_VALUE_)               (LIN3N_VAL(_N_).LCBR = _VALUE_ & 0xFF)
#define __RLIN3_GET_CHECKSUM_BUF(_N_)                       (LIN3N_VAL(_N_).LCBR & 0xFF)

/*RLN3nLUDB0 - UART Data Buffer 0 Register*/
#define __RLIN3_WRITE_DATA_BUF0(_N_,_VALUE_)                (LIN3N_VAL(_N_).LUDB0 = _VALUE_ & 0xFF)
#define __RLIN3_READ_DATA_BUF0(_N_)                         (LIN3N_VAL(_N_).LUDB0 & 0xFF)

/*RLN3nLDBRb - LIN/UART Data Buffer b Register (b = 1 to 8)*/
#define __RLIN3_WRITE_DATA_BUF(_N_,_B_,_VALUE_)             (*(((uint8_t*)&LIN3N_VAL(_N_).LDBR1) + (_B_) - 1) = _VALUE_ & 0xFF)
#define __RLIN3_READ_DATA_BUF(_N_,_B_)                      (*(((uint8_t*)&LIN3N_VAL(_N_).LDBR1) + (_B_) - 1) & 0xFF)

/*RLN3nLUOER - UART Operation Enable Register*/
#define __RLIN3_ENABEL_OPERATION(_N_,_MASK_,_VALUE_)        MODIFY_REG(&LIN3N_VAL(_N_).LUOER,_MASK_,_VALUE_)
#define __RLIN3_GET_OPERATION_STAT(_N_,_MASK_)              (LIN3N_VAL(_N_).LUOER & (_MASK_))

/*RLN3nLUOR1 - UART Option Register 1*/
#define __RLIN3_SET_OPTION_REG(_N_,_MASK_,_VALUE_)          MODIFY_REG(&LIN3N_VAL(_N_).LUOR1,_MASK_,_VALUE_)
#define __RLIN3_GET_OPTION_REG(_N_,_MASK_)                  (LIN3N_VAL(_N_).LUOR1 & (_MASK_))

/*RLN3nLUTDR - UART Transmission Data Register*/
#define __RLIN3_WRITE_TX_DATA(_N_,_VALUE_)                  (LIN3N_VAL(_N_).LUTDR.UINT16 = _VALUE_ & 0x1FF)
#define __RLIN3_READ_TX_DATA(_N_)                           (LIN3N_VAL(_N_).LUTDR.UINT16 & 0x1FF)

/*RLN3nLURDR - UART Reception Data Register read-only register */
#define __RLIN3_READ_RX_DATA(_N_)                           (LIN3N_VAL(_N_).LURDR.UINT16 & 0x1FF)

/*RLN3nLUWTDR - UART Wait Transmission Data Register*/
#define __RLIN3_WRITE_TXWAIT_DATA(_N_,_VALUE_)              (LIN3N_VAL(_N_).LUWTDR.UINT16 = _VALUE_ & 0x1FF)
#define __RLIN3_READ_TXWAIT_DATA(_N_)                       (LIN3N_VAL(_N_).LUWTDR.UINT16 & 0x1FF)


#define BAUDRATE_SAMPLE_CNT_16_  0
#define BAUDRATE_SAMPLE_CNT_4    3
#define BAUDRATE_SAMPLE_CNT_6    5
#define BAUDRATE_SAMPLE_CNT_7    6
#define BAUDRATE_SAMPLE_CNT_8    7
#define BAUDRATE_SAMPLE_CNT_9    8
#define BAUDRATE_SAMPLE_CNT_10   9
#define BAUDRATE_SAMPLE_CNT_11   10
#define BAUDRATE_SAMPLE_CNT_12   11
#define BAUDRATE_SAMPLE_CNT_13   12
#define BAUDRATE_SAMPLE_CNT_14   13
#define BAUDRATE_SAMPLE_CNT_15   14
#define BAUDRATE_SAMPLE_CNT_16   15

#define PRESCALER_CLK_DIV_1      0
#define PRESCALER_CLK_DIV_2      1
#define PRESCALER_CLK_DIV_4      2
#define PRESCALER_CLK_DIV_8      3
#define PRESCALER_CLK_DIV_16     4
#define PRESCALER_CLK_DIV_32     5
#define PRESCALER_CLK_DIV_64     6
#define PRESCALER_CLK_DIV_128    7
/*LIN Interrupt Enable mask*/
#define LIN3_EN_HDR_TX_INT_MASK  8 //Successful Header Transmission Interrupt Request mask
#define LIN3_ERR_DETECT_INT_MASK 4 //Error Detection Interrupt Request mask
#define LIN3_FRM_WU_RX_INT_MASK  2 //Successful Frame/Wake-up Reception Interrupt Request mask
#define LIN3_RES_WU_RX_INT_MASK  2 //Successful Response/Wake-up Reception Interrupt Request Enable
#define LIN3_FRM_WU_TX_INT_MASK  1 //Successful Frame/Wake-up Transmission Interrupt Request mask
#define LIN3_RES_WU_TX_INT_MASK  1 //Successful Response/Wake-up Transmission Interrupt Request Enable
/*LIN Error Detection Enable mask*/
#define LIN3_IDP_ERR_DETECT_MASK 64   //ID Parity Error Detection Enable
#define LIN3_SYN_ERR_DETECT_MASK 16 //Sync Field Error Detection Enable
#define LIN3_FRM_ERR_DETECT_MASK 8 //Framing Error Detection mask
#define LIN3_TIO_ERR_DETECT_MASK 4 //Timeout Error Detection mask
#define LIN3_PHB_ERR_DETECT_MASK 2 //Physical Bus Error Detection mask
#define LIN3_BIT_ERR_DETECT_MASK 1 //Bit Error Detection mask

typedef enum{
    LIN3_MASTER,//0 0: LIN master mode
    UART_MODE,  //0 1:Uart mode
    LIN3_SLAVE_AUTO,//1 0: LIN Slave mode (auto baud rate)
    LIN3_SLAVE_FIXED,//1 1: LIN Slave mode (fixed baud rate)
}LIN3_Mode;

typedef union{
    uint16_t brp; //baudrate prescaler
    struct{
        uint16_t brp0:8;
        uint16_t brp1:8;
    }bits;
}Br_PrescalerUnion;

typedef struct{
    uint8_t bit_sample_cnt; /*<Bit Sampling Count Select  UART: 6 -16 samplings>
                                LIN master: only 16 samplings
                                LIN slave : 4,8,16 samplings*/
    uint8_t prescaler_clk;  //Prescaler Clock Select
    Br_PrescalerUnion brp_un;  /*<the baud rate prescaler divides the frequency of
                                the prescaler clock by L + 1.UART or LIN slave: 0-65535
                                LIN master:low 8 bit set to RLN3nLBRP0,hi 8 bit set to RLN3nLBRP1*/
    uint8_t lin_sys_clk;   /*<LIN System Clock Select:>
                                0 0: fa (Clock generated by baud rate prescaler 0)
                                0 1: fb (1/2 clock generated by baud rate prescaler 0)
                                1 0: fc (1/8 clock generated by baud rate prescaler 0)
                                1 1: fd (1/2 clock generated by baud rate prescaler 1)*/
}UART_BaudrateTypeDef,LIN3_BaudrateTypeDef;

typedef union{
    uint8_t err_dct;
    struct{
        uint8_t bit_err_on :1;     //Bit Error Detection Enable/Disable
        uint8_t            :1;     //reserve
        uint8_t over_run_on:1;     //Overrun Error Detection Enable/Disable
        uint8_t frm_err_on :1;     //Framing Error Detection Enable/Disable
        uint8_t            :4;     //reserve
    }bits;
}UART_Err_DetectUnion;

typedef union{
    uint8_t option;
    struct{
        uint8_t expbit_on       :1;     //Expansion Bit Enable
        uint8_t expbit_level_dct:1;     //Expansion Bit Detection Level Select
        uint8_t exbit_datacmp_en:1;     //Expansion Bit Data Comparison Enable
        uint8_t tx_int_timing   :1;     //Transmission Interrupt Generation Timing Select
        uint8_t exbits_cmp_off  :1;     //Expansion Bit Comparison Disable
    }param_bits;
    struct{
        uint8_t UEBE       :1;          //Expansion Bit Enable
        uint8_t UEBDL      :1;          //Expansion Bit Detection Level Select
        uint8_t UEBDCE     :1;          //Expansion Bit Data Comparison Enable
        uint8_t UTIGTS     :1;          //Transmission Interrupt Generation Timing Select
        uint8_t UECD       :1;          //Expansion Bit Comparison Disable
    }reg_bits;
}UART_OptionUnion;

typedef struct{
    uint8_t uartn;
    uint32_t baudrate;      //this member configures the USART communication baud rate
    uint8_t word_length;     //Specifies the number of data bits transmitted or received in a frame.
    uint8_t stop_bits;      //Specifies the number of stop bits transmitted.
    uint8_t parity;         //Specifies the parity mode
    uint8_t mode;           //Specifies wether the Receive or Transmit mode is enabled or disabled.
    uint8_t noi_filter_off; // Sets noise filter ON/OFF,0:enable(ON) 1:disable(OFF)
    UART_Err_DetectUnion err_dct_un; //Enables or disable error detection.
    UART_OptionUnion opt_un;
}UART_InitTypeDef;

typedef struct{
    uint8_t break_delim_width;/*<Transmission Break Delimiter (High Level) Width Select
                                0 0: 1 Tbit, 0 1: 2 Tbits,1 0: 3 Tbits,1 1: 4 Tbits>*/
    uint8_t break_width;/*<Transmission Break (Low Level) Width Select
                            0 0 0 0: 13 Tbits
                            0 0 0 1: 14 Tbits
                            0 0 1 0: 15 Tbits
                            :
                            1 1 1 0: 27 Tbits
                            1 1 1 1: 28 Tbits>*/
    uint8_t rx_break_detect_width;/*<Reception Break (Low-Level) Detection Width Setting>
                            0: A break (low-level) is detected in 9.5 or 10 Tbits
                            1: A break (low-level) is detected in 10.5 or 11 Tbits*/
    uint8_t inter_byte_space;/*<Inter-Byte Space Select
                            0 0: 0 Tbit, 0 1: 1 Tbit,1 0: 2 Tbits,1 1: 3 Tbits>*/
    uint8_t resp_space; /*<Inter-Byte Space (Header)/Response Space Select
                            0 0 0: 0 Tbit
                            0 0 1: 1 Tbit
                            0 1 0: 2 Tbits
                            0 1 1: 3 Tbits
                            1 0 0: 4 Tbits
                            1 0 1: 5 Tbits
                            1 1 0: 6 Tbits
                            1 1 1: 7 Tbits>*/
    uint8_t wu_tx_ll_width;//Wake-up Transmission Low Level Width
}LIN3_ConfigurationTypeDef;

typedef struct{
    uint8_t frm_id; /*the ID set the 6-bit ID value to be transmitted in the ID field of the LIN frame.*/
    //uint8_t idp0;   //sets the parity bits (P0) to be transmitted in the ID field
    //uint8_t idp1;   //sets the parity bits (P1) to be transmitted in the ID field.
    uint8_t frm_sep;/*<Frame Separate Mode Select:
                    0: Frame separate mode is not set. 1: Frame separate mode is set.
                    With 0 set,after header transmission is started,response is transmitted/received without
                    setting the RTS bit in the RLN3nLTRC register.>*/
    uint8_t resp_dir;/*<sets the direction of the response field/wake-up signal communication
                    0: Reception 1: Transmission>*/
    uint8_t cs_meth;/*<selects the checksum mode.
                    0: Classic checksum mode 1: Enhanced checksum mode>*/
}LIN3_Frm_InfoTypeDef;

typedef struct{
    uint8_t linn;
    LIN3_Mode mode;
    uint16_t baudrate; // 1- 20K
    uint8_t noi_filter_off; // Sets noise filter ON/OFF,0:enable(ON) 1:disable(OFF)
    LIN3_ConfigurationTypeDef cfg_param;
    uint8_t int_out_sel; /*<LIN Interrupt Output Select
                            0: RLIN3 interrupt is used.
                            1: RLIN3n transmission interrupt, RLIN3n successful reception
                            interrupt, and RLIN3n reception status interrupt are used.>*/
    uint8_t int_en_mask;//LIN Interrupt Enable mask
    uint8_t timeout_err_sel;/*<Timeout Error Select
                            0: Frame timeout error
                            1: Response timeout error>*/
    uint8_t err_en_mask;//LIN Error Detection Enable mask
}LIN3_InitTypeDef,LIN3_SelfModeInitTypeDef;

uint8_t UART_Send_Data(uint8_t uartn,uint8_t* data, uint8_t data_len);

uint8_t UART_Recv_Data(uint8_t uartn,uint16_t* data);
bool UART_Get_Rx_State(uint8_t uartn);

void LIN3_Init(LIN3_InitTypeDef* LIN3_InitStruct);
int8_t LIN3_Master_Process(uint8_t linn,LIN3_Frm_InfoTypeDef *info_p,uint8_t resp_len,uint8_t *resp_data);
void RLIN3_Self_Mode_Init(LIN3_SelfModeInitTypeDef *LIN3_InitStruct);

/******************************************************************************/
/*******************######  #       ### #     #  ##### ************************/ 
/*******************#     # #        #  ##    # #     #************************/ 
/*******************#     # #        #  # #   #       #************************/ 
/*******************######  #        #  #  #  #  ##### ************************/ 
/*******************#   #   #        #  #   # # #      ************************/ 
/*******************#    #  #        #  #    ## #      ************************/ 
/*******************#     # ####### ### #     # #######************************/ 
/******************************************************************************/

/*Note: the index n(0 to 3) used in this file  is not consistent with that in the manual(n=0,1).*/
#define MAX_LIN2_NUM        4   //maximal number of units in LIN2 (0 to 3),corresponding to n
#define MAX_LIN2_CH_NUM     10 // maximal number of channels in LIN2 (0 to 9),corresponding to m

#define _RLN240     RLN240
#define _RLN20      RLN2400
#define _RLN21      RLN2401
#define _RLN22      RLN2402
#define _RLN23      RLN2403
#define _RLN241     RLN241
#define _RLN24      RLN2414
#define _RLN25      RLN2415
#define _RLN26      RLN2416
#define _RLN27      RLN2417
#define _RLN210     RLN210
#define _RLN28      RLN2108
#define _RLN211     RLN211
#define _RLN29      RLN2119

/*LIN2 unit:n (0 to 3)*/
#define LIN240      0
#define LIN241      1
#define LIN210      2
#define LIN211      3

/*LIN2 channel:m (0 to 9)*/
#define LIN20       0
#define LIN21       1
#define LIN22       2
#define LIN23       3
#define LIN24       4
#define LIN25       5
#define LIN26       6
#define LIN27       7
#define LIN28       8
#define LIN29       9

#define __lin2n_glbl_tag  __tag26   /*lin2 global struct*/
struct __lin2m_ch_tag
{                                                         /* Module           */
    unsigned char  LMD;                                   /* LMD              */
    unsigned char  LBFC;                                  /* LBFC             */
    unsigned char  LSC;                                   /* LSC              */
    unsigned char  LWUP;                                  /* LWUP             */
    unsigned char  LIE;                                   /* LIE              */
    unsigned char  LEDE;                                  /* LEDE             */
    unsigned char  LCUC;                                  /* LCUC             */
    unsigned char  dummy0[1];                             /* Reserved         */
    unsigned char  LTRC;                                  /* LTRC             */
    unsigned char  LMST;                                  /* LMST             */
    unsigned char  LST;                                   /* LST              */
    unsigned char  LEST;                                  /* LEST             */
    unsigned char  LDFC;                                  /* LDFC             */
    unsigned char  LIDB;                                  /* LIDB             */
    unsigned char  LCBR;                                  /* LCBR             */
    unsigned char  dummy1[1];                             /* Reserved         */
    unsigned char  LDBR1;                                 /* LDBR1            */
    unsigned char  LDBR2;                                 /* LDBR2            */
    unsigned char  LDBR3;                                 /* LDBR3            */
    unsigned char  LDBR4;                                 /* LDBR4            */
    unsigned char  LDBR5;                                 /* LDBR5            */
    unsigned char  LDBR6;                                 /* LDBR6            */
    unsigned char  LDBR7;                                 /* LDBR7            */
    unsigned char  LDBR8;                                 /* LDBR8            */
};


/*RLN24nGLWBR / RLN21nGLWBR - LIN Wake-Up Baud Rate Select Register*/
#define LIN2_LWBR0_MASK     ((uint8_t)0x01) //Wake-up Baud Rate Select

/*RLN24nGLBRP0 / RLN21nGLBRP0 - LIN Baud Rate Prescaler 0 Register
RLN24nGLBRP1 / RLN21nGLBRP1 - LIN Baud Rate Prescaler 1 Register
used to control the frequency of baud rate clock source fa, fb, and fc*/
#define LIN2_LBRP0_MASK     0xFF    //N
#define LIN2_LBRP1_MASK     0xFF    //M

/*RLN24nmLiMD / RLN21nmLiMD - LIN Mode Register*/
#define LIN2_LCKS_OFFSET     2
#define LIN2_LCKS_MASK       ((uint8_t)(0x03 << LIN2_LCKS_OFFSET)) //LIN System Clock Select

/*RLN24nmLiBFC / RLN21nmLiBFC - LIN Break Field Configuration Register*/
#define LIN2_BDT_OFFSET      4
#define LIN2_BDT_MASK        ((uint8_t)(0x03 << LIN2_BDT_OFFSET)) //Transmission Break Delimiter (High Level) Width Select
#define LIN2_BLT_MASK        ((uint8_t)0x0F) //Transmission Break (Low Level) Width Select

/*RLN24nmLiSC / RLN21nmLiSC - LIN Space Configuration Register*/
#define LIN2_IBS_OFFSET      4
#define LIN2_IBS_MASK        ((uint8_t)(0x03 << LIN2_IBS_OFFSET)) //Inter-Byte Space Select
#define LIN2_IBHS_MASK       ((uint8_t)0x07) //Inter-Byte Space (Header)/Response Space Select

/*RLN24nmLiWUP / RLN21nmLiWUP - LIN Wake-Up Configuration Register*/
#define LIN2_WUTL_OFFSET     4
#define LIN2_WUTL_MASK       ((uint8_t)(0x0F << LIN2_WUTL_OFFSET)) //Wake-up Transmission Low Level Width Select

/*RLN24nmLiIE / RLN21nmLiIE - LIN Interrupt Enable Register*/
#define LIN2_ERRIE_OFFSET    2
#define LIN2_FRCIE_OFFSET    1
#define LIN2_FTCIE_OFFSET    0
#define LIN2_ERRIE_MASK      ((uint8_t)(0x01 << LIN2_ERRIE_OFFSET)) //Error Detection Interrupt Request Enable
#define LIN2_FRCIE_MASK      ((uint8_t)(0x01 << LIN2_FRCIE_OFFSET)) //Successful Frame/Wake-up Reception Interrupt Request Enable
#define LIN2_FTCIE_MASK      ((uint8_t)0x01) //Successful Frame/Wake-up Transmission Interrupt Request Enable

/*RLN24nmLiEDE / RLN21nmLiEDE - LIN Error Detection Enable Register*/
#define LIN2_FERE_OFFSET     3
#define LIN2_FTERE_OFFSET    2
#define LIN2_PBERE_OFFSET    1

#define LIN2_FERE_MASK      ((uint8_t)(0x01 << LIN2_FERE_OFFSET)) //Framing Error Detection Enable
#define LIN2_FTERE_MASK     ((uint8_t)(0x01 << LIN2_FTERE_OFFSET))//Timeout Error Detection Enable
#define LIN2_PBERE_MASK     ((uint8_t)(0x01 << LIN2_PBERE_OFFSET))//Physical Bus Error Detection Enable
#define LIN2_BERE_MASK      ((uint8_t)0x01) //Bit Error Detection Enable

/*RLN24nmLiCUC / RLN21nmLiCUC - LIN Control Register*/
#define LIN2_OM1_OFFSET      1
#define LIN2_OM1_MASK        ((uint8_t)(0x01 << LIN2_OM1_OFFSET))//LIN Mode Select
#define LIN2_OM0_MASK        0x01 //LIN Reset

/*RLN24nmLiTRC / RLN21nmLiTRC - LIN Transmission Control Register*/
#define LIN2_RTS_OFFSET      1

#define LIN2_RTS_MASK        ((uint8_t)(0x01 << LIN2_RTS_OFFSET)) //Response Transmission/Reception Start
#define LIN2_FTS_MASK        ((uint8_t)0x01)   //Frame Transmission/Wake-up Transmission/Reception Start

/*RLN24nmLiMST / RLN21nmLiMST - LIN Mode Status Register read-only**/
#define LIN2_OMM1_OFFSET    1
#define LIN2_OMM1_MASK      ((uint8_t)(0x01 << LIN2_OMM1_OFFSET))//LIN Mode Status Monitor
#define LIN2_OMM0_MASK      0x01 //LIN Reset Status Monitor

/*RLN24nmLiST / RLN21nmLiST - LIN Status Register*/
#define LIN2_HTRC_OFFSET     7
#define LIN2_D1RC_OFFSET     6
#define LIN2_ERR_OFFSET      3
#define LIN2_FRC_OFFSET      1
#define LIN2_FTC_OFFSET      0

#define LIN2_HTRC_MASK       ((uint8_t)(0x01 << LIN2_HTRC_OFFSET)) //Successful Header Transmission Flag
#define LIN2_D1RC_MASK       ((uint8_t)(0x01 << LIN2_D1RC_OFFSET)) //Successful Data 1 Reception Flag
#define LIN2_ERR_MASK        ((uint8_t)(0x01 << LIN2_ERR_OFFSET))  //Error Detection Flag
#define LIN2_FRC_MASK        ((uint8_t)(0x01 << LIN2_FRC_OFFSET))  //Successful Frame/Wake-up Reception Flag
#define LIN2_FTC_MASK        ((uint8_t)0x01)                      //Successful UART Buffer Transmission Flag

/*RLN24nmLiEST / RLN21nmLiEST - LIN Error Status Register*/
#define LIN2_CSER_OFFSET    5
#define LIN2_FER_OFFSET     3
#define LIN2_FTER_OFFSET    2
#define LIN2_PBER_OFFSET    1
#define LIN2_BER_OFFSET     0

#define LIN2_CSER_MASK      ((uint8_t)(0x01 << LIN2_CSER_OFFSET)) //Checksum Error Flag
#define LIN2_FER_MASK       ((uint8_t)(0x01 << LIN2_FER_OFFSET))  //Framing Error Flag
#define LIN2_FTER_MASK      ((uint8_t)(0x01 << LIN2_FTER_OFFSET)) //Timeout Error Flag
#define LIN2_PBER_MASK      ((uint8_t)(0x01 << LIN2_PBER_OFFSET)) //Physical Bus Error Flag
#define LIN2_BER_MASK       ((uint8_t)0x01)                       //Bit Error Flag

/*RLN24nmLiDFC / RLN21nmLiDFC - LIN Data Field Configuration Register*/
#define LIN2_FSM_OFFSET     6
#define LIN2_CSM_OFFSET     5
#define LIN2_RFT_OFFSET     4
#define LIN2_RFDL_OFFSET    0

#define LIN2_FSM_MASK       ((uint8_t)(0x01 << LIN2_FSM_OFFSET)) //Frame Separate Mode Select
#define LIN2_CSM_MASK       ((uint8_t)(0x01 << LIN2_CSM_OFFSET)) //Checksum Select
#define LIN2_RFT_MASK       ((uint8_t)(0x01 << LIN2_RFT_OFFSET)) //Response Field Communication Direction Select
#define LIN2_RFDL_MASK      ((uint8_t)0x0F) //Response Field Length Select

/*RLN24nmLiIDB / RLN21nmLiIDB - LIN ID Buffer Register*/
#define LIN2_IDP1_OFFSET    7
#define LIN2_IDP0_OFFSET    6
#define LIN2_IDP_OFFSET     6

#define LIN2_IDP1_MASK      ((uint8_t)(0x01 << LIN2_IDP1_OFFSET)) //Parity Setting (P1)
#define LIN2_IDP0_MASK      ((uint8_t)(0x01 << LIN2_IDP0_OFFSET)) //Parity Setting (P0)
#define LIN2_IDP_MASK       ((uint8_t)(0x03 << LIN2_IDP_OFFSET)) //Parity Setting
#define LIN2_LIN_ID_MASK    0x3F    //LIN ID Setting



/******************************LIN2 Global register setting********************/
#define LIN2N_ADDR_OFFSET(_N_)   (0x80*(_N_) - (_N_== 3 ?0x60:0))
#define LIN2N_ADDR(_N_)          ((volatile struct __lin2n_glbl_tag*)(((uint8_t*)(&_RLN240))+  LIN2N_ADDR_OFFSET(_N_)))
#define LIN2N_VAL(_N_)           (*((volatile struct __lin2n_glbl_tag*)(((uint8_t*)(&_RLN240))+  LIN2N_ADDR_OFFSET(_N_))))

/*RLN24nGLWBR / RLN21nGLWBR - LIN Wake-Up Baud Rate Select Register*/
#define __RLIN2_SELECT_WAKEUP_BAUDRATE(_N_,_MASK_,_VALUE_)    MODIFY_REG(&LIN2N_VAL(_N_).GLWBR,_MASK_,_VALUE_)
#define __RLIN2_GET_WAKEUP_BAUDRATE(_N_,_MASK_)               (LIN2N_VAL(_N_).GLWBR & (_MASK_))

/*RLN24nGLBRP0 / RLN21nGLBRP0 - LIN Baud Rate Prescaler 0 Register
RLN24nGLBRP1 / RLN21nGLBRP1 - LIN Baud Rate Prescaler 1 Register
used to control the frequency of baud rate clock source fa, fb, and fc*/
#define __RLIN2_SET_BAUDRATE_PRE0(_N_,_VALUE_)              (LIN2N_VAL(_N_).GLBRP0 = _VALUE_ & LIN2_LBRP0_MASK)
#define __RLIN2_GET_BAUDRATE_PRE0(_N_)                      (LIN2N_VAL(_N_).GLBRP0 & LIN2_LBRP0_MASK)
#define __RLIN2_SET_BAUDRATE_PRE1(_N_,_VALUE_)              (LIN2N_VAL(_N_).GLBRP1 = _VALUE_ & LIN2_LBRP1_MASK)
#define __RLIN2_GET_BAUDRATE_PRE1(_N_)                      (LIN2N_VAL(_N_).GLBRP0 & LIN2_LBRP1_MASK)

/*RLN24nGLSTC / RLN21nGLSTC - LIN Self-Test Control Register*/
#define __RLIN2_ENTER_SELF_TEST(_N_)                        do{ \
                                                                LIN2N_VAL(_N_).GLSTC = 0xA7; \
                                                                LIN2N_VAL(_N_).GLSTC = 0x58; \
                                                                LIN2N_VAL(_N_).GLSTC = 0x01; \
                                                            }while(0)
#define __RLIN2_GET_SELF_TEST_STAT(_N_)                     (LIN2N_VAL(_N_).GLSTC & 0x01)


/******************************LIN2 Channel register setting*******************/

#define LIN2M_ADDR(_M_)          ((volatile struct __lin2m_ch_tag*)(((uint8_t*)(&_RLN20))+  0x20*(_M_)))
#define LIN2M_VAL(_M_)           (*((volatile struct __lin2m_ch_tag*)(((uint8_t*)(&_RLN20))+  0x20*(_M_))))

/*RLN24nmLiMD / RLN21nmLiMD - LIN Mode Register*/
#define __RLIN2_SET_LIN_MODE(_M_,_MASK_,_VALUE_)            MODIFY_REG(&LIN2M_VAL(_M_).LMD,_MASK_,_VALUE_)
#define __RLIN2_GET_LIN_MODE(_M_,_MASK_)                    (LIN2M_VAL(_M_).LMD & (_MASK_))

/*RLN24nmLiBFC / RLN21nmLiBFC - LIN Break Field Configuration Register*/
#define __RLIN2_SET_BREAK_FIELD_CONFIG(_M_,_MASK_,_VALUE_)  MODIFY_REG(&LIN2M_VAL(_M_).LBFC,_MASK_,_VALUE_)
#define __RLIN2_GET_BREAK_FIELD_CONFIG(_M_,_MASK_)          (LIN2M_VAL(_M_).LBFC & (_MASK_))

/*RLN24nmLiSC / RLN21nmLiSC - LIN Space Configuration Register*/
#define __RLIN2_SET_LIN_SPACE(_M_,_MASK_,_VALUE_)           MODIFY_REG(&LIN2M_VAL(_M_).LSC,_MASK_,_VALUE_)
#define __RLIN2_GET_LIN_SPACE(_M_,_MASK_)                   (LIN2M_VAL(_M_).LSC & (_MASK_))

/*RLN24nmLiWUP / RLN21nmLiWUP - LIN Wake-Up Configuration Register*/
#define __RLIN2_SET_WAKEUP_CONIFG(_M_,_MASK_,_VALUE_)       MODIFY_REG(&LIN2M_VAL(_M_).LWUP,_MASK_,_VALUE_)
#define __RLIN2_GET_WAKEUP_CONIFG(_M_,_MASK_)               (LIN2M_VAL(_M_).LWUP & (_MASK_))

/*RLN24nmLiIE / RLN21nmLiIE - LIN Interrupt Enable Register*/
#define __RLIN2_ENABLE_INT(_M_,_MASK_,_VALUE_)              MODIFY_REG(&LIN2M_VAL(_M_).LIE,_MASK_,_VALUE_)
#define __RLIN2_GET_INT_STAT(_M_,_MASK_)                    (LIN2M_VAL(_M_).LIE & (_MASK_))
#define __RLIN2_CONFIG_INT(_M_,_VALUE_)                     (LIN2M_VAL(_M_).LIE  = _VALUE_ & 0xff)

/*RLN24nmLiEDE / RLN21nmLiEDE - LIN Error Detection Enable Register*/
#define __RLIN2_ENABLE_ERR_DETECT(_M_,_MASK_,_VALUE_)       MODIFY_REG(&LIN2M_VAL(_M_).LEDE,_MASK_,_VALUE_)
#define __RLIN2_GET_ERR_DETECT(_M_,_MASK_)                  (LIN2M_VAL(_M_).LEDE & (_MASK_))
#define __RLIN2_CONFIG_ERR_DETECT(_M_,_VALUE_)              (LIN2M_VAL(_M_).LEDE  = _VALUE_ & 0xff)

/*RLN24nmLiCUC / RLN21nmLiCUC - LIN Control Register*/
#define __RLIN2_SET_LIN_CTL(_M_,_MASK_,_VALUE_)             MODIFY_REG(&LIN2M_VAL(_M_).LCUC,_MASK_,_VALUE_)
#define __RLIN2_GET_LIN_CTL(_M_,_MASK_)                     (LIN2M_VAL(_M_).LCUC & (_MASK_))

/*RLN24nmLiTRC / RLN21nmLiTRC - LIN Transmission Control Register*/
#define __RLIN2_SET_LIN_TX_CTL(_M_,_MASK_,_VALUE_)          MODIFY_REG(&LIN2M_VAL(_M_).LTRC,_MASK_,_VALUE_)
#define __RLIN2_GET_LIN_TX_CTL(_M_,_MASK_)                  (LIN2M_VAL(_M_).LTRC & (_MASK_))

/*RLN24nmLiMST / RLN21nmLiMST - LIN Mode Status Register read-only*/
#define __RLIN2_GET_LIN_MODE_STAT(_M_,_MASK_)               (LIN2M_VAL(_M_).LMST & (_MASK_))

/*RLN24nmLiST / RLN21nmLiST - LIN Status Register*/
#define __RLIN2_SET_LIN_STAT(_M_,_MASK_,_VALUE_)            MODIFY_REG(&LIN2M_VAL(_M_).LST,_MASK_,_VALUE_)
#define __RLIN2_GET_LIN_STAT(_M_,_MASK_)                    (LIN2M_VAL(_M_).LST & (_MASK_))

/*RLN24nmLiEST / RLN21nmLiEST - LIN Error Status Register*/
#define __RLIN2_SET_LIN_ERR_STAT(_M_,_MASK_,_VALUE_)        MODIFY_REG(&LIN2M_VAL(_M_).LEST,_MASK_,_VALUE_)
#define __RLIN2_GET_LIN_ERR_STAT(_M_,_MASK_)                (LIN2M_VAL(_M_).LEST & (_MASK_))

/*RLN24nmLiDFC / RLN21nmLiDFC - LIN Data Field Configuration Register*/
#define __RLIN2_SET_DATA_FIELD_CONFIG(_M_,_MASK_,_VALUE_)   MODIFY_REG(&LIN2M_VAL(_M_).LDFC,_MASK_,_VALUE_)
#define __RLIN2_GET_DATA_FIELD_CONFIG(_M_,_MASK_)           (LIN2M_VAL(_M_).LDFC & (_MASK_))

/*RLN24nmLiIDB / RLN21nmLiIDB - LIN ID Buffer Register*/
#define __RLIN2_SET_ID_BUF(_M_,_VALUE_)                     (LIN2M_VAL(_M_).LIDB = _VALUE_ & 0xFF)
#define __RLIN2_GET_ID_BUF(_M_)                             (LIN2M_VAL(_M_).LIDB & 0xFF)

/*RLN24nmLiCBR / RLN21nmLiCBR - LIN Checksum Buffer Register*/
#define __RLIN2_SET_CHECKSUM_BUF(_M_,_VALUE_)               (LIN2M_VAL(_M_).LCBR = _VALUE_ & 0xFF)
#define __RLIN2_GET_CHECKSUM_BUF(_M_)                       (LIN2M_VAL(_M_).LCBR & 0xFF)

/*RLN24nmLiDBRb / RLN21nmLiDBRb - LIN Data Buffer b Register (b = 1 to 8)*/
#define __RLIN2_WRITE_DATA_BUF(_M_,_B_,_VALUE_)             (*(((uint8_t*)&LIN2M_VAL(_M_).LDBR1) + (_B_) - 1) = _VALUE_ & 0xFF)
#define __RLIN2_READ_DATA_BUF(_M_,_B_)                      (*(((uint8_t*)&LIN2M_VAL(_M_).LDBR1) + (_B_) - 1) & 0xFF)


/** @defgroup int_enable_mask
  * @{
  */
#define LIN2_ERR_DETECT_INT_MASK 4 //Error Detection Interrupt Request mask
#define LIN2_FRM_WU_RX_INT_MASK  2 //Successful Frame/Wake-up Reception Interrupt Request mask
#define LIN2_FRM_WU_TX_INT_MASK  1 //Successful Frame/Wake-up Transmission Interrupt Request mask
/**
  * @}
  */

/** @defgroup int_detection_enable_mask
  * @{
  */
#define LIN2_FRM_ERR_DETECT_MASK 8 //Framing Error Detection mask
#define LIN2_TIO_ERR_DETECT_MASK 4 //Timeout Error Detection mask
#define LIN2_PHB_ERR_DETECT_MASK 2 //Physical Bus Error Detection mask
#define LIN2_BIT_ERR_DETECT_MASK 1 //Bit Error Detection mask
/**
  * @}
  */

typedef unsigned char err_statu_t;
/** @defgroup err_status_mask
  * @{
  */
#define LIN2_CKS_ERR_FLAG           LIN2_CSER_MASK //Checksum Error Flag
#define LIN2_FRM_ERR_FlAG           LIN2_FER_MASK  //Framing Error Flag
#define LIN2_FRM_TIMEOUT_ERR_FLAG   LIN2_FTER_MASK //Frame Timeout Error Flag
#define LIN2_PHB_ERR_FLAG           LIN2_PBER_MASK //Physical Bus Error Flag
#define LIN2_BIT_ERR_FLAG           LIN2_BER_MASK  //Bit Error Flag
#define LIN2_NO_ERR                 0
/**
  * @}
  */


typedef struct{
    uint8_t bit_sample_cnt; /*<Bit Sampling Count Select,not used, LIN2 master fixed at 16*/
    uint8_t prescaler_clk;  //Prescaler Clock Select,not used, LIN2 master fixed at 1
    Br_PrescalerUnion brp_un;  /*<the baud rate prescaler divides the frequency of
                                the prescaler clock by L + 1.UART or LIN slave: 0-65535
                                LIN master:low 8 bit set to RLN3nLBRP0,hi 8 bit set to RLN3nLBRP1*/
    uint8_t lin_sys_clk;   /*<LIN System Clock Select:>
                                0 0: fa (Clock generated by baud rate prescaler 0)
                                0 1: fb (1/2 clock generated by baud rate prescaler 0)
                                1 0: fc (1/8 clock generated by baud rate prescaler 0)
                                1 1: fd (1/2 clock generated by baud rate prescaler 1)*/
}LIN2_BaudrateTypeDef;

typedef LIN3_Frm_InfoTypeDef LIN2_Frm_InfoTypeDef;

typedef struct {
    uint8_t break_delim_width;/*<Transmission Break Delimiter (High Level) Width Select
                                0 0: 1 Tbit, 0 1: 2 Tbits,1 0: 3 Tbits,1 1: 4 Tbits>*/
    uint8_t break_width;/*<Transmission Break (Low Level) Width Select
                            0 0 0 0: 13 Tbits
                            0 0 0 1: 14 Tbits
                            0 0 1 0: 15 Tbits
                            :
                            1 1 1 0: 27 Tbits
                            1 1 1 1: 28 Tbits>*/
    uint8_t inter_byte_space;/*<Inter-Byte Space Select
                            0 0: 0 Tbit, 0 1: 1 Tbit,1 0: 2 Tbits,1 1: 3 Tbits>*/
    uint8_t resp_space; /*<Inter-Byte Space (Header)/Response Space Select
                            0 0 0: 0 Tbit
                            0 0 1: 1 Tbit
                            0 1 0: 2 Tbits
                            0 1 1: 3 Tbits
                            1 0 0: 4 Tbits
                            1 0 1: 5 Tbits
                            1 1 0: 6 Tbits
                            1 1 1: 7 Tbits>*/
    uint8_t wu_tx_ll_width;/*Wake-up Transmission Low Level Width Select
                            0 0 0 0: 1 Tbits
                            0 0 0 1: 2 Tbits
                            0 0 1 0: 3 Tbits
                            :
                            1 1 1 0: 15 Tbits
                            1 1 1 1: 16 Tbits>*/
}LIN2_ConfigurationTypeDef;

typedef struct{
    uint8_t linm; //the channel to initial
    uint16_t baudrate; // 1- 20K
    LIN2_ConfigurationTypeDef cfg_param;
    uint8_t int_en_mask;/*!< Specifies the LIN2 Interrupt Enable bits
                            This parameter can be a value of @ref int_enable_mask*/
    uint8_t err_en_mask;/*!< Specifies the LIN2 Interrupt Enable bits
                            This parameter can be a value of @ref int_detection_enable_mask*/
}LIN2_InitTypeDef;

typedef LIN2_InitTypeDef LIN2_SelfModeInitTypeDef;

typedef struct{
    uint8_t linm; //the channel to initial
    uint16_t baudrate; // 1- 20K
    uint8_t  rate_sel; // Wake-up Baud Rate Select
    uint8_t wu_tx_ll_width; //Wake-up Transmission Low Level Width
    uint8_t tx_int;/*!< Specifies the LIN2 Interrupt Enable bits
                            This parameter can be the LIN2_FRM_WU_TX_INT_MASK of @ref int_enable_mask*/
}LIN2_WakeupModeInitTypeDef;
/** @defgroup LIN2_Exported_Constants
  * @{
  */

#define IS_LIN2_ALL_UNIT(UNIT) 	    ( 	((UNIT) == LIN240) || \
                                        ((UNIT) == LIN241) || \
                                        ((UNIT) == LIN210) || \
										((UNIT) == LIN211) )

#define IS_LIN2_ALL_CHANNEL(CH) 	( 	((CH) == LIN20) || \
										((CH) == LIN21) || \
										((CH) == LIN22) || \
                                        ((CH) == LIN23) || \
                                        ((CH) == LIN24) || \
                                        ((CH) == LIN25) || \
                                        ((CH) == LIN26) || \
                                        ((CH) == LIN27) || \
                                        ((CH) == LIN28) || \
                                        ((CH) == LIN29) )
#define IS_LIN2_ALL_SYS_CLK(CLK)    ( 	((CLK) == 0) || \
                                        ((CLK) == 1) || \
                                        ((CLK) == 2) || \
										((CLK) == 3) )
/**
  * @}
  */

void LIN2_Init(LIN2_InitTypeDef* LIN2_InitStruct);
int8_t LIN2_Master_Process(uint8_t linm,LIN2_Frm_InfoTypeDef *info_p,
    uint8_t resp_len,uint8_t *resp_data);
int8_t RLIN2_Self_Mode_Init(LIN2_SelfModeInitTypeDef *LIN2_InitStruct);
void RLIN2_Self_Mode_Exit(uint8_t linn);

int8_t LIN2_Wakeup_Transmit(LIN2_WakeupModeInitTypeDef *LIN2_InitStruct);
#endif//RH850F1L_RLIN_H