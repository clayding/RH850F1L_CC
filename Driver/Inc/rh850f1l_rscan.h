/**
  ******************************************************************************
  * @file    rh850f1l_rscan.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    1-February-2018
  * @brief   Header file of RS-CAN module.
  ******************************************************************************
  */
#ifndef RH850F1L_RSCAN_H
#define RH850F1L_RSCAN_H
#include "rh850f1l.h"

/*Clock Supply Setting*/
#define RSCAN_CLK_XINCAN        0 //select the clk_xincan as clock source of the RS-CAN module
#define RSCAN_CLKC              1 //select the clkc as clock source of the RS-CAN module
#define RSCAN_CLK_XINCAN_FRE    8 //8 MHz ≤ clk_xincan ≤ pclk/2  or 4 MHz ≤ clk_xincan ≤ pclk/2
#define RSCAN_CLKC_FRE          12.5 //12.5 MHz ≤ clkc ≤ pclk/2
#define RSCAN_PCLK              ()

#define RSCAN0_BASE             RSCAN0

#define _C0CFG                  C0CFG.UINT32
#define _C0CTR                  C0CTR.UINT32
#define _C0STS                  C0STS.UINT32

#define _GCFG                   GCFG.UINT32
#define _GCTR                   GCTR.UINT32
#define _GSTS                   GSTS.UINT32

#define _GAFLECTR               GAFLECTR.UINT32
#define _GAFLCFG0               GAFLCFG0.UINT8
#define _GAFLCFG1               GAFLCFG1.UINT8
#define _GAFLID0                GAFLID0.UINT32
#define _GAFLM0                 GAFLM0.UINT32

/*RSCAN0CmCFG — Channel Configuration Register (m = 0 to 5) bits mask and offset*/
#define CAN_SJW_OFFSET          24
#define CAN_TSEG2_OFFSET        20
#define CAN_TSEG1_OFFSET        16
#define CAN_BRP_OFFSET          0

#define CAN_SJW_MASK            ((uint32_t)0x03 << CAN_SJW_OFFSET)   //[25,24]
#define CAN_TSEG2_MASK          ((uint32_t)0x07 << CAN_TSEG2_OFFSET) //[22,20]
#define CAN_TSEG1_MASK          ((uint32_t)0x0F << CAN_TSEG1_OFFSET) //[19,16]
#define CAN_BRP_MASK            ((uint32_t)0x3FF)                    //[9:0]

/*RSCAN0CmCTR — Channel Control Register (m = 0 to 5) bits mask*/
#define CAN_CSLPR_OFFSET        2
#define CAN_CHMDC_OFFSET        0
#define CAN_CSLPR_MASK          ((uint32_t)0x01 << 2) //Config Channel Stop Mode
#define CAN_CHMDC_MASK          ((uint32_t)0x03)      //Channel Mode Select Bits

/*RSCAN0CmSTS — Channel Status Register (m = 0 to 5) bits mask Read-only*/
#define CAN_EPSTS_MASK          ((uint32_t)0x01 << 3) //Error Passive Status Flag
#define CAN_CSLPSTS_MASK        ((uint32_t)0x01 << 2) //Channel Stop Status Flag
#define CAN_CHLTSTS_MASK        ((uint32_t)0x01 << 1) //Channel Test Status Flag
#define CAN_CRSTSTS_MASK        ((uint32_t)0x01 << 0) //Channel Reset Status Flag

/*RSCAN0GCFG — Global Configuration Register bits mask*/
#define CAN_ITRCP_OFFSET        16
#define CAN_TSBTCS_OFFSET       13
#define CAN_TSSS_OFFSET         12
#define CAN_TSP_OFFSET          8
#define CAN_DCS_OFFSET          4
#define CAN_MME_OFFSET          3
#define CAN_DRE_OFFSET          2
#define CAN_DCE_OFFSET          1
#define CAN_TPRI_OFFSET         0

#define CAN_ITRCP_MASK          ((uint32_t)0xFFFF << CAN_ITRCP_OFFSET) //Interval Timer Prescaler Set
#define CAN_TSBTCS_MASK         ((uint32_t)0x07 << CAN_TSBTCS_OFFSET)  //Timestamp Clock Source Select
#define CAN_TSSS_MASK           ((uint32_t)0x01 << CAN_TSSS_OFFSET))  //Timestamp Source Select
#define CAN_TSP_MASK            ((uint32_t)0x0F << CAN_TSP_OFFSET)   //Timestamp Clock Source Division
#define CAN_DCS_MASK            ((uint32_t)0x01 << CAN_DCS_OFFSET)   //CAN Clock Source Select
#define CAN_MME_MASK            ((uint32_t)0x01 << CAN_MME_OFFSET)   //Mirror Function Enable
#define CAN_DRE_MASK            ((uint32_t)0x01 << CAN_DRE_OFFSET)  //DLC Replacement Enable
#define CAN_DCE_MASK            ((uint32_t)0x01 << CAN_DCE_OFFSET)  //DLC Check Enable
#define CAN_TPRI_MASK           ((uint32_t)0x01)                    //Transmit Priority Select


/*RSCAN0GCTR — Global Control Register*/
#define CAN_GSLPR_OFFSET        2
#define CAN_GMDC_OFFSET         0
#define CAN_GSLPR_MASK          ((uint32_t)0x01 << CAN_GSLPR_OFFSET) //Config Global Stop Mode
#define CAN_GMDC_MASK           ((uint32_t)0x03)                    //Global Mode Select Bits

/*RSCAN0GSTS — Global Status Register Read-only*/
#define CAN_GRAMINIT_MASK       ((uint32_t)0x01 << 3) //CAN RAM Initialization Status Flag
#define CAN_GSLPSTS_MASK        ((uint32_t)0x01 << 3) //Global Stop Status Flag
#define CAN_GHLTSTS_MASK        ((uint32_t)0x01 << 1) //Global Test Status Flag
#define CAN_GRSTSTS_MASK        ((uint32_t)0x01 << 0) //Global Reset Status Flag

/*RSCAN0GAFLECTR — Receive Rule Entry Control Register*/
#define CAN_AFLDAE_MASK         ((uint32_t)0x01 << 8) //Receive Rule Table Write Enable bit
#define CAN_AFLPN_MASK          ((uint32_t)0x1F)      //Receive Rule Table Page Number Configuration

/*RSCAN0GAFLIDj — Receive Rule ID Register*/
#define CAN_GAFLIDE_OFFSET      31
#define CAN_GAFLRTR_OFFSET      30
#define CAN_GAFLLB_OFFSET       29
#define CAN_GAFLID_OFFSET       0

#define CAN_GAFLIDE_MASK        ((uint32_t)0x01 << 31) //IDE Select
#define CAN_GAFLRTR_MASK        ((uint32_t)0x01 << 30) //RTR Select
#define CAN_GAFLLB_MASK         ((uint32_t)0x01 << 29) //Receive Rule Target Message Select
#define CAN_GAFLID_MASK         ((uint32_t)0x1FFFFFFF) //ID

/*RSCAN0GAFLMj — Receive Rule Mask Register (j = 0 to 15)*/
#define CAN_GAFLIDEM_MASK       CAN_GAFLIDE_MASK //IDE Mask
#define CAN_GAFLRTRM_MASK       CAN_GAFLRTR_MASK //RTR Mask
#define CAN_GAFLIDM_MASK        CAN_GAFLID_MASK //ID Mask

/*RSCAN0GAFLP0j — Receive Rule Pointer 0 Register (j = 0 to 15)*/
#define CAN_GAFLDLC_OFFSET      28
#define CAN_GAFLPTR_OFFSET      16
#define CAN_GAFLRMV_OFFSET      15
#define CAN_GAFLRMDP_OFFSET     8

#define CAN_GAFLDLC_MASK        ((uint32_t)0x0F   << CAN_GAFLDLC_OFFSET) //Receive Rule DLC mask
#define CAN_GAFLPTR_MASK        ((uint32_t)0x0FFF << CAN_GAFLPTR_OFFSET) //Receive Rule Label mask
#define CAN_GAFLRMV_MASK        ((uint32_t)0x01   << CAN_GAFLRMV_OFFSET) //Receive Buffer Enable mask
#define CAN_GAFLRMDP_MASK       ((uint32_t)0x7F   << CAN_GAFLRMDP_OFFSET)//Receive Buffer Number Select mask

/*RSCAN0GAFLP1j — Receive Rule Pointer 1 Register (j = 0 to 15)*/
#define CAN_GAFLFDPH_OFFSET     8
#define CAN_GAFLFDPL_OFFSET     0

#define CAN_GAFLFDPH_MASK       ((uint32_t)0x3FFFF << CAN_GAFLFDPH_OFFSET)
#define CAN_GAFLFDPL_MASK       ((uint32_t)0xFF)



#define REG_ADDR(_CNT_,_BASE_REG_,_OFFSET_B_)                     ((uint32_t*)(&(RSCAN0_BASE.##_BASE_REG_))+ _OFFSET_B_*_CNT_)
#define REG_VAL(_CNT_,_BASE_REG_,,_OFFSET_B_)                      (*((uint32_t*)(&(RSCAN0_BASE.##_BASE_REG_))+ _OFFSET_B_*_CNT_))
/*Set the channel control register*/
#define __RSCAN_SET_CHANNEL_CFG(_CH_,_VALUE_)           (REG_VAL(_CH_,_C0CFG,0x10) = _VALUE_ & 0xFFFFFFFF)

#define __RSCAN_GET_CHANNEL_CFG(_CH_)                   REG_VAL(_CH_,_C0CFG,0x10)

/*Set the channel control register*/
#define __RSCAN_SET_CHANNEL_CTL(_CH_,_MASK_,_VALUE_)    \
                                                        do{ \
                                                            MODIFY_REG(REG_ADDR(_CH_,_C0CTR),_MASK_,_VALUE_);\
                                                        }while(0)
/*Get the channel control register*/
#define __RSCAN_GET_CHANNEL_CTL(_CH_,_MASK_)            (REG_VAL(_CH_,_C0CTR,0x10) & _MASK_)

/*Get the channel state register*/
#define __RSCAN_GET_CHANNEL_STAT(_CH_,_MASK_)           (REG_VAL(_CH_,_C0STS,0x10) & _MASK_)


/*Set the global configuration  register*/
#define __RSCAN_SET_GLOBAL_CFG(_MASK_,_VALUE_,) do{ \
                                                            MODIFY_REG(&RSCAN0_BASE._GCFG,_MASK_,_VALUE_);\
                                                        }while(0)
/*Get the global configuration register*/
#define __RSCAN_GET_GLOBAL_CFG(_MASK_)                  (RSCAN0_BASE._GCFG & _MASK_)

/*Set the global control register*/
#define __RSCAN_SET_GLOBAL_CTL(_MASK_,_VALUE_) do{ \
                                                            MODIFY_REG(&RSCAN0_BASE._GCTR,_MASK_,_VALUE_);\
                                                        }while(0)
/*Get the global control register*/
#define __RSCAN_GET_GLOBAL_CTL(_MASK_)                  (RSCAN0_BASE._GCTR & _MASK_)

#define __RSCAN_GET_GLOBAL_STAT(_MASK_)                 (RSCAN0_BASE._GSTS & _MASK_)


//Enable or disable receive rule table write 0--disbale 1 -- Enable
#define __RSCAN_RECV_TABLE_WRITE_EN(_ENABLE_)           do{ \
                                                            if(_ENBALE_) \
                                                                RSCAN0_BASE._GAFLECTR |= CAN_AFLDAE_MASK; \
                                                            else \
                                                                RSCAN0_BASE._GAFLECTR &= ~CAN_AFLDAE_MASK; \
                                                        }while(0)

#define __RSCAN_RECV_TABLE_WRITE_STAT()                 (RSCAN0_BASE._GAFLECTR & CAN_AFLDAE_MASK)

//Receive Rule Table Page Number Configuration,_NUMBER_ within the range of 00000B(0) to 10111B(23).
#define __RSCAN_RECV_TABLE_PAGE_NO_CFG(_NUMBER_)        MODIFY_REG(&RSCAN0_BASE._GAFLECTR,CAN_AFLPN_MASK,_NUMBER_)

/*Used to set the number(_NUMBER_) of rules to be registered in the channel x
 _INDEX_: 0-3*/
#define __RSCAN_SET_RULE_NUMBER_0(_INDEX_,_NUMBER_)     RSCAN0_BASE._GAFLCFG0[_INDEX_] = _NUMBER_ & 0xFF
/*_INDEX_: 4,5*/
#define __RSCAN_SET_RULE_NUMBER_1(_INDEX_,_NUMBER_)     RSCAN0_BASE._GAFLCFG0[_INDEX_] = _NUMBER_ & 0xFF

/*Set the RSCAN0GAFLIDj — Receive Rule ID Register*/
#define __RSCAN_SET_RULE_ID(_CNT_,_VALUE_)              REG_VAL(_CNT_,RSCAN0_BASE._GAFLID0,0x10) = _VALUE_
/*Get the RSCAN0GAFLIDj — Receive Rule ID Register*/
#define __RSCAN_GET_RULE_ID(_CNT_,_VALUE_)              REG_VAL(_CNT_,RSCAN0_BASE._GAFLID0,0x10)

#define __RSCAN_SET_RULE_MASK(_CNT_,_MASK_,_VALUE_)     MODIFY_REG(REG_ADDR(RSCAN0_BASE._GAFLM0,0x10),CAN_AFLPN_MASK,_VALUE_)

#define __RSCAN_SET_RULE_POINTER(_CNT,_MASK_)

typedef enum{
    RSCAN_OPERATE_MODE,     //Global operating mode
    RSCAN_COMMUNICATION_MODE = RSCAN_OPERATE_MODE, //Channel communication mode
    RSCAN_RESET_MODE,       //Global reset mode or Channel reset mode or
    RSCAN_TEST_MODE,        //Global test mode or Channel test mode
    RSCAN_STOP_MODE = 4,    //Global stop mode or Channel stop mode
}RSCAN_GLOBAL_MODE_Type,RSCAN_CHANNEL_MODE_Type;


typedef struct{
    uint8_t sjw;    //Resynchronization Jump Width Control 1Tq(0b00)--4Tq(0b11)
    uint8_t tseg2;  //Time Segment 2 Control  2Tq(0b01) -- 8Tq(0b111)
    uint8_t tseg1;  //Time Segment 1 Control  4Tq(0b11)  -- 16Tq(0b1111)
    uint16_t brp;   //Prescaler Division Ratio Set 0-1023
}RSCAN_BIT_TIMING_TypeDef;

typedef enum{
    RSCAN_1MHz_SPEED,RSCAN_500KHz_SPEED,RSCAN_250KHz_SPEED,RSCAN_125KHz_SPEED,
}RSCAN_COM_SPEED_Type;

typedef struct{
    uint8_t fcan_src; //set the CAN clock (fCAN) as a clock source of the RS-CAN module
    RSCAN_BIT_TIMING_TypeDef bit_time;//to set the bit timing
    RSCAN_COM_SPEED_Type com_speed;
}RSCAN_COM_SPEED_PARAM_TypeDef;

typedef enum{
    RSCAN_DLC_CHECK_DISABLED,   //0 0 0 0: DLC check is disabled.
    RSCAN_DLC_1_DATA_BYTE,      //0 0 0 1: 1 data byte
    RSCAN_DLC_2_DATA_BYTE,      //0 0 1 0: 2 data bytes
    RSCAN_DLC_3_DATA_BYTE,      //0 0 1 1: 3 data bytes
    RSCAN_DLC_4_DATA_BYTE,      //0 1 0 0: 4 data bytes
    RSCAN_DLC_5_DATA_BYTE,      //0 1 0 1: 5 data bytes
    RSCAN_DLC_6_DATA_BYTE,      //0 1 1 0: 6 data bytes
    RSCAN_DLC_7_DATA_BYTE,      //0 1 1 1: 7 data bytes
    RSCAN_DLC_8_DATA_BYTE,      //1 X X X: 8 data bytes
}RSCAN_DLC_CHECK_Type;

typedef struct{
    RSCAN_DLC_CHECK_Type dlc_t; //Receive Rule DLC disable or 1-8 data bytes
    uint16_t label_t;           //the 12-bit label information.
    bool recv_buf_used;         //TRUE or FLASE
    uint8_t buf_num;            //the receive buffer number to store received message
    uint8_t tr_sel;             //transmit/receive FIFO buffer number k 0-17
    uint8_t r_sel;              //receive FIFO buffer number x 0-7
}RSCAN_RECV_RULE_POINTER_TypeDef;


#endif //RH850F1L_RSCAN_H
