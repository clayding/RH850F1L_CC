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

#define _RLIN30         RLN30
#define _RLIN31         RLN31
#define _RLIN32         RLN32
#define _RLIN33         RLN33
#define _RLIN34         RLN34
#define _RLIN35         RLN35

/*RLN3nLWBR — LIN Wake-Up Baud Rate Select Register*/
#define LIN3_NSPB_OFFSET     4
#define LIN3_LPRS_OFFSET     1
#define LIN3_NSPB_MASK       0xf0
#define LIN3_LPRS_MASK     0x0e

/*RLN3nLMD — UART Mode Register*/
#define LIN3_LRDNFS_OFFSET   5
#define LIN3_LMD_OFFSET      0

#define LIN3_LRDNFS_MASK     0x20
#define LIN3_LMD_MASK        0x03

/*RLN3nLBFC — UART Configuration Register*/
#define LIN3_UTPS_OFFSET     6
#define LIN3_URPS_OFFSET     5
#define LIN3_UPS_OFFSET      3
#define LIN3_USBLS_OFFSET    2
#define LIN3_UBOS_OFFSET     1
#define LIN3_UBLS_OFFSET     0

#define LIN3_UTPS_MASK       ((uint8_t)(0x01 << LIN3_UTPS_OFFSET))
#define LIN3_URPS_MASK       ((uint8_t)(0x01 << LIN3_URPS_OFFSET))
#define LIN3_UPS_MASK        ((uint8_t)(0x03 << LIN3_UPS_OFFSET))
#define LIN3_USBLS_MASK      ((uint8_t)(0x01 << LIN3_USBLS_OFFSET))
#define LIN3_UBOS_MASK       ((uint8_t)(0x01 << LIN3_UBOS_OFFSET))
#define LIN3_UBLS_MASK       ((uint8_t)0x01)

/*LN3nLSC — UART Space Configuration Register*/
#define LIN3_IBS_OFFSET      4
#define LIN3_IBS_MASK        ((uint8_t)(0x03 << LIN3_IBS_OFFSET))

/*RLN3nLEDE —UART Error Detection Enable Register*/
#define LIN3_FERE_OFFSET     3
#define LIN3_OERE_OFFSET     2
#define LIN3_FERE_MASK       ((uint8_t)(0x01 << LIN3_FERE_OFFSET))
#define LIN3_OERE_MASK       ((uint8_t)(0x01 << LIN3_OERE_OFFSET))
#define LIN3_BERE_MASK       ((uint8_t)0x01)

/*RLN3nLCUC — UART Control Register*/
#define LIN3_OM0_MASK        0x01

/*RLN3nLTRC — UART Transmission Control Register*/
#define LIN3_RTS_OFFSET      1
#define LIN3_RTS_MASK        ((uint8_t)(0x01 << LIN3_RTS_OFFSET))


/*RLN3nLMST — UART Mode Status Register read-only register*/
#define LIN3_OMM0_MASK      0x01

/*RLN3nLST — UART Status Register*/
#define LIN3_URS_OFFSET      5
#define LIN3_UTS_OFFSET      4
#define LIN3_ERR_OFFSET      3
#define LIN3_FTC_OFFSET      0

#define LIN3_URS_MASK        ((uint8_t)(0x01 << LIN3_URS_OFFSET))  //Reception Status Flag
#define LIN3_UTS_MASK        ((uint8_t)(0x01 << LIN3_UTS_OFFSET))  //Transmission Status Flag
#define LIN3_ERR_MASK        ((uint8_t)(0x01 << LIN3_ERR_OFFSET))  //Error Detection Flag
#define LIN3_FTC_MASK        ((uint8_t)0x01)                      //Successful UART Buffer Transmission Flag

/*RLN3nLEST — UART Error Status Register*/
#define LIN3_UPER_OFFSET    6
#define LIN3_IDMT_OFFSET    5
#define LIN3_EXBT_OFFSET    4
#define LIN3_FER_OFFSET     3
#define LIN3_OER_OFFSET     2

#define LIN3_UPER_MASK      ((uint8_t)(0x01 << LIN3_UPER_OFFSET)) //Parity Error Flag
#define LIN3_IDMT_MASK      ((uint8_t)(0x01 << LIN3_IDMT_OFFSET)) //ID Match Flag
#define LIN3_EXBT_MASK      ((uint8_t)(0x01 << LIN3_EXBT_OFFSET)) //Expansion Bit Detection Flag
#define LIN3_FER_MASK       ((uint8_t)(0x01 << LIN3_FER_OFFSET))  //Framing Error Flag
#define LIN3_OER_MASK       ((uint8_t)(0x01 << LIN3_OER_OFFSET))  //Overrun Error Flag
#define LIN3_BER_MASK       ((uint8_t)0x01)                       //Bit Error Flag

/*RLN3nLDFC — UART Data Field Configuration Register*/
#define LIN3_UTSW_OFFSET    5
#define LIN3_MDL_OFFSET     0

#define LIN3_UTSW_MASK      ((uint8_t)(0x01 << LIN3_UTSW_OFFSET))
#define LIN3_MDL_MASK       ((uint8_t)0x01)

/*RLN3nLUOER — UART Operation Enable Register*/
#define LIN3_UROE_OFFSET    1
#define LIN3_UTOE_OFFSET    0

#define LIN3_UROE_MASK      ((uint8_t)(0x01 << LIN3_UROE_OFFSET)) //Reception Enable
#define LIN3_UTOE_MASK      ((uint8_t)0x01)                       //Transmission Enable

/*RLN3nLUOR1 — UART Option Register 1*/
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


/*RLN3nLWBR — LIN Wake-Up Baud Rate Select Register*/
#define __RLIN3_SELECT_WAKEUP_BAUDRATE(_N_,_MASK_,_VALUE_)    MODIFY_REG(&LIN3N_VAL(_N_).LWBR,_MASK_,_VALUE_)
#define __RLIN3_GET_WAKEUP_BAUDRATE(_N_,_MASK_)               (LIN3N_VAL(_N_).LWBR & _MASK_)

/*RLN3nLBRP01 — UART Baud Rate Prescaler 01 Register*/
#define __RLIN3_SET_BAUDRATE_PRE01(_N_,_VALUE_)             (LIN3N_VAL(_N_).LBRP01.UINT16 = _VALUE_ & 0xFFFF)
#define __RLIN3_GET_BAUDRATE_PRE01(_N_)                     (LIN3N_VAL(_N_).LBRP01.UINT16 & 0xFFFF)

/*RLN3nLMD — UART Mode Register*/
#define __RLIN3_SET_UART_MODE(_N_,_MASK_,_VALUE_)           MODIFY_REG(&LIN3N_VAL(_N_).LMD,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_MODE(_N_,_MASK_)                   (LIN3N_VAL(_N_).LMD & _MASK_)

/*RLN3nLBFC — UART Configuration Register*/
#define __RLIN3_SET_UART_CONFIG(_N_,_MASK_,_VALUE_)           MODIFY_REG(&LIN3N_VAL(_N_).LBFC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_CONFIG(_N_,_MASK_)                   (LIN3N_VAL(_N_).LBFC & _MASK_)

/*LN3nLSC — UART Space Configuration Register*/
#define __RLIN3_SET_UART_SPACE(_N_,_MASK_,_VALUE_)           MODIFY_REG(&LIN3N_VAL(_N_).LSC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_SPACE(_N_,_MASK_)                   (LIN3N_VAL(_N_).LSC & _MASK_)

/*RLN3nLEDE —UART Error Detection Enable Register*/
#define __RLIN3_ENABLE_ERR_DETECT(_N_,_MASK_,_VALUE_)        MODIFY_REG(&LIN3N_VAL(_N_).LEDE,_MASK_,_VALUE_)
#define __RLIN3_GET_ERR_DETECT(_N_,_MASK_)                   (LIN3N_VAL(_N_).LEDE & _MASK_)

/*RLN3nLCUC — UART Control Register*/
#define __RLIN3_SET_UART_CTL(_N_,_MASK_,_VALUE_)            MODIFY_REG(&LIN3N_VAL(_N_).LCUC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_CTL(_N_,_MASK_)                    (LIN3N_VAL(_N_).LCUC & _MASK_)

/*RLN3nLTRC — UART Transmission Control Register*/
#define __RLIN3_SET_UART_TX_CTL(_N_,_MASK_,_VALUE_)         MODIFY_REG(&LIN3N_VAL(_N_).LTRC,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_TX_CTL(_N_,_MASK_)                 (LIN3N_VAL(_N_).LTRC & _MASK_)

/*RLN3nLMST — UART Mode Status Register read-only register*/
#define __RLIN3_GET_UART_MODE_STAT(_N_,_MASK_)              (LIN3N_VAL(_N_).LMST & _MASK_)

/*RLN3nLST — UART Status Register*/
#define __RLIN3_SET_UART_STAT(_N_,_MASK_,_VALUE_)           MODIFY_REG(&LIN3N_VAL(_N_).LST,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_STAT(_N_,_MASK_)                   (LIN3N_VAL(_N_).LST & _MASK_)

/*RLN3nLEST — UART Error Status Register*/
#define __RLIN3_SET_UART_ERR_STAT(_N_,_MASK_,_VALUE_)       MODIFY_REG(&LIN3N_VAL(_N_).LEST,_MASK_,_VALUE_)
#define __RLIN3_GET_UART_ERR_STAT(_N_,_MASK_)               (LIN3N_VAL(_N_).LEST & _MASK_)

/*RLN3nLDFC — UART Data Field Configuration Register*/
#define __RLIN3_SET_DATA_FIELD_CONFIG(_N_,_MASK_,_VALUE_)   MODIFY_REG(&LIN3N_VAL(_N_).LDFC,_MASK_,_VALUE_)
#define __RLIN3_GET_DATA_FIELD_CONFIG(_N_,_MASK_)           (LIN3N_VAL(_N_).LDFC & _MASK_)

/*RLN3nLIDB — UART ID Buffer Register*/
#define __RLIN3_SET_ID_BUF(_N_,_VALUE_)                     (LIN3N_VAL(_N_).LIDB = _VALUE_ & 0xFF)
#define __RLIN3_GET_ID_BUF(_N_)                             (LIN3N_VAL(_N_).LIDB & 0xFF)

/*RLN3nLUDB0 — UART Data Buffer 0 Register*/
#define __RLIN3_WRITE_DATA_BUF0(_N_,_VALUE_)                (LIN3N_VAL(_N_).LUDB0 = _VALUE_ & 0xFF)
#define __RLIN3_READ_DATA_BUF0(_N_)                         (LIN3N_VAL(_N_).LUDB0 & 0xFF)

/*LN3nLDBRb — UART Data Buffer b Register (b = 1 to 8)*/
#define __RLIN3_WRITE_DATA_BUF(_N_,_B_,_VALUE_)             (*(((uint8_t*)&LIN3N_VAL(_N_).LDBR0) + _B_) = _VALUE_ & 0xFF)
#define __RLIN3_READ_DATA_BUF(_N_,_B_)                      (*(((uint8_t*)&LIN3N_VAL(_N_).LDBR0) + _B_) & 0xFF)

/*RLN3nLUOER — UART Operation Enable Register*/
#define __RLIN3_ENABEL_OPERATION(_N_,_MASK_,_VALUE_)        MODIFY_REG(&LIN3N_VAL(_N_).LUOER,_MASK_,_VALUE_)
#define __RLIN3_GET_OPERATION_STAT(_N_,_MASK_)              (LIN3N_VAL(_N_).LUOER & _MASK_)

/*RLN3nLUOR1 — UART Option Register 1*/
#define __RLIN3_SET_OPTION_REG(_N_,_MASK_,_VALUE_)          MODIFY_REG(&LIN3N_VAL(_N_).LUOR1,_MASK_,_VALUE_)
#define __RLIN3_GET_OPTION_REG(_N_,_MASK_)                  (LIN3N_VAL(_N_).LUOR1 & _MASK_)

/*RLN3nLUTDR — UART Transmission Data Register*/
#define __RLIN3_WRITE_TX_DATA(_N_,_VALUE_)                  (LIN3N_VAL(_N_).LUTDR.UINT16 = _VALUE_ & 0x1FF)
#define __RLIN3_READ_TX_DATA(_N_)                           (LIN3N_VAL(_N_).LUTDR.UINT16 & 0x1FF)

/*RLN3nLURDR — UART Reception Data Register read-only register */
#define __RLIN3_READ_RX_DATA(_N_)                           (LIN3N_VAL(_N_).LURDR.UINT16 & 0x1FF)

/*RLN3nLUWTDR — UART Wait Transmission Data Register*/
#define __RLIN3_WRITE_TXWAIT_DATA(_N_,_VALUE_)              (LIN3N_VAL(_N_).LUWTDR.UINT16 = _VALUE_ & 0x1FF)
#define __RLIN3_READ_TXWAIT_DATA(_N_)                       (LIN3N_VAL(_N_).LUWTDR.UINT16 & 0x1FF)


#define UART_BAUDRATE_SAMPLE_CNT_16_  0
#define UART_BAUDRATE_SAMPLE_CNT_6    5
#define UART_BAUDRATE_SAMPLE_CNT_7    6
#define UART_BAUDRATE_SAMPLE_CNT_8    7
#define UART_BAUDRATE_SAMPLE_CNT_9    8
#define UART_BAUDRATE_SAMPLE_CNT_10   9
#define UART_BAUDRATE_SAMPLE_CNT_11   10
#define UART_BAUDRATE_SAMPLE_CNT_12   11
#define UART_BAUDRATE_SAMPLE_CNT_13   12
#define UART_BAUDRATE_SAMPLE_CNT_14   13
#define UART_BAUDRATE_SAMPLE_CNT_15   14
#define UART_BAUDRATE_SAMPLE_CNT_16   15

#define UART_PRESCALER_CLK_DIV_1      0
#define UART_PRESCALER_CLK_DIV_2      1
#define UART_PRESCALER_CLK_DIV_4      2
#define UART_PRESCALER_CLK_DIV_8      3
#define UART_PRESCALER_CLK_DIV_16     4
#define UART_PRESCALER_CLK_DIV_32     5
#define UART_PRESCALER_CLK_DIV_64     6
#define UART_PRESCALER_CLK_DIV_128    7



typedef struct{
    uint8_t bit_sample_cnt; //Bit Sampling Count Select
    uint8_t prescaler_clk;  //Prescaler Clock Select
    uint16_t br_prescaler;  /*<the baud rate prescaler divides the frequency of the
                               clock that is selected by the LPRS bits (prescaler clock select bits)
                               in the RLN3nLWBR register by L + 1.>*/
}UART_BaudrateTypedef;

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

#endif//RH850F1L_RLIN_H
