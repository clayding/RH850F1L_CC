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

#define RSCAN0_BASE     RSCAN0

#define _C0CFG          C0CFG.UINT32
#define _C0CTR          C0CTR.UINT32
#define _C0STS          C0STS.UINT32

#define _GCFG           GCFG.UINT32
#define _GCTR           GCTR.UINT32
#define _GSTS           GSTS.UINT32

/*RSCAN0CmCFG — Channel Configuration Register (m = 0 to 5) bits mask and offset*/
#define CAN_SJW_OFFSET        24
#define CAN_TSEG2_OFFSET      20
#define CAN_TSEG1_OFFSET      16
#define CAN_BRP_OFFSET        0

#define CAN_SJW_MASK        ((uint32_t)0x03 << CAN_SJW_OFFSET)   //[25,24]
#define CAN_TSEG2_MASK      ((uint32_t)0x07 << CAN_TSEG2_OFFSET) //[22,20]
#define CAN_TSEG1_MASK      ((uint32_t)0x0F << CAN_TSEG1_OFFSET) //[19,16]
#define CAN_BRP_MASK        ((uint32_t)0x3FF)                    //[9:0]

/*RSCAN0CmCTR — Channel Control Register (m = 0 to 5) bits mask*/
#define CAN_CSLPR_OFFSET    2
#define CAN_CHMDC_OFFSET    0
#define CAN_CSLPR_MASK      ((uint32_t)0x01 << 2) //Config Channel Stop Mode
#define CAN_CHMDC_MASK      ((uint32_t)0x03)      //Channel Mode Select Bits

/*RSCAN0CmSTS — Channel Status Register (m = 0 to 5) bits mask Read-only*/
#define CAN_EPSTS_MASK      ((uint32_t)0x01 << 3) //Error Passive Status Flag
#define CAN_CSLPSTS_MASK    ((uint32_t)0x01 << 2) //Channel Stop Status Flag
#define CAN_CHLTSTS_MASK    ((uint32_t)0x01 << 1) //Channel Test Status Flag
#define CAN_CRSTSTS_MASK    ((uint32_t)0x01 << 0) //Channel Reset Status Flag

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
#define CAN_GSLPR_OFFSET    2
#define CAN_GMDC_OFFSET    0
#define CAN_GSLPR_MASK      ((uint32_t)0x01 << CAN_GSLPR_OFFSET) //Config Global Stop Mode
#define CAN_GMDC_MASK       ((uint32_t)0x03)                    //Global Mode Select Bits

/*RSCAN0GSTS — Global Status Register Read-only*/

#define CAN_GRAMINIT_MASK   ((uint32_t)0x01 << 3) //CAN RAM Initialization Status Flag
#define CAN_GSLPSTS_MASK    ((uint32_t)0x01 << 3) //Global Stop Status Flag
#define CAN_GHLTSTS_MASK    ((uint32_t)0x01 << 1) //Global Test Status Flag
#define CAN_GRSTSTS_MASK    ((uint32_t)0x01 << 0) //Global Reset Status Flag

#define REG32_ADDR(_CH_,_BASE_REG_)                     ((uint32_t*)(&(RSCAN0_BASE.##_BASE_REG_))+ 4*_CH_)
#define REG32_VAL(_CH_,_BASE_REG_)                      (*((uint32_t*)(&(RSCAN0_BASE.##_BASE_REG_))+ 4*_CH_))
/*Set the channel control register*/
#define __RSCAN_SET_CHANNEL_CFG(_CH_,_VALUE_)           (REG32_VAL(_CH_,_C0CFG) = _VALUE_ & 0xFFFFFFFF)

#define __RSCAN_GET_CHANNEL_CFG(_CH_)                   REG32_VAL(_CH_,_C0CFG)

/*Set the channel control register*/
#define __RSCAN_SET_CHANNEL_CTL(_CH_,_MASK_,_VALUE_,_OFFSET_)    \
                                                        do{ \
                                                            MODIFY_REG(REG32_ADDR(_CH_,_C0CTR),_MASK_, \
                                                                _VALUE_ << _OFFSET_);\
                                                        }while(0)
/*Get the channel control register*/
#define __RSCAN_GET_CHANNEL_CTL(_CH_,_MASK_)            (REG32_VAL(_CH_,_C0CTR) & _MASK_)

/*Get the channel state register*/
#define __RSCAN_GET_CHANNEL_STAT(_CH_,_MASK_)           (REG32_VAL(_CH_,_C0STS) & _MASK_)


/*Set the global configuration  register*/
#define __RSCAN_SET_GLOBAL_CFG(_MASK_,_VALUE_,_OFFSET_) do{ \
                                                            MODIFY_REG(&RSCAN0_BASE._GCFG,_MASK_,_VALUE_ << _OFFSET_);\
                                                        }while(0)
/*Get the global configuration register*/
#define __RSCAN_GET_GLOBAL_CFG(_MASK_)                  (RSCAN0_BASE._GCFG & _MASK_)

/*Set the global control register*/
#define __RSCAN_SET_GLOBAL_CTL(_MASK_,_VALUE_,_OFFSET_) do{ \
                                                            MODIFY_REG(&RSCAN0_BASE._GCTR,_MASK_,_VALUE_ << _OFFSET_);\
                                                        }while(0)
/*Get the global control register*/
#define __RSCAN_GET_GLOBAL_CTL(_MASK_)                  (RSCAN0_BASE._GCTR & _MASK_)

#define __RSCAN_GET_GLOBAL_STAT(_MASK_)                 (RSCAN0_BASE._GSTS & _MASK_)


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

#endif //RH850F1L_RSCAN_H
