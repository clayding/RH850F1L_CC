/**
  ******************************************************************************
  * @file    rh850f1l_wp.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Write-Protected Registers module.
  ******************************************************************************
  */
#ifndef RH850F1L_WP_H
#define RH850F1L_WP_H

#include "rh850f1l.h"

/*write-protection control registers address*/

/*Control protection clusters*/
#define PROTCMD0        0xFFF80000
#define PROTS0          0xFFF80004

#define PROTCMD1        0xFFF88000
#define PROTS1          0xFFF88004

/*Clock monitor control and test protection cluster*/
#define CLMA0PCMD       0xFFF8C010
#define CLMA1PCMD       0xFFF8D010
#define CLMA2PCMD       0xFFF8E010
#define CLMA0PS         0xFFF8C014
#define CLMA1PS         0xFFF8D014
#define CLMA2PS         0xFFF8E014
#define PROTCMDCLMA     0xFFF8C200
#define PROTSCLMA       0xFFF8C204

/**********Protection command registers*********/
/*Port protection cluster 0 */
#define JPPCMD0         0xFFC204C0

#define PPCMD_BASE      0xFFC14C00
#define PPCMD0          (PPCMD_BASE + 0x00)
#define PPCMD1          (PPCMD_BASE + 0x04)
#define PPCMD2          (PPCMD_BASE + 0x08)
#define PPCMD8          (PPCMD_BASE + 0x20)
/*Port protection cluster 1 */
#define PPCMD9          (PPCMD_BASE + 0x24)
#define PPCMD10         (PPCMD_BASE + 0x28)
#define PPCMD11         (PPCMD_BASE + 0x2C)
#define PPCMD12         (PPCMD_BASE + 0x30)
#define PPCMD18         (PPCMD_BASE + 0x48)
#define PPCMD20         (PPCMD_BASE + 0x50)

/*********Protection status registers**********/
/*Port protection cluster 0 */
#define JPPROTS0        0xFFC204B0

#define PPROTS_BASE     0xFFC14B00
#define PPROTS0         (PPROTS_BASE + 0x00)
#define PPROTS1         (PPROTS_BASE + 0x04)
#define PPROTS2         (PPROTS_BASE + 0x08)
#define PPROTS8         (PPROTS_BASE + 0x20)
/*Port protection cluster 1 */
#define PPROTS9         (PPROTS_BASE + 0x24)
#define PPROTS10        (PPROTS_BASE + 0x28)
#define PPROTS11        (PPROTS_BASE + 0x2C)
#define PPROTS12        (PPROTS_BASE + 0x30)
#define PPROTS18        (PPROTS_BASE + 0x48)
#define PPROTS20        (PPROTS_BASE + 0x50)

/*Core Voltage Monitor protection cluster*/
#define PROTCMDCVM      0xFFF50100
#define PROTSCVM        0xFFF50104

/*Self-programming protection cluster*/
#define FLMDPCMD        0xFFA00004
#define FLMDPS          0xFFA00008

typedef struct{
    uint32_t dst_protect_reg; //he protected register
    uint32_t dst_protect_cmd_reg;//the protection command register
    uint32_t dst_protect_stat_reg;//he protection status register
}WP_Opt_Reg ;

/*@brief: Excute writing Procedure to the specific Write-Protected Register*/
ErrorStatus  Write_Protected_Process(WP_Opt_Reg dst_reg,uint32_t dst_val);

#endif //RH850F1L_WP_H
