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

/*List of Clock Controller Registers*/
#define CLOCK_CTL_BASE          0xFFF81000

/*Clock oscillator registers address*/
#define MOSC_ENABLE_BASE        (CLOCK_CTL_BASE + 0x100)  //MainOSC enable register
#define MOSC_STAT_OFFSET        0x04            //MainOSC status register
#define MOSC_CTL_OFFSET         0x08            //MainOSC control register
#define MOSC_STAB_TIME_OFFSET   0x0C            //MainOSC stabilization time register
#define MOSC_STOP_MASK_OFFSET   0x18            //MainOSC stop mask register

#define SOSC_ENABLE_BASE        (CLOCK_CTL_BASE + 0x200) //SubOSC enable register
#define SOSC_STAT_OFFSET        0x04            //SubOSC status register
#define SOSC_STAB_TIME_OFFSET   0x0C            //SubOSC stabilization time register

#define ROSC_ENABLE_BASE        CLOCK_CTL_BASE  //HS IntOSC enable register
#define ROSC_STAT_OFFSET        0x04            //HS IntOSC status register
#define ROSC_STOP_MASK_OFFSET   0x18            //HS IntOSC stop mask register

#define PLL_ENABLE_BASE         (CLOCK_CTL_BASE + 0x8000)  //PLL enable register
#define PLL_STAT_OFFSET         0x04            //PLL status register
#define PLL_CTL_OFFSET          0x08            //PLL control register

/*Symbol related to Clock Controller Registers*/
#define MOSCE                   MOSC_ENABLE_BASE
#define MOSCS                   (MOSC_ENABLE_BASE + MOSC_STAT_OFFSET)
#define MOSCC                   (MOSC_ENABLE_BASE + MOSC_CTL_OFFSET)
#define MOSCST                  (MOSC_ENABLE_BASE + MOSC_STAB_TIME_OFFSET)
#define MOSCSTPM                (MOSC_ENABLE_BASE + MOSC_STOP_MASK_OFFSET)

#define SOSCE                   SOSC_ENABLE_BASE
#define SOSCS                   (SOSC_ENABLE_BASE + SOSC_STAT_OFFSET)
#define SOSCST                  (SOSC_ENABLE_BASE + SOSC_STAB_TIME_OFFSET)

#define ROSCE                   ROSC_ENABLE_BASE
#define ROSCS                   (ROSC_ENABLE_BASE + ROSC_STAT_OFFSET)
#define ROSCSTPM                (ROSC_ENABLE_BASE + ROSC_STOP_MASK_OFFSET)

#define PLLE                    PLL_ENABLE_BASE
#define PLLS                    (PLL_ENABLE_BASE + PLL_STAT_OFFSET)
#define PLLC                    (PLL_ENABLE_BASE + PLL_CTL_OFFSET)

/*Clock selector registers address */
#define CTL_OFFSET              0x00
#define ACT_OFFSET              0x08
#define STPM_OFFSET             0x18
/*Symbol related to Always-On-Area Domain*/
#define CKSC_AWD_BASE           (CLOCK_CTL_BASE + 0x1000)//0xFFF82000 AWD base address
#define CKSC_AWDTAD_CTL         (CKSC_AWD_BASE + CTL_OFFSET)
#define CKSC_AWDTAD_ACT         (CKSC_AWD_BASE + ACT_OFFSET)
#define CKSC_AWDTAD_STPM        (CKSC_AWD_BASE + STPM_OFFSET)

#define CKSC_ATAUJS_BASE        (CKSC_AWD_BASE + 0x100)//0xFFF82100
#define CKSC_ATAUJS_CTL         (CKSC_ATAUJS_BASE + CTL_OFFSET)
#define CKSC_ATAUJS_ACT         (CKSC_ATAUJS_BASE + ACT_OFFSET)

#define CKSC_ATAUJD_BASE        (CKSC_AWD_BASE + 0x200)//0xFFF82200
#define CKSC_ATAUJD_CTL         (CKSC_ATAUJD_BASE + CTL_OFFSET )
#define CKSC_ATAUJD_ACT         (CKSC_ATAUJD_BASE + ACT_OFFSET)
#define CKSC_ATAUJD_STPM        (CKSC_ATAUJD_BASE + STPM_OFFSET)

#define CKSC_ARTCAS_BASE        (CKSC_AWD_BASE + 0x300)//0xFFF82300
#define CKSC_ARTCAS_CTL         (CKSC_ARTCAS_BASE + CTL_OFFSET)
#define CKSC_ARTCAS_ACT         (CKSC_ARTCAS_BASE + ACT_OFFSET)

#define CKSC_ARTCAD_BASE        (CKSC_AWD_BASE + 0x400)//0xFFF82400
#define CKSC_ARTCAD_CTL         (CKSC_ARTCAD_BASE + CTL_OFFSET)
#define CKSC_ARTCAD_ACT         (CKSC_ARTCAD_BASE + ACT_OFFSET)
#define CKSC_ARTCAD_STPM        (CKSC_ARTCAD_BASE + STPM_OFFSET)

#define CKSC_AADCAS_BASE        (CKSC_AWD_BASE + 0x500)//0xFFF82500
#define CKSC_AADCAS_CTL         (CKSC_AADCAS_BASE + CTL_OFFSET)
#define CKSC_AADCAS_ACT         (CKSC_AADCAS_BASE + ACT_OFFSET)

#define CKSC_AADCAD_BASE        (CKSC_AWD_BASE + 0x600)//0xFFF82600
#define CKSC_AADCAD_CTL         (CKSC_AADCAD_BASE + CTL_OFFSET)
#define CKSC_AADCAD_ACT         (CKSC_AADCAD_BASE + ACT_OFFSET)
#define CKSC_AADCAD_STPM        (CKSC_AADCAD_BASE + STPM_OFFSET)

#define CKSC_AFOUTS_BASE        (CKSC_AWD_BASE + 0x700)//0xFFF82700
#define CKSC_AFOUTS_CTL         (CKSC_AFOUTS_BASE + CTL_OFFSET)
#define CKSC_AFOUTS_ACT         (CKSC_AFOUTS_BASE + ACT_OFFSET)
#define CKSC_AFOUTS_STPM        (CKSC_AFOUTS_BASE + STPM_OFFSET)

/*Symbol related to Isolated-Area Domain*/
#define CKSC_ISO_BASE           (CLOCK_CTL_BASE + 0x9000)//0xFFF8A000 ISO base address
#define CKSC_CPUCLKS_CTL        (CKSC_ISO_BASE + CTL_OFFSET)
#define CKSC_CPUCLKS_ACT        (CKSC_ISO_BASE + ACT_OFFSET)

#define CKSC_CPUCLKD_BASE       (CKSC_ISO_BASE + 0x100)//0xFFF8A100
#define CKSC_CPUCLKD_CTL        (CKSC_CPUCLKD_BASE + CTL_OFFSET)
#define CKSC_CPUCLKD_ACT        (CKSC_CPUCLKD_BASE + ACT_OFFSET)

#define CKSC_IPERI1S_BASE       (CKSC_ISO_BASE + 0x200)//0xFFF8A200
#define CKSC_IPERI1S_CTL        (CKSC_IPERI1S_BASE + CTL_OFFSET)
#define CKSC_IPERI1S_ACT        (CKSC_IPERI1S_BASE + ACT_OFFSET)

#define CKSC_IPERI2S_BASE       (CKSC_ISO_BASE + 0x300)//0xFFF8A300
#define CKSC_IPERI2S_CTL        (CKSC_IPERI2S_BASE + CTL_OFFSET)
#define CKSC_IPERI2S_ACT        (CKSC_IPERI2S_BASE + ACT_OFFSET)

#define CKSC_ILINS_BASE         (CKSC_ISO_BASE + 0x400)//0xFFF8A400
#define CKSC_ILINS_CTL          (CKSC_ILINS_BASE + CTL_OFFSET)
#define CKSC_ILINS_ACT          (CKSC_ILINS_BASE + ACT_OFFSET)

#define CKSC_IADCAS_BASE        (CKSC_ISO_BASE + 0x500)//0xFFF8A500
#define CKSC_IADCAS_CTL         (CKSC_IADCAS_BASE + CTL_OFFSET)
#define CKSC_IADCAS_ACT         (CKSC_IADCAS_BASE + ACT_OFFSET)

#define CKSC_IADCAD_BASE        (CKSC_ISO_BASE + 0x600)//0xFFF8A600
#define CKSC_IADCAD_CTL         (CKSC_IADCAD_BASE + CTL_OFFSET)
#define CKSC_IADCAD_ACT         (CKSC_IADCAD_BASE + ACT_OFFSET)

#define CKSC_ILIND_BASE         (CKSC_ISO_BASE + 0x800)//0xFFF8A800
#define CKSC_ILIND_CTL          (CKSC_ILIND_BASE + CTL_OFFSET)
#define CKSC_ILIND_ACT          (CKSC_ILIND_BASE + ACT_OFFSET)
#define CKSC_ILIND_STPM         (CKSC_ILIND_BASE + STPM_OFFSET)

#define CKSC_ICANS_BASE         (CKSC_ISO_BASE + 0x900)//0xFFF8A900
#define CKSC_ICANS_CTL          (CKSC_ICANS_BASE + CTL_OFFSET)
#define CKSC_ICANS_ACT          (CKSC_ICANS_BASE + ACT_OFFSET)
#define CKSC_ICANS_STPM         (CKSC_ICANS_BASE + STPM_OFFSET)

#define CKSC_ICANOSCD_BASE      (CKSC_ISO_BASE + 0xA00)//0xFFF8AA00
#define CKSC_ICANOSCD_CTL       (CKSC_ICANOSCD_BASE + CTL_OFFSET)
#define CKSC_ICANOSCD_ACT       (CKSC_ICANOSCD_BASE + ACT_OFFSET)
#define CKSC_ICANOSCD_STPM      (CKSC_ICANOSCD_BASE + STPM_OFFSET)

#define CKSC_ICSIS_BASE         (CKSC_ISO_BASE + 0xB00)//0xFFF8AB00
#define CKSC_ICSIS_CTL          (CKSC_ICSIS_BASE + CTL_OFFSET)
#define CKSC_ICSIS_ACT          (CKSC_ICSIS_BASE + ACT_OFFSET)

typedef enum {
    MOSC_DISABLE,
    MOSC_ENABLE = !MOSC_DISABLE,
}MOSC_OPT_Type;

typedef enum {
    OSC_INACTIVE,
    OSC_ACTIVED = !OSC_INACTIVE,
}MOSC_STATUS_Type,ROSCSTATUS_Type;

typedef enum {
    MOSC_AMP_HIGH,      //00b,20 MHz < fX ≤ 24 MHz
    MOSC_AMP_MID_HIGH,  //01b,16 MHz < fX ≤ 20 MHz
    MOSC_AMP_MID_LOW,   //10b,8 MHz < fX ≤ 16 MHz
    MOSC_AMP_LOW,       //11b,8 MHz
}MOSC_AMP_GAIN_Type;

#endif //RH850F1L_CLK_H
