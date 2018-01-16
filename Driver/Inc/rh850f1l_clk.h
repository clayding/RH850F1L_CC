/**
  ******************************************************************************
  * @file    rh850f1l_clk.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Clock Control module.
  ******************************************************************************
  */
#ifndef RH850F1L_CLK_H
#define RH850F1L_CLK_H

#include "rh850f1l.h"

#define CPUCLK2 40000000//40MHz max

/*Clock Oscillator registers mask or value*/
#define ROSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define ROSCCLK_FREQUENCY   (8*1024*1024) //Hi IntOSC frequency8MHz

#define MOSCENTRG_MASK      ((uint32_t)(0x01))
#define MOSCDISTRG_MASK     ((uint32_t)(0x01 << 1))
#define MOSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define MOSCAMPSEL_MASK     ((uint32_t)(0x03))
#define MOSCCLKST_MASK      ((uint32_t)0x0FFFF)
#define STABLIZATION_TIME   (2*ROSCCLK_FREQUENCY/1000) //when HI OSC actived,about 2ms

#define PLLENTRG_MASK       ((uint32_t)0x01 << 0)
#define PLLDISTRG_MASK      ((uint32_t)0x01 << 1)
#define PLLCLKACT_MASK      ((uint32_t)0x01 << 2)

#define PLLC_OUTBSEL_OFFSET 16
#define PLLC_OUTBSEL_MASK   ((uint32_t)0x01 << PLLC_OUTBSEL_OFFSET) //bit 16
#define PLLC_M_BITOFFSET    11
#define PLLC_M_MASK         ((uint32_t)0x03 << PLLC_M_BITOFFSET) //bit 12,11
#define PLLC_PA_BITOFFSET   8
#define PLLC_PA_MASK        ((uint32_t)0x07 << PLLC_PA_BITOFFSET)  //bit 10,9,8
#define PLLC_N_BITOFFSET    0
#define PLLC_N_MASK         ((uint32_t)0x3F << PLLC_N_BITOFFSET)  //bit 5,4,3,2,1,0
#define PLLC_MASK           (PLLC_OUTBSEL_MASK | PLLC_M_MASK| PLLC_PA_MASK | PLLC_N_MASK)
/*MainOSC 16MHz outsel =0 ,Mr = 2 -- > M Bit[12:11] = 01,pa = 4,Nr = 40 --> N Bit[5:0] = 10 0111*/
#define PLLC_OUTBSEL        0
#define PLLC_MR             2 //16 MHz ≤ fX ≤ 24 MHz
#define PLLC_PAR            4 //60 MHz to 80 MHz
#define PLLC_NR             40

/*Clock Selector registers mask or value*/
#define CPUCLK_SRC_EMCLK    ((uint32_t)0x01) //01B: EMCLK (default)
#define CPUCLK_SRC_MOSC     ((uint32_t)0x02) //10B: MainOSC
#define CPUCLK_SRC_CPLLCLK  ((uint32_t)0x03) //11B: CPLLCLK

#define CPUCLK_CTL_DIVI_1   ((uint32_t)0x01) //001B: CKSC_CPUCLKS_CTL selection /1 (Default)
#define CPUCLK_CTL_DIVI_2   ((uint32_t)0x02) //010B: CKSC_CPUCLKS_CTL selection /2
#define CPUCLK_CTL_DIVI_4   ((uint32_t)0x03) //011B: CKSC_CPUCLKS_CTL selection /4
#define CPUCLK_CTL_DIVI_8   ((uint32_t)0x04) //100B: CKSC_CPUCLKS_CTL selection /8

#define IPERI1_SRC_CPUCLK2  ((uint32_t)0x01) //01B: CPUCLK2 (default)
#define IPERI1_SRC_PPLLCLK  ((uint32_t)0x02) //10B: PPLLCLK

#define IPERI2_SRC_CPUCLK2  ((uint32_t)0x01) //01B: CPUCLK2 (default)
#define IPERI2_SRC_PPLLCLK2 ((uint32_t)0x02) //10B: PPLLCLK2

#define CPUCLKS_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define CPUCLKS_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask
#define CPUCLKD_CTL_MASK    ((uint32_t)0x07) //CKSC_CPUCLKD_CTL Bit Mask
#define CPUCLKD_ACT_MASK    ((uint32_t)0x07) //CKSC_CPUCLKD_ACT Bit Mask
#define IPERI1S_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define IPERI1S_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask
#define IPERI2S_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define IPERI2S_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask

#define FOUT_DIV_MASK       ((uint32_t)0x3F) //FOUTDIV Mask
#define FOUTSYNC_MASK       ((uint32_t)0x01) //FOUTSTAT FOUTSYNC Mask
#define FOUTCLKACT_MASK     ((uint32_t)0x01 << 1) //FOUTSTAT FOUTCLKACT Mask

#define AFOUTS_CTL_MASK     ((uint32_t)0x07) //C_AWO_FOUT Source Clock Selection Register Mask
#define AFOUTS_ACT_MASK     ((uint32_t)0x07) //C_AWO_FOUT Source Clock Active Register Mas

#define AWDTAD_CTL_MASK      ((uint32_t)0x03)
#define AWDTAD_ACT_MASK      ((uint32_t)0x03)

typedef enum {
    OSC_DISABLE,
    OSC_ENABLE = !OSC_DISABLE,
}OSC_OPT_Type;

typedef enum {
    OSC_INACTIVE,
    OSC_ACTIVED = !OSC_INACTIVE,
}OSC_STATUS_Type;

typedef enum {
    MOSC_AMP_HIGH,      //00b,20 MHz < fX ≤ 24 MHz
    MOSC_AMP_MID_HIGH,  //01b,16 MHz < fX ≤ 20 MHz
    MOSC_AMP_MID_LOW,   //10b,8 MHz < fX ≤ 16 MHz
    MOSC_AMP_LOW,       //11b,8 MHz
}MOSC_AMP_GAIN_Type;

typedef enum {
    M_OSC_TYPE,//Main OSC
    R_OSC_TYPE,//HI Int OSC
    PLL_TYPE,//PLL
}X_OSC_Type;

typedef enum { //Domain Clock
    AWDTA,ATAUJ,ARTCA,AADCA,AFOUT,//AWO_Domain
    CPUCLK,IPERI1,IPERI2,ILIN,IADCA,ICAN,ICANOSC,ICSI,//ISO Domain
    DOMAIN_CLK_TYPE_MAX,
}DOMAIN_CLK_Type;

typedef enum { //return after Setting CLock Domain
    SET_SRC_CLK_FAIL,
    SET_CLK_DIVIDER_FAIL = SET_SRC_CLK_FAIL,
    SET_CLK_DOMAIN_SUCCESS,
    SET_OTHER_FAIL,
}SET_CLK_DOMAIN_RET_Type;

typedef struct {
    uint32_t src_clk_ctl_val;
    uint32_t clk_divider_val;
}SET_CLK_DOMAIN_Struct;

typedef enum {
    AFOUT_SRC_DISABLED,//Disabled (default)
    AFOUT_SRC_MOSC, //001B: MainOSC
    AFOUT_SRC_RH,   //010B: HS IntOSC
    AFOUT_SRC_LH,   //011B: LS IntOSC
    AFOUT_SRC_SOSC, //100B: SubOSC*2
    AFOUT_SRC_CPLLCLK2, //101B: CPLLCLK2
    AFOUT_SRC_PPLLCLK4, //110B: PPLLCLK4
}AFOUT_SRC_CLK_Type;

typedef enum{
    AWDTA_LSOSC_128 = 1,//LS IntOSC / 128 (default)
    AWDTA_LSOSC_1,// LS IntOSC / 1
}AWDTA_DIV_SEL_Type;

void Clock_MOSC_Config(OSC_OPT_Type opt);
OSC_STATUS_Type Clock_OSC_Get_Status(X_OSC_Type otp);
void Clock_PLL_Config(OSC_OPT_Type opt);

#endif //RH850F1L_CLK_H
