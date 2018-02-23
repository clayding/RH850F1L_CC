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

#define MAX_RULE_NUM_PER_CHANNEL    128//
/*Clock Supply Setting*/
#define RSCAN_CLK_XINCAN        1 //select the clk_xincan as clock source of the RS-CAN module
#define RSCAN_CLKC              !RSCAN_CLK_XINCAN //select the clkc as clock source of the RS-CAN module
#define RSCAN_CLK_XINCAN_FRE    8 //8 MHz ≤ clk_xincan ≤ pclk/2  or 4 MHz ≤ clk_xincan ≤ pclk/2
#define RSCAN_CLKC_FRE          12.5 //12.5 MHz ≤ clkc ≤ pclk/2
#define RSCAN_PCLK              ()

#define RSCAN_RECV_IDE_STD      0 //IDE Select0: Standard ID
#define RSCAN_RECV_IDE_EXT      1 //1: Extended ID

#define RSCAN_RECV_DATA_FRM     0 // Data frame
#define RSCAN_RECV_REMOTE_FRM   1 //Remote Frame

#define RSCAN_RECV_FROM_OTHER   0 //When a message transmitted from another CAN node is received
#define RSCAN_RECV_FROM_OWN     1 //When the own transmitted message is received


#define RSCAN0_BASE             RSCAN0

#define _C0CFG                  C0CFG.UINT32
#define _C0CTR                  C0CTR.UINT32
#define _C0STS                  C0STS.UINT32
#define _C0ERFL                 C0ERFL.UINT32

#define _GCFG                   GCFG.UINT32
#define _GCTR                   GCTR.UINT32
#define _GSTS                   GSTS.UINT32
#define _GERFL                  GERFL.UINT32

#define _GAFLECTR               GAFLECTR.UINT32
#define _GAFLCFG0               GAFLCFG0.UINT8
#define _GAFLCFG1               GAFLCFG1.UINT8
#define _GAFLID0                GAFLID0.UINT32
#define _GAFLM0                 GAFLM0.UINT32
#define _GAFLP0                 GAFLP00.UINT32
#define _GAFLP1                 GAFLP10.UINT32

#define _RMNB                   RMNB.UINT32
#define _RFCC0                  RFCC0.UINT32
#define _CFCC0                  CFCC0.UINT32
#define _TXQCC0                 TXQCC0.UINT32
#define _TMIEC0                 TMIEC0.UINT32

#define _TMSTS0                 TMSTS0
#define _TMID0                  TMID0.UINT32
#define _TMPTR0                 TMPTR0.UINT32
#define _TMDF00                 TMDF00.UINT32
#define _TMDF10                 TMDF10.UINT32
#define _TMC0                   TMC0

#define _RFSTS0                 RFSTS0.UINT32
#define _RFID0                  RFID0.UINT32
#define _RFPTR0                 RFPTR0.UINT32
#define _RFDF00                 RFDF00.UINT32
#define _RFDF10                 RFDF10.UINT32
#define _RFPCTR0                RFPCTR0.UINT32

#define _CFSTS0                 CFSTS0.UINT32
#define _CFID0                  CFID0.UINT32
#define _CFPTR0                 CFPTR0.UINT32
#define _CFDF00                 CFDF00.UINT32
#define _CFDF10                 CFDF10.UINT32
#define _CFPCTR0                CFPCTR0.UINT32

#define _TXQSTS0                TXQSTS0.UINT32
#define _TXQPCTR0               TXQPCTR0.UINT32

#define _RMND0                  RMND0.UINT32
#define _RMID0                  RMID0.UINT32
#define _RMPTR0                 RMPTR0.UINT32
#define _RMDF00                 RMDF00.UINT32
#define _RMDF10                 RMDF10.UINT32

#define _GTSTCFG                GTSTCFG.UINT32
#define _GTSTCTR                GTSTCTR.UINT32
#define _GLOCKK                 GLOCKK.UINT32
#define _RPGACC0                RPGACC0.UINT32
/*******************************************************************************/
/*RSCAN0CmCFG — Channel Configuration Register (m = 0 to 5) bits mask and offset*/
#define CAN_SJW_OFFSET          24
#define CAN_TSEG2_OFFSET        20
#define CAN_TSEG1_OFFSET        16
#define CAN_BRP_OFFSET          0

#define CAN_SJW_MASK            ((uint32_t)0x03 << CAN_SJW_OFFSET)   //Resynchronization Jump Width Control [25:24]
#define CAN_TSEG2_MASK          ((uint32_t)0x07 << CAN_TSEG2_OFFSET) //Time Segment 2 Control [22:20]
#define CAN_TSEG1_MASK          ((uint32_t)0x0F << CAN_TSEG1_OFFSET) //Time Segment 1 Control [19:16]
#define CAN_BRP_MASK            ((uint32_t)0x3FF)                    //Prescaler Division Ratio Set [9:0]

/*RSCAN0CmCTR — Channel Control Register (m = 0 to 5) bits mask*/
#define CAN_CTMS_OFFSET         25
#define CAN_CTME_OFFSET         24
#define CAN_ERRD_OFFSET         23
#define CAN_BOM_OFFSET          21
#define CAN_TAIE_OFFSET         16
#define CAN_ALIE_OFFSET         15
#define CAN_BLIE_OFFSET         14
#define CAN_OLIE_OFFSET         13
#define CAN_BORIE_OFFSET        12
#define CAN_BOEIE_OFFSET        11
#define CAN_EPIE_OFFSET         10
#define CAN_EWIE_OFFSET         9
#define CAN_BEIE_OFFSET         8
#define CAN_RTBO_OFFSET         3
#define CAN_CSLPR_OFFSET        2
#define CAN_CHMDC_OFFSET        0

#define CAN_CTMS_MASK           ((uint32_t)0x03 << CAN_CTMS_OFFSET) //Communication Test Mode Select [26:25]
#define CAN_CTME_MASK           ((uint32_t)0x01 << CAN_CTME_OFFSET) //Communication Test Mode Enable
#define CAN_ERRD_MASK           ((uint32_t)0x01 << CAN_ERRD_OFFSET) //Error Display Mode Select
#define CAN_BOM_MASK            ((uint32_t)0x03 << CAN_BOM_OFFSET)  //Bus-off Recovery Mode Select [22:21]
#define CAN_TAIE_MASK           ((uint32_t)0x01 << CAN_TAIE_OFFSET) //Transmit Abort Interrupt Enable
#define CAN_ALIE_MASK           ((uint32_t)0x01 << CAN_ALIE_OFFSET) //Arbitration Lost Interrupt Enable
#define CAN_BLIE_MASK           ((uint32_t)0x01 << CAN_BLIE_OFFSET) //Bus Lock Interrupt Enable
#define CAN_OLIE_MASK           ((uint32_t)0x01 << CAN_OLIE_OFFSET) //Overload Frame Transmit Interrupt Enable
#define CAN_BORIE_MASK          ((uint32_t)0x01 << CAN_BORIE_OFFSET) //Bus-off Recovery Interrupt Enable
#define CAN_BOEIE_MASK          ((uint32_t)0x01 << CAN_BOEIE_OFFSET) //Bus-off Entry Interrupt Enable
#define CAN_EPIE_MASK           ((uint32_t)0x01 << CAN_EPIE_OFFSET) //Error Passive Interrupt Enable
#define CAN_EWIE_MASK           ((uint32_t)0x01 << CAN_EWIE_OFFSET) //Error Warning Interrupt Enable
#define CAN_BEIE_MASK           ((uint32_t)0x01 << CAN_BEIE_OFFSET) //Bus Error Interrupt Enable
#define CAN_RTBO_MASK           ((uint32_t)0x01 << CAN_RTBO_OFFSET) //Forcible Recovery from Bus-off
#define CAN_CSLPR_MASK          ((uint32_t)0x01 << CAN_CSLPR_OFFSET)//Config Channel Stop Mode
#define CAN_CHMDC_MASK          ((uint32_t)0x03)      //Channel Mode Select Bits [1:0]


/*RSCAN0CmSTS — Channel Status Register (m = 0 to 5) bits mask Read-only*/
#define CAN_EPSTS_MASK          ((uint32_t)0x01 << 3) //Error Passive Status Flag
#define CAN_CSLPSTS_MASK        ((uint32_t)0x01 << 2) //Channel Stop Status Flag
#define CAN_CHLTSTS_MASK        ((uint32_t)0x01 << 1) //Channel Test Status Flag
#define CAN_CRSTSTS_MASK        ((uint32_t)0x01 << 0) //Channel Reset Status Flag

/*RSCAN0CmERFL — Channel Error Flag Register (m = 0 to 5)*/

#define CAN_CRCREG_OFFSET       16 //CRC Calculation Data
#define CAN_ADERR_OFFSET        14
#define CAN_B0ERR_OFFSET        13
#define CAN_B1ERR_OFFSET        12
#define CAN_CERR_OFFSET         11
#define CAN_AERR_OFFSET         10
#define CAN_FERR_OFFSET         9
#define CAN_SERR_OFFSET         8
#define CAN_ALF_OFFSET          7
#define CAN_BLF_OFFSET          6
#define CAN_OVLF_OFFSET         5
#define CAN_BORF_OFFSET         4
#define CAN_BOEF_OFFSET         3
#define CAN_EPF_OFFSET          2
#define CAN_EWF_OFFSET          1
#define CAN_BEF_OFFSET          0

#define CAN_CRCREG_MASK         ((uint32_t)0x7FFF << 16) //CRC Calculation Data
#define CAN_ADERR_MASK          ((uint32_t)0x01 << 14)
#define CAN_B0ERR_MASK          ((uint32_t)0x01 << 13)
#define CAN_B1ERR_MASK          ((uint32_t)0x01 << 12)
#define CAN_CERR_MASK           ((uint32_t)0x01 << 11)
#define CAN_AERR_MASK           ((uint32_t)0x01 << 10)
#define CAN_FERR_MASK           ((uint32_t)0x01 << 9)
#define CAN_SERR_MASK           ((uint32_t)0x01 << 8)
#define CAN_ALF_MASK            ((uint32_t)0x01 << 7)
#define CAN_BLF_MASK            ((uint32_t)0x01 << 6)
#define CAN_OVLF_MASK           ((uint32_t)0x01 << 5)
#define CAN_BORF_MASK           ((uint32_t)0x01 << 4)
#define CAN_BOEF_MASK           ((uint32_t)0x01 << 3)
#define CAN_EPF_MASK            ((uint32_t)0x01 << 2)
#define CAN_EWF_MASK            ((uint32_t)0x01 << 1)
#define CAN_BEF_MASK            ((uint32_t)0x01)

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

#define CAN_GAFLIDE_MASK        ((uint32_t)0x01 << CAN_GAFLIDE_OFFSET) //IDE Select
#define CAN_GAFLRTR_MASK        ((uint32_t)0x01 << CAN_GAFLRTR_OFFSET) //RTR Select
#define CAN_GAFLLB_MASK         ((uint32_t)0x01 << CAN_GAFLLB_OFFSET) //Receive Rule Target Message Select
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
#define CAN_GAFLPTR_MASK        ((uint32_t)0xFFF  << CAN_GAFLPTR_OFFSET) //Receive Rule Label mask
#define CAN_GAFLRMV_MASK        ((uint32_t)0x01   << CAN_GAFLRMV_OFFSET) //Receive Buffer Enable mask
#define CAN_GAFLRMDP_MASK       ((uint32_t)0x7F   << CAN_GAFLRMDP_OFFSET)//Receive Buffer Number Select mask

/*RSCAN0GAFLP1j — Receive Rule Pointer 1 Register (j = 0 to 15)*/
#define CAN_GAFLFDPH_OFFSET     8

#define CAN_GAFLFDPH_MASK       ((uint32_t)0x3FFFF << CAN_GAFLFDPH_OFFSET)
#define CAN_GAFLFDPL_MASK       ((uint32_t)0xFF)

/******************************************************************************/
/*RSCAN0RMNB — Receive Buffer Number Register*/
#define CAN_NRXMB_MASK          ((uint32_t)0xFF)

/*None RSCAN0RMNDy — Receive Buffer New Data Register (y = 0 to 2)*/

/*RSCAN0RMIDq — Receive Buffer ID Register (q = 0 to 95)*/
#define CAN_RMIDE_OFFSET        31
#define CAN_RMRTR_OFFSET        30

#define CAN_RMIDE_MASK          ((uint32_t)0x01 << CAN_RMIDE_OFFSET) //Receive Buffer IDE
#define CAN_RMRTR_MASK          ((uint32_t)0x01 << CAN_RMRTR_OFFSET) //Receive Buffer RTR
#define CAN_RMID_MASK           ((uint32_t)0x1FFFFFFF) //Receive Buffer ID Data [28:0]

/*RSCAN0RMPTRq — Receive Buffer Pointer Register (q = 0 to 95)*/
#define CAN_RMDLC_OFFSET        28
#define CAN_RMPTR_OFFSET        16

#define CAN_RMDLC_MASK          ((uint32_t)0x0F << CAN_RMDLC_OFFSET) //Receive Buffer DLC Data [31:28]
#define CAN_RMPTR_MASK          ((uint32_t)0xFFF << CAN_RMPTR_OFFSET) //Receive Buffer Label Data [27:16]
#define CAN_RMTS_MASK           ((uint32_t)0xFFFF) //Receive Buffer Timestamp Data [15:0]

/******************************************************************************/
/*RSCAN0RFCCx — Receive FIFO Buffer Configuration and Control Register(x = 0 to 7)*/
#define CAN_RFIGCV_OFFSET       13
#define CAN_RFIM_OFFSET         12
#define CAN_RFDC_OFFSET         8
#define CAN_RFIE_OFFSET         1

#define CAN_RFIGCV_MASK         ((uint32_t)0x07 << CAN_RFIGCV_OFFSET)//Receive FIFO Interrupt Request Timing Select
#define CAN_RFIM_MASK           ((uint32_t)0x01 << CAN_RFIM_OFFSET) //Receive FIFO Interrupt Source Select
#define CAN_RFDC_MASK           ((uint32_t)0x07 << CAN_RFDC_OFFSET) //Receive FIFO Buffer Depth Configuration
#define CAN_RFIE_MASK           ((uint32_t)0x01 << CAN_RFIE_OFFSET) //Receive FIFO Interrupt Enable
#define CAN_RFE_MASK            ((uint32_t)0x01) //Receive FIFO Buffer Enable

/*RSCAN0RFSTSx — Receive FIFO Buffer Status Register (x = 0 to 7)*/
#define CAN_RFMC_OFFSET         8
#define CAN_RFIF_OFFSET         3
#define CAN_RFMLT_OFFSET        2
#define CAN_RFFLL_OFFSET        1

#define CAN_RFMC_MASK           ((uint32_t)0xFF << CAN_RFMC_OFFSET) //Receive FIFO Unread Message Counter [15:8]
#define CAN_RFIF_MASK           ((uint32_t)0x01 << CAN_RFIF_OFFSET) //Receive FIFO Interrupt Request Flag
#define CAN_RFMLT_MASK          ((uint32_t)0x01 << CAN_RFMLT_OFFSET)//Receive FIFO Message Lost Flag
#define CAN_RFFLL_MASK          ((uint32_t)0x01 << CAN_RFFLL_OFFSET)//Receive FIFO Buffer Full Status Flag
#define CAN_RFEMP_MASK          ((uint32_t)0x01) //Receive FIFO Buffer Empty Status Flag

/*RSCAN0RFPCTRx — Receive FIFO Buffer Pointer Control Register (x = 0 to 7)*/
#define CAN_RFPC_MASK           ((uint32_t)0xFF) //Receive FIFO Pointer Control

/*RSCAN0RFIDx — Receive FIFO Buffer Access ID Register (k = 0 to 7)*/
#define CAN_RFIDE_OFFSET        31
#define CAN_RFRTR_OFFSET        30

#define CAN_RFIDE_MASK          ((uint32_t)0x01 << CAN_RFIDE_OFFSET) //Receive FIFO Buffer IDE
#define CAN_RFRTR_MASK          ((uint32_t)0x01 << CAN_RFRTR_OFFSET) //Receive FIFO Buffer RTR
#define CAN_RFID_MASK           ((uint32_t)0x1FFFFFFF) //Receive FIFO Buffer ID Data

/*RSCAN0RFPTRx — Receive FIFO Buffer Access Pointer Register (k = 0 to 7)*/
#define CAN_RFDLC_OFFSET        28
#define CAN_RFPTR_OFFSET        16

#define CAN_RFDLC_MASK          ((uint32_t)0x0F << CAN_RFDLC_OFFSET)
#define CAN_RFPTR_MASK          ((uint32_t)0xFFF << CAN_RFPTR_OFFSET)
#define CAN_RFTS_MASK           ((uint32_t)0xFFFF)

/******************************************************************************/
/*RSCAN0CFCCk — Transmit/receive FIFO Buffer Configuration and Control
Register k (k = 0 to 17)*/
#define CAN_CFITT_OFFSET        24
#define CAN_CFTML_OFFSET        20
#define CAN_CFITR_OFFSET        19
#define CAN_CFITSS_OFFSET       18
#define CAN_CFM_OFFSET          16
#define CAN_CFIGCV_OFFSET       13
#define CAN_CFIM_OFFSET         12
#define CAN_CFDC_OFFSET         8
#define CAN_CFTXIE_OFFSET       2
#define CAN_CFRXIE_OFFSET       1

#define CAN_CFITT_MASK          ((uint32_t)0xFF << CAN_CFITT_OFFSET)
#define CAN_CFTML_MASK          ((uint32_t)0x0F << CAN_CFTML_OFFSET)
#define CAN_CFITR_MASK          ((uint32_t)0x01 << CAN_CFITR_OFFSET)
#define CAN_CFITSS_MASK         ((uint32_t)0x01 << CAN_CFITSS_OFFSET)
#define CAN_CFM_MASK            ((uint32_t)0x03 << CAN_CFM_OFFSET)
#define CAN_CFIGCV_MASK         ((uint32_t)0x07 << CAN_CFIGCV_OFFSET)
#define CAN_CFIM_MASK           ((uint32_t)0x01 << CAN_CFIM_OFFSET)
#define CAN_CFDC_MASK           ((uint32_t)0x07 << CAN_CFDC_OFFSET)
#define CAN_CFTXIE_MASK         ((uint32_t)0x01 << CAN_CFTXIE_OFFSET)
#define CAN_CFRXIE_MASK         ((uint32_t)0x01 << CAN_CFRXIE_OFFSET)
#define CAN_CFE_MASK            ((uint32_t)0x01)

/*RSCAN0CFSTSk — Transmit/receive FIFO Buffer Status Register (k = 0 to 17)*/
#define CAN_CFMC_OFFSET         8
#define CAN_CFTXIF_OFFSET       4
#define CAN_CFRXIF_OFFSET       3
#define CAN_CFMLT_OFFSET        2
#define CAN_CFFLL_OFFSET        1

#define CAN_CFMC_MASK           ((uint32_t)0x01 << CAN_CFMC_OFFSET)
#define CAN_CFTXIF_MASK         ((uint32_t)0x01 << CAN_CFTXIF_OFFSET)
#define CAN_CFRXIF_MASK         ((uint32_t)0x01 << CAN_CFRXIF_OFFSET)
#define CAN_CFMLT_MASK          ((uint32_t)0x01 << CAN_CFMLT_OFFSET)
#define CAN_CFFLL_MASK          ((uint32_t)0x01 << CAN_CFFLL_OFFSET)
#define CAN_CFEMP_MASK          ((uint32_t)0x01)

/*RSCAN0CFIDk — Transmit/receive FIFO Buffer Access ID Register (k = 0 to 17)*/
#define CAN_CFIDE_OFFSET        31
#define CAN_CFRTR_OFFSET        30
//#define CAN_THLEN_OFFSET        29

#define CAN_CFIDE_MASK          ((uint32_t)0x01 << CAN_CFIDE_OFFSET)
#define CAN_CFRTR_MASK          ((uint32_t)0x01 << CAN_CFRTR_OFFSET)
//#define CAN_THLEN_MASK          ((uint32_t)0x01 << CAN_THLEN_OFFSET)
#define CAN_CFID_MASK           ((uint32_t)0x1FFFFFFF)

/*RSCAN0CFPTRk — Transmit/receive FIFO Buffer Access Pointer Register (k = 0 to 17)*/
#define CAN_CFDLC_OFFSET        28
#define CAN_CFPTR_OFFSET        16

#define CAN_CFDLC_MASK          ((uint32_t)0x0F << CAN_CFDLC_OFFSET)
#define CAN_CFPTR_MASK          ((uint32_t)0xFFF << CAN_CFPTR_OFFSET)
#define CAN_CFTS_MASK           ((uint32_t)0xFFFF)

/*RSCAN0CFPCTRk — Transmit/receive FIFO Buffer Pointer Control Register (k = 0 to 17)*/
#define CAN_CFPC_MASK           ((uint32_t)0xFF)

/******************************************************************************/
/*RSCAN0TMCp — Transmit Buffer Control Register (p = 0 to 95)*/
#define CAN_TMOM_OFFSET         2
#define CAN_TMTAR_OFFSET        1

#define CAN_TMOM_MASK           ((uint32_t)0x01 << CAN_TMOM_OFFSET)
#define CAN_TMTAR_MASK          ((uint32_t)0x01 << CAN_TMTAR_OFFSET)
#define CAN_TMTR_MASK           ((uint32_t)0x01)

/*RSCAN0TMSTSp — Transmit Buffer Status Register (p = 0 to 95)*/
#define CAN_TMTARM_OFFSET       4
#define CAN_TMTRM_OFFSET        3
#define CAN_TMTRF_OFFSET        1

#define CAN_TMTARM_MASK         ((uint32_t)0x01 << CAN_TMTARM_OFFSET)
#define CAN_TMTRM_MASK          ((uint32_t)0x01 << CAN_TMTRM_OFFSET)
#define CAN_TMTRF_MASK          ((uint32_t)0x03 << CAN_TMTRF_OFFSET)
#define CAN_TMTSTS_MASK         ((uint32_t)0x01)

/*RSCAN0TMIDp — Transmit Buffer ID Register (p = 0 to 95)*/
#define CAN_TMIDE_OFFSET        31
#define CAN_TMRTR_OFFSET        30
#define CAN_THLEN_OFFSET        29

#define CAN_TMIDE_MASK          ((uint32_t)0x01 << CAN_TMIDE_OFFSET)
#define CAN_TMRTR_MASK          ((uint32_t)0x01 << CAN_TMRTR_OFFSET)
#define CAN_THLEN_MASK          ((uint32_t)0x01 << CAN_THLEN_OFFSET)
#define CAN_TMID_MASK           ((uint32_t)0x1FFFFFFF)

/*RSCAN0TMPTRp — Transmit Buffer Pointer Register (p= 0 to 95)*/
#define CAN_TMDLC_OFFSET        28
#define CAN_TMPTR_OFFSET        16

#define CAN_TMDLC_MASK          ((uint32_t)0x0F << CAN_TMDLC_OFFSET)
#define CAN_TMPTR_MASK          ((uint32_t)0xFF << CAN_TMPTR_OFFSET)

/******************************************************************************/
/*RSCAN0TXQCCm — Transmit Queue Configuration and Control Register
(m = 0 to 5)*/
#define CAN_TXQIM_OFFSET        13
#define CAN_TXQIE_OFFSET        12
#define CAN_TXQDC_OFFSET        8

#define CAN_TXQIM_MASK          ((uint32_t)0x01 << CAN_TXQIM_OFFSET)
#define CAN_TXQIE_MASK          ((uint32_t)0x01 << CAN_TXQIE_OFFSET)
#define CAN_TXQDC_MASK          ((uint32_t)0x0F << CAN_TXQDC_OFFSET)
#define CAN_TXQE_MASK           ((uint32_t)0x01)

/*RSCAN0TXQSTSm — Transmit Queue Status Register (m = 0 to 5)*/
#define CAN_TXQIF_OFFSET        2
#define CAN_TXQFLL_OFFSET       1

#define CAN_TXQIF_MASK          ((uint32_t)0x01 << CAN_TXQIF_OFFSET) //Transmit Queue Interrupt Request Flag
#define CAN_TXQFLL_MASK         ((uint32_t)0x01 << CAN_TXQFLL_OFFSET) //Transmit Queue Full Status Flag
#define CAN_TXQEMP_MASK         ((uint32_t)0x01) //Transmit Queue Empty Status Flag

/*RSCAN0TXQPCTRm — Transmit Queue Pointer Control Register (m = 0 to 5)*/
#define CAN_TXQPC_MASK          ((uint32_t)0xFF)
/******************************************************************************/
/*RSCAN0GTSTCFG — Global Test Configuration Register*/
#define CAN_RTMPS_OFFSET        16
#define CAN_C5ICBCE_OFFSET      5
#define CAN_C4ICBCE_OFFSET      4
#define CAN_C3ICBCE_OFFSET      3
#define CAN_C2ICBCE_OFFSET      2
#define CAN_C1ICBCE_OFFSET      1
#define CAN_C0ICBCE_OFFSET      0

#define CAN_RTMPS_MASK          ((uint32_t)0x3F << CAN_RTMPS_OFFSET)
#define CAN_C5ICBCE_MASK        ((uint32_t)0x01 << CAN_C5ICBCE_OFFSET)
#define CAN_C4ICBCE_MASK        ((uint32_t)0x01 << CAN_C4ICBCE_OFFSET)
#define CAN_C3ICBCE_MASK        ((uint32_t)0x01 << CAN_C3ICBCE_OFFSET)
#define CAN_C2ICBCE_MASK        ((uint32_t)0x01 << CAN_C2ICBCE_OFFSET)
#define CAN_C1ICBCE_MASK        ((uint32_t)0x01 << CAN_C1ICBCE_OFFSET)
#define CAN_C0ICBCE_MASK        ((uint32_t)0x01)

/*RSCAN0GTSTCTR — Global Test Control Register*/
#define CAN_RTME_OFFSET         2
#define CAN_ICBCTME_OFFSET      0

#define CAN_RTME_MASK           ((uint32_t)0x01 << CAN_RTME_OFFSET)
#define CAN_ICBCTME_MASK        ((uint32_t)0x01)


/******************************************************************************/

#define TEST_FUNC(_BASE_REG_)                              (uint32_t*)(&(RSCAN0_BASE.##_BASE_REG_))
#define CAN_REG_ADDR(_CNT_,_BASE_REG_,_OFFSET_B_)          ((uint32_t*)(((uint8_t*)(&(RSCAN0_BASE.##_BASE_REG_)))+ _OFFSET_B_ *_CNT_))
#define CAN_REG_VAL(_CNT_,_BASE_REG_,_OFFSET_B_)           (*((uint32_t*)(((uint8_t*)(&(RSCAN0_BASE.##_BASE_REG_)))+ _OFFSET_B_ *_CNT_)))

/*********************************19.3.2--19.3.5******************************/
/*Config RSCAN0CmCFG — Channel Configuration Register (m = 0 to 5)
Modify the RSCAN0CmCFG register in channel reset mode or channel halt mode. */
#define __RSCAN_SET_CHANNEL_CFG(_M_,_VALUE_)           (CAN_REG_VAL(_M_,_C0CFG,0x10) = _VALUE_ & 0xFFFFFFFF)
#define __RSCAN_GET_CHANNEL_CFG(_M_)                   CAN_REG_VAL(_M_,_C0CFG,0x10)

/*Config RSCAN0CmCTR — Channel Control Register (m = 0 to 5)*/
#define __RSCAN_SET_CHANNEL_CTL(_M_,_MASK_,_VALUE_)     do{ \
                                                            MODIFY_REG(CAN_REG_ADDR(_M_,_C0CTR,0x10),_MASK_,_VALUE_);\
                                                        }while(0)
#define __RSCAN_GET_CHANNEL_CTL(_M_,_MASK_)             (CAN_REG_VAL(_M_,_C0CTR,0x10) & _MASK_)

/*Read the RSCAN0CmSTS — Channel Status Register (m = 0 to 5) read-only*/
#define __RSCAN_GET_CHANNEL_STAT(_M_,_MASK_)            (CAN_REG_VAL(_M_,_C0STS,0x10) & _MASK_)

/*Config or read RSCAN0CmERFL — Channel Error Flag Register (m = 0 to 5)*/
#define __RSCAN_GET_CHANNEL_Error(_M_,_MASK_)           (CAN_REG_VAL(_M_,_C0ERFL,0x10) & _MASK_)

/*********************************19.3.6--19.3.12******************************/
/*Config RSCAN0GCFG — Global Configuration Register
Modify the RSCAN0GCFG register only in global reset mode.*/
#define __RSCAN_SET_GLOBAL_CFG(_MASK_,_VALUE_)          do{ \
                                                            MODIFY_REG(&RSCAN0_BASE._GCFG,_MASK_,_VALUE_);\
                                                        }while(0)
#define __RSCAN_GET_GLOBAL_CFG(_MASK_)                  (RSCAN0_BASE._GCFG & (_MASK_))

/*Config RSCAN0GCTR — Global Control Register*/
#define __RSCAN_SET_GLOBAL_CTL(_MASK_,_VALUE_)          do{ \
                                                            MODIFY_REG(&RSCAN0_BASE._GCTR,_MASK_,_VALUE_);\
                                                        }while(0)
#define __RSCAN_GET_GLOBAL_CTL(_MASK_)                  (RSCAN0_BASE._GCTR & (_MASK_))

/*Read the RSCAN0GSTS — Global Status Register read-only*/
#define __RSCAN_GET_GLOBAL_STAT(_MASK_)                 (RSCAN0_BASE._GSTS & (_MASK_))

/*Read the RSCAN0GERFL — Global Error Flag Register*/
#define __RSCAN_GET_GLOBAL_Error(_MASK_)                (RSCAN0_BASE._GERFL & (_MASK_))

/*TODO Config or read the RSCAN0GTINTSTS0 — Global TX Interrupt Status Register 0*/
/*TODO Config or read the RSCAN0GTINTSTS1 — Global TX Interrupt Status Register 1 */
/*TODO Config or read the RSCAN0GTSC — Global Timestamp Counter Register*/

/*********************************19.3.13--19.3.19*****************************/
/*Config RSCAN0GAFLECTR — Receive Rule Entry Control Register
Enable or disable receive rule table write 0--disbale 1 -- Enable*/
#define __RSCAN_ENABLE_RECV_TABLE_WRITE(_ENABLE_)       do{ \
                                                            if(_ENABLE_) \
                                                                RSCAN0_BASE._GAFLECTR |= CAN_AFLDAE_MASK; \
                                                            else \
                                                                RSCAN0_BASE._GAFLECTR &= ~CAN_AFLDAE_MASK; \
                                                        }while(0)
#define __RSCAN_RECV_TABLE_WRITE_STAT()                 (RSCAN0_BASE._GAFLECTR & CAN_AFLDAE_MASK)
//Receive Rule Table Page Number Configuration,_NUMBER_ within the range of 00000B(0) to 10111B(23).
#define __RSCAN_RECV_TABLE_PAGE_NUM_CFG(_NUMBER_)        MODIFY_REG(&RSCAN0_BASE._GAFLECTR,CAN_AFLPN_MASK,_NUMBER_)

/*Config RSCAN0GAFLCFG0 — Receive Rule Configuration Register 0
Used to set the number(_NUMBER_) of rules to be registered in the channel x
_INDEX_: 0-3,_NUMBER_: 0x00 -0x80. Modify the RSCAN0GAFLCFG0 register only in global reset mode.*/
#define __RSCAN_SET_RULE_NUMBER_0(_INDEX_,_NUMBER_)     RSCAN0_BASE._GAFLCFG0[_INDEX_] = _NUMBER_ & 0xFF
#define __RSCAN_GET_RULE_NUMBER_0(_INDEX_)              (RSCAN0_BASE._GAFLCFG0[_INDEX_])
/*Config RSCAN0GAFLCFG1 — Receive Rule Configuration Register 1 _INDEX_: 4-5 ,_NUMBER_: 0x00 -0x80
Modify the RSCAN0GAFLCFG1 register only in global reset mode.*/
#define __RSCAN_SET_RULE_NUMBER_1(_INDEX_,_NUMBER_)     RSCAN0_BASE._GAFLCFG1[_INDEX_] = _NUMBER_ & 0xFF
#define __RSCAN_GET_RULE_NUMBER_1(_INDEX_)              (RSCAN0_BASE._GAFLCFG1[_INDEX_])


/*Config the RSCAN0GAFLIDj — Receive Rule ID Register*/
#define __RSCAN_SET_RULE_ID(_J_,_VALUE_)                CAN_REG_VAL(_J_,_GAFLID0,0x10) = _VALUE_
/*Get the RSCAN0GAFLIDj — Receive Rule ID Register*/
#define __RSCAN_GET_RULE_ID(_J_)                        CAN_REG_VAL(_J_,_GAFLID0,0x10)
/*Config RSCAN0GAFLMj — Receive Rule Mask Register (j = 0 to 15)*/
#define __RSCAN_SET_RULE_MASK(_J_,_MASK_,_VALUE_)       MODIFY_REG(CAN_REG_ADDR(_J_,_GAFLM0,0x10),_MASK_,_VALUE_)

/*Config the RSCAN0GAFLP0j — Receive Rule Pointer 0 Register (j = 0 to 15)*/
#define __RSCAN_SET_RULE_POINTER0(_J_,_VALUE_)          CAN_REG_VAL(_J_,_GAFLP0,0x10) = _VALUE_
/*Config the RSCAN0GAFLP1j — Receive Rule Pointer 1 Register (j = 0 to 15)*/
#define __RSCAN_SET_RULE_POINTER1(_J_,_VALUE_)          CAN_REG_VAL(_J_,_GAFLP1,0x10) = _VALUE_

/*********************************19.3.20--19.3.25*****************************/
/*Config RSCAN0RMNB — Receive Buffer Number Register*/
#define __RSCAN_SET_TOTAL_RECV_BUF_NUM(_NUM_)           (RSCAN0_BASE._RMNB = _NUM_ & CAN_NRXMB_MASK)

/*Check new message or clear the flag. RSCAN0RMNDy — Receive Buffer New Data Register (y = 0 to 2)*/
#define __RSCAN_CHECK_RECV_NEW_MSG(_Y_,_MASK_)              (CAN_REG_VAL(_Y_,_RMND0,0x04) & (_MASK_))
#define __RSCAN_CLEAR_NEW_MSG_FLAG(_Y_,_MASK_)              (CAN_REG_VAL(_Y_,_RMND0,0x04) &= ~(_MASK_))

/*Read the RSCAN0RMIDq — Receive Buffer ID Register (q = 0 to 95)*/
#define __RSCAN_GET_RECV_BUF_ID(_Q_)                        (CAN_REG_VAL(_Q_,_RMID0,0x10))

/*Read the RSCAN0RMPTRq — Receive Buffer Pointer Register (q = 0 to 95)*/
#define __RSCAN_GET_RECV_BUF_POINTER(_Q_)                   (CAN_REG_VAL(_Q_,_RMPTR0,0x10))

/*Read the RSCAN0RMDF0q — Receive Buffer Data Field 0 Register (q = 0 to 95)*/
#define __RSCAN_READ_RECV_BUF_DATA_L(_Q_)                   (CAN_REG_ADDR(_Q_,_RMDF00,0x10))
/*Read the RSCAN0RMDF1q — Receive Buffer Data Field 1 Register (q = 0 to 95)*/
#define __RSCAN_READ_RECV_BUF_DATA_H(_Q_)                   (CAN_REG_ADDR(_Q_,_RMDF10,0x10))

/*********************************19.3.26--19.3.32*****************************/
/*Config the RSCAN0RFCCx Receive FIFO Buffer Configuration and Control Register (x = 0 to 7)*/
#define __RSCAN_SET_RECV_FIFO_BUF(_X_,_MASK_,_VALUE_)       MODIFY_REG(CAN_REG_ADDR(_X_,_RFCC0,0x04),_MASK_,_VALUE_)

/*Read the RSCAN0RFSTSx — Receive FIFO Buffer Status Register (x = 0 to 7)*/
#define __RSCAN_GET_RECV_FIFO_STAT(_X_,_MASK_)              (CAN_REG_VAL(_X_,_RFSTS0,0x04) & (_MASK_))
#define __RSCAN_SET_RECV_FIFO_STAT(_X_,_MASK_,_VALUE_)      MODIFY_REG(CAN_REG_ADDR(_X_,_RFSTS0,0x04),_MASK_,_VALUE_)
/*RSCAN0RFPCTRx — Receive FIFO Buffer Pointer Control Register (x = 0 to 7)
Writing FFH to these bits moves the read pointer to the next unread message*/
#define _RSCAN_SET_RECV_FIFO_POINTER(_X_)                   (CAN_REG_VAL(_X_,_RFPCTR0,0x04) =  0xFF)

/*Read the RSCAN0RFIDx — Receive FIFO Buffer Access ID Register (k = 0 to 7)
This register is read-only when receive mode*/
#define __RSCAN_GET_RECV_FIFO_ID(_X_)                       CAN_REG_VAL(_X_,_RFID0,0x10)
/*Read the RSCAN0RFPTRx — Receive FIFO Buffer Access Pointer Register(k = 0 to 7)
This register is read-only when receive mode*/
#define __RSCAN_GET_RECV_FIFO_POINTER(_X_)                  CAN_REG_VAL(_X_,_RFPTR0,0x10)
/*Read the RSCAN0RFDF0x — Receive FIFO Buffer Access Data Field 0 Register (k = 0 to 7)
This register is read-only when receive mode*/
#define __RSCAN_READ_RECV_FIFO_DATA_L(_X_)                  CAN_REG_VAL(_X_,_RFDF00,0x10)
/*Read the RSCAN0RFDF1x — Receive FIFO Buffer Access Data Field 1 Register (k = 0 to 7)
This register is read-only when receive mode*/
#define __RSCAN_READ_RECV_FIFO_DATA_H(_X_)                  CAN_REG_VAL(_X_,_RFDF10,0x10)

/*********************************19.3.33--19.3.39*****************************/
/*Config the RSCAN0CFCCx  Transmit/receive FIFO Buffer Configuration and Control
Register k (k = 0 to 17)*/
#define __RSCAN_SET_TrRe_FIFO_BUF(_K_,_MASK_,_VALUE_)       MODIFY_REG(CAN_REG_ADDR(_K_,_CFCC0,0x04),_MASK_,_VALUE_)

/*RSCAN0CFSTSk — Transmit/receive FIFO Buffer Status Register (k = 0 to 17)*/
#define __RSCAN_GET_TrRe_FIFO_STAT(_K_,_MASK_)              CAN_REG_VAL(_K_,_CFSTS0,0x04) & (_MASK_)
/*Config RSCAN0CFPCTRk — Transmit/receive FIFO Buffer Pointer Control Register (k = 0 to 17)
Writing FFH to these bits moves the read pointer to the next unread message or
moves the write pointer to the next stage of the transmit/receive FIFO buffer*/
#define _RSCAN_SET_TrRe_FIFO_POINTER(_K_)                   CAN_REG_VAL(_K_,_CFPCTR0,0x04) =  0xFF

/*Config RSCAN0CFIDk — Transmit/receive FIFO Buffer Access ID Register (k = 0 to 17)
This register is writable only when transmit mode, readable only when the CFM[1:0] value is 00B (receive mode)*/
#define __RSCAN_SET_TrRe_FIFO_ID(_K_,_VALUE_)               CAN_REG_VAL(_K_,_CFID0,0x10) = _VALUE_ & 0xFFFFFFFF
#define __RSCAN_GET_TrRe_FIFO_ID(_K_)                       CAN_REG_VAL(_K_,_CFID0,0x10)
/*Config RSCAN0CFPTRk — Transmit/receive FIFO Buffer Access Pointer Register(k = 0 to 17)
This register is writable only when transmit mode, readable only when the CFM[1:0] value is 00B (receive mode)*/
#define __RSCAN_SET_TrRe_FIFO_POINTER(_K_,_VALUE_)          CAN_REG_VAL(_K_,_CFPTR0,0x10) = _VALUE_ & 0xFFFFFFFF
#define __RSCAN_GET_TrRe_FIFO_POINTER(_K_)                  CAN_REG_VAL(_K_,_CFPTR0,0x10)
/*Config RSCAN0CFDF0k — Transmit/receive FIFO Buffer Access Data Field 0 Register (k = 0 to 17)
This register is writable only when transmit mode, readable only when the CFM[1:0] value is 00B (receive mode)*/
#define __RSCAN_WRITE_TrRe_FIFO_DATA_L(_K_,_MSG_BASE_)      CAN_REG_VAL(_K_,_CFDF00,0x10) = *((uint32_t *)_MSG_BASE_)
#define __RSCAN_READ_TrRe_FIFO_DATA_L(_K_)                  CAN_REG_VAL(_K_,_CFDF00,0x10)
/*Config RSCAN0CFDF1k — Transmit/receive FIFO Buffer Access Data Field 1 Register (k = 0 to 17)
This register is writable only when transmit mode, readable only when the CFM[1:0] value is 00B (receive mode)*/
#define __RSCAN_WRITE_TrRe_FIFO_DATA_H(_K_,_MSG_BASE_)      CAN_REG_VAL(_K_,_CFDF10,0x10) = *((uint32_t *)_MSG_BASE_)
#define __RSCAN_READ_TrRe_FIFO_DATA_H(_K_)                  CAN_REG_VAL(_K_,_CFDF10,0x10)

/*********************************19.3.40--19.3.45*****************************/
/*TODO Config or read the RSCAN0FESTS — FIFO Empty Status Register*/
/*TODO Config or read the RSCAN0FFSTS — FIFO Full Status Register*/
/*TODO Config or read the RSCAN0FMSTS — FIFO Message Lost Status Register*/
/*TODO Config or read the RSCAN0RFISTS — Receive FIFO Buffer Interrupt Flag Status Register*/
/*TODO Config or read the RSCAN0CFRISTS — Transmit/receive FIFO Buffer Receive Interrupt Flag Status Register*/
/*TODO Config or read the  RSCAN0CFTISTS — Transmit/receive FIFO Buffer Transmit Interrupt Flag Status Register*/

/*********************************19.3.46--19.3.56*****************************/
/*Config RSCAN0TMCp — Transmit Buffer Control Register (p = 0 to 95)*/
#define __RSCAN_SET_TRANSMIT_BUF_CTL(_P_,_MASK_,_VALUE_)        MODIFY_REG(CAN_REG_ADDR(_P_,_TMC0,0x01),_MASK_,_VALUE_ & 0xFFFFFFFF)

/*Config or read the RSCAN0TMSTSp — Transmit Buffer Status Register (p = 0 to 95)*/
#define __RSCAN_GET_TRANSMIT_STAT(_P_,_MASK_)                   (CAN_REG_VAL(_P_,_TMSTS0,0x01) & (_MASK_))
#define __RSCAN_SET_TRANSMIT_STAT(_P_,_MASK_,_VALUE_)           MODIFY_REG(CAN_REG_ADDR(_P_,_TMSTS0,0x01),_MASK_,_VALUE_)

/*TODO Config or read the RSCAN0TMTRSTSy — Transmit Buffer Transmit Request Status Register (y = 0 to 2)*/
/*TODO Config or read the RSCAN0TMTARSTSy — Transmit Buffer Transmit Abort Request Status Register (y = 0 to 2)*/
/*TODO Config or read the RSCAN0TMTCSTSy — Transmit Buffer Transmit Complete Status Register (y = 0 to 2)*/
/*TODO Config or read the RSCAN0TMTASTSy — Transmit Buffer Transmit Abort Status Register (y = 0 to 2)*/

/*Config RSCAN0TMIECy — Transmit Buffer Interrupt Enable Configuration Register
Modify this register when no transmit request is present*/
#define __RSCAN_ENABLE_TRANSMIT_BUF_INT(_Y_,_MASK_,_VALUE_)     MODIFY_REG(CAN_REG_ADDR(_Y_,_TMIEC0,0x04),_MASK_,_VALUE_)
/*Config RSCAN0TMIDp — Transmit Buffer ID Register (p = 0 to 95)
Modify this register when no transmit request is present*/
#define __RSCAN_SET_TRANSMIT_BUF_ID(_P_,_VALUE_)                CAN_REG_VAL(_P_,_TMID0,0x10) = _VALUE_ & 0xFFFFFFFF
/*Config RSCAN0TMPTRp — Transmit Buffer Pointer Register (p= 0 to 95)
Modify this register when no transmit request is present*/
#define __RSCAN_SET_TRANSMIT_BUF_POINTER(_P_,_VALUE_)           CAN_REG_VAL(_P_,_TMPTR0,0x10) = _VALUE_ & 0xFFFFFFFF
/*Write to RSCAN0TMDF0p — Transmit Buffer Data Field 0 Register (p = 0 to 95)*/
#define __RSCAN_WRITE_TRANSMIT_BUF_DATA_L(_P_,_MSG_BASE_)       CAN_REG_VAL(_P_,_TMDF00,0x10) = *((uint32_t *)_MSG_BASE_)
/*Write to RSCAN0TMDF1p — Transmit Buffer Data Field 1 Register (p = 0 to 95)*/
#define __RSCAN_WRITE_TRANSMIT_BUF_DATA_H(_P_,_MSG_BASE_)       CAN_REG_VAL(_P_,_TMDF10,0x10) = *((uint32_t *)_MSG_BASE_)

/*********************************19.3.57--19.3.59*****************************/
/*Config RSCAN0TXQCCm — Transmit Queue Configuration and Control Register(m = 0 to 5)*/
#define __RSCAN_SET_TRANSMIT_QUEUE(_M_,_MASK_,_VALUE_)          MODIFY_REG(CAN_REG_ADDR(_M_,_TXQCC0,0x04),_MASK_,_VALUE_)
/*Config RSCAN0TXQSTSm — Transmit Queue Status Register (m = 0 to 5)*/
#define __RSCAN_GET_TRANSMIT_QUEUE_STAT(_M_,_MASK_)             CAN_REG_VAL(_M_,_TXQSTS0,0x04) & (_MASK_)
/*Config RSCAN0TXQPCTRm — Transmit Queue Pointer Control Register (m = 0 to 5) -- write-only*/
#define __RSCAN_SET_TRANSMIT_QUEUE_POINTER(_M_)                 CAN_REG_VAL(_M_,_TXQPCTR0,0x04) =  0xFF

/*********************************19.3.60--19.3.63*****************************/
/*TODO Config or read the RSCAN0THLCCm — Transmit History Configuration and Control Register (m = 0 to 5)*/
/*TODO Config or read the RSCAN0THLSTSm — Transmit History Status Register (m = 0 to 5)*/
/*TODO Config or read the RSCAN0THLACCm — Transmit History Access Register (m = 0 to 5)*/
/*TODO Config or read the RSCAN0THLPCTRm — Transmit History Pointer Control Register (m = 0 to 5)*/

/*********************************19.3.64--19.3.67*****************************/
/*Config the RSCAN0GTSTCFG — Global Test Configuration Register*/
#define __RSCAN_SET_GLOBAL_TEST_CONFIG(_MASK_,_VALUE_)      do{ \
                                                                MODIFY_REG(&RSCAN0_BASE._GTSTCFG,_MASK_,_VALUE_);\
                                                            }while(0)
/*Config the RSCAN0GTSTCTR — Global Test Control Register*/
#define __RSCAN_SET_GLOBAL_TEST_CTL(_MASK_,_VALUE_)         do{ \
                                                                MODIFY_REG(&RSCAN0_BASE._GTSTCTR,_MASK_,_VALUE_);\
                                                            }while(0)
/*Config the  RSCAN0GLOCKK — Global Lock Key Register*/
#define __RSCAN_SET_LOCK_KEY(_VALUE_)                       (RSCAN0_BASE._GLOCKK  = _VALUE_ & 0xFFFF)

/*Config or read the RSCAN0RPGACCr — RAM Test Page Access Register (r = 0 to 63)*/
#define __RSCAN_WRITE_RAM_TEST_PAGE(_R_,_VALUE_)            (CAN_REG_VAL(_R_,_RPGACC0,0x04) =  _VALUE_ & 0xFFFFFFFF)
#define __RSCAN_READ_RAM_TEST_PAGE(_R_)                     CAN_REG_VAL(_R_,_RPGACC0,0x04)


#define RSCAN_TRANSMIT_IN_PROCESS               0   //Transmission is in progress or no transmit request is present
#define RSCAN_TRANSMIT_NO_REQUEST               RSCAN_TRANSMIT_IN_PROCESS
#define RSCAN_TRANSMIT_ABORT_COMPLETED          2   //Transmit abort has been completed.
#define RSCAN_TRANSMIT_COMPLETED_WITHOUT_ABORT  4   //Transmission has been completed (without transmit abort request)
#define RSCAN_TRANSMIT_COMPLETED_WITH_ABORT     6   //Transmission has been completed (with transmit abort request)

#define RSCAN_BUS_ERROR                         0   //Bus Error error
#define RSCAN_ERROR_WARNING                     1   //Error Warning error
#define RSCAN_ERROR_PASSIVE                     2   //Error Passive error
#define RSCAN_BUS_OFF_ENTRY                     3   //Bus-off Entry error
#define RSCAN_BUS_OFF_RECOVERY                  4   //Bus-off Recovery error
#define RSCAN_OVERLOAD_ERROR                    5   //Overload error
#define RSCAN_BUS_DOMINANT_LOCK                 6   //Bus Lock error
#define RSCAN_ARBITRATION_LOST                  7   //Arbitration-lost error
#define RSCAN_STUFF_ERROR                       8   //Stuff Error
#define RSCAN_FORM_ERROR                        9   //Form Error
#define RSCAN_ACK_ERROR                         10  //ACK Error
#define RSCAN_CRC_ERROR                         11  //CRC Error
#define RSCAN_R_BIT_ERROR                       12  //Recessive Bit Error
#define RSCAN_D_BIT_ERROR                       13  //Dominant Bit Error
#define RSCAN_ACK_DELIMITER_ERROR               14  //ACK Delimiter Error
#define RSCAN_DLC_ERROR                         15  //DLC Error Flag


typedef enum{
    RSCAN_RECV_FIFO_EMPTY,
    RSCAN_RECV_FIFO_NOT_EMPTY,
    RSCAN_RECV_FIFO_FULL,
    RSCAN_RECV_FIFO_ERR,
    RSCAN_RECV_FIFO_NO_MSG,
}RSCAN_RECV_FIFO_RESULT_Type;


typedef enum{
    RSCAN_OPERATE_MODE,     //Global operating mode
    RSCAN_COMMUNICATION_MODE = RSCAN_OPERATE_MODE, //Channel communication mode
    RSCAN_RESET_MODE,       //Global reset mode or Channel reset mode or
    RSCAN_TEST_MODE,        //Global test mode
    RSCAN_HALT_MODE = RSCAN_TEST_MODE,//Channel halt mode
    RSCAN_STOP_MODE = 4,    //Global stop mode or Channel stop mode
}RSCAN_GLOBAL_MODE_Type,RSCAN_CHANNEL_MODE_Type,RSCAN_MODE_Type;


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
    uint8_t fcan_src; //RSCAN_CLKC or RSCAN_CLK_XINCAN,set the CAN clock (fCAN) as a clock source of the RS-CAN module
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
    uint8_t ide;    //RSCAN_RECV_IDE_STD or RSCAN_RECV_IDE_EXT
    uint8_t rtr;    //RSCAN_RECV_DATA_FRM or RSCAN_RECV_REMOTE_FRM
    uint8_t target_msg;//RSCAN_RECV_FROM_OTHER or RSCAN_RECV_FROM_OWN
    uint32_t id;   //up to [28:0] bits id,For the standard ID, set the ID in bits b10 to b0 and set bits b28 to b11 to 0
    uint32_t mask; //the combination of CAN_GAFLIDEM_MASK, CAN_GAFLRTRM_MASK and CAN_GAFLIDM_MASK
}RSCAN_RECV_RULE_ID_INFO_TypeDef;

typedef enum{
    RSCAN_RECV_BUF,     //A receive buffer is used
    RSCAN_TrFIFO,       //Transmit/receive FIFO buffer is selected.
    RSCAN_RECV_FIFO,    //Receive FIFO buffer is selected
}RSCAN_RECV_BUF_Sel_Type;

typedef struct{
    RSCAN_DLC_CHECK_Type dlc_t; //Receive Rule DLC disable or 1-8 data bytes
    uint16_t label_t;           //the 12-bit label information.
    RSCAN_RECV_BUF_Sel_Type recv_buf; //RSCAN_RECV_BUF, RSCAN_TrFIFO or RSCAN_RECV_FIFO,
    uint8_t recv_buf_index;     //the receive buffer number to store received message
    uint8_t k_index;            //transmit/receive FIFO buffer number k 0-17,  active in RSCAN_TrFIFO
    uint8_t x_index;            //receive FIFO buffer number x 0-7, active in RSCAN_RECV_FIFO
}RSCAN_RECV_RULE_POINTER_TypeDef;

typedef struct{
    RSCAN_RECV_RULE_ID_INFO_TypeDef r_id_info;
    RSCAN_RECV_RULE_POINTER_TypeDef r_pointer;
}RSCAN_RECV_RULE_TypeDef;

typedef struct{
    uint8_t index;//p:0--95
    uint8_t ide;//Transmit Buffer IDE 0: Standard ID 1: Extended ID
    uint8_t rtr;//Transmit Buffer RTR 0: Data frame 1: Remote frame
    //Transmit History Data Store Enable 0: Transmit history data is not stored in the buffer.
    //1: Transmit history data is stored in the buffer.
    bool his_en;//Transmit History Data Store Enable
    uint32_t id;//Transmit/Receive FIFO Buffer ID Data
    uint8_t label_t;
    uint16_t time_stamp;
}RSCAN_TRANSMIT_ID_INFO_TypeDef,RSCAN_RECV_ID_INFO_TypeDef;

typedef struct{
    uint8_t channel;
    RSCAN_COM_SPEED_PARAM_TypeDef sp;
    uint8_t rule_num;
    RSCAN_RECV_RULE_TypeDef rule[MAX_RULE_NUM_PER_CHANNEL];
}RSCAN_InitTypeDef;


uint32_t  RSCAN_Global_Mode_Ctl(RSCAN_GLOBAL_MODE_Type mode, uint8_t ctl);
int32_t  RSCAN_Channel_Mode_Ctl(uint8_t channel,RSCAN_CHANNEL_MODE_Type mode,uint8_t ctl);
uint32_t RSCAN_Channel_Error(uint8_t channel);
uint32_t RSCAN_Global_Error(void);
bool R_CAN_Send_TxBuf0(uint8_t);
int8_t RSCAN_RAM_Test_Perform(uint8_t test_page,uint32_t *test_data,uint8_t size);

#endif //RH850F1L_RSCAN_H
