/******************************************************************************/
/* DISCLAIMER                                                                 */
/* This software is supplied by Renesas Electronics Corporation and is only   */
/* intended for use with Renesas products. No other uses are authorized.This  */
/* software is owned by Renesas Electronics Corporation and is protected      */
/* under all applicable laws, including copyright laws.                       */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES          */
/* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING  */
/* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR */
/* PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY           */
/* DISCLAIMED.                                                                */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS     */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE       */
/* LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL      */
/* DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS    */
/* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.           */
/* Renesas reserves the right, without notice, to make changes to this        */
/* software and to discontinue the availability of this software.             */
/* By using this software, you agree to the additional terms and conditions   */
/* found by accessing the following link:                                     */
/* http://www.renesas.com/disclaimer                                          */
/*                                                                            */
/* Device     : RH/RH850G3K/R7F701056                                         */
/* File Name  : iodefine.h                                                    */
/* Abstract   : Definition of I/O Register                                    */
/* History    : V1.20  [Device File version]                                  */
/* Options    : -df=D:\Program Files\Renesas Electronics\CS+\CC\Device\RH850\ */
/*              Devicefile\DR7F701056.DVF -o=D:\Workspace\RH850_Cube_CC\Pro_I */
/*              nterrupt\iodefine.h -def=off -f                               */
/* Date       : 12/10/2017                                                    */
/* Version    : V1.08.00.01  [df2iodef.exe version]                           */
/* This is a typical example.                                                 */
/*                                                                            */
/******************************************************************************/
#ifndef __R7F701056IODEFINE_HEADER__
#define __R7F701056IODEFINE_HEADER__

typedef struct
{
    unsigned char bit00:1;
    unsigned char bit01:1;
    unsigned char bit02:1;
    unsigned char bit03:1;
    unsigned char bit04:1;
    unsigned char bit05:1;
    unsigned char bit06:1;
    unsigned char bit07:1;
} __bitf_T;

#define  L 0
#define  H 1
#define LL 0
#define LH 1
#define HL 2
#define HH 3

struct __tag0
{                                                          /* Bit Access       */
    unsigned char  MBS:1;                                  /* MBS              */
    unsigned char  JOBE:1;                                 /* JOBE             */
    unsigned char  :3;                                     /* Reserved Bits    */
    unsigned char  RXE:1;                                  /* RXE              */
    unsigned char  TXE:1;                                  /* TXE              */
    unsigned char  PWR:1;                                  /* PWR              */
};
struct __tag1
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  SVSDIS:1;                               /* SVSDIS           */
};
struct __tag2
{                                                          /* Bit Access       */
    unsigned char  :5;                                     /* Reserved Bits    */
    unsigned char  RXE:1;                                  /* RXE              */
    unsigned char  TXE:1;                                  /* TXE              */
    unsigned char  PWR:1;                                  /* PWR              */
};
struct __tag3
{                                                          /* Bit Access       */
    unsigned char  SCE:1;                                  /* SCE              */
    unsigned char  :7;                                     /* Reserved Bits    */
};
struct __tag4
{                                                          /* Bit Access       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  SLSB:1;                                 /* SLSB             */
    unsigned char  AMPM:1;                                 /* AMPM             */
    unsigned char  CEST:1;                                 /* CEST             */
    unsigned char  CE:1;                                   /* CE               */
};
struct __tag5
{                                                          /* Bit Access       */
    unsigned char  CT0:1;                                  /* CT0              */
    unsigned char  CT1:1;                                  /* CT1              */
    unsigned char  CT2:1;                                  /* CT2              */
    unsigned char  EN1S:1;                                 /* EN1S             */
    unsigned char  ENALM:1;                                /* ENALM            */
    unsigned char  EN1HZ:1;                                /* EN1HZ            */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag6
{                                                          /* Bit Access       */
    unsigned char  WAIT:1;                                 /* WAIT             */
    unsigned char  WST:1;                                  /* WST              */
    unsigned char  RSUB:1;                                 /* RSUB             */
    unsigned char  RSST:1;                                 /* RSST             */
    unsigned char  WSST:1;                                 /* WSST             */
    unsigned char  WUST:1;                                 /* WUST             */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag7
{                                                          /* Bit Access       */
    unsigned char  KRM0:1;                                 /* KRM0             */
    unsigned char  KRM1:1;                                 /* KRM1             */
    unsigned char  KRM2:1;                                 /* KRM2             */
    unsigned char  KRM3:1;                                 /* KRM3             */
    unsigned char  KRM4:1;                                 /* KRM4             */
    unsigned char  KRM5:1;                                 /* KRM5             */
    unsigned char  KRM6:1;                                 /* KRM6             */
    unsigned char  KRM7:1;                                 /* KRM7             */
};
union __tag8
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
};
union __tag9
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } LBRP0;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } LBRP1;
    } REGS8;
};
union __tag10
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
};
union __tag11
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
};
union __tag12
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag0 BIT;                                     /* Bit Access       */
};
union __tag13
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag1 BIT;                                     /* Bit Access       */
};
union __tag14
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag2 BIT;                                     /* Bit Access       */
};
union __tag15
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag3 BIT;                                     /* Bit Access       */
};
union __tag16
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag4 BIT;                                     /* Bit Access       */
};
union __tag17
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag5 BIT;                                     /* Bit Access       */
};
union __tag18
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag6 BIT;                                     /* Bit Access       */
};
union __tag19
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag7 BIT;                                     /* Bit Access       */
};

struct __tag20
{                                                          /* Module           */
    unsigned long  ID0;                                    /* ID0              */
    unsigned long  ID1;                                    /* ID1              */
    unsigned long  ID2;                                    /* ID2              */
    unsigned long  ID3;                                    /* ID3              */
    union __tag8 IDST;                                     /* IDST             */
};
struct __tag21
{                                                          /* Module           */
    unsigned char  FPMON;                                  /* FPMON            */
    unsigned char  dummy0[15];                             /* Reserved         */
    unsigned char  FASTAT;                                 /* FASTAT           */
    unsigned char  dummy1[3];                              /* Reserved         */
    unsigned char  FAEINT;                                 /* FAEINT           */
    unsigned char  dummy2[11];                             /* Reserved         */
    unsigned short FAREASELC;                              /* FAREASELC        */
    unsigned char  dummy3[14];                             /* Reserved         */
    unsigned long  FSADDR;                                 /* FSADDR           */
    unsigned long  FEADDR;                                 /* FEADDR           */
    unsigned char  dummy4[28];                             /* Reserved         */
    unsigned short FCURAME;                                /* FCURAME          */
    unsigned char  dummy5[42];                             /* Reserved         */
    union __tag8 FSTATR;                                   /* FSTATR           */
    unsigned short FENTRYR;                                /* FENTRYR          */
    unsigned char  dummy6[2];                              /* Reserved         */
    unsigned short FPROTR;                                 /* FPROTR           */
    unsigned char  dummy7[2];                              /* Reserved         */
    unsigned short FSUINITR;                               /* FSUINITR         */
    unsigned char  dummy8[2];                              /* Reserved         */
    unsigned char  FLKSTAT;                                /* FLKSTAT          */
    unsigned char  dummy9[3];                              /* Reserved         */
    unsigned long  FRFSTEADR;                              /* FRFSTEADR        */
    unsigned char  FRTSTAT;                                /* FRTSTAT          */
    unsigned char  dummy10[7];                             /* Reserved         */
    unsigned short FCMDR;                                  /* FCMDR            */
    unsigned char  dummy11[30];                            /* Reserved         */
    unsigned short FPESTAT;                                /* FPESTAT          */
    unsigned char  dummy12[14];                            /* Reserved         */
    unsigned char  FBCCNT;                                 /* FBCCNT           */
    unsigned char  dummy13[3];                             /* Reserved         */
    unsigned char  FBCSTAT;                                /* FBCSTAT          */
    unsigned char  dummy14[3];                             /* Reserved         */
    unsigned long  FPSADDR;                                /* FPSADDR          */
    unsigned char  dummy15[4];                             /* Reserved         */
    unsigned short FCPSR;                                  /* FCPSR            */
    unsigned char  dummy16[2];                             /* Reserved         */
    unsigned short FPCKAR;                                 /* FPCKAR           */
    unsigned char  dummy17[26];                            /* Reserved         */
    unsigned short FECCEMON;                               /* FECCEMON         */
    unsigned char  dummy18[2];                             /* Reserved         */
    unsigned short FECCTMD;                                /* FECCTMD          */
    unsigned char  dummy19[2];                             /* Reserved         */
    unsigned short FDMYECC;                                /* FDMYECC          */
};
struct __tag22
{                                                          /* Module           */
    unsigned char  BWCBUFEN;                               /* BWCBUFEN         */
};
struct __tag23
{                                                          /* Module           */
    unsigned char  FCUFAREA;                               /* FCUFAREA         */
};
struct __tag24
{                                                          /* Module           */
    union __tag8 CR1;                                      /* CR1              */
    union __tag8 CR2;                                      /* CR2              */
    union __tag8 MR1;                                      /* MR1              */
    union __tag8 MR2;                                      /* MR2              */
    union __tag8 MR3;                                      /* MR3              */
    union __tag8 FER;                                      /* FER              */
    union __tag8 SER;                                      /* SER              */
    union __tag8 IER;                                      /* IER              */
    union __tag8 SR1;                                      /* SR1              */
    union __tag8 SR2;                                      /* SR2              */
    union __tag8 SAR0;                                     /* SAR0             */
    union __tag8 SAR1;                                     /* SAR1             */
    union __tag8 SAR2;                                     /* SAR2             */
    union __tag8 BRL;                                      /* BRL              */
    union __tag8 BRH;                                      /* BRH              */
    union __tag8 DRT;                                      /* DRT              */
    union __tag8 DRR;                                      /* DRR              */
};
struct __tag25
{                                                          /* Module           */
    unsigned long  PRDNAME1;                               /* PRDNAME1         */
    unsigned long  PRDNAME2;                               /* PRDNAME2         */
    unsigned long  PRDNAME3;                               /* PRDNAME3         */
};
struct __tag26
{                                                          /* Module           */
    unsigned char  dummy20[1];                             /* Reserved         */
    unsigned char  GLWBR;                                  /* GLWBR            */
    unsigned char  GLBRP0;                                 /* GLBRP0           */
    unsigned char  GLBRP1;                                 /* GLBRP1           */
    unsigned char  GLSTC;                                  /* GLSTC            */
};
struct __tag27
{                                                          /* Module           */
    unsigned char  L0MD;                                   /* L0MD             */
    unsigned char  L0BFC;                                  /* L0BFC            */
    unsigned char  L0SC;                                   /* L0SC             */
    unsigned char  L0WUP;                                  /* L0WUP            */
    unsigned char  L0IE;                                   /* L0IE             */
    unsigned char  L0EDE;                                  /* L0EDE            */
    unsigned char  L0CUC;                                  /* L0CUC            */
    unsigned char  dummy21[1];                             /* Reserved         */
    unsigned char  L0TRC;                                  /* L0TRC            */
    unsigned char  L0MST;                                  /* L0MST            */
    unsigned char  L0ST;                                   /* L0ST             */
    unsigned char  L0EST;                                  /* L0EST            */
    unsigned char  L0DFC;                                  /* L0DFC            */
    unsigned char  L0IDB;                                  /* L0IDB            */
    unsigned char  L0CBR;                                  /* L0CBR            */
    unsigned char  dummy22[1];                             /* Reserved         */
    unsigned char  L0DBR1;                                 /* L0DBR1           */
    unsigned char  L0DBR2;                                 /* L0DBR2           */
    unsigned char  L0DBR3;                                 /* L0DBR3           */
    unsigned char  L0DBR4;                                 /* L0DBR4           */
    unsigned char  L0DBR5;                                 /* L0DBR5           */
    unsigned char  L0DBR6;                                 /* L0DBR6           */
    unsigned char  L0DBR7;                                 /* L0DBR7           */
    unsigned char  L0DBR8;                                 /* L0DBR8           */
};
struct __tag28
{                                                          /* Module           */
    unsigned char  L1MD;                                   /* L1MD             */
    unsigned char  L1BFC;                                  /* L1BFC            */
    unsigned char  L1SC;                                   /* L1SC             */
    unsigned char  L1WUP;                                  /* L1WUP            */
    unsigned char  L1IE;                                   /* L1IE             */
    unsigned char  L1EDE;                                  /* L1EDE            */
    unsigned char  L1CUC;                                  /* L1CUC            */
    unsigned char  dummy23[1];                             /* Reserved         */
    unsigned char  L1TRC;                                  /* L1TRC            */
    unsigned char  L1MST;                                  /* L1MST            */
    unsigned char  L1ST;                                   /* L1ST             */
    unsigned char  L1EST;                                  /* L1EST            */
    unsigned char  L1DFC;                                  /* L1DFC            */
    unsigned char  L1IDB;                                  /* L1IDB            */
    unsigned char  L1CBR;                                  /* L1CBR            */
    unsigned char  dummy24[1];                             /* Reserved         */
    unsigned char  L1DBR1;                                 /* L1DBR1           */
    unsigned char  L1DBR2;                                 /* L1DBR2           */
    unsigned char  L1DBR3;                                 /* L1DBR3           */
    unsigned char  L1DBR4;                                 /* L1DBR4           */
    unsigned char  L1DBR5;                                 /* L1DBR5           */
    unsigned char  L1DBR6;                                 /* L1DBR6           */
    unsigned char  L1DBR7;                                 /* L1DBR7           */
    unsigned char  L1DBR8;                                 /* L1DBR8           */
};
struct __tag29
{                                                          /* Module           */
    unsigned char  L2MD;                                   /* L2MD             */
    unsigned char  L2BFC;                                  /* L2BFC            */
    unsigned char  L2SC;                                   /* L2SC             */
    unsigned char  L2WUP;                                  /* L2WUP            */
    unsigned char  L2IE;                                   /* L2IE             */
    unsigned char  L2EDE;                                  /* L2EDE            */
    unsigned char  L2CUC;                                  /* L2CUC            */
    unsigned char  dummy25[1];                             /* Reserved         */
    unsigned char  L2TRC;                                  /* L2TRC            */
    unsigned char  L2MST;                                  /* L2MST            */
    unsigned char  L2ST;                                   /* L2ST             */
    unsigned char  L2EST;                                  /* L2EST            */
    unsigned char  L2DFC;                                  /* L2DFC            */
    unsigned char  L2IDB;                                  /* L2IDB            */
    unsigned char  L2CBR;                                  /* L2CBR            */
    unsigned char  dummy26[1];                             /* Reserved         */
    unsigned char  L2DBR1;                                 /* L2DBR1           */
    unsigned char  L2DBR2;                                 /* L2DBR2           */
    unsigned char  L2DBR3;                                 /* L2DBR3           */
    unsigned char  L2DBR4;                                 /* L2DBR4           */
    unsigned char  L2DBR5;                                 /* L2DBR5           */
    unsigned char  L2DBR6;                                 /* L2DBR6           */
    unsigned char  L2DBR7;                                 /* L2DBR7           */
    unsigned char  L2DBR8;                                 /* L2DBR8           */
};
struct __tag30
{                                                          /* Module           */
    unsigned char  L3MD;                                   /* L3MD             */
    unsigned char  L3BFC;                                  /* L3BFC            */
    unsigned char  L3SC;                                   /* L3SC             */
    unsigned char  L3WUP;                                  /* L3WUP            */
    unsigned char  L3IE;                                   /* L3IE             */
    unsigned char  L3EDE;                                  /* L3EDE            */
    unsigned char  L3CUC;                                  /* L3CUC            */
    unsigned char  dummy27[1];                             /* Reserved         */
    unsigned char  L3TRC;                                  /* L3TRC            */
    unsigned char  L3MST;                                  /* L3MST            */
    unsigned char  L3ST;                                   /* L3ST             */
    unsigned char  L3EST;                                  /* L3EST            */
    unsigned char  L3DFC;                                  /* L3DFC            */
    unsigned char  L3IDB;                                  /* L3IDB            */
    unsigned char  L3CBR;                                  /* L3CBR            */
    unsigned char  dummy28[1];                             /* Reserved         */
    unsigned char  L3DBR1;                                 /* L3DBR1           */
    unsigned char  L3DBR2;                                 /* L3DBR2           */
    unsigned char  L3DBR3;                                 /* L3DBR3           */
    unsigned char  L3DBR4;                                 /* L3DBR4           */
    unsigned char  L3DBR5;                                 /* L3DBR5           */
    unsigned char  L3DBR6;                                 /* L3DBR6           */
    unsigned char  L3DBR7;                                 /* L3DBR7           */
    unsigned char  L3DBR8;                                 /* L3DBR8           */
};
struct __tag31
{                                                          /* Module           */
    unsigned char  dummy29[1];                             /* Reserved         */
    unsigned char  LWBR;                                   /* LWBR             */
    union __tag9 LBRP01;                                   /* LBRP01           */
    unsigned char  LSTC;                                   /* LSTC             */
    unsigned char  dummy30[3];                             /* Reserved         */
    unsigned char  LMD;                                    /* LMD              */
    unsigned char  LBFC;                                   /* LBFC             */
    unsigned char  LSC;                                    /* LSC              */
    unsigned char  LWUP;                                   /* LWUP             */
    unsigned char  LIE;                                    /* LIE              */
    unsigned char  LEDE;                                   /* LEDE             */
    unsigned char  LCUC;                                   /* LCUC             */
    unsigned char  dummy31[1];                             /* Reserved         */
    unsigned char  LTRC;                                   /* LTRC             */
    unsigned char  LMST;                                   /* LMST             */
    unsigned char  LST;                                    /* LST              */
    unsigned char  LEST;                                   /* LEST             */
    unsigned char  LDFC;                                   /* LDFC             */
    unsigned char  LIDB;                                   /* LIDB             */
    unsigned char  LCBR;                                   /* LCBR             */
    unsigned char  LUDB0;                                  /* LUDB0            */
    unsigned char  LDBR1;                                  /* LDBR1            */
    unsigned char  LDBR2;                                  /* LDBR2            */
    unsigned char  LDBR3;                                  /* LDBR3            */
    unsigned char  LDBR4;                                  /* LDBR4            */
    unsigned char  LDBR5;                                  /* LDBR5            */
    unsigned char  LDBR6;                                  /* LDBR6            */
    unsigned char  LDBR7;                                  /* LDBR7            */
    unsigned char  LDBR8;                                  /* LDBR8            */
    unsigned char  LUOER;                                  /* LUOER            */
    unsigned char  LUOR1;                                  /* LUOR1            */
    unsigned char  dummy32[2];                             /* Reserved         */
    union __tag10 LUTDR;                                   /* LUTDR            */
    union __tag10 LURDR;                                   /* LURDR            */
    union __tag10 LUWTDR;                                  /* LUWTDR           */
};
struct __tag32
{                                                          /* Module           */
    union __tag8 C0CFG;                                    /* C0CFG            */
    union __tag8 C0CTR;                                    /* C0CTR            */
    union __tag8 C0STS;                                    /* C0STS            */
    union __tag8 C0ERFL;                                   /* C0ERFL           */
    union __tag8 C1CFG;                                    /* C1CFG            */
    union __tag8 C1CTR;                                    /* C1CTR            */
    union __tag8 C1STS;                                    /* C1STS            */
    union __tag8 C1ERFL;                                   /* C1ERFL           */
    union __tag8 C2CFG;                                    /* C2CFG            */
    union __tag8 C2CTR;                                    /* C2CTR            */
    union __tag8 C2STS;                                    /* C2STS            */
    union __tag8 C2ERFL;                                   /* C2ERFL           */
    union __tag8 C3CFG;                                    /* C3CFG            */
    union __tag8 C3CTR;                                    /* C3CTR            */
    union __tag8 C3STS;                                    /* C3STS            */
    union __tag8 C3ERFL;                                   /* C3ERFL           */
    union __tag8 C4CFG;                                    /* C4CFG            */
    union __tag8 C4CTR;                                    /* C4CTR            */
    union __tag8 C4STS;                                    /* C4STS            */
    union __tag8 C4ERFL;                                   /* C4ERFL           */
    union __tag8 C5CFG;                                    /* C5CFG            */
    union __tag8 C5CTR;                                    /* C5CTR            */
    union __tag8 C5STS;                                    /* C5STS            */
    union __tag8 C5ERFL;                                   /* C5ERFL           */
    unsigned char  dummy33[36];                            /* Reserved         */
    union __tag8 GCFG;                                     /* GCFG             */
    union __tag8 GCTR;                                     /* GCTR             */
    union __tag8 GSTS;                                     /* GSTS             */
    union __tag8 GERFL;                                    /* GERFL            */
    union __tag11 GTSC;                                    /* GTSC             */
    union __tag8 GAFLECTR;                                 /* GAFLECTR         */
    union __tag8 GAFLCFG0;                                 /* GAFLCFG0         */
    union __tag8 GAFLCFG1;                                 /* GAFLCFG1         */
    union __tag8 RMNB;                                     /* RMNB             */
    union __tag8 RMND0;                                    /* RMND0            */
    union __tag8 RMND1;                                    /* RMND1            */
    union __tag8 RMND2;                                    /* RMND2            */
    unsigned char  dummy34[4];                             /* Reserved         */
    union __tag8 RFCC0;                                    /* RFCC0            */
    union __tag8 RFCC1;                                    /* RFCC1            */
    union __tag8 RFCC2;                                    /* RFCC2            */
    union __tag8 RFCC3;                                    /* RFCC3            */
    union __tag8 RFCC4;                                    /* RFCC4            */
    union __tag8 RFCC5;                                    /* RFCC5            */
    union __tag8 RFCC6;                                    /* RFCC6            */
    union __tag8 RFCC7;                                    /* RFCC7            */
    union __tag8 RFSTS0;                                   /* RFSTS0           */
    union __tag8 RFSTS1;                                   /* RFSTS1           */
    union __tag8 RFSTS2;                                   /* RFSTS2           */
    union __tag8 RFSTS3;                                   /* RFSTS3           */
    union __tag8 RFSTS4;                                   /* RFSTS4           */
    union __tag8 RFSTS5;                                   /* RFSTS5           */
    union __tag8 RFSTS6;                                   /* RFSTS6           */
    union __tag8 RFSTS7;                                   /* RFSTS7           */
    union __tag8 RFPCTR0;                                  /* RFPCTR0          */
    union __tag8 RFPCTR1;                                  /* RFPCTR1          */
    union __tag8 RFPCTR2;                                  /* RFPCTR2          */
    union __tag8 RFPCTR3;                                  /* RFPCTR3          */
    union __tag8 RFPCTR4;                                  /* RFPCTR4          */
    union __tag8 RFPCTR5;                                  /* RFPCTR5          */
    union __tag8 RFPCTR6;                                  /* RFPCTR6          */
    union __tag8 RFPCTR7;                                  /* RFPCTR7          */
    union __tag8 CFCC0;                                    /* CFCC0            */
    union __tag8 CFCC1;                                    /* CFCC1            */
    union __tag8 CFCC2;                                    /* CFCC2            */
    union __tag8 CFCC3;                                    /* CFCC3            */
    union __tag8 CFCC4;                                    /* CFCC4            */
    union __tag8 CFCC5;                                    /* CFCC5            */
    union __tag8 CFCC6;                                    /* CFCC6            */
    union __tag8 CFCC7;                                    /* CFCC7            */
    union __tag8 CFCC8;                                    /* CFCC8            */
    union __tag8 CFCC9;                                    /* CFCC9            */
    union __tag8 CFCC10;                                   /* CFCC10           */
    union __tag8 CFCC11;                                   /* CFCC11           */
    union __tag8 CFCC12;                                   /* CFCC12           */
    union __tag8 CFCC13;                                   /* CFCC13           */
    union __tag8 CFCC14;                                   /* CFCC14           */
    union __tag8 CFCC15;                                   /* CFCC15           */
    union __tag8 CFCC16;                                   /* CFCC16           */
    union __tag8 CFCC17;                                   /* CFCC17           */
    unsigned char  dummy35[24];                            /* Reserved         */
    union __tag8 CFSTS0;                                   /* CFSTS0           */
    union __tag8 CFSTS1;                                   /* CFSTS1           */
    union __tag8 CFSTS2;                                   /* CFSTS2           */
    union __tag8 CFSTS3;                                   /* CFSTS3           */
    union __tag8 CFSTS4;                                   /* CFSTS4           */
    union __tag8 CFSTS5;                                   /* CFSTS5           */
    union __tag8 CFSTS6;                                   /* CFSTS6           */
    union __tag8 CFSTS7;                                   /* CFSTS7           */
    union __tag8 CFSTS8;                                   /* CFSTS8           */
    union __tag8 CFSTS9;                                   /* CFSTS9           */
    union __tag8 CFSTS10;                                  /* CFSTS10          */
    union __tag8 CFSTS11;                                  /* CFSTS11          */
    union __tag8 CFSTS12;                                  /* CFSTS12          */
    union __tag8 CFSTS13;                                  /* CFSTS13          */
    union __tag8 CFSTS14;                                  /* CFSTS14          */
    union __tag8 CFSTS15;                                  /* CFSTS15          */
    union __tag8 CFSTS16;                                  /* CFSTS16          */
    union __tag8 CFSTS17;                                  /* CFSTS17          */
    unsigned char  dummy36[24];                            /* Reserved         */
    union __tag8 CFPCTR0;                                  /* CFPCTR0          */
    union __tag8 CFPCTR1;                                  /* CFPCTR1          */
    union __tag8 CFPCTR2;                                  /* CFPCTR2          */
    union __tag8 CFPCTR3;                                  /* CFPCTR3          */
    union __tag8 CFPCTR4;                                  /* CFPCTR4          */
    union __tag8 CFPCTR5;                                  /* CFPCTR5          */
    union __tag8 CFPCTR6;                                  /* CFPCTR6          */
    union __tag8 CFPCTR7;                                  /* CFPCTR7          */
    union __tag8 CFPCTR8;                                  /* CFPCTR8          */
    union __tag8 CFPCTR9;                                  /* CFPCTR9          */
    union __tag8 CFPCTR10;                                 /* CFPCTR10         */
    union __tag8 CFPCTR11;                                 /* CFPCTR11         */
    union __tag8 CFPCTR12;                                 /* CFPCTR12         */
    union __tag8 CFPCTR13;                                 /* CFPCTR13         */
    union __tag8 CFPCTR14;                                 /* CFPCTR14         */
    union __tag8 CFPCTR15;                                 /* CFPCTR15         */
    union __tag8 CFPCTR16;                                 /* CFPCTR16         */
    union __tag8 CFPCTR17;                                 /* CFPCTR17         */
    unsigned char  dummy37[24];                            /* Reserved         */
    union __tag8 FESTS;                                    /* FESTS            */
    union __tag8 FFSTS;                                    /* FFSTS            */
    union __tag8 FMSTS;                                    /* FMSTS            */
    union __tag8 RFISTS;                                   /* RFISTS           */
    union __tag8 CFRISTS;                                  /* CFRISTS          */
    union __tag8 CFTISTS;                                  /* CFTISTS          */
    unsigned char  TMC0;                                   /* TMC0             */
    unsigned char  TMC1;                                   /* TMC1             */
    unsigned char  TMC2;                                   /* TMC2             */
    unsigned char  TMC3;                                   /* TMC3             */
    unsigned char  TMC4;                                   /* TMC4             */
    unsigned char  TMC5;                                   /* TMC5             */
    unsigned char  TMC6;                                   /* TMC6             */
    unsigned char  TMC7;                                   /* TMC7             */
    unsigned char  TMC8;                                   /* TMC8             */
    unsigned char  TMC9;                                   /* TMC9             */
    unsigned char  TMC10;                                  /* TMC10            */
    unsigned char  TMC11;                                  /* TMC11            */
    unsigned char  TMC12;                                  /* TMC12            */
    unsigned char  TMC13;                                  /* TMC13            */
    unsigned char  TMC14;                                  /* TMC14            */
    unsigned char  TMC15;                                  /* TMC15            */
    unsigned char  TMC16;                                  /* TMC16            */
    unsigned char  TMC17;                                  /* TMC17            */
    unsigned char  TMC18;                                  /* TMC18            */
    unsigned char  TMC19;                                  /* TMC19            */
    unsigned char  TMC20;                                  /* TMC20            */
    unsigned char  TMC21;                                  /* TMC21            */
    unsigned char  TMC22;                                  /* TMC22            */
    unsigned char  TMC23;                                  /* TMC23            */
    unsigned char  TMC24;                                  /* TMC24            */
    unsigned char  TMC25;                                  /* TMC25            */
    unsigned char  TMC26;                                  /* TMC26            */
    unsigned char  TMC27;                                  /* TMC27            */
    unsigned char  TMC28;                                  /* TMC28            */
    unsigned char  TMC29;                                  /* TMC29            */
    unsigned char  TMC30;                                  /* TMC30            */
    unsigned char  TMC31;                                  /* TMC31            */
    unsigned char  TMC32;                                  /* TMC32            */
    unsigned char  TMC33;                                  /* TMC33            */
    unsigned char  TMC34;                                  /* TMC34            */
    unsigned char  TMC35;                                  /* TMC35            */
    unsigned char  TMC36;                                  /* TMC36            */
    unsigned char  TMC37;                                  /* TMC37            */
    unsigned char  TMC38;                                  /* TMC38            */
    unsigned char  TMC39;                                  /* TMC39            */
    unsigned char  TMC40;                                  /* TMC40            */
    unsigned char  TMC41;                                  /* TMC41            */
    unsigned char  TMC42;                                  /* TMC42            */
    unsigned char  TMC43;                                  /* TMC43            */
    unsigned char  TMC44;                                  /* TMC44            */
    unsigned char  TMC45;                                  /* TMC45            */
    unsigned char  TMC46;                                  /* TMC46            */
    unsigned char  TMC47;                                  /* TMC47            */
    unsigned char  TMC48;                                  /* TMC48            */
    unsigned char  TMC49;                                  /* TMC49            */
    unsigned char  TMC50;                                  /* TMC50            */
    unsigned char  TMC51;                                  /* TMC51            */
    unsigned char  TMC52;                                  /* TMC52            */
    unsigned char  TMC53;                                  /* TMC53            */
    unsigned char  TMC54;                                  /* TMC54            */
    unsigned char  TMC55;                                  /* TMC55            */
    unsigned char  TMC56;                                  /* TMC56            */
    unsigned char  TMC57;                                  /* TMC57            */
    unsigned char  TMC58;                                  /* TMC58            */
    unsigned char  TMC59;                                  /* TMC59            */
    unsigned char  TMC60;                                  /* TMC60            */
    unsigned char  TMC61;                                  /* TMC61            */
    unsigned char  TMC62;                                  /* TMC62            */
    unsigned char  TMC63;                                  /* TMC63            */
    unsigned char  TMC64;                                  /* TMC64            */
    unsigned char  TMC65;                                  /* TMC65            */
    unsigned char  TMC66;                                  /* TMC66            */
    unsigned char  TMC67;                                  /* TMC67            */
    unsigned char  TMC68;                                  /* TMC68            */
    unsigned char  TMC69;                                  /* TMC69            */
    unsigned char  TMC70;                                  /* TMC70            */
    unsigned char  TMC71;                                  /* TMC71            */
    unsigned char  TMC72;                                  /* TMC72            */
    unsigned char  TMC73;                                  /* TMC73            */
    unsigned char  TMC74;                                  /* TMC74            */
    unsigned char  TMC75;                                  /* TMC75            */
    unsigned char  TMC76;                                  /* TMC76            */
    unsigned char  TMC77;                                  /* TMC77            */
    unsigned char  TMC78;                                  /* TMC78            */
    unsigned char  TMC79;                                  /* TMC79            */
    unsigned char  TMC80;                                  /* TMC80            */
    unsigned char  TMC81;                                  /* TMC81            */
    unsigned char  TMC82;                                  /* TMC82            */
    unsigned char  TMC83;                                  /* TMC83            */
    unsigned char  TMC84;                                  /* TMC84            */
    unsigned char  TMC85;                                  /* TMC85            */
    unsigned char  TMC86;                                  /* TMC86            */
    unsigned char  TMC87;                                  /* TMC87            */
    unsigned char  TMC88;                                  /* TMC88            */
    unsigned char  TMC89;                                  /* TMC89            */
    unsigned char  TMC90;                                  /* TMC90            */
    unsigned char  TMC91;                                  /* TMC91            */
    unsigned char  TMC92;                                  /* TMC92            */
    unsigned char  TMC93;                                  /* TMC93            */
    unsigned char  TMC94;                                  /* TMC94            */
    unsigned char  TMC95;                                  /* TMC95            */
    unsigned char  dummy38[32];                            /* Reserved         */
    unsigned char  TMSTS0;                                 /* TMSTS0           */
    unsigned char  TMSTS1;                                 /* TMSTS1           */
    unsigned char  TMSTS2;                                 /* TMSTS2           */
    unsigned char  TMSTS3;                                 /* TMSTS3           */
    unsigned char  TMSTS4;                                 /* TMSTS4           */
    unsigned char  TMSTS5;                                 /* TMSTS5           */
    unsigned char  TMSTS6;                                 /* TMSTS6           */
    unsigned char  TMSTS7;                                 /* TMSTS7           */
    unsigned char  TMSTS8;                                 /* TMSTS8           */
    unsigned char  TMSTS9;                                 /* TMSTS9           */
    unsigned char  TMSTS10;                                /* TMSTS10          */
    unsigned char  TMSTS11;                                /* TMSTS11          */
    unsigned char  TMSTS12;                                /* TMSTS12          */
    unsigned char  TMSTS13;                                /* TMSTS13          */
    unsigned char  TMSTS14;                                /* TMSTS14          */
    unsigned char  TMSTS15;                                /* TMSTS15          */
    unsigned char  TMSTS16;                                /* TMSTS16          */
    unsigned char  TMSTS17;                                /* TMSTS17          */
    unsigned char  TMSTS18;                                /* TMSTS18          */
    unsigned char  TMSTS19;                                /* TMSTS19          */
    unsigned char  TMSTS20;                                /* TMSTS20          */
    unsigned char  TMSTS21;                                /* TMSTS21          */
    unsigned char  TMSTS22;                                /* TMSTS22          */
    unsigned char  TMSTS23;                                /* TMSTS23          */
    unsigned char  TMSTS24;                                /* TMSTS24          */
    unsigned char  TMSTS25;                                /* TMSTS25          */
    unsigned char  TMSTS26;                                /* TMSTS26          */
    unsigned char  TMSTS27;                                /* TMSTS27          */
    unsigned char  TMSTS28;                                /* TMSTS28          */
    unsigned char  TMSTS29;                                /* TMSTS29          */
    unsigned char  TMSTS30;                                /* TMSTS30          */
    unsigned char  TMSTS31;                                /* TMSTS31          */
    unsigned char  TMSTS32;                                /* TMSTS32          */
    unsigned char  TMSTS33;                                /* TMSTS33          */
    unsigned char  TMSTS34;                                /* TMSTS34          */
    unsigned char  TMSTS35;                                /* TMSTS35          */
    unsigned char  TMSTS36;                                /* TMSTS36          */
    unsigned char  TMSTS37;                                /* TMSTS37          */
    unsigned char  TMSTS38;                                /* TMSTS38          */
    unsigned char  TMSTS39;                                /* TMSTS39          */
    unsigned char  TMSTS40;                                /* TMSTS40          */
    unsigned char  TMSTS41;                                /* TMSTS41          */
    unsigned char  TMSTS42;                                /* TMSTS42          */
    unsigned char  TMSTS43;                                /* TMSTS43          */
    unsigned char  TMSTS44;                                /* TMSTS44          */
    unsigned char  TMSTS45;                                /* TMSTS45          */
    unsigned char  TMSTS46;                                /* TMSTS46          */
    unsigned char  TMSTS47;                                /* TMSTS47          */
    unsigned char  TMSTS48;                                /* TMSTS48          */
    unsigned char  TMSTS49;                                /* TMSTS49          */
    unsigned char  TMSTS50;                                /* TMSTS50          */
    unsigned char  TMSTS51;                                /* TMSTS51          */
    unsigned char  TMSTS52;                                /* TMSTS52          */
    unsigned char  TMSTS53;                                /* TMSTS53          */
    unsigned char  TMSTS54;                                /* TMSTS54          */
    unsigned char  TMSTS55;                                /* TMSTS55          */
    unsigned char  TMSTS56;                                /* TMSTS56          */
    unsigned char  TMSTS57;                                /* TMSTS57          */
    unsigned char  TMSTS58;                                /* TMSTS58          */
    unsigned char  TMSTS59;                                /* TMSTS59          */
    unsigned char  TMSTS60;                                /* TMSTS60          */
    unsigned char  TMSTS61;                                /* TMSTS61          */
    unsigned char  TMSTS62;                                /* TMSTS62          */
    unsigned char  TMSTS63;                                /* TMSTS63          */
    unsigned char  TMSTS64;                                /* TMSTS64          */
    unsigned char  TMSTS65;                                /* TMSTS65          */
    unsigned char  TMSTS66;                                /* TMSTS66          */
    unsigned char  TMSTS67;                                /* TMSTS67          */
    unsigned char  TMSTS68;                                /* TMSTS68          */
    unsigned char  TMSTS69;                                /* TMSTS69          */
    unsigned char  TMSTS70;                                /* TMSTS70          */
    unsigned char  TMSTS71;                                /* TMSTS71          */
    unsigned char  TMSTS72;                                /* TMSTS72          */
    unsigned char  TMSTS73;                                /* TMSTS73          */
    unsigned char  TMSTS74;                                /* TMSTS74          */
    unsigned char  TMSTS75;                                /* TMSTS75          */
    unsigned char  TMSTS76;                                /* TMSTS76          */
    unsigned char  TMSTS77;                                /* TMSTS77          */
    unsigned char  TMSTS78;                                /* TMSTS78          */
    unsigned char  TMSTS79;                                /* TMSTS79          */
    unsigned char  TMSTS80;                                /* TMSTS80          */
    unsigned char  TMSTS81;                                /* TMSTS81          */
    unsigned char  TMSTS82;                                /* TMSTS82          */
    unsigned char  TMSTS83;                                /* TMSTS83          */
    unsigned char  TMSTS84;                                /* TMSTS84          */
    unsigned char  TMSTS85;                                /* TMSTS85          */
    unsigned char  TMSTS86;                                /* TMSTS86          */
    unsigned char  TMSTS87;                                /* TMSTS87          */
    unsigned char  TMSTS88;                                /* TMSTS88          */
    unsigned char  TMSTS89;                                /* TMSTS89          */
    unsigned char  TMSTS90;                                /* TMSTS90          */
    unsigned char  TMSTS91;                                /* TMSTS91          */
    unsigned char  TMSTS92;                                /* TMSTS92          */
    unsigned char  TMSTS93;                                /* TMSTS93          */
    unsigned char  TMSTS94;                                /* TMSTS94          */
    unsigned char  TMSTS95;                                /* TMSTS95          */
    unsigned char  dummy39[32];                            /* Reserved         */
    union __tag8 TMTRSTS0;                                 /* TMTRSTS0         */
    union __tag8 TMTRSTS1;                                 /* TMTRSTS1         */
    union __tag8 TMTRSTS2;                                 /* TMTRSTS2         */
    unsigned char  dummy40[4];                             /* Reserved         */
    union __tag8 TMTARSTS0;                                /* TMTARSTS0        */
    union __tag8 TMTARSTS1;                                /* TMTARSTS1        */
    union __tag8 TMTARSTS2;                                /* TMTARSTS2        */
    unsigned char  dummy41[4];                             /* Reserved         */
    union __tag8 TMTCSTS0;                                 /* TMTCSTS0         */
    union __tag8 TMTCSTS1;                                 /* TMTCSTS1         */
    union __tag8 TMTCSTS2;                                 /* TMTCSTS2         */
    unsigned char  dummy42[4];                             /* Reserved         */
    union __tag8 TMTASTS0;                                 /* TMTASTS0         */
    union __tag8 TMTASTS1;                                 /* TMTASTS1         */
    union __tag8 TMTASTS2;                                 /* TMTASTS2         */
    unsigned char  dummy43[4];                             /* Reserved         */
    union __tag8 TMIEC0;                                   /* TMIEC0           */
    union __tag8 TMIEC1;                                   /* TMIEC1           */
    union __tag8 TMIEC2;                                   /* TMIEC2           */
    unsigned char  dummy44[4];                             /* Reserved         */
    union __tag8 TXQCC0;                                   /* TXQCC0           */
    union __tag8 TXQCC1;                                   /* TXQCC1           */
    union __tag8 TXQCC2;                                   /* TXQCC2           */
    union __tag8 TXQCC3;                                   /* TXQCC3           */
    union __tag8 TXQCC4;                                   /* TXQCC4           */
    union __tag8 TXQCC5;                                   /* TXQCC5           */
    unsigned char  dummy45[8];                             /* Reserved         */
    union __tag8 TXQSTS0;                                  /* TXQSTS0          */
    union __tag8 TXQSTS1;                                  /* TXQSTS1          */
    union __tag8 TXQSTS2;                                  /* TXQSTS2          */
    union __tag8 TXQSTS3;                                  /* TXQSTS3          */
    union __tag8 TXQSTS4;                                  /* TXQSTS4          */
    union __tag8 TXQSTS5;                                  /* TXQSTS5          */
    unsigned char  dummy46[8];                             /* Reserved         */
    union __tag8 TXQPCTR0;                                 /* TXQPCTR0         */
    union __tag8 TXQPCTR1;                                 /* TXQPCTR1         */
    union __tag8 TXQPCTR2;                                 /* TXQPCTR2         */
    union __tag8 TXQPCTR3;                                 /* TXQPCTR3         */
    union __tag8 TXQPCTR4;                                 /* TXQPCTR4         */
    union __tag8 TXQPCTR5;                                 /* TXQPCTR5         */
    unsigned char  dummy47[8];                             /* Reserved         */
    union __tag8 THLCC0;                                   /* THLCC0           */
    union __tag8 THLCC1;                                   /* THLCC1           */
    union __tag8 THLCC2;                                   /* THLCC2           */
    union __tag8 THLCC3;                                   /* THLCC3           */
    union __tag8 THLCC4;                                   /* THLCC4           */
    union __tag8 THLCC5;                                   /* THLCC5           */
    unsigned char  dummy48[8];                             /* Reserved         */
    union __tag8 THLSTS0;                                  /* THLSTS0          */
    union __tag8 THLSTS1;                                  /* THLSTS1          */
    union __tag8 THLSTS2;                                  /* THLSTS2          */
    union __tag8 THLSTS3;                                  /* THLSTS3          */
    union __tag8 THLSTS4;                                  /* THLSTS4          */
    union __tag8 THLSTS5;                                  /* THLSTS5          */
    unsigned char  dummy49[8];                             /* Reserved         */
    union __tag8 THLPCTR0;                                 /* THLPCTR0         */
    union __tag8 THLPCTR1;                                 /* THLPCTR1         */
    union __tag8 THLPCTR2;                                 /* THLPCTR2         */
    union __tag8 THLPCTR3;                                 /* THLPCTR3         */
    union __tag8 THLPCTR4;                                 /* THLPCTR4         */
    union __tag8 THLPCTR5;                                 /* THLPCTR5         */
    unsigned char  dummy50[8];                             /* Reserved         */
    union __tag8 GTINTSTS0;                                /* GTINTSTS0        */
    union __tag8 GTINTSTS1;                                /* GTINTSTS1        */
    union __tag8 GTSTCFG;                                  /* GTSTCFG          */
    union __tag8 GTSTCTR;                                  /* GTSTCTR          */
    unsigned char  dummy51[12];                            /* Reserved         */
    union __tag11 GLOCKK;                                  /* GLOCKK           */
    unsigned char  dummy52[128];                           /* Reserved         */
    union __tag8 GAFLID0;                                  /* GAFLID0          */
    union __tag8 GAFLM0;                                   /* GAFLM0           */
    union __tag8 GAFLP00;                                  /* GAFLP00          */
    union __tag8 GAFLP10;                                  /* GAFLP10          */
    union __tag8 GAFLID1;                                  /* GAFLID1          */
    union __tag8 GAFLM1;                                   /* GAFLM1           */
    union __tag8 GAFLP01;                                  /* GAFLP01          */
    union __tag8 GAFLP11;                                  /* GAFLP11          */
    union __tag8 GAFLID2;                                  /* GAFLID2          */
    union __tag8 GAFLM2;                                   /* GAFLM2           */
    union __tag8 GAFLP02;                                  /* GAFLP02          */
    union __tag8 GAFLP12;                                  /* GAFLP12          */
    union __tag8 GAFLID3;                                  /* GAFLID3          */
    union __tag8 GAFLM3;                                   /* GAFLM3           */
    union __tag8 GAFLP03;                                  /* GAFLP03          */
    union __tag8 GAFLP13;                                  /* GAFLP13          */
    union __tag8 GAFLID4;                                  /* GAFLID4          */
    union __tag8 GAFLM4;                                   /* GAFLM4           */
    union __tag8 GAFLP04;                                  /* GAFLP04          */
    union __tag8 GAFLP14;                                  /* GAFLP14          */
    union __tag8 GAFLID5;                                  /* GAFLID5          */
    union __tag8 GAFLM5;                                   /* GAFLM5           */
    union __tag8 GAFLP05;                                  /* GAFLP05          */
    union __tag8 GAFLP15;                                  /* GAFLP15          */
    union __tag8 GAFLID6;                                  /* GAFLID6          */
    union __tag8 GAFLM6;                                   /* GAFLM6           */
    union __tag8 GAFLP06;                                  /* GAFLP06          */
    union __tag8 GAFLP16;                                  /* GAFLP16          */
    union __tag8 GAFLID7;                                  /* GAFLID7          */
    union __tag8 GAFLM7;                                   /* GAFLM7           */
    union __tag8 GAFLP07;                                  /* GAFLP07          */
    union __tag8 GAFLP17;                                  /* GAFLP17          */
    union __tag8 GAFLID8;                                  /* GAFLID8          */
    union __tag8 GAFLM8;                                   /* GAFLM8           */
    union __tag8 GAFLP08;                                  /* GAFLP08          */
    union __tag8 GAFLP18;                                  /* GAFLP18          */
    union __tag8 GAFLID9;                                  /* GAFLID9          */
    union __tag8 GAFLM9;                                   /* GAFLM9           */
    union __tag8 GAFLP09;                                  /* GAFLP09          */
    union __tag8 GAFLP19;                                  /* GAFLP19          */
    union __tag8 GAFLID10;                                 /* GAFLID10         */
    union __tag8 GAFLM10;                                  /* GAFLM10          */
    union __tag8 GAFLP010;                                 /* GAFLP010         */
    union __tag8 GAFLP110;                                 /* GAFLP110         */
    union __tag8 GAFLID11;                                 /* GAFLID11         */
    union __tag8 GAFLM11;                                  /* GAFLM11          */
    union __tag8 GAFLP011;                                 /* GAFLP011         */
    union __tag8 GAFLP111;                                 /* GAFLP111         */
    union __tag8 GAFLID12;                                 /* GAFLID12         */
    union __tag8 GAFLM12;                                  /* GAFLM12          */
    union __tag8 GAFLP012;                                 /* GAFLP012         */
    union __tag8 GAFLP112;                                 /* GAFLP112         */
    union __tag8 GAFLID13;                                 /* GAFLID13         */
    union __tag8 GAFLM13;                                  /* GAFLM13          */
    union __tag8 GAFLP013;                                 /* GAFLP013         */
    union __tag8 GAFLP113;                                 /* GAFLP113         */
    union __tag8 GAFLID14;                                 /* GAFLID14         */
    union __tag8 GAFLM14;                                  /* GAFLM14          */
    union __tag8 GAFLP014;                                 /* GAFLP014         */
    union __tag8 GAFLP114;                                 /* GAFLP114         */
    union __tag8 GAFLID15;                                 /* GAFLID15         */
    union __tag8 GAFLM15;                                  /* GAFLM15          */
    union __tag8 GAFLP015;                                 /* GAFLP015         */
    union __tag8 GAFLP115;                                 /* GAFLP115         */
    union __tag8 RMID0;                                    /* RMID0            */
    union __tag8 RMPTR0;                                   /* RMPTR0           */
    union __tag8 RMDF00;                                   /* RMDF00           */
    union __tag8 RMDF10;                                   /* RMDF10           */
    union __tag8 RMID1;                                    /* RMID1            */
    union __tag8 RMPTR1;                                   /* RMPTR1           */
    union __tag8 RMDF01;                                   /* RMDF01           */
    union __tag8 RMDF11;                                   /* RMDF11           */
    union __tag8 RMID2;                                    /* RMID2            */
    union __tag8 RMPTR2;                                   /* RMPTR2           */
    union __tag8 RMDF02;                                   /* RMDF02           */
    union __tag8 RMDF12;                                   /* RMDF12           */
    union __tag8 RMID3;                                    /* RMID3            */
    union __tag8 RMPTR3;                                   /* RMPTR3           */
    union __tag8 RMDF03;                                   /* RMDF03           */
    union __tag8 RMDF13;                                   /* RMDF13           */
    union __tag8 RMID4;                                    /* RMID4            */
    union __tag8 RMPTR4;                                   /* RMPTR4           */
    union __tag8 RMDF04;                                   /* RMDF04           */
    union __tag8 RMDF14;                                   /* RMDF14           */
    union __tag8 RMID5;                                    /* RMID5            */
    union __tag8 RMPTR5;                                   /* RMPTR5           */
    union __tag8 RMDF05;                                   /* RMDF05           */
    union __tag8 RMDF15;                                   /* RMDF15           */
    union __tag8 RMID6;                                    /* RMID6            */
    union __tag8 RMPTR6;                                   /* RMPTR6           */
    union __tag8 RMDF06;                                   /* RMDF06           */
    union __tag8 RMDF16;                                   /* RMDF16           */
    union __tag8 RMID7;                                    /* RMID7            */
    union __tag8 RMPTR7;                                   /* RMPTR7           */
    union __tag8 RMDF07;                                   /* RMDF07           */
    union __tag8 RMDF17;                                   /* RMDF17           */
    union __tag8 RMID8;                                    /* RMID8            */
    union __tag8 RMPTR8;                                   /* RMPTR8           */
    union __tag8 RMDF08;                                   /* RMDF08           */
    union __tag8 RMDF18;                                   /* RMDF18           */
    union __tag8 RMID9;                                    /* RMID9            */
    union __tag8 RMPTR9;                                   /* RMPTR9           */
    union __tag8 RMDF09;                                   /* RMDF09           */
    union __tag8 RMDF19;                                   /* RMDF19           */
    union __tag8 RMID10;                                   /* RMID10           */
    union __tag8 RMPTR10;                                  /* RMPTR10          */
    union __tag8 RMDF010;                                  /* RMDF010          */
    union __tag8 RMDF110;                                  /* RMDF110          */
    union __tag8 RMID11;                                   /* RMID11           */
    union __tag8 RMPTR11;                                  /* RMPTR11          */
    union __tag8 RMDF011;                                  /* RMDF011          */
    union __tag8 RMDF111;                                  /* RMDF111          */
    union __tag8 RMID12;                                   /* RMID12           */
    union __tag8 RMPTR12;                                  /* RMPTR12          */
    union __tag8 RMDF012;                                  /* RMDF012          */
    union __tag8 RMDF112;                                  /* RMDF112          */
    union __tag8 RMID13;                                   /* RMID13           */
    union __tag8 RMPTR13;                                  /* RMPTR13          */
    union __tag8 RMDF013;                                  /* RMDF013          */
    union __tag8 RMDF113;                                  /* RMDF113          */
    union __tag8 RMID14;                                   /* RMID14           */
    union __tag8 RMPTR14;                                  /* RMPTR14          */
    union __tag8 RMDF014;                                  /* RMDF014          */
    union __tag8 RMDF114;                                  /* RMDF114          */
    union __tag8 RMID15;                                   /* RMID15           */
    union __tag8 RMPTR15;                                  /* RMPTR15          */
    union __tag8 RMDF015;                                  /* RMDF015          */
    union __tag8 RMDF115;                                  /* RMDF115          */
    union __tag8 RMID16;                                   /* RMID16           */
    union __tag8 RMPTR16;                                  /* RMPTR16          */
    union __tag8 RMDF016;                                  /* RMDF016          */
    union __tag8 RMDF116;                                  /* RMDF116          */
    union __tag8 RMID17;                                   /* RMID17           */
    union __tag8 RMPTR17;                                  /* RMPTR17          */
    union __tag8 RMDF017;                                  /* RMDF017          */
    union __tag8 RMDF117;                                  /* RMDF117          */
    union __tag8 RMID18;                                   /* RMID18           */
    union __tag8 RMPTR18;                                  /* RMPTR18          */
    union __tag8 RMDF018;                                  /* RMDF018          */
    union __tag8 RMDF118;                                  /* RMDF118          */
    union __tag8 RMID19;                                   /* RMID19           */
    union __tag8 RMPTR19;                                  /* RMPTR19          */
    union __tag8 RMDF019;                                  /* RMDF019          */
    union __tag8 RMDF119;                                  /* RMDF119          */
    union __tag8 RMID20;                                   /* RMID20           */
    union __tag8 RMPTR20;                                  /* RMPTR20          */
    union __tag8 RMDF020;                                  /* RMDF020          */
    union __tag8 RMDF120;                                  /* RMDF120          */
    union __tag8 RMID21;                                   /* RMID21           */
    union __tag8 RMPTR21;                                  /* RMPTR21          */
    union __tag8 RMDF021;                                  /* RMDF021          */
    union __tag8 RMDF121;                                  /* RMDF121          */
    union __tag8 RMID22;                                   /* RMID22           */
    union __tag8 RMPTR22;                                  /* RMPTR22          */
    union __tag8 RMDF022;                                  /* RMDF022          */
    union __tag8 RMDF122;                                  /* RMDF122          */
    union __tag8 RMID23;                                   /* RMID23           */
    union __tag8 RMPTR23;                                  /* RMPTR23          */
    union __tag8 RMDF023;                                  /* RMDF023          */
    union __tag8 RMDF123;                                  /* RMDF123          */
    union __tag8 RMID24;                                   /* RMID24           */
    union __tag8 RMPTR24;                                  /* RMPTR24          */
    union __tag8 RMDF024;                                  /* RMDF024          */
    union __tag8 RMDF124;                                  /* RMDF124          */
    union __tag8 RMID25;                                   /* RMID25           */
    union __tag8 RMPTR25;                                  /* RMPTR25          */
    union __tag8 RMDF025;                                  /* RMDF025          */
    union __tag8 RMDF125;                                  /* RMDF125          */
    union __tag8 RMID26;                                   /* RMID26           */
    union __tag8 RMPTR26;                                  /* RMPTR26          */
    union __tag8 RMDF026;                                  /* RMDF026          */
    union __tag8 RMDF126;                                  /* RMDF126          */
    union __tag8 RMID27;                                   /* RMID27           */
    union __tag8 RMPTR27;                                  /* RMPTR27          */
    union __tag8 RMDF027;                                  /* RMDF027          */
    union __tag8 RMDF127;                                  /* RMDF127          */
    union __tag8 RMID28;                                   /* RMID28           */
    union __tag8 RMPTR28;                                  /* RMPTR28          */
    union __tag8 RMDF028;                                  /* RMDF028          */
    union __tag8 RMDF128;                                  /* RMDF128          */
    union __tag8 RMID29;                                   /* RMID29           */
    union __tag8 RMPTR29;                                  /* RMPTR29          */
    union __tag8 RMDF029;                                  /* RMDF029          */
    union __tag8 RMDF129;                                  /* RMDF129          */
    union __tag8 RMID30;                                   /* RMID30           */
    union __tag8 RMPTR30;                                  /* RMPTR30          */
    union __tag8 RMDF030;                                  /* RMDF030          */
    union __tag8 RMDF130;                                  /* RMDF130          */
    union __tag8 RMID31;                                   /* RMID31           */
    union __tag8 RMPTR31;                                  /* RMPTR31          */
    union __tag8 RMDF031;                                  /* RMDF031          */
    union __tag8 RMDF131;                                  /* RMDF131          */
    union __tag8 RMID32;                                   /* RMID32           */
    union __tag8 RMPTR32;                                  /* RMPTR32          */
    union __tag8 RMDF032;                                  /* RMDF032          */
    union __tag8 RMDF132;                                  /* RMDF132          */
    union __tag8 RMID33;                                   /* RMID33           */
    union __tag8 RMPTR33;                                  /* RMPTR33          */
    union __tag8 RMDF033;                                  /* RMDF033          */
    union __tag8 RMDF133;                                  /* RMDF133          */
    union __tag8 RMID34;                                   /* RMID34           */
    union __tag8 RMPTR34;                                  /* RMPTR34          */
    union __tag8 RMDF034;                                  /* RMDF034          */
    union __tag8 RMDF134;                                  /* RMDF134          */
    union __tag8 RMID35;                                   /* RMID35           */
    union __tag8 RMPTR35;                                  /* RMPTR35          */
    union __tag8 RMDF035;                                  /* RMDF035          */
    union __tag8 RMDF135;                                  /* RMDF135          */
    union __tag8 RMID36;                                   /* RMID36           */
    union __tag8 RMPTR36;                                  /* RMPTR36          */
    union __tag8 RMDF036;                                  /* RMDF036          */
    union __tag8 RMDF136;                                  /* RMDF136          */
    union __tag8 RMID37;                                   /* RMID37           */
    union __tag8 RMPTR37;                                  /* RMPTR37          */
    union __tag8 RMDF037;                                  /* RMDF037          */
    union __tag8 RMDF137;                                  /* RMDF137          */
    union __tag8 RMID38;                                   /* RMID38           */
    union __tag8 RMPTR38;                                  /* RMPTR38          */
    union __tag8 RMDF038;                                  /* RMDF038          */
    union __tag8 RMDF138;                                  /* RMDF138          */
    union __tag8 RMID39;                                   /* RMID39           */
    union __tag8 RMPTR39;                                  /* RMPTR39          */
    union __tag8 RMDF039;                                  /* RMDF039          */
    union __tag8 RMDF139;                                  /* RMDF139          */
    union __tag8 RMID40;                                   /* RMID40           */
    union __tag8 RMPTR40;                                  /* RMPTR40          */
    union __tag8 RMDF040;                                  /* RMDF040          */
    union __tag8 RMDF140;                                  /* RMDF140          */
    union __tag8 RMID41;                                   /* RMID41           */
    union __tag8 RMPTR41;                                  /* RMPTR41          */
    union __tag8 RMDF041;                                  /* RMDF041          */
    union __tag8 RMDF141;                                  /* RMDF141          */
    union __tag8 RMID42;                                   /* RMID42           */
    union __tag8 RMPTR42;                                  /* RMPTR42          */
    union __tag8 RMDF042;                                  /* RMDF042          */
    union __tag8 RMDF142;                                  /* RMDF142          */
    union __tag8 RMID43;                                   /* RMID43           */
    union __tag8 RMPTR43;                                  /* RMPTR43          */
    union __tag8 RMDF043;                                  /* RMDF043          */
    union __tag8 RMDF143;                                  /* RMDF143          */
    union __tag8 RMID44;                                   /* RMID44           */
    union __tag8 RMPTR44;                                  /* RMPTR44          */
    union __tag8 RMDF044;                                  /* RMDF044          */
    union __tag8 RMDF144;                                  /* RMDF144          */
    union __tag8 RMID45;                                   /* RMID45           */
    union __tag8 RMPTR45;                                  /* RMPTR45          */
    union __tag8 RMDF045;                                  /* RMDF045          */
    union __tag8 RMDF145;                                  /* RMDF145          */
    union __tag8 RMID46;                                   /* RMID46           */
    union __tag8 RMPTR46;                                  /* RMPTR46          */
    union __tag8 RMDF046;                                  /* RMDF046          */
    union __tag8 RMDF146;                                  /* RMDF146          */
    union __tag8 RMID47;                                   /* RMID47           */
    union __tag8 RMPTR47;                                  /* RMPTR47          */
    union __tag8 RMDF047;                                  /* RMDF047          */
    union __tag8 RMDF147;                                  /* RMDF147          */
    union __tag8 RMID48;                                   /* RMID48           */
    union __tag8 RMPTR48;                                  /* RMPTR48          */
    union __tag8 RMDF048;                                  /* RMDF048          */
    union __tag8 RMDF148;                                  /* RMDF148          */
    union __tag8 RMID49;                                   /* RMID49           */
    union __tag8 RMPTR49;                                  /* RMPTR49          */
    union __tag8 RMDF049;                                  /* RMDF049          */
    union __tag8 RMDF149;                                  /* RMDF149          */
    union __tag8 RMID50;                                   /* RMID50           */
    union __tag8 RMPTR50;                                  /* RMPTR50          */
    union __tag8 RMDF050;                                  /* RMDF050          */
    union __tag8 RMDF150;                                  /* RMDF150          */
    union __tag8 RMID51;                                   /* RMID51           */
    union __tag8 RMPTR51;                                  /* RMPTR51          */
    union __tag8 RMDF051;                                  /* RMDF051          */
    union __tag8 RMDF151;                                  /* RMDF151          */
    union __tag8 RMID52;                                   /* RMID52           */
    union __tag8 RMPTR52;                                  /* RMPTR52          */
    union __tag8 RMDF052;                                  /* RMDF052          */
    union __tag8 RMDF152;                                  /* RMDF152          */
    union __tag8 RMID53;                                   /* RMID53           */
    union __tag8 RMPTR53;                                  /* RMPTR53          */
    union __tag8 RMDF053;                                  /* RMDF053          */
    union __tag8 RMDF153;                                  /* RMDF153          */
    union __tag8 RMID54;                                   /* RMID54           */
    union __tag8 RMPTR54;                                  /* RMPTR54          */
    union __tag8 RMDF054;                                  /* RMDF054          */
    union __tag8 RMDF154;                                  /* RMDF154          */
    union __tag8 RMID55;                                   /* RMID55           */
    union __tag8 RMPTR55;                                  /* RMPTR55          */
    union __tag8 RMDF055;                                  /* RMDF055          */
    union __tag8 RMDF155;                                  /* RMDF155          */
    union __tag8 RMID56;                                   /* RMID56           */
    union __tag8 RMPTR56;                                  /* RMPTR56          */
    union __tag8 RMDF056;                                  /* RMDF056          */
    union __tag8 RMDF156;                                  /* RMDF156          */
    union __tag8 RMID57;                                   /* RMID57           */
    union __tag8 RMPTR57;                                  /* RMPTR57          */
    union __tag8 RMDF057;                                  /* RMDF057          */
    union __tag8 RMDF157;                                  /* RMDF157          */
    union __tag8 RMID58;                                   /* RMID58           */
    union __tag8 RMPTR58;                                  /* RMPTR58          */
    union __tag8 RMDF058;                                  /* RMDF058          */
    union __tag8 RMDF158;                                  /* RMDF158          */
    union __tag8 RMID59;                                   /* RMID59           */
    union __tag8 RMPTR59;                                  /* RMPTR59          */
    union __tag8 RMDF059;                                  /* RMDF059          */
    union __tag8 RMDF159;                                  /* RMDF159          */
    union __tag8 RMID60;                                   /* RMID60           */
    union __tag8 RMPTR60;                                  /* RMPTR60          */
    union __tag8 RMDF060;                                  /* RMDF060          */
    union __tag8 RMDF160;                                  /* RMDF160          */
    union __tag8 RMID61;                                   /* RMID61           */
    union __tag8 RMPTR61;                                  /* RMPTR61          */
    union __tag8 RMDF061;                                  /* RMDF061          */
    union __tag8 RMDF161;                                  /* RMDF161          */
    union __tag8 RMID62;                                   /* RMID62           */
    union __tag8 RMPTR62;                                  /* RMPTR62          */
    union __tag8 RMDF062;                                  /* RMDF062          */
    union __tag8 RMDF162;                                  /* RMDF162          */
    union __tag8 RMID63;                                   /* RMID63           */
    union __tag8 RMPTR63;                                  /* RMPTR63          */
    union __tag8 RMDF063;                                  /* RMDF063          */
    union __tag8 RMDF163;                                  /* RMDF163          */
    union __tag8 RMID64;                                   /* RMID64           */
    union __tag8 RMPTR64;                                  /* RMPTR64          */
    union __tag8 RMDF064;                                  /* RMDF064          */
    union __tag8 RMDF164;                                  /* RMDF164          */
    union __tag8 RMID65;                                   /* RMID65           */
    union __tag8 RMPTR65;                                  /* RMPTR65          */
    union __tag8 RMDF065;                                  /* RMDF065          */
    union __tag8 RMDF165;                                  /* RMDF165          */
    union __tag8 RMID66;                                   /* RMID66           */
    union __tag8 RMPTR66;                                  /* RMPTR66          */
    union __tag8 RMDF066;                                  /* RMDF066          */
    union __tag8 RMDF166;                                  /* RMDF166          */
    union __tag8 RMID67;                                   /* RMID67           */
    union __tag8 RMPTR67;                                  /* RMPTR67          */
    union __tag8 RMDF067;                                  /* RMDF067          */
    union __tag8 RMDF167;                                  /* RMDF167          */
    union __tag8 RMID68;                                   /* RMID68           */
    union __tag8 RMPTR68;                                  /* RMPTR68          */
    union __tag8 RMDF068;                                  /* RMDF068          */
    union __tag8 RMDF168;                                  /* RMDF168          */
    union __tag8 RMID69;                                   /* RMID69           */
    union __tag8 RMPTR69;                                  /* RMPTR69          */
    union __tag8 RMDF069;                                  /* RMDF069          */
    union __tag8 RMDF169;                                  /* RMDF169          */
    union __tag8 RMID70;                                   /* RMID70           */
    union __tag8 RMPTR70;                                  /* RMPTR70          */
    union __tag8 RMDF070;                                  /* RMDF070          */
    union __tag8 RMDF170;                                  /* RMDF170          */
    union __tag8 RMID71;                                   /* RMID71           */
    union __tag8 RMPTR71;                                  /* RMPTR71          */
    union __tag8 RMDF071;                                  /* RMDF071          */
    union __tag8 RMDF171;                                  /* RMDF171          */
    union __tag8 RMID72;                                   /* RMID72           */
    union __tag8 RMPTR72;                                  /* RMPTR72          */
    union __tag8 RMDF072;                                  /* RMDF072          */
    union __tag8 RMDF172;                                  /* RMDF172          */
    union __tag8 RMID73;                                   /* RMID73           */
    union __tag8 RMPTR73;                                  /* RMPTR73          */
    union __tag8 RMDF073;                                  /* RMDF073          */
    union __tag8 RMDF173;                                  /* RMDF173          */
    union __tag8 RMID74;                                   /* RMID74           */
    union __tag8 RMPTR74;                                  /* RMPTR74          */
    union __tag8 RMDF074;                                  /* RMDF074          */
    union __tag8 RMDF174;                                  /* RMDF174          */
    union __tag8 RMID75;                                   /* RMID75           */
    union __tag8 RMPTR75;                                  /* RMPTR75          */
    union __tag8 RMDF075;                                  /* RMDF075          */
    union __tag8 RMDF175;                                  /* RMDF175          */
    union __tag8 RMID76;                                   /* RMID76           */
    union __tag8 RMPTR76;                                  /* RMPTR76          */
    union __tag8 RMDF076;                                  /* RMDF076          */
    union __tag8 RMDF176;                                  /* RMDF176          */
    union __tag8 RMID77;                                   /* RMID77           */
    union __tag8 RMPTR77;                                  /* RMPTR77          */
    union __tag8 RMDF077;                                  /* RMDF077          */
    union __tag8 RMDF177;                                  /* RMDF177          */
    union __tag8 RMID78;                                   /* RMID78           */
    union __tag8 RMPTR78;                                  /* RMPTR78          */
    union __tag8 RMDF078;                                  /* RMDF078          */
    union __tag8 RMDF178;                                  /* RMDF178          */
    union __tag8 RMID79;                                   /* RMID79           */
    union __tag8 RMPTR79;                                  /* RMPTR79          */
    union __tag8 RMDF079;                                  /* RMDF079          */
    union __tag8 RMDF179;                                  /* RMDF179          */
    union __tag8 RMID80;                                   /* RMID80           */
    union __tag8 RMPTR80;                                  /* RMPTR80          */
    union __tag8 RMDF080;                                  /* RMDF080          */
    union __tag8 RMDF180;                                  /* RMDF180          */
    union __tag8 RMID81;                                   /* RMID81           */
    union __tag8 RMPTR81;                                  /* RMPTR81          */
    union __tag8 RMDF081;                                  /* RMDF081          */
    union __tag8 RMDF181;                                  /* RMDF181          */
    union __tag8 RMID82;                                   /* RMID82           */
    union __tag8 RMPTR82;                                  /* RMPTR82          */
    union __tag8 RMDF082;                                  /* RMDF082          */
    union __tag8 RMDF182;                                  /* RMDF182          */
    union __tag8 RMID83;                                   /* RMID83           */
    union __tag8 RMPTR83;                                  /* RMPTR83          */
    union __tag8 RMDF083;                                  /* RMDF083          */
    union __tag8 RMDF183;                                  /* RMDF183          */
    union __tag8 RMID84;                                   /* RMID84           */
    union __tag8 RMPTR84;                                  /* RMPTR84          */
    union __tag8 RMDF084;                                  /* RMDF084          */
    union __tag8 RMDF184;                                  /* RMDF184          */
    union __tag8 RMID85;                                   /* RMID85           */
    union __tag8 RMPTR85;                                  /* RMPTR85          */
    union __tag8 RMDF085;                                  /* RMDF085          */
    union __tag8 RMDF185;                                  /* RMDF185          */
    union __tag8 RMID86;                                   /* RMID86           */
    union __tag8 RMPTR86;                                  /* RMPTR86          */
    union __tag8 RMDF086;                                  /* RMDF086          */
    union __tag8 RMDF186;                                  /* RMDF186          */
    union __tag8 RMID87;                                   /* RMID87           */
    union __tag8 RMPTR87;                                  /* RMPTR87          */
    union __tag8 RMDF087;                                  /* RMDF087          */
    union __tag8 RMDF187;                                  /* RMDF187          */
    union __tag8 RMID88;                                   /* RMID88           */
    union __tag8 RMPTR88;                                  /* RMPTR88          */
    union __tag8 RMDF088;                                  /* RMDF088          */
    union __tag8 RMDF188;                                  /* RMDF188          */
    union __tag8 RMID89;                                   /* RMID89           */
    union __tag8 RMPTR89;                                  /* RMPTR89          */
    union __tag8 RMDF089;                                  /* RMDF089          */
    union __tag8 RMDF189;                                  /* RMDF189          */
    union __tag8 RMID90;                                   /* RMID90           */
    union __tag8 RMPTR90;                                  /* RMPTR90          */
    union __tag8 RMDF090;                                  /* RMDF090          */
    union __tag8 RMDF190;                                  /* RMDF190          */
    union __tag8 RMID91;                                   /* RMID91           */
    union __tag8 RMPTR91;                                  /* RMPTR91          */
    union __tag8 RMDF091;                                  /* RMDF091          */
    union __tag8 RMDF191;                                  /* RMDF191          */
    union __tag8 RMID92;                                   /* RMID92           */
    union __tag8 RMPTR92;                                  /* RMPTR92          */
    union __tag8 RMDF092;                                  /* RMDF092          */
    union __tag8 RMDF192;                                  /* RMDF192          */
    union __tag8 RMID93;                                   /* RMID93           */
    union __tag8 RMPTR93;                                  /* RMPTR93          */
    union __tag8 RMDF093;                                  /* RMDF093          */
    union __tag8 RMDF193;                                  /* RMDF193          */
    union __tag8 RMID94;                                   /* RMID94           */
    union __tag8 RMPTR94;                                  /* RMPTR94          */
    union __tag8 RMDF094;                                  /* RMDF094          */
    union __tag8 RMDF194;                                  /* RMDF194          */
    union __tag8 RMID95;                                   /* RMID95           */
    union __tag8 RMPTR95;                                  /* RMPTR95          */
    union __tag8 RMDF095;                                  /* RMDF095          */
    union __tag8 RMDF195;                                  /* RMDF195          */
    unsigned char  dummy53[512];                           /* Reserved         */
    union __tag8 RFID0;                                    /* RFID0            */
    union __tag8 RFPTR0;                                   /* RFPTR0           */
    union __tag8 RFDF00;                                   /* RFDF00           */
    union __tag8 RFDF10;                                   /* RFDF10           */
    union __tag8 RFID1;                                    /* RFID1            */
    union __tag8 RFPTR1;                                   /* RFPTR1           */
    union __tag8 RFDF01;                                   /* RFDF01           */
    union __tag8 RFDF11;                                   /* RFDF11           */
    union __tag8 RFID2;                                    /* RFID2            */
    union __tag8 RFPTR2;                                   /* RFPTR2           */
    union __tag8 RFDF02;                                   /* RFDF02           */
    union __tag8 RFDF12;                                   /* RFDF12           */
    union __tag8 RFID3;                                    /* RFID3            */
    union __tag8 RFPTR3;                                   /* RFPTR3           */
    union __tag8 RFDF03;                                   /* RFDF03           */
    union __tag8 RFDF13;                                   /* RFDF13           */
    union __tag8 RFID4;                                    /* RFID4            */
    union __tag8 RFPTR4;                                   /* RFPTR4           */
    union __tag8 RFDF04;                                   /* RFDF04           */
    union __tag8 RFDF14;                                   /* RFDF14           */
    union __tag8 RFID5;                                    /* RFID5            */
    union __tag8 RFPTR5;                                   /* RFPTR5           */
    union __tag8 RFDF05;                                   /* RFDF05           */
    union __tag8 RFDF15;                                   /* RFDF15           */
    union __tag8 RFID6;                                    /* RFID6            */
    union __tag8 RFPTR6;                                   /* RFPTR6           */
    union __tag8 RFDF06;                                   /* RFDF06           */
    union __tag8 RFDF16;                                   /* RFDF16           */
    union __tag8 RFID7;                                    /* RFID7            */
    union __tag8 RFPTR7;                                   /* RFPTR7           */
    union __tag8 RFDF07;                                   /* RFDF07           */
    union __tag8 RFDF17;                                   /* RFDF17           */
    union __tag8 CFID0;                                    /* CFID0            */
    union __tag8 CFPTR0;                                   /* CFPTR0           */
    union __tag8 CFDF00;                                   /* CFDF00           */
    union __tag8 CFDF10;                                   /* CFDF10           */
    union __tag8 CFID1;                                    /* CFID1            */
    union __tag8 CFPTR1;                                   /* CFPTR1           */
    union __tag8 CFDF01;                                   /* CFDF01           */
    union __tag8 CFDF11;                                   /* CFDF11           */
    union __tag8 CFID2;                                    /* CFID2            */
    union __tag8 CFPTR2;                                   /* CFPTR2           */
    union __tag8 CFDF02;                                   /* CFDF02           */
    union __tag8 CFDF12;                                   /* CFDF12           */
    union __tag8 CFID3;                                    /* CFID3            */
    union __tag8 CFPTR3;                                   /* CFPTR3           */
    union __tag8 CFDF03;                                   /* CFDF03           */
    union __tag8 CFDF13;                                   /* CFDF13           */
    union __tag8 CFID4;                                    /* CFID4            */
    union __tag8 CFPTR4;                                   /* CFPTR4           */
    union __tag8 CFDF04;                                   /* CFDF04           */
    union __tag8 CFDF14;                                   /* CFDF14           */
    union __tag8 CFID5;                                    /* CFID5            */
    union __tag8 CFPTR5;                                   /* CFPTR5           */
    union __tag8 CFDF05;                                   /* CFDF05           */
    union __tag8 CFDF15;                                   /* CFDF15           */
    union __tag8 CFID6;                                    /* CFID6            */
    union __tag8 CFPTR6;                                   /* CFPTR6           */
    union __tag8 CFDF06;                                   /* CFDF06           */
    union __tag8 CFDF16;                                   /* CFDF16           */
    union __tag8 CFID7;                                    /* CFID7            */
    union __tag8 CFPTR7;                                   /* CFPTR7           */
    union __tag8 CFDF07;                                   /* CFDF07           */
    union __tag8 CFDF17;                                   /* CFDF17           */
    union __tag8 CFID8;                                    /* CFID8            */
    union __tag8 CFPTR8;                                   /* CFPTR8           */
    union __tag8 CFDF08;                                   /* CFDF08           */
    union __tag8 CFDF18;                                   /* CFDF18           */
    union __tag8 CFID9;                                    /* CFID9            */
    union __tag8 CFPTR9;                                   /* CFPTR9           */
    union __tag8 CFDF09;                                   /* CFDF09           */
    union __tag8 CFDF19;                                   /* CFDF19           */
    union __tag8 CFID10;                                   /* CFID10           */
    union __tag8 CFPTR10;                                  /* CFPTR10          */
    union __tag8 CFDF010;                                  /* CFDF010          */
    union __tag8 CFDF110;                                  /* CFDF110          */
    union __tag8 CFID11;                                   /* CFID11           */
    union __tag8 CFPTR11;                                  /* CFPTR11          */
    union __tag8 CFDF011;                                  /* CFDF011          */
    union __tag8 CFDF111;                                  /* CFDF111          */
    union __tag8 CFID12;                                   /* CFID12           */
    union __tag8 CFPTR12;                                  /* CFPTR12          */
    union __tag8 CFDF012;                                  /* CFDF012          */
    union __tag8 CFDF112;                                  /* CFDF112          */
    union __tag8 CFID13;                                   /* CFID13           */
    union __tag8 CFPTR13;                                  /* CFPTR13          */
    union __tag8 CFDF013;                                  /* CFDF013          */
    union __tag8 CFDF113;                                  /* CFDF113          */
    union __tag8 CFID14;                                   /* CFID14           */
    union __tag8 CFPTR14;                                  /* CFPTR14          */
    union __tag8 CFDF014;                                  /* CFDF014          */
    union __tag8 CFDF114;                                  /* CFDF114          */
    union __tag8 CFID15;                                   /* CFID15           */
    union __tag8 CFPTR15;                                  /* CFPTR15          */
    union __tag8 CFDF015;                                  /* CFDF015          */
    union __tag8 CFDF115;                                  /* CFDF115          */
    union __tag8 CFID16;                                   /* CFID16           */
    union __tag8 CFPTR16;                                  /* CFPTR16          */
    union __tag8 CFDF016;                                  /* CFDF016          */
    union __tag8 CFDF116;                                  /* CFDF116          */
    union __tag8 CFID17;                                   /* CFID17           */
    union __tag8 CFPTR17;                                  /* CFPTR17          */
    union __tag8 CFDF017;                                  /* CFDF017          */
    union __tag8 CFDF117;                                  /* CFDF117          */
    unsigned char  dummy54[96];                            /* Reserved         */
    union __tag8 TMID0;                                    /* TMID0            */
    union __tag8 TMPTR0;                                   /* TMPTR0           */
    union __tag8 TMDF00;                                   /* TMDF00           */
    union __tag8 TMDF10;                                   /* TMDF10           */
    union __tag8 TMID1;                                    /* TMID1            */
    union __tag8 TMPTR1;                                   /* TMPTR1           */
    union __tag8 TMDF01;                                   /* TMDF01           */
    union __tag8 TMDF11;                                   /* TMDF11           */
    union __tag8 TMID2;                                    /* TMID2            */
    union __tag8 TMPTR2;                                   /* TMPTR2           */
    union __tag8 TMDF02;                                   /* TMDF02           */
    union __tag8 TMDF12;                                   /* TMDF12           */
    union __tag8 TMID3;                                    /* TMID3            */
    union __tag8 TMPTR3;                                   /* TMPTR3           */
    union __tag8 TMDF03;                                   /* TMDF03           */
    union __tag8 TMDF13;                                   /* TMDF13           */
    union __tag8 TMID4;                                    /* TMID4            */
    union __tag8 TMPTR4;                                   /* TMPTR4           */
    union __tag8 TMDF04;                                   /* TMDF04           */
    union __tag8 TMDF14;                                   /* TMDF14           */
    union __tag8 TMID5;                                    /* TMID5            */
    union __tag8 TMPTR5;                                   /* TMPTR5           */
    union __tag8 TMDF05;                                   /* TMDF05           */
    union __tag8 TMDF15;                                   /* TMDF15           */
    union __tag8 TMID6;                                    /* TMID6            */
    union __tag8 TMPTR6;                                   /* TMPTR6           */
    union __tag8 TMDF06;                                   /* TMDF06           */
    union __tag8 TMDF16;                                   /* TMDF16           */
    union __tag8 TMID7;                                    /* TMID7            */
    union __tag8 TMPTR7;                                   /* TMPTR7           */
    union __tag8 TMDF07;                                   /* TMDF07           */
    union __tag8 TMDF17;                                   /* TMDF17           */
    union __tag8 TMID8;                                    /* TMID8            */
    union __tag8 TMPTR8;                                   /* TMPTR8           */
    union __tag8 TMDF08;                                   /* TMDF08           */
    union __tag8 TMDF18;                                   /* TMDF18           */
    union __tag8 TMID9;                                    /* TMID9            */
    union __tag8 TMPTR9;                                   /* TMPTR9           */
    union __tag8 TMDF09;                                   /* TMDF09           */
    union __tag8 TMDF19;                                   /* TMDF19           */
    union __tag8 TMID10;                                   /* TMID10           */
    union __tag8 TMPTR10;                                  /* TMPTR10          */
    union __tag8 TMDF010;                                  /* TMDF010          */
    union __tag8 TMDF110;                                  /* TMDF110          */
    union __tag8 TMID11;                                   /* TMID11           */
    union __tag8 TMPTR11;                                  /* TMPTR11          */
    union __tag8 TMDF011;                                  /* TMDF011          */
    union __tag8 TMDF111;                                  /* TMDF111          */
    union __tag8 TMID12;                                   /* TMID12           */
    union __tag8 TMPTR12;                                  /* TMPTR12          */
    union __tag8 TMDF012;                                  /* TMDF012          */
    union __tag8 TMDF112;                                  /* TMDF112          */
    union __tag8 TMID13;                                   /* TMID13           */
    union __tag8 TMPTR13;                                  /* TMPTR13          */
    union __tag8 TMDF013;                                  /* TMDF013          */
    union __tag8 TMDF113;                                  /* TMDF113          */
    union __tag8 TMID14;                                   /* TMID14           */
    union __tag8 TMPTR14;                                  /* TMPTR14          */
    union __tag8 TMDF014;                                  /* TMDF014          */
    union __tag8 TMDF114;                                  /* TMDF114          */
    union __tag8 TMID15;                                   /* TMID15           */
    union __tag8 TMPTR15;                                  /* TMPTR15          */
    union __tag8 TMDF015;                                  /* TMDF015          */
    union __tag8 TMDF115;                                  /* TMDF115          */
    union __tag8 TMID16;                                   /* TMID16           */
    union __tag8 TMPTR16;                                  /* TMPTR16          */
    union __tag8 TMDF016;                                  /* TMDF016          */
    union __tag8 TMDF116;                                  /* TMDF116          */
    union __tag8 TMID17;                                   /* TMID17           */
    union __tag8 TMPTR17;                                  /* TMPTR17          */
    union __tag8 TMDF017;                                  /* TMDF017          */
    union __tag8 TMDF117;                                  /* TMDF117          */
    union __tag8 TMID18;                                   /* TMID18           */
    union __tag8 TMPTR18;                                  /* TMPTR18          */
    union __tag8 TMDF018;                                  /* TMDF018          */
    union __tag8 TMDF118;                                  /* TMDF118          */
    union __tag8 TMID19;                                   /* TMID19           */
    union __tag8 TMPTR19;                                  /* TMPTR19          */
    union __tag8 TMDF019;                                  /* TMDF019          */
    union __tag8 TMDF119;                                  /* TMDF119          */
    union __tag8 TMID20;                                   /* TMID20           */
    union __tag8 TMPTR20;                                  /* TMPTR20          */
    union __tag8 TMDF020;                                  /* TMDF020          */
    union __tag8 TMDF120;                                  /* TMDF120          */
    union __tag8 TMID21;                                   /* TMID21           */
    union __tag8 TMPTR21;                                  /* TMPTR21          */
    union __tag8 TMDF021;                                  /* TMDF021          */
    union __tag8 TMDF121;                                  /* TMDF121          */
    union __tag8 TMID22;                                   /* TMID22           */
    union __tag8 TMPTR22;                                  /* TMPTR22          */
    union __tag8 TMDF022;                                  /* TMDF022          */
    union __tag8 TMDF122;                                  /* TMDF122          */
    union __tag8 TMID23;                                   /* TMID23           */
    union __tag8 TMPTR23;                                  /* TMPTR23          */
    union __tag8 TMDF023;                                  /* TMDF023          */
    union __tag8 TMDF123;                                  /* TMDF123          */
    union __tag8 TMID24;                                   /* TMID24           */
    union __tag8 TMPTR24;                                  /* TMPTR24          */
    union __tag8 TMDF024;                                  /* TMDF024          */
    union __tag8 TMDF124;                                  /* TMDF124          */
    union __tag8 TMID25;                                   /* TMID25           */
    union __tag8 TMPTR25;                                  /* TMPTR25          */
    union __tag8 TMDF025;                                  /* TMDF025          */
    union __tag8 TMDF125;                                  /* TMDF125          */
    union __tag8 TMID26;                                   /* TMID26           */
    union __tag8 TMPTR26;                                  /* TMPTR26          */
    union __tag8 TMDF026;                                  /* TMDF026          */
    union __tag8 TMDF126;                                  /* TMDF126          */
    union __tag8 TMID27;                                   /* TMID27           */
    union __tag8 TMPTR27;                                  /* TMPTR27          */
    union __tag8 TMDF027;                                  /* TMDF027          */
    union __tag8 TMDF127;                                  /* TMDF127          */
    union __tag8 TMID28;                                   /* TMID28           */
    union __tag8 TMPTR28;                                  /* TMPTR28          */
    union __tag8 TMDF028;                                  /* TMDF028          */
    union __tag8 TMDF128;                                  /* TMDF128          */
    union __tag8 TMID29;                                   /* TMID29           */
    union __tag8 TMPTR29;                                  /* TMPTR29          */
    union __tag8 TMDF029;                                  /* TMDF029          */
    union __tag8 TMDF129;                                  /* TMDF129          */
    union __tag8 TMID30;                                   /* TMID30           */
    union __tag8 TMPTR30;                                  /* TMPTR30          */
    union __tag8 TMDF030;                                  /* TMDF030          */
    union __tag8 TMDF130;                                  /* TMDF130          */
    union __tag8 TMID31;                                   /* TMID31           */
    union __tag8 TMPTR31;                                  /* TMPTR31          */
    union __tag8 TMDF031;                                  /* TMDF031          */
    union __tag8 TMDF131;                                  /* TMDF131          */
    union __tag8 TMID32;                                   /* TMID32           */
    union __tag8 TMPTR32;                                  /* TMPTR32          */
    union __tag8 TMDF032;                                  /* TMDF032          */
    union __tag8 TMDF132;                                  /* TMDF132          */
    union __tag8 TMID33;                                   /* TMID33           */
    union __tag8 TMPTR33;                                  /* TMPTR33          */
    union __tag8 TMDF033;                                  /* TMDF033          */
    union __tag8 TMDF133;                                  /* TMDF133          */
    union __tag8 TMID34;                                   /* TMID34           */
    union __tag8 TMPTR34;                                  /* TMPTR34          */
    union __tag8 TMDF034;                                  /* TMDF034          */
    union __tag8 TMDF134;                                  /* TMDF134          */
    union __tag8 TMID35;                                   /* TMID35           */
    union __tag8 TMPTR35;                                  /* TMPTR35          */
    union __tag8 TMDF035;                                  /* TMDF035          */
    union __tag8 TMDF135;                                  /* TMDF135          */
    union __tag8 TMID36;                                   /* TMID36           */
    union __tag8 TMPTR36;                                  /* TMPTR36          */
    union __tag8 TMDF036;                                  /* TMDF036          */
    union __tag8 TMDF136;                                  /* TMDF136          */
    union __tag8 TMID37;                                   /* TMID37           */
    union __tag8 TMPTR37;                                  /* TMPTR37          */
    union __tag8 TMDF037;                                  /* TMDF037          */
    union __tag8 TMDF137;                                  /* TMDF137          */
    union __tag8 TMID38;                                   /* TMID38           */
    union __tag8 TMPTR38;                                  /* TMPTR38          */
    union __tag8 TMDF038;                                  /* TMDF038          */
    union __tag8 TMDF138;                                  /* TMDF138          */
    union __tag8 TMID39;                                   /* TMID39           */
    union __tag8 TMPTR39;                                  /* TMPTR39          */
    union __tag8 TMDF039;                                  /* TMDF039          */
    union __tag8 TMDF139;                                  /* TMDF139          */
    union __tag8 TMID40;                                   /* TMID40           */
    union __tag8 TMPTR40;                                  /* TMPTR40          */
    union __tag8 TMDF040;                                  /* TMDF040          */
    union __tag8 TMDF140;                                  /* TMDF140          */
    union __tag8 TMID41;                                   /* TMID41           */
    union __tag8 TMPTR41;                                  /* TMPTR41          */
    union __tag8 TMDF041;                                  /* TMDF041          */
    union __tag8 TMDF141;                                  /* TMDF141          */
    union __tag8 TMID42;                                   /* TMID42           */
    union __tag8 TMPTR42;                                  /* TMPTR42          */
    union __tag8 TMDF042;                                  /* TMDF042          */
    union __tag8 TMDF142;                                  /* TMDF142          */
    union __tag8 TMID43;                                   /* TMID43           */
    union __tag8 TMPTR43;                                  /* TMPTR43          */
    union __tag8 TMDF043;                                  /* TMDF043          */
    union __tag8 TMDF143;                                  /* TMDF143          */
    union __tag8 TMID44;                                   /* TMID44           */
    union __tag8 TMPTR44;                                  /* TMPTR44          */
    union __tag8 TMDF044;                                  /* TMDF044          */
    union __tag8 TMDF144;                                  /* TMDF144          */
    union __tag8 TMID45;                                   /* TMID45           */
    union __tag8 TMPTR45;                                  /* TMPTR45          */
    union __tag8 TMDF045;                                  /* TMDF045          */
    union __tag8 TMDF145;                                  /* TMDF145          */
    union __tag8 TMID46;                                   /* TMID46           */
    union __tag8 TMPTR46;                                  /* TMPTR46          */
    union __tag8 TMDF046;                                  /* TMDF046          */
    union __tag8 TMDF146;                                  /* TMDF146          */
    union __tag8 TMID47;                                   /* TMID47           */
    union __tag8 TMPTR47;                                  /* TMPTR47          */
    union __tag8 TMDF047;                                  /* TMDF047          */
    union __tag8 TMDF147;                                  /* TMDF147          */
    union __tag8 TMID48;                                   /* TMID48           */
    union __tag8 TMPTR48;                                  /* TMPTR48          */
    union __tag8 TMDF048;                                  /* TMDF048          */
    union __tag8 TMDF148;                                  /* TMDF148          */
    union __tag8 TMID49;                                   /* TMID49           */
    union __tag8 TMPTR49;                                  /* TMPTR49          */
    union __tag8 TMDF049;                                  /* TMDF049          */
    union __tag8 TMDF149;                                  /* TMDF149          */
    union __tag8 TMID50;                                   /* TMID50           */
    union __tag8 TMPTR50;                                  /* TMPTR50          */
    union __tag8 TMDF050;                                  /* TMDF050          */
    union __tag8 TMDF150;                                  /* TMDF150          */
    union __tag8 TMID51;                                   /* TMID51           */
    union __tag8 TMPTR51;                                  /* TMPTR51          */
    union __tag8 TMDF051;                                  /* TMDF051          */
    union __tag8 TMDF151;                                  /* TMDF151          */
    union __tag8 TMID52;                                   /* TMID52           */
    union __tag8 TMPTR52;                                  /* TMPTR52          */
    union __tag8 TMDF052;                                  /* TMDF052          */
    union __tag8 TMDF152;                                  /* TMDF152          */
    union __tag8 TMID53;                                   /* TMID53           */
    union __tag8 TMPTR53;                                  /* TMPTR53          */
    union __tag8 TMDF053;                                  /* TMDF053          */
    union __tag8 TMDF153;                                  /* TMDF153          */
    union __tag8 TMID54;                                   /* TMID54           */
    union __tag8 TMPTR54;                                  /* TMPTR54          */
    union __tag8 TMDF054;                                  /* TMDF054          */
    union __tag8 TMDF154;                                  /* TMDF154          */
    union __tag8 TMID55;                                   /* TMID55           */
    union __tag8 TMPTR55;                                  /* TMPTR55          */
    union __tag8 TMDF055;                                  /* TMDF055          */
    union __tag8 TMDF155;                                  /* TMDF155          */
    union __tag8 TMID56;                                   /* TMID56           */
    union __tag8 TMPTR56;                                  /* TMPTR56          */
    union __tag8 TMDF056;                                  /* TMDF056          */
    union __tag8 TMDF156;                                  /* TMDF156          */
    union __tag8 TMID57;                                   /* TMID57           */
    union __tag8 TMPTR57;                                  /* TMPTR57          */
    union __tag8 TMDF057;                                  /* TMDF057          */
    union __tag8 TMDF157;                                  /* TMDF157          */
    union __tag8 TMID58;                                   /* TMID58           */
    union __tag8 TMPTR58;                                  /* TMPTR58          */
    union __tag8 TMDF058;                                  /* TMDF058          */
    union __tag8 TMDF158;                                  /* TMDF158          */
    union __tag8 TMID59;                                   /* TMID59           */
    union __tag8 TMPTR59;                                  /* TMPTR59          */
    union __tag8 TMDF059;                                  /* TMDF059          */
    union __tag8 TMDF159;                                  /* TMDF159          */
    union __tag8 TMID60;                                   /* TMID60           */
    union __tag8 TMPTR60;                                  /* TMPTR60          */
    union __tag8 TMDF060;                                  /* TMDF060          */
    union __tag8 TMDF160;                                  /* TMDF160          */
    union __tag8 TMID61;                                   /* TMID61           */
    union __tag8 TMPTR61;                                  /* TMPTR61          */
    union __tag8 TMDF061;                                  /* TMDF061          */
    union __tag8 TMDF161;                                  /* TMDF161          */
    union __tag8 TMID62;                                   /* TMID62           */
    union __tag8 TMPTR62;                                  /* TMPTR62          */
    union __tag8 TMDF062;                                  /* TMDF062          */
    union __tag8 TMDF162;                                  /* TMDF162          */
    union __tag8 TMID63;                                   /* TMID63           */
    union __tag8 TMPTR63;                                  /* TMPTR63          */
    union __tag8 TMDF063;                                  /* TMDF063          */
    union __tag8 TMDF163;                                  /* TMDF163          */
    union __tag8 TMID64;                                   /* TMID64           */
    union __tag8 TMPTR64;                                  /* TMPTR64          */
    union __tag8 TMDF064;                                  /* TMDF064          */
    union __tag8 TMDF164;                                  /* TMDF164          */
    union __tag8 TMID65;                                   /* TMID65           */
    union __tag8 TMPTR65;                                  /* TMPTR65          */
    union __tag8 TMDF065;                                  /* TMDF065          */
    union __tag8 TMDF165;                                  /* TMDF165          */
    union __tag8 TMID66;                                   /* TMID66           */
    union __tag8 TMPTR66;                                  /* TMPTR66          */
    union __tag8 TMDF066;                                  /* TMDF066          */
    union __tag8 TMDF166;                                  /* TMDF166          */
    union __tag8 TMID67;                                   /* TMID67           */
    union __tag8 TMPTR67;                                  /* TMPTR67          */
    union __tag8 TMDF067;                                  /* TMDF067          */
    union __tag8 TMDF167;                                  /* TMDF167          */
    union __tag8 TMID68;                                   /* TMID68           */
    union __tag8 TMPTR68;                                  /* TMPTR68          */
    union __tag8 TMDF068;                                  /* TMDF068          */
    union __tag8 TMDF168;                                  /* TMDF168          */
    union __tag8 TMID69;                                   /* TMID69           */
    union __tag8 TMPTR69;                                  /* TMPTR69          */
    union __tag8 TMDF069;                                  /* TMDF069          */
    union __tag8 TMDF169;                                  /* TMDF169          */
    union __tag8 TMID70;                                   /* TMID70           */
    union __tag8 TMPTR70;                                  /* TMPTR70          */
    union __tag8 TMDF070;                                  /* TMDF070          */
    union __tag8 TMDF170;                                  /* TMDF170          */
    union __tag8 TMID71;                                   /* TMID71           */
    union __tag8 TMPTR71;                                  /* TMPTR71          */
    union __tag8 TMDF071;                                  /* TMDF071          */
    union __tag8 TMDF171;                                  /* TMDF171          */
    union __tag8 TMID72;                                   /* TMID72           */
    union __tag8 TMPTR72;                                  /* TMPTR72          */
    union __tag8 TMDF072;                                  /* TMDF072          */
    union __tag8 TMDF172;                                  /* TMDF172          */
    union __tag8 TMID73;                                   /* TMID73           */
    union __tag8 TMPTR73;                                  /* TMPTR73          */
    union __tag8 TMDF073;                                  /* TMDF073          */
    union __tag8 TMDF173;                                  /* TMDF173          */
    union __tag8 TMID74;                                   /* TMID74           */
    union __tag8 TMPTR74;                                  /* TMPTR74          */
    union __tag8 TMDF074;                                  /* TMDF074          */
    union __tag8 TMDF174;                                  /* TMDF174          */
    union __tag8 TMID75;                                   /* TMID75           */
    union __tag8 TMPTR75;                                  /* TMPTR75          */
    union __tag8 TMDF075;                                  /* TMDF075          */
    union __tag8 TMDF175;                                  /* TMDF175          */
    union __tag8 TMID76;                                   /* TMID76           */
    union __tag8 TMPTR76;                                  /* TMPTR76          */
    union __tag8 TMDF076;                                  /* TMDF076          */
    union __tag8 TMDF176;                                  /* TMDF176          */
    union __tag8 TMID77;                                   /* TMID77           */
    union __tag8 TMPTR77;                                  /* TMPTR77          */
    union __tag8 TMDF077;                                  /* TMDF077          */
    union __tag8 TMDF177;                                  /* TMDF177          */
    union __tag8 TMID78;                                   /* TMID78           */
    union __tag8 TMPTR78;                                  /* TMPTR78          */
    union __tag8 TMDF078;                                  /* TMDF078          */
    union __tag8 TMDF178;                                  /* TMDF178          */
    union __tag8 TMID79;                                   /* TMID79           */
    union __tag8 TMPTR79;                                  /* TMPTR79          */
    union __tag8 TMDF079;                                  /* TMDF079          */
    union __tag8 TMDF179;                                  /* TMDF179          */
    union __tag8 TMID80;                                   /* TMID80           */
    union __tag8 TMPTR80;                                  /* TMPTR80          */
    union __tag8 TMDF080;                                  /* TMDF080          */
    union __tag8 TMDF180;                                  /* TMDF180          */
    union __tag8 TMID81;                                   /* TMID81           */
    union __tag8 TMPTR81;                                  /* TMPTR81          */
    union __tag8 TMDF081;                                  /* TMDF081          */
    union __tag8 TMDF181;                                  /* TMDF181          */
    union __tag8 TMID82;                                   /* TMID82           */
    union __tag8 TMPTR82;                                  /* TMPTR82          */
    union __tag8 TMDF082;                                  /* TMDF082          */
    union __tag8 TMDF182;                                  /* TMDF182          */
    union __tag8 TMID83;                                   /* TMID83           */
    union __tag8 TMPTR83;                                  /* TMPTR83          */
    union __tag8 TMDF083;                                  /* TMDF083          */
    union __tag8 TMDF183;                                  /* TMDF183          */
    union __tag8 TMID84;                                   /* TMID84           */
    union __tag8 TMPTR84;                                  /* TMPTR84          */
    union __tag8 TMDF084;                                  /* TMDF084          */
    union __tag8 TMDF184;                                  /* TMDF184          */
    union __tag8 TMID85;                                   /* TMID85           */
    union __tag8 TMPTR85;                                  /* TMPTR85          */
    union __tag8 TMDF085;                                  /* TMDF085          */
    union __tag8 TMDF185;                                  /* TMDF185          */
    union __tag8 TMID86;                                   /* TMID86           */
    union __tag8 TMPTR86;                                  /* TMPTR86          */
    union __tag8 TMDF086;                                  /* TMDF086          */
    union __tag8 TMDF186;                                  /* TMDF186          */
    union __tag8 TMID87;                                   /* TMID87           */
    union __tag8 TMPTR87;                                  /* TMPTR87          */
    union __tag8 TMDF087;                                  /* TMDF087          */
    union __tag8 TMDF187;                                  /* TMDF187          */
    union __tag8 TMID88;                                   /* TMID88           */
    union __tag8 TMPTR88;                                  /* TMPTR88          */
    union __tag8 TMDF088;                                  /* TMDF088          */
    union __tag8 TMDF188;                                  /* TMDF188          */
    union __tag8 TMID89;                                   /* TMID89           */
    union __tag8 TMPTR89;                                  /* TMPTR89          */
    union __tag8 TMDF089;                                  /* TMDF089          */
    union __tag8 TMDF189;                                  /* TMDF189          */
    union __tag8 TMID90;                                   /* TMID90           */
    union __tag8 TMPTR90;                                  /* TMPTR90          */
    union __tag8 TMDF090;                                  /* TMDF090          */
    union __tag8 TMDF190;                                  /* TMDF190          */
    union __tag8 TMID91;                                   /* TMID91           */
    union __tag8 TMPTR91;                                  /* TMPTR91          */
    union __tag8 TMDF091;                                  /* TMDF091          */
    union __tag8 TMDF191;                                  /* TMDF191          */
    union __tag8 TMID92;                                   /* TMID92           */
    union __tag8 TMPTR92;                                  /* TMPTR92          */
    union __tag8 TMDF092;                                  /* TMDF092          */
    union __tag8 TMDF192;                                  /* TMDF192          */
    union __tag8 TMID93;                                   /* TMID93           */
    union __tag8 TMPTR93;                                  /* TMPTR93          */
    union __tag8 TMDF093;                                  /* TMDF093          */
    union __tag8 TMDF193;                                  /* TMDF193          */
    union __tag8 TMID94;                                   /* TMID94           */
    union __tag8 TMPTR94;                                  /* TMPTR94          */
    union __tag8 TMDF094;                                  /* TMDF094          */
    union __tag8 TMDF194;                                  /* TMDF194          */
    union __tag8 TMID95;                                   /* TMID95           */
    union __tag8 TMPTR95;                                  /* TMPTR95          */
    union __tag8 TMDF095;                                  /* TMDF095          */
    union __tag8 TMDF195;                                  /* TMDF195          */
    unsigned char  dummy55[512];                           /* Reserved         */
    union __tag8 THLACC0;                                  /* THLACC0          */
    union __tag8 THLACC1;                                  /* THLACC1          */
    union __tag8 THLACC2;                                  /* THLACC2          */
    union __tag8 THLACC3;                                  /* THLACC3          */
    union __tag8 THLACC4;                                  /* THLACC4          */
    union __tag8 THLACC5;                                  /* THLACC5          */
    unsigned char  dummy56[232];                           /* Reserved         */
    union __tag8 RPGACC0;                                  /* RPGACC0          */
    union __tag8 RPGACC1;                                  /* RPGACC1          */
    union __tag8 RPGACC2;                                  /* RPGACC2          */
    union __tag8 RPGACC3;                                  /* RPGACC3          */
    union __tag8 RPGACC4;                                  /* RPGACC4          */
    union __tag8 RPGACC5;                                  /* RPGACC5          */
    union __tag8 RPGACC6;                                  /* RPGACC6          */
    union __tag8 RPGACC7;                                  /* RPGACC7          */
    union __tag8 RPGACC8;                                  /* RPGACC8          */
    union __tag8 RPGACC9;                                  /* RPGACC9          */
    union __tag8 RPGACC10;                                 /* RPGACC10         */
    union __tag8 RPGACC11;                                 /* RPGACC11         */
    union __tag8 RPGACC12;                                 /* RPGACC12         */
    union __tag8 RPGACC13;                                 /* RPGACC13         */
    union __tag8 RPGACC14;                                 /* RPGACC14         */
    union __tag8 RPGACC15;                                 /* RPGACC15         */
    union __tag8 RPGACC16;                                 /* RPGACC16         */
    union __tag8 RPGACC17;                                 /* RPGACC17         */
    union __tag8 RPGACC18;                                 /* RPGACC18         */
    union __tag8 RPGACC19;                                 /* RPGACC19         */
    union __tag8 RPGACC20;                                 /* RPGACC20         */
    union __tag8 RPGACC21;                                 /* RPGACC21         */
    union __tag8 RPGACC22;                                 /* RPGACC22         */
    union __tag8 RPGACC23;                                 /* RPGACC23         */
    union __tag8 RPGACC24;                                 /* RPGACC24         */
    union __tag8 RPGACC25;                                 /* RPGACC25         */
    union __tag8 RPGACC26;                                 /* RPGACC26         */
    union __tag8 RPGACC27;                                 /* RPGACC27         */
    union __tag8 RPGACC28;                                 /* RPGACC28         */
    union __tag8 RPGACC29;                                 /* RPGACC29         */
    union __tag8 RPGACC30;                                 /* RPGACC30         */
    union __tag8 RPGACC31;                                 /* RPGACC31         */
    union __tag8 RPGACC32;                                 /* RPGACC32         */
    union __tag8 RPGACC33;                                 /* RPGACC33         */
    union __tag8 RPGACC34;                                 /* RPGACC34         */
    union __tag8 RPGACC35;                                 /* RPGACC35         */
    union __tag8 RPGACC36;                                 /* RPGACC36         */
    union __tag8 RPGACC37;                                 /* RPGACC37         */
    union __tag8 RPGACC38;                                 /* RPGACC38         */
    union __tag8 RPGACC39;                                 /* RPGACC39         */
    union __tag8 RPGACC40;                                 /* RPGACC40         */
    union __tag8 RPGACC41;                                 /* RPGACC41         */
    union __tag8 RPGACC42;                                 /* RPGACC42         */
    union __tag8 RPGACC43;                                 /* RPGACC43         */
    union __tag8 RPGACC44;                                 /* RPGACC44         */
    union __tag8 RPGACC45;                                 /* RPGACC45         */
    union __tag8 RPGACC46;                                 /* RPGACC46         */
    union __tag8 RPGACC47;                                 /* RPGACC47         */
    union __tag8 RPGACC48;                                 /* RPGACC48         */
    union __tag8 RPGACC49;                                 /* RPGACC49         */
    union __tag8 RPGACC50;                                 /* RPGACC50         */
    union __tag8 RPGACC51;                                 /* RPGACC51         */
    union __tag8 RPGACC52;                                 /* RPGACC52         */
    union __tag8 RPGACC53;                                 /* RPGACC53         */
    union __tag8 RPGACC54;                                 /* RPGACC54         */
    union __tag8 RPGACC55;                                 /* RPGACC55         */
    union __tag8 RPGACC56;                                 /* RPGACC56         */
    union __tag8 RPGACC57;                                 /* RPGACC57         */
    union __tag8 RPGACC58;                                 /* RPGACC58         */
    union __tag8 RPGACC59;                                 /* RPGACC59         */
    union __tag8 RPGACC60;                                 /* RPGACC60         */
    union __tag8 RPGACC61;                                 /* RPGACC61         */
    union __tag8 RPGACC62;                                 /* RPGACC62         */
    union __tag8 RPGACC63;                                 /* RPGACC63         */
};
struct __tag33
{                                                          /* Module           */
    union __tag12 CTL0;                                    /* CTL0             */
    unsigned char  dummy57[3];                             /* Reserved         */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy58[6];                             /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy59[2];                             /* Reserved         */
    union __tag13 EMU;                                     /* EMU              */
    unsigned char  dummy60[4071];                          /* Reserved         */
    unsigned long  MCTL1;                                  /* MCTL1            */
    unsigned long  MCTL2;                                  /* MCTL2            */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy61[2];                             /* Reserved         */
    unsigned long  RX0W;                                   /* RX0W             */
    unsigned short RX0H;                                   /* RX0H             */
    unsigned char  dummy62[2];                             /* Reserved         */
    unsigned long  MRWP0;                                  /* MRWP0            */
    unsigned char  dummy63[36];                            /* Reserved         */
    unsigned short MCTL0;                                  /* MCTL0            */
    unsigned char  dummy64[2];                             /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
    unsigned long  CFG1;                                   /* CFG1             */
    unsigned long  CFG2;                                   /* CFG2             */
    unsigned long  CFG3;                                   /* CFG3             */
    unsigned long  CFG4;                                   /* CFG4             */
    unsigned long  CFG5;                                   /* CFG5             */
    unsigned long  CFG6;                                   /* CFG6             */
    unsigned long  CFG7;                                   /* CFG7             */
    unsigned char  dummy65[4];                             /* Reserved         */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy66[2];                             /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy67[2];                             /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy68[2];                             /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
};
struct __tag34
{                                                          /* Module           */
    union __tag12 CTL0;                                    /* CTL0             */
    unsigned char  dummy69[3];                             /* Reserved         */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy70[6];                             /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy71[2];                             /* Reserved         */
    union __tag13 EMU;                                     /* EMU              */
    unsigned char  dummy72[4071];                          /* Reserved         */
    unsigned long  MCTL1;                                  /* MCTL1            */
    unsigned long  MCTL2;                                  /* MCTL2            */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy73[2];                             /* Reserved         */
    unsigned long  RX0W;                                   /* RX0W             */
    unsigned short RX0H;                                   /* RX0H             */
    unsigned char  dummy74[2];                             /* Reserved         */
    unsigned long  MRWP0;                                  /* MRWP0            */
    unsigned char  dummy75[36];                            /* Reserved         */
    unsigned short MCTL0;                                  /* MCTL0            */
    unsigned char  dummy76[2];                             /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
    unsigned long  CFG1;                                   /* CFG1             */
    unsigned long  CFG2;                                   /* CFG2             */
    unsigned long  CFG3;                                   /* CFG3             */
    unsigned long  CFG4;                                   /* CFG4             */
    unsigned long  CFG5;                                   /* CFG5             */
    unsigned char  dummy77[12];                            /* Reserved         */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy78[2];                             /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy79[2];                             /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy80[2];                             /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
};
struct __tag35
{                                                          /* Module           */
    union __tag12 CTL0;                                    /* CTL0             */
    unsigned char  dummy81[3];                             /* Reserved         */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy82[6];                             /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy83[2];                             /* Reserved         */
    union __tag13 EMU;                                     /* EMU              */
    unsigned char  dummy84[4071];                          /* Reserved         */
    unsigned long  MCTL1;                                  /* MCTL1            */
    unsigned long  MCTL2;                                  /* MCTL2            */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy85[2];                             /* Reserved         */
    unsigned long  RX0W;                                   /* RX0W             */
    unsigned short RX0H;                                   /* RX0H             */
    unsigned char  dummy86[2];                             /* Reserved         */
    unsigned long  MRWP0;                                  /* MRWP0            */
    unsigned char  dummy87[36];                            /* Reserved         */
    unsigned short MCTL0;                                  /* MCTL0            */
    unsigned char  dummy88[2];                             /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
    unsigned long  CFG1;                                   /* CFG1             */
    unsigned long  CFG2;                                   /* CFG2             */
    unsigned long  CFG3;                                   /* CFG3             */
    unsigned char  dummy89[20];                            /* Reserved         */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy90[2];                             /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy91[2];                             /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy92[2];                             /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
};
struct __tag36
{                                                          /* Module           */
    union __tag14 CTL0;                                    /* CTL0             */
    unsigned char  dummy93[3];                             /* Reserved         */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy94[6];                             /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy95[2];                             /* Reserved         */
    union __tag13 EMU;                                     /* EMU              */
    unsigned char  dummy96[4071];                          /* Reserved         */
    union __tag15 BCTL0;                                   /* BCTL0            */
    unsigned char  dummy97[3];                             /* Reserved         */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy98[2];                             /* Reserved         */
    unsigned short RX0;                                    /* RX0              */
    unsigned char  dummy99[2];                             /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
};
struct __tag37
{                                                          /* Module           */
    unsigned char  SST;                                    /* SST              */
    unsigned char  dummy100[11];                           /* Reserved         */
    unsigned short SSER0;                                  /* SSER0            */
    unsigned char  dummy101[6];                            /* Reserved         */
    unsigned short SSER2;                                  /* SSER2            */
    unsigned char  dummy102[102];                          /* Reserved         */
    unsigned char  HIZCEN0;                                /* HIZCEN0          */
    unsigned char  dummy103[15];                           /* Reserved         */
    unsigned short ADTEN400;                               /* ADTEN400         */
    unsigned char  dummy104[2];                            /* Reserved         */
    unsigned short ADTEN401;                               /* ADTEN401         */
    unsigned char  dummy105[2];                            /* Reserved         */
    unsigned short ADTEN402;                               /* ADTEN402         */
    unsigned char  dummy106[38];                           /* Reserved         */
    unsigned long  REG200;                                 /* REG200           */
    unsigned long  REG201;                                 /* REG201           */
    unsigned long  REG202;                                 /* REG202           */
    unsigned long  REG203;                                 /* REG203           */
    unsigned char  dummy107[24];                           /* Reserved         */
    unsigned long  REG30;                                  /* REG30            */
    unsigned long  REG31;                                  /* REG31            */
};
struct __tag38
{                                                          /* Module           */
    unsigned short CDR0;                                   /* CDR0             */
    unsigned char  dummy108[2];                            /* Reserved         */
    unsigned short CDR1;                                   /* CDR1             */
    unsigned char  dummy109[2];                            /* Reserved         */
    unsigned short CDR2;                                   /* CDR2             */
    unsigned char  dummy110[2];                            /* Reserved         */
    unsigned short CDR3;                                   /* CDR3             */
    unsigned char  dummy111[2];                            /* Reserved         */
    unsigned short CDR4;                                   /* CDR4             */
    unsigned char  dummy112[2];                            /* Reserved         */
    unsigned short CDR5;                                   /* CDR5             */
    unsigned char  dummy113[2];                            /* Reserved         */
    unsigned short CDR6;                                   /* CDR6             */
    unsigned char  dummy114[2];                            /* Reserved         */
    unsigned short CDR7;                                   /* CDR7             */
    unsigned char  dummy115[2];                            /* Reserved         */
    unsigned short CDR8;                                   /* CDR8             */
    unsigned char  dummy116[2];                            /* Reserved         */
    unsigned short CDR9;                                   /* CDR9             */
    unsigned char  dummy117[2];                            /* Reserved         */
    unsigned short CDR10;                                  /* CDR10            */
    unsigned char  dummy118[2];                            /* Reserved         */
    unsigned short CDR11;                                  /* CDR11            */
    unsigned char  dummy119[2];                            /* Reserved         */
    unsigned short CDR12;                                  /* CDR12            */
    unsigned char  dummy120[2];                            /* Reserved         */
    unsigned short CDR13;                                  /* CDR13            */
    unsigned char  dummy121[2];                            /* Reserved         */
    unsigned short CDR14;                                  /* CDR14            */
    unsigned char  dummy122[2];                            /* Reserved         */
    unsigned short CDR15;                                  /* CDR15            */
    unsigned char  dummy123[2];                            /* Reserved         */
    unsigned short TOL;                                    /* TOL              */
    unsigned char  dummy124[2];                            /* Reserved         */
    unsigned short RDT;                                    /* RDT              */
    unsigned char  dummy125[2];                            /* Reserved         */
    unsigned short RSF;                                    /* RSF              */
    unsigned char  dummy126[2];                            /* Reserved         */
    unsigned short TRO;                                    /* TRO              */
    unsigned char  dummy127[2];                            /* Reserved         */
    unsigned short TME;                                    /* TME              */
    unsigned char  dummy128[2];                            /* Reserved         */
    unsigned short TDL;                                    /* TDL              */
    unsigned char  dummy129[2];                            /* Reserved         */
    unsigned short TO;                                     /* TO               */
    unsigned char  dummy130[2];                            /* Reserved         */
    unsigned short TOE;                                    /* TOE              */
    unsigned char  dummy131[34];                           /* Reserved         */
    unsigned short CNT0;                                   /* CNT0             */
    unsigned char  dummy132[2];                            /* Reserved         */
    unsigned short CNT1;                                   /* CNT1             */
    unsigned char  dummy133[2];                            /* Reserved         */
    unsigned short CNT2;                                   /* CNT2             */
    unsigned char  dummy134[2];                            /* Reserved         */
    unsigned short CNT3;                                   /* CNT3             */
    unsigned char  dummy135[2];                            /* Reserved         */
    unsigned short CNT4;                                   /* CNT4             */
    unsigned char  dummy136[2];                            /* Reserved         */
    unsigned short CNT5;                                   /* CNT5             */
    unsigned char  dummy137[2];                            /* Reserved         */
    unsigned short CNT6;                                   /* CNT6             */
    unsigned char  dummy138[2];                            /* Reserved         */
    unsigned short CNT7;                                   /* CNT7             */
    unsigned char  dummy139[2];                            /* Reserved         */
    unsigned short CNT8;                                   /* CNT8             */
    unsigned char  dummy140[2];                            /* Reserved         */
    unsigned short CNT9;                                   /* CNT9             */
    unsigned char  dummy141[2];                            /* Reserved         */
    unsigned short CNT10;                                  /* CNT10            */
    unsigned char  dummy142[2];                            /* Reserved         */
    unsigned short CNT11;                                  /* CNT11            */
    unsigned char  dummy143[2];                            /* Reserved         */
    unsigned short CNT12;                                  /* CNT12            */
    unsigned char  dummy144[2];                            /* Reserved         */
    unsigned short CNT13;                                  /* CNT13            */
    unsigned char  dummy145[2];                            /* Reserved         */
    unsigned short CNT14;                                  /* CNT14            */
    unsigned char  dummy146[2];                            /* Reserved         */
    unsigned short CNT15;                                  /* CNT15            */
    unsigned char  dummy147[2];                            /* Reserved         */
    unsigned char  CMUR0;                                  /* CMUR0            */
    unsigned char  dummy148[3];                            /* Reserved         */
    unsigned char  CMUR1;                                  /* CMUR1            */
    unsigned char  dummy149[3];                            /* Reserved         */
    unsigned char  CMUR2;                                  /* CMUR2            */
    unsigned char  dummy150[3];                            /* Reserved         */
    unsigned char  CMUR3;                                  /* CMUR3            */
    unsigned char  dummy151[3];                            /* Reserved         */
    unsigned char  CMUR4;                                  /* CMUR4            */
    unsigned char  dummy152[3];                            /* Reserved         */
    unsigned char  CMUR5;                                  /* CMUR5            */
    unsigned char  dummy153[3];                            /* Reserved         */
    unsigned char  CMUR6;                                  /* CMUR6            */
    unsigned char  dummy154[3];                            /* Reserved         */
    unsigned char  CMUR7;                                  /* CMUR7            */
    unsigned char  dummy155[3];                            /* Reserved         */
    unsigned char  CMUR8;                                  /* CMUR8            */
    unsigned char  dummy156[3];                            /* Reserved         */
    unsigned char  CMUR9;                                  /* CMUR9            */
    unsigned char  dummy157[3];                            /* Reserved         */
    unsigned char  CMUR10;                                 /* CMUR10           */
    unsigned char  dummy158[3];                            /* Reserved         */
    unsigned char  CMUR11;                                 /* CMUR11           */
    unsigned char  dummy159[3];                            /* Reserved         */
    unsigned char  CMUR12;                                 /* CMUR12           */
    unsigned char  dummy160[3];                            /* Reserved         */
    unsigned char  CMUR13;                                 /* CMUR13           */
    unsigned char  dummy161[3];                            /* Reserved         */
    unsigned char  CMUR14;                                 /* CMUR14           */
    unsigned char  dummy162[3];                            /* Reserved         */
    unsigned char  CMUR15;                                 /* CMUR15           */
    unsigned char  dummy163[67];                           /* Reserved         */
    unsigned char  CSR0;                                   /* CSR0             */
    unsigned char  dummy164[3];                            /* Reserved         */
    unsigned char  CSR1;                                   /* CSR1             */
    unsigned char  dummy165[3];                            /* Reserved         */
    unsigned char  CSR2;                                   /* CSR2             */
    unsigned char  dummy166[3];                            /* Reserved         */
    unsigned char  CSR3;                                   /* CSR3             */
    unsigned char  dummy167[3];                            /* Reserved         */
    unsigned char  CSR4;                                   /* CSR4             */
    unsigned char  dummy168[3];                            /* Reserved         */
    unsigned char  CSR5;                                   /* CSR5             */
    unsigned char  dummy169[3];                            /* Reserved         */
    unsigned char  CSR6;                                   /* CSR6             */
    unsigned char  dummy170[3];                            /* Reserved         */
    unsigned char  CSR7;                                   /* CSR7             */
    unsigned char  dummy171[3];                            /* Reserved         */
    unsigned char  CSR8;                                   /* CSR8             */
    unsigned char  dummy172[3];                            /* Reserved         */
    unsigned char  CSR9;                                   /* CSR9             */
    unsigned char  dummy173[3];                            /* Reserved         */
    unsigned char  CSR10;                                  /* CSR10            */
    unsigned char  dummy174[3];                            /* Reserved         */
    unsigned char  CSR11;                                  /* CSR11            */
    unsigned char  dummy175[3];                            /* Reserved         */
    unsigned char  CSR12;                                  /* CSR12            */
    unsigned char  dummy176[3];                            /* Reserved         */
    unsigned char  CSR13;                                  /* CSR13            */
    unsigned char  dummy177[3];                            /* Reserved         */
    unsigned char  CSR14;                                  /* CSR14            */
    unsigned char  dummy178[3];                            /* Reserved         */
    unsigned char  CSR15;                                  /* CSR15            */
    unsigned char  dummy179[3];                            /* Reserved         */
    unsigned char  CSC0;                                   /* CSC0             */
    unsigned char  dummy180[3];                            /* Reserved         */
    unsigned char  CSC1;                                   /* CSC1             */
    unsigned char  dummy181[3];                            /* Reserved         */
    unsigned char  CSC2;                                   /* CSC2             */
    unsigned char  dummy182[3];                            /* Reserved         */
    unsigned char  CSC3;                                   /* CSC3             */
    unsigned char  dummy183[3];                            /* Reserved         */
    unsigned char  CSC4;                                   /* CSC4             */
    unsigned char  dummy184[3];                            /* Reserved         */
    unsigned char  CSC5;                                   /* CSC5             */
    unsigned char  dummy185[3];                            /* Reserved         */
    unsigned char  CSC6;                                   /* CSC6             */
    unsigned char  dummy186[3];                            /* Reserved         */
    unsigned char  CSC7;                                   /* CSC7             */
    unsigned char  dummy187[3];                            /* Reserved         */
    unsigned char  CSC8;                                   /* CSC8             */
    unsigned char  dummy188[3];                            /* Reserved         */
    unsigned char  CSC9;                                   /* CSC9             */
    unsigned char  dummy189[3];                            /* Reserved         */
    unsigned char  CSC10;                                  /* CSC10            */
    unsigned char  dummy190[3];                            /* Reserved         */
    unsigned char  CSC11;                                  /* CSC11            */
    unsigned char  dummy191[3];                            /* Reserved         */
    unsigned char  CSC12;                                  /* CSC12            */
    unsigned char  dummy192[3];                            /* Reserved         */
    unsigned char  CSC13;                                  /* CSC13            */
    unsigned char  dummy193[3];                            /* Reserved         */
    unsigned char  CSC14;                                  /* CSC14            */
    unsigned char  dummy194[3];                            /* Reserved         */
    unsigned char  CSC15;                                  /* CSC15            */
    unsigned char  dummy195[3];                            /* Reserved         */
    unsigned short TE;                                     /* TE               */
    unsigned char  dummy196[2];                            /* Reserved         */
    unsigned short TS;                                     /* TS               */
    unsigned char  dummy197[2];                            /* Reserved         */
    unsigned short TT;                                     /* TT               */
    unsigned char  dummy198[54];                           /* Reserved         */
    unsigned short CMOR0;                                  /* CMOR0            */
    unsigned char  dummy199[2];                            /* Reserved         */
    unsigned short CMOR1;                                  /* CMOR1            */
    unsigned char  dummy200[2];                            /* Reserved         */
    unsigned short CMOR2;                                  /* CMOR2            */
    unsigned char  dummy201[2];                            /* Reserved         */
    unsigned short CMOR3;                                  /* CMOR3            */
    unsigned char  dummy202[2];                            /* Reserved         */
    unsigned short CMOR4;                                  /* CMOR4            */
    unsigned char  dummy203[2];                            /* Reserved         */
    unsigned short CMOR5;                                  /* CMOR5            */
    unsigned char  dummy204[2];                            /* Reserved         */
    unsigned short CMOR6;                                  /* CMOR6            */
    unsigned char  dummy205[2];                            /* Reserved         */
    unsigned short CMOR7;                                  /* CMOR7            */
    unsigned char  dummy206[2];                            /* Reserved         */
    unsigned short CMOR8;                                  /* CMOR8            */
    unsigned char  dummy207[2];                            /* Reserved         */
    unsigned short CMOR9;                                  /* CMOR9            */
    unsigned char  dummy208[2];                            /* Reserved         */
    unsigned short CMOR10;                                 /* CMOR10           */
    unsigned char  dummy209[2];                            /* Reserved         */
    unsigned short CMOR11;                                 /* CMOR11           */
    unsigned char  dummy210[2];                            /* Reserved         */
    unsigned short CMOR12;                                 /* CMOR12           */
    unsigned char  dummy211[2];                            /* Reserved         */
    unsigned short CMOR13;                                 /* CMOR13           */
    unsigned char  dummy212[2];                            /* Reserved         */
    unsigned short CMOR14;                                 /* CMOR14           */
    unsigned char  dummy213[2];                            /* Reserved         */
    unsigned short CMOR15;                                 /* CMOR15           */
    unsigned char  dummy214[2];                            /* Reserved         */
    unsigned short TPS;                                    /* TPS              */
    unsigned char  dummy215[2];                            /* Reserved         */
    unsigned char  BRS;                                    /* BRS              */
    unsigned char  dummy216[3];                            /* Reserved         */
    unsigned short TOM;                                    /* TOM              */
    unsigned char  dummy217[2];                            /* Reserved         */
    unsigned short TOC;                                    /* TOC              */
    unsigned char  dummy218[2];                            /* Reserved         */
    unsigned short TDE;                                    /* TDE              */
    unsigned char  dummy219[2];                            /* Reserved         */
    unsigned short TDM;                                    /* TDM              */
    unsigned char  dummy220[2];                            /* Reserved         */
    unsigned short TRE;                                    /* TRE              */
    unsigned char  dummy221[2];                            /* Reserved         */
    unsigned short TRC;                                    /* TRC              */
    unsigned char  dummy222[2];                            /* Reserved         */
    unsigned short RDE;                                    /* RDE              */
    unsigned char  dummy223[2];                            /* Reserved         */
    unsigned short RDM;                                    /* RDM              */
    unsigned char  dummy224[2];                            /* Reserved         */
    unsigned short RDS;                                    /* RDS              */
    unsigned char  dummy225[2];                            /* Reserved         */
    unsigned short RDC;                                    /* RDC              */
    unsigned char  dummy226[34];                           /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag39
{                                                          /* Module           */
    unsigned short CDR0;                                   /* CDR0             */
    unsigned char  dummy227[2];                            /* Reserved         */
    unsigned short CDR1;                                   /* CDR1             */
    unsigned char  dummy228[2];                            /* Reserved         */
    unsigned short CDR2;                                   /* CDR2             */
    unsigned char  dummy229[2];                            /* Reserved         */
    unsigned short CDR3;                                   /* CDR3             */
    unsigned char  dummy230[2];                            /* Reserved         */
    unsigned short CDR4;                                   /* CDR4             */
    unsigned char  dummy231[2];                            /* Reserved         */
    unsigned short CDR5;                                   /* CDR5             */
    unsigned char  dummy232[2];                            /* Reserved         */
    unsigned short CDR6;                                   /* CDR6             */
    unsigned char  dummy233[2];                            /* Reserved         */
    unsigned short CDR7;                                   /* CDR7             */
    unsigned char  dummy234[2];                            /* Reserved         */
    unsigned short CDR8;                                   /* CDR8             */
    unsigned char  dummy235[2];                            /* Reserved         */
    unsigned short CDR9;                                   /* CDR9             */
    unsigned char  dummy236[2];                            /* Reserved         */
    unsigned short CDR10;                                  /* CDR10            */
    unsigned char  dummy237[2];                            /* Reserved         */
    unsigned short CDR11;                                  /* CDR11            */
    unsigned char  dummy238[2];                            /* Reserved         */
    unsigned short CDR12;                                  /* CDR12            */
    unsigned char  dummy239[2];                            /* Reserved         */
    unsigned short CDR13;                                  /* CDR13            */
    unsigned char  dummy240[2];                            /* Reserved         */
    unsigned short CDR14;                                  /* CDR14            */
    unsigned char  dummy241[2];                            /* Reserved         */
    unsigned short CDR15;                                  /* CDR15            */
    unsigned char  dummy242[2];                            /* Reserved         */
    unsigned short TOL;                                    /* TOL              */
    unsigned char  dummy243[2];                            /* Reserved         */
    unsigned short RDT;                                    /* RDT              */
    unsigned char  dummy244[2];                            /* Reserved         */
    unsigned short RSF;                                    /* RSF              */
    unsigned char  dummy245[10];                           /* Reserved         */
    unsigned short TDL;                                    /* TDL              */
    unsigned char  dummy246[2];                            /* Reserved         */
    unsigned short TO;                                     /* TO               */
    unsigned char  dummy247[2];                            /* Reserved         */
    unsigned short TOE;                                    /* TOE              */
    unsigned char  dummy248[34];                           /* Reserved         */
    unsigned short CNT0;                                   /* CNT0             */
    unsigned char  dummy249[2];                            /* Reserved         */
    unsigned short CNT1;                                   /* CNT1             */
    unsigned char  dummy250[2];                            /* Reserved         */
    unsigned short CNT2;                                   /* CNT2             */
    unsigned char  dummy251[2];                            /* Reserved         */
    unsigned short CNT3;                                   /* CNT3             */
    unsigned char  dummy252[2];                            /* Reserved         */
    unsigned short CNT4;                                   /* CNT4             */
    unsigned char  dummy253[2];                            /* Reserved         */
    unsigned short CNT5;                                   /* CNT5             */
    unsigned char  dummy254[2];                            /* Reserved         */
    unsigned short CNT6;                                   /* CNT6             */
    unsigned char  dummy255[2];                            /* Reserved         */
    unsigned short CNT7;                                   /* CNT7             */
    unsigned char  dummy256[2];                            /* Reserved         */
    unsigned short CNT8;                                   /* CNT8             */
    unsigned char  dummy257[2];                            /* Reserved         */
    unsigned short CNT9;                                   /* CNT9             */
    unsigned char  dummy258[2];                            /* Reserved         */
    unsigned short CNT10;                                  /* CNT10            */
    unsigned char  dummy259[2];                            /* Reserved         */
    unsigned short CNT11;                                  /* CNT11            */
    unsigned char  dummy260[2];                            /* Reserved         */
    unsigned short CNT12;                                  /* CNT12            */
    unsigned char  dummy261[2];                            /* Reserved         */
    unsigned short CNT13;                                  /* CNT13            */
    unsigned char  dummy262[2];                            /* Reserved         */
    unsigned short CNT14;                                  /* CNT14            */
    unsigned char  dummy263[2];                            /* Reserved         */
    unsigned short CNT15;                                  /* CNT15            */
    unsigned char  dummy264[2];                            /* Reserved         */
    unsigned char  CMUR0;                                  /* CMUR0            */
    unsigned char  dummy265[3];                            /* Reserved         */
    unsigned char  CMUR1;                                  /* CMUR1            */
    unsigned char  dummy266[3];                            /* Reserved         */
    unsigned char  CMUR2;                                  /* CMUR2            */
    unsigned char  dummy267[3];                            /* Reserved         */
    unsigned char  CMUR3;                                  /* CMUR3            */
    unsigned char  dummy268[3];                            /* Reserved         */
    unsigned char  CMUR4;                                  /* CMUR4            */
    unsigned char  dummy269[3];                            /* Reserved         */
    unsigned char  CMUR5;                                  /* CMUR5            */
    unsigned char  dummy270[3];                            /* Reserved         */
    unsigned char  CMUR6;                                  /* CMUR6            */
    unsigned char  dummy271[3];                            /* Reserved         */
    unsigned char  CMUR7;                                  /* CMUR7            */
    unsigned char  dummy272[3];                            /* Reserved         */
    unsigned char  CMUR8;                                  /* CMUR8            */
    unsigned char  dummy273[3];                            /* Reserved         */
    unsigned char  CMUR9;                                  /* CMUR9            */
    unsigned char  dummy274[3];                            /* Reserved         */
    unsigned char  CMUR10;                                 /* CMUR10           */
    unsigned char  dummy275[3];                            /* Reserved         */
    unsigned char  CMUR11;                                 /* CMUR11           */
    unsigned char  dummy276[3];                            /* Reserved         */
    unsigned char  CMUR12;                                 /* CMUR12           */
    unsigned char  dummy277[3];                            /* Reserved         */
    unsigned char  CMUR13;                                 /* CMUR13           */
    unsigned char  dummy278[3];                            /* Reserved         */
    unsigned char  CMUR14;                                 /* CMUR14           */
    unsigned char  dummy279[3];                            /* Reserved         */
    unsigned char  CMUR15;                                 /* CMUR15           */
    unsigned char  dummy280[67];                           /* Reserved         */
    unsigned char  CSR0;                                   /* CSR0             */
    unsigned char  dummy281[3];                            /* Reserved         */
    unsigned char  CSR1;                                   /* CSR1             */
    unsigned char  dummy282[3];                            /* Reserved         */
    unsigned char  CSR2;                                   /* CSR2             */
    unsigned char  dummy283[3];                            /* Reserved         */
    unsigned char  CSR3;                                   /* CSR3             */
    unsigned char  dummy284[3];                            /* Reserved         */
    unsigned char  CSR4;                                   /* CSR4             */
    unsigned char  dummy285[3];                            /* Reserved         */
    unsigned char  CSR5;                                   /* CSR5             */
    unsigned char  dummy286[3];                            /* Reserved         */
    unsigned char  CSR6;                                   /* CSR6             */
    unsigned char  dummy287[3];                            /* Reserved         */
    unsigned char  CSR7;                                   /* CSR7             */
    unsigned char  dummy288[3];                            /* Reserved         */
    unsigned char  CSR8;                                   /* CSR8             */
    unsigned char  dummy289[3];                            /* Reserved         */
    unsigned char  CSR9;                                   /* CSR9             */
    unsigned char  dummy290[3];                            /* Reserved         */
    unsigned char  CSR10;                                  /* CSR10            */
    unsigned char  dummy291[3];                            /* Reserved         */
    unsigned char  CSR11;                                  /* CSR11            */
    unsigned char  dummy292[3];                            /* Reserved         */
    unsigned char  CSR12;                                  /* CSR12            */
    unsigned char  dummy293[3];                            /* Reserved         */
    unsigned char  CSR13;                                  /* CSR13            */
    unsigned char  dummy294[3];                            /* Reserved         */
    unsigned char  CSR14;                                  /* CSR14            */
    unsigned char  dummy295[3];                            /* Reserved         */
    unsigned char  CSR15;                                  /* CSR15            */
    unsigned char  dummy296[3];                            /* Reserved         */
    unsigned char  CSC0;                                   /* CSC0             */
    unsigned char  dummy297[3];                            /* Reserved         */
    unsigned char  CSC1;                                   /* CSC1             */
    unsigned char  dummy298[3];                            /* Reserved         */
    unsigned char  CSC2;                                   /* CSC2             */
    unsigned char  dummy299[3];                            /* Reserved         */
    unsigned char  CSC3;                                   /* CSC3             */
    unsigned char  dummy300[3];                            /* Reserved         */
    unsigned char  CSC4;                                   /* CSC4             */
    unsigned char  dummy301[3];                            /* Reserved         */
    unsigned char  CSC5;                                   /* CSC5             */
    unsigned char  dummy302[3];                            /* Reserved         */
    unsigned char  CSC6;                                   /* CSC6             */
    unsigned char  dummy303[3];                            /* Reserved         */
    unsigned char  CSC7;                                   /* CSC7             */
    unsigned char  dummy304[3];                            /* Reserved         */
    unsigned char  CSC8;                                   /* CSC8             */
    unsigned char  dummy305[3];                            /* Reserved         */
    unsigned char  CSC9;                                   /* CSC9             */
    unsigned char  dummy306[3];                            /* Reserved         */
    unsigned char  CSC10;                                  /* CSC10            */
    unsigned char  dummy307[3];                            /* Reserved         */
    unsigned char  CSC11;                                  /* CSC11            */
    unsigned char  dummy308[3];                            /* Reserved         */
    unsigned char  CSC12;                                  /* CSC12            */
    unsigned char  dummy309[3];                            /* Reserved         */
    unsigned char  CSC13;                                  /* CSC13            */
    unsigned char  dummy310[3];                            /* Reserved         */
    unsigned char  CSC14;                                  /* CSC14            */
    unsigned char  dummy311[3];                            /* Reserved         */
    unsigned char  CSC15;                                  /* CSC15            */
    unsigned char  dummy312[3];                            /* Reserved         */
    unsigned short TE;                                     /* TE               */
    unsigned char  dummy313[2];                            /* Reserved         */
    unsigned short TS;                                     /* TS               */
    unsigned char  dummy314[2];                            /* Reserved         */
    unsigned short TT;                                     /* TT               */
    unsigned char  dummy315[54];                           /* Reserved         */
    unsigned short CMOR0;                                  /* CMOR0            */
    unsigned char  dummy316[2];                            /* Reserved         */
    unsigned short CMOR1;                                  /* CMOR1            */
    unsigned char  dummy317[2];                            /* Reserved         */
    unsigned short CMOR2;                                  /* CMOR2            */
    unsigned char  dummy318[2];                            /* Reserved         */
    unsigned short CMOR3;                                  /* CMOR3            */
    unsigned char  dummy319[2];                            /* Reserved         */
    unsigned short CMOR4;                                  /* CMOR4            */
    unsigned char  dummy320[2];                            /* Reserved         */
    unsigned short CMOR5;                                  /* CMOR5            */
    unsigned char  dummy321[2];                            /* Reserved         */
    unsigned short CMOR6;                                  /* CMOR6            */
    unsigned char  dummy322[2];                            /* Reserved         */
    unsigned short CMOR7;                                  /* CMOR7            */
    unsigned char  dummy323[2];                            /* Reserved         */
    unsigned short CMOR8;                                  /* CMOR8            */
    unsigned char  dummy324[2];                            /* Reserved         */
    unsigned short CMOR9;                                  /* CMOR9            */
    unsigned char  dummy325[2];                            /* Reserved         */
    unsigned short CMOR10;                                 /* CMOR10           */
    unsigned char  dummy326[2];                            /* Reserved         */
    unsigned short CMOR11;                                 /* CMOR11           */
    unsigned char  dummy327[2];                            /* Reserved         */
    unsigned short CMOR12;                                 /* CMOR12           */
    unsigned char  dummy328[2];                            /* Reserved         */
    unsigned short CMOR13;                                 /* CMOR13           */
    unsigned char  dummy329[2];                            /* Reserved         */
    unsigned short CMOR14;                                 /* CMOR14           */
    unsigned char  dummy330[2];                            /* Reserved         */
    unsigned short CMOR15;                                 /* CMOR15           */
    unsigned char  dummy331[2];                            /* Reserved         */
    unsigned short TPS;                                    /* TPS              */
    unsigned char  dummy332[6];                            /* Reserved         */
    unsigned short TOM;                                    /* TOM              */
    unsigned char  dummy333[2];                            /* Reserved         */
    unsigned short TOC;                                    /* TOC              */
    unsigned char  dummy334[2];                            /* Reserved         */
    unsigned short TDE;                                    /* TDE              */
    unsigned char  dummy335[14];                           /* Reserved         */
    unsigned short RDE;                                    /* RDE              */
    unsigned char  dummy336[2];                            /* Reserved         */
    unsigned short RDM;                                    /* RDM              */
    unsigned char  dummy337[2];                            /* Reserved         */
    unsigned short RDS;                                    /* RDS              */
    unsigned char  dummy338[2];                            /* Reserved         */
    unsigned short RDC;                                    /* RDC              */
    unsigned char  dummy339[34];                           /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag40
{                                                          /* Module           */
    unsigned long  CDR0;                                   /* CDR0             */
    unsigned long  CDR1;                                   /* CDR1             */
    unsigned long  CDR2;                                   /* CDR2             */
    unsigned long  CDR3;                                   /* CDR3             */
    unsigned long  CNT0;                                   /* CNT0             */
    unsigned long  CNT1;                                   /* CNT1             */
    unsigned long  CNT2;                                   /* CNT2             */
    unsigned long  CNT3;                                   /* CNT3             */
    unsigned char  CMUR0;                                  /* CMUR0            */
    unsigned char  dummy340[3];                            /* Reserved         */
    unsigned char  CMUR1;                                  /* CMUR1            */
    unsigned char  dummy341[3];                            /* Reserved         */
    unsigned char  CMUR2;                                  /* CMUR2            */
    unsigned char  dummy342[3];                            /* Reserved         */
    unsigned char  CMUR3;                                  /* CMUR3            */
    unsigned char  dummy343[3];                            /* Reserved         */
    unsigned char  CSR0;                                   /* CSR0             */
    unsigned char  dummy344[3];                            /* Reserved         */
    unsigned char  CSR1;                                   /* CSR1             */
    unsigned char  dummy345[3];                            /* Reserved         */
    unsigned char  CSR2;                                   /* CSR2             */
    unsigned char  dummy346[3];                            /* Reserved         */
    unsigned char  CSR3;                                   /* CSR3             */
    unsigned char  dummy347[3];                            /* Reserved         */
    unsigned char  CSC0;                                   /* CSC0             */
    unsigned char  dummy348[3];                            /* Reserved         */
    unsigned char  CSC1;                                   /* CSC1             */
    unsigned char  dummy349[3];                            /* Reserved         */
    unsigned char  CSC2;                                   /* CSC2             */
    unsigned char  dummy350[3];                            /* Reserved         */
    unsigned char  CSC3;                                   /* CSC3             */
    unsigned char  dummy351[3];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy352[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy353[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy354[3];                            /* Reserved         */
    unsigned char  TO;                                     /* TO               */
    unsigned char  dummy355[3];                            /* Reserved         */
    unsigned char  TOE;                                    /* TOE              */
    unsigned char  dummy356[3];                            /* Reserved         */
    unsigned char  TOL;                                    /* TOL              */
    unsigned char  dummy357[3];                            /* Reserved         */
    unsigned char  RDT;                                    /* RDT              */
    unsigned char  dummy358[3];                            /* Reserved         */
    unsigned char  RSF;                                    /* RSF              */
    unsigned char  dummy359[19];                           /* Reserved         */
    unsigned short CMOR0;                                  /* CMOR0            */
    unsigned char  dummy360[2];                            /* Reserved         */
    unsigned short CMOR1;                                  /* CMOR1            */
    unsigned char  dummy361[2];                            /* Reserved         */
    unsigned short CMOR2;                                  /* CMOR2            */
    unsigned char  dummy362[2];                            /* Reserved         */
    unsigned short CMOR3;                                  /* CMOR3            */
    unsigned char  dummy363[2];                            /* Reserved         */
    unsigned short TPS;                                    /* TPS              */
    unsigned char  dummy364[2];                            /* Reserved         */
    unsigned char  BRS;                                    /* BRS              */
    unsigned char  dummy365[3];                            /* Reserved         */
    unsigned char  TOM;                                    /* TOM              */
    unsigned char  dummy366[3];                            /* Reserved         */
    unsigned char  TOC;                                    /* TOC              */
    unsigned char  dummy367[3];                            /* Reserved         */
    unsigned char  RDE;                                    /* RDE              */
    unsigned char  dummy368[3];                            /* Reserved         */
    unsigned char  RDM;                                    /* RDM              */
    unsigned char  dummy369[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag41
{                                                          /* Module           */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy370[3];                            /* Reserved         */
    unsigned char  STR;                                    /* STR              */
    unsigned char  dummy371[3];                            /* Reserved         */
    unsigned char  STC;                                    /* STC              */
    unsigned char  dummy372[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
    unsigned char  dummy373[19];                           /* Reserved         */
    unsigned char  QUE0;                                   /* QUE0             */
    unsigned char  dummy374[3];                            /* Reserved         */
    unsigned char  QUE1;                                   /* QUE1             */
    unsigned char  dummy375[3];                            /* Reserved         */
    unsigned char  QUE2;                                   /* QUE2             */
    unsigned char  dummy376[3];                            /* Reserved         */
    unsigned char  QUE3;                                   /* QUE3             */
    unsigned char  dummy377[3];                            /* Reserved         */
    unsigned char  QUE4;                                   /* QUE4             */
    unsigned char  dummy378[3];                            /* Reserved         */
    unsigned char  QUE5;                                   /* QUE5             */
    unsigned char  dummy379[3];                            /* Reserved         */
    unsigned char  QUE6;                                   /* QUE6             */
    unsigned char  dummy380[3];                            /* Reserved         */
    unsigned char  QUE7;                                   /* QUE7             */
    unsigned char  dummy381[3];                            /* Reserved         */
    unsigned long  PVCR00_01;                              /* PVCR00_01        */
    unsigned long  PVCR02_03;                              /* PVCR02_03        */
    unsigned long  PVCR04_05;                              /* PVCR04_05        */
    unsigned long  PVCR06_07;                              /* PVCR06_07        */
    unsigned long  PVCR08_09;                              /* PVCR08_09        */
    unsigned long  PVCR10_11;                              /* PVCR10_11        */
    unsigned long  PVCR12_13;                              /* PVCR12_13        */
    unsigned long  PVCR14_15;                              /* PVCR14_15        */
    unsigned long  PVCR16_17;                              /* PVCR16_17        */
    unsigned long  PVCR18_19;                              /* PVCR18_19        */
    unsigned long  PVCR20_21;                              /* PVCR20_21        */
    unsigned long  PVCR22_23;                              /* PVCR22_23        */
    unsigned long  PVCR24_25;                              /* PVCR24_25        */
    unsigned long  PVCR26_27;                              /* PVCR26_27        */
    unsigned long  PVCR28_29;                              /* PVCR28_29        */
    unsigned long  PVCR30_31;                              /* PVCR30_31        */
    unsigned long  PVCR32_33;                              /* PVCR32_33        */
    unsigned long  PVCR34_35;                              /* PVCR34_35        */
    unsigned long  PVCR36_37;                              /* PVCR36_37        */
    unsigned long  PVCR38_39;                              /* PVCR38_39        */
    unsigned long  PVCR40_41;                              /* PVCR40_41        */
    unsigned long  PVCR42_43;                              /* PVCR42_43        */
    unsigned long  PVCR44_45;                              /* PVCR44_45        */
    unsigned long  PVCR46_47;                              /* PVCR46_47        */
    unsigned long  PVCR48_49;                              /* PVCR48_49        */
    unsigned long  PVCR50_51;                              /* PVCR50_51        */
    unsigned long  PVCR52_53;                              /* PVCR52_53        */
    unsigned long  PVCR54_55;                              /* PVCR54_55        */
    unsigned long  PVCR56_57;                              /* PVCR56_57        */
    unsigned long  PVCR58_59;                              /* PVCR58_59        */
    unsigned long  PVCR60_61;                              /* PVCR60_61        */
    unsigned long  PVCR62_63;                              /* PVCR62_63        */
    unsigned long  PVCR64_65;                              /* PVCR64_65        */
    unsigned long  PVCR66_67;                              /* PVCR66_67        */
    unsigned long  PVCR68_69;                              /* PVCR68_69        */
    unsigned long  PVCR70_71;                              /* PVCR70_71        */
};
struct __tag42
{                                                          /* Module           */
    unsigned short CSDR;                                   /* CSDR             */
    unsigned char  dummy382[2];                            /* Reserved         */
    unsigned short CRDR;                                   /* CRDR             */
    unsigned char  dummy383[2];                            /* Reserved         */
    unsigned short CTDR;                                   /* CTDR             */
    unsigned char  dummy384[2];                            /* Reserved         */
    unsigned char  RDT;                                    /* RDT              */
    unsigned char  dummy385[3];                            /* Reserved         */
    unsigned char  RSF;                                    /* RSF              */
    unsigned char  dummy386[3];                            /* Reserved         */
    unsigned short CNT;                                    /* CNT              */
    unsigned char  dummy387[10];                           /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy388[3];                            /* Reserved         */
    unsigned short CSBR;                                   /* CSBR             */
    unsigned char  dummy389[2];                            /* Reserved         */
    unsigned short CRBR;                                   /* CRBR             */
    unsigned char  dummy390[2];                            /* Reserved         */
    unsigned short CTBR;                                   /* CTBR             */
};
struct __tag43
{                                                          /* Module           */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy391[2];                            /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy392[2];                            /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy393[2];                            /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
    unsigned char  dummy394[2];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy395[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy396[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy397[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag44
{                                                          /* Module           */
    union __tag16 CTL0;                                    /* CTL0             */
    unsigned char  dummy398[3];                            /* Reserved         */
    union __tag17 CTL1;                                    /* CTL1             */
    unsigned char  dummy399[3];                            /* Reserved         */
    union __tag18 CTL2;                                    /* CTL2             */
    unsigned char  dummy400[3];                            /* Reserved         */
    unsigned long  SUBC;                                   /* SUBC             */
    unsigned long  SRBU;                                   /* SRBU             */
    unsigned char  SEC;                                    /* SEC              */
    unsigned char  dummy401[3];                            /* Reserved         */
    unsigned char  MIN;                                    /* MIN              */
    unsigned char  dummy402[3];                            /* Reserved         */
    unsigned char  HOUR;                                   /* HOUR             */
    unsigned char  dummy403[3];                            /* Reserved         */
    unsigned char  WEEK;                                   /* WEEK             */
    unsigned char  dummy404[3];                            /* Reserved         */
    unsigned char  DAY;                                    /* DAY              */
    unsigned char  dummy405[3];                            /* Reserved         */
    unsigned char  MONTH;                                  /* MONTH            */
    unsigned char  dummy406[3];                            /* Reserved         */
    unsigned char  YEAR;                                   /* YEAR             */
    unsigned char  dummy407[3];                            /* Reserved         */
    unsigned long  TIME;                                   /* TIME             */
    unsigned long  CAL;                                    /* CAL              */
    unsigned char  SUBU;                                   /* SUBU             */
    unsigned char  dummy408[3];                            /* Reserved         */
    unsigned long  SCMP;                                   /* SCMP             */
    unsigned char  ALM;                                    /* ALM              */
    unsigned char  dummy409[3];                            /* Reserved         */
    unsigned char  ALH;                                    /* ALH              */
    unsigned char  dummy410[3];                            /* Reserved         */
    unsigned char  ALW;                                    /* ALW              */
    unsigned char  dummy411[3];                            /* Reserved         */
    unsigned char  SECC;                                   /* SECC             */
    unsigned char  dummy412[3];                            /* Reserved         */
    unsigned char  MINC;                                   /* MINC             */
    unsigned char  dummy413[3];                            /* Reserved         */
    unsigned char  HOURC;                                  /* HOURC            */
    unsigned char  dummy414[3];                            /* Reserved         */
    unsigned char  WEEKC;                                  /* WEEKC            */
    unsigned char  dummy415[3];                            /* Reserved         */
    unsigned char  DAYC;                                   /* DAYC             */
    unsigned char  dummy416[3];                            /* Reserved         */
    unsigned char  MONC;                                   /* MONC             */
    unsigned char  dummy417[3];                            /* Reserved         */
    unsigned char  YEARC;                                  /* YEARC            */
    unsigned char  dummy418[3];                            /* Reserved         */
    unsigned long  TIMEC;                                  /* TIMEC            */
    unsigned long  CALC;                                   /* CALC             */
    unsigned char  dummy419[4];                            /* Reserved         */
    union __tag13 EMU;                                     /* EMU              */
};
struct __tag45
{                                                          /* Module           */
    unsigned short CCR0;                                   /* CCR0             */
    unsigned char  dummy420[2];                            /* Reserved         */
    unsigned short CCR1;                                   /* CCR1             */
    unsigned char  dummy421[2];                            /* Reserved         */
    unsigned short CNT;                                    /* CNT              */
    unsigned char  dummy422[2];                            /* Reserved         */
    unsigned char  FLG;                                    /* FLG              */
    unsigned char  dummy423[3];                            /* Reserved         */
    unsigned char  FGC;                                    /* FGC              */
    unsigned char  dummy424[3];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy425[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy426[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy427[3];                            /* Reserved         */
    unsigned char  IOC0;                                   /* IOC0             */
    unsigned char  dummy428[31];                           /* Reserved         */
    unsigned short CTL;                                    /* CTL              */
    unsigned char  dummy429[2];                            /* Reserved         */
    unsigned char  IOC1;                                   /* IOC1             */
    unsigned char  dummy430[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag46
{                                                          /* Module           */
    unsigned short FLG;                                    /* FLG              */
    unsigned char  dummy431[2];                            /* Reserved         */
    unsigned char  ACWE;                                   /* ACWE             */
    unsigned char  dummy432[3];                            /* Reserved         */
    unsigned char  ACTS;                                   /* ACTS             */
    unsigned char  dummy433[3];                            /* Reserved         */
    unsigned char  ACTT;                                   /* ACTT             */
    unsigned char  dummy434[7];                            /* Reserved         */
    unsigned char  OPHS;                                   /* OPHS             */
    unsigned char  dummy435[3];                            /* Reserved         */
    unsigned char  OPHT;                                   /* OPHT             */
    unsigned char  dummy436[7];                            /* Reserved         */
    unsigned short CTL0;                                   /* CTL0             */
    unsigned char  dummy437[2];                            /* Reserved         */
    unsigned char  CTL1;                                   /* CTL1             */
    unsigned char  dummy438[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag47
{                                                          /* Module           */
    unsigned long  CMP;                                    /* CMP              */
    unsigned long  CNT;                                    /* CNT              */
    unsigned char  dummy439[8];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy440[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy441[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy442[7];                            /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy443[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag48
{                                                          /* Module           */
    unsigned char  WDTE;                                   /* WDTE             */
    unsigned char  dummy444[3];                            /* Reserved         */
    unsigned char  EVAC;                                   /* EVAC             */
    unsigned char  dummy445[3];                            /* Reserved         */
    unsigned char  REF;                                    /* REF              */
    unsigned char  dummy446[3];                            /* Reserved         */
    unsigned char  MD;                                     /* MD               */
};
struct __tag49
{                                                          /* Module           */
    union __tag8 VCR00;                                    /* VCR00            */
    union __tag8 VCR01;                                    /* VCR01            */
    union __tag8 VCR02;                                    /* VCR02            */
    union __tag8 VCR03;                                    /* VCR03            */
    union __tag8 VCR04;                                    /* VCR04            */
    union __tag8 VCR05;                                    /* VCR05            */
    union __tag8 VCR06;                                    /* VCR06            */
    union __tag8 VCR07;                                    /* VCR07            */
    union __tag8 VCR08;                                    /* VCR08            */
    union __tag8 VCR09;                                    /* VCR09            */
    union __tag8 VCR10;                                    /* VCR10            */
    union __tag8 VCR11;                                    /* VCR11            */
    union __tag8 VCR12;                                    /* VCR12            */
    union __tag8 VCR13;                                    /* VCR13            */
    union __tag8 VCR14;                                    /* VCR14            */
    union __tag8 VCR15;                                    /* VCR15            */
    union __tag8 VCR16;                                    /* VCR16            */
    union __tag8 VCR17;                                    /* VCR17            */
    union __tag8 VCR18;                                    /* VCR18            */
    union __tag8 VCR19;                                    /* VCR19            */
    union __tag8 VCR20;                                    /* VCR20            */
    union __tag8 VCR21;                                    /* VCR21            */
    union __tag8 VCR22;                                    /* VCR22            */
    union __tag8 VCR23;                                    /* VCR23            */
    union __tag8 VCR24;                                    /* VCR24            */
    union __tag8 VCR25;                                    /* VCR25            */
    union __tag8 VCR26;                                    /* VCR26            */
    union __tag8 VCR27;                                    /* VCR27            */
    union __tag8 VCR28;                                    /* VCR28            */
    union __tag8 VCR29;                                    /* VCR29            */
    union __tag8 VCR30;                                    /* VCR30            */
    union __tag8 VCR31;                                    /* VCR31            */
    union __tag8 VCR32;                                    /* VCR32            */
    union __tag8 VCR33;                                    /* VCR33            */
    union __tag8 VCR34;                                    /* VCR34            */
    union __tag8 VCR35;                                    /* VCR35            */
    union __tag8 VCR36;                                    /* VCR36            */
    union __tag8 VCR37;                                    /* VCR37            */
    union __tag8 VCR38;                                    /* VCR38            */
    union __tag8 VCR39;                                    /* VCR39            */
    union __tag8 VCR40;                                    /* VCR40            */
    union __tag8 VCR41;                                    /* VCR41            */
    union __tag8 VCR42;                                    /* VCR42            */
    union __tag8 VCR43;                                    /* VCR43            */
    union __tag8 VCR44;                                    /* VCR44            */
    union __tag8 VCR45;                                    /* VCR45            */
    union __tag8 VCR46;                                    /* VCR46            */
    union __tag8 VCR47;                                    /* VCR47            */
    union __tag8 VCR48;                                    /* VCR48            */
    union __tag8 VCR49;                                    /* VCR49            */
    unsigned char  dummy447[44];                           /* Reserved         */
    union __tag8 PWDVCR;                                   /* PWDVCR           */
    unsigned char  dummy448[8];                            /* Reserved         */
    union __tag11 DR00;                                    /* DR00             */
    union __tag11 DR02;                                    /* DR02             */
    union __tag11 DR04;                                    /* DR04             */
    union __tag11 DR06;                                    /* DR06             */
    union __tag11 DR08;                                    /* DR08             */
    union __tag11 DR10;                                    /* DR10             */
    union __tag11 DR12;                                    /* DR12             */
    union __tag11 DR14;                                    /* DR14             */
    union __tag11 DR16;                                    /* DR16             */
    union __tag11 DR18;                                    /* DR18             */
    union __tag11 DR20;                                    /* DR20             */
    union __tag11 DR22;                                    /* DR22             */
    union __tag11 DR24;                                    /* DR24             */
    union __tag11 DR26;                                    /* DR26             */
    union __tag11 DR28;                                    /* DR28             */
    union __tag11 DR30;                                    /* DR30             */
    union __tag11 DR32;                                    /* DR32             */
    union __tag11 DR34;                                    /* DR34             */
    union __tag11 DR36;                                    /* DR36             */
    union __tag11 DR38;                                    /* DR38             */
    union __tag11 DR40;                                    /* DR40             */
    union __tag11 DR42;                                    /* DR42             */
    union __tag11 DR44;                                    /* DR44             */
    union __tag11 DR46;                                    /* DR46             */
    union __tag11 DR48;                                    /* DR48             */
    unsigned char  dummy449[20];                           /* Reserved         */
    union __tag11 PWDTSNDR;                                /* PWDTSNDR         */
    unsigned char  dummy450[132];                          /* Reserved         */
    unsigned long  DIR00;                                  /* DIR00            */
    unsigned long  DIR01;                                  /* DIR01            */
    unsigned long  DIR02;                                  /* DIR02            */
    unsigned long  DIR03;                                  /* DIR03            */
    unsigned long  DIR04;                                  /* DIR04            */
    unsigned long  DIR05;                                  /* DIR05            */
    unsigned long  DIR06;                                  /* DIR06            */
    unsigned long  DIR07;                                  /* DIR07            */
    unsigned long  DIR08;                                  /* DIR08            */
    unsigned long  DIR09;                                  /* DIR09            */
    unsigned long  DIR10;                                  /* DIR10            */
    unsigned long  DIR11;                                  /* DIR11            */
    unsigned long  DIR12;                                  /* DIR12            */
    unsigned long  DIR13;                                  /* DIR13            */
    unsigned long  DIR14;                                  /* DIR14            */
    unsigned long  DIR15;                                  /* DIR15            */
    unsigned long  DIR16;                                  /* DIR16            */
    unsigned long  DIR17;                                  /* DIR17            */
    unsigned long  DIR18;                                  /* DIR18            */
    unsigned long  DIR19;                                  /* DIR19            */
    unsigned long  DIR20;                                  /* DIR20            */
    unsigned long  DIR21;                                  /* DIR21            */
    unsigned long  DIR22;                                  /* DIR22            */
    unsigned long  DIR23;                                  /* DIR23            */
    unsigned long  DIR24;                                  /* DIR24            */
    unsigned long  DIR25;                                  /* DIR25            */
    unsigned long  DIR26;                                  /* DIR26            */
    unsigned long  DIR27;                                  /* DIR27            */
    unsigned long  DIR28;                                  /* DIR28            */
    unsigned long  DIR29;                                  /* DIR29            */
    unsigned long  DIR30;                                  /* DIR30            */
    unsigned long  DIR31;                                  /* DIR31            */
    unsigned long  DIR32;                                  /* DIR32            */
    unsigned long  DIR33;                                  /* DIR33            */
    unsigned long  DIR34;                                  /* DIR34            */
    unsigned long  DIR35;                                  /* DIR35            */
    unsigned long  DIR36;                                  /* DIR36            */
    unsigned long  DIR37;                                  /* DIR37            */
    unsigned long  DIR38;                                  /* DIR38            */
    unsigned long  DIR39;                                  /* DIR39            */
    unsigned long  DIR40;                                  /* DIR40            */
    unsigned long  DIR41;                                  /* DIR41            */
    unsigned long  DIR42;                                  /* DIR42            */
    unsigned long  DIR43;                                  /* DIR43            */
    unsigned long  DIR44;                                  /* DIR44            */
    unsigned long  DIR45;                                  /* DIR45            */
    unsigned long  DIR46;                                  /* DIR46            */
    unsigned long  DIR47;                                  /* DIR47            */
    unsigned long  DIR48;                                  /* DIR48            */
    unsigned long  DIR49;                                  /* DIR49            */
    unsigned char  dummy451[44];                           /* Reserved         */
    unsigned long  PWDDIR;                                 /* PWDDIR           */
    unsigned char  dummy452[8];                            /* Reserved         */
    union __tag8 ADHALTR;                                  /* ADHALTR          */
    union __tag8 ADCR;                                     /* ADCR             */
    union __tag11 SGSTR;                                   /* SGSTR            */
    union __tag8 MPXCURR;                                  /* MPXCURR          */
    unsigned char  dummy453[4];                            /* Reserved         */
    union __tag8 THSMPSTCR;                                /* THSMPSTCR        */
    union __tag8 THCR;                                     /* THCR             */
    union __tag8 THAHLDSTCR;                               /* THAHLDSTCR       */
    union __tag8 THBHLDSTCR;                               /* THBHLDSTCR       */
    union __tag8 THACR;                                    /* THACR            */
    union __tag8 THBCR;                                    /* THBCR            */
    union __tag8 THER;                                     /* THER             */
    union __tag8 THGSR;                                    /* THGSR            */
    union __tag8 SFTCR;                                    /* SFTCR            */
    union __tag11 ULLMTBR0;                                /* ULLMTBR0         */
    union __tag11 ULLMTBR1;                                /* ULLMTBR1         */
    union __tag11 ULLMTBR2;                                /* ULLMTBR2         */
    union __tag8 ECR;                                      /* ECR              */
    union __tag8 ULER;                                     /* ULER             */
    union __tag8 OWER;                                     /* OWER             */
    union __tag8 DGCTL0;                                   /* DGCTL0           */
    union __tag11 DGCTL1;                                  /* DGCTL1           */
    union __tag11 PDCTL1;                                  /* PDCTL1           */
    union __tag8 PDCTL2;                                   /* PDCTL2           */
    unsigned char  dummy454[32];                           /* Reserved         */
    union __tag8 SMPCR;                                    /* SMPCR            */
    unsigned char  dummy455[4];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
    unsigned char  dummy456[183];                          /* Reserved         */
    union __tag8 SGSTCR1;                                  /* SGSTCR1          */
    unsigned char  dummy457[4];                            /* Reserved         */
    union __tag8 SGCR1;                                    /* SGCR1            */
    union __tag8 SGVCSP1;                                  /* SGVCSP1          */
    union __tag8 SGVCEP1;                                  /* SGVCEP1          */
    union __tag8 SGMCYCR1;                                 /* SGMCYCR1         */
    union __tag8 SGSEFCR1;                                 /* SGSEFCR1         */
    union __tag11 SGTSEL1;                                 /* SGTSEL1          */
    unsigned char  dummy458[32];                           /* Reserved         */
    union __tag8 SGSTCR2;                                  /* SGSTCR2          */
    unsigned char  dummy459[4];                            /* Reserved         */
    union __tag8 SGCR2;                                    /* SGCR2            */
    union __tag8 SGVCSP2;                                  /* SGVCSP2          */
    union __tag8 SGVCEP2;                                  /* SGVCEP2          */
    union __tag8 SGMCYCR2;                                 /* SGMCYCR2         */
    union __tag8 SGSEFCR2;                                 /* SGSEFCR2         */
    union __tag11 SGTSEL2;                                 /* SGTSEL2          */
    unsigned char  dummy460[32];                           /* Reserved         */
    union __tag8 SGSTCR3;                                  /* SGSTCR3          */
    unsigned char  dummy461[4];                            /* Reserved         */
    union __tag8 SGCR3;                                    /* SGCR3            */
    union __tag8 SGVCSP3;                                  /* SGVCSP3          */
    union __tag8 SGVCEP3;                                  /* SGVCEP3          */
    union __tag8 SGMCYCR3;                                 /* SGMCYCR3         */
    union __tag8 SGSEFCR3;                                 /* SGSEFCR3         */
    union __tag11 SGTSEL3;                                 /* SGTSEL3          */
    unsigned char  dummy462[40];                           /* Reserved         */
    union __tag8 PWDSGCR;                                  /* PWDSGCR          */
    unsigned char  dummy463[12];                           /* Reserved         */
    union __tag8 PWDSGSEFCR;                               /* PWDSGSEFCR       */
};
struct __tag50
{                                                          /* Module           */
    union __tag8 VCR00;                                    /* VCR00            */
    union __tag8 VCR01;                                    /* VCR01            */
    union __tag8 VCR02;                                    /* VCR02            */
    union __tag8 VCR03;                                    /* VCR03            */
    union __tag8 VCR04;                                    /* VCR04            */
    union __tag8 VCR05;                                    /* VCR05            */
    union __tag8 VCR06;                                    /* VCR06            */
    union __tag8 VCR07;                                    /* VCR07            */
    union __tag8 VCR08;                                    /* VCR08            */
    union __tag8 VCR09;                                    /* VCR09            */
    union __tag8 VCR10;                                    /* VCR10            */
    union __tag8 VCR11;                                    /* VCR11            */
    union __tag8 VCR12;                                    /* VCR12            */
    union __tag8 VCR13;                                    /* VCR13            */
    union __tag8 VCR14;                                    /* VCR14            */
    union __tag8 VCR15;                                    /* VCR15            */
    union __tag8 VCR16;                                    /* VCR16            */
    union __tag8 VCR17;                                    /* VCR17            */
    union __tag8 VCR18;                                    /* VCR18            */
    union __tag8 VCR19;                                    /* VCR19            */
    union __tag8 VCR20;                                    /* VCR20            */
    union __tag8 VCR21;                                    /* VCR21            */
    union __tag8 VCR22;                                    /* VCR22            */
    union __tag8 VCR23;                                    /* VCR23            */
    unsigned char  dummy464[148];                          /* Reserved         */
    union __tag8 PWDVCR;                                   /* PWDVCR           */
    unsigned char  dummy465[8];                            /* Reserved         */
    union __tag11 DR00;                                    /* DR00             */
    union __tag11 DR02;                                    /* DR02             */
    union __tag11 DR04;                                    /* DR04             */
    union __tag11 DR06;                                    /* DR06             */
    union __tag11 DR08;                                    /* DR08             */
    union __tag11 DR10;                                    /* DR10             */
    union __tag11 DR12;                                    /* DR12             */
    union __tag11 DR14;                                    /* DR14             */
    union __tag11 DR16;                                    /* DR16             */
    union __tag11 DR18;                                    /* DR18             */
    union __tag11 DR20;                                    /* DR20             */
    union __tag11 DR22;                                    /* DR22             */
    unsigned char  dummy466[72];                           /* Reserved         */
    union __tag11 PWDTSNDR;                                /* PWDTSNDR         */
    unsigned char  dummy467[132];                          /* Reserved         */
    unsigned long  DIR00;                                  /* DIR00            */
    unsigned long  DIR01;                                  /* DIR01            */
    unsigned long  DIR02;                                  /* DIR02            */
    unsigned long  DIR03;                                  /* DIR03            */
    unsigned long  DIR04;                                  /* DIR04            */
    unsigned long  DIR05;                                  /* DIR05            */
    unsigned long  DIR06;                                  /* DIR06            */
    unsigned long  DIR07;                                  /* DIR07            */
    unsigned long  DIR08;                                  /* DIR08            */
    unsigned long  DIR09;                                  /* DIR09            */
    unsigned long  DIR10;                                  /* DIR10            */
    unsigned long  DIR11;                                  /* DIR11            */
    unsigned long  DIR12;                                  /* DIR12            */
    unsigned long  DIR13;                                  /* DIR13            */
    unsigned long  DIR14;                                  /* DIR14            */
    unsigned long  DIR15;                                  /* DIR15            */
    unsigned long  DIR16;                                  /* DIR16            */
    unsigned long  DIR17;                                  /* DIR17            */
    unsigned long  DIR18;                                  /* DIR18            */
    unsigned long  DIR19;                                  /* DIR19            */
    unsigned long  DIR20;                                  /* DIR20            */
    unsigned long  DIR21;                                  /* DIR21            */
    unsigned long  DIR22;                                  /* DIR22            */
    unsigned long  DIR23;                                  /* DIR23            */
    unsigned char  dummy468[148];                          /* Reserved         */
    unsigned long  PWDDIR;                                 /* PWDDIR           */
    unsigned char  dummy469[8];                            /* Reserved         */
    union __tag8 ADHALTR;                                  /* ADHALTR          */
    union __tag8 ADCR;                                     /* ADCR             */
    union __tag11 SGSTR;                                   /* SGSTR            */
    unsigned char  dummy470[40];                           /* Reserved         */
    union __tag8 SFTCR;                                    /* SFTCR            */
    union __tag11 ULLMTBR0;                                /* ULLMTBR0         */
    union __tag11 ULLMTBR1;                                /* ULLMTBR1         */
    union __tag11 ULLMTBR2;                                /* ULLMTBR2         */
    union __tag8 ECR;                                      /* ECR              */
    union __tag8 ULER;                                     /* ULER             */
    union __tag8 OWER;                                     /* OWER             */
    union __tag8 DGCTL0;                                   /* DGCTL0           */
    union __tag11 DGCTL1;                                  /* DGCTL1           */
    union __tag11 PDCTL1;                                  /* PDCTL1           */
    union __tag8 PDCTL2;                                   /* PDCTL2           */
    unsigned char  dummy471[32];                           /* Reserved         */
    union __tag8 SMPCR;                                    /* SMPCR            */
    unsigned char  dummy472[4];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
    unsigned char  dummy473[183];                          /* Reserved         */
    union __tag8 SGSTCR1;                                  /* SGSTCR1          */
    unsigned char  dummy474[4];                            /* Reserved         */
    union __tag8 SGCR1;                                    /* SGCR1            */
    union __tag8 SGVCSP1;                                  /* SGVCSP1          */
    union __tag8 SGVCEP1;                                  /* SGVCEP1          */
    union __tag8 SGMCYCR1;                                 /* SGMCYCR1         */
    union __tag8 SGSEFCR1;                                 /* SGSEFCR1         */
    union __tag11 SGTSEL1;                                 /* SGTSEL1          */
    unsigned char  dummy475[32];                           /* Reserved         */
    union __tag8 SGSTCR2;                                  /* SGSTCR2          */
    unsigned char  dummy476[4];                            /* Reserved         */
    union __tag8 SGCR2;                                    /* SGCR2            */
    union __tag8 SGVCSP2;                                  /* SGVCSP2          */
    union __tag8 SGVCEP2;                                  /* SGVCEP2          */
    union __tag8 SGMCYCR2;                                 /* SGMCYCR2         */
    union __tag8 SGSEFCR2;                                 /* SGSEFCR2         */
    union __tag11 SGTSEL2;                                 /* SGTSEL2          */
    unsigned char  dummy477[32];                           /* Reserved         */
    union __tag8 SGSTCR3;                                  /* SGSTCR3          */
    unsigned char  dummy478[4];                            /* Reserved         */
    union __tag8 SGCR3;                                    /* SGCR3            */
    union __tag8 SGVCSP3;                                  /* SGVCSP3          */
    union __tag8 SGVCEP3;                                  /* SGVCEP3          */
    union __tag8 SGMCYCR3;                                 /* SGMCYCR3         */
    union __tag8 SGSEFCR3;                                 /* SGSEFCR3         */
    union __tag11 SGTSEL3;                                 /* SGTSEL3          */
    unsigned char  dummy479[40];                           /* Reserved         */
    union __tag8 PWDSGCR;                                  /* PWDSGCR          */
    unsigned char  dummy480[12];                           /* Reserved         */
    union __tag8 PWDSGSEFCR;                               /* PWDSGSEFCR       */
};
struct __tag51
{                                                          /* Module           */
    unsigned long  CIN;                                    /* CIN              */
    unsigned long  COUT;                                   /* COUT             */
    unsigned char  dummy481[24];                           /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
};
struct __tag52
{                                                          /* Module           */
    union __tag19 KRM;                                     /* KRM              */
};
struct __tag53
{                                                          /* Module           */
    unsigned char  CTL0;                                   /* CTL0             */
    unsigned char  dummy482[7];                            /* Reserved         */
    unsigned short CMPL;                                   /* CMPL             */
    unsigned char  dummy483[2];                            /* Reserved         */
    unsigned short CMPH;                                   /* CMPH             */
    unsigned char  dummy484[2];                            /* Reserved         */
    unsigned char  PCMD;                                   /* PCMD             */
    unsigned char  dummy485[3];                            /* Reserved         */
    unsigned char  PS;                                     /* PS               */
    unsigned char  dummy486[3];                            /* Reserved         */
    unsigned char  EMU0;                                   /* EMU0             */
};
struct __tag54
{                                                          /* Module           */
    unsigned long  TEST;                                   /* TEST             */
    unsigned long  TESTS;                                  /* TESTS            */
};


#define FLMDCNT            (*(volatile unsigned long  *)0xFFA00000)
#define FLMDPCMD           (*(volatile unsigned long  *)0xFFA00004)
#define FLMDPS             (*(volatile unsigned long  *)0xFFA00008)
#define SELB_TAUJ0I        (*(volatile unsigned char  *)0xFFBC0100)
#define SELB_TAUD0I        (*(volatile unsigned short *)0xFFBC0200)
#define SELB_INTC1         (*(volatile unsigned short *)0xFFBC0300)
#define SELB_INTC2         (*(volatile unsigned short *)0xFFBC0304)
#define SELB_READTEST      (*(volatile unsigned char  *)0xFFBC0600)
#define SLPWGA0            (*(volatile unsigned long  *)0xFFBC1000)
#define SLPWGA1            (*(volatile unsigned long  *)0xFFBC1004)
#define SLPWGA2            (*(volatile unsigned long  *)0xFFBC1008)
#define SCTLR              (*(volatile unsigned long  *)0xFFBC2000)
#define EVFR               (*(volatile unsigned long  *)0xFFBC2004)
#define DPSELR0            (*(volatile unsigned long  *)0xFFBC2008)
#define DPSELRM            (*(volatile unsigned long  *)0xFFBC200C)
#define DPSELRML           (*(volatile unsigned short *)0xFFBC200C)
#define DPSELR1            (*(volatile unsigned char  *)0xFFBC200C)
#define DPSELR2            (*(volatile unsigned char  *)0xFFBC200D)
#define DPSELRMH           (*(volatile unsigned short *)0xFFBC200E)
#define DPSELR3            (*(volatile unsigned char  *)0xFFBC200E)
#define DPSELR4            (*(volatile unsigned char  *)0xFFBC200F)
#define DPSELRH            (*(volatile unsigned long  *)0xFFBC2010)
#define DPSELRHL           (*(volatile unsigned short *)0xFFBC2010)
#define DPSELR5            (*(volatile unsigned char  *)0xFFBC2010)
#define DPSELR6            (*(volatile unsigned char  *)0xFFBC2011)
#define DPSELRHH           (*(volatile unsigned short *)0xFFBC2012)
#define DPSELR7            (*(volatile unsigned char  *)0xFFBC2012)
#define DPDSR0             (*(volatile unsigned long  *)0xFFBC2014)
#define DPDSRM             (*(volatile unsigned long  *)0xFFBC2018)
#define DPDSRML            (*(volatile unsigned short *)0xFFBC2018)
#define DPDSR1             (*(volatile unsigned char  *)0xFFBC2018)
#define DPDSR2             (*(volatile unsigned char  *)0xFFBC2019)
#define DPDSRMH            (*(volatile unsigned short *)0xFFBC201A)
#define DPDSR3             (*(volatile unsigned char  *)0xFFBC201A)
#define DPDSR4             (*(volatile unsigned char  *)0xFFBC201B)
#define DPDSRH             (*(volatile unsigned long  *)0xFFBC201C)
#define DPDSRHL            (*(volatile unsigned short *)0xFFBC201C)
#define DPDSR5             (*(volatile unsigned char  *)0xFFBC201C)
#define DPDSR6             (*(volatile unsigned char  *)0xFFBC201D)
#define DPDSRHH            (*(volatile unsigned short *)0xFFBC201E)
#define DPDSR7             (*(volatile unsigned char  *)0xFFBC201E)
#define DPDIMR0            (*(volatile unsigned long  *)0xFFBC2020)
#define DPDIMR1            (*(volatile unsigned char  *)0xFFBC2024)
#define DPDIMR2            (*(volatile unsigned char  *)0xFFBC2028)
#define DPDIMR3            (*(volatile unsigned char  *)0xFFBC202C)
#define DPDIMR4            (*(volatile unsigned char  *)0xFFBC2030)
#define DPDIMR5            (*(volatile unsigned char  *)0xFFBC2034)
#define DPDIMR6            (*(volatile unsigned char  *)0xFFBC2038)
#define DPDIMR7            (*(volatile unsigned char  *)0xFFBC203C)
#define CNTVAL             (*(volatile unsigned short *)0xFFBC2040)
#define SOSTR              (*(volatile unsigned char  *)0xFFBC2044)
#define P0                 (*(volatile unsigned short *)0xFFC10000)
#define P1                 (*(volatile unsigned short *)0xFFC10004)
#define P2                 (*(volatile unsigned short *)0xFFC10008)
#define P8                 (*(volatile unsigned short *)0xFFC10020)
#define P9                 (*(volatile unsigned short *)0xFFC10024)
#define P10                (*(volatile unsigned short *)0xFFC10028)
#define P11                (*(volatile unsigned short *)0xFFC1002C)
#define P12                (*(volatile unsigned short *)0xFFC10030)
#define P18                (*(volatile unsigned short *)0xFFC10048)
#define P20                (*(volatile unsigned short *)0xFFC10050)
#define AP0                (*(volatile unsigned short *)0xFFC100C8)
#define AP1                (*(volatile unsigned short *)0xFFC100CC)
#define PSR0               (*(volatile unsigned long  *)0xFFC10100)
#define PSR1               (*(volatile unsigned long  *)0xFFC10104)
#define PSR2               (*(volatile unsigned long  *)0xFFC10108)
#define PSR8               (*(volatile unsigned long  *)0xFFC10120)
#define PSR9               (*(volatile unsigned long  *)0xFFC10124)
#define PSR10              (*(volatile unsigned long  *)0xFFC10128)
#define PSR11              (*(volatile unsigned long  *)0xFFC1012C)
#define PSR12              (*(volatile unsigned long  *)0xFFC10130)
#define PSR18              (*(volatile unsigned long  *)0xFFC10148)
#define PSR20              (*(volatile unsigned long  *)0xFFC10150)
#define APSR0              (*(volatile unsigned long  *)0xFFC101C8)
#define APSR1              (*(volatile unsigned long  *)0xFFC101CC)
#define PPR0               (*(volatile unsigned short *)0xFFC10200)
#define PPR1               (*(volatile unsigned short *)0xFFC10204)
#define PPR2               (*(volatile unsigned short *)0xFFC10208)
#define PPR8               (*(volatile unsigned short *)0xFFC10220)
#define PPR9               (*(volatile unsigned short *)0xFFC10224)
#define PPR10              (*(volatile unsigned short *)0xFFC10228)
#define PPR11              (*(volatile unsigned short *)0xFFC1022C)
#define PPR12              (*(volatile unsigned short *)0xFFC10230)
#define PPR18              (*(volatile unsigned short *)0xFFC10248)
#define PPR20              (*(volatile unsigned short *)0xFFC10250)
#define APPR0              (*(volatile unsigned short *)0xFFC102C8)
#define APPR1              (*(volatile unsigned short *)0xFFC102CC)
#define IPPR0              (*(volatile unsigned short *)0xFFC102F0)
#define PM0                (*(volatile unsigned short *)0xFFC10300)
#define PM1                (*(volatile unsigned short *)0xFFC10304)
#define PM2                (*(volatile unsigned short *)0xFFC10308)
#define PM8                (*(volatile unsigned short *)0xFFC10320)
#define PM9                (*(volatile unsigned short *)0xFFC10324)
#define PM10               (*(volatile unsigned short *)0xFFC10328)
#define PM11               (*(volatile unsigned short *)0xFFC1032C)
#define PM12               (*(volatile unsigned short *)0xFFC10330)
#define PM18               (*(volatile unsigned short *)0xFFC10348)
#define PM20               (*(volatile unsigned short *)0xFFC10350)
#define APM0               (*(volatile unsigned short *)0xFFC103C8)
#define APM1               (*(volatile unsigned short *)0xFFC103CC)
#define PMC0               (*(volatile unsigned short *)0xFFC10400)
#define PMC1               (*(volatile unsigned short *)0xFFC10404)
#define PMC2               (*(volatile unsigned short *)0xFFC10408)
#define PMC8               (*(volatile unsigned short *)0xFFC10420)
#define PMC9               (*(volatile unsigned short *)0xFFC10424)
#define PMC10              (*(volatile unsigned short *)0xFFC10428)
#define PMC11              (*(volatile unsigned short *)0xFFC1042C)
#define PMC12              (*(volatile unsigned short *)0xFFC10430)
#define PMC18              (*(volatile unsigned short *)0xFFC10448)
#define PMC20              (*(volatile unsigned short *)0xFFC10450)
#define PFC0               (*(volatile unsigned short *)0xFFC10500)
#define PFC1               (*(volatile unsigned short *)0xFFC10504)
#define PFC8               (*(volatile unsigned short *)0xFFC10520)
#define PFC9               (*(volatile unsigned short *)0xFFC10524)
#define PFC10              (*(volatile unsigned short *)0xFFC10528)
#define PFC11              (*(volatile unsigned short *)0xFFC1052C)
#define PFC12              (*(volatile unsigned short *)0xFFC10530)
#define PFC18              (*(volatile unsigned short *)0xFFC10548)
#define PFC20              (*(volatile unsigned short *)0xFFC10550)
#define PFCE0              (*(volatile unsigned short *)0xFFC10600)
#define PFCE8              (*(volatile unsigned short *)0xFFC10620)
#define PFCE9              (*(volatile unsigned short *)0xFFC10624)
#define PFCE10             (*(volatile unsigned short *)0xFFC10628)
#define PFCE11             (*(volatile unsigned short *)0xFFC1062C)
#define PFCE12             (*(volatile unsigned short *)0xFFC10630)
#define PNOT0              (*(volatile unsigned short *)0xFFC10700)
#define PNOT1              (*(volatile unsigned short *)0xFFC10704)
#define PNOT2              (*(volatile unsigned short *)0xFFC10708)
#define PNOT8              (*(volatile unsigned short *)0xFFC10720)
#define PNOT9              (*(volatile unsigned short *)0xFFC10724)
#define PNOT10             (*(volatile unsigned short *)0xFFC10728)
#define PNOT11             (*(volatile unsigned short *)0xFFC1072C)
#define PNOT12             (*(volatile unsigned short *)0xFFC10730)
#define PNOT18             (*(volatile unsigned short *)0xFFC10748)
#define PNOT20             (*(volatile unsigned short *)0xFFC10750)
#define APNOT0             (*(volatile unsigned short *)0xFFC107C8)
#define APNOT1             (*(volatile unsigned short *)0xFFC107CC)
#define PMSR0              (*(volatile unsigned long  *)0xFFC10800)
#define PMSR1              (*(volatile unsigned long  *)0xFFC10804)
#define PMSR2              (*(volatile unsigned long  *)0xFFC10808)
#define PMSR8              (*(volatile unsigned long  *)0xFFC10820)
#define PMSR9              (*(volatile unsigned long  *)0xFFC10824)
#define PMSR10             (*(volatile unsigned long  *)0xFFC10828)
#define PMSR11             (*(volatile unsigned long  *)0xFFC1082C)
#define PMSR12             (*(volatile unsigned long  *)0xFFC10830)
#define PMSR18             (*(volatile unsigned long  *)0xFFC10848)
#define PMSR20             (*(volatile unsigned long  *)0xFFC10850)
#define APMSR0             (*(volatile unsigned long  *)0xFFC108C8)
#define APMSR1             (*(volatile unsigned long  *)0xFFC108CC)
#define PMCSR0             (*(volatile unsigned long  *)0xFFC10900)
#define PMCSR1             (*(volatile unsigned long  *)0xFFC10904)
#define PMCSR2             (*(volatile unsigned long  *)0xFFC10908)
#define PMCSR8             (*(volatile unsigned long  *)0xFFC10920)
#define PMCSR9             (*(volatile unsigned long  *)0xFFC10924)
#define PMCSR10            (*(volatile unsigned long  *)0xFFC10928)
#define PMCSR11            (*(volatile unsigned long  *)0xFFC1092C)
#define PMCSR12            (*(volatile unsigned long  *)0xFFC10930)
#define PMCSR18            (*(volatile unsigned long  *)0xFFC10948)
#define PMCSR20            (*(volatile unsigned long  *)0xFFC10950)
#define PFCAE0             (*(volatile unsigned short *)0xFFC10A00)
#define PFCAE10            (*(volatile unsigned short *)0xFFC10A28)
#define PFCAE11            (*(volatile unsigned short *)0xFFC10A2C)
#define PIBC0              (*(volatile unsigned short *)0xFFC14000)
#define PIBC1              (*(volatile unsigned short *)0xFFC14004)
#define PIBC2              (*(volatile unsigned short *)0xFFC14008)
#define PIBC8              (*(volatile unsigned short *)0xFFC14020)
#define PIBC9              (*(volatile unsigned short *)0xFFC14024)
#define PIBC10             (*(volatile unsigned short *)0xFFC14028)
#define PIBC11             (*(volatile unsigned short *)0xFFC1402C)
#define PIBC12             (*(volatile unsigned short *)0xFFC14030)
#define PIBC18             (*(volatile unsigned short *)0xFFC14048)
#define PIBC20             (*(volatile unsigned short *)0xFFC14050)
#define APIBC0             (*(volatile unsigned short *)0xFFC140C8)
#define APIBC1             (*(volatile unsigned short *)0xFFC140CC)
#define IPIBC0             (*(volatile unsigned short *)0xFFC140F0)
#define PBDC0              (*(volatile unsigned short *)0xFFC14100)
#define PBDC1              (*(volatile unsigned short *)0xFFC14104)
#define PBDC2              (*(volatile unsigned short *)0xFFC14108)
#define PBDC8              (*(volatile unsigned short *)0xFFC14120)
#define PBDC9              (*(volatile unsigned short *)0xFFC14124)
#define PBDC10             (*(volatile unsigned short *)0xFFC14128)
#define PBDC11             (*(volatile unsigned short *)0xFFC1412C)
#define PBDC12             (*(volatile unsigned short *)0xFFC14130)
#define PBDC18             (*(volatile unsigned short *)0xFFC14148)
#define PBDC20             (*(volatile unsigned short *)0xFFC14150)
#define APBDC0             (*(volatile unsigned short *)0xFFC141C8)
#define APBDC1             (*(volatile unsigned short *)0xFFC141CC)
#define PIPC0              (*(volatile unsigned short *)0xFFC14200)
#define PIPC10             (*(volatile unsigned short *)0xFFC14228)
#define PIPC11             (*(volatile unsigned short *)0xFFC1422C)
#define PU0                (*(volatile unsigned short *)0xFFC14300)
#define PU1                (*(volatile unsigned short *)0xFFC14304)
#define PU2                (*(volatile unsigned short *)0xFFC14308)
#define PU8                (*(volatile unsigned short *)0xFFC14320)
#define PU9                (*(volatile unsigned short *)0xFFC14324)
#define PU10               (*(volatile unsigned short *)0xFFC14328)
#define PU11               (*(volatile unsigned short *)0xFFC1432C)
#define PU12               (*(volatile unsigned short *)0xFFC14330)
#define PU18               (*(volatile unsigned short *)0xFFC14348)
#define PU20               (*(volatile unsigned short *)0xFFC14350)
#define PD0                (*(volatile unsigned short *)0xFFC14400)
#define PD8                (*(volatile unsigned short *)0xFFC14420)
#define PD9                (*(volatile unsigned short *)0xFFC14424)
#define PD10               (*(volatile unsigned short *)0xFFC14428)
#define PD11               (*(volatile unsigned short *)0xFFC1442C)
#define PODC0              (*(volatile unsigned long  *)0xFFC14500)
#define PODC1              (*(volatile unsigned long  *)0xFFC14504)
#define PODC2              (*(volatile unsigned long  *)0xFFC14508)
#define PODC8              (*(volatile unsigned long  *)0xFFC14520)
#define PODC9              (*(volatile unsigned long  *)0xFFC14524)
#define PODC10             (*(volatile unsigned long  *)0xFFC14528)
#define PODC11             (*(volatile unsigned long  *)0xFFC1452C)
#define PODC12             (*(volatile unsigned long  *)0xFFC14530)
#define PODC18             (*(volatile unsigned long  *)0xFFC14548)
#define PODC20             (*(volatile unsigned long  *)0xFFC14550)
#define PDSC0              (*(volatile unsigned long  *)0xFFC14600)
#define PDSC10             (*(volatile unsigned long  *)0xFFC14628)
#define PDSC11             (*(volatile unsigned long  *)0xFFC1462C)
#define PDSC12             (*(volatile unsigned long  *)0xFFC14630)
#define PIS0               (*(volatile unsigned short *)0xFFC14700)
#define PIS1               (*(volatile unsigned short *)0xFFC14704)
#define PIS2               (*(volatile unsigned short *)0xFFC14708)
#define PIS10              (*(volatile unsigned short *)0xFFC14728)
#define PIS11              (*(volatile unsigned short *)0xFFC1472C)
#define PIS12              (*(volatile unsigned short *)0xFFC14730)
#define PIS20              (*(volatile unsigned short *)0xFFC14750)
#define PPROTS0            (*(volatile unsigned long  *)0xFFC14B00)
#define PPROTS1            (*(volatile unsigned long  *)0xFFC14B04)
#define PPROTS2            (*(volatile unsigned long  *)0xFFC14B08)
#define PPROTS8            (*(volatile unsigned long  *)0xFFC14B20)
#define PPROTS9            (*(volatile unsigned long  *)0xFFC14B24)
#define PPROTS10           (*(volatile unsigned long  *)0xFFC14B28)
#define PPROTS11           (*(volatile unsigned long  *)0xFFC14B2C)
#define PPROTS12           (*(volatile unsigned long  *)0xFFC14B30)
#define PPROTS18           (*(volatile unsigned long  *)0xFFC14B48)
#define PPROTS20           (*(volatile unsigned long  *)0xFFC14B50)
#define PPCMD0             (*(volatile unsigned long  *)0xFFC14C00)
#define PPCMD1             (*(volatile unsigned long  *)0xFFC14C04)
#define PPCMD2             (*(volatile unsigned long  *)0xFFC14C08)
#define PPCMD8             (*(volatile unsigned long  *)0xFFC14C20)
#define PPCMD9             (*(volatile unsigned long  *)0xFFC14C24)
#define PPCMD10            (*(volatile unsigned long  *)0xFFC14C28)
#define PPCMD11            (*(volatile unsigned long  *)0xFFC14C2C)
#define PPCMD12            (*(volatile unsigned long  *)0xFFC14C30)
#define PPCMD18            (*(volatile unsigned long  *)0xFFC14C48)
#define PPCMD20            (*(volatile unsigned long  *)0xFFC14C50)
#define JP0                (*(volatile unsigned char  *)0xFFC20000)
#define JPSR0              (*(volatile unsigned long  *)0xFFC20010)
#define JPPR0              (*(volatile unsigned char  *)0xFFC20020)
#define JPM0               (*(volatile unsigned char  *)0xFFC20030)
#define JPMC0              (*(volatile unsigned char  *)0xFFC20040)
#define JPFC0              (*(volatile unsigned char  *)0xFFC20050)
#define JPNOT0             (*(volatile unsigned char  *)0xFFC20070)
#define JPMSR0             (*(volatile unsigned long  *)0xFFC20080)
#define JPMCSR0            (*(volatile unsigned long  *)0xFFC20090)
#define JPIBC0             (*(volatile unsigned char  *)0xFFC20400)
#define JPBDC0             (*(volatile unsigned char  *)0xFFC20410)
#define JPU0               (*(volatile unsigned char  *)0xFFC20430)
#define JPD0               (*(volatile unsigned char  *)0xFFC20440)
#define JPODC0             (*(volatile unsigned long  *)0xFFC20450)
#define JPISA0             (*(volatile unsigned char  *)0xFFC204A0)
#define JPPROTS0           (*(volatile unsigned long  *)0xFFC204B0)
#define JPPCMD0            (*(volatile unsigned long  *)0xFFC204C0)
#define DNFATAUD0ICTL      (*(volatile unsigned char  *)0xFFC30000)
#define DNFATAUD0IEN       (*(volatile unsigned short *)0xFFC30004)
#define DNFATAUD0IENH      (*(volatile unsigned char  *)0xFFC30008)
#define DNFATAUD0IENH0     (((volatile __bitf_T *)0xFFC30008)->bit00)
#define DNFATAUD0IENH1     (((volatile __bitf_T *)0xFFC30008)->bit01)
#define DNFATAUD0IENH2     (((volatile __bitf_T *)0xFFC30008)->bit02)
#define DNFATAUD0IENH3     (((volatile __bitf_T *)0xFFC30008)->bit03)
#define DNFATAUD0IENH4     (((volatile __bitf_T *)0xFFC30008)->bit04)
#define DNFATAUD0IENH5     (((volatile __bitf_T *)0xFFC30008)->bit05)
#define DNFATAUD0IENH6     (((volatile __bitf_T *)0xFFC30008)->bit06)
#define DNFATAUD0IENH7     (((volatile __bitf_T *)0xFFC30008)->bit07)
#define DNFATAUD0IENL      (*(volatile unsigned char  *)0xFFC3000C)
#define DNFATAUD0IENL0     (((volatile __bitf_T *)0xFFC3000C)->bit00)
#define DNFATAUD0IENL1     (((volatile __bitf_T *)0xFFC3000C)->bit01)
#define DNFATAUD0IENL2     (((volatile __bitf_T *)0xFFC3000C)->bit02)
#define DNFATAUD0IENL3     (((volatile __bitf_T *)0xFFC3000C)->bit03)
#define DNFATAUD0IENL4     (((volatile __bitf_T *)0xFFC3000C)->bit04)
#define DNFATAUD0IENL5     (((volatile __bitf_T *)0xFFC3000C)->bit05)
#define DNFATAUD0IENL6     (((volatile __bitf_T *)0xFFC3000C)->bit06)
#define DNFATAUD0IENL7     (((volatile __bitf_T *)0xFFC3000C)->bit07)
#define DNFATAUB0ICTL      (*(volatile unsigned char  *)0xFFC30020)
#define DNFATAUB0IEN       (*(volatile unsigned short *)0xFFC30024)
#define DNFATAUB0IENH      (*(volatile unsigned char  *)0xFFC30028)
#define DNFATAUB0IENH0     (((volatile __bitf_T *)0xFFC30028)->bit00)
#define DNFATAUB0IENH1     (((volatile __bitf_T *)0xFFC30028)->bit01)
#define DNFATAUB0IENH2     (((volatile __bitf_T *)0xFFC30028)->bit02)
#define DNFATAUB0IENH3     (((volatile __bitf_T *)0xFFC30028)->bit03)
#define DNFATAUB0IENH4     (((volatile __bitf_T *)0xFFC30028)->bit04)
#define DNFATAUB0IENH5     (((volatile __bitf_T *)0xFFC30028)->bit05)
#define DNFATAUB0IENH6     (((volatile __bitf_T *)0xFFC30028)->bit06)
#define DNFATAUB0IENH7     (((volatile __bitf_T *)0xFFC30028)->bit07)
#define DNFATAUB0IENL      (*(volatile unsigned char  *)0xFFC3002C)
#define DNFATAUB0IENL0     (((volatile __bitf_T *)0xFFC3002C)->bit00)
#define DNFATAUB0IENL1     (((volatile __bitf_T *)0xFFC3002C)->bit01)
#define DNFATAUB0IENL2     (((volatile __bitf_T *)0xFFC3002C)->bit02)
#define DNFATAUB0IENL3     (((volatile __bitf_T *)0xFFC3002C)->bit03)
#define DNFATAUB0IENL4     (((volatile __bitf_T *)0xFFC3002C)->bit04)
#define DNFATAUB0IENL5     (((volatile __bitf_T *)0xFFC3002C)->bit05)
#define DNFATAUB0IENL6     (((volatile __bitf_T *)0xFFC3002C)->bit06)
#define DNFATAUB0IENL7     (((volatile __bitf_T *)0xFFC3002C)->bit07)
#define DNFATAUB1ICTL      (*(volatile unsigned char  *)0xFFC30040)
#define DNFATAUB1IEN       (*(volatile unsigned short *)0xFFC30044)
#define DNFATAUB1IENH      (*(volatile unsigned char  *)0xFFC30048)
#define DNFATAUB1IENH0     (((volatile __bitf_T *)0xFFC30048)->bit00)
#define DNFATAUB1IENH1     (((volatile __bitf_T *)0xFFC30048)->bit01)
#define DNFATAUB1IENH2     (((volatile __bitf_T *)0xFFC30048)->bit02)
#define DNFATAUB1IENH3     (((volatile __bitf_T *)0xFFC30048)->bit03)
#define DNFATAUB1IENH4     (((volatile __bitf_T *)0xFFC30048)->bit04)
#define DNFATAUB1IENH5     (((volatile __bitf_T *)0xFFC30048)->bit05)
#define DNFATAUB1IENH6     (((volatile __bitf_T *)0xFFC30048)->bit06)
#define DNFATAUB1IENH7     (((volatile __bitf_T *)0xFFC30048)->bit07)
#define DNFATAUB1IENL      (*(volatile unsigned char  *)0xFFC3004C)
#define DNFATAUB1IENL0     (((volatile __bitf_T *)0xFFC3004C)->bit00)
#define DNFATAUB1IENL1     (((volatile __bitf_T *)0xFFC3004C)->bit01)
#define DNFATAUB1IENL2     (((volatile __bitf_T *)0xFFC3004C)->bit02)
#define DNFATAUB1IENL3     (((volatile __bitf_T *)0xFFC3004C)->bit03)
#define DNFATAUB1IENL4     (((volatile __bitf_T *)0xFFC3004C)->bit04)
#define DNFATAUB1IENL5     (((volatile __bitf_T *)0xFFC3004C)->bit05)
#define DNFATAUB1IENL6     (((volatile __bitf_T *)0xFFC3004C)->bit06)
#define DNFATAUB1IENL7     (((volatile __bitf_T *)0xFFC3004C)->bit07)
#define DNFAENCA0ICTL      (*(volatile unsigned char  *)0xFFC30060)
#define DNFAENCA0IEN       (*(volatile unsigned short *)0xFFC30064)
#define DNFAENCA0IENL      (*(volatile unsigned char  *)0xFFC3006C)
#define DNFAENCA0IENL0     (((volatile __bitf_T *)0xFFC3006C)->bit00)
#define DNFAENCA0IENL1     (((volatile __bitf_T *)0xFFC3006C)->bit01)
#define DNFAENCA0IENL2     (((volatile __bitf_T *)0xFFC3006C)->bit02)
#define DNFAENCA0IENL3     (((volatile __bitf_T *)0xFFC3006C)->bit03)
#define DNFAENCA0IENL4     (((volatile __bitf_T *)0xFFC3006C)->bit04)
#define DNFAADCTL0CTL      (*(volatile unsigned char  *)0xFFC300A0)
#define DNFAADCTL0EN       (*(volatile unsigned short *)0xFFC300A4)
#define DNFAADCTL0ENL      (*(volatile unsigned char  *)0xFFC300AC)
#define DNFAADCTL0ENL0     (((volatile __bitf_T *)0xFFC300AC)->bit00)
#define DNFAADCTL0ENL1     (((volatile __bitf_T *)0xFFC300AC)->bit01)
#define DNFAADCTL0ENL2     (((volatile __bitf_T *)0xFFC300AC)->bit02)
#define DNFAADCTL1CTL      (*(volatile unsigned char  *)0xFFC300C0)
#define DNFAADCTL1EN       (*(volatile unsigned short *)0xFFC300C4)
#define DNFAADCTL1ENL      (*(volatile unsigned char  *)0xFFC300CC)
#define DNFAADCTL1ENL0     (((volatile __bitf_T *)0xFFC300CC)->bit00)
#define DNFAADCTL1ENL1     (((volatile __bitf_T *)0xFFC300CC)->bit01)
#define DNFAADCTL1ENL2     (((volatile __bitf_T *)0xFFC300CC)->bit02)
#define FCLA0CTL0_NMI      (*(volatile unsigned char  *)0xFFC34000)
#define FCLA0CTL0_INTPL    (*(volatile unsigned char  *)0xFFC34020)
#define FCLA0CTL1_INTPL    (*(volatile unsigned char  *)0xFFC34024)
#define FCLA0CTL2_INTPL    (*(volatile unsigned char  *)0xFFC34028)
#define FCLA0CTL3_INTPL    (*(volatile unsigned char  *)0xFFC3402C)
#define FCLA0CTL4_INTPL    (*(volatile unsigned char  *)0xFFC34030)
#define FCLA0CTL5_INTPL    (*(volatile unsigned char  *)0xFFC34034)
#define FCLA0CTL6_INTPL    (*(volatile unsigned char  *)0xFFC34038)
#define FCLA0CTL7_INTPL    (*(volatile unsigned char  *)0xFFC3403C)
#define FCLA0CTL0_INTPH    (*(volatile unsigned char  *)0xFFC34040)
#define FCLA0CTL1_INTPH    (*(volatile unsigned char  *)0xFFC34044)
#define FCLA0CTL2_INTPH    (*(volatile unsigned char  *)0xFFC34048)
#define FCLA0CTL3_INTPH    (*(volatile unsigned char  *)0xFFC3404C)
#define FCLA0CTL4_INTPH    (*(volatile unsigned char  *)0xFFC34050)
#define FCLA0CTL5_INTPH    (*(volatile unsigned char  *)0xFFC34054)
#define FCLA0CTL6_INTPH    (*(volatile unsigned char  *)0xFFC34058)
#define FCLA0CTL7_INTPH    (*(volatile unsigned char  *)0xFFC3405C)
#define FCLA0CTL0_ADC0     (*(volatile unsigned char  *)0xFFC34060)
#define FCLA0CTL1_ADC0     (*(volatile unsigned char  *)0xFFC34064)
#define FCLA0CTL2_ADC0     (*(volatile unsigned char  *)0xFFC34068)
#define FCLA0CTL0_ADC1     (*(volatile unsigned char  *)0xFFC34080)
#define FCLA0CTL1_ADC1     (*(volatile unsigned char  *)0xFFC34084)
#define FCLA0CTL2_ADC1     (*(volatile unsigned char  *)0xFFC34088)
#define EEPRDCYCL          (*(volatile unsigned char  *)0xFFC5A010)
#define CFECCCTL           (*(volatile unsigned short *)0xFFC62000)
#define CFFSTERSTR         (*(volatile unsigned long  *)0xFFC62004)
#define CFFSTSTC           (*(volatile unsigned char  *)0xFFC62024)
#define CFOVFSTR           (*(volatile unsigned char  *)0xFFC62028)
#define CFOVFSTC           (*(volatile unsigned char  *)0xFFC6202C)
#define CFERRINT           (*(volatile unsigned char  *)0xFFC62030)
#define CFFSTEADR          (*(volatile unsigned long  *)0xFFC62034)
#define CFTSTCTL           (*(volatile unsigned short *)0xFFC62054)
#define LRECCCTL           (*(volatile unsigned short *)0xFFC63000)
#define LRFSTERSTR         (*(volatile unsigned long  *)0xFFC63004)
#define LRSTCLR            (*(volatile unsigned char  *)0xFFC63024)
#define LROVFSTR           (*(volatile unsigned char  *)0xFFC63028)
#define LROVFSTC           (*(volatile unsigned char  *)0xFFC6302C)
#define LRFSTEADR0         (*(volatile unsigned long  *)0xFFC63030)
#define LRERRINT           (*(volatile unsigned char  *)0xFFC630B0)
#define LRTSTCTL           (*(volatile unsigned short *)0xFFC630B4)
#define LRTDATBF0          (*(volatile unsigned long  *)0xFFC630B8)
#define DFECCCTL           (*(volatile unsigned short *)0xFFC66000)
#define DFERSTR            (*(volatile unsigned long  *)0xFFC66004)
#define DFERSTC            (*(volatile unsigned char  *)0xFFC66008)
#define DFERRINT           (*(volatile unsigned char  *)0xFFC66014)
#define DFTSTCTL           (*(volatile unsigned short *)0xFFC6601C)
#define ECCCSIH0CTL        (*(volatile unsigned short *)0xFFC70000)
#define ECCCSIH0TMC        (*(volatile unsigned short *)0xFFC70004)
#define ECCCSIH0TRC        (*(volatile unsigned long  *)0xFFC70008)
#define ECCCSIH0ERDB       (*(volatile unsigned char  *)0xFFC70008)
#define ECCCSIH0ECRD       (*(volatile unsigned char  *)0xFFC70009)
#define ECCCSIH0HORD       (*(volatile unsigned char  *)0xFFC7000A)
#define ECCCSIH0SYND       (*(volatile unsigned char  *)0xFFC7000B)
#define ECCCSIH0TED        (*(volatile unsigned long  *)0xFFC7000C)
#define ECCCSIH1CTL        (*(volatile unsigned short *)0xFFC70010)
#define ECCCSIH1TMC        (*(volatile unsigned short *)0xFFC70014)
#define ECCCSIH1TRC        (*(volatile unsigned long  *)0xFFC70018)
#define ECCCSIH1ERDB       (*(volatile unsigned char  *)0xFFC70018)
#define ECCCSIH1ECRD       (*(volatile unsigned char  *)0xFFC70019)
#define ECCCSIH1HORD       (*(volatile unsigned char  *)0xFFC7001A)
#define ECCCSIH1SYND       (*(volatile unsigned char  *)0xFFC7001B)
#define ECCCSIH1TED        (*(volatile unsigned long  *)0xFFC7001C)
#define ECCCSIH2CTL        (*(volatile unsigned short *)0xFFC70020)
#define ECCCSIH2TMC        (*(volatile unsigned short *)0xFFC70024)
#define ECCCSIH2TRC        (*(volatile unsigned long  *)0xFFC70028)
#define ECCCSIH2ERDB       (*(volatile unsigned char  *)0xFFC70028)
#define ECCCSIH2ECRD       (*(volatile unsigned char  *)0xFFC70029)
#define ECCCSIH2HORD       (*(volatile unsigned char  *)0xFFC7002A)
#define ECCCSIH2SYND       (*(volatile unsigned char  *)0xFFC7002B)
#define ECCCSIH2TED        (*(volatile unsigned long  *)0xFFC7002C)
#define ECCCSIH3CTL        (*(volatile unsigned short *)0xFFC70030)
#define ECCCSIH3TMC        (*(volatile unsigned short *)0xFFC70034)
#define ECCCSIH3TRC        (*(volatile unsigned long  *)0xFFC70038)
#define ECCCSIH3ERDB       (*(volatile unsigned char  *)0xFFC70038)
#define ECCCSIH3ECRD       (*(volatile unsigned char  *)0xFFC70039)
#define ECCCSIH3HORD       (*(volatile unsigned char  *)0xFFC7003A)
#define ECCCSIH3SYND       (*(volatile unsigned char  *)0xFFC7003B)
#define ECCCSIH3TED        (*(volatile unsigned long  *)0xFFC7003C)
#define ECCRCAN0CTL        (*(volatile unsigned short *)0xFFC71000)
#define ECCRCAN0TMC        (*(volatile unsigned short *)0xFFC71004)
#define ECCRCAN0TRC        (*(volatile unsigned long  *)0xFFC71008)
#define ECCRCAN0ERDB       (*(volatile unsigned char  *)0xFFC71008)
#define ECCRCAN0ECRD       (*(volatile unsigned char  *)0xFFC71009)
#define ECCRCAN0HORD       (*(volatile unsigned char  *)0xFFC7100A)
#define ECCRCAN0SYND       (*(volatile unsigned char  *)0xFFC7100B)
#define ECCRCAN0TED        (*(volatile unsigned long  *)0xFFC7100C)
#define CVMF               (*(volatile unsigned long  *)0xFFF50000)
#define CVMDE              (*(volatile unsigned long  *)0xFFF50004)
#define CVMDIAG            (*(volatile unsigned long  *)0xFFF50014)
#define PROTCMDCVM         (*(volatile unsigned long  *)0xFFF50100)
#define PROTSCVM           (*(volatile unsigned long  *)0xFFF50104)
#define PROTCMD0           (*(volatile unsigned long  *)0xFFF80000)
#define PROTS0             (*(volatile unsigned long  *)0xFFF80004)
#define STBC0PSC           (*(volatile unsigned long  *)0xFFF80100)
#define STBC0STPT          (*(volatile unsigned long  *)0xFFF80110)
#define WDTNMIF            (*(volatile unsigned long  *)0xFFF80200)
#define WDTNMIFC           (*(volatile unsigned long  *)0xFFF80208)
#define FEINTF             (*(volatile unsigned long  *)0xFFF80300)
#define FEINTFMSK          (*(volatile unsigned long  *)0xFFF80304)
#define FEINTFC            (*(volatile unsigned long  *)0xFFF80308)
#define WUF0               (*(volatile unsigned long  *)0xFFF80400)
#define WUFMSK0            (*(volatile unsigned long  *)0xFFF80404)
#define WUFC0              (*(volatile unsigned long  *)0xFFF80408)
#define WUF20              (*(volatile unsigned long  *)0xFFF80520)
#define WUFMSK20           (*(volatile unsigned long  *)0xFFF80524)
#define WUFC20             (*(volatile unsigned long  *)0xFFF80528)
#define RESF               (*(volatile unsigned long  *)0xFFF80760)
#define RESFC              (*(volatile unsigned long  *)0xFFF80768)
#define RESFR              (*(volatile unsigned long  *)0xFFF80860)
#define RESFCR             (*(volatile unsigned long  *)0xFFF80868)
#define VLVF               (*(volatile unsigned long  *)0xFFF80980)
#define VLVFC              (*(volatile unsigned long  *)0xFFF80988)
#define LVICNT             (*(volatile unsigned long  *)0xFFF80A00)
#define SWRESA             (*(volatile unsigned long  *)0xFFF80A04)
#define IOHOLD             (*(volatile unsigned long  *)0xFFF80B00)
#define ROSCE              (*(volatile unsigned long  *)0xFFF81000)
#define ROSCS              (*(volatile unsigned long  *)0xFFF81004)
#define ROSCSTPM           (*(volatile unsigned long  *)0xFFF81018)
#define MOSCE              (*(volatile unsigned long  *)0xFFF81100)
#define MOSCS              (*(volatile unsigned long  *)0xFFF81104)
#define MOSCC              (*(volatile unsigned long  *)0xFFF81108)
#define MOSCST             (*(volatile unsigned long  *)0xFFF8110C)
#define MOSCSTPM           (*(volatile unsigned long  *)0xFFF81118)
#define SOSCE              (*(volatile unsigned long  *)0xFFF81200)
#define SOSCS              (*(volatile unsigned long  *)0xFFF81204)
#define SOSCST             (*(volatile unsigned long  *)0xFFF8120C)
#define CKSC_AWDTAD_CTL    (*(volatile unsigned long  *)0xFFF82000)
#define CKSC_AWDTAD_ACT    (*(volatile unsigned long  *)0xFFF82008)
#define CKSC_AWDTAD_STPM   (*(volatile unsigned long  *)0xFFF82018)
#define CKSC_ATAUJS_CTL    (*(volatile unsigned long  *)0xFFF82100)
#define CKSC_ATAUJS_ACT    (*(volatile unsigned long  *)0xFFF82108)
#define CKSC_ATAUJD_CTL    (*(volatile unsigned long  *)0xFFF82200)
#define CKSC_ATAUJD_ACT    (*(volatile unsigned long  *)0xFFF82208)
#define CKSC_ATAUJD_STPM   (*(volatile unsigned long  *)0xFFF82218)
#define CKSC_ARTCAS_CTL    (*(volatile unsigned long  *)0xFFF82300)
#define CKSC_ARTCAS_ACT    (*(volatile unsigned long  *)0xFFF82308)
#define CKSC_ARTCAD_CTL    (*(volatile unsigned long  *)0xFFF82400)
#define CKSC_ARTCAD_ACT    (*(volatile unsigned long  *)0xFFF82408)
#define CKSC_ARTCAD_STPM   (*(volatile unsigned long  *)0xFFF82418)
#define CKSC_AADCAS_CTL    (*(volatile unsigned long  *)0xFFF82500)
#define CKSC_AADCAS_ACT    (*(volatile unsigned long  *)0xFFF82508)
#define CKSC_AADCAD_CTL    (*(volatile unsigned long  *)0xFFF82600)
#define CKSC_AADCAD_ACT    (*(volatile unsigned long  *)0xFFF82608)
#define CKSC_AADCAD_STPM   (*(volatile unsigned long  *)0xFFF82618)
#define CKSC_AFOUTS_CTL    (*(volatile unsigned long  *)0xFFF82700)
#define CKSC_AFOUTS_ACT    (*(volatile unsigned long  *)0xFFF82708)
#define CKSC_AFOUTS_STPM   (*(volatile unsigned long  *)0xFFF82718)
#define FOUTDIV            (*(volatile unsigned long  *)0xFFF82800)
#define FOUTSTAT           (*(volatile unsigned long  *)0xFFF82804)
#define PROTCMD1           (*(volatile unsigned long  *)0xFFF88000)
#define PROTS1             (*(volatile unsigned long  *)0xFFF88004)
#define WUF_ISO0           (*(volatile unsigned long  *)0xFFF88110)
#define WUFMSK_ISO0        (*(volatile unsigned long  *)0xFFF88114)
#define WUFC_ISO0          (*(volatile unsigned long  *)0xFFF88118)
#define PLLE               (*(volatile unsigned long  *)0xFFF89000)
#define PLLS               (*(volatile unsigned long  *)0xFFF89004)
#define PLLC               (*(volatile unsigned long  *)0xFFF89008)
#define CKSC_CPUCLKS_CTL   (*(volatile unsigned long  *)0xFFF8A000)
#define CKSC_CPUCLKS_ACT   (*(volatile unsigned long  *)0xFFF8A008)
#define CKSC_CPUCLKD_CTL   (*(volatile unsigned long  *)0xFFF8A100)
#define CKSC_CPUCLKD_ACT   (*(volatile unsigned long  *)0xFFF8A108)
#define CKSC_IPERI1S_CTL   (*(volatile unsigned long  *)0xFFF8A200)
#define CKSC_IPERI1S_ACT   (*(volatile unsigned long  *)0xFFF8A208)
#define CKSC_IPERI2S_CTL   (*(volatile unsigned long  *)0xFFF8A300)
#define CKSC_IPERI2S_ACT   (*(volatile unsigned long  *)0xFFF8A308)
#define CKSC_ILINS_CTL     (*(volatile unsigned long  *)0xFFF8A400)
#define CKSC_ILINS_ACT     (*(volatile unsigned long  *)0xFFF8A408)
#define CKSC_IADCAS_CTL    (*(volatile unsigned long  *)0xFFF8A500)
#define CKSC_IADCAS_ACT    (*(volatile unsigned long  *)0xFFF8A508)
#define CKSC_IADCAD_CTL    (*(volatile unsigned long  *)0xFFF8A600)
#define CKSC_IADCAD_ACT    (*(volatile unsigned long  *)0xFFF8A608)
#define CKSC_ILIND_CTL     (*(volatile unsigned long  *)0xFFF8A800)
#define CKSC_ILIND_ACT     (*(volatile unsigned long  *)0xFFF8A808)
#define CKSC_ILIND_STPM    (*(volatile unsigned long  *)0xFFF8A818)
#define CKSC_ICANS_CTL     (*(volatile unsigned long  *)0xFFF8A900)
#define CKSC_ICANS_ACT     (*(volatile unsigned long  *)0xFFF8A908)
#define CKSC_ICANS_STPM    (*(volatile unsigned long  *)0xFFF8A918)
#define CKSC_ICANOSCD_CTL  (*(volatile unsigned long  *)0xFFF8AA00)
#define CKSC_ICANOSCD_ACT  (*(volatile unsigned long  *)0xFFF8AA08)
#define CKSC_ICANOSCD_STPM (*(volatile unsigned long  *)0xFFF8AA18)
#define CKSC_ICSIS_CTL     (*(volatile unsigned long  *)0xFFF8AB00)
#define CKSC_ICSIS_ACT     (*(volatile unsigned long  *)0xFFF8AB08)
#define PROTCMDCLMA        (*(volatile unsigned long  *)0xFFF8C200)
#define PROTSCLMA          (*(volatile unsigned long  *)0xFFF8C204)
#define BSC                (*(volatile unsigned short *)0xFFFF8200)
#define DEC                (*(volatile unsigned short *)0xFFFF8202)
#define DWC                (*(volatile unsigned short *)0xFFFF8208)
#define DHC                (*(volatile unsigned short *)0xFFFF820C)
#define AWC                (*(volatile unsigned short *)0xFFFF8210)
#define ICC                (*(volatile unsigned short *)0xFFFF8214)
#define DTRC0              (*(volatile unsigned char  *)0xFFFF8300)
#define DTRC0ADS           (((volatile __bitf_T *)0xFFFF8300)->bit00)
#define DTRC0ERR           (((volatile __bitf_T *)0xFFFF8300)->bit07)
#define DMCM0              (*(volatile unsigned short *)0xFFFF8304)
#define DSA0               (*(volatile unsigned long  *)0xFFFF8314)
#define DSA0L              (*(volatile unsigned short *)0xFFFF8314)
#define DSA0H              (*(volatile unsigned short *)0xFFFF8316)
#define DDA0               (*(volatile unsigned long  *)0xFFFF8324)
#define DDA0L              (*(volatile unsigned short *)0xFFFF8324)
#define DDA0H              (*(volatile unsigned short *)0xFFFF8326)
#define DTC0               (*(volatile unsigned short *)0xFFFF8332)
#define DTCT0              (*(volatile unsigned short *)0xFFFF8338)
#define DTS0               (*(volatile unsigned char  *)0xFFFF833A)
#define DTS0DTE            (((volatile __bitf_T *)0xFFFF833A)->bit00)
#define DTS0SR             (((volatile __bitf_T *)0xFFFF833A)->bit01)
#define DTS0DR             (((volatile __bitf_T *)0xFFFF833A)->bit02)
#define DTS0ER             (((volatile __bitf_T *)0xFFFF833A)->bit03)
#define DTS0DT             (((volatile __bitf_T *)0xFFFF833A)->bit06)
#define DTS0TC             (((volatile __bitf_T *)0xFFFF833A)->bit07)
#define DSA1               (*(volatile unsigned long  *)0xFFFF8344)
#define DSA1L              (*(volatile unsigned short *)0xFFFF8344)
#define DSA1H              (*(volatile unsigned short *)0xFFFF8346)
#define DDA1               (*(volatile unsigned long  *)0xFFFF8354)
#define DDA1L              (*(volatile unsigned short *)0xFFFF8354)
#define DDA1H              (*(volatile unsigned short *)0xFFFF8356)
#define DTC1               (*(volatile unsigned short *)0xFFFF8362)
#define DTCT1              (*(volatile unsigned short *)0xFFFF8368)
#define DTS1               (*(volatile unsigned char  *)0xFFFF836A)
#define DTS1DTE            (((volatile __bitf_T *)0xFFFF836A)->bit00)
#define DTS1SR             (((volatile __bitf_T *)0xFFFF836A)->bit01)
#define DTS1DR             (((volatile __bitf_T *)0xFFFF836A)->bit02)
#define DTS1ER             (((volatile __bitf_T *)0xFFFF836A)->bit03)
#define DTS1DT             (((volatile __bitf_T *)0xFFFF836A)->bit06)
#define DTS1TC             (((volatile __bitf_T *)0xFFFF836A)->bit07)
#define DSA2               (*(volatile unsigned long  *)0xFFFF8374)
#define DSA2L              (*(volatile unsigned short *)0xFFFF8374)
#define DSA2H              (*(volatile unsigned short *)0xFFFF8376)
#define DDA2               (*(volatile unsigned long  *)0xFFFF8384)
#define DDA2L              (*(volatile unsigned short *)0xFFFF8384)
#define DDA2H              (*(volatile unsigned short *)0xFFFF8386)
#define DTC2               (*(volatile unsigned short *)0xFFFF8392)
#define DTCT2              (*(volatile unsigned short *)0xFFFF8398)
#define DTS2               (*(volatile unsigned char  *)0xFFFF839A)
#define DTS2DTE            (((volatile __bitf_T *)0xFFFF839A)->bit00)
#define DTS2SR             (((volatile __bitf_T *)0xFFFF839A)->bit01)
#define DTS2DR             (((volatile __bitf_T *)0xFFFF839A)->bit02)
#define DTS2ER             (((volatile __bitf_T *)0xFFFF839A)->bit03)
#define DTS2DT             (((volatile __bitf_T *)0xFFFF839A)->bit06)
#define DTS2TC             (((volatile __bitf_T *)0xFFFF839A)->bit07)
#define DSA3               (*(volatile unsigned long  *)0xFFFF83A4)
#define DSA3L              (*(volatile unsigned short *)0xFFFF83A4)
#define DSA3H              (*(volatile unsigned short *)0xFFFF83A6)
#define DDA3               (*(volatile unsigned long  *)0xFFFF83B4)
#define DDA3L              (*(volatile unsigned short *)0xFFFF83B4)
#define DDA3H              (*(volatile unsigned short *)0xFFFF83B6)
#define DTC3               (*(volatile unsigned short *)0xFFFF83C2)
#define DTCT3              (*(volatile unsigned short *)0xFFFF83C8)
#define DTS3               (*(volatile unsigned char  *)0xFFFF83CA)
#define DTS3DTE            (((volatile __bitf_T *)0xFFFF83CA)->bit00)
#define DTS3SR             (((volatile __bitf_T *)0xFFFF83CA)->bit01)
#define DTS3DR             (((volatile __bitf_T *)0xFFFF83CA)->bit02)
#define DTS3ER             (((volatile __bitf_T *)0xFFFF83CA)->bit03)
#define DTS3DT             (((volatile __bitf_T *)0xFFFF83CA)->bit06)
#define DTS3TC             (((volatile __bitf_T *)0xFFFF83CA)->bit07)
#define DSA4               (*(volatile unsigned long  *)0xFFFF83D4)
#define DSA4L              (*(volatile unsigned short *)0xFFFF83D4)
#define DSA4H              (*(volatile unsigned short *)0xFFFF83D6)
#define DDA4               (*(volatile unsigned long  *)0xFFFF83E4)
#define DDA4L              (*(volatile unsigned short *)0xFFFF83E4)
#define DDA4H              (*(volatile unsigned short *)0xFFFF83E6)
#define DTC4               (*(volatile unsigned short *)0xFFFF83F2)
#define DTCT4              (*(volatile unsigned short *)0xFFFF83F8)
#define DTS4               (*(volatile unsigned char  *)0xFFFF83FA)
#define DTS4DTE            (((volatile __bitf_T *)0xFFFF83FA)->bit00)
#define DTS4SR             (((volatile __bitf_T *)0xFFFF83FA)->bit01)
#define DTS4DR             (((volatile __bitf_T *)0xFFFF83FA)->bit02)
#define DTS4ER             (((volatile __bitf_T *)0xFFFF83FA)->bit03)
#define DTS4DT             (((volatile __bitf_T *)0xFFFF83FA)->bit06)
#define DTS4TC             (((volatile __bitf_T *)0xFFFF83FA)->bit07)
#define DSA5               (*(volatile unsigned long  *)0xFFFF8404)
#define DSA5L              (*(volatile unsigned short *)0xFFFF8404)
#define DSA5H              (*(volatile unsigned short *)0xFFFF8406)
#define DDA5               (*(volatile unsigned long  *)0xFFFF8414)
#define DDA5L              (*(volatile unsigned short *)0xFFFF8414)
#define DDA5H              (*(volatile unsigned short *)0xFFFF8416)
#define DTC5               (*(volatile unsigned short *)0xFFFF8422)
#define DTCT5              (*(volatile unsigned short *)0xFFFF8428)
#define DTS5               (*(volatile unsigned char  *)0xFFFF842A)
#define DTS5DTE            (((volatile __bitf_T *)0xFFFF842A)->bit00)
#define DTS5SR             (((volatile __bitf_T *)0xFFFF842A)->bit01)
#define DTS5DR             (((volatile __bitf_T *)0xFFFF842A)->bit02)
#define DTS5ER             (((volatile __bitf_T *)0xFFFF842A)->bit03)
#define DTS5DT             (((volatile __bitf_T *)0xFFFF842A)->bit06)
#define DTS5TC             (((volatile __bitf_T *)0xFFFF842A)->bit07)
#define DSA6               (*(volatile unsigned long  *)0xFFFF8434)
#define DSA6L              (*(volatile unsigned short *)0xFFFF8434)
#define DSA6H              (*(volatile unsigned short *)0xFFFF8436)
#define DDA6               (*(volatile unsigned long  *)0xFFFF8444)
#define DDA6L              (*(volatile unsigned short *)0xFFFF8444)
#define DDA6H              (*(volatile unsigned short *)0xFFFF8446)
#define DTC6               (*(volatile unsigned short *)0xFFFF8452)
#define DTCT6              (*(volatile unsigned short *)0xFFFF8458)
#define DTS6               (*(volatile unsigned char  *)0xFFFF845A)
#define DTS6DTE            (((volatile __bitf_T *)0xFFFF845A)->bit00)
#define DTS6SR             (((volatile __bitf_T *)0xFFFF845A)->bit01)
#define DTS6DR             (((volatile __bitf_T *)0xFFFF845A)->bit02)
#define DTS6ER             (((volatile __bitf_T *)0xFFFF845A)->bit03)
#define DTS6DT             (((volatile __bitf_T *)0xFFFF845A)->bit06)
#define DTS6TC             (((volatile __bitf_T *)0xFFFF845A)->bit07)
#define DSA7               (*(volatile unsigned long  *)0xFFFF8464)
#define DSA7L              (*(volatile unsigned short *)0xFFFF8464)
#define DSA7H              (*(volatile unsigned short *)0xFFFF8466)
#define DDA7               (*(volatile unsigned long  *)0xFFFF8474)
#define DDA7L              (*(volatile unsigned short *)0xFFFF8474)
#define DDA7H              (*(volatile unsigned short *)0xFFFF8476)
#define DTC7               (*(volatile unsigned short *)0xFFFF8482)
#define DTCT7              (*(volatile unsigned short *)0xFFFF8488)
#define DTS7               (*(volatile unsigned char  *)0xFFFF848A)
#define DTS7DTE            (((volatile __bitf_T *)0xFFFF848A)->bit00)
#define DTS7SR             (((volatile __bitf_T *)0xFFFF848A)->bit01)
#define DTS7DR             (((volatile __bitf_T *)0xFFFF848A)->bit02)
#define DTS7ER             (((volatile __bitf_T *)0xFFFF848A)->bit03)
#define DTS7DT             (((volatile __bitf_T *)0xFFFF848A)->bit06)
#define DTS7TC             (((volatile __bitf_T *)0xFFFF848A)->bit07)
#define DSA8               (*(volatile unsigned long  *)0xFFFF8514)
#define DSA8L              (*(volatile unsigned short *)0xFFFF8514)
#define DSA8H              (*(volatile unsigned short *)0xFFFF8516)
#define DDA8               (*(volatile unsigned long  *)0xFFFF8524)
#define DDA8L              (*(volatile unsigned short *)0xFFFF8524)
#define DDA8H              (*(volatile unsigned short *)0xFFFF8526)
#define DTC8               (*(volatile unsigned short *)0xFFFF8532)
#define DTCT8              (*(volatile unsigned short *)0xFFFF8538)
#define DTS8               (*(volatile unsigned char  *)0xFFFF853A)
#define DTS8DTE            (((volatile __bitf_T *)0xFFFF853A)->bit00)
#define DTS8SR             (((volatile __bitf_T *)0xFFFF853A)->bit01)
#define DTS8DR             (((volatile __bitf_T *)0xFFFF853A)->bit02)
#define DTS8ER             (((volatile __bitf_T *)0xFFFF853A)->bit03)
#define DTS8DT             (((volatile __bitf_T *)0xFFFF853A)->bit06)
#define DTS8TC             (((volatile __bitf_T *)0xFFFF853A)->bit07)
#define DSA9               (*(volatile unsigned long  *)0xFFFF8544)
#define DSA9L              (*(volatile unsigned short *)0xFFFF8544)
#define DSA9H              (*(volatile unsigned short *)0xFFFF8546)
#define DDA9               (*(volatile unsigned long  *)0xFFFF8554)
#define DDA9L              (*(volatile unsigned short *)0xFFFF8554)
#define DDA9H              (*(volatile unsigned short *)0xFFFF8556)
#define DTC9               (*(volatile unsigned short *)0xFFFF8562)
#define DTCT9              (*(volatile unsigned short *)0xFFFF8568)
#define DTS9               (*(volatile unsigned char  *)0xFFFF856A)
#define DTS9DTE            (((volatile __bitf_T *)0xFFFF856A)->bit00)
#define DTS9SR             (((volatile __bitf_T *)0xFFFF856A)->bit01)
#define DTS9DR             (((volatile __bitf_T *)0xFFFF856A)->bit02)
#define DTS9ER             (((volatile __bitf_T *)0xFFFF856A)->bit03)
#define DTS9DT             (((volatile __bitf_T *)0xFFFF856A)->bit06)
#define DTS9TC             (((volatile __bitf_T *)0xFFFF856A)->bit07)
#define DSA10              (*(volatile unsigned long  *)0xFFFF8574)
#define DSA10L             (*(volatile unsigned short *)0xFFFF8574)
#define DSA10H             (*(volatile unsigned short *)0xFFFF8576)
#define DDA10              (*(volatile unsigned long  *)0xFFFF8584)
#define DDA10L             (*(volatile unsigned short *)0xFFFF8584)
#define DDA10H             (*(volatile unsigned short *)0xFFFF8586)
#define DTC10              (*(volatile unsigned short *)0xFFFF8592)
#define DTCT10             (*(volatile unsigned short *)0xFFFF8598)
#define DTS10              (*(volatile unsigned char  *)0xFFFF859A)
#define DTS10DTE           (((volatile __bitf_T *)0xFFFF859A)->bit00)
#define DTS10SR            (((volatile __bitf_T *)0xFFFF859A)->bit01)
#define DTS10DR            (((volatile __bitf_T *)0xFFFF859A)->bit02)
#define DTS10ER            (((volatile __bitf_T *)0xFFFF859A)->bit03)
#define DTS10DT            (((volatile __bitf_T *)0xFFFF859A)->bit06)
#define DTS10TC            (((volatile __bitf_T *)0xFFFF859A)->bit07)
#define DSA11              (*(volatile unsigned long  *)0xFFFF85A4)
#define DSA11L             (*(volatile unsigned short *)0xFFFF85A4)
#define DSA11H             (*(volatile unsigned short *)0xFFFF85A6)
#define DDA11              (*(volatile unsigned long  *)0xFFFF85B4)
#define DDA11L             (*(volatile unsigned short *)0xFFFF85B4)
#define DDA11H             (*(volatile unsigned short *)0xFFFF85B6)
#define DTC11              (*(volatile unsigned short *)0xFFFF85C2)
#define DTCT11             (*(volatile unsigned short *)0xFFFF85C8)
#define DTS11              (*(volatile unsigned char  *)0xFFFF85CA)
#define DTS11DTE           (((volatile __bitf_T *)0xFFFF85CA)->bit00)
#define DTS11SR            (((volatile __bitf_T *)0xFFFF85CA)->bit01)
#define DTS11DR            (((volatile __bitf_T *)0xFFFF85CA)->bit02)
#define DTS11ER            (((volatile __bitf_T *)0xFFFF85CA)->bit03)
#define DTS11DT            (((volatile __bitf_T *)0xFFFF85CA)->bit06)
#define DTS11TC            (((volatile __bitf_T *)0xFFFF85CA)->bit07)
#define DSA12              (*(volatile unsigned long  *)0xFFFF85D4)
#define DSA12L             (*(volatile unsigned short *)0xFFFF85D4)
#define DSA12H             (*(volatile unsigned short *)0xFFFF85D6)
#define DDA12              (*(volatile unsigned long  *)0xFFFF85E4)
#define DDA12L             (*(volatile unsigned short *)0xFFFF85E4)
#define DDA12H             (*(volatile unsigned short *)0xFFFF85E6)
#define DTC12              (*(volatile unsigned short *)0xFFFF85F2)
#define DTCT12             (*(volatile unsigned short *)0xFFFF85F8)
#define DTS12              (*(volatile unsigned char  *)0xFFFF85FA)
#define DTS12DTE           (((volatile __bitf_T *)0xFFFF85FA)->bit00)
#define DTS12SR            (((volatile __bitf_T *)0xFFFF85FA)->bit01)
#define DTS12DR            (((volatile __bitf_T *)0xFFFF85FA)->bit02)
#define DTS12ER            (((volatile __bitf_T *)0xFFFF85FA)->bit03)
#define DTS12DT            (((volatile __bitf_T *)0xFFFF85FA)->bit06)
#define DTS12TC            (((volatile __bitf_T *)0xFFFF85FA)->bit07)
#define DSA13              (*(volatile unsigned long  *)0xFFFF8604)
#define DSA13L             (*(volatile unsigned short *)0xFFFF8604)
#define DSA13H             (*(volatile unsigned short *)0xFFFF8606)
#define DDA13              (*(volatile unsigned long  *)0xFFFF8614)
#define DDA13L             (*(volatile unsigned short *)0xFFFF8614)
#define DDA13H             (*(volatile unsigned short *)0xFFFF8616)
#define DTC13              (*(volatile unsigned short *)0xFFFF8622)
#define DTCT13             (*(volatile unsigned short *)0xFFFF8628)
#define DTS13              (*(volatile unsigned char  *)0xFFFF862A)
#define DTS13DTE           (((volatile __bitf_T *)0xFFFF862A)->bit00)
#define DTS13SR            (((volatile __bitf_T *)0xFFFF862A)->bit01)
#define DTS13DR            (((volatile __bitf_T *)0xFFFF862A)->bit02)
#define DTS13ER            (((volatile __bitf_T *)0xFFFF862A)->bit03)
#define DTS13DT            (((volatile __bitf_T *)0xFFFF862A)->bit06)
#define DTS13TC            (((volatile __bitf_T *)0xFFFF862A)->bit07)
#define DSA14              (*(volatile unsigned long  *)0xFFFF8634)
#define DSA14L             (*(volatile unsigned short *)0xFFFF8634)
#define DSA14H             (*(volatile unsigned short *)0xFFFF8636)
#define DDA14              (*(volatile unsigned long  *)0xFFFF8644)
#define DDA14L             (*(volatile unsigned short *)0xFFFF8644)
#define DDA14H             (*(volatile unsigned short *)0xFFFF8646)
#define DTC14              (*(volatile unsigned short *)0xFFFF8652)
#define DTCT14             (*(volatile unsigned short *)0xFFFF8658)
#define DTS14              (*(volatile unsigned char  *)0xFFFF865A)
#define DTS14DTE           (((volatile __bitf_T *)0xFFFF865A)->bit00)
#define DTS14SR            (((volatile __bitf_T *)0xFFFF865A)->bit01)
#define DTS14DR            (((volatile __bitf_T *)0xFFFF865A)->bit02)
#define DTS14ER            (((volatile __bitf_T *)0xFFFF865A)->bit03)
#define DTS14DT            (((volatile __bitf_T *)0xFFFF865A)->bit06)
#define DTS14TC            (((volatile __bitf_T *)0xFFFF865A)->bit07)
#define DSA15              (*(volatile unsigned long  *)0xFFFF8664)
#define DSA15L             (*(volatile unsigned short *)0xFFFF8664)
#define DSA15H             (*(volatile unsigned short *)0xFFFF8666)
#define DDA15              (*(volatile unsigned long  *)0xFFFF8674)
#define DDA15L             (*(volatile unsigned short *)0xFFFF8674)
#define DDA15H             (*(volatile unsigned short *)0xFFFF8676)
#define DTC15              (*(volatile unsigned short *)0xFFFF8682)
#define DTCT15             (*(volatile unsigned short *)0xFFFF8688)
#define DTS15              (*(volatile unsigned char  *)0xFFFF868A)
#define DTS15DTE           (((volatile __bitf_T *)0xFFFF868A)->bit00)
#define DTS15SR            (((volatile __bitf_T *)0xFFFF868A)->bit01)
#define DTS15DR            (((volatile __bitf_T *)0xFFFF868A)->bit02)
#define DTS15ER            (((volatile __bitf_T *)0xFFFF868A)->bit03)
#define DTS15DT            (((volatile __bitf_T *)0xFFFF868A)->bit06)
#define DTS15TC            (((volatile __bitf_T *)0xFFFF868A)->bit07)
#define DTFR0              (*(volatile unsigned short *)0xFFFF8B00)
#define DTFR1              (*(volatile unsigned short *)0xFFFF8B02)
#define DTFR2              (*(volatile unsigned short *)0xFFFF8B04)
#define DTFR3              (*(volatile unsigned short *)0xFFFF8B06)
#define DTFR4              (*(volatile unsigned short *)0xFFFF8B08)
#define DTFR5              (*(volatile unsigned short *)0xFFFF8B0A)
#define DTFR6              (*(volatile unsigned short *)0xFFFF8B0C)
#define DTFR7              (*(volatile unsigned short *)0xFFFF8B0E)
#define DTFR8              (*(volatile unsigned short *)0xFFFF8B10)
#define DTFR9              (*(volatile unsigned short *)0xFFFF8B12)
#define DTFR10             (*(volatile unsigned short *)0xFFFF8B14)
#define DTFR11             (*(volatile unsigned short *)0xFFFF8B16)
#define DTFR12             (*(volatile unsigned short *)0xFFFF8B18)
#define DTFR13             (*(volatile unsigned short *)0xFFFF8B1A)
#define DTFR14             (*(volatile unsigned short *)0xFFFF8B1C)
#define DTFR15             (*(volatile unsigned short *)0xFFFF8B1E)
#define DRQCLR             (*(volatile unsigned short *)0xFFFF8B40)
#define DRQSTR             (*(volatile unsigned short *)0xFFFF8B44)
#define SEG_CONT           (*(volatile unsigned short *)0xFFFF8C00)
#define SEG_CONTL          (*(volatile unsigned char  *)0xFFFF8C00)
#define SEG_CONTROME       (((volatile __bitf_T *)0xFFFF8C00)->bit01)
#define SEG_CONTEXTE       (((volatile __bitf_T *)0xFFFF8C00)->bit02)
#define SEG_CONTRAME       (((volatile __bitf_T *)0xFFFF8C00)->bit04)
#define SEG_CONTRMWE       (((volatile __bitf_T *)0xFFFF8C00)->bit06)
#define SEG_CONTDMAE       (((volatile __bitf_T *)0xFFFF8C00)->bit07)
#define SEG_FLAG           (*(volatile unsigned short *)0xFFFF8C02)
#define SEG_FLAGL          (*(volatile unsigned char  *)0xFFFF8C02)
#define SEG_FLAGROMF       (((volatile __bitf_T *)0xFFFF8C02)->bit01)
#define SEG_FLAGEXTF       (((volatile __bitf_T *)0xFFFF8C02)->bit02)
#define SEG_FLAGRAMF       (((volatile __bitf_T *)0xFFFF8C02)->bit04)
#define SEG_FLAGRMWF       (((volatile __bitf_T *)0xFFFF8C02)->bit06)
#define SEG_FLAGDMAF       (((volatile __bitf_T *)0xFFFF8C02)->bit07)
#define ICCSIH2IC_1        (*(volatile unsigned short *)0xFFFF9000)
#define ICTAUD0I0          (*(volatile unsigned short *)0xFFFF9000)
#define ICCSIH2ICL_1       (*(volatile unsigned char  *)0xFFFF9000)
#define ICTAUD0I0L         (*(volatile unsigned char  *)0xFFFF9000)
#define ICCSIH2ICH_1       (*(volatile unsigned char  *)0xFFFF9001)
#define ICTAUD0I0H         (*(volatile unsigned char  *)0xFFFF9001)
#define P0CSIH2IC_1        (((volatile __bitf_T *)0xFFFF9000)->bit00)
#define P0TAUD0I0          (((volatile __bitf_T *)0xFFFF9000)->bit00)
#define P1CSIH2IC_1        (((volatile __bitf_T *)0xFFFF9000)->bit01)
#define P1TAUD0I0          (((volatile __bitf_T *)0xFFFF9000)->bit01)
#define P2CSIH2IC_1        (((volatile __bitf_T *)0xFFFF9000)->bit02)
#define P2TAUD0I0          (((volatile __bitf_T *)0xFFFF9000)->bit02)
#define TBCSIH2IC_1        (((volatile __bitf_T *)0xFFFF9000)->bit06)
#define TBTAUD0I0          (((volatile __bitf_T *)0xFFFF9000)->bit06)
#define MKCSIH2IC_1        (((volatile __bitf_T *)0xFFFF9000)->bit07)
#define MKTAUD0I0          (((volatile __bitf_T *)0xFFFF9000)->bit07)
#define RFCSIH2IC_1        (((volatile __bitf_T *)0xFFFF9001)->bit04)
#define RFTAUD0I0          (((volatile __bitf_T *)0xFFFF9001)->bit04)
#define CTCSIH2IC_1        (((volatile __bitf_T *)0xFFFF9001)->bit07)
#define CTTAUD0I0          (((volatile __bitf_T *)0xFFFF9001)->bit07)
#define ICCSIH3IC_1        (*(volatile unsigned short *)0xFFFF9002)
#define ICTAUD0I2          (*(volatile unsigned short *)0xFFFF9002)
#define ICCSIH3ICL_1       (*(volatile unsigned char  *)0xFFFF9002)
#define ICTAUD0I2L         (*(volatile unsigned char  *)0xFFFF9002)
#define ICCSIH3ICH_1       (*(volatile unsigned char  *)0xFFFF9003)
#define ICTAUD0I2H         (*(volatile unsigned char  *)0xFFFF9003)
#define P0CSIH3IC_1        (((volatile __bitf_T *)0xFFFF9002)->bit00)
#define P0TAUD0I2          (((volatile __bitf_T *)0xFFFF9002)->bit00)
#define P1CSIH3IC_1        (((volatile __bitf_T *)0xFFFF9002)->bit01)
#define P1TAUD0I2          (((volatile __bitf_T *)0xFFFF9002)->bit01)
#define P2CSIH3IC_1        (((volatile __bitf_T *)0xFFFF9002)->bit02)
#define P2TAUD0I2          (((volatile __bitf_T *)0xFFFF9002)->bit02)
#define TBCSIH3IC_1        (((volatile __bitf_T *)0xFFFF9002)->bit06)
#define TBTAUD0I2          (((volatile __bitf_T *)0xFFFF9002)->bit06)
#define MKCSIH3IC_1        (((volatile __bitf_T *)0xFFFF9002)->bit07)
#define MKTAUD0I2          (((volatile __bitf_T *)0xFFFF9002)->bit07)
#define RFCSIH3IC_1        (((volatile __bitf_T *)0xFFFF9003)->bit04)
#define RFTAUD0I2          (((volatile __bitf_T *)0xFFFF9003)->bit04)
#define CTCSIH3IC_1        (((volatile __bitf_T *)0xFFFF9003)->bit07)
#define CTTAUD0I2          (((volatile __bitf_T *)0xFFFF9003)->bit07)
#define ICTAUD0I4          (*(volatile unsigned short *)0xFFFF9004)
#define ICTAUD0I4L         (*(volatile unsigned char  *)0xFFFF9004)
#define ICTAUD0I4H         (*(volatile unsigned char  *)0xFFFF9005)
#define P0TAUD0I4          (((volatile __bitf_T *)0xFFFF9004)->bit00)
#define P1TAUD0I4          (((volatile __bitf_T *)0xFFFF9004)->bit01)
#define P2TAUD0I4          (((volatile __bitf_T *)0xFFFF9004)->bit02)
#define TBTAUD0I4          (((volatile __bitf_T *)0xFFFF9004)->bit06)
#define MKTAUD0I4          (((volatile __bitf_T *)0xFFFF9004)->bit07)
#define RFTAUD0I4          (((volatile __bitf_T *)0xFFFF9005)->bit04)
#define CTTAUD0I4          (((volatile __bitf_T *)0xFFFF9005)->bit07)
#define ICTAUD0I6          (*(volatile unsigned short *)0xFFFF9006)
#define ICTAUD0I6L         (*(volatile unsigned char  *)0xFFFF9006)
#define ICTAUD0I6H         (*(volatile unsigned char  *)0xFFFF9007)
#define P0TAUD0I6          (((volatile __bitf_T *)0xFFFF9006)->bit00)
#define P1TAUD0I6          (((volatile __bitf_T *)0xFFFF9006)->bit01)
#define P2TAUD0I6          (((volatile __bitf_T *)0xFFFF9006)->bit02)
#define TBTAUD0I6          (((volatile __bitf_T *)0xFFFF9006)->bit06)
#define MKTAUD0I6          (((volatile __bitf_T *)0xFFFF9006)->bit07)
#define RFTAUD0I6          (((volatile __bitf_T *)0xFFFF9007)->bit04)
#define CTTAUD0I6          (((volatile __bitf_T *)0xFFFF9007)->bit07)
#define ICTAUD0I8          (*(volatile unsigned short *)0xFFFF9008)
#define ICTAUD0I8L         (*(volatile unsigned char  *)0xFFFF9008)
#define ICTAUD0I8H         (*(volatile unsigned char  *)0xFFFF9009)
#define P0TAUD0I8          (((volatile __bitf_T *)0xFFFF9008)->bit00)
#define P1TAUD0I8          (((volatile __bitf_T *)0xFFFF9008)->bit01)
#define P2TAUD0I8          (((volatile __bitf_T *)0xFFFF9008)->bit02)
#define TBTAUD0I8          (((volatile __bitf_T *)0xFFFF9008)->bit06)
#define MKTAUD0I8          (((volatile __bitf_T *)0xFFFF9008)->bit07)
#define RFTAUD0I8          (((volatile __bitf_T *)0xFFFF9009)->bit04)
#define CTTAUD0I8          (((volatile __bitf_T *)0xFFFF9009)->bit07)
#define ICCSIH3IR_1        (*(volatile unsigned short *)0xFFFF900A)
#define ICTAUD0I10         (*(volatile unsigned short *)0xFFFF900A)
#define ICCSIH3IRL_1       (*(volatile unsigned char  *)0xFFFF900A)
#define ICTAUD0I10L        (*(volatile unsigned char  *)0xFFFF900A)
#define ICCSIH3IRH_1       (*(volatile unsigned char  *)0xFFFF900B)
#define ICTAUD0I10H        (*(volatile unsigned char  *)0xFFFF900B)
#define P0CSIH3IR_1        (((volatile __bitf_T *)0xFFFF900A)->bit00)
#define P0TAUD0I10         (((volatile __bitf_T *)0xFFFF900A)->bit00)
#define P1CSIH3IR_1        (((volatile __bitf_T *)0xFFFF900A)->bit01)
#define P1TAUD0I10         (((volatile __bitf_T *)0xFFFF900A)->bit01)
#define P2CSIH3IR_1        (((volatile __bitf_T *)0xFFFF900A)->bit02)
#define P2TAUD0I10         (((volatile __bitf_T *)0xFFFF900A)->bit02)
#define TBCSIH3IR_1        (((volatile __bitf_T *)0xFFFF900A)->bit06)
#define TBTAUD0I10         (((volatile __bitf_T *)0xFFFF900A)->bit06)
#define MKCSIH3IR_1        (((volatile __bitf_T *)0xFFFF900A)->bit07)
#define MKTAUD0I10         (((volatile __bitf_T *)0xFFFF900A)->bit07)
#define RFCSIH3IR_1        (((volatile __bitf_T *)0xFFFF900B)->bit04)
#define RFTAUD0I10         (((volatile __bitf_T *)0xFFFF900B)->bit04)
#define CTCSIH3IR_1        (((volatile __bitf_T *)0xFFFF900B)->bit07)
#define CTTAUD0I10         (((volatile __bitf_T *)0xFFFF900B)->bit07)
#define ICCSIH3IRE_1       (*(volatile unsigned short *)0xFFFF900C)
#define ICTAUD0I12         (*(volatile unsigned short *)0xFFFF900C)
#define ICCSIH3IREL_1      (*(volatile unsigned char  *)0xFFFF900C)
#define ICTAUD0I12L        (*(volatile unsigned char  *)0xFFFF900C)
#define ICCSIH3IREH_1      (*(volatile unsigned char  *)0xFFFF900D)
#define ICTAUD0I12H        (*(volatile unsigned char  *)0xFFFF900D)
#define P0CSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900C)->bit00)
#define P0TAUD0I12         (((volatile __bitf_T *)0xFFFF900C)->bit00)
#define P1CSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900C)->bit01)
#define P1TAUD0I12         (((volatile __bitf_T *)0xFFFF900C)->bit01)
#define P2CSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900C)->bit02)
#define P2TAUD0I12         (((volatile __bitf_T *)0xFFFF900C)->bit02)
#define TBCSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900C)->bit06)
#define TBTAUD0I12         (((volatile __bitf_T *)0xFFFF900C)->bit06)
#define MKCSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900C)->bit07)
#define MKTAUD0I12         (((volatile __bitf_T *)0xFFFF900C)->bit07)
#define RFCSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900D)->bit04)
#define RFTAUD0I12         (((volatile __bitf_T *)0xFFFF900D)->bit04)
#define CTCSIH3IRE_1       (((volatile __bitf_T *)0xFFFF900D)->bit07)
#define CTTAUD0I12         (((volatile __bitf_T *)0xFFFF900D)->bit07)
#define ICCSIH3IJC_1       (*(volatile unsigned short *)0xFFFF900E)
#define ICTAUD0I14         (*(volatile unsigned short *)0xFFFF900E)
#define ICCSIH3IJCL_1      (*(volatile unsigned char  *)0xFFFF900E)
#define ICTAUD0I14L        (*(volatile unsigned char  *)0xFFFF900E)
#define ICCSIH3IJCH_1      (*(volatile unsigned char  *)0xFFFF900F)
#define ICTAUD0I14H        (*(volatile unsigned char  *)0xFFFF900F)
#define P0CSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900E)->bit00)
#define P0TAUD0I14         (((volatile __bitf_T *)0xFFFF900E)->bit00)
#define P1CSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900E)->bit01)
#define P1TAUD0I14         (((volatile __bitf_T *)0xFFFF900E)->bit01)
#define P2CSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900E)->bit02)
#define P2TAUD0I14         (((volatile __bitf_T *)0xFFFF900E)->bit02)
#define TBCSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900E)->bit06)
#define TBTAUD0I14         (((volatile __bitf_T *)0xFFFF900E)->bit06)
#define MKCSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900E)->bit07)
#define MKTAUD0I14         (((volatile __bitf_T *)0xFFFF900E)->bit07)
#define RFCSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900F)->bit04)
#define RFTAUD0I14         (((volatile __bitf_T *)0xFFFF900F)->bit04)
#define CTCSIH3IJC_1       (((volatile __bitf_T *)0xFFFF900F)->bit07)
#define CTTAUD0I14         (((volatile __bitf_T *)0xFFFF900F)->bit07)
#define ICCSIH1IC_1        (*(volatile unsigned short *)0xFFFF9010)
#define ICTAPA0IPEK0       (*(volatile unsigned short *)0xFFFF9010)
#define ICCSIH1ICL_1       (*(volatile unsigned char  *)0xFFFF9010)
#define ICTAPA0IPEK0L      (*(volatile unsigned char  *)0xFFFF9010)
#define ICCSIH1ICH_1       (*(volatile unsigned char  *)0xFFFF9011)
#define ICTAPA0IPEK0H      (*(volatile unsigned char  *)0xFFFF9011)
#define P0CSIH1IC_1        (((volatile __bitf_T *)0xFFFF9010)->bit00)
#define P0TAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9010)->bit00)
#define P1CSIH1IC_1        (((volatile __bitf_T *)0xFFFF9010)->bit01)
#define P1TAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9010)->bit01)
#define P2CSIH1IC_1        (((volatile __bitf_T *)0xFFFF9010)->bit02)
#define P2TAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9010)->bit02)
#define TBCSIH1IC_1        (((volatile __bitf_T *)0xFFFF9010)->bit06)
#define TBTAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9010)->bit06)
#define MKCSIH1IC_1        (((volatile __bitf_T *)0xFFFF9010)->bit07)
#define MKTAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9010)->bit07)
#define RFCSIH1IC_1        (((volatile __bitf_T *)0xFFFF9011)->bit04)
#define RFTAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9011)->bit04)
#define CTCSIH1IC_1        (((volatile __bitf_T *)0xFFFF9011)->bit07)
#define CTTAPA0IPEK0       (((volatile __bitf_T *)0xFFFF9011)->bit07)
#define ICCSIH1IR_1        (*(volatile unsigned short *)0xFFFF9012)
#define ICTAPA0IVLY0       (*(volatile unsigned short *)0xFFFF9012)
#define ICCSIH1IRL_1       (*(volatile unsigned char  *)0xFFFF9012)
#define ICTAPA0IVLY0L      (*(volatile unsigned char  *)0xFFFF9012)
#define ICCSIH1IRH_1       (*(volatile unsigned char  *)0xFFFF9013)
#define ICTAPA0IVLY0H      (*(volatile unsigned char  *)0xFFFF9013)
#define P0CSIH1IR_1        (((volatile __bitf_T *)0xFFFF9012)->bit00)
#define P0TAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9012)->bit00)
#define P1CSIH1IR_1        (((volatile __bitf_T *)0xFFFF9012)->bit01)
#define P1TAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9012)->bit01)
#define P2CSIH1IR_1        (((volatile __bitf_T *)0xFFFF9012)->bit02)
#define P2TAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9012)->bit02)
#define TBCSIH1IR_1        (((volatile __bitf_T *)0xFFFF9012)->bit06)
#define TBTAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9012)->bit06)
#define MKCSIH1IR_1        (((volatile __bitf_T *)0xFFFF9012)->bit07)
#define MKTAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9012)->bit07)
#define RFCSIH1IR_1        (((volatile __bitf_T *)0xFFFF9013)->bit04)
#define RFTAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9013)->bit04)
#define CTCSIH1IR_1        (((volatile __bitf_T *)0xFFFF9013)->bit07)
#define CTTAPA0IVLY0       (((volatile __bitf_T *)0xFFFF9013)->bit07)
#define ICADCA0I0          (*(volatile unsigned short *)0xFFFF9014)
#define ICADCA0I0L         (*(volatile unsigned char  *)0xFFFF9014)
#define ICADCA0I0H         (*(volatile unsigned char  *)0xFFFF9015)
#define P0ADCA0I0          (((volatile __bitf_T *)0xFFFF9014)->bit00)
#define P1ADCA0I0          (((volatile __bitf_T *)0xFFFF9014)->bit01)
#define P2ADCA0I0          (((volatile __bitf_T *)0xFFFF9014)->bit02)
#define TBADCA0I0          (((volatile __bitf_T *)0xFFFF9014)->bit06)
#define MKADCA0I0          (((volatile __bitf_T *)0xFFFF9014)->bit07)
#define RFADCA0I0          (((volatile __bitf_T *)0xFFFF9015)->bit04)
#define CTADCA0I0          (((volatile __bitf_T *)0xFFFF9015)->bit07)
#define ICADCA0I1          (*(volatile unsigned short *)0xFFFF9016)
#define ICADCA0I1L         (*(volatile unsigned char  *)0xFFFF9016)
#define ICADCA0I1H         (*(volatile unsigned char  *)0xFFFF9017)
#define P0ADCA0I1          (((volatile __bitf_T *)0xFFFF9016)->bit00)
#define P1ADCA0I1          (((volatile __bitf_T *)0xFFFF9016)->bit01)
#define P2ADCA0I1          (((volatile __bitf_T *)0xFFFF9016)->bit02)
#define TBADCA0I1          (((volatile __bitf_T *)0xFFFF9016)->bit06)
#define MKADCA0I1          (((volatile __bitf_T *)0xFFFF9016)->bit07)
#define RFADCA0I1          (((volatile __bitf_T *)0xFFFF9017)->bit04)
#define CTADCA0I1          (((volatile __bitf_T *)0xFFFF9017)->bit07)
#define ICADCA0I2          (*(volatile unsigned short *)0xFFFF9018)
#define ICADCA0I2L         (*(volatile unsigned char  *)0xFFFF9018)
#define ICADCA0I2H         (*(volatile unsigned char  *)0xFFFF9019)
#define P0ADCA0I2          (((volatile __bitf_T *)0xFFFF9018)->bit00)
#define P1ADCA0I2          (((volatile __bitf_T *)0xFFFF9018)->bit01)
#define P2ADCA0I2          (((volatile __bitf_T *)0xFFFF9018)->bit02)
#define TBADCA0I2          (((volatile __bitf_T *)0xFFFF9018)->bit06)
#define MKADCA0I2          (((volatile __bitf_T *)0xFFFF9018)->bit07)
#define RFADCA0I2          (((volatile __bitf_T *)0xFFFF9019)->bit04)
#define CTADCA0I2          (((volatile __bitf_T *)0xFFFF9019)->bit07)
#define ICDCUTDI           (*(volatile unsigned short *)0xFFFF901A)
#define ICDCUTDIL          (*(volatile unsigned char  *)0xFFFF901A)
#define ICDCUTDIH          (*(volatile unsigned char  *)0xFFFF901B)
#define P0DCUTDI           (((volatile __bitf_T *)0xFFFF901A)->bit00)
#define P1DCUTDI           (((volatile __bitf_T *)0xFFFF901A)->bit01)
#define P2DCUTDI           (((volatile __bitf_T *)0xFFFF901A)->bit02)
#define TBDCUTDI           (((volatile __bitf_T *)0xFFFF901A)->bit06)
#define MKDCUTDI           (((volatile __bitf_T *)0xFFFF901A)->bit07)
#define RFDCUTDI           (((volatile __bitf_T *)0xFFFF901B)->bit04)
#define CTDCUTDI           (((volatile __bitf_T *)0xFFFF901B)->bit07)
#define ICRCANGERR         (*(volatile unsigned short *)0xFFFF901C)
#define ICRCANGERRL        (*(volatile unsigned char  *)0xFFFF901C)
#define ICRCANGERRH        (*(volatile unsigned char  *)0xFFFF901D)
#define P0RCANGERR         (((volatile __bitf_T *)0xFFFF901C)->bit00)
#define P1RCANGERR         (((volatile __bitf_T *)0xFFFF901C)->bit01)
#define P2RCANGERR         (((volatile __bitf_T *)0xFFFF901C)->bit02)
#define TBRCANGERR         (((volatile __bitf_T *)0xFFFF901C)->bit06)
#define MKRCANGERR         (((volatile __bitf_T *)0xFFFF901C)->bit07)
#define RFRCANGERR         (((volatile __bitf_T *)0xFFFF901D)->bit04)
#define CTRCANGERR         (((volatile __bitf_T *)0xFFFF901D)->bit07)
#define ICRCANGRECC        (*(volatile unsigned short *)0xFFFF901E)
#define ICRCANGRECCL       (*(volatile unsigned char  *)0xFFFF901E)
#define ICRCANGRECCH       (*(volatile unsigned char  *)0xFFFF901F)
#define P0RCANGRECC        (((volatile __bitf_T *)0xFFFF901E)->bit00)
#define P1RCANGRECC        (((volatile __bitf_T *)0xFFFF901E)->bit01)
#define P2RCANGRECC        (((volatile __bitf_T *)0xFFFF901E)->bit02)
#define TBRCANGRECC        (((volatile __bitf_T *)0xFFFF901E)->bit06)
#define MKRCANGRECC        (((volatile __bitf_T *)0xFFFF901E)->bit07)
#define RFRCANGRECC        (((volatile __bitf_T *)0xFFFF901F)->bit04)
#define CTRCANGRECC        (((volatile __bitf_T *)0xFFFF901F)->bit07)
#define ICRCAN0ERR         (*(volatile unsigned short *)0xFFFF9020)
#define ICRCAN0ERRL        (*(volatile unsigned char  *)0xFFFF9020)
#define ICRCAN0ERRH        (*(volatile unsigned char  *)0xFFFF9021)
#define P0RCAN0ERR         (((volatile __bitf_T *)0xFFFF9020)->bit00)
#define P1RCAN0ERR         (((volatile __bitf_T *)0xFFFF9020)->bit01)
#define P2RCAN0ERR         (((volatile __bitf_T *)0xFFFF9020)->bit02)
#define TBRCAN0ERR         (((volatile __bitf_T *)0xFFFF9020)->bit06)
#define MKRCAN0ERR         (((volatile __bitf_T *)0xFFFF9020)->bit07)
#define RFRCAN0ERR         (((volatile __bitf_T *)0xFFFF9021)->bit04)
#define CTRCAN0ERR         (((volatile __bitf_T *)0xFFFF9021)->bit07)
#define ICRCAN0REC         (*(volatile unsigned short *)0xFFFF9022)
#define ICRCAN0RECL        (*(volatile unsigned char  *)0xFFFF9022)
#define ICRCAN0RECH        (*(volatile unsigned char  *)0xFFFF9023)
#define P0RCAN0REC         (((volatile __bitf_T *)0xFFFF9022)->bit00)
#define P1RCAN0REC         (((volatile __bitf_T *)0xFFFF9022)->bit01)
#define P2RCAN0REC         (((volatile __bitf_T *)0xFFFF9022)->bit02)
#define TBRCAN0REC         (((volatile __bitf_T *)0xFFFF9022)->bit06)
#define MKRCAN0REC         (((volatile __bitf_T *)0xFFFF9022)->bit07)
#define RFRCAN0REC         (((volatile __bitf_T *)0xFFFF9023)->bit04)
#define CTRCAN0REC         (((volatile __bitf_T *)0xFFFF9023)->bit07)
#define ICRCAN0TRX         (*(volatile unsigned short *)0xFFFF9024)
#define ICRCAN0TRXL        (*(volatile unsigned char  *)0xFFFF9024)
#define ICRCAN0TRXH        (*(volatile unsigned char  *)0xFFFF9025)
#define P0RCAN0TRX         (((volatile __bitf_T *)0xFFFF9024)->bit00)
#define P1RCAN0TRX         (((volatile __bitf_T *)0xFFFF9024)->bit01)
#define P2RCAN0TRX         (((volatile __bitf_T *)0xFFFF9024)->bit02)
#define TBRCAN0TRX         (((volatile __bitf_T *)0xFFFF9024)->bit06)
#define MKRCAN0TRX         (((volatile __bitf_T *)0xFFFF9024)->bit07)
#define RFRCAN0TRX         (((volatile __bitf_T *)0xFFFF9025)->bit04)
#define CTRCAN0TRX         (((volatile __bitf_T *)0xFFFF9025)->bit07)
#define ICCSIG0IC          (*(volatile unsigned short *)0xFFFF9026)
#define ICCSIH1IRE_1       (*(volatile unsigned short *)0xFFFF9026)
#define ICCSIG0ICL         (*(volatile unsigned char  *)0xFFFF9026)
#define ICCSIH1IREL_1      (*(volatile unsigned char  *)0xFFFF9026)
#define ICCSIG0ICH         (*(volatile unsigned char  *)0xFFFF9027)
#define ICCSIH1IREH_1      (*(volatile unsigned char  *)0xFFFF9027)
#define P0CSIG0IC          (((volatile __bitf_T *)0xFFFF9026)->bit00)
#define P0CSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9026)->bit00)
#define P1CSIG0IC          (((volatile __bitf_T *)0xFFFF9026)->bit01)
#define P1CSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9026)->bit01)
#define P2CSIG0IC          (((volatile __bitf_T *)0xFFFF9026)->bit02)
#define P2CSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9026)->bit02)
#define TBCSIG0IC          (((volatile __bitf_T *)0xFFFF9026)->bit06)
#define TBCSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9026)->bit06)
#define MKCSIG0IC          (((volatile __bitf_T *)0xFFFF9026)->bit07)
#define MKCSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9026)->bit07)
#define RFCSIG0IC          (((volatile __bitf_T *)0xFFFF9027)->bit04)
#define RFCSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9027)->bit04)
#define CTCSIG0IC          (((volatile __bitf_T *)0xFFFF9027)->bit07)
#define CTCSIH1IRE_1       (((volatile __bitf_T *)0xFFFF9027)->bit07)
#define ICCSIG0IR          (*(volatile unsigned short *)0xFFFF9028)
#define ICCSIH1IJC_1       (*(volatile unsigned short *)0xFFFF9028)
#define ICCSIG0IRL         (*(volatile unsigned char  *)0xFFFF9028)
#define ICCSIH1IJCL_1      (*(volatile unsigned char  *)0xFFFF9028)
#define ICCSIG0IRH         (*(volatile unsigned char  *)0xFFFF9029)
#define ICCSIH1IJCH_1      (*(volatile unsigned char  *)0xFFFF9029)
#define P0CSIG0IR          (((volatile __bitf_T *)0xFFFF9028)->bit00)
#define P0CSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9028)->bit00)
#define P1CSIG0IR          (((volatile __bitf_T *)0xFFFF9028)->bit01)
#define P1CSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9028)->bit01)
#define P2CSIG0IR          (((volatile __bitf_T *)0xFFFF9028)->bit02)
#define P2CSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9028)->bit02)
#define TBCSIG0IR          (((volatile __bitf_T *)0xFFFF9028)->bit06)
#define TBCSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9028)->bit06)
#define MKCSIG0IR          (((volatile __bitf_T *)0xFFFF9028)->bit07)
#define MKCSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9028)->bit07)
#define RFCSIG0IR          (((volatile __bitf_T *)0xFFFF9029)->bit04)
#define RFCSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9029)->bit04)
#define CTCSIG0IR          (((volatile __bitf_T *)0xFFFF9029)->bit07)
#define CTCSIH1IJC_1       (((volatile __bitf_T *)0xFFFF9029)->bit07)
#define ICCSIH0IC          (*(volatile unsigned short *)0xFFFF902A)
#define ICCSIH0ICL         (*(volatile unsigned char  *)0xFFFF902A)
#define ICCSIH0ICH         (*(volatile unsigned char  *)0xFFFF902B)
#define P0CSIH0IC          (((volatile __bitf_T *)0xFFFF902A)->bit00)
#define P1CSIH0IC          (((volatile __bitf_T *)0xFFFF902A)->bit01)
#define P2CSIH0IC          (((volatile __bitf_T *)0xFFFF902A)->bit02)
#define TBCSIH0IC          (((volatile __bitf_T *)0xFFFF902A)->bit06)
#define MKCSIH0IC          (((volatile __bitf_T *)0xFFFF902A)->bit07)
#define RFCSIH0IC          (((volatile __bitf_T *)0xFFFF902B)->bit04)
#define CTCSIH0IC          (((volatile __bitf_T *)0xFFFF902B)->bit07)
#define ICCSIH0IR          (*(volatile unsigned short *)0xFFFF902C)
#define ICCSIH0IRL         (*(volatile unsigned char  *)0xFFFF902C)
#define ICCSIH0IRH         (*(volatile unsigned char  *)0xFFFF902D)
#define P0CSIH0IR          (((volatile __bitf_T *)0xFFFF902C)->bit00)
#define P1CSIH0IR          (((volatile __bitf_T *)0xFFFF902C)->bit01)
#define P2CSIH0IR          (((volatile __bitf_T *)0xFFFF902C)->bit02)
#define TBCSIH0IR          (((volatile __bitf_T *)0xFFFF902C)->bit06)
#define MKCSIH0IR          (((volatile __bitf_T *)0xFFFF902C)->bit07)
#define RFCSIH0IR          (((volatile __bitf_T *)0xFFFF902D)->bit04)
#define CTCSIH0IR          (((volatile __bitf_T *)0xFFFF902D)->bit07)
#define ICCSIH0IRE         (*(volatile unsigned short *)0xFFFF902E)
#define ICCSIH0IREL        (*(volatile unsigned char  *)0xFFFF902E)
#define ICCSIH0IREH        (*(volatile unsigned char  *)0xFFFF902F)
#define P0CSIH0IRE         (((volatile __bitf_T *)0xFFFF902E)->bit00)
#define P1CSIH0IRE         (((volatile __bitf_T *)0xFFFF902E)->bit01)
#define P2CSIH0IRE         (((volatile __bitf_T *)0xFFFF902E)->bit02)
#define TBCSIH0IRE         (((volatile __bitf_T *)0xFFFF902E)->bit06)
#define MKCSIH0IRE         (((volatile __bitf_T *)0xFFFF902E)->bit07)
#define RFCSIH0IRE         (((volatile __bitf_T *)0xFFFF902F)->bit04)
#define CTCSIH0IRE         (((volatile __bitf_T *)0xFFFF902F)->bit07)
#define ICCSIH0IJC         (*(volatile unsigned short *)0xFFFF9030)
#define ICCSIH0IJCL        (*(volatile unsigned char  *)0xFFFF9030)
#define ICCSIH0IJCH        (*(volatile unsigned char  *)0xFFFF9031)
#define P0CSIH0IJC         (((volatile __bitf_T *)0xFFFF9030)->bit00)
#define P1CSIH0IJC         (((volatile __bitf_T *)0xFFFF9030)->bit01)
#define P2CSIH0IJC         (((volatile __bitf_T *)0xFFFF9030)->bit02)
#define TBCSIH0IJC         (((volatile __bitf_T *)0xFFFF9030)->bit06)
#define MKCSIH0IJC         (((volatile __bitf_T *)0xFFFF9030)->bit07)
#define RFCSIH0IJC         (((volatile __bitf_T *)0xFFFF9031)->bit04)
#define CTCSIH0IJC         (((volatile __bitf_T *)0xFFFF9031)->bit07)
#define ICRLIN30           (*(volatile unsigned short *)0xFFFF9032)
#define ICRLIN30L          (*(volatile unsigned char  *)0xFFFF9032)
#define ICRLIN30H          (*(volatile unsigned char  *)0xFFFF9033)
#define P0RLIN30           (((volatile __bitf_T *)0xFFFF9032)->bit00)
#define P1RLIN30           (((volatile __bitf_T *)0xFFFF9032)->bit01)
#define P2RLIN30           (((volatile __bitf_T *)0xFFFF9032)->bit02)
#define TBRLIN30           (((volatile __bitf_T *)0xFFFF9032)->bit06)
#define MKRLIN30           (((volatile __bitf_T *)0xFFFF9032)->bit07)
#define RFRLIN30           (((volatile __bitf_T *)0xFFFF9033)->bit04)
#define CTRLIN30           (((volatile __bitf_T *)0xFFFF9033)->bit07)
#define ICRLIN30UR0        (*(volatile unsigned short *)0xFFFF9034)
#define ICRLIN30UR0L       (*(volatile unsigned char  *)0xFFFF9034)
#define ICRLIN30UR0H       (*(volatile unsigned char  *)0xFFFF9035)
#define P0RLIN30UR0        (((volatile __bitf_T *)0xFFFF9034)->bit00)
#define P1RLIN30UR0        (((volatile __bitf_T *)0xFFFF9034)->bit01)
#define P2RLIN30UR0        (((volatile __bitf_T *)0xFFFF9034)->bit02)
#define TBRLIN30UR0        (((volatile __bitf_T *)0xFFFF9034)->bit06)
#define MKRLIN30UR0        (((volatile __bitf_T *)0xFFFF9034)->bit07)
#define RFRLIN30UR0        (((volatile __bitf_T *)0xFFFF9035)->bit04)
#define CTRLIN30UR0        (((volatile __bitf_T *)0xFFFF9035)->bit07)
#define ICRLIN30UR1        (*(volatile unsigned short *)0xFFFF9036)
#define ICRLIN30UR1L       (*(volatile unsigned char  *)0xFFFF9036)
#define ICRLIN30UR1H       (*(volatile unsigned char  *)0xFFFF9037)
#define P0RLIN30UR1        (((volatile __bitf_T *)0xFFFF9036)->bit00)
#define P1RLIN30UR1        (((volatile __bitf_T *)0xFFFF9036)->bit01)
#define P2RLIN30UR1        (((volatile __bitf_T *)0xFFFF9036)->bit02)
#define TBRLIN30UR1        (((volatile __bitf_T *)0xFFFF9036)->bit06)
#define MKRLIN30UR1        (((volatile __bitf_T *)0xFFFF9036)->bit07)
#define RFRLIN30UR1        (((volatile __bitf_T *)0xFFFF9037)->bit04)
#define CTRLIN30UR1        (((volatile __bitf_T *)0xFFFF9037)->bit07)
#define ICRLIN30UR2        (*(volatile unsigned short *)0xFFFF9038)
#define ICRLIN30UR2L       (*(volatile unsigned char  *)0xFFFF9038)
#define ICRLIN30UR2H       (*(volatile unsigned char  *)0xFFFF9039)
#define P0RLIN30UR2        (((volatile __bitf_T *)0xFFFF9038)->bit00)
#define P1RLIN30UR2        (((volatile __bitf_T *)0xFFFF9038)->bit01)
#define P2RLIN30UR2        (((volatile __bitf_T *)0xFFFF9038)->bit02)
#define TBRLIN30UR2        (((volatile __bitf_T *)0xFFFF9038)->bit06)
#define MKRLIN30UR2        (((volatile __bitf_T *)0xFFFF9038)->bit07)
#define RFRLIN30UR2        (((volatile __bitf_T *)0xFFFF9039)->bit04)
#define CTRLIN30UR2        (((volatile __bitf_T *)0xFFFF9039)->bit07)
#define ICCSIH2IR_1        (*(volatile unsigned short *)0xFFFF903A)
#define ICP0               (*(volatile unsigned short *)0xFFFF903A)
#define ICCSIH2IRL_1       (*(volatile unsigned char  *)0xFFFF903A)
#define ICP0L              (*(volatile unsigned char  *)0xFFFF903A)
#define ICCSIH2IRH_1       (*(volatile unsigned char  *)0xFFFF903B)
#define ICP0H              (*(volatile unsigned char  *)0xFFFF903B)
#define P0CSIH2IR_1        (((volatile __bitf_T *)0xFFFF903A)->bit00)
#define P0P0               (((volatile __bitf_T *)0xFFFF903A)->bit00)
#define P1CSIH2IR_1        (((volatile __bitf_T *)0xFFFF903A)->bit01)
#define P1P0               (((volatile __bitf_T *)0xFFFF903A)->bit01)
#define P2CSIH2IR_1        (((volatile __bitf_T *)0xFFFF903A)->bit02)
#define P2P0               (((volatile __bitf_T *)0xFFFF903A)->bit02)
#define TBCSIH2IR_1        (((volatile __bitf_T *)0xFFFF903A)->bit06)
#define TBP0               (((volatile __bitf_T *)0xFFFF903A)->bit06)
#define MKCSIH2IR_1        (((volatile __bitf_T *)0xFFFF903A)->bit07)
#define MKP0               (((volatile __bitf_T *)0xFFFF903A)->bit07)
#define RFCSIH2IR_1        (((volatile __bitf_T *)0xFFFF903B)->bit04)
#define RFP0               (((volatile __bitf_T *)0xFFFF903B)->bit04)
#define CTCSIH2IR_1        (((volatile __bitf_T *)0xFFFF903B)->bit07)
#define CTP0               (((volatile __bitf_T *)0xFFFF903B)->bit07)
#define ICCSIH2IRE_1       (*(volatile unsigned short *)0xFFFF903C)
#define ICP1               (*(volatile unsigned short *)0xFFFF903C)
#define ICCSIH2IREL_1      (*(volatile unsigned char  *)0xFFFF903C)
#define ICP1L              (*(volatile unsigned char  *)0xFFFF903C)
#define ICCSIH2IREH_1      (*(volatile unsigned char  *)0xFFFF903D)
#define ICP1H              (*(volatile unsigned char  *)0xFFFF903D)
#define P0CSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903C)->bit00)
#define P0P1               (((volatile __bitf_T *)0xFFFF903C)->bit00)
#define P1CSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903C)->bit01)
#define P1P1               (((volatile __bitf_T *)0xFFFF903C)->bit01)
#define P2CSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903C)->bit02)
#define P2P1               (((volatile __bitf_T *)0xFFFF903C)->bit02)
#define TBCSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903C)->bit06)
#define TBP1               (((volatile __bitf_T *)0xFFFF903C)->bit06)
#define MKCSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903C)->bit07)
#define MKP1               (((volatile __bitf_T *)0xFFFF903C)->bit07)
#define RFCSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903D)->bit04)
#define RFP1               (((volatile __bitf_T *)0xFFFF903D)->bit04)
#define CTCSIH2IRE_1       (((volatile __bitf_T *)0xFFFF903D)->bit07)
#define CTP1               (((volatile __bitf_T *)0xFFFF903D)->bit07)
#define ICCSIH2IJC_1       (*(volatile unsigned short *)0xFFFF903E)
#define ICP2               (*(volatile unsigned short *)0xFFFF903E)
#define ICCSIH2IJCL_1      (*(volatile unsigned char  *)0xFFFF903E)
#define ICP2L              (*(volatile unsigned char  *)0xFFFF903E)
#define ICCSIH2IJCH_1      (*(volatile unsigned char  *)0xFFFF903F)
#define ICP2H              (*(volatile unsigned char  *)0xFFFF903F)
#define P0CSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903E)->bit00)
#define P0P2               (((volatile __bitf_T *)0xFFFF903E)->bit00)
#define P1CSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903E)->bit01)
#define P1P2               (((volatile __bitf_T *)0xFFFF903E)->bit01)
#define P2CSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903E)->bit02)
#define P2P2               (((volatile __bitf_T *)0xFFFF903E)->bit02)
#define TBCSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903E)->bit06)
#define TBP2               (((volatile __bitf_T *)0xFFFF903E)->bit06)
#define MKCSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903E)->bit07)
#define MKP2               (((volatile __bitf_T *)0xFFFF903E)->bit07)
#define RFCSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903F)->bit04)
#define RFP2               (((volatile __bitf_T *)0xFFFF903F)->bit04)
#define CTCSIH2IJC_1       (((volatile __bitf_T *)0xFFFF903F)->bit07)
#define CTP2               (((volatile __bitf_T *)0xFFFF903F)->bit07)
#define FNC                (*(volatile unsigned short *)0xFFFF9078)
#define FNCH               (*(volatile unsigned char  *)0xFFFF9079)
#define FNRF               (((volatile __bitf_T *)0xFFFF9079)->bit04)
#define FIC                (*(volatile unsigned short *)0xFFFF907A)
#define FICH               (*(volatile unsigned char  *)0xFFFF907B)
#define FIRF               (((volatile __bitf_T *)0xFFFF907B)->bit04)
#define IMR0               (*(volatile unsigned long  *)0xFFFF90F0)
#define IMR0L              (*(volatile unsigned short *)0xFFFF90F0)
#define IMR0LL             (*(volatile unsigned char  *)0xFFFF90F0)
#define IMR0LH             (*(volatile unsigned char  *)0xFFFF90F1)
#define IMR0H              (*(volatile unsigned short *)0xFFFF90F2)
#define IMR0HL             (*(volatile unsigned char  *)0xFFFF90F2)
#define IMR0HH             (*(volatile unsigned char  *)0xFFFF90F3)
#define IMR0EIMK0          (((volatile __bitf_T *)0xFFFF90F0)->bit00)
#define IMR0EIMK1          (((volatile __bitf_T *)0xFFFF90F0)->bit01)
#define IMR0EIMK2          (((volatile __bitf_T *)0xFFFF90F0)->bit02)
#define IMR0EIMK3          (((volatile __bitf_T *)0xFFFF90F0)->bit03)
#define IMR0EIMK4          (((volatile __bitf_T *)0xFFFF90F0)->bit04)
#define IMR0EIMK5          (((volatile __bitf_T *)0xFFFF90F0)->bit05)
#define IMR0EIMK6          (((volatile __bitf_T *)0xFFFF90F0)->bit06)
#define IMR0EIMK7          (((volatile __bitf_T *)0xFFFF90F0)->bit07)
#define IMR0EIMK8          (((volatile __bitf_T *)0xFFFF90F1)->bit00)
#define IMR0EIMK9          (((volatile __bitf_T *)0xFFFF90F1)->bit01)
#define IMR0EIMK10         (((volatile __bitf_T *)0xFFFF90F1)->bit02)
#define IMR0EIMK11         (((volatile __bitf_T *)0xFFFF90F1)->bit03)
#define IMR0EIMK12         (((volatile __bitf_T *)0xFFFF90F1)->bit04)
#define IMR0EIMK13         (((volatile __bitf_T *)0xFFFF90F1)->bit05)
#define IMR0EIMK14         (((volatile __bitf_T *)0xFFFF90F1)->bit06)
#define IMR0EIMK15         (((volatile __bitf_T *)0xFFFF90F1)->bit07)
#define IMR0EIMK16         (((volatile __bitf_T *)0xFFFF90F2)->bit00)
#define IMR0EIMK17         (((volatile __bitf_T *)0xFFFF90F2)->bit01)
#define IMR0EIMK18         (((volatile __bitf_T *)0xFFFF90F2)->bit02)
#define IMR0EIMK19         (((volatile __bitf_T *)0xFFFF90F2)->bit03)
#define IMR0EIMK20         (((volatile __bitf_T *)0xFFFF90F2)->bit04)
#define IMR0EIMK21         (((volatile __bitf_T *)0xFFFF90F2)->bit05)
#define IMR0EIMK22         (((volatile __bitf_T *)0xFFFF90F2)->bit06)
#define IMR0EIMK23         (((volatile __bitf_T *)0xFFFF90F2)->bit07)
#define IMR0EIMK24         (((volatile __bitf_T *)0xFFFF90F3)->bit00)
#define IMR0EIMK25         (((volatile __bitf_T *)0xFFFF90F3)->bit01)
#define IMR0EIMK26         (((volatile __bitf_T *)0xFFFF90F3)->bit02)
#define IMR0EIMK27         (((volatile __bitf_T *)0xFFFF90F3)->bit03)
#define IMR0EIMK28         (((volatile __bitf_T *)0xFFFF90F3)->bit04)
#define IMR0EIMK29         (((volatile __bitf_T *)0xFFFF90F3)->bit05)
#define IMR0EIMK30         (((volatile __bitf_T *)0xFFFF90F3)->bit06)
#define IMR0EIMK31         (((volatile __bitf_T *)0xFFFF90F3)->bit07)
#define ICWDTA0            (*(volatile unsigned short *)0xFFFFA040)
#define ICWDTA0L           (*(volatile unsigned char  *)0xFFFFA040)
#define ICWDTA0H           (*(volatile unsigned char  *)0xFFFFA041)
#define P0WDTA0            (((volatile __bitf_T *)0xFFFFA040)->bit00)
#define P1WDTA0            (((volatile __bitf_T *)0xFFFFA040)->bit01)
#define P2WDTA0            (((volatile __bitf_T *)0xFFFFA040)->bit02)
#define TBWDTA0            (((volatile __bitf_T *)0xFFFFA040)->bit06)
#define MKWDTA0            (((volatile __bitf_T *)0xFFFFA040)->bit07)
#define RFWDTA0            (((volatile __bitf_T *)0xFFFFA041)->bit04)
#define CTWDTA0            (((volatile __bitf_T *)0xFFFFA041)->bit07)
#define ICWDTA1            (*(volatile unsigned short *)0xFFFFA042)
#define ICWDTA1L           (*(volatile unsigned char  *)0xFFFFA042)
#define ICWDTA1H           (*(volatile unsigned char  *)0xFFFFA043)
#define P0WDTA1            (((volatile __bitf_T *)0xFFFFA042)->bit00)
#define P1WDTA1            (((volatile __bitf_T *)0xFFFFA042)->bit01)
#define P2WDTA1            (((volatile __bitf_T *)0xFFFFA042)->bit02)
#define TBWDTA1            (((volatile __bitf_T *)0xFFFFA042)->bit06)
#define MKWDTA1            (((volatile __bitf_T *)0xFFFFA042)->bit07)
#define RFWDTA1            (((volatile __bitf_T *)0xFFFFA043)->bit04)
#define CTWDTA1            (((volatile __bitf_T *)0xFFFFA043)->bit07)
#define ICP3               (*(volatile unsigned short *)0xFFFFA044)
#define ICP3L              (*(volatile unsigned char  *)0xFFFFA044)
#define ICP3H              (*(volatile unsigned char  *)0xFFFFA045)
#define P0P3               (((volatile __bitf_T *)0xFFFFA044)->bit00)
#define P1P3               (((volatile __bitf_T *)0xFFFFA044)->bit01)
#define P2P3               (((volatile __bitf_T *)0xFFFFA044)->bit02)
#define TBP3               (((volatile __bitf_T *)0xFFFFA044)->bit06)
#define MKP3               (((volatile __bitf_T *)0xFFFFA044)->bit07)
#define RFP3               (((volatile __bitf_T *)0xFFFFA045)->bit04)
#define CTP3               (((volatile __bitf_T *)0xFFFFA045)->bit07)
#define ICP4               (*(volatile unsigned short *)0xFFFFA046)
#define ICP4L              (*(volatile unsigned char  *)0xFFFFA046)
#define ICP4H              (*(volatile unsigned char  *)0xFFFFA047)
#define P0P4               (((volatile __bitf_T *)0xFFFFA046)->bit00)
#define P1P4               (((volatile __bitf_T *)0xFFFFA046)->bit01)
#define P2P4               (((volatile __bitf_T *)0xFFFFA046)->bit02)
#define TBP4               (((volatile __bitf_T *)0xFFFFA046)->bit06)
#define MKP4               (((volatile __bitf_T *)0xFFFFA046)->bit07)
#define RFP4               (((volatile __bitf_T *)0xFFFFA047)->bit04)
#define CTP4               (((volatile __bitf_T *)0xFFFFA047)->bit07)
#define ICP5               (*(volatile unsigned short *)0xFFFFA048)
#define ICP5L              (*(volatile unsigned char  *)0xFFFFA048)
#define ICP5H              (*(volatile unsigned char  *)0xFFFFA049)
#define P0P5               (((volatile __bitf_T *)0xFFFFA048)->bit00)
#define P1P5               (((volatile __bitf_T *)0xFFFFA048)->bit01)
#define P2P5               (((volatile __bitf_T *)0xFFFFA048)->bit02)
#define TBP5               (((volatile __bitf_T *)0xFFFFA048)->bit06)
#define MKP5               (((volatile __bitf_T *)0xFFFFA048)->bit07)
#define RFP5               (((volatile __bitf_T *)0xFFFFA049)->bit04)
#define CTP5               (((volatile __bitf_T *)0xFFFFA049)->bit07)
#define ICP10              (*(volatile unsigned short *)0xFFFFA04A)
#define ICP10L             (*(volatile unsigned char  *)0xFFFFA04A)
#define ICP10H             (*(volatile unsigned char  *)0xFFFFA04B)
#define P0P10              (((volatile __bitf_T *)0xFFFFA04A)->bit00)
#define P1P10              (((volatile __bitf_T *)0xFFFFA04A)->bit01)
#define P2P10              (((volatile __bitf_T *)0xFFFFA04A)->bit02)
#define TBP10              (((volatile __bitf_T *)0xFFFFA04A)->bit06)
#define MKP10              (((volatile __bitf_T *)0xFFFFA04A)->bit07)
#define RFP10              (((volatile __bitf_T *)0xFFFFA04B)->bit04)
#define CTP10              (((volatile __bitf_T *)0xFFFFA04B)->bit07)
#define ICP11              (*(volatile unsigned short *)0xFFFFA04C)
#define ICP11L             (*(volatile unsigned char  *)0xFFFFA04C)
#define ICP11H             (*(volatile unsigned char  *)0xFFFFA04D)
#define P0P11              (((volatile __bitf_T *)0xFFFFA04C)->bit00)
#define P1P11              (((volatile __bitf_T *)0xFFFFA04C)->bit01)
#define P2P11              (((volatile __bitf_T *)0xFFFFA04C)->bit02)
#define TBP11              (((volatile __bitf_T *)0xFFFFA04C)->bit06)
#define MKP11              (((volatile __bitf_T *)0xFFFFA04C)->bit07)
#define RFP11              (((volatile __bitf_T *)0xFFFFA04D)->bit04)
#define CTP11              (((volatile __bitf_T *)0xFFFFA04D)->bit07)
#define ICTAUD0I1          (*(volatile unsigned short *)0xFFFFA04E)
#define ICTAUD0I1L         (*(volatile unsigned char  *)0xFFFFA04E)
#define ICTAUD0I1H         (*(volatile unsigned char  *)0xFFFFA04F)
#define P0TAUD0I1          (((volatile __bitf_T *)0xFFFFA04E)->bit00)
#define P1TAUD0I1          (((volatile __bitf_T *)0xFFFFA04E)->bit01)
#define P2TAUD0I1          (((volatile __bitf_T *)0xFFFFA04E)->bit02)
#define TBTAUD0I1          (((volatile __bitf_T *)0xFFFFA04E)->bit06)
#define MKTAUD0I1          (((volatile __bitf_T *)0xFFFFA04E)->bit07)
#define RFTAUD0I1          (((volatile __bitf_T *)0xFFFFA04F)->bit04)
#define CTTAUD0I1          (((volatile __bitf_T *)0xFFFFA04F)->bit07)
#define ICTAUD0I3          (*(volatile unsigned short *)0xFFFFA050)
#define ICTAUD0I3L         (*(volatile unsigned char  *)0xFFFFA050)
#define ICTAUD0I3H         (*(volatile unsigned char  *)0xFFFFA051)
#define P0TAUD0I3          (((volatile __bitf_T *)0xFFFFA050)->bit00)
#define P1TAUD0I3          (((volatile __bitf_T *)0xFFFFA050)->bit01)
#define P2TAUD0I3          (((volatile __bitf_T *)0xFFFFA050)->bit02)
#define TBTAUD0I3          (((volatile __bitf_T *)0xFFFFA050)->bit06)
#define MKTAUD0I3          (((volatile __bitf_T *)0xFFFFA050)->bit07)
#define RFTAUD0I3          (((volatile __bitf_T *)0xFFFFA051)->bit04)
#define CTTAUD0I3          (((volatile __bitf_T *)0xFFFFA051)->bit07)
#define ICTAUD0I5          (*(volatile unsigned short *)0xFFFFA052)
#define ICTAUD0I5L         (*(volatile unsigned char  *)0xFFFFA052)
#define ICTAUD0I5H         (*(volatile unsigned char  *)0xFFFFA053)
#define P0TAUD0I5          (((volatile __bitf_T *)0xFFFFA052)->bit00)
#define P1TAUD0I5          (((volatile __bitf_T *)0xFFFFA052)->bit01)
#define P2TAUD0I5          (((volatile __bitf_T *)0xFFFFA052)->bit02)
#define TBTAUD0I5          (((volatile __bitf_T *)0xFFFFA052)->bit06)
#define MKTAUD0I5          (((volatile __bitf_T *)0xFFFFA052)->bit07)
#define RFTAUD0I5          (((volatile __bitf_T *)0xFFFFA053)->bit04)
#define CTTAUD0I5          (((volatile __bitf_T *)0xFFFFA053)->bit07)
#define ICTAUD0I7          (*(volatile unsigned short *)0xFFFFA054)
#define ICTAUD0I7L         (*(volatile unsigned char  *)0xFFFFA054)
#define ICTAUD0I7H         (*(volatile unsigned char  *)0xFFFFA055)
#define P0TAUD0I7          (((volatile __bitf_T *)0xFFFFA054)->bit00)
#define P1TAUD0I7          (((volatile __bitf_T *)0xFFFFA054)->bit01)
#define P2TAUD0I7          (((volatile __bitf_T *)0xFFFFA054)->bit02)
#define TBTAUD0I7          (((volatile __bitf_T *)0xFFFFA054)->bit06)
#define MKTAUD0I7          (((volatile __bitf_T *)0xFFFFA054)->bit07)
#define RFTAUD0I7          (((volatile __bitf_T *)0xFFFFA055)->bit04)
#define CTTAUD0I7          (((volatile __bitf_T *)0xFFFFA055)->bit07)
#define ICTAUD0I9          (*(volatile unsigned short *)0xFFFFA056)
#define ICTAUD0I9L         (*(volatile unsigned char  *)0xFFFFA056)
#define ICTAUD0I9H         (*(volatile unsigned char  *)0xFFFFA057)
#define P0TAUD0I9          (((volatile __bitf_T *)0xFFFFA056)->bit00)
#define P1TAUD0I9          (((volatile __bitf_T *)0xFFFFA056)->bit01)
#define P2TAUD0I9          (((volatile __bitf_T *)0xFFFFA056)->bit02)
#define TBTAUD0I9          (((volatile __bitf_T *)0xFFFFA056)->bit06)
#define MKTAUD0I9          (((volatile __bitf_T *)0xFFFFA056)->bit07)
#define RFTAUD0I9          (((volatile __bitf_T *)0xFFFFA057)->bit04)
#define CTTAUD0I9          (((volatile __bitf_T *)0xFFFFA057)->bit07)
#define ICTAUD0I11         (*(volatile unsigned short *)0xFFFFA058)
#define ICTAUD0I11L        (*(volatile unsigned char  *)0xFFFFA058)
#define ICTAUD0I11H        (*(volatile unsigned char  *)0xFFFFA059)
#define P0TAUD0I11         (((volatile __bitf_T *)0xFFFFA058)->bit00)
#define P1TAUD0I11         (((volatile __bitf_T *)0xFFFFA058)->bit01)
#define P2TAUD0I11         (((volatile __bitf_T *)0xFFFFA058)->bit02)
#define TBTAUD0I11         (((volatile __bitf_T *)0xFFFFA058)->bit06)
#define MKTAUD0I11         (((volatile __bitf_T *)0xFFFFA058)->bit07)
#define RFTAUD0I11         (((volatile __bitf_T *)0xFFFFA059)->bit04)
#define CTTAUD0I11         (((volatile __bitf_T *)0xFFFFA059)->bit07)
#define ICTAUD0I13         (*(volatile unsigned short *)0xFFFFA05A)
#define ICTAUD0I13L        (*(volatile unsigned char  *)0xFFFFA05A)
#define ICTAUD0I13H        (*(volatile unsigned char  *)0xFFFFA05B)
#define P0TAUD0I13         (((volatile __bitf_T *)0xFFFFA05A)->bit00)
#define P1TAUD0I13         (((volatile __bitf_T *)0xFFFFA05A)->bit01)
#define P2TAUD0I13         (((volatile __bitf_T *)0xFFFFA05A)->bit02)
#define TBTAUD0I13         (((volatile __bitf_T *)0xFFFFA05A)->bit06)
#define MKTAUD0I13         (((volatile __bitf_T *)0xFFFFA05A)->bit07)
#define RFTAUD0I13         (((volatile __bitf_T *)0xFFFFA05B)->bit04)
#define CTTAUD0I13         (((volatile __bitf_T *)0xFFFFA05B)->bit07)
#define ICTAUD0I15         (*(volatile unsigned short *)0xFFFFA05C)
#define ICTAUD0I15L        (*(volatile unsigned char  *)0xFFFFA05C)
#define ICTAUD0I15H        (*(volatile unsigned char  *)0xFFFFA05D)
#define P0TAUD0I15         (((volatile __bitf_T *)0xFFFFA05C)->bit00)
#define P1TAUD0I15         (((volatile __bitf_T *)0xFFFFA05C)->bit01)
#define P2TAUD0I15         (((volatile __bitf_T *)0xFFFFA05C)->bit02)
#define TBTAUD0I15         (((volatile __bitf_T *)0xFFFFA05C)->bit06)
#define MKTAUD0I15         (((volatile __bitf_T *)0xFFFFA05C)->bit07)
#define RFTAUD0I15         (((volatile __bitf_T *)0xFFFFA05D)->bit04)
#define CTTAUD0I15         (((volatile __bitf_T *)0xFFFFA05D)->bit07)
#define ICADCA0ERR         (*(volatile unsigned short *)0xFFFFA05E)
#define ICADCA0ERRL        (*(volatile unsigned char  *)0xFFFFA05E)
#define ICADCA0ERRH        (*(volatile unsigned char  *)0xFFFFA05F)
#define P0ADCA0ERR         (((volatile __bitf_T *)0xFFFFA05E)->bit00)
#define P1ADCA0ERR         (((volatile __bitf_T *)0xFFFFA05E)->bit01)
#define P2ADCA0ERR         (((volatile __bitf_T *)0xFFFFA05E)->bit02)
#define TBADCA0ERR         (((volatile __bitf_T *)0xFFFFA05E)->bit06)
#define MKADCA0ERR         (((volatile __bitf_T *)0xFFFFA05E)->bit07)
#define RFADCA0ERR         (((volatile __bitf_T *)0xFFFFA05F)->bit04)
#define CTADCA0ERR         (((volatile __bitf_T *)0xFFFFA05F)->bit07)
#define ICCSIG0IRE         (*(volatile unsigned short *)0xFFFFA062)
#define ICCSIG0IREL        (*(volatile unsigned char  *)0xFFFFA062)
#define ICCSIG0IREH        (*(volatile unsigned char  *)0xFFFFA063)
#define P0CSIG0IRE         (((volatile __bitf_T *)0xFFFFA062)->bit00)
#define P1CSIG0IRE         (((volatile __bitf_T *)0xFFFFA062)->bit01)
#define P2CSIG0IRE         (((volatile __bitf_T *)0xFFFFA062)->bit02)
#define TBCSIG0IRE         (((volatile __bitf_T *)0xFFFFA062)->bit06)
#define MKCSIG0IRE         (((volatile __bitf_T *)0xFFFFA062)->bit07)
#define RFCSIG0IRE         (((volatile __bitf_T *)0xFFFFA063)->bit04)
#define CTCSIG0IRE         (((volatile __bitf_T *)0xFFFFA063)->bit07)
#define ICRLIN20           (*(volatile unsigned short *)0xFFFFA064)
#define ICRLIN20L          (*(volatile unsigned char  *)0xFFFFA064)
#define ICRLIN20H          (*(volatile unsigned char  *)0xFFFFA065)
#define P0RLIN20           (((volatile __bitf_T *)0xFFFFA064)->bit00)
#define P1RLIN20           (((volatile __bitf_T *)0xFFFFA064)->bit01)
#define P2RLIN20           (((volatile __bitf_T *)0xFFFFA064)->bit02)
#define TBRLIN20           (((volatile __bitf_T *)0xFFFFA064)->bit06)
#define MKRLIN20           (((volatile __bitf_T *)0xFFFFA064)->bit07)
#define RFRLIN20           (((volatile __bitf_T *)0xFFFFA065)->bit04)
#define CTRLIN20           (((volatile __bitf_T *)0xFFFFA065)->bit07)
#define ICRLIN21           (*(volatile unsigned short *)0xFFFFA066)
#define ICRLIN21L          (*(volatile unsigned char  *)0xFFFFA066)
#define ICRLIN21H          (*(volatile unsigned char  *)0xFFFFA067)
#define P0RLIN21           (((volatile __bitf_T *)0xFFFFA066)->bit00)
#define P1RLIN21           (((volatile __bitf_T *)0xFFFFA066)->bit01)
#define P2RLIN21           (((volatile __bitf_T *)0xFFFFA066)->bit02)
#define TBRLIN21           (((volatile __bitf_T *)0xFFFFA066)->bit06)
#define MKRLIN21           (((volatile __bitf_T *)0xFFFFA066)->bit07)
#define RFRLIN21           (((volatile __bitf_T *)0xFFFFA067)->bit04)
#define CTRLIN21           (((volatile __bitf_T *)0xFFFFA067)->bit07)
#define ICDMA0             (*(volatile unsigned short *)0xFFFFA068)
#define ICDMA0L            (*(volatile unsigned char  *)0xFFFFA068)
#define ICDMA0H            (*(volatile unsigned char  *)0xFFFFA069)
#define P0DMA0             (((volatile __bitf_T *)0xFFFFA068)->bit00)
#define P1DMA0             (((volatile __bitf_T *)0xFFFFA068)->bit01)
#define P2DMA0             (((volatile __bitf_T *)0xFFFFA068)->bit02)
#define TBDMA0             (((volatile __bitf_T *)0xFFFFA068)->bit06)
#define MKDMA0             (((volatile __bitf_T *)0xFFFFA068)->bit07)
#define RFDMA0             (((volatile __bitf_T *)0xFFFFA069)->bit04)
#define CTDMA0             (((volatile __bitf_T *)0xFFFFA069)->bit07)
#define ICDMA1             (*(volatile unsigned short *)0xFFFFA06A)
#define ICDMA1L            (*(volatile unsigned char  *)0xFFFFA06A)
#define ICDMA1H            (*(volatile unsigned char  *)0xFFFFA06B)
#define P0DMA1             (((volatile __bitf_T *)0xFFFFA06A)->bit00)
#define P1DMA1             (((volatile __bitf_T *)0xFFFFA06A)->bit01)
#define P2DMA1             (((volatile __bitf_T *)0xFFFFA06A)->bit02)
#define TBDMA1             (((volatile __bitf_T *)0xFFFFA06A)->bit06)
#define MKDMA1             (((volatile __bitf_T *)0xFFFFA06A)->bit07)
#define RFDMA1             (((volatile __bitf_T *)0xFFFFA06B)->bit04)
#define CTDMA1             (((volatile __bitf_T *)0xFFFFA06B)->bit07)
#define ICDMA2             (*(volatile unsigned short *)0xFFFFA06C)
#define ICDMA2L            (*(volatile unsigned char  *)0xFFFFA06C)
#define ICDMA2H            (*(volatile unsigned char  *)0xFFFFA06D)
#define P0DMA2             (((volatile __bitf_T *)0xFFFFA06C)->bit00)
#define P1DMA2             (((volatile __bitf_T *)0xFFFFA06C)->bit01)
#define P2DMA2             (((volatile __bitf_T *)0xFFFFA06C)->bit02)
#define TBDMA2             (((volatile __bitf_T *)0xFFFFA06C)->bit06)
#define MKDMA2             (((volatile __bitf_T *)0xFFFFA06C)->bit07)
#define RFDMA2             (((volatile __bitf_T *)0xFFFFA06D)->bit04)
#define CTDMA2             (((volatile __bitf_T *)0xFFFFA06D)->bit07)
#define ICDMA3             (*(volatile unsigned short *)0xFFFFA06E)
#define ICDMA3L            (*(volatile unsigned char  *)0xFFFFA06E)
#define ICDMA3H            (*(volatile unsigned char  *)0xFFFFA06F)
#define P0DMA3             (((volatile __bitf_T *)0xFFFFA06E)->bit00)
#define P1DMA3             (((volatile __bitf_T *)0xFFFFA06E)->bit01)
#define P2DMA3             (((volatile __bitf_T *)0xFFFFA06E)->bit02)
#define TBDMA3             (((volatile __bitf_T *)0xFFFFA06E)->bit06)
#define MKDMA3             (((volatile __bitf_T *)0xFFFFA06E)->bit07)
#define RFDMA3             (((volatile __bitf_T *)0xFFFFA06F)->bit04)
#define CTDMA3             (((volatile __bitf_T *)0xFFFFA06F)->bit07)
#define ICDMA4             (*(volatile unsigned short *)0xFFFFA070)
#define ICDMA4L            (*(volatile unsigned char  *)0xFFFFA070)
#define ICDMA4H            (*(volatile unsigned char  *)0xFFFFA071)
#define P0DMA4             (((volatile __bitf_T *)0xFFFFA070)->bit00)
#define P1DMA4             (((volatile __bitf_T *)0xFFFFA070)->bit01)
#define P2DMA4             (((volatile __bitf_T *)0xFFFFA070)->bit02)
#define TBDMA4             (((volatile __bitf_T *)0xFFFFA070)->bit06)
#define MKDMA4             (((volatile __bitf_T *)0xFFFFA070)->bit07)
#define RFDMA4             (((volatile __bitf_T *)0xFFFFA071)->bit04)
#define CTDMA4             (((volatile __bitf_T *)0xFFFFA071)->bit07)
#define ICDMA5             (*(volatile unsigned short *)0xFFFFA072)
#define ICDMA5L            (*(volatile unsigned char  *)0xFFFFA072)
#define ICDMA5H            (*(volatile unsigned char  *)0xFFFFA073)
#define P0DMA5             (((volatile __bitf_T *)0xFFFFA072)->bit00)
#define P1DMA5             (((volatile __bitf_T *)0xFFFFA072)->bit01)
#define P2DMA5             (((volatile __bitf_T *)0xFFFFA072)->bit02)
#define TBDMA5             (((volatile __bitf_T *)0xFFFFA072)->bit06)
#define MKDMA5             (((volatile __bitf_T *)0xFFFFA072)->bit07)
#define RFDMA5             (((volatile __bitf_T *)0xFFFFA073)->bit04)
#define CTDMA5             (((volatile __bitf_T *)0xFFFFA073)->bit07)
#define ICDMA6             (*(volatile unsigned short *)0xFFFFA074)
#define ICDMA6L            (*(volatile unsigned char  *)0xFFFFA074)
#define ICDMA6H            (*(volatile unsigned char  *)0xFFFFA075)
#define P0DMA6             (((volatile __bitf_T *)0xFFFFA074)->bit00)
#define P1DMA6             (((volatile __bitf_T *)0xFFFFA074)->bit01)
#define P2DMA6             (((volatile __bitf_T *)0xFFFFA074)->bit02)
#define TBDMA6             (((volatile __bitf_T *)0xFFFFA074)->bit06)
#define MKDMA6             (((volatile __bitf_T *)0xFFFFA074)->bit07)
#define RFDMA6             (((volatile __bitf_T *)0xFFFFA075)->bit04)
#define CTDMA6             (((volatile __bitf_T *)0xFFFFA075)->bit07)
#define ICDMA7             (*(volatile unsigned short *)0xFFFFA076)
#define ICDMA7L            (*(volatile unsigned char  *)0xFFFFA076)
#define ICDMA7H            (*(volatile unsigned char  *)0xFFFFA077)
#define P0DMA7             (((volatile __bitf_T *)0xFFFFA076)->bit00)
#define P1DMA7             (((volatile __bitf_T *)0xFFFFA076)->bit01)
#define P2DMA7             (((volatile __bitf_T *)0xFFFFA076)->bit02)
#define TBDMA7             (((volatile __bitf_T *)0xFFFFA076)->bit06)
#define MKDMA7             (((volatile __bitf_T *)0xFFFFA076)->bit07)
#define RFDMA7             (((volatile __bitf_T *)0xFFFFA077)->bit04)
#define CTDMA7             (((volatile __bitf_T *)0xFFFFA077)->bit07)
#define ICDMA8             (*(volatile unsigned short *)0xFFFFA078)
#define ICDMA8L            (*(volatile unsigned char  *)0xFFFFA078)
#define ICDMA8H            (*(volatile unsigned char  *)0xFFFFA079)
#define P0DMA8             (((volatile __bitf_T *)0xFFFFA078)->bit00)
#define P1DMA8             (((volatile __bitf_T *)0xFFFFA078)->bit01)
#define P2DMA8             (((volatile __bitf_T *)0xFFFFA078)->bit02)
#define TBDMA8             (((volatile __bitf_T *)0xFFFFA078)->bit06)
#define MKDMA8             (((volatile __bitf_T *)0xFFFFA078)->bit07)
#define RFDMA8             (((volatile __bitf_T *)0xFFFFA079)->bit04)
#define CTDMA8             (((volatile __bitf_T *)0xFFFFA079)->bit07)
#define ICDMA9             (*(volatile unsigned short *)0xFFFFA07A)
#define ICDMA9L            (*(volatile unsigned char  *)0xFFFFA07A)
#define ICDMA9H            (*(volatile unsigned char  *)0xFFFFA07B)
#define P0DMA9             (((volatile __bitf_T *)0xFFFFA07A)->bit00)
#define P1DMA9             (((volatile __bitf_T *)0xFFFFA07A)->bit01)
#define P2DMA9             (((volatile __bitf_T *)0xFFFFA07A)->bit02)
#define TBDMA9             (((volatile __bitf_T *)0xFFFFA07A)->bit06)
#define MKDMA9             (((volatile __bitf_T *)0xFFFFA07A)->bit07)
#define RFDMA9             (((volatile __bitf_T *)0xFFFFA07B)->bit04)
#define CTDMA9             (((volatile __bitf_T *)0xFFFFA07B)->bit07)
#define ICDMA10            (*(volatile unsigned short *)0xFFFFA07C)
#define ICDMA10L           (*(volatile unsigned char  *)0xFFFFA07C)
#define ICDMA10H           (*(volatile unsigned char  *)0xFFFFA07D)
#define P0DMA10            (((volatile __bitf_T *)0xFFFFA07C)->bit00)
#define P1DMA10            (((volatile __bitf_T *)0xFFFFA07C)->bit01)
#define P2DMA10            (((volatile __bitf_T *)0xFFFFA07C)->bit02)
#define TBDMA10            (((volatile __bitf_T *)0xFFFFA07C)->bit06)
#define MKDMA10            (((volatile __bitf_T *)0xFFFFA07C)->bit07)
#define RFDMA10            (((volatile __bitf_T *)0xFFFFA07D)->bit04)
#define CTDMA10            (((volatile __bitf_T *)0xFFFFA07D)->bit07)
#define ICDMA11            (*(volatile unsigned short *)0xFFFFA07E)
#define ICDMA11L           (*(volatile unsigned char  *)0xFFFFA07E)
#define ICDMA11H           (*(volatile unsigned char  *)0xFFFFA07F)
#define P0DMA11            (((volatile __bitf_T *)0xFFFFA07E)->bit00)
#define P1DMA11            (((volatile __bitf_T *)0xFFFFA07E)->bit01)
#define P2DMA11            (((volatile __bitf_T *)0xFFFFA07E)->bit02)
#define TBDMA11            (((volatile __bitf_T *)0xFFFFA07E)->bit06)
#define MKDMA11            (((volatile __bitf_T *)0xFFFFA07E)->bit07)
#define RFDMA11            (((volatile __bitf_T *)0xFFFFA07F)->bit04)
#define CTDMA11            (((volatile __bitf_T *)0xFFFFA07F)->bit07)
#define ICDMA12            (*(volatile unsigned short *)0xFFFFA080)
#define ICDMA12L           (*(volatile unsigned char  *)0xFFFFA080)
#define ICDMA12H           (*(volatile unsigned char  *)0xFFFFA081)
#define P0DMA12            (((volatile __bitf_T *)0xFFFFA080)->bit00)
#define P1DMA12            (((volatile __bitf_T *)0xFFFFA080)->bit01)
#define P2DMA12            (((volatile __bitf_T *)0xFFFFA080)->bit02)
#define TBDMA12            (((volatile __bitf_T *)0xFFFFA080)->bit06)
#define MKDMA12            (((volatile __bitf_T *)0xFFFFA080)->bit07)
#define RFDMA12            (((volatile __bitf_T *)0xFFFFA081)->bit04)
#define CTDMA12            (((volatile __bitf_T *)0xFFFFA081)->bit07)
#define ICDMA13            (*(volatile unsigned short *)0xFFFFA082)
#define ICDMA13L           (*(volatile unsigned char  *)0xFFFFA082)
#define ICDMA13H           (*(volatile unsigned char  *)0xFFFFA083)
#define P0DMA13            (((volatile __bitf_T *)0xFFFFA082)->bit00)
#define P1DMA13            (((volatile __bitf_T *)0xFFFFA082)->bit01)
#define P2DMA13            (((volatile __bitf_T *)0xFFFFA082)->bit02)
#define TBDMA13            (((volatile __bitf_T *)0xFFFFA082)->bit06)
#define MKDMA13            (((volatile __bitf_T *)0xFFFFA082)->bit07)
#define RFDMA13            (((volatile __bitf_T *)0xFFFFA083)->bit04)
#define CTDMA13            (((volatile __bitf_T *)0xFFFFA083)->bit07)
#define ICDMA14            (*(volatile unsigned short *)0xFFFFA084)
#define ICDMA14L           (*(volatile unsigned char  *)0xFFFFA084)
#define ICDMA14H           (*(volatile unsigned char  *)0xFFFFA085)
#define P0DMA14            (((volatile __bitf_T *)0xFFFFA084)->bit00)
#define P1DMA14            (((volatile __bitf_T *)0xFFFFA084)->bit01)
#define P2DMA14            (((volatile __bitf_T *)0xFFFFA084)->bit02)
#define TBDMA14            (((volatile __bitf_T *)0xFFFFA084)->bit06)
#define MKDMA14            (((volatile __bitf_T *)0xFFFFA084)->bit07)
#define RFDMA14            (((volatile __bitf_T *)0xFFFFA085)->bit04)
#define CTDMA14            (((volatile __bitf_T *)0xFFFFA085)->bit07)
#define ICDMA15            (*(volatile unsigned short *)0xFFFFA086)
#define ICDMA15L           (*(volatile unsigned char  *)0xFFFFA086)
#define ICDMA15H           (*(volatile unsigned char  *)0xFFFFA087)
#define P0DMA15            (((volatile __bitf_T *)0xFFFFA086)->bit00)
#define P1DMA15            (((volatile __bitf_T *)0xFFFFA086)->bit01)
#define P2DMA15            (((volatile __bitf_T *)0xFFFFA086)->bit02)
#define TBDMA15            (((volatile __bitf_T *)0xFFFFA086)->bit06)
#define MKDMA15            (((volatile __bitf_T *)0xFFFFA086)->bit07)
#define RFDMA15            (((volatile __bitf_T *)0xFFFFA087)->bit04)
#define CTDMA15            (((volatile __bitf_T *)0xFFFFA087)->bit07)
#define ICRIIC0TI          (*(volatile unsigned short *)0xFFFFA088)
#define ICRIIC0TIL         (*(volatile unsigned char  *)0xFFFFA088)
#define ICRIIC0TIH         (*(volatile unsigned char  *)0xFFFFA089)
#define P0RIIC0TI          (((volatile __bitf_T *)0xFFFFA088)->bit00)
#define P1RIIC0TI          (((volatile __bitf_T *)0xFFFFA088)->bit01)
#define P2RIIC0TI          (((volatile __bitf_T *)0xFFFFA088)->bit02)
#define TBRIIC0TI          (((volatile __bitf_T *)0xFFFFA088)->bit06)
#define MKRIIC0TI          (((volatile __bitf_T *)0xFFFFA088)->bit07)
#define RFRIIC0TI          (((volatile __bitf_T *)0xFFFFA089)->bit04)
#define CTRIIC0TI          (((volatile __bitf_T *)0xFFFFA089)->bit07)
#define ICRIIC0TEI         (*(volatile unsigned short *)0xFFFFA08A)
#define ICRIIC0TEIL        (*(volatile unsigned char  *)0xFFFFA08A)
#define ICRIIC0TEIH        (*(volatile unsigned char  *)0xFFFFA08B)
#define P0RIIC0TEI         (((volatile __bitf_T *)0xFFFFA08A)->bit00)
#define P1RIIC0TEI         (((volatile __bitf_T *)0xFFFFA08A)->bit01)
#define P2RIIC0TEI         (((volatile __bitf_T *)0xFFFFA08A)->bit02)
#define TBRIIC0TEI         (((volatile __bitf_T *)0xFFFFA08A)->bit06)
#define MKRIIC0TEI         (((volatile __bitf_T *)0xFFFFA08A)->bit07)
#define RFRIIC0TEI         (((volatile __bitf_T *)0xFFFFA08B)->bit04)
#define CTRIIC0TEI         (((volatile __bitf_T *)0xFFFFA08B)->bit07)
#define ICRIIC0RI          (*(volatile unsigned short *)0xFFFFA08C)
#define ICRIIC0RIL         (*(volatile unsigned char  *)0xFFFFA08C)
#define ICRIIC0RIH         (*(volatile unsigned char  *)0xFFFFA08D)
#define P0RIIC0RI          (((volatile __bitf_T *)0xFFFFA08C)->bit00)
#define P1RIIC0RI          (((volatile __bitf_T *)0xFFFFA08C)->bit01)
#define P2RIIC0RI          (((volatile __bitf_T *)0xFFFFA08C)->bit02)
#define TBRIIC0RI          (((volatile __bitf_T *)0xFFFFA08C)->bit06)
#define MKRIIC0RI          (((volatile __bitf_T *)0xFFFFA08C)->bit07)
#define RFRIIC0RI          (((volatile __bitf_T *)0xFFFFA08D)->bit04)
#define CTRIIC0RI          (((volatile __bitf_T *)0xFFFFA08D)->bit07)
#define ICRIIC0EE          (*(volatile unsigned short *)0xFFFFA08E)
#define ICRIIC0EEL         (*(volatile unsigned char  *)0xFFFFA08E)
#define ICRIIC0EEH         (*(volatile unsigned char  *)0xFFFFA08F)
#define P0RIIC0EE          (((volatile __bitf_T *)0xFFFFA08E)->bit00)
#define P1RIIC0EE          (((volatile __bitf_T *)0xFFFFA08E)->bit01)
#define P2RIIC0EE          (((volatile __bitf_T *)0xFFFFA08E)->bit02)
#define TBRIIC0EE          (((volatile __bitf_T *)0xFFFFA08E)->bit06)
#define MKRIIC0EE          (((volatile __bitf_T *)0xFFFFA08E)->bit07)
#define RFRIIC0EE          (((volatile __bitf_T *)0xFFFFA08F)->bit04)
#define CTRIIC0EE          (((volatile __bitf_T *)0xFFFFA08F)->bit07)
#define ICTAUJ0I0          (*(volatile unsigned short *)0xFFFFA090)
#define ICTAUJ0I0L         (*(volatile unsigned char  *)0xFFFFA090)
#define ICTAUJ0I0H         (*(volatile unsigned char  *)0xFFFFA091)
#define P0TAUJ0I0          (((volatile __bitf_T *)0xFFFFA090)->bit00)
#define P1TAUJ0I0          (((volatile __bitf_T *)0xFFFFA090)->bit01)
#define P2TAUJ0I0          (((volatile __bitf_T *)0xFFFFA090)->bit02)
#define TBTAUJ0I0          (((volatile __bitf_T *)0xFFFFA090)->bit06)
#define MKTAUJ0I0          (((volatile __bitf_T *)0xFFFFA090)->bit07)
#define RFTAUJ0I0          (((volatile __bitf_T *)0xFFFFA091)->bit04)
#define CTTAUJ0I0          (((volatile __bitf_T *)0xFFFFA091)->bit07)
#define ICTAUJ0I1          (*(volatile unsigned short *)0xFFFFA092)
#define ICTAUJ0I1L         (*(volatile unsigned char  *)0xFFFFA092)
#define ICTAUJ0I1H         (*(volatile unsigned char  *)0xFFFFA093)
#define P0TAUJ0I1          (((volatile __bitf_T *)0xFFFFA092)->bit00)
#define P1TAUJ0I1          (((volatile __bitf_T *)0xFFFFA092)->bit01)
#define P2TAUJ0I1          (((volatile __bitf_T *)0xFFFFA092)->bit02)
#define TBTAUJ0I1          (((volatile __bitf_T *)0xFFFFA092)->bit06)
#define MKTAUJ0I1          (((volatile __bitf_T *)0xFFFFA092)->bit07)
#define RFTAUJ0I1          (((volatile __bitf_T *)0xFFFFA093)->bit04)
#define CTTAUJ0I1          (((volatile __bitf_T *)0xFFFFA093)->bit07)
#define ICTAUJ0I2          (*(volatile unsigned short *)0xFFFFA094)
#define ICTAUJ0I2L         (*(volatile unsigned char  *)0xFFFFA094)
#define ICTAUJ0I2H         (*(volatile unsigned char  *)0xFFFFA095)
#define P0TAUJ0I2          (((volatile __bitf_T *)0xFFFFA094)->bit00)
#define P1TAUJ0I2          (((volatile __bitf_T *)0xFFFFA094)->bit01)
#define P2TAUJ0I2          (((volatile __bitf_T *)0xFFFFA094)->bit02)
#define TBTAUJ0I2          (((volatile __bitf_T *)0xFFFFA094)->bit06)
#define MKTAUJ0I2          (((volatile __bitf_T *)0xFFFFA094)->bit07)
#define RFTAUJ0I2          (((volatile __bitf_T *)0xFFFFA095)->bit04)
#define CTTAUJ0I2          (((volatile __bitf_T *)0xFFFFA095)->bit07)
#define ICTAUJ0I3          (*(volatile unsigned short *)0xFFFFA096)
#define ICTAUJ0I3L         (*(volatile unsigned char  *)0xFFFFA096)
#define ICTAUJ0I3H         (*(volatile unsigned char  *)0xFFFFA097)
#define P0TAUJ0I3          (((volatile __bitf_T *)0xFFFFA096)->bit00)
#define P1TAUJ0I3          (((volatile __bitf_T *)0xFFFFA096)->bit01)
#define P2TAUJ0I3          (((volatile __bitf_T *)0xFFFFA096)->bit02)
#define TBTAUJ0I3          (((volatile __bitf_T *)0xFFFFA096)->bit06)
#define MKTAUJ0I3          (((volatile __bitf_T *)0xFFFFA096)->bit07)
#define RFTAUJ0I3          (((volatile __bitf_T *)0xFFFFA097)->bit04)
#define CTTAUJ0I3          (((volatile __bitf_T *)0xFFFFA097)->bit07)
#define ICOSTM0            (*(volatile unsigned short *)0xFFFFA098)
#define ICOSTM0L           (*(volatile unsigned char  *)0xFFFFA098)
#define ICOSTM0H           (*(volatile unsigned char  *)0xFFFFA099)
#define P0OSTM0            (((volatile __bitf_T *)0xFFFFA098)->bit00)
#define P1OSTM0            (((volatile __bitf_T *)0xFFFFA098)->bit01)
#define P2OSTM0            (((volatile __bitf_T *)0xFFFFA098)->bit02)
#define TBOSTM0            (((volatile __bitf_T *)0xFFFFA098)->bit06)
#define MKOSTM0            (((volatile __bitf_T *)0xFFFFA098)->bit07)
#define RFOSTM0            (((volatile __bitf_T *)0xFFFFA099)->bit04)
#define CTOSTM0            (((volatile __bitf_T *)0xFFFFA099)->bit07)
#define ICENCA0IOV         (*(volatile unsigned short *)0xFFFFA09A)
#define ICPWGA4            (*(volatile unsigned short *)0xFFFFA09A)
#define ICENCA0IOVL        (*(volatile unsigned char  *)0xFFFFA09A)
#define ICPWGA4L           (*(volatile unsigned char  *)0xFFFFA09A)
#define ICENCA0IOVH        (*(volatile unsigned char  *)0xFFFFA09B)
#define ICPWGA4H           (*(volatile unsigned char  *)0xFFFFA09B)
#define P0ENCA0IOV         (((volatile __bitf_T *)0xFFFFA09A)->bit00)
#define P0PWGA4            (((volatile __bitf_T *)0xFFFFA09A)->bit00)
#define P1ENCA0IOV         (((volatile __bitf_T *)0xFFFFA09A)->bit01)
#define P1PWGA4            (((volatile __bitf_T *)0xFFFFA09A)->bit01)
#define P2ENCA0IOV         (((volatile __bitf_T *)0xFFFFA09A)->bit02)
#define P2PWGA4            (((volatile __bitf_T *)0xFFFFA09A)->bit02)
#define TBENCA0IOV         (((volatile __bitf_T *)0xFFFFA09A)->bit06)
#define TBPWGA4            (((volatile __bitf_T *)0xFFFFA09A)->bit06)
#define MKENCA0IOV         (((volatile __bitf_T *)0xFFFFA09A)->bit07)
#define MKPWGA4            (((volatile __bitf_T *)0xFFFFA09A)->bit07)
#define RFENCA0IOV         (((volatile __bitf_T *)0xFFFFA09B)->bit04)
#define RFPWGA4            (((volatile __bitf_T *)0xFFFFA09B)->bit04)
#define CTENCA0IOV         (((volatile __bitf_T *)0xFFFFA09B)->bit07)
#define CTPWGA4            (((volatile __bitf_T *)0xFFFFA09B)->bit07)
#define ICENCA0IUD         (*(volatile unsigned short *)0xFFFFA09C)
#define ICPWGA5            (*(volatile unsigned short *)0xFFFFA09C)
#define ICENCA0IUDL        (*(volatile unsigned char  *)0xFFFFA09C)
#define ICPWGA5L           (*(volatile unsigned char  *)0xFFFFA09C)
#define ICENCA0IUDH        (*(volatile unsigned char  *)0xFFFFA09D)
#define ICPWGA5H           (*(volatile unsigned char  *)0xFFFFA09D)
#define P0ENCA0IUD         (((volatile __bitf_T *)0xFFFFA09C)->bit00)
#define P0PWGA5            (((volatile __bitf_T *)0xFFFFA09C)->bit00)
#define P1ENCA0IUD         (((volatile __bitf_T *)0xFFFFA09C)->bit01)
#define P1PWGA5            (((volatile __bitf_T *)0xFFFFA09C)->bit01)
#define P2ENCA0IUD         (((volatile __bitf_T *)0xFFFFA09C)->bit02)
#define P2PWGA5            (((volatile __bitf_T *)0xFFFFA09C)->bit02)
#define TBENCA0IUD         (((volatile __bitf_T *)0xFFFFA09C)->bit06)
#define TBPWGA5            (((volatile __bitf_T *)0xFFFFA09C)->bit06)
#define MKENCA0IUD         (((volatile __bitf_T *)0xFFFFA09C)->bit07)
#define MKPWGA5            (((volatile __bitf_T *)0xFFFFA09C)->bit07)
#define RFENCA0IUD         (((volatile __bitf_T *)0xFFFFA09D)->bit04)
#define RFPWGA5            (((volatile __bitf_T *)0xFFFFA09D)->bit04)
#define CTENCA0IUD         (((volatile __bitf_T *)0xFFFFA09D)->bit07)
#define CTPWGA5            (((volatile __bitf_T *)0xFFFFA09D)->bit07)
#define ICENCA0I0          (*(volatile unsigned short *)0xFFFFA09E)
#define ICPWGA6            (*(volatile unsigned short *)0xFFFFA09E)
#define ICENCA0I0L         (*(volatile unsigned char  *)0xFFFFA09E)
#define ICPWGA6L           (*(volatile unsigned char  *)0xFFFFA09E)
#define ICENCA0I0H         (*(volatile unsigned char  *)0xFFFFA09F)
#define ICPWGA6H           (*(volatile unsigned char  *)0xFFFFA09F)
#define P0ENCA0I0          (((volatile __bitf_T *)0xFFFFA09E)->bit00)
#define P0PWGA6            (((volatile __bitf_T *)0xFFFFA09E)->bit00)
#define P1ENCA0I0          (((volatile __bitf_T *)0xFFFFA09E)->bit01)
#define P1PWGA6            (((volatile __bitf_T *)0xFFFFA09E)->bit01)
#define P2ENCA0I0          (((volatile __bitf_T *)0xFFFFA09E)->bit02)
#define P2PWGA6            (((volatile __bitf_T *)0xFFFFA09E)->bit02)
#define TBENCA0I0          (((volatile __bitf_T *)0xFFFFA09E)->bit06)
#define TBPWGA6            (((volatile __bitf_T *)0xFFFFA09E)->bit06)
#define MKENCA0I0          (((volatile __bitf_T *)0xFFFFA09E)->bit07)
#define MKPWGA6            (((volatile __bitf_T *)0xFFFFA09E)->bit07)
#define RFENCA0I0          (((volatile __bitf_T *)0xFFFFA09F)->bit04)
#define RFPWGA6            (((volatile __bitf_T *)0xFFFFA09F)->bit04)
#define CTENCA0I0          (((volatile __bitf_T *)0xFFFFA09F)->bit07)
#define CTPWGA6            (((volatile __bitf_T *)0xFFFFA09F)->bit07)
#define ICENCA0I1          (*(volatile unsigned short *)0xFFFFA0A0)
#define ICPWGA7            (*(volatile unsigned short *)0xFFFFA0A0)
#define ICENCA0I1L         (*(volatile unsigned char  *)0xFFFFA0A0)
#define ICPWGA7L           (*(volatile unsigned char  *)0xFFFFA0A0)
#define ICENCA0I1H         (*(volatile unsigned char  *)0xFFFFA0A1)
#define ICPWGA7H           (*(volatile unsigned char  *)0xFFFFA0A1)
#define P0ENCA0I1          (((volatile __bitf_T *)0xFFFFA0A0)->bit00)
#define P0PWGA7            (((volatile __bitf_T *)0xFFFFA0A0)->bit00)
#define P1ENCA0I1          (((volatile __bitf_T *)0xFFFFA0A0)->bit01)
#define P1PWGA7            (((volatile __bitf_T *)0xFFFFA0A0)->bit01)
#define P2ENCA0I1          (((volatile __bitf_T *)0xFFFFA0A0)->bit02)
#define P2PWGA7            (((volatile __bitf_T *)0xFFFFA0A0)->bit02)
#define TBENCA0I1          (((volatile __bitf_T *)0xFFFFA0A0)->bit06)
#define TBPWGA7            (((volatile __bitf_T *)0xFFFFA0A0)->bit06)
#define MKENCA0I1          (((volatile __bitf_T *)0xFFFFA0A0)->bit07)
#define MKPWGA7            (((volatile __bitf_T *)0xFFFFA0A0)->bit07)
#define RFENCA0I1          (((volatile __bitf_T *)0xFFFFA0A1)->bit04)
#define RFPWGA7            (((volatile __bitf_T *)0xFFFFA0A1)->bit04)
#define CTENCA0I1          (((volatile __bitf_T *)0xFFFFA0A1)->bit07)
#define CTPWGA7            (((volatile __bitf_T *)0xFFFFA0A1)->bit07)
#define ICENCA0IEC         (*(volatile unsigned short *)0xFFFFA0A2)
#define ICENCA0IECL        (*(volatile unsigned char  *)0xFFFFA0A2)
#define ICENCA0IECH        (*(volatile unsigned char  *)0xFFFFA0A3)
#define P0ENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A2)->bit00)
#define P1ENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A2)->bit01)
#define P2ENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A2)->bit02)
#define TBENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A2)->bit06)
#define MKENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A2)->bit07)
#define RFENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A3)->bit04)
#define CTENCA0IEC         (((volatile __bitf_T *)0xFFFFA0A3)->bit07)
#define ICKR0              (*(volatile unsigned short *)0xFFFFA0A4)
#define ICKR0L             (*(volatile unsigned char  *)0xFFFFA0A4)
#define ICKR0H             (*(volatile unsigned char  *)0xFFFFA0A5)
#define P0KR0              (((volatile __bitf_T *)0xFFFFA0A4)->bit00)
#define P1KR0              (((volatile __bitf_T *)0xFFFFA0A4)->bit01)
#define P2KR0              (((volatile __bitf_T *)0xFFFFA0A4)->bit02)
#define TBKR0              (((volatile __bitf_T *)0xFFFFA0A4)->bit06)
#define MKKR0              (((volatile __bitf_T *)0xFFFFA0A4)->bit07)
#define RFKR0              (((volatile __bitf_T *)0xFFFFA0A5)->bit04)
#define CTKR0              (((volatile __bitf_T *)0xFFFFA0A5)->bit07)
#define ICQFULL            (*(volatile unsigned short *)0xFFFFA0A6)
#define ICQFULLL           (*(volatile unsigned char  *)0xFFFFA0A6)
#define ICQFULLH           (*(volatile unsigned char  *)0xFFFFA0A7)
#define P0QFULL            (((volatile __bitf_T *)0xFFFFA0A6)->bit00)
#define P1QFULL            (((volatile __bitf_T *)0xFFFFA0A6)->bit01)
#define P2QFULL            (((volatile __bitf_T *)0xFFFFA0A6)->bit02)
#define TBQFULL            (((volatile __bitf_T *)0xFFFFA0A6)->bit06)
#define MKQFULL            (((volatile __bitf_T *)0xFFFFA0A6)->bit07)
#define RFQFULL            (((volatile __bitf_T *)0xFFFFA0A7)->bit04)
#define CTQFULL            (((volatile __bitf_T *)0xFFFFA0A7)->bit07)
#define ICPWGA0            (*(volatile unsigned short *)0xFFFFA0A8)
#define ICPWGA0L           (*(volatile unsigned char  *)0xFFFFA0A8)
#define ICPWGA0H           (*(volatile unsigned char  *)0xFFFFA0A9)
#define P0PWGA0            (((volatile __bitf_T *)0xFFFFA0A8)->bit00)
#define P1PWGA0            (((volatile __bitf_T *)0xFFFFA0A8)->bit01)
#define P2PWGA0            (((volatile __bitf_T *)0xFFFFA0A8)->bit02)
#define TBPWGA0            (((volatile __bitf_T *)0xFFFFA0A8)->bit06)
#define MKPWGA0            (((volatile __bitf_T *)0xFFFFA0A8)->bit07)
#define RFPWGA0            (((volatile __bitf_T *)0xFFFFA0A9)->bit04)
#define CTPWGA0            (((volatile __bitf_T *)0xFFFFA0A9)->bit07)
#define ICPWGA1            (*(volatile unsigned short *)0xFFFFA0AA)
#define ICPWGA1L           (*(volatile unsigned char  *)0xFFFFA0AA)
#define ICPWGA1H           (*(volatile unsigned char  *)0xFFFFA0AB)
#define P0PWGA1            (((volatile __bitf_T *)0xFFFFA0AA)->bit00)
#define P1PWGA1            (((volatile __bitf_T *)0xFFFFA0AA)->bit01)
#define P2PWGA1            (((volatile __bitf_T *)0xFFFFA0AA)->bit02)
#define TBPWGA1            (((volatile __bitf_T *)0xFFFFA0AA)->bit06)
#define MKPWGA1            (((volatile __bitf_T *)0xFFFFA0AA)->bit07)
#define RFPWGA1            (((volatile __bitf_T *)0xFFFFA0AB)->bit04)
#define CTPWGA1            (((volatile __bitf_T *)0xFFFFA0AB)->bit07)
#define ICPWGA2            (*(volatile unsigned short *)0xFFFFA0AC)
#define ICPWGA2L           (*(volatile unsigned char  *)0xFFFFA0AC)
#define ICPWGA2H           (*(volatile unsigned char  *)0xFFFFA0AD)
#define P0PWGA2            (((volatile __bitf_T *)0xFFFFA0AC)->bit00)
#define P1PWGA2            (((volatile __bitf_T *)0xFFFFA0AC)->bit01)
#define P2PWGA2            (((volatile __bitf_T *)0xFFFFA0AC)->bit02)
#define TBPWGA2            (((volatile __bitf_T *)0xFFFFA0AC)->bit06)
#define MKPWGA2            (((volatile __bitf_T *)0xFFFFA0AC)->bit07)
#define RFPWGA2            (((volatile __bitf_T *)0xFFFFA0AD)->bit04)
#define CTPWGA2            (((volatile __bitf_T *)0xFFFFA0AD)->bit07)
#define ICPWGA3            (*(volatile unsigned short *)0xFFFFA0AE)
#define ICPWGA3L           (*(volatile unsigned char  *)0xFFFFA0AE)
#define ICPWGA3H           (*(volatile unsigned char  *)0xFFFFA0AF)
#define P0PWGA3            (((volatile __bitf_T *)0xFFFFA0AE)->bit00)
#define P1PWGA3            (((volatile __bitf_T *)0xFFFFA0AE)->bit01)
#define P2PWGA3            (((volatile __bitf_T *)0xFFFFA0AE)->bit02)
#define TBPWGA3            (((volatile __bitf_T *)0xFFFFA0AE)->bit06)
#define MKPWGA3            (((volatile __bitf_T *)0xFFFFA0AE)->bit07)
#define RFPWGA3            (((volatile __bitf_T *)0xFFFFA0AF)->bit04)
#define CTPWGA3            (((volatile __bitf_T *)0xFFFFA0AF)->bit07)
#define ICPWGA8            (*(volatile unsigned short *)0xFFFFA0B0)
#define ICPWGA8L           (*(volatile unsigned char  *)0xFFFFA0B0)
#define ICPWGA8H           (*(volatile unsigned char  *)0xFFFFA0B1)
#define P0PWGA8            (((volatile __bitf_T *)0xFFFFA0B0)->bit00)
#define P1PWGA8            (((volatile __bitf_T *)0xFFFFA0B0)->bit01)
#define P2PWGA8            (((volatile __bitf_T *)0xFFFFA0B0)->bit02)
#define TBPWGA8            (((volatile __bitf_T *)0xFFFFA0B0)->bit06)
#define MKPWGA8            (((volatile __bitf_T *)0xFFFFA0B0)->bit07)
#define RFPWGA8            (((volatile __bitf_T *)0xFFFFA0B1)->bit04)
#define CTPWGA8            (((volatile __bitf_T *)0xFFFFA0B1)->bit07)
#define ICPWGA9            (*(volatile unsigned short *)0xFFFFA0B2)
#define ICPWGA9L           (*(volatile unsigned char  *)0xFFFFA0B2)
#define ICPWGA9H           (*(volatile unsigned char  *)0xFFFFA0B3)
#define P0PWGA9            (((volatile __bitf_T *)0xFFFFA0B2)->bit00)
#define P1PWGA9            (((volatile __bitf_T *)0xFFFFA0B2)->bit01)
#define P2PWGA9            (((volatile __bitf_T *)0xFFFFA0B2)->bit02)
#define TBPWGA9            (((volatile __bitf_T *)0xFFFFA0B2)->bit06)
#define MKPWGA9            (((volatile __bitf_T *)0xFFFFA0B2)->bit07)
#define RFPWGA9            (((volatile __bitf_T *)0xFFFFA0B3)->bit04)
#define CTPWGA9            (((volatile __bitf_T *)0xFFFFA0B3)->bit07)
#define ICPWGA10           (*(volatile unsigned short *)0xFFFFA0B4)
#define ICPWGA10L          (*(volatile unsigned char  *)0xFFFFA0B4)
#define ICPWGA10H          (*(volatile unsigned char  *)0xFFFFA0B5)
#define P0PWGA10           (((volatile __bitf_T *)0xFFFFA0B4)->bit00)
#define P1PWGA10           (((volatile __bitf_T *)0xFFFFA0B4)->bit01)
#define P2PWGA10           (((volatile __bitf_T *)0xFFFFA0B4)->bit02)
#define TBPWGA10           (((volatile __bitf_T *)0xFFFFA0B4)->bit06)
#define MKPWGA10           (((volatile __bitf_T *)0xFFFFA0B4)->bit07)
#define RFPWGA10           (((volatile __bitf_T *)0xFFFFA0B5)->bit04)
#define CTPWGA10           (((volatile __bitf_T *)0xFFFFA0B5)->bit07)
#define ICPWGA11           (*(volatile unsigned short *)0xFFFFA0B6)
#define ICPWGA11L          (*(volatile unsigned char  *)0xFFFFA0B6)
#define ICPWGA11H          (*(volatile unsigned char  *)0xFFFFA0B7)
#define P0PWGA11           (((volatile __bitf_T *)0xFFFFA0B6)->bit00)
#define P1PWGA11           (((volatile __bitf_T *)0xFFFFA0B6)->bit01)
#define P2PWGA11           (((volatile __bitf_T *)0xFFFFA0B6)->bit02)
#define TBPWGA11           (((volatile __bitf_T *)0xFFFFA0B6)->bit06)
#define MKPWGA11           (((volatile __bitf_T *)0xFFFFA0B6)->bit07)
#define RFPWGA11           (((volatile __bitf_T *)0xFFFFA0B7)->bit04)
#define CTPWGA11           (((volatile __bitf_T *)0xFFFFA0B7)->bit07)
#define ICPWGA12           (*(volatile unsigned short *)0xFFFFA0B8)
#define ICPWGA12L          (*(volatile unsigned char  *)0xFFFFA0B8)
#define ICPWGA12H          (*(volatile unsigned char  *)0xFFFFA0B9)
#define P0PWGA12           (((volatile __bitf_T *)0xFFFFA0B8)->bit00)
#define P1PWGA12           (((volatile __bitf_T *)0xFFFFA0B8)->bit01)
#define P2PWGA12           (((volatile __bitf_T *)0xFFFFA0B8)->bit02)
#define TBPWGA12           (((volatile __bitf_T *)0xFFFFA0B8)->bit06)
#define MKPWGA12           (((volatile __bitf_T *)0xFFFFA0B8)->bit07)
#define RFPWGA12           (((volatile __bitf_T *)0xFFFFA0B9)->bit04)
#define CTPWGA12           (((volatile __bitf_T *)0xFFFFA0B9)->bit07)
#define ICPWGA13           (*(volatile unsigned short *)0xFFFFA0BA)
#define ICPWGA13L          (*(volatile unsigned char  *)0xFFFFA0BA)
#define ICPWGA13H          (*(volatile unsigned char  *)0xFFFFA0BB)
#define P0PWGA13           (((volatile __bitf_T *)0xFFFFA0BA)->bit00)
#define P1PWGA13           (((volatile __bitf_T *)0xFFFFA0BA)->bit01)
#define P2PWGA13           (((volatile __bitf_T *)0xFFFFA0BA)->bit02)
#define TBPWGA13           (((volatile __bitf_T *)0xFFFFA0BA)->bit06)
#define MKPWGA13           (((volatile __bitf_T *)0xFFFFA0BA)->bit07)
#define RFPWGA13           (((volatile __bitf_T *)0xFFFFA0BB)->bit04)
#define CTPWGA13           (((volatile __bitf_T *)0xFFFFA0BB)->bit07)
#define ICPWGA14           (*(volatile unsigned short *)0xFFFFA0BC)
#define ICPWGA14L          (*(volatile unsigned char  *)0xFFFFA0BC)
#define ICPWGA14H          (*(volatile unsigned char  *)0xFFFFA0BD)
#define P0PWGA14           (((volatile __bitf_T *)0xFFFFA0BC)->bit00)
#define P1PWGA14           (((volatile __bitf_T *)0xFFFFA0BC)->bit01)
#define P2PWGA14           (((volatile __bitf_T *)0xFFFFA0BC)->bit02)
#define TBPWGA14           (((volatile __bitf_T *)0xFFFFA0BC)->bit06)
#define MKPWGA14           (((volatile __bitf_T *)0xFFFFA0BC)->bit07)
#define RFPWGA14           (((volatile __bitf_T *)0xFFFFA0BD)->bit04)
#define CTPWGA14           (((volatile __bitf_T *)0xFFFFA0BD)->bit07)
#define ICPWGA15           (*(volatile unsigned short *)0xFFFFA0BE)
#define ICPWGA15L          (*(volatile unsigned char  *)0xFFFFA0BE)
#define ICPWGA15H          (*(volatile unsigned char  *)0xFFFFA0BF)
#define P0PWGA15           (((volatile __bitf_T *)0xFFFFA0BE)->bit00)
#define P1PWGA15           (((volatile __bitf_T *)0xFFFFA0BE)->bit01)
#define P2PWGA15           (((volatile __bitf_T *)0xFFFFA0BE)->bit02)
#define TBPWGA15           (((volatile __bitf_T *)0xFFFFA0BE)->bit06)
#define MKPWGA15           (((volatile __bitf_T *)0xFFFFA0BE)->bit07)
#define RFPWGA15           (((volatile __bitf_T *)0xFFFFA0BF)->bit04)
#define CTPWGA15           (((volatile __bitf_T *)0xFFFFA0BF)->bit07)
#define ICFLERR            (*(volatile unsigned short *)0xFFFFA0CC)
#define ICFLERRL           (*(volatile unsigned char  *)0xFFFFA0CC)
#define ICFLERRH           (*(volatile unsigned char  *)0xFFFFA0CD)
#define P0FLERR            (((volatile __bitf_T *)0xFFFFA0CC)->bit00)
#define P1FLERR            (((volatile __bitf_T *)0xFFFFA0CC)->bit01)
#define P2FLERR            (((volatile __bitf_T *)0xFFFFA0CC)->bit02)
#define TBFLERR            (((volatile __bitf_T *)0xFFFFA0CC)->bit06)
#define MKFLERR            (((volatile __bitf_T *)0xFFFFA0CC)->bit07)
#define RFFLERR            (((volatile __bitf_T *)0xFFFFA0CD)->bit04)
#define CTFLERR            (((volatile __bitf_T *)0xFFFFA0CD)->bit07)
#define ICFLENDNM          (*(volatile unsigned short *)0xFFFFA0CE)
#define ICFLENDNML         (*(volatile unsigned char  *)0xFFFFA0CE)
#define ICFLENDNMH         (*(volatile unsigned char  *)0xFFFFA0CF)
#define P0FLENDNM          (((volatile __bitf_T *)0xFFFFA0CE)->bit00)
#define P1FLENDNM          (((volatile __bitf_T *)0xFFFFA0CE)->bit01)
#define P2FLENDNM          (((volatile __bitf_T *)0xFFFFA0CE)->bit02)
#define TBFLENDNM          (((volatile __bitf_T *)0xFFFFA0CE)->bit06)
#define MKFLENDNM          (((volatile __bitf_T *)0xFFFFA0CE)->bit07)
#define RFFLENDNM          (((volatile __bitf_T *)0xFFFFA0CF)->bit04)
#define CTFLENDNM          (((volatile __bitf_T *)0xFFFFA0CF)->bit07)
#define ICCWEND            (*(volatile unsigned short *)0xFFFFA0D0)
#define ICCWENDL           (*(volatile unsigned char  *)0xFFFFA0D0)
#define ICCWENDH           (*(volatile unsigned char  *)0xFFFFA0D1)
#define P0CWEND            (((volatile __bitf_T *)0xFFFFA0D0)->bit00)
#define P1CWEND            (((volatile __bitf_T *)0xFFFFA0D0)->bit01)
#define P2CWEND            (((volatile __bitf_T *)0xFFFFA0D0)->bit02)
#define TBCWEND            (((volatile __bitf_T *)0xFFFFA0D0)->bit06)
#define MKCWEND            (((volatile __bitf_T *)0xFFFFA0D0)->bit07)
#define RFCWEND            (((volatile __bitf_T *)0xFFFFA0D1)->bit04)
#define CTCWEND            (((volatile __bitf_T *)0xFFFFA0D1)->bit07)
#define ICRCAN1ERR         (*(volatile unsigned short *)0xFFFFA0D2)
#define ICRCAN1ERRL        (*(volatile unsigned char  *)0xFFFFA0D2)
#define ICRCAN1ERRH        (*(volatile unsigned char  *)0xFFFFA0D3)
#define P0RCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D2)->bit00)
#define P1RCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D2)->bit01)
#define P2RCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D2)->bit02)
#define TBRCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D2)->bit06)
#define MKRCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D2)->bit07)
#define RFRCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D3)->bit04)
#define CTRCAN1ERR         (((volatile __bitf_T *)0xFFFFA0D3)->bit07)
#define ICRCAN1REC         (*(volatile unsigned short *)0xFFFFA0D4)
#define ICRCAN1RECL        (*(volatile unsigned char  *)0xFFFFA0D4)
#define ICRCAN1RECH        (*(volatile unsigned char  *)0xFFFFA0D5)
#define P0RCAN1REC         (((volatile __bitf_T *)0xFFFFA0D4)->bit00)
#define P1RCAN1REC         (((volatile __bitf_T *)0xFFFFA0D4)->bit01)
#define P2RCAN1REC         (((volatile __bitf_T *)0xFFFFA0D4)->bit02)
#define TBRCAN1REC         (((volatile __bitf_T *)0xFFFFA0D4)->bit06)
#define MKRCAN1REC         (((volatile __bitf_T *)0xFFFFA0D4)->bit07)
#define RFRCAN1REC         (((volatile __bitf_T *)0xFFFFA0D5)->bit04)
#define CTRCAN1REC         (((volatile __bitf_T *)0xFFFFA0D5)->bit07)
#define ICRCAN1TRX         (*(volatile unsigned short *)0xFFFFA0D6)
#define ICRCAN1TRXL        (*(volatile unsigned char  *)0xFFFFA0D6)
#define ICRCAN1TRXH        (*(volatile unsigned char  *)0xFFFFA0D7)
#define P0RCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D6)->bit00)
#define P1RCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D6)->bit01)
#define P2RCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D6)->bit02)
#define TBRCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D6)->bit06)
#define MKRCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D6)->bit07)
#define RFRCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D7)->bit04)
#define CTRCAN1TRX         (((volatile __bitf_T *)0xFFFFA0D7)->bit07)
#define ICCSIH1IC          (*(volatile unsigned short *)0xFFFFA0D8)
#define ICTAPA0IPEK0_2     (*(volatile unsigned short *)0xFFFFA0D8)
#define ICCSIH1ICL         (*(volatile unsigned char  *)0xFFFFA0D8)
#define ICTAPA0IPEK0L_2    (*(volatile unsigned char  *)0xFFFFA0D8)
#define ICCSIH1ICH         (*(volatile unsigned char  *)0xFFFFA0D9)
#define ICTAPA0IPEK0H_2    (*(volatile unsigned char  *)0xFFFFA0D9)
#define P0CSIH1IC          (((volatile __bitf_T *)0xFFFFA0D8)->bit00)
#define P0TAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D8)->bit00)
#define P1CSIH1IC          (((volatile __bitf_T *)0xFFFFA0D8)->bit01)
#define P1TAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D8)->bit01)
#define P2CSIH1IC          (((volatile __bitf_T *)0xFFFFA0D8)->bit02)
#define P2TAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D8)->bit02)
#define TBCSIH1IC          (((volatile __bitf_T *)0xFFFFA0D8)->bit06)
#define TBTAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D8)->bit06)
#define MKCSIH1IC          (((volatile __bitf_T *)0xFFFFA0D8)->bit07)
#define MKTAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D8)->bit07)
#define RFCSIH1IC          (((volatile __bitf_T *)0xFFFFA0D9)->bit04)
#define RFTAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D9)->bit04)
#define CTCSIH1IC          (((volatile __bitf_T *)0xFFFFA0D9)->bit07)
#define CTTAPA0IPEK0_2     (((volatile __bitf_T *)0xFFFFA0D9)->bit07)
#define ICCSIH1IR          (*(volatile unsigned short *)0xFFFFA0DA)
#define ICTAPA0IVLY0_2     (*(volatile unsigned short *)0xFFFFA0DA)
#define ICCSIH1IRL         (*(volatile unsigned char  *)0xFFFFA0DA)
#define ICTAPA0IVLY0L_2    (*(volatile unsigned char  *)0xFFFFA0DA)
#define ICCSIH1IRH         (*(volatile unsigned char  *)0xFFFFA0DB)
#define ICTAPA0IVLY0H_2    (*(volatile unsigned char  *)0xFFFFA0DB)
#define P0CSIH1IR          (((volatile __bitf_T *)0xFFFFA0DA)->bit00)
#define P0TAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DA)->bit00)
#define P1CSIH1IR          (((volatile __bitf_T *)0xFFFFA0DA)->bit01)
#define P1TAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DA)->bit01)
#define P2CSIH1IR          (((volatile __bitf_T *)0xFFFFA0DA)->bit02)
#define P2TAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DA)->bit02)
#define TBCSIH1IR          (((volatile __bitf_T *)0xFFFFA0DA)->bit06)
#define TBTAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DA)->bit06)
#define MKCSIH1IR          (((volatile __bitf_T *)0xFFFFA0DA)->bit07)
#define MKTAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DA)->bit07)
#define RFCSIH1IR          (((volatile __bitf_T *)0xFFFFA0DB)->bit04)
#define RFTAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DB)->bit04)
#define CTCSIH1IR          (((volatile __bitf_T *)0xFFFFA0DB)->bit07)
#define CTTAPA0IVLY0_2     (((volatile __bitf_T *)0xFFFFA0DB)->bit07)
#define ICCSIG0IC_2        (*(volatile unsigned short *)0xFFFFA0DC)
#define ICCSIH1IRE         (*(volatile unsigned short *)0xFFFFA0DC)
#define ICCSIG0ICL_2       (*(volatile unsigned char  *)0xFFFFA0DC)
#define ICCSIH1IREL        (*(volatile unsigned char  *)0xFFFFA0DC)
#define ICCSIG0ICH_2       (*(volatile unsigned char  *)0xFFFFA0DD)
#define ICCSIH1IREH        (*(volatile unsigned char  *)0xFFFFA0DD)
#define P0CSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DC)->bit00)
#define P0CSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DC)->bit00)
#define P1CSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DC)->bit01)
#define P1CSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DC)->bit01)
#define P2CSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DC)->bit02)
#define P2CSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DC)->bit02)
#define TBCSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DC)->bit06)
#define TBCSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DC)->bit06)
#define MKCSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DC)->bit07)
#define MKCSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DC)->bit07)
#define RFCSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DD)->bit04)
#define RFCSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DD)->bit04)
#define CTCSIG0IC_2        (((volatile __bitf_T *)0xFFFFA0DD)->bit07)
#define CTCSIH1IRE         (((volatile __bitf_T *)0xFFFFA0DD)->bit07)
#define ICCSIG0IR_2        (*(volatile unsigned short *)0xFFFFA0DE)
#define ICCSIH1IJC         (*(volatile unsigned short *)0xFFFFA0DE)
#define ICCSIG0IRL_2       (*(volatile unsigned char  *)0xFFFFA0DE)
#define ICCSIH1IJCL        (*(volatile unsigned char  *)0xFFFFA0DE)
#define ICCSIG0IRH_2       (*(volatile unsigned char  *)0xFFFFA0DF)
#define ICCSIH1IJCH        (*(volatile unsigned char  *)0xFFFFA0DF)
#define P0CSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DE)->bit00)
#define P0CSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DE)->bit00)
#define P1CSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DE)->bit01)
#define P1CSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DE)->bit01)
#define P2CSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DE)->bit02)
#define P2CSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DE)->bit02)
#define TBCSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DE)->bit06)
#define TBCSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DE)->bit06)
#define MKCSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DE)->bit07)
#define MKCSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DE)->bit07)
#define RFCSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DF)->bit04)
#define RFCSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DF)->bit04)
#define CTCSIG0IR_2        (((volatile __bitf_T *)0xFFFFA0DF)->bit07)
#define CTCSIH1IJC         (((volatile __bitf_T *)0xFFFFA0DF)->bit07)
#define ICRLIN31           (*(volatile unsigned short *)0xFFFFA0E0)
#define ICRLIN31L          (*(volatile unsigned char  *)0xFFFFA0E0)
#define ICRLIN31H          (*(volatile unsigned char  *)0xFFFFA0E1)
#define P0RLIN31           (((volatile __bitf_T *)0xFFFFA0E0)->bit00)
#define P1RLIN31           (((volatile __bitf_T *)0xFFFFA0E0)->bit01)
#define P2RLIN31           (((volatile __bitf_T *)0xFFFFA0E0)->bit02)
#define TBRLIN31           (((volatile __bitf_T *)0xFFFFA0E0)->bit06)
#define MKRLIN31           (((volatile __bitf_T *)0xFFFFA0E0)->bit07)
#define RFRLIN31           (((volatile __bitf_T *)0xFFFFA0E1)->bit04)
#define CTRLIN31           (((volatile __bitf_T *)0xFFFFA0E1)->bit07)
#define ICRLIN31UR0        (*(volatile unsigned short *)0xFFFFA0E2)
#define ICRLIN31UR0L       (*(volatile unsigned char  *)0xFFFFA0E2)
#define ICRLIN31UR0H       (*(volatile unsigned char  *)0xFFFFA0E3)
#define P0RLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E2)->bit00)
#define P1RLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E2)->bit01)
#define P2RLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E2)->bit02)
#define TBRLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E2)->bit06)
#define MKRLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E2)->bit07)
#define RFRLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E3)->bit04)
#define CTRLIN31UR0        (((volatile __bitf_T *)0xFFFFA0E3)->bit07)
#define ICRLIN31UR1        (*(volatile unsigned short *)0xFFFFA0E4)
#define ICRLIN31UR1L       (*(volatile unsigned char  *)0xFFFFA0E4)
#define ICRLIN31UR1H       (*(volatile unsigned char  *)0xFFFFA0E5)
#define P0RLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E4)->bit00)
#define P1RLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E4)->bit01)
#define P2RLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E4)->bit02)
#define TBRLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E4)->bit06)
#define MKRLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E4)->bit07)
#define RFRLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E5)->bit04)
#define CTRLIN31UR1        (((volatile __bitf_T *)0xFFFFA0E5)->bit07)
#define ICRLIN31UR2        (*(volatile unsigned short *)0xFFFFA0E6)
#define ICRLIN31UR2L       (*(volatile unsigned char  *)0xFFFFA0E6)
#define ICRLIN31UR2H       (*(volatile unsigned char  *)0xFFFFA0E7)
#define P0RLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E6)->bit00)
#define P1RLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E6)->bit01)
#define P2RLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E6)->bit02)
#define TBRLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E6)->bit06)
#define MKRLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E6)->bit07)
#define RFRLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E7)->bit04)
#define CTRLIN31UR2        (((volatile __bitf_T *)0xFFFFA0E7)->bit07)
#define ICPWGA20           (*(volatile unsigned short *)0xFFFFA0E8)
#define ICPWGA20L          (*(volatile unsigned char  *)0xFFFFA0E8)
#define ICPWGA20H          (*(volatile unsigned char  *)0xFFFFA0E9)
#define P0PWGA20           (((volatile __bitf_T *)0xFFFFA0E8)->bit00)
#define P1PWGA20           (((volatile __bitf_T *)0xFFFFA0E8)->bit01)
#define P2PWGA20           (((volatile __bitf_T *)0xFFFFA0E8)->bit02)
#define TBPWGA20           (((volatile __bitf_T *)0xFFFFA0E8)->bit06)
#define MKPWGA20           (((volatile __bitf_T *)0xFFFFA0E8)->bit07)
#define RFPWGA20           (((volatile __bitf_T *)0xFFFFA0E9)->bit04)
#define CTPWGA20           (((volatile __bitf_T *)0xFFFFA0E9)->bit07)
#define ICPWGA21           (*(volatile unsigned short *)0xFFFFA0EA)
#define ICPWGA21L          (*(volatile unsigned char  *)0xFFFFA0EA)
#define ICPWGA21H          (*(volatile unsigned char  *)0xFFFFA0EB)
#define P0PWGA21           (((volatile __bitf_T *)0xFFFFA0EA)->bit00)
#define P1PWGA21           (((volatile __bitf_T *)0xFFFFA0EA)->bit01)
#define P2PWGA21           (((volatile __bitf_T *)0xFFFFA0EA)->bit02)
#define TBPWGA21           (((volatile __bitf_T *)0xFFFFA0EA)->bit06)
#define MKPWGA21           (((volatile __bitf_T *)0xFFFFA0EA)->bit07)
#define RFPWGA21           (((volatile __bitf_T *)0xFFFFA0EB)->bit04)
#define CTPWGA21           (((volatile __bitf_T *)0xFFFFA0EB)->bit07)
#define ICPWGA22           (*(volatile unsigned short *)0xFFFFA0EC)
#define ICPWGA22L          (*(volatile unsigned char  *)0xFFFFA0EC)
#define ICPWGA22H          (*(volatile unsigned char  *)0xFFFFA0ED)
#define P0PWGA22           (((volatile __bitf_T *)0xFFFFA0EC)->bit00)
#define P1PWGA22           (((volatile __bitf_T *)0xFFFFA0EC)->bit01)
#define P2PWGA22           (((volatile __bitf_T *)0xFFFFA0EC)->bit02)
#define TBPWGA22           (((volatile __bitf_T *)0xFFFFA0EC)->bit06)
#define MKPWGA22           (((volatile __bitf_T *)0xFFFFA0EC)->bit07)
#define RFPWGA22           (((volatile __bitf_T *)0xFFFFA0ED)->bit04)
#define CTPWGA22           (((volatile __bitf_T *)0xFFFFA0ED)->bit07)
#define ICPWGA23           (*(volatile unsigned short *)0xFFFFA0EE)
#define ICPWGA23L          (*(volatile unsigned char  *)0xFFFFA0EE)
#define ICPWGA23H          (*(volatile unsigned char  *)0xFFFFA0EF)
#define P0PWGA23           (((volatile __bitf_T *)0xFFFFA0EE)->bit00)
#define P1PWGA23           (((volatile __bitf_T *)0xFFFFA0EE)->bit01)
#define P2PWGA23           (((volatile __bitf_T *)0xFFFFA0EE)->bit02)
#define TBPWGA23           (((volatile __bitf_T *)0xFFFFA0EE)->bit06)
#define MKPWGA23           (((volatile __bitf_T *)0xFFFFA0EE)->bit07)
#define RFPWGA23           (((volatile __bitf_T *)0xFFFFA0EF)->bit04)
#define CTPWGA23           (((volatile __bitf_T *)0xFFFFA0EF)->bit07)
#define ICP6               (*(volatile unsigned short *)0xFFFFA0F0)
#define ICP6L              (*(volatile unsigned char  *)0xFFFFA0F0)
#define ICP6H              (*(volatile unsigned char  *)0xFFFFA0F1)
#define P0P6               (((volatile __bitf_T *)0xFFFFA0F0)->bit00)
#define P1P6               (((volatile __bitf_T *)0xFFFFA0F0)->bit01)
#define P2P6               (((volatile __bitf_T *)0xFFFFA0F0)->bit02)
#define TBP6               (((volatile __bitf_T *)0xFFFFA0F0)->bit06)
#define MKP6               (((volatile __bitf_T *)0xFFFFA0F0)->bit07)
#define RFP6               (((volatile __bitf_T *)0xFFFFA0F1)->bit04)
#define CTP6               (((volatile __bitf_T *)0xFFFFA0F1)->bit07)
#define ICP7               (*(volatile unsigned short *)0xFFFFA0F2)
#define ICP7L              (*(volatile unsigned char  *)0xFFFFA0F2)
#define ICP7H              (*(volatile unsigned char  *)0xFFFFA0F3)
#define P0P7               (((volatile __bitf_T *)0xFFFFA0F2)->bit00)
#define P1P7               (((volatile __bitf_T *)0xFFFFA0F2)->bit01)
#define P2P7               (((volatile __bitf_T *)0xFFFFA0F2)->bit02)
#define TBP7               (((volatile __bitf_T *)0xFFFFA0F2)->bit06)
#define MKP7               (((volatile __bitf_T *)0xFFFFA0F2)->bit07)
#define RFP7               (((volatile __bitf_T *)0xFFFFA0F3)->bit04)
#define CTP7               (((volatile __bitf_T *)0xFFFFA0F3)->bit07)
#define ICP8               (*(volatile unsigned short *)0xFFFFA0F4)
#define ICP8L              (*(volatile unsigned char  *)0xFFFFA0F4)
#define ICP8H              (*(volatile unsigned char  *)0xFFFFA0F5)
#define P0P8               (((volatile __bitf_T *)0xFFFFA0F4)->bit00)
#define P1P8               (((volatile __bitf_T *)0xFFFFA0F4)->bit01)
#define P2P8               (((volatile __bitf_T *)0xFFFFA0F4)->bit02)
#define TBP8               (((volatile __bitf_T *)0xFFFFA0F4)->bit06)
#define MKP8               (((volatile __bitf_T *)0xFFFFA0F4)->bit07)
#define RFP8               (((volatile __bitf_T *)0xFFFFA0F5)->bit04)
#define CTP8               (((volatile __bitf_T *)0xFFFFA0F5)->bit07)
#define ICP12              (*(volatile unsigned short *)0xFFFFA0F6)
#define ICP12L             (*(volatile unsigned char  *)0xFFFFA0F6)
#define ICP12H             (*(volatile unsigned char  *)0xFFFFA0F7)
#define P0P12              (((volatile __bitf_T *)0xFFFFA0F6)->bit00)
#define P1P12              (((volatile __bitf_T *)0xFFFFA0F6)->bit01)
#define P2P12              (((volatile __bitf_T *)0xFFFFA0F6)->bit02)
#define TBP12              (((volatile __bitf_T *)0xFFFFA0F6)->bit06)
#define MKP12              (((volatile __bitf_T *)0xFFFFA0F6)->bit07)
#define RFP12              (((volatile __bitf_T *)0xFFFFA0F7)->bit04)
#define CTP12              (((volatile __bitf_T *)0xFFFFA0F7)->bit07)
#define ICCSIH2IC          (*(volatile unsigned short *)0xFFFFA0F8)
#define ICTAUD0I0_2        (*(volatile unsigned short *)0xFFFFA0F8)
#define ICCSIH2ICL         (*(volatile unsigned char  *)0xFFFFA0F8)
#define ICTAUD0I0L_2       (*(volatile unsigned char  *)0xFFFFA0F8)
#define ICCSIH2ICH         (*(volatile unsigned char  *)0xFFFFA0F9)
#define ICTAUD0I0H_2       (*(volatile unsigned char  *)0xFFFFA0F9)
#define P0CSIH2IC          (((volatile __bitf_T *)0xFFFFA0F8)->bit00)
#define P0TAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F8)->bit00)
#define P1CSIH2IC          (((volatile __bitf_T *)0xFFFFA0F8)->bit01)
#define P1TAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F8)->bit01)
#define P2CSIH2IC          (((volatile __bitf_T *)0xFFFFA0F8)->bit02)
#define P2TAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F8)->bit02)
#define TBCSIH2IC          (((volatile __bitf_T *)0xFFFFA0F8)->bit06)
#define TBTAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F8)->bit06)
#define MKCSIH2IC          (((volatile __bitf_T *)0xFFFFA0F8)->bit07)
#define MKTAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F8)->bit07)
#define RFCSIH2IC          (((volatile __bitf_T *)0xFFFFA0F9)->bit04)
#define RFTAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F9)->bit04)
#define CTCSIH2IC          (((volatile __bitf_T *)0xFFFFA0F9)->bit07)
#define CTTAUD0I0_2        (((volatile __bitf_T *)0xFFFFA0F9)->bit07)
#define ICCSIH2IR          (*(volatile unsigned short *)0xFFFFA0FA)
#define ICP0_2             (*(volatile unsigned short *)0xFFFFA0FA)
#define ICCSIH2IRL         (*(volatile unsigned char  *)0xFFFFA0FA)
#define ICP0L_2            (*(volatile unsigned char  *)0xFFFFA0FA)
#define ICCSIH2IRH         (*(volatile unsigned char  *)0xFFFFA0FB)
#define ICP0H_2            (*(volatile unsigned char  *)0xFFFFA0FB)
#define P0CSIH2IR          (((volatile __bitf_T *)0xFFFFA0FA)->bit00)
#define P0P0_2             (((volatile __bitf_T *)0xFFFFA0FA)->bit00)
#define P1CSIH2IR          (((volatile __bitf_T *)0xFFFFA0FA)->bit01)
#define P1P0_2             (((volatile __bitf_T *)0xFFFFA0FA)->bit01)
#define P2CSIH2IR          (((volatile __bitf_T *)0xFFFFA0FA)->bit02)
#define P2P0_2             (((volatile __bitf_T *)0xFFFFA0FA)->bit02)
#define TBCSIH2IR          (((volatile __bitf_T *)0xFFFFA0FA)->bit06)
#define TBP0_2             (((volatile __bitf_T *)0xFFFFA0FA)->bit06)
#define MKCSIH2IR          (((volatile __bitf_T *)0xFFFFA0FA)->bit07)
#define MKP0_2             (((volatile __bitf_T *)0xFFFFA0FA)->bit07)
#define RFCSIH2IR          (((volatile __bitf_T *)0xFFFFA0FB)->bit04)
#define RFP0_2             (((volatile __bitf_T *)0xFFFFA0FB)->bit04)
#define CTCSIH2IR          (((volatile __bitf_T *)0xFFFFA0FB)->bit07)
#define CTP0_2             (((volatile __bitf_T *)0xFFFFA0FB)->bit07)
#define ICCSIH2IRE         (*(volatile unsigned short *)0xFFFFA0FC)
#define ICP1_2             (*(volatile unsigned short *)0xFFFFA0FC)
#define ICCSIH2IREL        (*(volatile unsigned char  *)0xFFFFA0FC)
#define ICP1L_2            (*(volatile unsigned char  *)0xFFFFA0FC)
#define ICCSIH2IREH        (*(volatile unsigned char  *)0xFFFFA0FD)
#define ICP1H_2            (*(volatile unsigned char  *)0xFFFFA0FD)
#define P0CSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FC)->bit00)
#define P0P1_2             (((volatile __bitf_T *)0xFFFFA0FC)->bit00)
#define P1CSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FC)->bit01)
#define P1P1_2             (((volatile __bitf_T *)0xFFFFA0FC)->bit01)
#define P2CSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FC)->bit02)
#define P2P1_2             (((volatile __bitf_T *)0xFFFFA0FC)->bit02)
#define TBCSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FC)->bit06)
#define TBP1_2             (((volatile __bitf_T *)0xFFFFA0FC)->bit06)
#define MKCSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FC)->bit07)
#define MKP1_2             (((volatile __bitf_T *)0xFFFFA0FC)->bit07)
#define RFCSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FD)->bit04)
#define RFP1_2             (((volatile __bitf_T *)0xFFFFA0FD)->bit04)
#define CTCSIH2IRE         (((volatile __bitf_T *)0xFFFFA0FD)->bit07)
#define CTP1_2             (((volatile __bitf_T *)0xFFFFA0FD)->bit07)
#define ICCSIH2IJC         (*(volatile unsigned short *)0xFFFFA0FE)
#define ICP2_2             (*(volatile unsigned short *)0xFFFFA0FE)
#define ICCSIH2IJCL        (*(volatile unsigned char  *)0xFFFFA0FE)
#define ICP2L_2            (*(volatile unsigned char  *)0xFFFFA0FE)
#define ICCSIH2IJCH        (*(volatile unsigned char  *)0xFFFFA0FF)
#define ICP2H_2            (*(volatile unsigned char  *)0xFFFFA0FF)
#define P0CSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FE)->bit00)
#define P0P2_2             (((volatile __bitf_T *)0xFFFFA0FE)->bit00)
#define P1CSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FE)->bit01)
#define P1P2_2             (((volatile __bitf_T *)0xFFFFA0FE)->bit01)
#define P2CSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FE)->bit02)
#define P2P2_2             (((volatile __bitf_T *)0xFFFFA0FE)->bit02)
#define TBCSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FE)->bit06)
#define TBP2_2             (((volatile __bitf_T *)0xFFFFA0FE)->bit06)
#define MKCSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FE)->bit07)
#define MKP2_2             (((volatile __bitf_T *)0xFFFFA0FE)->bit07)
#define RFCSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FF)->bit04)
#define RFP2_2             (((volatile __bitf_T *)0xFFFFA0FF)->bit04)
#define CTCSIH2IJC         (((volatile __bitf_T *)0xFFFFA0FF)->bit07)
#define CTP2_2             (((volatile __bitf_T *)0xFFFFA0FF)->bit07)
#define ICTAUB0I0          (*(volatile unsigned short *)0xFFFFA10C)
#define ICTAUB0I0L         (*(volatile unsigned char  *)0xFFFFA10C)
#define ICTAUB0I0H         (*(volatile unsigned char  *)0xFFFFA10D)
#define P0TAUB0I0          (((volatile __bitf_T *)0xFFFFA10C)->bit00)
#define P1TAUB0I0          (((volatile __bitf_T *)0xFFFFA10C)->bit01)
#define P2TAUB0I0          (((volatile __bitf_T *)0xFFFFA10C)->bit02)
#define TBTAUB0I0          (((volatile __bitf_T *)0xFFFFA10C)->bit06)
#define MKTAUB0I0          (((volatile __bitf_T *)0xFFFFA10C)->bit07)
#define RFTAUB0I0          (((volatile __bitf_T *)0xFFFFA10D)->bit04)
#define CTTAUB0I0          (((volatile __bitf_T *)0xFFFFA10D)->bit07)
#define ICTAUB0I1          (*(volatile unsigned short *)0xFFFFA10E)
#define ICTAUB0I1L         (*(volatile unsigned char  *)0xFFFFA10E)
#define ICTAUB0I1H         (*(volatile unsigned char  *)0xFFFFA10F)
#define P0TAUB0I1          (((volatile __bitf_T *)0xFFFFA10E)->bit00)
#define P1TAUB0I1          (((volatile __bitf_T *)0xFFFFA10E)->bit01)
#define P2TAUB0I1          (((volatile __bitf_T *)0xFFFFA10E)->bit02)
#define TBTAUB0I1          (((volatile __bitf_T *)0xFFFFA10E)->bit06)
#define MKTAUB0I1          (((volatile __bitf_T *)0xFFFFA10E)->bit07)
#define RFTAUB0I1          (((volatile __bitf_T *)0xFFFFA10F)->bit04)
#define CTTAUB0I1          (((volatile __bitf_T *)0xFFFFA10F)->bit07)
#define ICTAUB0I2          (*(volatile unsigned short *)0xFFFFA110)
#define ICTAUB0I2L         (*(volatile unsigned char  *)0xFFFFA110)
#define ICTAUB0I2H         (*(volatile unsigned char  *)0xFFFFA111)
#define P0TAUB0I2          (((volatile __bitf_T *)0xFFFFA110)->bit00)
#define P1TAUB0I2          (((volatile __bitf_T *)0xFFFFA110)->bit01)
#define P2TAUB0I2          (((volatile __bitf_T *)0xFFFFA110)->bit02)
#define TBTAUB0I2          (((volatile __bitf_T *)0xFFFFA110)->bit06)
#define MKTAUB0I2          (((volatile __bitf_T *)0xFFFFA110)->bit07)
#define RFTAUB0I2          (((volatile __bitf_T *)0xFFFFA111)->bit04)
#define CTTAUB0I2          (((volatile __bitf_T *)0xFFFFA111)->bit07)
#define ICPWGA16           (*(volatile unsigned short *)0xFFFFA112)
#define ICTAUB0I3          (*(volatile unsigned short *)0xFFFFA112)
#define ICPWGA16L          (*(volatile unsigned char  *)0xFFFFA112)
#define ICTAUB0I3L         (*(volatile unsigned char  *)0xFFFFA112)
#define ICPWGA16H          (*(volatile unsigned char  *)0xFFFFA113)
#define ICTAUB0I3H         (*(volatile unsigned char  *)0xFFFFA113)
#define P0PWGA16           (((volatile __bitf_T *)0xFFFFA112)->bit00)
#define P0TAUB0I3          (((volatile __bitf_T *)0xFFFFA112)->bit00)
#define P1PWGA16           (((volatile __bitf_T *)0xFFFFA112)->bit01)
#define P1TAUB0I3          (((volatile __bitf_T *)0xFFFFA112)->bit01)
#define P2PWGA16           (((volatile __bitf_T *)0xFFFFA112)->bit02)
#define P2TAUB0I3          (((volatile __bitf_T *)0xFFFFA112)->bit02)
#define TBPWGA16           (((volatile __bitf_T *)0xFFFFA112)->bit06)
#define TBTAUB0I3          (((volatile __bitf_T *)0xFFFFA112)->bit06)
#define MKPWGA16           (((volatile __bitf_T *)0xFFFFA112)->bit07)
#define MKTAUB0I3          (((volatile __bitf_T *)0xFFFFA112)->bit07)
#define RFPWGA16           (((volatile __bitf_T *)0xFFFFA113)->bit04)
#define RFTAUB0I3          (((volatile __bitf_T *)0xFFFFA113)->bit04)
#define CTPWGA16           (((volatile __bitf_T *)0xFFFFA113)->bit07)
#define CTTAUB0I3          (((volatile __bitf_T *)0xFFFFA113)->bit07)
#define ICTAUB0I4          (*(volatile unsigned short *)0xFFFFA114)
#define ICTAUB0I4L         (*(volatile unsigned char  *)0xFFFFA114)
#define ICTAUB0I4H         (*(volatile unsigned char  *)0xFFFFA115)
#define P0TAUB0I4          (((volatile __bitf_T *)0xFFFFA114)->bit00)
#define P1TAUB0I4          (((volatile __bitf_T *)0xFFFFA114)->bit01)
#define P2TAUB0I4          (((volatile __bitf_T *)0xFFFFA114)->bit02)
#define TBTAUB0I4          (((volatile __bitf_T *)0xFFFFA114)->bit06)
#define MKTAUB0I4          (((volatile __bitf_T *)0xFFFFA114)->bit07)
#define RFTAUB0I4          (((volatile __bitf_T *)0xFFFFA115)->bit04)
#define CTTAUB0I4          (((volatile __bitf_T *)0xFFFFA115)->bit07)
#define ICPWGA17           (*(volatile unsigned short *)0xFFFFA116)
#define ICTAUB0I5          (*(volatile unsigned short *)0xFFFFA116)
#define ICPWGA17L          (*(volatile unsigned char  *)0xFFFFA116)
#define ICTAUB0I5L         (*(volatile unsigned char  *)0xFFFFA116)
#define ICPWGA17H          (*(volatile unsigned char  *)0xFFFFA117)
#define ICTAUB0I5H         (*(volatile unsigned char  *)0xFFFFA117)
#define P0PWGA17           (((volatile __bitf_T *)0xFFFFA116)->bit00)
#define P0TAUB0I5          (((volatile __bitf_T *)0xFFFFA116)->bit00)
#define P1PWGA17           (((volatile __bitf_T *)0xFFFFA116)->bit01)
#define P1TAUB0I5          (((volatile __bitf_T *)0xFFFFA116)->bit01)
#define P2PWGA17           (((volatile __bitf_T *)0xFFFFA116)->bit02)
#define P2TAUB0I5          (((volatile __bitf_T *)0xFFFFA116)->bit02)
#define TBPWGA17           (((volatile __bitf_T *)0xFFFFA116)->bit06)
#define TBTAUB0I5          (((volatile __bitf_T *)0xFFFFA116)->bit06)
#define MKPWGA17           (((volatile __bitf_T *)0xFFFFA116)->bit07)
#define MKTAUB0I5          (((volatile __bitf_T *)0xFFFFA116)->bit07)
#define RFPWGA17           (((volatile __bitf_T *)0xFFFFA117)->bit04)
#define RFTAUB0I5          (((volatile __bitf_T *)0xFFFFA117)->bit04)
#define CTPWGA17           (((volatile __bitf_T *)0xFFFFA117)->bit07)
#define CTTAUB0I5          (((volatile __bitf_T *)0xFFFFA117)->bit07)
#define ICTAUB0I6          (*(volatile unsigned short *)0xFFFFA118)
#define ICTAUB0I6L         (*(volatile unsigned char  *)0xFFFFA118)
#define ICTAUB0I6H         (*(volatile unsigned char  *)0xFFFFA119)
#define P0TAUB0I6          (((volatile __bitf_T *)0xFFFFA118)->bit00)
#define P1TAUB0I6          (((volatile __bitf_T *)0xFFFFA118)->bit01)
#define P2TAUB0I6          (((volatile __bitf_T *)0xFFFFA118)->bit02)
#define TBTAUB0I6          (((volatile __bitf_T *)0xFFFFA118)->bit06)
#define MKTAUB0I6          (((volatile __bitf_T *)0xFFFFA118)->bit07)
#define RFTAUB0I6          (((volatile __bitf_T *)0xFFFFA119)->bit04)
#define CTTAUB0I6          (((volatile __bitf_T *)0xFFFFA119)->bit07)
#define ICPWGA18           (*(volatile unsigned short *)0xFFFFA11A)
#define ICTAUB0I7          (*(volatile unsigned short *)0xFFFFA11A)
#define ICPWGA18L          (*(volatile unsigned char  *)0xFFFFA11A)
#define ICTAUB0I7L         (*(volatile unsigned char  *)0xFFFFA11A)
#define ICPWGA18H          (*(volatile unsigned char  *)0xFFFFA11B)
#define ICTAUB0I7H         (*(volatile unsigned char  *)0xFFFFA11B)
#define P0PWGA18           (((volatile __bitf_T *)0xFFFFA11A)->bit00)
#define P0TAUB0I7          (((volatile __bitf_T *)0xFFFFA11A)->bit00)
#define P1PWGA18           (((volatile __bitf_T *)0xFFFFA11A)->bit01)
#define P1TAUB0I7          (((volatile __bitf_T *)0xFFFFA11A)->bit01)
#define P2PWGA18           (((volatile __bitf_T *)0xFFFFA11A)->bit02)
#define P2TAUB0I7          (((volatile __bitf_T *)0xFFFFA11A)->bit02)
#define TBPWGA18           (((volatile __bitf_T *)0xFFFFA11A)->bit06)
#define TBTAUB0I7          (((volatile __bitf_T *)0xFFFFA11A)->bit06)
#define MKPWGA18           (((volatile __bitf_T *)0xFFFFA11A)->bit07)
#define MKTAUB0I7          (((volatile __bitf_T *)0xFFFFA11A)->bit07)
#define RFPWGA18           (((volatile __bitf_T *)0xFFFFA11B)->bit04)
#define RFTAUB0I7          (((volatile __bitf_T *)0xFFFFA11B)->bit04)
#define CTPWGA18           (((volatile __bitf_T *)0xFFFFA11B)->bit07)
#define CTTAUB0I7          (((volatile __bitf_T *)0xFFFFA11B)->bit07)
#define ICTAUB0I8          (*(volatile unsigned short *)0xFFFFA11C)
#define ICTAUB0I8L         (*(volatile unsigned char  *)0xFFFFA11C)
#define ICTAUB0I8H         (*(volatile unsigned char  *)0xFFFFA11D)
#define P0TAUB0I8          (((volatile __bitf_T *)0xFFFFA11C)->bit00)
#define P1TAUB0I8          (((volatile __bitf_T *)0xFFFFA11C)->bit01)
#define P2TAUB0I8          (((volatile __bitf_T *)0xFFFFA11C)->bit02)
#define TBTAUB0I8          (((volatile __bitf_T *)0xFFFFA11C)->bit06)
#define MKTAUB0I8          (((volatile __bitf_T *)0xFFFFA11C)->bit07)
#define RFTAUB0I8          (((volatile __bitf_T *)0xFFFFA11D)->bit04)
#define CTTAUB0I8          (((volatile __bitf_T *)0xFFFFA11D)->bit07)
#define ICPWGA19           (*(volatile unsigned short *)0xFFFFA11E)
#define ICTAUB0I9          (*(volatile unsigned short *)0xFFFFA11E)
#define ICPWGA19L          (*(volatile unsigned char  *)0xFFFFA11E)
#define ICTAUB0I9L         (*(volatile unsigned char  *)0xFFFFA11E)
#define ICPWGA19H          (*(volatile unsigned char  *)0xFFFFA11F)
#define ICTAUB0I9H         (*(volatile unsigned char  *)0xFFFFA11F)
#define P0PWGA19           (((volatile __bitf_T *)0xFFFFA11E)->bit00)
#define P0TAUB0I9          (((volatile __bitf_T *)0xFFFFA11E)->bit00)
#define P1PWGA19           (((volatile __bitf_T *)0xFFFFA11E)->bit01)
#define P1TAUB0I9          (((volatile __bitf_T *)0xFFFFA11E)->bit01)
#define P2PWGA19           (((volatile __bitf_T *)0xFFFFA11E)->bit02)
#define P2TAUB0I9          (((volatile __bitf_T *)0xFFFFA11E)->bit02)
#define TBPWGA19           (((volatile __bitf_T *)0xFFFFA11E)->bit06)
#define TBTAUB0I9          (((volatile __bitf_T *)0xFFFFA11E)->bit06)
#define MKPWGA19           (((volatile __bitf_T *)0xFFFFA11E)->bit07)
#define MKTAUB0I9          (((volatile __bitf_T *)0xFFFFA11E)->bit07)
#define RFPWGA19           (((volatile __bitf_T *)0xFFFFA11F)->bit04)
#define RFTAUB0I9          (((volatile __bitf_T *)0xFFFFA11F)->bit04)
#define CTPWGA19           (((volatile __bitf_T *)0xFFFFA11F)->bit07)
#define CTTAUB0I9          (((volatile __bitf_T *)0xFFFFA11F)->bit07)
#define ICTAUB0I10         (*(volatile unsigned short *)0xFFFFA120)
#define ICTAUB0I10L        (*(volatile unsigned char  *)0xFFFFA120)
#define ICTAUB0I10H        (*(volatile unsigned char  *)0xFFFFA121)
#define P0TAUB0I10         (((volatile __bitf_T *)0xFFFFA120)->bit00)
#define P1TAUB0I10         (((volatile __bitf_T *)0xFFFFA120)->bit01)
#define P2TAUB0I10         (((volatile __bitf_T *)0xFFFFA120)->bit02)
#define TBTAUB0I10         (((volatile __bitf_T *)0xFFFFA120)->bit06)
#define MKTAUB0I10         (((volatile __bitf_T *)0xFFFFA120)->bit07)
#define RFTAUB0I10         (((volatile __bitf_T *)0xFFFFA121)->bit04)
#define CTTAUB0I10         (((volatile __bitf_T *)0xFFFFA121)->bit07)
#define ICPWGA26           (*(volatile unsigned short *)0xFFFFA122)
#define ICTAUB0I11         (*(volatile unsigned short *)0xFFFFA122)
#define ICPWGA26L          (*(volatile unsigned char  *)0xFFFFA122)
#define ICTAUB0I11L        (*(volatile unsigned char  *)0xFFFFA122)
#define ICPWGA26H          (*(volatile unsigned char  *)0xFFFFA123)
#define ICTAUB0I11H        (*(volatile unsigned char  *)0xFFFFA123)
#define P0PWGA26           (((volatile __bitf_T *)0xFFFFA122)->bit00)
#define P0TAUB0I11         (((volatile __bitf_T *)0xFFFFA122)->bit00)
#define P1PWGA26           (((volatile __bitf_T *)0xFFFFA122)->bit01)
#define P1TAUB0I11         (((volatile __bitf_T *)0xFFFFA122)->bit01)
#define P2PWGA26           (((volatile __bitf_T *)0xFFFFA122)->bit02)
#define P2TAUB0I11         (((volatile __bitf_T *)0xFFFFA122)->bit02)
#define TBPWGA26           (((volatile __bitf_T *)0xFFFFA122)->bit06)
#define TBTAUB0I11         (((volatile __bitf_T *)0xFFFFA122)->bit06)
#define MKPWGA26           (((volatile __bitf_T *)0xFFFFA122)->bit07)
#define MKTAUB0I11         (((volatile __bitf_T *)0xFFFFA122)->bit07)
#define RFPWGA26           (((volatile __bitf_T *)0xFFFFA123)->bit04)
#define RFTAUB0I11         (((volatile __bitf_T *)0xFFFFA123)->bit04)
#define CTPWGA26           (((volatile __bitf_T *)0xFFFFA123)->bit07)
#define CTTAUB0I11         (((volatile __bitf_T *)0xFFFFA123)->bit07)
#define ICTAUB0I12         (*(volatile unsigned short *)0xFFFFA124)
#define ICTAUB0I12L        (*(volatile unsigned char  *)0xFFFFA124)
#define ICTAUB0I12H        (*(volatile unsigned char  *)0xFFFFA125)
#define P0TAUB0I12         (((volatile __bitf_T *)0xFFFFA124)->bit00)
#define P1TAUB0I12         (((volatile __bitf_T *)0xFFFFA124)->bit01)
#define P2TAUB0I12         (((volatile __bitf_T *)0xFFFFA124)->bit02)
#define TBTAUB0I12         (((volatile __bitf_T *)0xFFFFA124)->bit06)
#define MKTAUB0I12         (((volatile __bitf_T *)0xFFFFA124)->bit07)
#define RFTAUB0I12         (((volatile __bitf_T *)0xFFFFA125)->bit04)
#define CTTAUB0I12         (((volatile __bitf_T *)0xFFFFA125)->bit07)
#define ICPWGA30           (*(volatile unsigned short *)0xFFFFA126)
#define ICTAUB0I13         (*(volatile unsigned short *)0xFFFFA126)
#define ICPWGA30L          (*(volatile unsigned char  *)0xFFFFA126)
#define ICTAUB0I13L        (*(volatile unsigned char  *)0xFFFFA126)
#define ICPWGA30H          (*(volatile unsigned char  *)0xFFFFA127)
#define ICTAUB0I13H        (*(volatile unsigned char  *)0xFFFFA127)
#define P0PWGA30           (((volatile __bitf_T *)0xFFFFA126)->bit00)
#define P0TAUB0I13         (((volatile __bitf_T *)0xFFFFA126)->bit00)
#define P1PWGA30           (((volatile __bitf_T *)0xFFFFA126)->bit01)
#define P1TAUB0I13         (((volatile __bitf_T *)0xFFFFA126)->bit01)
#define P2PWGA30           (((volatile __bitf_T *)0xFFFFA126)->bit02)
#define P2TAUB0I13         (((volatile __bitf_T *)0xFFFFA126)->bit02)
#define TBPWGA30           (((volatile __bitf_T *)0xFFFFA126)->bit06)
#define TBTAUB0I13         (((volatile __bitf_T *)0xFFFFA126)->bit06)
#define MKPWGA30           (((volatile __bitf_T *)0xFFFFA126)->bit07)
#define MKTAUB0I13         (((volatile __bitf_T *)0xFFFFA126)->bit07)
#define RFPWGA30           (((volatile __bitf_T *)0xFFFFA127)->bit04)
#define RFTAUB0I13         (((volatile __bitf_T *)0xFFFFA127)->bit04)
#define CTPWGA30           (((volatile __bitf_T *)0xFFFFA127)->bit07)
#define CTTAUB0I13         (((volatile __bitf_T *)0xFFFFA127)->bit07)
#define ICTAUB0I14         (*(volatile unsigned short *)0xFFFFA128)
#define ICTAUB0I14L        (*(volatile unsigned char  *)0xFFFFA128)
#define ICTAUB0I14H        (*(volatile unsigned char  *)0xFFFFA129)
#define P0TAUB0I14         (((volatile __bitf_T *)0xFFFFA128)->bit00)
#define P1TAUB0I14         (((volatile __bitf_T *)0xFFFFA128)->bit01)
#define P2TAUB0I14         (((volatile __bitf_T *)0xFFFFA128)->bit02)
#define TBTAUB0I14         (((volatile __bitf_T *)0xFFFFA128)->bit06)
#define MKTAUB0I14         (((volatile __bitf_T *)0xFFFFA128)->bit07)
#define RFTAUB0I14         (((volatile __bitf_T *)0xFFFFA129)->bit04)
#define CTTAUB0I14         (((volatile __bitf_T *)0xFFFFA129)->bit07)
#define ICPWGA31           (*(volatile unsigned short *)0xFFFFA12A)
#define ICTAUB0I15         (*(volatile unsigned short *)0xFFFFA12A)
#define ICPWGA31L          (*(volatile unsigned char  *)0xFFFFA12A)
#define ICTAUB0I15L        (*(volatile unsigned char  *)0xFFFFA12A)
#define ICPWGA31H          (*(volatile unsigned char  *)0xFFFFA12B)
#define ICTAUB0I15H        (*(volatile unsigned char  *)0xFFFFA12B)
#define P0PWGA31           (((volatile __bitf_T *)0xFFFFA12A)->bit00)
#define P0TAUB0I15         (((volatile __bitf_T *)0xFFFFA12A)->bit00)
#define P1PWGA31           (((volatile __bitf_T *)0xFFFFA12A)->bit01)
#define P1TAUB0I15         (((volatile __bitf_T *)0xFFFFA12A)->bit01)
#define P2PWGA31           (((volatile __bitf_T *)0xFFFFA12A)->bit02)
#define P2TAUB0I15         (((volatile __bitf_T *)0xFFFFA12A)->bit02)
#define TBPWGA31           (((volatile __bitf_T *)0xFFFFA12A)->bit06)
#define TBTAUB0I15         (((volatile __bitf_T *)0xFFFFA12A)->bit06)
#define MKPWGA31           (((volatile __bitf_T *)0xFFFFA12A)->bit07)
#define MKTAUB0I15         (((volatile __bitf_T *)0xFFFFA12A)->bit07)
#define RFPWGA31           (((volatile __bitf_T *)0xFFFFA12B)->bit04)
#define RFTAUB0I15         (((volatile __bitf_T *)0xFFFFA12B)->bit04)
#define CTPWGA31           (((volatile __bitf_T *)0xFFFFA12B)->bit07)
#define CTTAUB0I15         (((volatile __bitf_T *)0xFFFFA12B)->bit07)
#define ICCSIH3IC          (*(volatile unsigned short *)0xFFFFA12C)
#define ICTAUD0I2_2        (*(volatile unsigned short *)0xFFFFA12C)
#define ICCSIH3ICL         (*(volatile unsigned char  *)0xFFFFA12C)
#define ICTAUD0I2L_2       (*(volatile unsigned char  *)0xFFFFA12C)
#define ICCSIH3ICH         (*(volatile unsigned char  *)0xFFFFA12D)
#define ICTAUD0I2H_2       (*(volatile unsigned char  *)0xFFFFA12D)
#define P0CSIH3IC          (((volatile __bitf_T *)0xFFFFA12C)->bit00)
#define P0TAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12C)->bit00)
#define P1CSIH3IC          (((volatile __bitf_T *)0xFFFFA12C)->bit01)
#define P1TAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12C)->bit01)
#define P2CSIH3IC          (((volatile __bitf_T *)0xFFFFA12C)->bit02)
#define P2TAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12C)->bit02)
#define TBCSIH3IC          (((volatile __bitf_T *)0xFFFFA12C)->bit06)
#define TBTAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12C)->bit06)
#define MKCSIH3IC          (((volatile __bitf_T *)0xFFFFA12C)->bit07)
#define MKTAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12C)->bit07)
#define RFCSIH3IC          (((volatile __bitf_T *)0xFFFFA12D)->bit04)
#define RFTAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12D)->bit04)
#define CTCSIH3IC          (((volatile __bitf_T *)0xFFFFA12D)->bit07)
#define CTTAUD0I2_2        (((volatile __bitf_T *)0xFFFFA12D)->bit07)
#define ICCSIH3IR          (*(volatile unsigned short *)0xFFFFA12E)
#define ICTAUD0I10_2       (*(volatile unsigned short *)0xFFFFA12E)
#define ICCSIH3IRL         (*(volatile unsigned char  *)0xFFFFA12E)
#define ICTAUD0I10L_2      (*(volatile unsigned char  *)0xFFFFA12E)
#define ICCSIH3IRH         (*(volatile unsigned char  *)0xFFFFA12F)
#define ICTAUD0I10H_2      (*(volatile unsigned char  *)0xFFFFA12F)
#define P0CSIH3IR          (((volatile __bitf_T *)0xFFFFA12E)->bit00)
#define P0TAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12E)->bit00)
#define P1CSIH3IR          (((volatile __bitf_T *)0xFFFFA12E)->bit01)
#define P1TAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12E)->bit01)
#define P2CSIH3IR          (((volatile __bitf_T *)0xFFFFA12E)->bit02)
#define P2TAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12E)->bit02)
#define TBCSIH3IR          (((volatile __bitf_T *)0xFFFFA12E)->bit06)
#define TBTAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12E)->bit06)
#define MKCSIH3IR          (((volatile __bitf_T *)0xFFFFA12E)->bit07)
#define MKTAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12E)->bit07)
#define RFCSIH3IR          (((volatile __bitf_T *)0xFFFFA12F)->bit04)
#define RFTAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12F)->bit04)
#define CTCSIH3IR          (((volatile __bitf_T *)0xFFFFA12F)->bit07)
#define CTTAUD0I10_2       (((volatile __bitf_T *)0xFFFFA12F)->bit07)
#define ICCSIH3IRE         (*(volatile unsigned short *)0xFFFFA130)
#define ICTAUD0I12_2       (*(volatile unsigned short *)0xFFFFA130)
#define ICCSIH3IREL        (*(volatile unsigned char  *)0xFFFFA130)
#define ICTAUD0I12L_2      (*(volatile unsigned char  *)0xFFFFA130)
#define ICCSIH3IREH        (*(volatile unsigned char  *)0xFFFFA131)
#define ICTAUD0I12H_2      (*(volatile unsigned char  *)0xFFFFA131)
#define P0CSIH3IRE         (((volatile __bitf_T *)0xFFFFA130)->bit00)
#define P0TAUD0I12_2       (((volatile __bitf_T *)0xFFFFA130)->bit00)
#define P1CSIH3IRE         (((volatile __bitf_T *)0xFFFFA130)->bit01)
#define P1TAUD0I12_2       (((volatile __bitf_T *)0xFFFFA130)->bit01)
#define P2CSIH3IRE         (((volatile __bitf_T *)0xFFFFA130)->bit02)
#define P2TAUD0I12_2       (((volatile __bitf_T *)0xFFFFA130)->bit02)
#define TBCSIH3IRE         (((volatile __bitf_T *)0xFFFFA130)->bit06)
#define TBTAUD0I12_2       (((volatile __bitf_T *)0xFFFFA130)->bit06)
#define MKCSIH3IRE         (((volatile __bitf_T *)0xFFFFA130)->bit07)
#define MKTAUD0I12_2       (((volatile __bitf_T *)0xFFFFA130)->bit07)
#define RFCSIH3IRE         (((volatile __bitf_T *)0xFFFFA131)->bit04)
#define RFTAUD0I12_2       (((volatile __bitf_T *)0xFFFFA131)->bit04)
#define CTCSIH3IRE         (((volatile __bitf_T *)0xFFFFA131)->bit07)
#define CTTAUD0I12_2       (((volatile __bitf_T *)0xFFFFA131)->bit07)
#define ICCSIH3IJC         (*(volatile unsigned short *)0xFFFFA132)
#define ICTAUD0I14_2       (*(volatile unsigned short *)0xFFFFA132)
#define ICCSIH3IJCL        (*(volatile unsigned char  *)0xFFFFA132)
#define ICTAUD0I14L_2      (*(volatile unsigned char  *)0xFFFFA132)
#define ICCSIH3IJCH        (*(volatile unsigned char  *)0xFFFFA133)
#define ICTAUD0I14H_2      (*(volatile unsigned char  *)0xFFFFA133)
#define P0CSIH3IJC         (((volatile __bitf_T *)0xFFFFA132)->bit00)
#define P0TAUD0I14_2       (((volatile __bitf_T *)0xFFFFA132)->bit00)
#define P1CSIH3IJC         (((volatile __bitf_T *)0xFFFFA132)->bit01)
#define P1TAUD0I14_2       (((volatile __bitf_T *)0xFFFFA132)->bit01)
#define P2CSIH3IJC         (((volatile __bitf_T *)0xFFFFA132)->bit02)
#define P2TAUD0I14_2       (((volatile __bitf_T *)0xFFFFA132)->bit02)
#define TBCSIH3IJC         (((volatile __bitf_T *)0xFFFFA132)->bit06)
#define TBTAUD0I14_2       (((volatile __bitf_T *)0xFFFFA132)->bit06)
#define MKCSIH3IJC         (((volatile __bitf_T *)0xFFFFA132)->bit07)
#define MKTAUD0I14_2       (((volatile __bitf_T *)0xFFFFA132)->bit07)
#define RFCSIH3IJC         (((volatile __bitf_T *)0xFFFFA133)->bit04)
#define RFTAUD0I14_2       (((volatile __bitf_T *)0xFFFFA133)->bit04)
#define CTCSIH3IJC         (((volatile __bitf_T *)0xFFFFA133)->bit07)
#define CTTAUD0I14_2       (((volatile __bitf_T *)0xFFFFA133)->bit07)
#define ICRLIN22           (*(volatile unsigned short *)0xFFFFA134)
#define ICRLIN22L          (*(volatile unsigned char  *)0xFFFFA134)
#define ICRLIN22H          (*(volatile unsigned char  *)0xFFFFA135)
#define P0RLIN22           (((volatile __bitf_T *)0xFFFFA134)->bit00)
#define P1RLIN22           (((volatile __bitf_T *)0xFFFFA134)->bit01)
#define P2RLIN22           (((volatile __bitf_T *)0xFFFFA134)->bit02)
#define TBRLIN22           (((volatile __bitf_T *)0xFFFFA134)->bit06)
#define MKRLIN22           (((volatile __bitf_T *)0xFFFFA134)->bit07)
#define RFRLIN22           (((volatile __bitf_T *)0xFFFFA135)->bit04)
#define CTRLIN22           (((volatile __bitf_T *)0xFFFFA135)->bit07)
#define ICRLIN23           (*(volatile unsigned short *)0xFFFFA136)
#define ICRLIN23L          (*(volatile unsigned char  *)0xFFFFA136)
#define ICRLIN23H          (*(volatile unsigned char  *)0xFFFFA137)
#define P0RLIN23           (((volatile __bitf_T *)0xFFFFA136)->bit00)
#define P1RLIN23           (((volatile __bitf_T *)0xFFFFA136)->bit01)
#define P2RLIN23           (((volatile __bitf_T *)0xFFFFA136)->bit02)
#define TBRLIN23           (((volatile __bitf_T *)0xFFFFA136)->bit06)
#define MKRLIN23           (((volatile __bitf_T *)0xFFFFA136)->bit07)
#define RFRLIN23           (((volatile __bitf_T *)0xFFFFA137)->bit04)
#define CTRLIN23           (((volatile __bitf_T *)0xFFFFA137)->bit07)
#define ICRLIN32           (*(volatile unsigned short *)0xFFFFA138)
#define ICRLIN32L          (*(volatile unsigned char  *)0xFFFFA138)
#define ICRLIN32H          (*(volatile unsigned char  *)0xFFFFA139)
#define P0RLIN32           (((volatile __bitf_T *)0xFFFFA138)->bit00)
#define P1RLIN32           (((volatile __bitf_T *)0xFFFFA138)->bit01)
#define P2RLIN32           (((volatile __bitf_T *)0xFFFFA138)->bit02)
#define TBRLIN32           (((volatile __bitf_T *)0xFFFFA138)->bit06)
#define MKRLIN32           (((volatile __bitf_T *)0xFFFFA138)->bit07)
#define RFRLIN32           (((volatile __bitf_T *)0xFFFFA139)->bit04)
#define CTRLIN32           (((volatile __bitf_T *)0xFFFFA139)->bit07)
#define ICRLIN32UR0        (*(volatile unsigned short *)0xFFFFA13A)
#define ICRLIN32UR0L       (*(volatile unsigned char  *)0xFFFFA13A)
#define ICRLIN32UR0H       (*(volatile unsigned char  *)0xFFFFA13B)
#define P0RLIN32UR0        (((volatile __bitf_T *)0xFFFFA13A)->bit00)
#define P1RLIN32UR0        (((volatile __bitf_T *)0xFFFFA13A)->bit01)
#define P2RLIN32UR0        (((volatile __bitf_T *)0xFFFFA13A)->bit02)
#define TBRLIN32UR0        (((volatile __bitf_T *)0xFFFFA13A)->bit06)
#define MKRLIN32UR0        (((volatile __bitf_T *)0xFFFFA13A)->bit07)
#define RFRLIN32UR0        (((volatile __bitf_T *)0xFFFFA13B)->bit04)
#define CTRLIN32UR0        (((volatile __bitf_T *)0xFFFFA13B)->bit07)
#define ICRLIN32UR1        (*(volatile unsigned short *)0xFFFFA13C)
#define ICRLIN32UR1L       (*(volatile unsigned char  *)0xFFFFA13C)
#define ICRLIN32UR1H       (*(volatile unsigned char  *)0xFFFFA13D)
#define P0RLIN32UR1        (((volatile __bitf_T *)0xFFFFA13C)->bit00)
#define P1RLIN32UR1        (((volatile __bitf_T *)0xFFFFA13C)->bit01)
#define P2RLIN32UR1        (((volatile __bitf_T *)0xFFFFA13C)->bit02)
#define TBRLIN32UR1        (((volatile __bitf_T *)0xFFFFA13C)->bit06)
#define MKRLIN32UR1        (((volatile __bitf_T *)0xFFFFA13C)->bit07)
#define RFRLIN32UR1        (((volatile __bitf_T *)0xFFFFA13D)->bit04)
#define CTRLIN32UR1        (((volatile __bitf_T *)0xFFFFA13D)->bit07)
#define ICRLIN32UR2        (*(volatile unsigned short *)0xFFFFA13E)
#define ICRLIN32UR2L       (*(volatile unsigned char  *)0xFFFFA13E)
#define ICRLIN32UR2H       (*(volatile unsigned char  *)0xFFFFA13F)
#define P0RLIN32UR2        (((volatile __bitf_T *)0xFFFFA13E)->bit00)
#define P1RLIN32UR2        (((volatile __bitf_T *)0xFFFFA13E)->bit01)
#define P2RLIN32UR2        (((volatile __bitf_T *)0xFFFFA13E)->bit02)
#define TBRLIN32UR2        (((volatile __bitf_T *)0xFFFFA13E)->bit06)
#define MKRLIN32UR2        (((volatile __bitf_T *)0xFFFFA13E)->bit07)
#define RFRLIN32UR2        (((volatile __bitf_T *)0xFFFFA13F)->bit04)
#define CTRLIN32UR2        (((volatile __bitf_T *)0xFFFFA13F)->bit07)
#define ICTAUJ1I0          (*(volatile unsigned short *)0xFFFFA140)
#define ICTAUJ1I0L         (*(volatile unsigned char  *)0xFFFFA140)
#define ICTAUJ1I0H         (*(volatile unsigned char  *)0xFFFFA141)
#define P0TAUJ1I0          (((volatile __bitf_T *)0xFFFFA140)->bit00)
#define P1TAUJ1I0          (((volatile __bitf_T *)0xFFFFA140)->bit01)
#define P2TAUJ1I0          (((volatile __bitf_T *)0xFFFFA140)->bit02)
#define TBTAUJ1I0          (((volatile __bitf_T *)0xFFFFA140)->bit06)
#define MKTAUJ1I0          (((volatile __bitf_T *)0xFFFFA140)->bit07)
#define RFTAUJ1I0          (((volatile __bitf_T *)0xFFFFA141)->bit04)
#define CTTAUJ1I0          (((volatile __bitf_T *)0xFFFFA141)->bit07)
#define ICTAUJ1I1          (*(volatile unsigned short *)0xFFFFA142)
#define ICTAUJ1I1L         (*(volatile unsigned char  *)0xFFFFA142)
#define ICTAUJ1I1H         (*(volatile unsigned char  *)0xFFFFA143)
#define P0TAUJ1I1          (((volatile __bitf_T *)0xFFFFA142)->bit00)
#define P1TAUJ1I1          (((volatile __bitf_T *)0xFFFFA142)->bit01)
#define P2TAUJ1I1          (((volatile __bitf_T *)0xFFFFA142)->bit02)
#define TBTAUJ1I1          (((volatile __bitf_T *)0xFFFFA142)->bit06)
#define MKTAUJ1I1          (((volatile __bitf_T *)0xFFFFA142)->bit07)
#define RFTAUJ1I1          (((volatile __bitf_T *)0xFFFFA143)->bit04)
#define CTTAUJ1I1          (((volatile __bitf_T *)0xFFFFA143)->bit07)
#define ICTAUJ1I2          (*(volatile unsigned short *)0xFFFFA144)
#define ICTAUJ1I2L         (*(volatile unsigned char  *)0xFFFFA144)
#define ICTAUJ1I2H         (*(volatile unsigned char  *)0xFFFFA145)
#define P0TAUJ1I2          (((volatile __bitf_T *)0xFFFFA144)->bit00)
#define P1TAUJ1I2          (((volatile __bitf_T *)0xFFFFA144)->bit01)
#define P2TAUJ1I2          (((volatile __bitf_T *)0xFFFFA144)->bit02)
#define TBTAUJ1I2          (((volatile __bitf_T *)0xFFFFA144)->bit06)
#define MKTAUJ1I2          (((volatile __bitf_T *)0xFFFFA144)->bit07)
#define RFTAUJ1I2          (((volatile __bitf_T *)0xFFFFA145)->bit04)
#define CTTAUJ1I2          (((volatile __bitf_T *)0xFFFFA145)->bit07)
#define ICTAUJ1I3          (*(volatile unsigned short *)0xFFFFA146)
#define ICTAUJ1I3L         (*(volatile unsigned char  *)0xFFFFA146)
#define ICTAUJ1I3H         (*(volatile unsigned char  *)0xFFFFA147)
#define P0TAUJ1I3          (((volatile __bitf_T *)0xFFFFA146)->bit00)
#define P1TAUJ1I3          (((volatile __bitf_T *)0xFFFFA146)->bit01)
#define P2TAUJ1I3          (((volatile __bitf_T *)0xFFFFA146)->bit02)
#define TBTAUJ1I3          (((volatile __bitf_T *)0xFFFFA146)->bit06)
#define MKTAUJ1I3          (((volatile __bitf_T *)0xFFFFA146)->bit07)
#define RFTAUJ1I3          (((volatile __bitf_T *)0xFFFFA147)->bit04)
#define CTTAUJ1I3          (((volatile __bitf_T *)0xFFFFA147)->bit07)
#define ICPWGA24           (*(volatile unsigned short *)0xFFFFA160)
#define ICPWGA24L          (*(volatile unsigned char  *)0xFFFFA160)
#define ICPWGA24H          (*(volatile unsigned char  *)0xFFFFA161)
#define P0PWGA24           (((volatile __bitf_T *)0xFFFFA160)->bit00)
#define P1PWGA24           (((volatile __bitf_T *)0xFFFFA160)->bit01)
#define P2PWGA24           (((volatile __bitf_T *)0xFFFFA160)->bit02)
#define TBPWGA24           (((volatile __bitf_T *)0xFFFFA160)->bit06)
#define MKPWGA24           (((volatile __bitf_T *)0xFFFFA160)->bit07)
#define RFPWGA24           (((volatile __bitf_T *)0xFFFFA161)->bit04)
#define CTPWGA24           (((volatile __bitf_T *)0xFFFFA161)->bit07)
#define ICPWGA25           (*(volatile unsigned short *)0xFFFFA162)
#define ICPWGA25L          (*(volatile unsigned char  *)0xFFFFA162)
#define ICPWGA25H          (*(volatile unsigned char  *)0xFFFFA163)
#define P0PWGA25           (((volatile __bitf_T *)0xFFFFA162)->bit00)
#define P1PWGA25           (((volatile __bitf_T *)0xFFFFA162)->bit01)
#define P2PWGA25           (((volatile __bitf_T *)0xFFFFA162)->bit02)
#define TBPWGA25           (((volatile __bitf_T *)0xFFFFA162)->bit06)
#define MKPWGA25           (((volatile __bitf_T *)0xFFFFA162)->bit07)
#define RFPWGA25           (((volatile __bitf_T *)0xFFFFA163)->bit04)
#define CTPWGA25           (((volatile __bitf_T *)0xFFFFA163)->bit07)
#define ICPWGA27           (*(volatile unsigned short *)0xFFFFA164)
#define ICPWGA27L          (*(volatile unsigned char  *)0xFFFFA164)
#define ICPWGA27H          (*(volatile unsigned char  *)0xFFFFA165)
#define P0PWGA27           (((volatile __bitf_T *)0xFFFFA164)->bit00)
#define P1PWGA27           (((volatile __bitf_T *)0xFFFFA164)->bit01)
#define P2PWGA27           (((volatile __bitf_T *)0xFFFFA164)->bit02)
#define TBPWGA27           (((volatile __bitf_T *)0xFFFFA164)->bit06)
#define MKPWGA27           (((volatile __bitf_T *)0xFFFFA164)->bit07)
#define RFPWGA27           (((volatile __bitf_T *)0xFFFFA165)->bit04)
#define CTPWGA27           (((volatile __bitf_T *)0xFFFFA165)->bit07)
#define ICPWGA28           (*(volatile unsigned short *)0xFFFFA166)
#define ICPWGA28L          (*(volatile unsigned char  *)0xFFFFA166)
#define ICPWGA28H          (*(volatile unsigned char  *)0xFFFFA167)
#define P0PWGA28           (((volatile __bitf_T *)0xFFFFA166)->bit00)
#define P1PWGA28           (((volatile __bitf_T *)0xFFFFA166)->bit01)
#define P2PWGA28           (((volatile __bitf_T *)0xFFFFA166)->bit02)
#define TBPWGA28           (((volatile __bitf_T *)0xFFFFA166)->bit06)
#define MKPWGA28           (((volatile __bitf_T *)0xFFFFA166)->bit07)
#define RFPWGA28           (((volatile __bitf_T *)0xFFFFA167)->bit04)
#define CTPWGA28           (((volatile __bitf_T *)0xFFFFA167)->bit07)
#define ICPWGA29           (*(volatile unsigned short *)0xFFFFA168)
#define ICPWGA29L          (*(volatile unsigned char  *)0xFFFFA168)
#define ICPWGA29H          (*(volatile unsigned char  *)0xFFFFA169)
#define P0PWGA29           (((volatile __bitf_T *)0xFFFFA168)->bit00)
#define P1PWGA29           (((volatile __bitf_T *)0xFFFFA168)->bit01)
#define P2PWGA29           (((volatile __bitf_T *)0xFFFFA168)->bit02)
#define TBPWGA29           (((volatile __bitf_T *)0xFFFFA168)->bit06)
#define MKPWGA29           (((volatile __bitf_T *)0xFFFFA168)->bit07)
#define RFPWGA29           (((volatile __bitf_T *)0xFFFFA169)->bit04)
#define CTPWGA29           (((volatile __bitf_T *)0xFFFFA169)->bit07)
#define ICPWGA32           (*(volatile unsigned short *)0xFFFFA16A)
#define ICPWGA32L          (*(volatile unsigned char  *)0xFFFFA16A)
#define ICPWGA32H          (*(volatile unsigned char  *)0xFFFFA16B)
#define P0PWGA32           (((volatile __bitf_T *)0xFFFFA16A)->bit00)
#define P1PWGA32           (((volatile __bitf_T *)0xFFFFA16A)->bit01)
#define P2PWGA32           (((volatile __bitf_T *)0xFFFFA16A)->bit02)
#define TBPWGA32           (((volatile __bitf_T *)0xFFFFA16A)->bit06)
#define MKPWGA32           (((volatile __bitf_T *)0xFFFFA16A)->bit07)
#define RFPWGA32           (((volatile __bitf_T *)0xFFFFA16B)->bit04)
#define CTPWGA32           (((volatile __bitf_T *)0xFFFFA16B)->bit07)
#define ICPWGA33           (*(volatile unsigned short *)0xFFFFA16C)
#define ICPWGA33L          (*(volatile unsigned char  *)0xFFFFA16C)
#define ICPWGA33H          (*(volatile unsigned char  *)0xFFFFA16D)
#define P0PWGA33           (((volatile __bitf_T *)0xFFFFA16C)->bit00)
#define P1PWGA33           (((volatile __bitf_T *)0xFFFFA16C)->bit01)
#define P2PWGA33           (((volatile __bitf_T *)0xFFFFA16C)->bit02)
#define TBPWGA33           (((volatile __bitf_T *)0xFFFFA16C)->bit06)
#define MKPWGA33           (((volatile __bitf_T *)0xFFFFA16C)->bit07)
#define RFPWGA33           (((volatile __bitf_T *)0xFFFFA16D)->bit04)
#define CTPWGA33           (((volatile __bitf_T *)0xFFFFA16D)->bit07)
#define ICPWGA34           (*(volatile unsigned short *)0xFFFFA16E)
#define ICPWGA34L          (*(volatile unsigned char  *)0xFFFFA16E)
#define ICPWGA34H          (*(volatile unsigned char  *)0xFFFFA16F)
#define P0PWGA34           (((volatile __bitf_T *)0xFFFFA16E)->bit00)
#define P1PWGA34           (((volatile __bitf_T *)0xFFFFA16E)->bit01)
#define P2PWGA34           (((volatile __bitf_T *)0xFFFFA16E)->bit02)
#define TBPWGA34           (((volatile __bitf_T *)0xFFFFA16E)->bit06)
#define MKPWGA34           (((volatile __bitf_T *)0xFFFFA16E)->bit07)
#define RFPWGA34           (((volatile __bitf_T *)0xFFFFA16F)->bit04)
#define CTPWGA34           (((volatile __bitf_T *)0xFFFFA16F)->bit07)
#define ICPWGA35           (*(volatile unsigned short *)0xFFFFA170)
#define ICPWGA35L          (*(volatile unsigned char  *)0xFFFFA170)
#define ICPWGA35H          (*(volatile unsigned char  *)0xFFFFA171)
#define P0PWGA35           (((volatile __bitf_T *)0xFFFFA170)->bit00)
#define P1PWGA35           (((volatile __bitf_T *)0xFFFFA170)->bit01)
#define P2PWGA35           (((volatile __bitf_T *)0xFFFFA170)->bit02)
#define TBPWGA35           (((volatile __bitf_T *)0xFFFFA170)->bit06)
#define MKPWGA35           (((volatile __bitf_T *)0xFFFFA170)->bit07)
#define RFPWGA35           (((volatile __bitf_T *)0xFFFFA171)->bit04)
#define CTPWGA35           (((volatile __bitf_T *)0xFFFFA171)->bit07)
#define ICPWGA36           (*(volatile unsigned short *)0xFFFFA172)
#define ICPWGA36L          (*(volatile unsigned char  *)0xFFFFA172)
#define ICPWGA36H          (*(volatile unsigned char  *)0xFFFFA173)
#define P0PWGA36           (((volatile __bitf_T *)0xFFFFA172)->bit00)
#define P1PWGA36           (((volatile __bitf_T *)0xFFFFA172)->bit01)
#define P2PWGA36           (((volatile __bitf_T *)0xFFFFA172)->bit02)
#define TBPWGA36           (((volatile __bitf_T *)0xFFFFA172)->bit06)
#define MKPWGA36           (((volatile __bitf_T *)0xFFFFA172)->bit07)
#define RFPWGA36           (((volatile __bitf_T *)0xFFFFA173)->bit04)
#define CTPWGA36           (((volatile __bitf_T *)0xFFFFA173)->bit07)
#define ICPWGA37           (*(volatile unsigned short *)0xFFFFA174)
#define ICPWGA37L          (*(volatile unsigned char  *)0xFFFFA174)
#define ICPWGA37H          (*(volatile unsigned char  *)0xFFFFA175)
#define P0PWGA37           (((volatile __bitf_T *)0xFFFFA174)->bit00)
#define P1PWGA37           (((volatile __bitf_T *)0xFFFFA174)->bit01)
#define P2PWGA37           (((volatile __bitf_T *)0xFFFFA174)->bit02)
#define TBPWGA37           (((volatile __bitf_T *)0xFFFFA174)->bit06)
#define MKPWGA37           (((volatile __bitf_T *)0xFFFFA174)->bit07)
#define RFPWGA37           (((volatile __bitf_T *)0xFFFFA175)->bit04)
#define CTPWGA37           (((volatile __bitf_T *)0xFFFFA175)->bit07)
#define ICPWGA38           (*(volatile unsigned short *)0xFFFFA176)
#define ICPWGA38L          (*(volatile unsigned char  *)0xFFFFA176)
#define ICPWGA38H          (*(volatile unsigned char  *)0xFFFFA177)
#define P0PWGA38           (((volatile __bitf_T *)0xFFFFA176)->bit00)
#define P1PWGA38           (((volatile __bitf_T *)0xFFFFA176)->bit01)
#define P2PWGA38           (((volatile __bitf_T *)0xFFFFA176)->bit02)
#define TBPWGA38           (((volatile __bitf_T *)0xFFFFA176)->bit06)
#define MKPWGA38           (((volatile __bitf_T *)0xFFFFA176)->bit07)
#define RFPWGA38           (((volatile __bitf_T *)0xFFFFA177)->bit04)
#define CTPWGA38           (((volatile __bitf_T *)0xFFFFA177)->bit07)
#define ICPWGA39           (*(volatile unsigned short *)0xFFFFA178)
#define ICPWGA39L          (*(volatile unsigned char  *)0xFFFFA178)
#define ICPWGA39H          (*(volatile unsigned char  *)0xFFFFA179)
#define P0PWGA39           (((volatile __bitf_T *)0xFFFFA178)->bit00)
#define P1PWGA39           (((volatile __bitf_T *)0xFFFFA178)->bit01)
#define P2PWGA39           (((volatile __bitf_T *)0xFFFFA178)->bit02)
#define TBPWGA39           (((volatile __bitf_T *)0xFFFFA178)->bit06)
#define MKPWGA39           (((volatile __bitf_T *)0xFFFFA178)->bit07)
#define RFPWGA39           (((volatile __bitf_T *)0xFFFFA179)->bit04)
#define CTPWGA39           (((volatile __bitf_T *)0xFFFFA179)->bit07)
#define ICPWGA40           (*(volatile unsigned short *)0xFFFFA17A)
#define ICPWGA40L          (*(volatile unsigned char  *)0xFFFFA17A)
#define ICPWGA40H          (*(volatile unsigned char  *)0xFFFFA17B)
#define P0PWGA40           (((volatile __bitf_T *)0xFFFFA17A)->bit00)
#define P1PWGA40           (((volatile __bitf_T *)0xFFFFA17A)->bit01)
#define P2PWGA40           (((volatile __bitf_T *)0xFFFFA17A)->bit02)
#define TBPWGA40           (((volatile __bitf_T *)0xFFFFA17A)->bit06)
#define MKPWGA40           (((volatile __bitf_T *)0xFFFFA17A)->bit07)
#define RFPWGA40           (((volatile __bitf_T *)0xFFFFA17B)->bit04)
#define CTPWGA40           (((volatile __bitf_T *)0xFFFFA17B)->bit07)
#define ICPWGA41           (*(volatile unsigned short *)0xFFFFA17C)
#define ICPWGA41L          (*(volatile unsigned char  *)0xFFFFA17C)
#define ICPWGA41H          (*(volatile unsigned char  *)0xFFFFA17D)
#define P0PWGA41           (((volatile __bitf_T *)0xFFFFA17C)->bit00)
#define P1PWGA41           (((volatile __bitf_T *)0xFFFFA17C)->bit01)
#define P2PWGA41           (((volatile __bitf_T *)0xFFFFA17C)->bit02)
#define TBPWGA41           (((volatile __bitf_T *)0xFFFFA17C)->bit06)
#define MKPWGA41           (((volatile __bitf_T *)0xFFFFA17C)->bit07)
#define RFPWGA41           (((volatile __bitf_T *)0xFFFFA17D)->bit04)
#define CTPWGA41           (((volatile __bitf_T *)0xFFFFA17D)->bit07)
#define ICPWGA42           (*(volatile unsigned short *)0xFFFFA17E)
#define ICPWGA42L          (*(volatile unsigned char  *)0xFFFFA17E)
#define ICPWGA42H          (*(volatile unsigned char  *)0xFFFFA17F)
#define P0PWGA42           (((volatile __bitf_T *)0xFFFFA17E)->bit00)
#define P1PWGA42           (((volatile __bitf_T *)0xFFFFA17E)->bit01)
#define P2PWGA42           (((volatile __bitf_T *)0xFFFFA17E)->bit02)
#define TBPWGA42           (((volatile __bitf_T *)0xFFFFA17E)->bit06)
#define MKPWGA42           (((volatile __bitf_T *)0xFFFFA17E)->bit07)
#define RFPWGA42           (((volatile __bitf_T *)0xFFFFA17F)->bit04)
#define CTPWGA42           (((volatile __bitf_T *)0xFFFFA17F)->bit07)
#define ICPWGA43           (*(volatile unsigned short *)0xFFFFA180)
#define ICPWGA43L          (*(volatile unsigned char  *)0xFFFFA180)
#define ICPWGA43H          (*(volatile unsigned char  *)0xFFFFA181)
#define P0PWGA43           (((volatile __bitf_T *)0xFFFFA180)->bit00)
#define P1PWGA43           (((volatile __bitf_T *)0xFFFFA180)->bit01)
#define P2PWGA43           (((volatile __bitf_T *)0xFFFFA180)->bit02)
#define TBPWGA43           (((volatile __bitf_T *)0xFFFFA180)->bit06)
#define MKPWGA43           (((volatile __bitf_T *)0xFFFFA180)->bit07)
#define RFPWGA43           (((volatile __bitf_T *)0xFFFFA181)->bit04)
#define CTPWGA43           (((volatile __bitf_T *)0xFFFFA181)->bit07)
#define ICPWGA44           (*(volatile unsigned short *)0xFFFFA182)
#define ICPWGA44L          (*(volatile unsigned char  *)0xFFFFA182)
#define ICPWGA44H          (*(volatile unsigned char  *)0xFFFFA183)
#define P0PWGA44           (((volatile __bitf_T *)0xFFFFA182)->bit00)
#define P1PWGA44           (((volatile __bitf_T *)0xFFFFA182)->bit01)
#define P2PWGA44           (((volatile __bitf_T *)0xFFFFA182)->bit02)
#define TBPWGA44           (((volatile __bitf_T *)0xFFFFA182)->bit06)
#define MKPWGA44           (((volatile __bitf_T *)0xFFFFA182)->bit07)
#define RFPWGA44           (((volatile __bitf_T *)0xFFFFA183)->bit04)
#define CTPWGA44           (((volatile __bitf_T *)0xFFFFA183)->bit07)
#define ICPWGA45           (*(volatile unsigned short *)0xFFFFA184)
#define ICPWGA45L          (*(volatile unsigned char  *)0xFFFFA184)
#define ICPWGA45H          (*(volatile unsigned char  *)0xFFFFA185)
#define P0PWGA45           (((volatile __bitf_T *)0xFFFFA184)->bit00)
#define P1PWGA45           (((volatile __bitf_T *)0xFFFFA184)->bit01)
#define P2PWGA45           (((volatile __bitf_T *)0xFFFFA184)->bit02)
#define TBPWGA45           (((volatile __bitf_T *)0xFFFFA184)->bit06)
#define MKPWGA45           (((volatile __bitf_T *)0xFFFFA184)->bit07)
#define RFPWGA45           (((volatile __bitf_T *)0xFFFFA185)->bit04)
#define CTPWGA45           (((volatile __bitf_T *)0xFFFFA185)->bit07)
#define ICPWGA46           (*(volatile unsigned short *)0xFFFFA186)
#define ICPWGA46L          (*(volatile unsigned char  *)0xFFFFA186)
#define ICPWGA46H          (*(volatile unsigned char  *)0xFFFFA187)
#define P0PWGA46           (((volatile __bitf_T *)0xFFFFA186)->bit00)
#define P1PWGA46           (((volatile __bitf_T *)0xFFFFA186)->bit01)
#define P2PWGA46           (((volatile __bitf_T *)0xFFFFA186)->bit02)
#define TBPWGA46           (((volatile __bitf_T *)0xFFFFA186)->bit06)
#define MKPWGA46           (((volatile __bitf_T *)0xFFFFA186)->bit07)
#define RFPWGA46           (((volatile __bitf_T *)0xFFFFA187)->bit04)
#define CTPWGA46           (((volatile __bitf_T *)0xFFFFA187)->bit07)
#define ICPWGA47           (*(volatile unsigned short *)0xFFFFA188)
#define ICPWGA47L          (*(volatile unsigned char  *)0xFFFFA188)
#define ICPWGA47H          (*(volatile unsigned char  *)0xFFFFA189)
#define P0PWGA47           (((volatile __bitf_T *)0xFFFFA188)->bit00)
#define P1PWGA47           (((volatile __bitf_T *)0xFFFFA188)->bit01)
#define P2PWGA47           (((volatile __bitf_T *)0xFFFFA188)->bit02)
#define TBPWGA47           (((volatile __bitf_T *)0xFFFFA188)->bit06)
#define MKPWGA47           (((volatile __bitf_T *)0xFFFFA188)->bit07)
#define RFPWGA47           (((volatile __bitf_T *)0xFFFFA189)->bit04)
#define CTPWGA47           (((volatile __bitf_T *)0xFFFFA189)->bit07)
#define ICP9               (*(volatile unsigned short *)0xFFFFA18A)
#define ICP9L              (*(volatile unsigned char  *)0xFFFFA18A)
#define ICP9H              (*(volatile unsigned char  *)0xFFFFA18B)
#define P0P9               (((volatile __bitf_T *)0xFFFFA18A)->bit00)
#define P1P9               (((volatile __bitf_T *)0xFFFFA18A)->bit01)
#define P2P9               (((volatile __bitf_T *)0xFFFFA18A)->bit02)
#define TBP9               (((volatile __bitf_T *)0xFFFFA18A)->bit06)
#define MKP9               (((volatile __bitf_T *)0xFFFFA18A)->bit07)
#define RFP9               (((volatile __bitf_T *)0xFFFFA18B)->bit04)
#define CTP9               (((volatile __bitf_T *)0xFFFFA18B)->bit07)
#define ICP13              (*(volatile unsigned short *)0xFFFFA18C)
#define ICP13L             (*(volatile unsigned char  *)0xFFFFA18C)
#define ICP13H             (*(volatile unsigned char  *)0xFFFFA18D)
#define P0P13              (((volatile __bitf_T *)0xFFFFA18C)->bit00)
#define P1P13              (((volatile __bitf_T *)0xFFFFA18C)->bit01)
#define P2P13              (((volatile __bitf_T *)0xFFFFA18C)->bit02)
#define TBP13              (((volatile __bitf_T *)0xFFFFA18C)->bit06)
#define MKP13              (((volatile __bitf_T *)0xFFFFA18C)->bit07)
#define RFP13              (((volatile __bitf_T *)0xFFFFA18D)->bit04)
#define CTP13              (((volatile __bitf_T *)0xFFFFA18D)->bit07)
#define ICP14              (*(volatile unsigned short *)0xFFFFA18E)
#define ICP14L             (*(volatile unsigned char  *)0xFFFFA18E)
#define ICP14H             (*(volatile unsigned char  *)0xFFFFA18F)
#define P0P14              (((volatile __bitf_T *)0xFFFFA18E)->bit00)
#define P1P14              (((volatile __bitf_T *)0xFFFFA18E)->bit01)
#define P2P14              (((volatile __bitf_T *)0xFFFFA18E)->bit02)
#define TBP14              (((volatile __bitf_T *)0xFFFFA18E)->bit06)
#define MKP14              (((volatile __bitf_T *)0xFFFFA18E)->bit07)
#define RFP14              (((volatile __bitf_T *)0xFFFFA18F)->bit04)
#define CTP14              (((volatile __bitf_T *)0xFFFFA18F)->bit07)
#define ICP15              (*(volatile unsigned short *)0xFFFFA190)
#define ICP15L             (*(volatile unsigned char  *)0xFFFFA190)
#define ICP15H             (*(volatile unsigned char  *)0xFFFFA191)
#define P0P15              (((volatile __bitf_T *)0xFFFFA190)->bit00)
#define P1P15              (((volatile __bitf_T *)0xFFFFA190)->bit01)
#define P2P15              (((volatile __bitf_T *)0xFFFFA190)->bit02)
#define TBP15              (((volatile __bitf_T *)0xFFFFA190)->bit06)
#define MKP15              (((volatile __bitf_T *)0xFFFFA190)->bit07)
#define RFP15              (((volatile __bitf_T *)0xFFFFA191)->bit04)
#define CTP15              (((volatile __bitf_T *)0xFFFFA191)->bit07)
#define ICRTCA01S          (*(volatile unsigned short *)0xFFFFA192)
#define ICRTCA01SL         (*(volatile unsigned char  *)0xFFFFA192)
#define ICRTCA01SH         (*(volatile unsigned char  *)0xFFFFA193)
#define P0RTCA01S          (((volatile __bitf_T *)0xFFFFA192)->bit00)
#define P1RTCA01S          (((volatile __bitf_T *)0xFFFFA192)->bit01)
#define P2RTCA01S          (((volatile __bitf_T *)0xFFFFA192)->bit02)
#define TBRTCA01S          (((volatile __bitf_T *)0xFFFFA192)->bit06)
#define MKRTCA01S          (((volatile __bitf_T *)0xFFFFA192)->bit07)
#define RFRTCA01S          (((volatile __bitf_T *)0xFFFFA193)->bit04)
#define CTRTCA01S          (((volatile __bitf_T *)0xFFFFA193)->bit07)
#define ICRTCA0AL          (*(volatile unsigned short *)0xFFFFA194)
#define ICRTCA0ALL         (*(volatile unsigned char  *)0xFFFFA194)
#define ICRTCA0ALH         (*(volatile unsigned char  *)0xFFFFA195)
#define P0RTCA0AL          (((volatile __bitf_T *)0xFFFFA194)->bit00)
#define P1RTCA0AL          (((volatile __bitf_T *)0xFFFFA194)->bit01)
#define P2RTCA0AL          (((volatile __bitf_T *)0xFFFFA194)->bit02)
#define TBRTCA0AL          (((volatile __bitf_T *)0xFFFFA194)->bit06)
#define MKRTCA0AL          (((volatile __bitf_T *)0xFFFFA194)->bit07)
#define RFRTCA0AL          (((volatile __bitf_T *)0xFFFFA195)->bit04)
#define CTRTCA0AL          (((volatile __bitf_T *)0xFFFFA195)->bit07)
#define ICRTCA0R           (*(volatile unsigned short *)0xFFFFA196)
#define ICRTCA0RL          (*(volatile unsigned char  *)0xFFFFA196)
#define ICRTCA0RH          (*(volatile unsigned char  *)0xFFFFA197)
#define P0RTCA0R           (((volatile __bitf_T *)0xFFFFA196)->bit00)
#define P1RTCA0R           (((volatile __bitf_T *)0xFFFFA196)->bit01)
#define P2RTCA0R           (((volatile __bitf_T *)0xFFFFA196)->bit02)
#define TBRTCA0R           (((volatile __bitf_T *)0xFFFFA196)->bit06)
#define MKRTCA0R           (((volatile __bitf_T *)0xFFFFA196)->bit07)
#define RFRTCA0R           (((volatile __bitf_T *)0xFFFFA197)->bit04)
#define CTRTCA0R           (((volatile __bitf_T *)0xFFFFA197)->bit07)
#define ICADCA1ERR         (*(volatile unsigned short *)0xFFFFA198)
#define ICADCA1ERRL        (*(volatile unsigned char  *)0xFFFFA198)
#define ICADCA1ERRH        (*(volatile unsigned char  *)0xFFFFA199)
#define P0ADCA1ERR         (((volatile __bitf_T *)0xFFFFA198)->bit00)
#define P1ADCA1ERR         (((volatile __bitf_T *)0xFFFFA198)->bit01)
#define P2ADCA1ERR         (((volatile __bitf_T *)0xFFFFA198)->bit02)
#define TBADCA1ERR         (((volatile __bitf_T *)0xFFFFA198)->bit06)
#define MKADCA1ERR         (((volatile __bitf_T *)0xFFFFA198)->bit07)
#define RFADCA1ERR         (((volatile __bitf_T *)0xFFFFA199)->bit04)
#define CTADCA1ERR         (((volatile __bitf_T *)0xFFFFA199)->bit07)
#define ICADCA1I0          (*(volatile unsigned short *)0xFFFFA19A)
#define ICADCA1I0L         (*(volatile unsigned char  *)0xFFFFA19A)
#define ICADCA1I0H         (*(volatile unsigned char  *)0xFFFFA19B)
#define P0ADCA1I0          (((volatile __bitf_T *)0xFFFFA19A)->bit00)
#define P1ADCA1I0          (((volatile __bitf_T *)0xFFFFA19A)->bit01)
#define P2ADCA1I0          (((volatile __bitf_T *)0xFFFFA19A)->bit02)
#define TBADCA1I0          (((volatile __bitf_T *)0xFFFFA19A)->bit06)
#define MKADCA1I0          (((volatile __bitf_T *)0xFFFFA19A)->bit07)
#define RFADCA1I0          (((volatile __bitf_T *)0xFFFFA19B)->bit04)
#define CTADCA1I0          (((volatile __bitf_T *)0xFFFFA19B)->bit07)
#define ICADCA1I1          (*(volatile unsigned short *)0xFFFFA19C)
#define ICADCA1I1L         (*(volatile unsigned char  *)0xFFFFA19C)
#define ICADCA1I1H         (*(volatile unsigned char  *)0xFFFFA19D)
#define P0ADCA1I1          (((volatile __bitf_T *)0xFFFFA19C)->bit00)
#define P1ADCA1I1          (((volatile __bitf_T *)0xFFFFA19C)->bit01)
#define P2ADCA1I1          (((volatile __bitf_T *)0xFFFFA19C)->bit02)
#define TBADCA1I1          (((volatile __bitf_T *)0xFFFFA19C)->bit06)
#define MKADCA1I1          (((volatile __bitf_T *)0xFFFFA19C)->bit07)
#define RFADCA1I1          (((volatile __bitf_T *)0xFFFFA19D)->bit04)
#define CTADCA1I1          (((volatile __bitf_T *)0xFFFFA19D)->bit07)
#define ICADCA1I2          (*(volatile unsigned short *)0xFFFFA19E)
#define ICADCA1I2L         (*(volatile unsigned char  *)0xFFFFA19E)
#define ICADCA1I2H         (*(volatile unsigned char  *)0xFFFFA19F)
#define P0ADCA1I2          (((volatile __bitf_T *)0xFFFFA19E)->bit00)
#define P1ADCA1I2          (((volatile __bitf_T *)0xFFFFA19E)->bit01)
#define P2ADCA1I2          (((volatile __bitf_T *)0xFFFFA19E)->bit02)
#define TBADCA1I2          (((volatile __bitf_T *)0xFFFFA19E)->bit06)
#define MKADCA1I2          (((volatile __bitf_T *)0xFFFFA19E)->bit07)
#define RFADCA1I2          (((volatile __bitf_T *)0xFFFFA19F)->bit04)
#define CTADCA1I2          (((volatile __bitf_T *)0xFFFFA19F)->bit07)
#define ICRCAN2ERR         (*(volatile unsigned short *)0xFFFFA1A2)
#define ICRCAN2ERRL        (*(volatile unsigned char  *)0xFFFFA1A2)
#define ICRCAN2ERRH        (*(volatile unsigned char  *)0xFFFFA1A3)
#define P0RCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A2)->bit00)
#define P1RCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A2)->bit01)
#define P2RCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A2)->bit02)
#define TBRCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A2)->bit06)
#define MKRCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A2)->bit07)
#define RFRCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A3)->bit04)
#define CTRCAN2ERR         (((volatile __bitf_T *)0xFFFFA1A3)->bit07)
#define ICRCAN2REC         (*(volatile unsigned short *)0xFFFFA1A4)
#define ICRCAN2RECL        (*(volatile unsigned char  *)0xFFFFA1A4)
#define ICRCAN2RECH        (*(volatile unsigned char  *)0xFFFFA1A5)
#define P0RCAN2REC         (((volatile __bitf_T *)0xFFFFA1A4)->bit00)
#define P1RCAN2REC         (((volatile __bitf_T *)0xFFFFA1A4)->bit01)
#define P2RCAN2REC         (((volatile __bitf_T *)0xFFFFA1A4)->bit02)
#define TBRCAN2REC         (((volatile __bitf_T *)0xFFFFA1A4)->bit06)
#define MKRCAN2REC         (((volatile __bitf_T *)0xFFFFA1A4)->bit07)
#define RFRCAN2REC         (((volatile __bitf_T *)0xFFFFA1A5)->bit04)
#define CTRCAN2REC         (((volatile __bitf_T *)0xFFFFA1A5)->bit07)
#define ICRCAN2TRX         (*(volatile unsigned short *)0xFFFFA1A6)
#define ICRCAN2TRXL        (*(volatile unsigned char  *)0xFFFFA1A6)
#define ICRCAN2TRXH        (*(volatile unsigned char  *)0xFFFFA1A7)
#define P0RCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A6)->bit00)
#define P1RCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A6)->bit01)
#define P2RCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A6)->bit02)
#define TBRCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A6)->bit06)
#define MKRCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A6)->bit07)
#define RFRCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A7)->bit04)
#define CTRCAN2TRX         (((volatile __bitf_T *)0xFFFFA1A7)->bit07)
#define ICRCAN3ERR         (*(volatile unsigned short *)0xFFFFA1A8)
#define ICRCAN3ERRL        (*(volatile unsigned char  *)0xFFFFA1A8)
#define ICRCAN3ERRH        (*(volatile unsigned char  *)0xFFFFA1A9)
#define P0RCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A8)->bit00)
#define P1RCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A8)->bit01)
#define P2RCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A8)->bit02)
#define TBRCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A8)->bit06)
#define MKRCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A8)->bit07)
#define RFRCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A9)->bit04)
#define CTRCAN3ERR         (((volatile __bitf_T *)0xFFFFA1A9)->bit07)
#define ICRCAN3REC         (*(volatile unsigned short *)0xFFFFA1AA)
#define ICRCAN3RECL        (*(volatile unsigned char  *)0xFFFFA1AA)
#define ICRCAN3RECH        (*(volatile unsigned char  *)0xFFFFA1AB)
#define P0RCAN3REC         (((volatile __bitf_T *)0xFFFFA1AA)->bit00)
#define P1RCAN3REC         (((volatile __bitf_T *)0xFFFFA1AA)->bit01)
#define P2RCAN3REC         (((volatile __bitf_T *)0xFFFFA1AA)->bit02)
#define TBRCAN3REC         (((volatile __bitf_T *)0xFFFFA1AA)->bit06)
#define MKRCAN3REC         (((volatile __bitf_T *)0xFFFFA1AA)->bit07)
#define RFRCAN3REC         (((volatile __bitf_T *)0xFFFFA1AB)->bit04)
#define CTRCAN3REC         (((volatile __bitf_T *)0xFFFFA1AB)->bit07)
#define ICRCAN3TRX         (*(volatile unsigned short *)0xFFFFA1AC)
#define ICRCAN3TRXL        (*(volatile unsigned char  *)0xFFFFA1AC)
#define ICRCAN3TRXH        (*(volatile unsigned char  *)0xFFFFA1AD)
#define P0RCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AC)->bit00)
#define P1RCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AC)->bit01)
#define P2RCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AC)->bit02)
#define TBRCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AC)->bit06)
#define MKRCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AC)->bit07)
#define RFRCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AD)->bit04)
#define CTRCAN3TRX         (((volatile __bitf_T *)0xFFFFA1AD)->bit07)
#define ICCSIG1IC          (*(volatile unsigned short *)0xFFFFA1AE)
#define ICCSIG1ICL         (*(volatile unsigned char  *)0xFFFFA1AE)
#define ICCSIG1ICH         (*(volatile unsigned char  *)0xFFFFA1AF)
#define P0CSIG1IC          (((volatile __bitf_T *)0xFFFFA1AE)->bit00)
#define P1CSIG1IC          (((volatile __bitf_T *)0xFFFFA1AE)->bit01)
#define P2CSIG1IC          (((volatile __bitf_T *)0xFFFFA1AE)->bit02)
#define TBCSIG1IC          (((volatile __bitf_T *)0xFFFFA1AE)->bit06)
#define MKCSIG1IC          (((volatile __bitf_T *)0xFFFFA1AE)->bit07)
#define RFCSIG1IC          (((volatile __bitf_T *)0xFFFFA1AF)->bit04)
#define CTCSIG1IC          (((volatile __bitf_T *)0xFFFFA1AF)->bit07)
#define ICCSIG1IR          (*(volatile unsigned short *)0xFFFFA1B0)
#define ICCSIG1IRL         (*(volatile unsigned char  *)0xFFFFA1B0)
#define ICCSIG1IRH         (*(volatile unsigned char  *)0xFFFFA1B1)
#define P0CSIG1IR          (((volatile __bitf_T *)0xFFFFA1B0)->bit00)
#define P1CSIG1IR          (((volatile __bitf_T *)0xFFFFA1B0)->bit01)
#define P2CSIG1IR          (((volatile __bitf_T *)0xFFFFA1B0)->bit02)
#define TBCSIG1IR          (((volatile __bitf_T *)0xFFFFA1B0)->bit06)
#define MKCSIG1IR          (((volatile __bitf_T *)0xFFFFA1B0)->bit07)
#define RFCSIG1IR          (((volatile __bitf_T *)0xFFFFA1B1)->bit04)
#define CTCSIG1IR          (((volatile __bitf_T *)0xFFFFA1B1)->bit07)
#define ICCSIG1IRE         (*(volatile unsigned short *)0xFFFFA1B2)
#define ICCSIG1IREL        (*(volatile unsigned char  *)0xFFFFA1B2)
#define ICCSIG1IREH        (*(volatile unsigned char  *)0xFFFFA1B3)
#define P0CSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B2)->bit00)
#define P1CSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B2)->bit01)
#define P2CSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B2)->bit02)
#define TBCSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B2)->bit06)
#define MKCSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B2)->bit07)
#define RFCSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B3)->bit04)
#define CTCSIG1IRE         (((volatile __bitf_T *)0xFFFFA1B3)->bit07)
#define ICRLIN24           (*(volatile unsigned short *)0xFFFFA1B4)
#define ICRLIN24L          (*(volatile unsigned char  *)0xFFFFA1B4)
#define ICRLIN24H          (*(volatile unsigned char  *)0xFFFFA1B5)
#define P0RLIN24           (((volatile __bitf_T *)0xFFFFA1B4)->bit00)
#define P1RLIN24           (((volatile __bitf_T *)0xFFFFA1B4)->bit01)
#define P2RLIN24           (((volatile __bitf_T *)0xFFFFA1B4)->bit02)
#define TBRLIN24           (((volatile __bitf_T *)0xFFFFA1B4)->bit06)
#define MKRLIN24           (((volatile __bitf_T *)0xFFFFA1B4)->bit07)
#define RFRLIN24           (((volatile __bitf_T *)0xFFFFA1B5)->bit04)
#define CTRLIN24           (((volatile __bitf_T *)0xFFFFA1B5)->bit07)
#define ICRLIN25           (*(volatile unsigned short *)0xFFFFA1B6)
#define ICRLIN25L          (*(volatile unsigned char  *)0xFFFFA1B6)
#define ICRLIN25H          (*(volatile unsigned char  *)0xFFFFA1B7)
#define P0RLIN25           (((volatile __bitf_T *)0xFFFFA1B6)->bit00)
#define P1RLIN25           (((volatile __bitf_T *)0xFFFFA1B6)->bit01)
#define P2RLIN25           (((volatile __bitf_T *)0xFFFFA1B6)->bit02)
#define TBRLIN25           (((volatile __bitf_T *)0xFFFFA1B6)->bit06)
#define MKRLIN25           (((volatile __bitf_T *)0xFFFFA1B6)->bit07)
#define RFRLIN25           (((volatile __bitf_T *)0xFFFFA1B7)->bit04)
#define CTRLIN25           (((volatile __bitf_T *)0xFFFFA1B7)->bit07)
#define ICRLIN33           (*(volatile unsigned short *)0xFFFFA1B8)
#define ICRLIN33L          (*(volatile unsigned char  *)0xFFFFA1B8)
#define ICRLIN33H          (*(volatile unsigned char  *)0xFFFFA1B9)
#define P0RLIN33           (((volatile __bitf_T *)0xFFFFA1B8)->bit00)
#define P1RLIN33           (((volatile __bitf_T *)0xFFFFA1B8)->bit01)
#define P2RLIN33           (((volatile __bitf_T *)0xFFFFA1B8)->bit02)
#define TBRLIN33           (((volatile __bitf_T *)0xFFFFA1B8)->bit06)
#define MKRLIN33           (((volatile __bitf_T *)0xFFFFA1B8)->bit07)
#define RFRLIN33           (((volatile __bitf_T *)0xFFFFA1B9)->bit04)
#define CTRLIN33           (((volatile __bitf_T *)0xFFFFA1B9)->bit07)
#define ICRLIN33UR0        (*(volatile unsigned short *)0xFFFFA1BA)
#define ICRLIN33UR0L       (*(volatile unsigned char  *)0xFFFFA1BA)
#define ICRLIN33UR0H       (*(volatile unsigned char  *)0xFFFFA1BB)
#define P0RLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BA)->bit00)
#define P1RLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BA)->bit01)
#define P2RLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BA)->bit02)
#define TBRLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BA)->bit06)
#define MKRLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BA)->bit07)
#define RFRLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BB)->bit04)
#define CTRLIN33UR0        (((volatile __bitf_T *)0xFFFFA1BB)->bit07)
#define ICRLIN33UR1        (*(volatile unsigned short *)0xFFFFA1BC)
#define ICRLIN33UR1L       (*(volatile unsigned char  *)0xFFFFA1BC)
#define ICRLIN33UR1H       (*(volatile unsigned char  *)0xFFFFA1BD)
#define P0RLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BC)->bit00)
#define P1RLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BC)->bit01)
#define P2RLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BC)->bit02)
#define TBRLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BC)->bit06)
#define MKRLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BC)->bit07)
#define RFRLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BD)->bit04)
#define CTRLIN33UR1        (((volatile __bitf_T *)0xFFFFA1BD)->bit07)
#define ICRLIN33UR2        (*(volatile unsigned short *)0xFFFFA1BE)
#define ICRLIN33UR2L       (*(volatile unsigned char  *)0xFFFFA1BE)
#define ICRLIN33UR2H       (*(volatile unsigned char  *)0xFFFFA1BF)
#define P0RLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BE)->bit00)
#define P1RLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BE)->bit01)
#define P2RLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BE)->bit02)
#define TBRLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BE)->bit06)
#define MKRLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BE)->bit07)
#define RFRLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BF)->bit04)
#define CTRLIN33UR2        (((volatile __bitf_T *)0xFFFFA1BF)->bit07)
#define ICRLIN34           (*(volatile unsigned short *)0xFFFFA1C0)
#define ICRLIN34L          (*(volatile unsigned char  *)0xFFFFA1C0)
#define ICRLIN34H          (*(volatile unsigned char  *)0xFFFFA1C1)
#define P0RLIN34           (((volatile __bitf_T *)0xFFFFA1C0)->bit00)
#define P1RLIN34           (((volatile __bitf_T *)0xFFFFA1C0)->bit01)
#define P2RLIN34           (((volatile __bitf_T *)0xFFFFA1C0)->bit02)
#define TBRLIN34           (((volatile __bitf_T *)0xFFFFA1C0)->bit06)
#define MKRLIN34           (((volatile __bitf_T *)0xFFFFA1C0)->bit07)
#define RFRLIN34           (((volatile __bitf_T *)0xFFFFA1C1)->bit04)
#define CTRLIN34           (((volatile __bitf_T *)0xFFFFA1C1)->bit07)
#define ICRLIN34UR0        (*(volatile unsigned short *)0xFFFFA1C2)
#define ICRLIN34UR0L       (*(volatile unsigned char  *)0xFFFFA1C2)
#define ICRLIN34UR0H       (*(volatile unsigned char  *)0xFFFFA1C3)
#define P0RLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C2)->bit00)
#define P1RLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C2)->bit01)
#define P2RLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C2)->bit02)
#define TBRLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C2)->bit06)
#define MKRLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C2)->bit07)
#define RFRLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C3)->bit04)
#define CTRLIN34UR0        (((volatile __bitf_T *)0xFFFFA1C3)->bit07)
#define ICRLIN34UR1        (*(volatile unsigned short *)0xFFFFA1C4)
#define ICRLIN34UR1L       (*(volatile unsigned char  *)0xFFFFA1C4)
#define ICRLIN34UR1H       (*(volatile unsigned char  *)0xFFFFA1C5)
#define P0RLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C4)->bit00)
#define P1RLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C4)->bit01)
#define P2RLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C4)->bit02)
#define TBRLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C4)->bit06)
#define MKRLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C4)->bit07)
#define RFRLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C5)->bit04)
#define CTRLIN34UR1        (((volatile __bitf_T *)0xFFFFA1C5)->bit07)
#define ICRLIN34UR2        (*(volatile unsigned short *)0xFFFFA1C6)
#define ICRLIN34UR2L       (*(volatile unsigned char  *)0xFFFFA1C6)
#define ICRLIN34UR2H       (*(volatile unsigned char  *)0xFFFFA1C7)
#define P0RLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C6)->bit00)
#define P1RLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C6)->bit01)
#define P2RLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C6)->bit02)
#define TBRLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C6)->bit06)
#define MKRLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C6)->bit07)
#define RFRLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C7)->bit04)
#define CTRLIN34UR2        (((volatile __bitf_T *)0xFFFFA1C7)->bit07)
#define ICRLIN35           (*(volatile unsigned short *)0xFFFFA1C8)
#define ICRLIN35L          (*(volatile unsigned char  *)0xFFFFA1C8)
#define ICRLIN35H          (*(volatile unsigned char  *)0xFFFFA1C9)
#define P0RLIN35           (((volatile __bitf_T *)0xFFFFA1C8)->bit00)
#define P1RLIN35           (((volatile __bitf_T *)0xFFFFA1C8)->bit01)
#define P2RLIN35           (((volatile __bitf_T *)0xFFFFA1C8)->bit02)
#define TBRLIN35           (((volatile __bitf_T *)0xFFFFA1C8)->bit06)
#define MKRLIN35           (((volatile __bitf_T *)0xFFFFA1C8)->bit07)
#define RFRLIN35           (((volatile __bitf_T *)0xFFFFA1C9)->bit04)
#define CTRLIN35           (((volatile __bitf_T *)0xFFFFA1C9)->bit07)
#define ICRLIN35UR0        (*(volatile unsigned short *)0xFFFFA1CA)
#define ICRLIN35UR0L       (*(volatile unsigned char  *)0xFFFFA1CA)
#define ICRLIN35UR0H       (*(volatile unsigned char  *)0xFFFFA1CB)
#define P0RLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CA)->bit00)
#define P1RLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CA)->bit01)
#define P2RLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CA)->bit02)
#define TBRLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CA)->bit06)
#define MKRLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CA)->bit07)
#define RFRLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CB)->bit04)
#define CTRLIN35UR0        (((volatile __bitf_T *)0xFFFFA1CB)->bit07)
#define ICRLIN35UR1        (*(volatile unsigned short *)0xFFFFA1CC)
#define ICRLIN35UR1L       (*(volatile unsigned char  *)0xFFFFA1CC)
#define ICRLIN35UR1H       (*(volatile unsigned char  *)0xFFFFA1CD)
#define P0RLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CC)->bit00)
#define P1RLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CC)->bit01)
#define P2RLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CC)->bit02)
#define TBRLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CC)->bit06)
#define MKRLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CC)->bit07)
#define RFRLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CD)->bit04)
#define CTRLIN35UR1        (((volatile __bitf_T *)0xFFFFA1CD)->bit07)
#define ICRLIN35UR2        (*(volatile unsigned short *)0xFFFFA1CE)
#define ICRLIN35UR2L       (*(volatile unsigned char  *)0xFFFFA1CE)
#define ICRLIN35UR2H       (*(volatile unsigned char  *)0xFFFFA1CF)
#define P0RLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CE)->bit00)
#define P1RLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CE)->bit01)
#define P2RLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CE)->bit02)
#define TBRLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CE)->bit06)
#define MKRLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CE)->bit07)
#define RFRLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CF)->bit04)
#define CTRLIN35UR2        (((volatile __bitf_T *)0xFFFFA1CF)->bit07)
#define ICPWGA48           (*(volatile unsigned short *)0xFFFFA1D0)
#define ICPWGA48L          (*(volatile unsigned char  *)0xFFFFA1D0)
#define ICPWGA48H          (*(volatile unsigned char  *)0xFFFFA1D1)
#define P0PWGA48           (((volatile __bitf_T *)0xFFFFA1D0)->bit00)
#define P1PWGA48           (((volatile __bitf_T *)0xFFFFA1D0)->bit01)
#define P2PWGA48           (((volatile __bitf_T *)0xFFFFA1D0)->bit02)
#define TBPWGA48           (((volatile __bitf_T *)0xFFFFA1D0)->bit06)
#define MKPWGA48           (((volatile __bitf_T *)0xFFFFA1D0)->bit07)
#define RFPWGA48           (((volatile __bitf_T *)0xFFFFA1D1)->bit04)
#define CTPWGA48           (((volatile __bitf_T *)0xFFFFA1D1)->bit07)
#define ICPWGA49           (*(volatile unsigned short *)0xFFFFA1D2)
#define ICPWGA49L          (*(volatile unsigned char  *)0xFFFFA1D2)
#define ICPWGA49H          (*(volatile unsigned char  *)0xFFFFA1D3)
#define P0PWGA49           (((volatile __bitf_T *)0xFFFFA1D2)->bit00)
#define P1PWGA49           (((volatile __bitf_T *)0xFFFFA1D2)->bit01)
#define P2PWGA49           (((volatile __bitf_T *)0xFFFFA1D2)->bit02)
#define TBPWGA49           (((volatile __bitf_T *)0xFFFFA1D2)->bit06)
#define MKPWGA49           (((volatile __bitf_T *)0xFFFFA1D2)->bit07)
#define RFPWGA49           (((volatile __bitf_T *)0xFFFFA1D3)->bit04)
#define CTPWGA49           (((volatile __bitf_T *)0xFFFFA1D3)->bit07)
#define ICPWGA50           (*(volatile unsigned short *)0xFFFFA1D4)
#define ICPWGA50L          (*(volatile unsigned char  *)0xFFFFA1D4)
#define ICPWGA50H          (*(volatile unsigned char  *)0xFFFFA1D5)
#define P0PWGA50           (((volatile __bitf_T *)0xFFFFA1D4)->bit00)
#define P1PWGA50           (((volatile __bitf_T *)0xFFFFA1D4)->bit01)
#define P2PWGA50           (((volatile __bitf_T *)0xFFFFA1D4)->bit02)
#define TBPWGA50           (((volatile __bitf_T *)0xFFFFA1D4)->bit06)
#define MKPWGA50           (((volatile __bitf_T *)0xFFFFA1D4)->bit07)
#define RFPWGA50           (((volatile __bitf_T *)0xFFFFA1D5)->bit04)
#define CTPWGA50           (((volatile __bitf_T *)0xFFFFA1D5)->bit07)
#define ICPWGA51           (*(volatile unsigned short *)0xFFFFA1D6)
#define ICPWGA51L          (*(volatile unsigned char  *)0xFFFFA1D6)
#define ICPWGA51H          (*(volatile unsigned char  *)0xFFFFA1D7)
#define P0PWGA51           (((volatile __bitf_T *)0xFFFFA1D6)->bit00)
#define P1PWGA51           (((volatile __bitf_T *)0xFFFFA1D6)->bit01)
#define P2PWGA51           (((volatile __bitf_T *)0xFFFFA1D6)->bit02)
#define TBPWGA51           (((volatile __bitf_T *)0xFFFFA1D6)->bit06)
#define MKPWGA51           (((volatile __bitf_T *)0xFFFFA1D6)->bit07)
#define RFPWGA51           (((volatile __bitf_T *)0xFFFFA1D7)->bit04)
#define CTPWGA51           (((volatile __bitf_T *)0xFFFFA1D7)->bit07)
#define ICPWGA52           (*(volatile unsigned short *)0xFFFFA1D8)
#define ICPWGA52L          (*(volatile unsigned char  *)0xFFFFA1D8)
#define ICPWGA52H          (*(volatile unsigned char  *)0xFFFFA1D9)
#define P0PWGA52           (((volatile __bitf_T *)0xFFFFA1D8)->bit00)
#define P1PWGA52           (((volatile __bitf_T *)0xFFFFA1D8)->bit01)
#define P2PWGA52           (((volatile __bitf_T *)0xFFFFA1D8)->bit02)
#define TBPWGA52           (((volatile __bitf_T *)0xFFFFA1D8)->bit06)
#define MKPWGA52           (((volatile __bitf_T *)0xFFFFA1D8)->bit07)
#define RFPWGA52           (((volatile __bitf_T *)0xFFFFA1D9)->bit04)
#define CTPWGA52           (((volatile __bitf_T *)0xFFFFA1D9)->bit07)
#define ICPWGA53           (*(volatile unsigned short *)0xFFFFA1DA)
#define ICPWGA53L          (*(volatile unsigned char  *)0xFFFFA1DA)
#define ICPWGA53H          (*(volatile unsigned char  *)0xFFFFA1DB)
#define P0PWGA53           (((volatile __bitf_T *)0xFFFFA1DA)->bit00)
#define P1PWGA53           (((volatile __bitf_T *)0xFFFFA1DA)->bit01)
#define P2PWGA53           (((volatile __bitf_T *)0xFFFFA1DA)->bit02)
#define TBPWGA53           (((volatile __bitf_T *)0xFFFFA1DA)->bit06)
#define MKPWGA53           (((volatile __bitf_T *)0xFFFFA1DA)->bit07)
#define RFPWGA53           (((volatile __bitf_T *)0xFFFFA1DB)->bit04)
#define CTPWGA53           (((volatile __bitf_T *)0xFFFFA1DB)->bit07)
#define ICPWGA54           (*(volatile unsigned short *)0xFFFFA1DC)
#define ICPWGA54L          (*(volatile unsigned char  *)0xFFFFA1DC)
#define ICPWGA54H          (*(volatile unsigned char  *)0xFFFFA1DD)
#define P0PWGA54           (((volatile __bitf_T *)0xFFFFA1DC)->bit00)
#define P1PWGA54           (((volatile __bitf_T *)0xFFFFA1DC)->bit01)
#define P2PWGA54           (((volatile __bitf_T *)0xFFFFA1DC)->bit02)
#define TBPWGA54           (((volatile __bitf_T *)0xFFFFA1DC)->bit06)
#define MKPWGA54           (((volatile __bitf_T *)0xFFFFA1DC)->bit07)
#define RFPWGA54           (((volatile __bitf_T *)0xFFFFA1DD)->bit04)
#define CTPWGA54           (((volatile __bitf_T *)0xFFFFA1DD)->bit07)
#define ICPWGA55           (*(volatile unsigned short *)0xFFFFA1DE)
#define ICPWGA55L          (*(volatile unsigned char  *)0xFFFFA1DE)
#define ICPWGA55H          (*(volatile unsigned char  *)0xFFFFA1DF)
#define P0PWGA55           (((volatile __bitf_T *)0xFFFFA1DE)->bit00)
#define P1PWGA55           (((volatile __bitf_T *)0xFFFFA1DE)->bit01)
#define P2PWGA55           (((volatile __bitf_T *)0xFFFFA1DE)->bit02)
#define TBPWGA55           (((volatile __bitf_T *)0xFFFFA1DE)->bit06)
#define MKPWGA55           (((volatile __bitf_T *)0xFFFFA1DE)->bit07)
#define RFPWGA55           (((volatile __bitf_T *)0xFFFFA1DF)->bit04)
#define CTPWGA55           (((volatile __bitf_T *)0xFFFFA1DF)->bit07)
#define ICPWGA56           (*(volatile unsigned short *)0xFFFFA1E0)
#define ICPWGA56L          (*(volatile unsigned char  *)0xFFFFA1E0)
#define ICPWGA56H          (*(volatile unsigned char  *)0xFFFFA1E1)
#define P0PWGA56           (((volatile __bitf_T *)0xFFFFA1E0)->bit00)
#define P1PWGA56           (((volatile __bitf_T *)0xFFFFA1E0)->bit01)
#define P2PWGA56           (((volatile __bitf_T *)0xFFFFA1E0)->bit02)
#define TBPWGA56           (((volatile __bitf_T *)0xFFFFA1E0)->bit06)
#define MKPWGA56           (((volatile __bitf_T *)0xFFFFA1E0)->bit07)
#define RFPWGA56           (((volatile __bitf_T *)0xFFFFA1E1)->bit04)
#define CTPWGA56           (((volatile __bitf_T *)0xFFFFA1E1)->bit07)
#define ICPWGA57           (*(volatile unsigned short *)0xFFFFA1E2)
#define ICPWGA57L          (*(volatile unsigned char  *)0xFFFFA1E2)
#define ICPWGA57H          (*(volatile unsigned char  *)0xFFFFA1E3)
#define P0PWGA57           (((volatile __bitf_T *)0xFFFFA1E2)->bit00)
#define P1PWGA57           (((volatile __bitf_T *)0xFFFFA1E2)->bit01)
#define P2PWGA57           (((volatile __bitf_T *)0xFFFFA1E2)->bit02)
#define TBPWGA57           (((volatile __bitf_T *)0xFFFFA1E2)->bit06)
#define MKPWGA57           (((volatile __bitf_T *)0xFFFFA1E2)->bit07)
#define RFPWGA57           (((volatile __bitf_T *)0xFFFFA1E3)->bit04)
#define CTPWGA57           (((volatile __bitf_T *)0xFFFFA1E3)->bit07)
#define ICPWGA58           (*(volatile unsigned short *)0xFFFFA1E4)
#define ICPWGA58L          (*(volatile unsigned char  *)0xFFFFA1E4)
#define ICPWGA58H          (*(volatile unsigned char  *)0xFFFFA1E5)
#define P0PWGA58           (((volatile __bitf_T *)0xFFFFA1E4)->bit00)
#define P1PWGA58           (((volatile __bitf_T *)0xFFFFA1E4)->bit01)
#define P2PWGA58           (((volatile __bitf_T *)0xFFFFA1E4)->bit02)
#define TBPWGA58           (((volatile __bitf_T *)0xFFFFA1E4)->bit06)
#define MKPWGA58           (((volatile __bitf_T *)0xFFFFA1E4)->bit07)
#define RFPWGA58           (((volatile __bitf_T *)0xFFFFA1E5)->bit04)
#define CTPWGA58           (((volatile __bitf_T *)0xFFFFA1E5)->bit07)
#define ICPWGA59           (*(volatile unsigned short *)0xFFFFA1E6)
#define ICPWGA59L          (*(volatile unsigned char  *)0xFFFFA1E6)
#define ICPWGA59H          (*(volatile unsigned char  *)0xFFFFA1E7)
#define P0PWGA59           (((volatile __bitf_T *)0xFFFFA1E6)->bit00)
#define P1PWGA59           (((volatile __bitf_T *)0xFFFFA1E6)->bit01)
#define P2PWGA59           (((volatile __bitf_T *)0xFFFFA1E6)->bit02)
#define TBPWGA59           (((volatile __bitf_T *)0xFFFFA1E6)->bit06)
#define MKPWGA59           (((volatile __bitf_T *)0xFFFFA1E6)->bit07)
#define RFPWGA59           (((volatile __bitf_T *)0xFFFFA1E7)->bit04)
#define CTPWGA59           (((volatile __bitf_T *)0xFFFFA1E7)->bit07)
#define ICPWGA60           (*(volatile unsigned short *)0xFFFFA1E8)
#define ICPWGA60L          (*(volatile unsigned char  *)0xFFFFA1E8)
#define ICPWGA60H          (*(volatile unsigned char  *)0xFFFFA1E9)
#define P0PWGA60           (((volatile __bitf_T *)0xFFFFA1E8)->bit00)
#define P1PWGA60           (((volatile __bitf_T *)0xFFFFA1E8)->bit01)
#define P2PWGA60           (((volatile __bitf_T *)0xFFFFA1E8)->bit02)
#define TBPWGA60           (((volatile __bitf_T *)0xFFFFA1E8)->bit06)
#define MKPWGA60           (((volatile __bitf_T *)0xFFFFA1E8)->bit07)
#define RFPWGA60           (((volatile __bitf_T *)0xFFFFA1E9)->bit04)
#define CTPWGA60           (((volatile __bitf_T *)0xFFFFA1E9)->bit07)
#define ICPWGA61           (*(volatile unsigned short *)0xFFFFA1EA)
#define ICPWGA61L          (*(volatile unsigned char  *)0xFFFFA1EA)
#define ICPWGA61H          (*(volatile unsigned char  *)0xFFFFA1EB)
#define P0PWGA61           (((volatile __bitf_T *)0xFFFFA1EA)->bit00)
#define P1PWGA61           (((volatile __bitf_T *)0xFFFFA1EA)->bit01)
#define P2PWGA61           (((volatile __bitf_T *)0xFFFFA1EA)->bit02)
#define TBPWGA61           (((volatile __bitf_T *)0xFFFFA1EA)->bit06)
#define MKPWGA61           (((volatile __bitf_T *)0xFFFFA1EA)->bit07)
#define RFPWGA61           (((volatile __bitf_T *)0xFFFFA1EB)->bit04)
#define CTPWGA61           (((volatile __bitf_T *)0xFFFFA1EB)->bit07)
#define ICPWGA62           (*(volatile unsigned short *)0xFFFFA1EC)
#define ICPWGA62L          (*(volatile unsigned char  *)0xFFFFA1EC)
#define ICPWGA62H          (*(volatile unsigned char  *)0xFFFFA1ED)
#define P0PWGA62           (((volatile __bitf_T *)0xFFFFA1EC)->bit00)
#define P1PWGA62           (((volatile __bitf_T *)0xFFFFA1EC)->bit01)
#define P2PWGA62           (((volatile __bitf_T *)0xFFFFA1EC)->bit02)
#define TBPWGA62           (((volatile __bitf_T *)0xFFFFA1EC)->bit06)
#define MKPWGA62           (((volatile __bitf_T *)0xFFFFA1EC)->bit07)
#define RFPWGA62           (((volatile __bitf_T *)0xFFFFA1ED)->bit04)
#define CTPWGA62           (((volatile __bitf_T *)0xFFFFA1ED)->bit07)
#define ICPWGA63           (*(volatile unsigned short *)0xFFFFA1EE)
#define ICPWGA63L          (*(volatile unsigned char  *)0xFFFFA1EE)
#define ICPWGA63H          (*(volatile unsigned char  *)0xFFFFA1EF)
#define P0PWGA63           (((volatile __bitf_T *)0xFFFFA1EE)->bit00)
#define P1PWGA63           (((volatile __bitf_T *)0xFFFFA1EE)->bit01)
#define P2PWGA63           (((volatile __bitf_T *)0xFFFFA1EE)->bit02)
#define TBPWGA63           (((volatile __bitf_T *)0xFFFFA1EE)->bit06)
#define MKPWGA63           (((volatile __bitf_T *)0xFFFFA1EE)->bit07)
#define RFPWGA63           (((volatile __bitf_T *)0xFFFFA1EF)->bit04)
#define CTPWGA63           (((volatile __bitf_T *)0xFFFFA1EF)->bit07)
#define ICTAUB1I0          (*(volatile unsigned short *)0xFFFFA1F0)
#define ICTAUB1I0L         (*(volatile unsigned char  *)0xFFFFA1F0)
#define ICTAUB1I0H         (*(volatile unsigned char  *)0xFFFFA1F1)
#define P0TAUB1I0          (((volatile __bitf_T *)0xFFFFA1F0)->bit00)
#define P1TAUB1I0          (((volatile __bitf_T *)0xFFFFA1F0)->bit01)
#define P2TAUB1I0          (((volatile __bitf_T *)0xFFFFA1F0)->bit02)
#define TBTAUB1I0          (((volatile __bitf_T *)0xFFFFA1F0)->bit06)
#define MKTAUB1I0          (((volatile __bitf_T *)0xFFFFA1F0)->bit07)
#define RFTAUB1I0          (((volatile __bitf_T *)0xFFFFA1F1)->bit04)
#define CTTAUB1I0          (((volatile __bitf_T *)0xFFFFA1F1)->bit07)
#define ICTAUB1I1          (*(volatile unsigned short *)0xFFFFA1F2)
#define ICTAUB1I1L         (*(volatile unsigned char  *)0xFFFFA1F2)
#define ICTAUB1I1H         (*(volatile unsigned char  *)0xFFFFA1F3)
#define P0TAUB1I1          (((volatile __bitf_T *)0xFFFFA1F2)->bit00)
#define P1TAUB1I1          (((volatile __bitf_T *)0xFFFFA1F2)->bit01)
#define P2TAUB1I1          (((volatile __bitf_T *)0xFFFFA1F2)->bit02)
#define TBTAUB1I1          (((volatile __bitf_T *)0xFFFFA1F2)->bit06)
#define MKTAUB1I1          (((volatile __bitf_T *)0xFFFFA1F2)->bit07)
#define RFTAUB1I1          (((volatile __bitf_T *)0xFFFFA1F3)->bit04)
#define CTTAUB1I1          (((volatile __bitf_T *)0xFFFFA1F3)->bit07)
#define ICTAUB1I2          (*(volatile unsigned short *)0xFFFFA1F4)
#define ICTAUB1I2L         (*(volatile unsigned char  *)0xFFFFA1F4)
#define ICTAUB1I2H         (*(volatile unsigned char  *)0xFFFFA1F5)
#define P0TAUB1I2          (((volatile __bitf_T *)0xFFFFA1F4)->bit00)
#define P1TAUB1I2          (((volatile __bitf_T *)0xFFFFA1F4)->bit01)
#define P2TAUB1I2          (((volatile __bitf_T *)0xFFFFA1F4)->bit02)
#define TBTAUB1I2          (((volatile __bitf_T *)0xFFFFA1F4)->bit06)
#define MKTAUB1I2          (((volatile __bitf_T *)0xFFFFA1F4)->bit07)
#define RFTAUB1I2          (((volatile __bitf_T *)0xFFFFA1F5)->bit04)
#define CTTAUB1I2          (((volatile __bitf_T *)0xFFFFA1F5)->bit07)
#define ICTAUB1I3          (*(volatile unsigned short *)0xFFFFA1F6)
#define ICTAUB1I3L         (*(volatile unsigned char  *)0xFFFFA1F6)
#define ICTAUB1I3H         (*(volatile unsigned char  *)0xFFFFA1F7)
#define P0TAUB1I3          (((volatile __bitf_T *)0xFFFFA1F6)->bit00)
#define P1TAUB1I3          (((volatile __bitf_T *)0xFFFFA1F6)->bit01)
#define P2TAUB1I3          (((volatile __bitf_T *)0xFFFFA1F6)->bit02)
#define TBTAUB1I3          (((volatile __bitf_T *)0xFFFFA1F6)->bit06)
#define MKTAUB1I3          (((volatile __bitf_T *)0xFFFFA1F6)->bit07)
#define RFTAUB1I3          (((volatile __bitf_T *)0xFFFFA1F7)->bit04)
#define CTTAUB1I3          (((volatile __bitf_T *)0xFFFFA1F7)->bit07)
#define ICTAUB1I4          (*(volatile unsigned short *)0xFFFFA1F8)
#define ICTAUB1I4L         (*(volatile unsigned char  *)0xFFFFA1F8)
#define ICTAUB1I4H         (*(volatile unsigned char  *)0xFFFFA1F9)
#define P0TAUB1I4          (((volatile __bitf_T *)0xFFFFA1F8)->bit00)
#define P1TAUB1I4          (((volatile __bitf_T *)0xFFFFA1F8)->bit01)
#define P2TAUB1I4          (((volatile __bitf_T *)0xFFFFA1F8)->bit02)
#define TBTAUB1I4          (((volatile __bitf_T *)0xFFFFA1F8)->bit06)
#define MKTAUB1I4          (((volatile __bitf_T *)0xFFFFA1F8)->bit07)
#define RFTAUB1I4          (((volatile __bitf_T *)0xFFFFA1F9)->bit04)
#define CTTAUB1I4          (((volatile __bitf_T *)0xFFFFA1F9)->bit07)
#define ICTAUB1I5          (*(volatile unsigned short *)0xFFFFA1FA)
#define ICTAUB1I5L         (*(volatile unsigned char  *)0xFFFFA1FA)
#define ICTAUB1I5H         (*(volatile unsigned char  *)0xFFFFA1FB)
#define P0TAUB1I5          (((volatile __bitf_T *)0xFFFFA1FA)->bit00)
#define P1TAUB1I5          (((volatile __bitf_T *)0xFFFFA1FA)->bit01)
#define P2TAUB1I5          (((volatile __bitf_T *)0xFFFFA1FA)->bit02)
#define TBTAUB1I5          (((volatile __bitf_T *)0xFFFFA1FA)->bit06)
#define MKTAUB1I5          (((volatile __bitf_T *)0xFFFFA1FA)->bit07)
#define RFTAUB1I5          (((volatile __bitf_T *)0xFFFFA1FB)->bit04)
#define CTTAUB1I5          (((volatile __bitf_T *)0xFFFFA1FB)->bit07)
#define ICTAUB1I6          (*(volatile unsigned short *)0xFFFFA1FC)
#define ICTAUB1I6L         (*(volatile unsigned char  *)0xFFFFA1FC)
#define ICTAUB1I6H         (*(volatile unsigned char  *)0xFFFFA1FD)
#define P0TAUB1I6          (((volatile __bitf_T *)0xFFFFA1FC)->bit00)
#define P1TAUB1I6          (((volatile __bitf_T *)0xFFFFA1FC)->bit01)
#define P2TAUB1I6          (((volatile __bitf_T *)0xFFFFA1FC)->bit02)
#define TBTAUB1I6          (((volatile __bitf_T *)0xFFFFA1FC)->bit06)
#define MKTAUB1I6          (((volatile __bitf_T *)0xFFFFA1FC)->bit07)
#define RFTAUB1I6          (((volatile __bitf_T *)0xFFFFA1FD)->bit04)
#define CTTAUB1I6          (((volatile __bitf_T *)0xFFFFA1FD)->bit07)
#define ICTAUB1I7          (*(volatile unsigned short *)0xFFFFA1FE)
#define ICTAUB1I7L         (*(volatile unsigned char  *)0xFFFFA1FE)
#define ICTAUB1I7H         (*(volatile unsigned char  *)0xFFFFA1FF)
#define P0TAUB1I7          (((volatile __bitf_T *)0xFFFFA1FE)->bit00)
#define P1TAUB1I7          (((volatile __bitf_T *)0xFFFFA1FE)->bit01)
#define P2TAUB1I7          (((volatile __bitf_T *)0xFFFFA1FE)->bit02)
#define TBTAUB1I7          (((volatile __bitf_T *)0xFFFFA1FE)->bit06)
#define MKTAUB1I7          (((volatile __bitf_T *)0xFFFFA1FE)->bit07)
#define RFTAUB1I7          (((volatile __bitf_T *)0xFFFFA1FF)->bit04)
#define CTTAUB1I7          (((volatile __bitf_T *)0xFFFFA1FF)->bit07)
#define ICTAUB1I8          (*(volatile unsigned short *)0xFFFFA200)
#define ICTAUB1I8L         (*(volatile unsigned char  *)0xFFFFA200)
#define ICTAUB1I8H         (*(volatile unsigned char  *)0xFFFFA201)
#define P0TAUB1I8          (((volatile __bitf_T *)0xFFFFA200)->bit00)
#define P1TAUB1I8          (((volatile __bitf_T *)0xFFFFA200)->bit01)
#define P2TAUB1I8          (((volatile __bitf_T *)0xFFFFA200)->bit02)
#define TBTAUB1I8          (((volatile __bitf_T *)0xFFFFA200)->bit06)
#define MKTAUB1I8          (((volatile __bitf_T *)0xFFFFA200)->bit07)
#define RFTAUB1I8          (((volatile __bitf_T *)0xFFFFA201)->bit04)
#define CTTAUB1I8          (((volatile __bitf_T *)0xFFFFA201)->bit07)
#define ICTAUB1I9          (*(volatile unsigned short *)0xFFFFA202)
#define ICTAUB1I9L         (*(volatile unsigned char  *)0xFFFFA202)
#define ICTAUB1I9H         (*(volatile unsigned char  *)0xFFFFA203)
#define P0TAUB1I9          (((volatile __bitf_T *)0xFFFFA202)->bit00)
#define P1TAUB1I9          (((volatile __bitf_T *)0xFFFFA202)->bit01)
#define P2TAUB1I9          (((volatile __bitf_T *)0xFFFFA202)->bit02)
#define TBTAUB1I9          (((volatile __bitf_T *)0xFFFFA202)->bit06)
#define MKTAUB1I9          (((volatile __bitf_T *)0xFFFFA202)->bit07)
#define RFTAUB1I9          (((volatile __bitf_T *)0xFFFFA203)->bit04)
#define CTTAUB1I9          (((volatile __bitf_T *)0xFFFFA203)->bit07)
#define ICTAUB1I10         (*(volatile unsigned short *)0xFFFFA204)
#define ICTAUB1I10L        (*(volatile unsigned char  *)0xFFFFA204)
#define ICTAUB1I10H        (*(volatile unsigned char  *)0xFFFFA205)
#define P0TAUB1I10         (((volatile __bitf_T *)0xFFFFA204)->bit00)
#define P1TAUB1I10         (((volatile __bitf_T *)0xFFFFA204)->bit01)
#define P2TAUB1I10         (((volatile __bitf_T *)0xFFFFA204)->bit02)
#define TBTAUB1I10         (((volatile __bitf_T *)0xFFFFA204)->bit06)
#define MKTAUB1I10         (((volatile __bitf_T *)0xFFFFA204)->bit07)
#define RFTAUB1I10         (((volatile __bitf_T *)0xFFFFA205)->bit04)
#define CTTAUB1I10         (((volatile __bitf_T *)0xFFFFA205)->bit07)
#define ICTAUB1I11         (*(volatile unsigned short *)0xFFFFA206)
#define ICTAUB1I11L        (*(volatile unsigned char  *)0xFFFFA206)
#define ICTAUB1I11H        (*(volatile unsigned char  *)0xFFFFA207)
#define P0TAUB1I11         (((volatile __bitf_T *)0xFFFFA206)->bit00)
#define P1TAUB1I11         (((volatile __bitf_T *)0xFFFFA206)->bit01)
#define P2TAUB1I11         (((volatile __bitf_T *)0xFFFFA206)->bit02)
#define TBTAUB1I11         (((volatile __bitf_T *)0xFFFFA206)->bit06)
#define MKTAUB1I11         (((volatile __bitf_T *)0xFFFFA206)->bit07)
#define RFTAUB1I11         (((volatile __bitf_T *)0xFFFFA207)->bit04)
#define CTTAUB1I11         (((volatile __bitf_T *)0xFFFFA207)->bit07)
#define ICTAUB1I12         (*(volatile unsigned short *)0xFFFFA208)
#define ICTAUB1I12L        (*(volatile unsigned char  *)0xFFFFA208)
#define ICTAUB1I12H        (*(volatile unsigned char  *)0xFFFFA209)
#define P0TAUB1I12         (((volatile __bitf_T *)0xFFFFA208)->bit00)
#define P1TAUB1I12         (((volatile __bitf_T *)0xFFFFA208)->bit01)
#define P2TAUB1I12         (((volatile __bitf_T *)0xFFFFA208)->bit02)
#define TBTAUB1I12         (((volatile __bitf_T *)0xFFFFA208)->bit06)
#define MKTAUB1I12         (((volatile __bitf_T *)0xFFFFA208)->bit07)
#define RFTAUB1I12         (((volatile __bitf_T *)0xFFFFA209)->bit04)
#define CTTAUB1I12         (((volatile __bitf_T *)0xFFFFA209)->bit07)
#define ICTAUB1I13         (*(volatile unsigned short *)0xFFFFA20A)
#define ICTAUB1I13L        (*(volatile unsigned char  *)0xFFFFA20A)
#define ICTAUB1I13H        (*(volatile unsigned char  *)0xFFFFA20B)
#define P0TAUB1I13         (((volatile __bitf_T *)0xFFFFA20A)->bit00)
#define P1TAUB1I13         (((volatile __bitf_T *)0xFFFFA20A)->bit01)
#define P2TAUB1I13         (((volatile __bitf_T *)0xFFFFA20A)->bit02)
#define TBTAUB1I13         (((volatile __bitf_T *)0xFFFFA20A)->bit06)
#define MKTAUB1I13         (((volatile __bitf_T *)0xFFFFA20A)->bit07)
#define RFTAUB1I13         (((volatile __bitf_T *)0xFFFFA20B)->bit04)
#define CTTAUB1I13         (((volatile __bitf_T *)0xFFFFA20B)->bit07)
#define ICTAUB1I14         (*(volatile unsigned short *)0xFFFFA20C)
#define ICTAUB1I14L        (*(volatile unsigned char  *)0xFFFFA20C)
#define ICTAUB1I14H        (*(volatile unsigned char  *)0xFFFFA20D)
#define P0TAUB1I14         (((volatile __bitf_T *)0xFFFFA20C)->bit00)
#define P1TAUB1I14         (((volatile __bitf_T *)0xFFFFA20C)->bit01)
#define P2TAUB1I14         (((volatile __bitf_T *)0xFFFFA20C)->bit02)
#define TBTAUB1I14         (((volatile __bitf_T *)0xFFFFA20C)->bit06)
#define MKTAUB1I14         (((volatile __bitf_T *)0xFFFFA20C)->bit07)
#define RFTAUB1I14         (((volatile __bitf_T *)0xFFFFA20D)->bit04)
#define CTTAUB1I14         (((volatile __bitf_T *)0xFFFFA20D)->bit07)
#define ICTAUB1I15         (*(volatile unsigned short *)0xFFFFA20E)
#define ICTAUB1I15L        (*(volatile unsigned char  *)0xFFFFA20E)
#define ICTAUB1I15H        (*(volatile unsigned char  *)0xFFFFA20F)
#define P0TAUB1I15         (((volatile __bitf_T *)0xFFFFA20E)->bit00)
#define P1TAUB1I15         (((volatile __bitf_T *)0xFFFFA20E)->bit01)
#define P2TAUB1I15         (((volatile __bitf_T *)0xFFFFA20E)->bit02)
#define TBTAUB1I15         (((volatile __bitf_T *)0xFFFFA20E)->bit06)
#define MKTAUB1I15         (((volatile __bitf_T *)0xFFFFA20E)->bit07)
#define RFTAUB1I15         (((volatile __bitf_T *)0xFFFFA20F)->bit04)
#define CTTAUB1I15         (((volatile __bitf_T *)0xFFFFA20F)->bit07)
#define ICRCAN4ERR         (*(volatile unsigned short *)0xFFFFA210)
#define ICRCAN4ERRL        (*(volatile unsigned char  *)0xFFFFA210)
#define ICRCAN4ERRH        (*(volatile unsigned char  *)0xFFFFA211)
#define P0RCAN4ERR         (((volatile __bitf_T *)0xFFFFA210)->bit00)
#define P1RCAN4ERR         (((volatile __bitf_T *)0xFFFFA210)->bit01)
#define P2RCAN4ERR         (((volatile __bitf_T *)0xFFFFA210)->bit02)
#define TBRCAN4ERR         (((volatile __bitf_T *)0xFFFFA210)->bit06)
#define MKRCAN4ERR         (((volatile __bitf_T *)0xFFFFA210)->bit07)
#define RFRCAN4ERR         (((volatile __bitf_T *)0xFFFFA211)->bit04)
#define CTRCAN4ERR         (((volatile __bitf_T *)0xFFFFA211)->bit07)
#define ICRCAN4REC         (*(volatile unsigned short *)0xFFFFA212)
#define ICRCAN4RECL        (*(volatile unsigned char  *)0xFFFFA212)
#define ICRCAN4RECH        (*(volatile unsigned char  *)0xFFFFA213)
#define P0RCAN4REC         (((volatile __bitf_T *)0xFFFFA212)->bit00)
#define P1RCAN4REC         (((volatile __bitf_T *)0xFFFFA212)->bit01)
#define P2RCAN4REC         (((volatile __bitf_T *)0xFFFFA212)->bit02)
#define TBRCAN4REC         (((volatile __bitf_T *)0xFFFFA212)->bit06)
#define MKRCAN4REC         (((volatile __bitf_T *)0xFFFFA212)->bit07)
#define RFRCAN4REC         (((volatile __bitf_T *)0xFFFFA213)->bit04)
#define CTRCAN4REC         (((volatile __bitf_T *)0xFFFFA213)->bit07)
#define ICRCAN4TRX         (*(volatile unsigned short *)0xFFFFA214)
#define ICRCAN4TRXL        (*(volatile unsigned char  *)0xFFFFA214)
#define ICRCAN4TRXH        (*(volatile unsigned char  *)0xFFFFA215)
#define P0RCAN4TRX         (((volatile __bitf_T *)0xFFFFA214)->bit00)
#define P1RCAN4TRX         (((volatile __bitf_T *)0xFFFFA214)->bit01)
#define P2RCAN4TRX         (((volatile __bitf_T *)0xFFFFA214)->bit02)
#define TBRCAN4TRX         (((volatile __bitf_T *)0xFFFFA214)->bit06)
#define MKRCAN4TRX         (((volatile __bitf_T *)0xFFFFA214)->bit07)
#define RFRCAN4TRX         (((volatile __bitf_T *)0xFFFFA215)->bit04)
#define CTRCAN4TRX         (((volatile __bitf_T *)0xFFFFA215)->bit07)
#define ICRLIN26           (*(volatile unsigned short *)0xFFFFA216)
#define ICRLIN26L          (*(volatile unsigned char  *)0xFFFFA216)
#define ICRLIN26H          (*(volatile unsigned char  *)0xFFFFA217)
#define P0RLIN26           (((volatile __bitf_T *)0xFFFFA216)->bit00)
#define P1RLIN26           (((volatile __bitf_T *)0xFFFFA216)->bit01)
#define P2RLIN26           (((volatile __bitf_T *)0xFFFFA216)->bit02)
#define TBRLIN26           (((volatile __bitf_T *)0xFFFFA216)->bit06)
#define MKRLIN26           (((volatile __bitf_T *)0xFFFFA216)->bit07)
#define RFRLIN26           (((volatile __bitf_T *)0xFFFFA217)->bit04)
#define CTRLIN26           (((volatile __bitf_T *)0xFFFFA217)->bit07)
#define ICRLIN27           (*(volatile unsigned short *)0xFFFFA218)
#define ICRLIN27L          (*(volatile unsigned char  *)0xFFFFA218)
#define ICRLIN27H          (*(volatile unsigned char  *)0xFFFFA219)
#define P0RLIN27           (((volatile __bitf_T *)0xFFFFA218)->bit00)
#define P1RLIN27           (((volatile __bitf_T *)0xFFFFA218)->bit01)
#define P2RLIN27           (((volatile __bitf_T *)0xFFFFA218)->bit02)
#define TBRLIN27           (((volatile __bitf_T *)0xFFFFA218)->bit06)
#define MKRLIN27           (((volatile __bitf_T *)0xFFFFA218)->bit07)
#define RFRLIN27           (((volatile __bitf_T *)0xFFFFA219)->bit04)
#define CTRLIN27           (((volatile __bitf_T *)0xFFFFA219)->bit07)
#define ICPWGA64           (*(volatile unsigned short *)0xFFFFA21A)
#define ICPWGA64L          (*(volatile unsigned char  *)0xFFFFA21A)
#define ICPWGA64H          (*(volatile unsigned char  *)0xFFFFA21B)
#define P0PWGA64           (((volatile __bitf_T *)0xFFFFA21A)->bit00)
#define P1PWGA64           (((volatile __bitf_T *)0xFFFFA21A)->bit01)
#define P2PWGA64           (((volatile __bitf_T *)0xFFFFA21A)->bit02)
#define TBPWGA64           (((volatile __bitf_T *)0xFFFFA21A)->bit06)
#define MKPWGA64           (((volatile __bitf_T *)0xFFFFA21A)->bit07)
#define RFPWGA64           (((volatile __bitf_T *)0xFFFFA21B)->bit04)
#define CTPWGA64           (((volatile __bitf_T *)0xFFFFA21B)->bit07)
#define ICPWGA65           (*(volatile unsigned short *)0xFFFFA21C)
#define ICPWGA65L          (*(volatile unsigned char  *)0xFFFFA21C)
#define ICPWGA65H          (*(volatile unsigned char  *)0xFFFFA21D)
#define P0PWGA65           (((volatile __bitf_T *)0xFFFFA21C)->bit00)
#define P1PWGA65           (((volatile __bitf_T *)0xFFFFA21C)->bit01)
#define P2PWGA65           (((volatile __bitf_T *)0xFFFFA21C)->bit02)
#define TBPWGA65           (((volatile __bitf_T *)0xFFFFA21C)->bit06)
#define MKPWGA65           (((volatile __bitf_T *)0xFFFFA21C)->bit07)
#define RFPWGA65           (((volatile __bitf_T *)0xFFFFA21D)->bit04)
#define CTPWGA65           (((volatile __bitf_T *)0xFFFFA21D)->bit07)
#define ICPWGA66           (*(volatile unsigned short *)0xFFFFA21E)
#define ICPWGA66L          (*(volatile unsigned char  *)0xFFFFA21E)
#define ICPWGA66H          (*(volatile unsigned char  *)0xFFFFA21F)
#define P0PWGA66           (((volatile __bitf_T *)0xFFFFA21E)->bit00)
#define P1PWGA66           (((volatile __bitf_T *)0xFFFFA21E)->bit01)
#define P2PWGA66           (((volatile __bitf_T *)0xFFFFA21E)->bit02)
#define TBPWGA66           (((volatile __bitf_T *)0xFFFFA21E)->bit06)
#define MKPWGA66           (((volatile __bitf_T *)0xFFFFA21E)->bit07)
#define RFPWGA66           (((volatile __bitf_T *)0xFFFFA21F)->bit04)
#define CTPWGA66           (((volatile __bitf_T *)0xFFFFA21F)->bit07)
#define ICPWGA67           (*(volatile unsigned short *)0xFFFFA220)
#define ICPWGA67L          (*(volatile unsigned char  *)0xFFFFA220)
#define ICPWGA67H          (*(volatile unsigned char  *)0xFFFFA221)
#define P0PWGA67           (((volatile __bitf_T *)0xFFFFA220)->bit00)
#define P1PWGA67           (((volatile __bitf_T *)0xFFFFA220)->bit01)
#define P2PWGA67           (((volatile __bitf_T *)0xFFFFA220)->bit02)
#define TBPWGA67           (((volatile __bitf_T *)0xFFFFA220)->bit06)
#define MKPWGA67           (((volatile __bitf_T *)0xFFFFA220)->bit07)
#define RFPWGA67           (((volatile __bitf_T *)0xFFFFA221)->bit04)
#define CTPWGA67           (((volatile __bitf_T *)0xFFFFA221)->bit07)
#define ICPWGA68           (*(volatile unsigned short *)0xFFFFA222)
#define ICPWGA68L          (*(volatile unsigned char  *)0xFFFFA222)
#define ICPWGA68H          (*(volatile unsigned char  *)0xFFFFA223)
#define P0PWGA68           (((volatile __bitf_T *)0xFFFFA222)->bit00)
#define P1PWGA68           (((volatile __bitf_T *)0xFFFFA222)->bit01)
#define P2PWGA68           (((volatile __bitf_T *)0xFFFFA222)->bit02)
#define TBPWGA68           (((volatile __bitf_T *)0xFFFFA222)->bit06)
#define MKPWGA68           (((volatile __bitf_T *)0xFFFFA222)->bit07)
#define RFPWGA68           (((volatile __bitf_T *)0xFFFFA223)->bit04)
#define CTPWGA68           (((volatile __bitf_T *)0xFFFFA223)->bit07)
#define ICPWGA69           (*(volatile unsigned short *)0xFFFFA224)
#define ICPWGA69L          (*(volatile unsigned char  *)0xFFFFA224)
#define ICPWGA69H          (*(volatile unsigned char  *)0xFFFFA225)
#define P0PWGA69           (((volatile __bitf_T *)0xFFFFA224)->bit00)
#define P1PWGA69           (((volatile __bitf_T *)0xFFFFA224)->bit01)
#define P2PWGA69           (((volatile __bitf_T *)0xFFFFA224)->bit02)
#define TBPWGA69           (((volatile __bitf_T *)0xFFFFA224)->bit06)
#define MKPWGA69           (((volatile __bitf_T *)0xFFFFA224)->bit07)
#define RFPWGA69           (((volatile __bitf_T *)0xFFFFA225)->bit04)
#define CTPWGA69           (((volatile __bitf_T *)0xFFFFA225)->bit07)
#define ICPWGA70           (*(volatile unsigned short *)0xFFFFA226)
#define ICPWGA70L          (*(volatile unsigned char  *)0xFFFFA226)
#define ICPWGA70H          (*(volatile unsigned char  *)0xFFFFA227)
#define P0PWGA70           (((volatile __bitf_T *)0xFFFFA226)->bit00)
#define P1PWGA70           (((volatile __bitf_T *)0xFFFFA226)->bit01)
#define P2PWGA70           (((volatile __bitf_T *)0xFFFFA226)->bit02)
#define TBPWGA70           (((volatile __bitf_T *)0xFFFFA226)->bit06)
#define MKPWGA70           (((volatile __bitf_T *)0xFFFFA226)->bit07)
#define RFPWGA70           (((volatile __bitf_T *)0xFFFFA227)->bit04)
#define CTPWGA70           (((volatile __bitf_T *)0xFFFFA227)->bit07)
#define ICPWGA71           (*(volatile unsigned short *)0xFFFFA228)
#define ICPWGA71L          (*(volatile unsigned char  *)0xFFFFA228)
#define ICPWGA71H          (*(volatile unsigned char  *)0xFFFFA229)
#define P0PWGA71           (((volatile __bitf_T *)0xFFFFA228)->bit00)
#define P1PWGA71           (((volatile __bitf_T *)0xFFFFA228)->bit01)
#define P2PWGA71           (((volatile __bitf_T *)0xFFFFA228)->bit02)
#define TBPWGA71           (((volatile __bitf_T *)0xFFFFA228)->bit06)
#define MKPWGA71           (((volatile __bitf_T *)0xFFFFA228)->bit07)
#define RFPWGA71           (((volatile __bitf_T *)0xFFFFA229)->bit04)
#define CTPWGA71           (((volatile __bitf_T *)0xFFFFA229)->bit07)
#define ICRLIN28           (*(volatile unsigned short *)0xFFFFA22A)
#define ICRLIN28L          (*(volatile unsigned char  *)0xFFFFA22A)
#define ICRLIN28H          (*(volatile unsigned char  *)0xFFFFA22B)
#define P0RLIN28           (((volatile __bitf_T *)0xFFFFA22A)->bit00)
#define P1RLIN28           (((volatile __bitf_T *)0xFFFFA22A)->bit01)
#define P2RLIN28           (((volatile __bitf_T *)0xFFFFA22A)->bit02)
#define TBRLIN28           (((volatile __bitf_T *)0xFFFFA22A)->bit06)
#define MKRLIN28           (((volatile __bitf_T *)0xFFFFA22A)->bit07)
#define RFRLIN28           (((volatile __bitf_T *)0xFFFFA22B)->bit04)
#define CTRLIN28           (((volatile __bitf_T *)0xFFFFA22B)->bit07)
#define ICRLIN29           (*(volatile unsigned short *)0xFFFFA22C)
#define ICRLIN29L          (*(volatile unsigned char  *)0xFFFFA22C)
#define ICRLIN29H          (*(volatile unsigned char  *)0xFFFFA22D)
#define P0RLIN29           (((volatile __bitf_T *)0xFFFFA22C)->bit00)
#define P1RLIN29           (((volatile __bitf_T *)0xFFFFA22C)->bit01)
#define P2RLIN29           (((volatile __bitf_T *)0xFFFFA22C)->bit02)
#define TBRLIN29           (((volatile __bitf_T *)0xFFFFA22C)->bit06)
#define MKRLIN29           (((volatile __bitf_T *)0xFFFFA22C)->bit07)
#define RFRLIN29           (((volatile __bitf_T *)0xFFFFA22D)->bit04)
#define CTRLIN29           (((volatile __bitf_T *)0xFFFFA22D)->bit07)
#define ICRCAN5ERR         (*(volatile unsigned short *)0xFFFFA22E)
#define ICRCAN5ERRL        (*(volatile unsigned char  *)0xFFFFA22E)
#define ICRCAN5ERRH        (*(volatile unsigned char  *)0xFFFFA22F)
#define P0RCAN5ERR         (((volatile __bitf_T *)0xFFFFA22E)->bit00)
#define P1RCAN5ERR         (((volatile __bitf_T *)0xFFFFA22E)->bit01)
#define P2RCAN5ERR         (((volatile __bitf_T *)0xFFFFA22E)->bit02)
#define TBRCAN5ERR         (((volatile __bitf_T *)0xFFFFA22E)->bit06)
#define MKRCAN5ERR         (((volatile __bitf_T *)0xFFFFA22E)->bit07)
#define RFRCAN5ERR         (((volatile __bitf_T *)0xFFFFA22F)->bit04)
#define CTRCAN5ERR         (((volatile __bitf_T *)0xFFFFA22F)->bit07)
#define ICRCAN5REC         (*(volatile unsigned short *)0xFFFFA230)
#define ICRCAN5RECL        (*(volatile unsigned char  *)0xFFFFA230)
#define ICRCAN5RECH        (*(volatile unsigned char  *)0xFFFFA231)
#define P0RCAN5REC         (((volatile __bitf_T *)0xFFFFA230)->bit00)
#define P1RCAN5REC         (((volatile __bitf_T *)0xFFFFA230)->bit01)
#define P2RCAN5REC         (((volatile __bitf_T *)0xFFFFA230)->bit02)
#define TBRCAN5REC         (((volatile __bitf_T *)0xFFFFA230)->bit06)
#define MKRCAN5REC         (((volatile __bitf_T *)0xFFFFA230)->bit07)
#define RFRCAN5REC         (((volatile __bitf_T *)0xFFFFA231)->bit04)
#define CTRCAN5REC         (((volatile __bitf_T *)0xFFFFA231)->bit07)
#define ICRCAN5TRX         (*(volatile unsigned short *)0xFFFFA232)
#define ICRCAN5TRXL        (*(volatile unsigned char  *)0xFFFFA232)
#define ICRCAN5TRXH        (*(volatile unsigned char  *)0xFFFFA233)
#define P0RCAN5TRX         (((volatile __bitf_T *)0xFFFFA232)->bit00)
#define P1RCAN5TRX         (((volatile __bitf_T *)0xFFFFA232)->bit01)
#define P2RCAN5TRX         (((volatile __bitf_T *)0xFFFFA232)->bit02)
#define TBRCAN5TRX         (((volatile __bitf_T *)0xFFFFA232)->bit06)
#define MKRCAN5TRX         (((volatile __bitf_T *)0xFFFFA232)->bit07)
#define RFRCAN5TRX         (((volatile __bitf_T *)0xFFFFA233)->bit04)
#define CTRCAN5TRX         (((volatile __bitf_T *)0xFFFFA233)->bit07)
#define IMR1               (*(volatile unsigned long  *)0xFFFFA404)
#define IMR1L              (*(volatile unsigned short *)0xFFFFA404)
#define IMR1LL             (*(volatile unsigned char  *)0xFFFFA404)
#define IMR1LH             (*(volatile unsigned char  *)0xFFFFA405)
#define IMR1H              (*(volatile unsigned short *)0xFFFFA406)
#define IMR1HL             (*(volatile unsigned char  *)0xFFFFA406)
#define IMR1HH             (*(volatile unsigned char  *)0xFFFFA407)
#define IMR1EIMK32         (((volatile __bitf_T *)0xFFFFA404)->bit00)
#define IMR1EIMK33         (((volatile __bitf_T *)0xFFFFA404)->bit01)
#define IMR1EIMK34         (((volatile __bitf_T *)0xFFFFA404)->bit02)
#define IMR1EIMK35         (((volatile __bitf_T *)0xFFFFA404)->bit03)
#define IMR1EIMK36         (((volatile __bitf_T *)0xFFFFA404)->bit04)
#define IMR1EIMK37         (((volatile __bitf_T *)0xFFFFA404)->bit05)
#define IMR1EIMK38         (((volatile __bitf_T *)0xFFFFA404)->bit06)
#define IMR1EIMK39         (((volatile __bitf_T *)0xFFFFA404)->bit07)
#define IMR1EIMK40         (((volatile __bitf_T *)0xFFFFA405)->bit00)
#define IMR1EIMK41         (((volatile __bitf_T *)0xFFFFA405)->bit01)
#define IMR1EIMK42         (((volatile __bitf_T *)0xFFFFA405)->bit02)
#define IMR1EIMK43         (((volatile __bitf_T *)0xFFFFA405)->bit03)
#define IMR1EIMK44         (((volatile __bitf_T *)0xFFFFA405)->bit04)
#define IMR1EIMK45         (((volatile __bitf_T *)0xFFFFA405)->bit05)
#define IMR1EIMK46         (((volatile __bitf_T *)0xFFFFA405)->bit06)
#define IMR1EIMK47         (((volatile __bitf_T *)0xFFFFA405)->bit07)
#define IMR1EIMK49         (((volatile __bitf_T *)0xFFFFA406)->bit01)
#define IMR1EIMK50         (((volatile __bitf_T *)0xFFFFA406)->bit02)
#define IMR1EIMK51         (((volatile __bitf_T *)0xFFFFA406)->bit03)
#define IMR1EIMK52         (((volatile __bitf_T *)0xFFFFA406)->bit04)
#define IMR1EIMK53         (((volatile __bitf_T *)0xFFFFA406)->bit05)
#define IMR1EIMK54         (((volatile __bitf_T *)0xFFFFA406)->bit06)
#define IMR1EIMK55         (((volatile __bitf_T *)0xFFFFA406)->bit07)
#define IMR1EIMK56         (((volatile __bitf_T *)0xFFFFA407)->bit00)
#define IMR1EIMK57         (((volatile __bitf_T *)0xFFFFA407)->bit01)
#define IMR1EIMK58         (((volatile __bitf_T *)0xFFFFA407)->bit02)
#define IMR1EIMK59         (((volatile __bitf_T *)0xFFFFA407)->bit03)
#define IMR1EIMK60         (((volatile __bitf_T *)0xFFFFA407)->bit04)
#define IMR1EIMK61         (((volatile __bitf_T *)0xFFFFA407)->bit05)
#define IMR1EIMK62         (((volatile __bitf_T *)0xFFFFA407)->bit06)
#define IMR1EIMK63         (((volatile __bitf_T *)0xFFFFA407)->bit07)
#define IMR2               (*(volatile unsigned long  *)0xFFFFA408)
#define IMR2L              (*(volatile unsigned short *)0xFFFFA408)
#define IMR2LL             (*(volatile unsigned char  *)0xFFFFA408)
#define IMR2LH             (*(volatile unsigned char  *)0xFFFFA409)
#define IMR2H              (*(volatile unsigned short *)0xFFFFA40A)
#define IMR2HL             (*(volatile unsigned char  *)0xFFFFA40A)
#define IMR2HH             (*(volatile unsigned char  *)0xFFFFA40B)
#define IMR2EIMK64         (((volatile __bitf_T *)0xFFFFA408)->bit00)
#define IMR2EIMK65         (((volatile __bitf_T *)0xFFFFA408)->bit01)
#define IMR2EIMK66         (((volatile __bitf_T *)0xFFFFA408)->bit02)
#define IMR2EIMK67         (((volatile __bitf_T *)0xFFFFA408)->bit03)
#define IMR2EIMK68         (((volatile __bitf_T *)0xFFFFA408)->bit04)
#define IMR2EIMK69         (((volatile __bitf_T *)0xFFFFA408)->bit05)
#define IMR2EIMK70         (((volatile __bitf_T *)0xFFFFA408)->bit06)
#define IMR2EIMK71         (((volatile __bitf_T *)0xFFFFA408)->bit07)
#define IMR2EIMK72         (((volatile __bitf_T *)0xFFFFA409)->bit00)
#define IMR2EIMK73         (((volatile __bitf_T *)0xFFFFA409)->bit01)
#define IMR2EIMK74         (((volatile __bitf_T *)0xFFFFA409)->bit02)
#define IMR2EIMK75         (((volatile __bitf_T *)0xFFFFA409)->bit03)
#define IMR2EIMK76         (((volatile __bitf_T *)0xFFFFA409)->bit04)
#define IMR2EIMK77         (((volatile __bitf_T *)0xFFFFA409)->bit05)
#define IMR2EIMK78         (((volatile __bitf_T *)0xFFFFA409)->bit06)
#define IMR2EIMK79         (((volatile __bitf_T *)0xFFFFA409)->bit07)
#define IMR2EIMK80         (((volatile __bitf_T *)0xFFFFA40A)->bit00)
#define IMR2EIMK81         (((volatile __bitf_T *)0xFFFFA40A)->bit01)
#define IMR2EIMK82         (((volatile __bitf_T *)0xFFFFA40A)->bit02)
#define IMR2EIMK83         (((volatile __bitf_T *)0xFFFFA40A)->bit03)
#define IMR2EIMK84         (((volatile __bitf_T *)0xFFFFA40A)->bit04)
#define IMR2EIMK85         (((volatile __bitf_T *)0xFFFFA40A)->bit05)
#define IMR2EIMK86         (((volatile __bitf_T *)0xFFFFA40A)->bit06)
#define IMR2EIMK87         (((volatile __bitf_T *)0xFFFFA40A)->bit07)
#define IMR2EIMK88         (((volatile __bitf_T *)0xFFFFA40B)->bit00)
#define IMR2EIMK89         (((volatile __bitf_T *)0xFFFFA40B)->bit01)
#define IMR2EIMK90         (((volatile __bitf_T *)0xFFFFA40B)->bit02)
#define IMR2EIMK91         (((volatile __bitf_T *)0xFFFFA40B)->bit03)
#define IMR2EIMK92         (((volatile __bitf_T *)0xFFFFA40B)->bit04)
#define IMR2EIMK93         (((volatile __bitf_T *)0xFFFFA40B)->bit05)
#define IMR2EIMK94         (((volatile __bitf_T *)0xFFFFA40B)->bit06)
#define IMR2EIMK95         (((volatile __bitf_T *)0xFFFFA40B)->bit07)
#define IMR3               (*(volatile unsigned long  *)0xFFFFA40C)
#define IMR3L              (*(volatile unsigned short *)0xFFFFA40C)
#define IMR3LL             (*(volatile unsigned char  *)0xFFFFA40C)
#define IMR3LH             (*(volatile unsigned char  *)0xFFFFA40D)
#define IMR3H              (*(volatile unsigned short *)0xFFFFA40E)
#define IMR3HL             (*(volatile unsigned char  *)0xFFFFA40E)
#define IMR3HH             (*(volatile unsigned char  *)0xFFFFA40F)
#define IMR3EIMK102        (((volatile __bitf_T *)0xFFFFA40C)->bit06)
#define IMR3EIMK103        (((volatile __bitf_T *)0xFFFFA40C)->bit07)
#define IMR3EIMK104        (((volatile __bitf_T *)0xFFFFA40D)->bit00)
#define IMR3EIMK105        (((volatile __bitf_T *)0xFFFFA40D)->bit01)
#define IMR3EIMK106        (((volatile __bitf_T *)0xFFFFA40D)->bit02)
#define IMR3EIMK107        (((volatile __bitf_T *)0xFFFFA40D)->bit03)
#define IMR3EIMK108        (((volatile __bitf_T *)0xFFFFA40D)->bit04)
#define IMR3EIMK109        (((volatile __bitf_T *)0xFFFFA40D)->bit05)
#define IMR3EIMK110        (((volatile __bitf_T *)0xFFFFA40D)->bit06)
#define IMR3EIMK111        (((volatile __bitf_T *)0xFFFFA40D)->bit07)
#define IMR3EIMK112        (((volatile __bitf_T *)0xFFFFA40E)->bit00)
#define IMR3EIMK113        (((volatile __bitf_T *)0xFFFFA40E)->bit01)
#define IMR3EIMK114        (((volatile __bitf_T *)0xFFFFA40E)->bit02)
#define IMR3EIMK115        (((volatile __bitf_T *)0xFFFFA40E)->bit03)
#define IMR3EIMK116        (((volatile __bitf_T *)0xFFFFA40E)->bit04)
#define IMR3EIMK117        (((volatile __bitf_T *)0xFFFFA40E)->bit05)
#define IMR3EIMK118        (((volatile __bitf_T *)0xFFFFA40E)->bit06)
#define IMR3EIMK119        (((volatile __bitf_T *)0xFFFFA40E)->bit07)
#define IMR3EIMK120        (((volatile __bitf_T *)0xFFFFA40F)->bit00)
#define IMR3EIMK121        (((volatile __bitf_T *)0xFFFFA40F)->bit01)
#define IMR3EIMK122        (((volatile __bitf_T *)0xFFFFA40F)->bit02)
#define IMR3EIMK123        (((volatile __bitf_T *)0xFFFFA40F)->bit03)
#define IMR3EIMK124        (((volatile __bitf_T *)0xFFFFA40F)->bit04)
#define IMR3EIMK125        (((volatile __bitf_T *)0xFFFFA40F)->bit05)
#define IMR3EIMK126        (((volatile __bitf_T *)0xFFFFA40F)->bit06)
#define IMR3EIMK127        (((volatile __bitf_T *)0xFFFFA40F)->bit07)
#define IMR4               (*(volatile unsigned long  *)0xFFFFA410)
#define IMR4L              (*(volatile unsigned short *)0xFFFFA410)
#define IMR4LL             (*(volatile unsigned char  *)0xFFFFA410)
#define IMR4LH             (*(volatile unsigned char  *)0xFFFFA411)
#define IMR4H              (*(volatile unsigned short *)0xFFFFA412)
#define IMR4HL             (*(volatile unsigned char  *)0xFFFFA412)
#define IMR4HH             (*(volatile unsigned char  *)0xFFFFA413)
#define IMR4EIMK134        (((volatile __bitf_T *)0xFFFFA410)->bit06)
#define IMR4EIMK135        (((volatile __bitf_T *)0xFFFFA410)->bit07)
#define IMR4EIMK136        (((volatile __bitf_T *)0xFFFFA411)->bit00)
#define IMR4EIMK137        (((volatile __bitf_T *)0xFFFFA411)->bit01)
#define IMR4EIMK138        (((volatile __bitf_T *)0xFFFFA411)->bit02)
#define IMR4EIMK139        (((volatile __bitf_T *)0xFFFFA411)->bit03)
#define IMR4EIMK140        (((volatile __bitf_T *)0xFFFFA411)->bit04)
#define IMR4EIMK141        (((volatile __bitf_T *)0xFFFFA411)->bit05)
#define IMR4EIMK142        (((volatile __bitf_T *)0xFFFFA411)->bit06)
#define IMR4EIMK143        (((volatile __bitf_T *)0xFFFFA411)->bit07)
#define IMR4EIMK144        (((volatile __bitf_T *)0xFFFFA412)->bit00)
#define IMR4EIMK145        (((volatile __bitf_T *)0xFFFFA412)->bit01)
#define IMR4EIMK146        (((volatile __bitf_T *)0xFFFFA412)->bit02)
#define IMR4EIMK147        (((volatile __bitf_T *)0xFFFFA412)->bit03)
#define IMR4EIMK148        (((volatile __bitf_T *)0xFFFFA412)->bit04)
#define IMR4EIMK149        (((volatile __bitf_T *)0xFFFFA412)->bit05)
#define IMR4EIMK150        (((volatile __bitf_T *)0xFFFFA412)->bit06)
#define IMR4EIMK151        (((volatile __bitf_T *)0xFFFFA412)->bit07)
#define IMR4EIMK152        (((volatile __bitf_T *)0xFFFFA413)->bit00)
#define IMR4EIMK153        (((volatile __bitf_T *)0xFFFFA413)->bit01)
#define IMR4EIMK154        (((volatile __bitf_T *)0xFFFFA413)->bit02)
#define IMR4EIMK155        (((volatile __bitf_T *)0xFFFFA413)->bit03)
#define IMR4EIMK156        (((volatile __bitf_T *)0xFFFFA413)->bit04)
#define IMR4EIMK157        (((volatile __bitf_T *)0xFFFFA413)->bit05)
#define IMR4EIMK158        (((volatile __bitf_T *)0xFFFFA413)->bit06)
#define IMR4EIMK159        (((volatile __bitf_T *)0xFFFFA413)->bit07)
#define IMR5               (*(volatile unsigned long  *)0xFFFFA414)
#define IMR5L              (*(volatile unsigned short *)0xFFFFA414)
#define IMR5LL             (*(volatile unsigned char  *)0xFFFFA414)
#define IMR5H              (*(volatile unsigned short *)0xFFFFA416)
#define IMR5HL             (*(volatile unsigned char  *)0xFFFFA416)
#define IMR5HH             (*(volatile unsigned char  *)0xFFFFA417)
#define IMR5EIMK160        (((volatile __bitf_T *)0xFFFFA414)->bit00)
#define IMR5EIMK161        (((volatile __bitf_T *)0xFFFFA414)->bit01)
#define IMR5EIMK162        (((volatile __bitf_T *)0xFFFFA414)->bit02)
#define IMR5EIMK163        (((volatile __bitf_T *)0xFFFFA414)->bit03)
#define IMR5EIMK176        (((volatile __bitf_T *)0xFFFFA416)->bit00)
#define IMR5EIMK177        (((volatile __bitf_T *)0xFFFFA416)->bit01)
#define IMR5EIMK178        (((volatile __bitf_T *)0xFFFFA416)->bit02)
#define IMR5EIMK179        (((volatile __bitf_T *)0xFFFFA416)->bit03)
#define IMR5EIMK180        (((volatile __bitf_T *)0xFFFFA416)->bit04)
#define IMR5EIMK181        (((volatile __bitf_T *)0xFFFFA416)->bit05)
#define IMR5EIMK182        (((volatile __bitf_T *)0xFFFFA416)->bit06)
#define IMR5EIMK183        (((volatile __bitf_T *)0xFFFFA416)->bit07)
#define IMR5EIMK184        (((volatile __bitf_T *)0xFFFFA417)->bit00)
#define IMR5EIMK185        (((volatile __bitf_T *)0xFFFFA417)->bit01)
#define IMR5EIMK186        (((volatile __bitf_T *)0xFFFFA417)->bit02)
#define IMR5EIMK187        (((volatile __bitf_T *)0xFFFFA417)->bit03)
#define IMR5EIMK188        (((volatile __bitf_T *)0xFFFFA417)->bit04)
#define IMR5EIMK189        (((volatile __bitf_T *)0xFFFFA417)->bit05)
#define IMR5EIMK190        (((volatile __bitf_T *)0xFFFFA417)->bit06)
#define IMR5EIMK191        (((volatile __bitf_T *)0xFFFFA417)->bit07)
#define IMR6               (*(volatile unsigned long  *)0xFFFFA418)
#define IMR6L              (*(volatile unsigned short *)0xFFFFA418)
#define IMR6LL             (*(volatile unsigned char  *)0xFFFFA418)
#define IMR6LH             (*(volatile unsigned char  *)0xFFFFA419)
#define IMR6H              (*(volatile unsigned short *)0xFFFFA41A)
#define IMR6HL             (*(volatile unsigned char  *)0xFFFFA41A)
#define IMR6HH             (*(volatile unsigned char  *)0xFFFFA41B)
#define IMR6EIMK192        (((volatile __bitf_T *)0xFFFFA418)->bit00)
#define IMR6EIMK193        (((volatile __bitf_T *)0xFFFFA418)->bit01)
#define IMR6EIMK194        (((volatile __bitf_T *)0xFFFFA418)->bit02)
#define IMR6EIMK195        (((volatile __bitf_T *)0xFFFFA418)->bit03)
#define IMR6EIMK196        (((volatile __bitf_T *)0xFFFFA418)->bit04)
#define IMR6EIMK197        (((volatile __bitf_T *)0xFFFFA418)->bit05)
#define IMR6EIMK198        (((volatile __bitf_T *)0xFFFFA418)->bit06)
#define IMR6EIMK199        (((volatile __bitf_T *)0xFFFFA418)->bit07)
#define IMR6EIMK200        (((volatile __bitf_T *)0xFFFFA419)->bit00)
#define IMR6EIMK201        (((volatile __bitf_T *)0xFFFFA419)->bit01)
#define IMR6EIMK202        (((volatile __bitf_T *)0xFFFFA419)->bit02)
#define IMR6EIMK203        (((volatile __bitf_T *)0xFFFFA419)->bit03)
#define IMR6EIMK204        (((volatile __bitf_T *)0xFFFFA419)->bit04)
#define IMR6EIMK205        (((volatile __bitf_T *)0xFFFFA419)->bit05)
#define IMR6EIMK206        (((volatile __bitf_T *)0xFFFFA419)->bit06)
#define IMR6EIMK207        (((volatile __bitf_T *)0xFFFFA419)->bit07)
#define IMR6EIMK209        (((volatile __bitf_T *)0xFFFFA41A)->bit01)
#define IMR6EIMK210        (((volatile __bitf_T *)0xFFFFA41A)->bit02)
#define IMR6EIMK211        (((volatile __bitf_T *)0xFFFFA41A)->bit03)
#define IMR6EIMK212        (((volatile __bitf_T *)0xFFFFA41A)->bit04)
#define IMR6EIMK213        (((volatile __bitf_T *)0xFFFFA41A)->bit05)
#define IMR6EIMK214        (((volatile __bitf_T *)0xFFFFA41A)->bit06)
#define IMR6EIMK215        (((volatile __bitf_T *)0xFFFFA41A)->bit07)
#define IMR6EIMK216        (((volatile __bitf_T *)0xFFFFA41B)->bit00)
#define IMR6EIMK217        (((volatile __bitf_T *)0xFFFFA41B)->bit01)
#define IMR6EIMK218        (((volatile __bitf_T *)0xFFFFA41B)->bit02)
#define IMR6EIMK219        (((volatile __bitf_T *)0xFFFFA41B)->bit03)
#define IMR6EIMK220        (((volatile __bitf_T *)0xFFFFA41B)->bit04)
#define IMR6EIMK221        (((volatile __bitf_T *)0xFFFFA41B)->bit05)
#define IMR6EIMK222        (((volatile __bitf_T *)0xFFFFA41B)->bit06)
#define IMR6EIMK223        (((volatile __bitf_T *)0xFFFFA41B)->bit07)
#define IMR7               (*(volatile unsigned long  *)0xFFFFA41C)
#define IMR7L              (*(volatile unsigned short *)0xFFFFA41C)
#define IMR7LL             (*(volatile unsigned char  *)0xFFFFA41C)
#define IMR7LH             (*(volatile unsigned char  *)0xFFFFA41D)
#define IMR7H              (*(volatile unsigned short *)0xFFFFA41E)
#define IMR7HL             (*(volatile unsigned char  *)0xFFFFA41E)
#define IMR7HH             (*(volatile unsigned char  *)0xFFFFA41F)
#define IMR7EIMK224        (((volatile __bitf_T *)0xFFFFA41C)->bit00)
#define IMR7EIMK225        (((volatile __bitf_T *)0xFFFFA41C)->bit01)
#define IMR7EIMK226        (((volatile __bitf_T *)0xFFFFA41C)->bit02)
#define IMR7EIMK227        (((volatile __bitf_T *)0xFFFFA41C)->bit03)
#define IMR7EIMK228        (((volatile __bitf_T *)0xFFFFA41C)->bit04)
#define IMR7EIMK229        (((volatile __bitf_T *)0xFFFFA41C)->bit05)
#define IMR7EIMK230        (((volatile __bitf_T *)0xFFFFA41C)->bit06)
#define IMR7EIMK231        (((volatile __bitf_T *)0xFFFFA41C)->bit07)
#define IMR7EIMK232        (((volatile __bitf_T *)0xFFFFA41D)->bit00)
#define IMR7EIMK233        (((volatile __bitf_T *)0xFFFFA41D)->bit01)
#define IMR7EIMK234        (((volatile __bitf_T *)0xFFFFA41D)->bit02)
#define IMR7EIMK235        (((volatile __bitf_T *)0xFFFFA41D)->bit03)
#define IMR7EIMK236        (((volatile __bitf_T *)0xFFFFA41D)->bit04)
#define IMR7EIMK237        (((volatile __bitf_T *)0xFFFFA41D)->bit05)
#define IMR7EIMK238        (((volatile __bitf_T *)0xFFFFA41D)->bit06)
#define IMR7EIMK239        (((volatile __bitf_T *)0xFFFFA41D)->bit07)
#define IMR7EIMK240        (((volatile __bitf_T *)0xFFFFA41E)->bit00)
#define IMR7EIMK241        (((volatile __bitf_T *)0xFFFFA41E)->bit01)
#define IMR7EIMK242        (((volatile __bitf_T *)0xFFFFA41E)->bit02)
#define IMR7EIMK243        (((volatile __bitf_T *)0xFFFFA41E)->bit03)
#define IMR7EIMK244        (((volatile __bitf_T *)0xFFFFA41E)->bit04)
#define IMR7EIMK245        (((volatile __bitf_T *)0xFFFFA41E)->bit05)
#define IMR7EIMK246        (((volatile __bitf_T *)0xFFFFA41E)->bit06)
#define IMR7EIMK247        (((volatile __bitf_T *)0xFFFFA41E)->bit07)
#define IMR7EIMK248        (((volatile __bitf_T *)0xFFFFA41F)->bit00)
#define IMR7EIMK249        (((volatile __bitf_T *)0xFFFFA41F)->bit01)
#define IMR7EIMK250        (((volatile __bitf_T *)0xFFFFA41F)->bit02)
#define IMR7EIMK251        (((volatile __bitf_T *)0xFFFFA41F)->bit03)
#define IMR7EIMK252        (((volatile __bitf_T *)0xFFFFA41F)->bit04)
#define IMR7EIMK253        (((volatile __bitf_T *)0xFFFFA41F)->bit05)
#define IMR7EIMK254        (((volatile __bitf_T *)0xFFFFA41F)->bit06)
#define IMR7EIMK255        (((volatile __bitf_T *)0xFFFFA41F)->bit07)
#define IMR8               (*(volatile unsigned long  *)0xFFFFA420)
#define IMR8L              (*(volatile unsigned short *)0xFFFFA420)
#define IMR8LL             (*(volatile unsigned char  *)0xFFFFA420)
#define IMR8LH             (*(volatile unsigned char  *)0xFFFFA421)
#define IMR8H              (*(volatile unsigned short *)0xFFFFA422)
#define IMR8HL             (*(volatile unsigned char  *)0xFFFFA422)
#define IMR8HH             (*(volatile unsigned char  *)0xFFFFA423)
#define IMR8EIMK256        (((volatile __bitf_T *)0xFFFFA420)->bit00)
#define IMR8EIMK257        (((volatile __bitf_T *)0xFFFFA420)->bit01)
#define IMR8EIMK258        (((volatile __bitf_T *)0xFFFFA420)->bit02)
#define IMR8EIMK259        (((volatile __bitf_T *)0xFFFFA420)->bit03)
#define IMR8EIMK260        (((volatile __bitf_T *)0xFFFFA420)->bit04)
#define IMR8EIMK261        (((volatile __bitf_T *)0xFFFFA420)->bit05)
#define IMR8EIMK262        (((volatile __bitf_T *)0xFFFFA420)->bit06)
#define IMR8EIMK263        (((volatile __bitf_T *)0xFFFFA420)->bit07)
#define IMR8EIMK264        (((volatile __bitf_T *)0xFFFFA421)->bit00)
#define IMR8EIMK265        (((volatile __bitf_T *)0xFFFFA421)->bit01)
#define IMR8EIMK266        (((volatile __bitf_T *)0xFFFFA421)->bit02)
#define IMR8EIMK267        (((volatile __bitf_T *)0xFFFFA421)->bit03)
#define IMR8EIMK268        (((volatile __bitf_T *)0xFFFFA421)->bit04)
#define IMR8EIMK269        (((volatile __bitf_T *)0xFFFFA421)->bit05)
#define IMR8EIMK270        (((volatile __bitf_T *)0xFFFFA421)->bit06)
#define IMR8EIMK271        (((volatile __bitf_T *)0xFFFFA421)->bit07)
#define IMR8EIMK272        (((volatile __bitf_T *)0xFFFFA422)->bit00)
#define IMR8EIMK273        (((volatile __bitf_T *)0xFFFFA422)->bit01)
#define IMR8EIMK274        (((volatile __bitf_T *)0xFFFFA422)->bit02)
#define IMR8EIMK275        (((volatile __bitf_T *)0xFFFFA422)->bit03)
#define IMR8EIMK276        (((volatile __bitf_T *)0xFFFFA422)->bit04)
#define IMR8EIMK277        (((volatile __bitf_T *)0xFFFFA422)->bit05)
#define IMR8EIMK278        (((volatile __bitf_T *)0xFFFFA422)->bit06)
#define IMR8EIMK279        (((volatile __bitf_T *)0xFFFFA422)->bit07)
#define IMR8EIMK280        (((volatile __bitf_T *)0xFFFFA423)->bit00)
#define IMR8EIMK281        (((volatile __bitf_T *)0xFFFFA423)->bit01)

#define SELF    (*(volatile struct __tag20 *)0xFFA08000) /* SELF */
#define FACI    (*(volatile struct __tag21 *)0xFFA10000) /* FACI */
#define PFSS    (*(volatile struct __tag22 *)0xFFBC0700) /* PFSS */
#define CCIB    (*(volatile struct __tag23 *)0xFFC59008) /* CCIB */
#define RIIC0   (*(volatile struct __tag24 *)0xFFCA0000) /* RIIC0 */
#define SCDS    (*(volatile struct __tag25 *)0xFFCD00D0) /* SCDS */
#define RLN240  (*(volatile struct __tag26 *)0xFFCE0000) /* RLN240 */
#define RLN2400 (*(volatile struct __tag27 *)0xFFCE0008) /* RLN2400 */
#define RLN2401 (*(volatile struct __tag28 *)0xFFCE0028) /* RLN2401 */
#define RLN2402 (*(volatile struct __tag29 *)0xFFCE0048) /* RLN2402 */
#define RLN2403 (*(volatile struct __tag30 *)0xFFCE0068) /* RLN2403 */
#define RLN241  (*(volatile struct __tag26 *)0xFFCE0080) /* RLN241 */
#define RLN2414 (*(volatile struct __tag27 *)0xFFCE0088) /* RLN2414 */
#define RLN2415 (*(volatile struct __tag28 *)0xFFCE00A8) /* RLN2415 */
#define RLN2416 (*(volatile struct __tag29 *)0xFFCE00C8) /* RLN2416 */
#define RLN2417 (*(volatile struct __tag30 *)0xFFCE00E8) /* RLN2417 */
#define RLN210  (*(volatile struct __tag26 *)0xFFCE0100) /* RLN210 */
#define RLN2108 (*(volatile struct __tag27 *)0xFFCE0108) /* RLN2108 */
#define RLN211  (*(volatile struct __tag26 *)0xFFCE0120) /* RLN211 */
#define RLN2119 (*(volatile struct __tag27 *)0xFFCE0128) /* RLN2119 */
#define RLN30   (*(volatile struct __tag31 *)0xFFCF0000) /* RLN30 */
#define RLN31   (*(volatile struct __tag31 *)0xFFCF0040) /* RLN31 */
#define RLN32   (*(volatile struct __tag31 *)0xFFCF0080) /* RLN32 */
#define RLN33   (*(volatile struct __tag31 *)0xFFCF00C0) /* RLN33 */
#define RLN34   (*(volatile struct __tag31 *)0xFFCF0100) /* RLN34 */
#define RLN35   (*(volatile struct __tag31 *)0xFFCF0140) /* RLN35 */
#define RSCAN0  (*(volatile struct __tag32 *)0xFFD00000) /* RSCAN0 */
#define CSIH0   (*(volatile struct __tag33 *)0xFFD80000) /* CSIH0 */
#define CSIH1   (*(volatile struct __tag34 *)0xFFD82000) /* CSIH1 */
#define CSIH2   (*(volatile struct __tag34 *)0xFFD84000) /* CSIH2 */
#define CSIH3   (*(volatile struct __tag35 *)0xFFD86000) /* CSIH3 */
#define CSIG0   (*(volatile struct __tag36 *)0xFFDB0000) /* CSIG0 */
#define CSIG1   (*(volatile struct __tag36 *)0xFFDB2000) /* CSIG1 */
#define PIC0    (*(volatile struct __tag37 *)0xFFDD0004) /* PIC0 */
#define TAUD0   (*(volatile struct __tag38 *)0xFFE20000) /* TAUD0 */
#define TAUB0   (*(volatile struct __tag39 *)0xFFE30000) /* TAUB0 */
#define TAUB1   (*(volatile struct __tag39 *)0xFFE31000) /* TAUB1 */
#define TAUJ0   (*(volatile struct __tag40 *)0xFFE50000) /* TAUJ0 */
#define TAUJ1   (*(volatile struct __tag40 *)0xFFE51000) /* TAUJ1 */
#define PWSA0   (*(volatile struct __tag41 *)0xFFE70000) /* PWSA0 */
#define PWGA0   (*(volatile struct __tag42 *)0xFFE71000) /* PWGA0 */
#define PWGA1   (*(volatile struct __tag42 *)0xFFE71040) /* PWGA1 */
#define PWGA2   (*(volatile struct __tag42 *)0xFFE71080) /* PWGA2 */
#define PWGA3   (*(volatile struct __tag42 *)0xFFE710C0) /* PWGA3 */
#define PWGA4   (*(volatile struct __tag42 *)0xFFE71100) /* PWGA4 */
#define PWGA5   (*(volatile struct __tag42 *)0xFFE71140) /* PWGA5 */
#define PWGA6   (*(volatile struct __tag42 *)0xFFE71180) /* PWGA6 */
#define PWGA7   (*(volatile struct __tag42 *)0xFFE711C0) /* PWGA7 */
#define PWGA8   (*(volatile struct __tag42 *)0xFFE71200) /* PWGA8 */
#define PWGA9   (*(volatile struct __tag42 *)0xFFE71240) /* PWGA9 */
#define PWGA10  (*(volatile struct __tag42 *)0xFFE71280) /* PWGA10 */
#define PWGA11  (*(volatile struct __tag42 *)0xFFE712C0) /* PWGA11 */
#define PWGA12  (*(volatile struct __tag42 *)0xFFE71300) /* PWGA12 */
#define PWGA13  (*(volatile struct __tag42 *)0xFFE71340) /* PWGA13 */
#define PWGA14  (*(volatile struct __tag42 *)0xFFE71380) /* PWGA14 */
#define PWGA15  (*(volatile struct __tag42 *)0xFFE713C0) /* PWGA15 */
#define PWGA16  (*(volatile struct __tag42 *)0xFFE71400) /* PWGA16 */
#define PWGA17  (*(volatile struct __tag42 *)0xFFE71440) /* PWGA17 */
#define PWGA18  (*(volatile struct __tag42 *)0xFFE71480) /* PWGA18 */
#define PWGA19  (*(volatile struct __tag42 *)0xFFE714C0) /* PWGA19 */
#define PWGA20  (*(volatile struct __tag42 *)0xFFE71500) /* PWGA20 */
#define PWGA21  (*(volatile struct __tag42 *)0xFFE71540) /* PWGA21 */
#define PWGA22  (*(volatile struct __tag42 *)0xFFE71580) /* PWGA22 */
#define PWGA23  (*(volatile struct __tag42 *)0xFFE715C0) /* PWGA23 */
#define PWGA24  (*(volatile struct __tag42 *)0xFFE71600) /* PWGA24 */
#define PWGA25  (*(volatile struct __tag42 *)0xFFE71640) /* PWGA25 */
#define PWGA26  (*(volatile struct __tag42 *)0xFFE71680) /* PWGA26 */
#define PWGA27  (*(volatile struct __tag42 *)0xFFE716C0) /* PWGA27 */
#define PWGA28  (*(volatile struct __tag42 *)0xFFE71700) /* PWGA28 */
#define PWGA29  (*(volatile struct __tag42 *)0xFFE71740) /* PWGA29 */
#define PWGA30  (*(volatile struct __tag42 *)0xFFE71780) /* PWGA30 */
#define PWGA31  (*(volatile struct __tag42 *)0xFFE717C0) /* PWGA31 */
#define PWGA32  (*(volatile struct __tag42 *)0xFFE71800) /* PWGA32 */
#define PWGA33  (*(volatile struct __tag42 *)0xFFE71840) /* PWGA33 */
#define PWGA34  (*(volatile struct __tag42 *)0xFFE71880) /* PWGA34 */
#define PWGA35  (*(volatile struct __tag42 *)0xFFE718C0) /* PWGA35 */
#define PWGA36  (*(volatile struct __tag42 *)0xFFE71900) /* PWGA36 */
#define PWGA37  (*(volatile struct __tag42 *)0xFFE71940) /* PWGA37 */
#define PWGA38  (*(volatile struct __tag42 *)0xFFE71980) /* PWGA38 */
#define PWGA39  (*(volatile struct __tag42 *)0xFFE719C0) /* PWGA39 */
#define PWGA40  (*(volatile struct __tag42 *)0xFFE71A00) /* PWGA40 */
#define PWGA41  (*(volatile struct __tag42 *)0xFFE71A40) /* PWGA41 */
#define PWGA42  (*(volatile struct __tag42 *)0xFFE71A80) /* PWGA42 */
#define PWGA43  (*(volatile struct __tag42 *)0xFFE71AC0) /* PWGA43 */
#define PWGA44  (*(volatile struct __tag42 *)0xFFE71B00) /* PWGA44 */
#define PWGA45  (*(volatile struct __tag42 *)0xFFE71B40) /* PWGA45 */
#define PWGA46  (*(volatile struct __tag42 *)0xFFE71B80) /* PWGA46 */
#define PWGA47  (*(volatile struct __tag42 *)0xFFE71BC0) /* PWGA47 */
#define PWGA48  (*(volatile struct __tag42 *)0xFFE71C00) /* PWGA48 */
#define PWGA49  (*(volatile struct __tag42 *)0xFFE71C40) /* PWGA49 */
#define PWGA50  (*(volatile struct __tag42 *)0xFFE71C80) /* PWGA50 */
#define PWGA51  (*(volatile struct __tag42 *)0xFFE71CC0) /* PWGA51 */
#define PWGA52  (*(volatile struct __tag42 *)0xFFE71D00) /* PWGA52 */
#define PWGA53  (*(volatile struct __tag42 *)0xFFE71D40) /* PWGA53 */
#define PWGA54  (*(volatile struct __tag42 *)0xFFE71D80) /* PWGA54 */
#define PWGA55  (*(volatile struct __tag42 *)0xFFE71DC0) /* PWGA55 */
#define PWGA56  (*(volatile struct __tag42 *)0xFFE71E00) /* PWGA56 */
#define PWGA57  (*(volatile struct __tag42 *)0xFFE71E40) /* PWGA57 */
#define PWGA58  (*(volatile struct __tag42 *)0xFFE71E80) /* PWGA58 */
#define PWGA59  (*(volatile struct __tag42 *)0xFFE71EC0) /* PWGA59 */
#define PWGA60  (*(volatile struct __tag42 *)0xFFE71F00) /* PWGA60 */
#define PWGA61  (*(volatile struct __tag42 *)0xFFE71F40) /* PWGA61 */
#define PWGA62  (*(volatile struct __tag42 *)0xFFE71F80) /* PWGA62 */
#define PWGA63  (*(volatile struct __tag42 *)0xFFE71FC0) /* PWGA63 */
#define PWGA64  (*(volatile struct __tag42 *)0xFFE72000) /* PWGA64 */
#define PWGA65  (*(volatile struct __tag42 *)0xFFE72040) /* PWGA65 */
#define PWGA66  (*(volatile struct __tag42 *)0xFFE72080) /* PWGA66 */
#define PWGA67  (*(volatile struct __tag42 *)0xFFE720C0) /* PWGA67 */
#define PWGA68  (*(volatile struct __tag42 *)0xFFE72100) /* PWGA68 */
#define PWGA69  (*(volatile struct __tag42 *)0xFFE72140) /* PWGA69 */
#define PWGA70  (*(volatile struct __tag42 *)0xFFE72180) /* PWGA70 */
#define PWGA71  (*(volatile struct __tag42 *)0xFFE721C0) /* PWGA71 */
#define PWBA0   (*(volatile struct __tag43 *)0xFFE72800) /* PWBA0 */
#define RTCA0   (*(volatile struct __tag44 *)0xFFE78000) /* RTCA0 */
#define ENCA0   (*(volatile struct __tag45 *)0xFFE80000) /* ENCA0 */
#define TAPA0   (*(volatile struct __tag46 *)0xFFE90000) /* TAPA0 */
#define OSTM0   (*(volatile struct __tag47 *)0xFFEC0000) /* OSTM0 */
#define WDTA0   (*(volatile struct __tag48 *)0xFFED0000) /* WDTA0 */
#define WDTA1   (*(volatile struct __tag48 *)0xFFED1000) /* WDTA1 */
#define ADCA0   (*(volatile struct __tag49 *)0xFFF20000) /* ADCA0 */
#define ADCA1   (*(volatile struct __tag50 *)0xFFF21000) /* ADCA1 */
#define DCRA0   (*(volatile struct __tag51 *)0xFFF70000) /* DCRA0 */
#define DCRA1   (*(volatile struct __tag51 *)0xFFF71000) /* DCRA1 */
#define DCRA2   (*(volatile struct __tag51 *)0xFFF72000) /* DCRA2 */
#define DCRA3   (*(volatile struct __tag51 *)0xFFF73000) /* DCRA3 */
#define KR0     (*(volatile struct __tag52 *)0xFFF78000) /* KR0 */
#define CLMA0   (*(volatile struct __tag53 *)0xFFF8C000) /* CLMA0 */
#define CLMA    (*(volatile struct __tag54 *)0xFFF8C100) /* CLMA */
#define CLMA1   (*(volatile struct __tag53 *)0xFFF8D000) /* CLMA1 */
#define CLMA2   (*(volatile struct __tag53 *)0xFFF8E000) /* CLMA2 */

/* IOR List *
FLMDCNT
FLMDPCMD
FLMDPS
SELB_TAUJ0I
SELB_TAUD0I
SELB_INTC1
SELB_INTC2
SELB_READTEST
SLPWGA0 ... SLPWGA2
SCTLR
EVFR
DPSELR0
DPSELRM
DPSELRML
DPSELR1
DPSELR2
DPSELRMH
DPSELR3
DPSELR4
DPSELRH
DPSELRHL
DPSELR5
DPSELR6
DPSELRHH
DPSELR7
DPDSR0
DPDSRM
DPDSRML
DPDSR1
DPDSR2
DPDSRMH
DPDSR3
DPDSR4
DPDSRH
DPDSRHL
DPDSR5
DPDSR6
DPDSRHH
DPDSR7
DPDIMR0 ... DPDIMR7
CNTVAL
SOSTR
P0 ... P2
P8 ... P12
P18
P20
AP0
AP1
PSR0 ... PSR2
PSR8 ... PSR12
PSR18
PSR20
APSR0
APSR1
PPR0 ... PPR2
PPR8 ... PPR12
PPR18
PPR20
APPR0
APPR1
IPPR0
PM0 ... PM2
PM8 ... PM12
PM18
PM20
APM0
APM1
PMC0 ... PMC2
PMC8 ... PMC12
PMC18
PMC20
PFC0
PFC1
PFC8 ... PFC12
PFC18
PFC20
PFCE0
PFCE8 ... PFCE12
PNOT0 ... PNOT2
PNOT8 ... PNOT12
PNOT18
PNOT20
APNOT0
APNOT1
PMSR0 ... PMSR2
PMSR8 ... PMSR12
PMSR18
PMSR20
APMSR0
APMSR1
PMCSR0 ... PMCSR2
PMCSR8 ... PMCSR12
PMCSR18
PMCSR20
PFCAE0
PFCAE10
PFCAE11
PIBC0 ... PIBC2
PIBC8 ... PIBC12
PIBC18
PIBC20
APIBC0
APIBC1
IPIBC0
PBDC0 ... PBDC2
PBDC8 ... PBDC12
PBDC18
PBDC20
APBDC0
APBDC1
PIPC0
PIPC10
PIPC11
PU0 ... PU2
PU8 ... PU12
PU18
PU20
PD0
PD8 ... PD11
PODC0 ... PODC2
PODC8 ... PODC12
PODC18
PODC20
PDSC0
PDSC10 ... PDSC12
PIS0 ... PIS2
PIS10 ... PIS12
PIS20
PPROTS0 ... PPROTS2
PPROTS8 ... PPROTS12
PPROTS18
PPROTS20
PPCMD0 ... PPCMD2
PPCMD8 ... PPCMD12
PPCMD18
PPCMD20
JP0
JPSR0
JPPR0
JPM0
JPMC0
JPFC0
JPNOT0
JPMSR0
JPMCSR0
JPIBC0
JPBDC0
JPU0
JPD0
JPODC0
JPISA0
JPPROTS0
JPPCMD0
DNFATAUD0ICTL
DNFATAUD0IEN
DNFATAUD0IENH
DNFATAUD0IENH0 ... DNFATAUD0IENH7
DNFATAUD0IENL
DNFATAUD0IENL0 ... DNFATAUD0IENL7
DNFATAUB0ICTL
DNFATAUB0IEN
DNFATAUB0IENH
DNFATAUB0IENH0 ... DNFATAUB0IENH7
DNFATAUB0IENL
DNFATAUB0IENL0 ... DNFATAUB0IENL7
DNFATAUB1ICTL
DNFATAUB1IEN
DNFATAUB1IENH
DNFATAUB1IENH0 ... DNFATAUB1IENH7
DNFATAUB1IENL
DNFATAUB1IENL0 ... DNFATAUB1IENL7
DNFAENCA0ICTL
DNFAENCA0IEN
DNFAENCA0IENL
DNFAENCA0IENL0 ... DNFAENCA0IENL4
DNFAADCTL0CTL
DNFAADCTL0EN
DNFAADCTL0ENL
DNFAADCTL0ENL0 ... DNFAADCTL0ENL2
DNFAADCTL1CTL
DNFAADCTL1EN
DNFAADCTL1ENL
DNFAADCTL1ENL0 ... DNFAADCTL1ENL2
FCLA0CTL0_NMI
FCLA0CTL0_INTPL
FCLA0CTL1_INTPL
FCLA0CTL2_INTPL
FCLA0CTL3_INTPL
FCLA0CTL4_INTPL
FCLA0CTL5_INTPL
FCLA0CTL6_INTPL
FCLA0CTL7_INTPL
FCLA0CTL0_INTPH
FCLA0CTL1_INTPH
FCLA0CTL2_INTPH
FCLA0CTL3_INTPH
FCLA0CTL4_INTPH
FCLA0CTL5_INTPH
FCLA0CTL6_INTPH
FCLA0CTL7_INTPH
FCLA0CTL0_ADC0
FCLA0CTL1_ADC0
FCLA0CTL2_ADC0
FCLA0CTL0_ADC1
FCLA0CTL1_ADC1
FCLA0CTL2_ADC1
EEPRDCYCL
CFECCCTL
CFFSTERSTR
CFFSTSTC
CFOVFSTR
CFOVFSTC
CFERRINT
CFFSTEADR
CFTSTCTL
LRECCCTL
LRFSTERSTR
LRSTCLR
LROVFSTR
LROVFSTC
LRFSTEADR0
LRERRINT
LRTSTCTL
LRTDATBF0
DFECCCTL
DFERSTR
DFERSTC
DFERRINT
DFTSTCTL
ECCCSIH0CTL
ECCCSIH0TMC
ECCCSIH0TRC
ECCCSIH0ERDB
ECCCSIH0ECRD
ECCCSIH0HORD
ECCCSIH0SYND
ECCCSIH0TED
ECCCSIH1CTL
ECCCSIH1TMC
ECCCSIH1TRC
ECCCSIH1ERDB
ECCCSIH1ECRD
ECCCSIH1HORD
ECCCSIH1SYND
ECCCSIH1TED
ECCCSIH2CTL
ECCCSIH2TMC
ECCCSIH2TRC
ECCCSIH2ERDB
ECCCSIH2ECRD
ECCCSIH2HORD
ECCCSIH2SYND
ECCCSIH2TED
ECCCSIH3CTL
ECCCSIH3TMC
ECCCSIH3TRC
ECCCSIH3ERDB
ECCCSIH3ECRD
ECCCSIH3HORD
ECCCSIH3SYND
ECCCSIH3TED
ECCRCAN0CTL
ECCRCAN0TMC
ECCRCAN0TRC
ECCRCAN0ERDB
ECCRCAN0ECRD
ECCRCAN0HORD
ECCRCAN0SYND
ECCRCAN0TED
CVMF
CVMDE
CVMDIAG
PROTCMDCVM
PROTSCVM
PROTCMD0
PROTS0
STBC0PSC
STBC0STPT
WDTNMIF
WDTNMIFC
FEINTF
FEINTFMSK
FEINTFC
WUF0
WUFMSK0
WUFC0
WUF20
WUFMSK20
WUFC20
RESF
RESFC
RESFR
RESFCR
VLVF
VLVFC
LVICNT
SWRESA
IOHOLD
ROSCE
ROSCS
ROSCSTPM
MOSCE
MOSCS
MOSCC
MOSCST
MOSCSTPM
SOSCE
SOSCS
SOSCST
CKSC_AWDTAD_CTL
CKSC_AWDTAD_ACT
CKSC_AWDTAD_STPM
CKSC_ATAUJS_CTL
CKSC_ATAUJS_ACT
CKSC_ATAUJD_CTL
CKSC_ATAUJD_ACT
CKSC_ATAUJD_STPM
CKSC_ARTCAS_CTL
CKSC_ARTCAS_ACT
CKSC_ARTCAD_CTL
CKSC_ARTCAD_ACT
CKSC_ARTCAD_STPM
CKSC_AADCAS_CTL
CKSC_AADCAS_ACT
CKSC_AADCAD_CTL
CKSC_AADCAD_ACT
CKSC_AADCAD_STPM
CKSC_AFOUTS_CTL
CKSC_AFOUTS_ACT
CKSC_AFOUTS_STPM
FOUTDIV
FOUTSTAT
PROTCMD1
PROTS1
WUF_ISO0
WUFMSK_ISO0
WUFC_ISO0
PLLE
PLLS
PLLC
CKSC_CPUCLKS_CTL
CKSC_CPUCLKS_ACT
CKSC_CPUCLKD_CTL
CKSC_CPUCLKD_ACT
CKSC_IPERI1S_CTL
CKSC_IPERI1S_ACT
CKSC_IPERI2S_CTL
CKSC_IPERI2S_ACT
CKSC_ILINS_CTL
CKSC_ILINS_ACT
CKSC_IADCAS_CTL
CKSC_IADCAS_ACT
CKSC_IADCAD_CTL
CKSC_IADCAD_ACT
CKSC_ILIND_CTL
CKSC_ILIND_ACT
CKSC_ILIND_STPM
CKSC_ICANS_CTL
CKSC_ICANS_ACT
CKSC_ICANS_STPM
CKSC_ICANOSCD_CTL
CKSC_ICANOSCD_ACT
CKSC_ICANOSCD_STPM
CKSC_ICSIS_CTL
CKSC_ICSIS_ACT
PROTCMDCLMA
PROTSCLMA
BSC
DEC
DWC
DHC
AWC
ICC
DTRC0
DTRC0ADS
DTRC0ERR
DMCM0
DSA0
DSA0L
DSA0H
DDA0
DDA0L
DDA0H
DTC0
DTCT0
DTS0
DTS0DTE
DTS0SR
DTS0DR
DTS0ER
DTS0DT
DTS0TC
DSA1
DSA1L
DSA1H
DDA1
DDA1L
DDA1H
DTC1
DTCT1
DTS1
DTS1DTE
DTS1SR
DTS1DR
DTS1ER
DTS1DT
DTS1TC
DSA2
DSA2L
DSA2H
DDA2
DDA2L
DDA2H
DTC2
DTCT2
DTS2
DTS2DTE
DTS2SR
DTS2DR
DTS2ER
DTS2DT
DTS2TC
DSA3
DSA3L
DSA3H
DDA3
DDA3L
DDA3H
DTC3
DTCT3
DTS3
DTS3DTE
DTS3SR
DTS3DR
DTS3ER
DTS3DT
DTS3TC
DSA4
DSA4L
DSA4H
DDA4
DDA4L
DDA4H
DTC4
DTCT4
DTS4
DTS4DTE
DTS4SR
DTS4DR
DTS4ER
DTS4DT
DTS4TC
DSA5
DSA5L
DSA5H
DDA5
DDA5L
DDA5H
DTC5
DTCT5
DTS5
DTS5DTE
DTS5SR
DTS5DR
DTS5ER
DTS5DT
DTS5TC
DSA6
DSA6L
DSA6H
DDA6
DDA6L
DDA6H
DTC6
DTCT6
DTS6
DTS6DTE
DTS6SR
DTS6DR
DTS6ER
DTS6DT
DTS6TC
DSA7
DSA7L
DSA7H
DDA7
DDA7L
DDA7H
DTC7
DTCT7
DTS7
DTS7DTE
DTS7SR
DTS7DR
DTS7ER
DTS7DT
DTS7TC
DSA8
DSA8L
DSA8H
DDA8
DDA8L
DDA8H
DTC8
DTCT8
DTS8
DTS8DTE
DTS8SR
DTS8DR
DTS8ER
DTS8DT
DTS8TC
DSA9
DSA9L
DSA9H
DDA9
DDA9L
DDA9H
DTC9
DTCT9
DTS9
DTS9DTE
DTS9SR
DTS9DR
DTS9ER
DTS9DT
DTS9TC
DSA10
DSA10L
DSA10H
DDA10
DDA10L
DDA10H
DTC10
DTCT10
DTS10
DTS10DTE
DTS10SR
DTS10DR
DTS10ER
DTS10DT
DTS10TC
DSA11
DSA11L
DSA11H
DDA11
DDA11L
DDA11H
DTC11
DTCT11
DTS11
DTS11DTE
DTS11SR
DTS11DR
DTS11ER
DTS11DT
DTS11TC
DSA12
DSA12L
DSA12H
DDA12
DDA12L
DDA12H
DTC12
DTCT12
DTS12
DTS12DTE
DTS12SR
DTS12DR
DTS12ER
DTS12DT
DTS12TC
DSA13
DSA13L
DSA13H
DDA13
DDA13L
DDA13H
DTC13
DTCT13
DTS13
DTS13DTE
DTS13SR
DTS13DR
DTS13ER
DTS13DT
DTS13TC
DSA14
DSA14L
DSA14H
DDA14
DDA14L
DDA14H
DTC14
DTCT14
DTS14
DTS14DTE
DTS14SR
DTS14DR
DTS14ER
DTS14DT
DTS14TC
DSA15
DSA15L
DSA15H
DDA15
DDA15L
DDA15H
DTC15
DTCT15
DTS15
DTS15DTE
DTS15SR
DTS15DR
DTS15ER
DTS15DT
DTS15TC
DTFR0 ... DTFR15
DRQCLR
DRQSTR
SEG_CONT
SEG_CONTL
SEG_CONTROME
SEG_CONTEXTE
SEG_CONTRAME
SEG_CONTRMWE
SEG_CONTDMAE
SEG_FLAG
SEG_FLAGL
SEG_FLAGROMF
SEG_FLAGEXTF
SEG_FLAGRAMF
SEG_FLAGRMWF
SEG_FLAGDMAF
ICCSIH2IC_1
ICTAUD0I0
ICCSIH2ICL_1
ICTAUD0I0L
ICCSIH2ICH_1
ICTAUD0I0H
P0CSIH2IC_1
P0TAUD0I0
P1CSIH2IC_1
P1TAUD0I0
P2CSIH2IC_1
P2TAUD0I0
TBCSIH2IC_1
TBTAUD0I0
MKCSIH2IC_1
MKTAUD0I0
RFCSIH2IC_1
RFTAUD0I0
CTCSIH2IC_1
CTTAUD0I0
ICCSIH3IC_1
ICTAUD0I2
ICCSIH3ICL_1
ICTAUD0I2L
ICCSIH3ICH_1
ICTAUD0I2H
P0CSIH3IC_1
P0TAUD0I2
P1CSIH3IC_1
P1TAUD0I2
P2CSIH3IC_1
P2TAUD0I2
TBCSIH3IC_1
TBTAUD0I2
MKCSIH3IC_1
MKTAUD0I2
RFCSIH3IC_1
RFTAUD0I2
CTCSIH3IC_1
CTTAUD0I2
ICTAUD0I4
ICTAUD0I4L
ICTAUD0I4H
P0TAUD0I4
P1TAUD0I4
P2TAUD0I4
TBTAUD0I4
MKTAUD0I4
RFTAUD0I4
CTTAUD0I4
ICTAUD0I6
ICTAUD0I6L
ICTAUD0I6H
P0TAUD0I6
P1TAUD0I6
P2TAUD0I6
TBTAUD0I6
MKTAUD0I6
RFTAUD0I6
CTTAUD0I6
ICTAUD0I8
ICTAUD0I8L
ICTAUD0I8H
P0TAUD0I8
P1TAUD0I8
P2TAUD0I8
TBTAUD0I8
MKTAUD0I8
RFTAUD0I8
CTTAUD0I8
ICCSIH3IR_1
ICTAUD0I10
ICCSIH3IRL_1
ICTAUD0I10L
ICCSIH3IRH_1
ICTAUD0I10H
P0CSIH3IR_1
P0TAUD0I10
P1CSIH3IR_1
P1TAUD0I10
P2CSIH3IR_1
P2TAUD0I10
TBCSIH3IR_1
TBTAUD0I10
MKCSIH3IR_1
MKTAUD0I10
RFCSIH3IR_1
RFTAUD0I10
CTCSIH3IR_1
CTTAUD0I10
ICCSIH3IRE_1
ICTAUD0I12
ICCSIH3IREL_1
ICTAUD0I12L
ICCSIH3IREH_1
ICTAUD0I12H
P0CSIH3IRE_1
P0TAUD0I12
P1CSIH3IRE_1
P1TAUD0I12
P2CSIH3IRE_1
P2TAUD0I12
TBCSIH3IRE_1
TBTAUD0I12
MKCSIH3IRE_1
MKTAUD0I12
RFCSIH3IRE_1
RFTAUD0I12
CTCSIH3IRE_1
CTTAUD0I12
ICCSIH3IJC_1
ICTAUD0I14
ICCSIH3IJCL_1
ICTAUD0I14L
ICCSIH3IJCH_1
ICTAUD0I14H
P0CSIH3IJC_1
P0TAUD0I14
P1CSIH3IJC_1
P1TAUD0I14
P2CSIH3IJC_1
P2TAUD0I14
TBCSIH3IJC_1
TBTAUD0I14
MKCSIH3IJC_1
MKTAUD0I14
RFCSIH3IJC_1
RFTAUD0I14
CTCSIH3IJC_1
CTTAUD0I14
ICCSIH1IC_1
ICTAPA0IPEK0
ICCSIH1ICL_1
ICTAPA0IPEK0L
ICCSIH1ICH_1
ICTAPA0IPEK0H
P0CSIH1IC_1
P0TAPA0IPEK0
P1CSIH1IC_1
P1TAPA0IPEK0
P2CSIH1IC_1
P2TAPA0IPEK0
TBCSIH1IC_1
TBTAPA0IPEK0
MKCSIH1IC_1
MKTAPA0IPEK0
RFCSIH1IC_1
RFTAPA0IPEK0
CTCSIH1IC_1
CTTAPA0IPEK0
ICCSIH1IR_1
ICTAPA0IVLY0
ICCSIH1IRL_1
ICTAPA0IVLY0L
ICCSIH1IRH_1
ICTAPA0IVLY0H
P0CSIH1IR_1
P0TAPA0IVLY0
P1CSIH1IR_1
P1TAPA0IVLY0
P2CSIH1IR_1
P2TAPA0IVLY0
TBCSIH1IR_1
TBTAPA0IVLY0
MKCSIH1IR_1
MKTAPA0IVLY0
RFCSIH1IR_1
RFTAPA0IVLY0
CTCSIH1IR_1
CTTAPA0IVLY0
ICADCA0I0
ICADCA0I0L
ICADCA0I0H
P0ADCA0I0
P1ADCA0I0
P2ADCA0I0
TBADCA0I0
MKADCA0I0
RFADCA0I0
CTADCA0I0
ICADCA0I1
ICADCA0I1L
ICADCA0I1H
P0ADCA0I1
P1ADCA0I1
P2ADCA0I1
TBADCA0I1
MKADCA0I1
RFADCA0I1
CTADCA0I1
ICADCA0I2
ICADCA0I2L
ICADCA0I2H
P0ADCA0I2
P1ADCA0I2
P2ADCA0I2
TBADCA0I2
MKADCA0I2
RFADCA0I2
CTADCA0I2
ICDCUTDI
ICDCUTDIL
ICDCUTDIH
P0DCUTDI
P1DCUTDI
P2DCUTDI
TBDCUTDI
MKDCUTDI
RFDCUTDI
CTDCUTDI
ICRCANGERR
ICRCANGERRL
ICRCANGERRH
P0RCANGERR
P1RCANGERR
P2RCANGERR
TBRCANGERR
MKRCANGERR
RFRCANGERR
CTRCANGERR
ICRCANGRECC
ICRCANGRECCL
ICRCANGRECCH
P0RCANGRECC
P1RCANGRECC
P2RCANGRECC
TBRCANGRECC
MKRCANGRECC
RFRCANGRECC
CTRCANGRECC
ICRCAN0ERR
ICRCAN0ERRL
ICRCAN0ERRH
P0RCAN0ERR
P1RCAN0ERR
P2RCAN0ERR
TBRCAN0ERR
MKRCAN0ERR
RFRCAN0ERR
CTRCAN0ERR
ICRCAN0REC
ICRCAN0RECL
ICRCAN0RECH
P0RCAN0REC
P1RCAN0REC
P2RCAN0REC
TBRCAN0REC
MKRCAN0REC
RFRCAN0REC
CTRCAN0REC
ICRCAN0TRX
ICRCAN0TRXL
ICRCAN0TRXH
P0RCAN0TRX
P1RCAN0TRX
P2RCAN0TRX
TBRCAN0TRX
MKRCAN0TRX
RFRCAN0TRX
CTRCAN0TRX
ICCSIG0IC
ICCSIH1IRE_1
ICCSIG0ICL
ICCSIH1IREL_1
ICCSIG0ICH
ICCSIH1IREH_1
P0CSIG0IC
P0CSIH1IRE_1
P1CSIG0IC
P1CSIH1IRE_1
P2CSIG0IC
P2CSIH1IRE_1
TBCSIG0IC
TBCSIH1IRE_1
MKCSIG0IC
MKCSIH1IRE_1
RFCSIG0IC
RFCSIH1IRE_1
CTCSIG0IC
CTCSIH1IRE_1
ICCSIG0IR
ICCSIH1IJC_1
ICCSIG0IRL
ICCSIH1IJCL_1
ICCSIG0IRH
ICCSIH1IJCH_1
P0CSIG0IR
P0CSIH1IJC_1
P1CSIG0IR
P1CSIH1IJC_1
P2CSIG0IR
P2CSIH1IJC_1
TBCSIG0IR
TBCSIH1IJC_1
MKCSIG0IR
MKCSIH1IJC_1
RFCSIG0IR
RFCSIH1IJC_1
CTCSIG0IR
CTCSIH1IJC_1
ICCSIH0IC
ICCSIH0ICL
ICCSIH0ICH
P0CSIH0IC
P1CSIH0IC
P2CSIH0IC
TBCSIH0IC
MKCSIH0IC
RFCSIH0IC
CTCSIH0IC
ICCSIH0IR
ICCSIH0IRL
ICCSIH0IRH
P0CSIH0IR
P1CSIH0IR
P2CSIH0IR
TBCSIH0IR
MKCSIH0IR
RFCSIH0IR
CTCSIH0IR
ICCSIH0IRE
ICCSIH0IREL
ICCSIH0IREH
P0CSIH0IRE
P1CSIH0IRE
P2CSIH0IRE
TBCSIH0IRE
MKCSIH0IRE
RFCSIH0IRE
CTCSIH0IRE
ICCSIH0IJC
ICCSIH0IJCL
ICCSIH0IJCH
P0CSIH0IJC
P1CSIH0IJC
P2CSIH0IJC
TBCSIH0IJC
MKCSIH0IJC
RFCSIH0IJC
CTCSIH0IJC
ICRLIN30
ICRLIN30L
ICRLIN30H
P0RLIN30
P1RLIN30
P2RLIN30
TBRLIN30
MKRLIN30
RFRLIN30
CTRLIN30
ICRLIN30UR0
ICRLIN30UR0L
ICRLIN30UR0H
P0RLIN30UR0
P1RLIN30UR0
P2RLIN30UR0
TBRLIN30UR0
MKRLIN30UR0
RFRLIN30UR0
CTRLIN30UR0
ICRLIN30UR1
ICRLIN30UR1L
ICRLIN30UR1H
P0RLIN30UR1
P1RLIN30UR1
P2RLIN30UR1
TBRLIN30UR1
MKRLIN30UR1
RFRLIN30UR1
CTRLIN30UR1
ICRLIN30UR2
ICRLIN30UR2L
ICRLIN30UR2H
P0RLIN30UR2
P1RLIN30UR2
P2RLIN30UR2
TBRLIN30UR2
MKRLIN30UR2
RFRLIN30UR2
CTRLIN30UR2
ICCSIH2IR_1
ICP0
ICCSIH2IRL_1
ICP0L
ICCSIH2IRH_1
ICP0H
P0CSIH2IR_1
P0P0
P1CSIH2IR_1
P1P0
P2CSIH2IR_1
P2P0
TBCSIH2IR_1
TBP0
MKCSIH2IR_1
MKP0
RFCSIH2IR_1
RFP0
CTCSIH2IR_1
CTP0
ICCSIH2IRE_1
ICP1
ICCSIH2IREL_1
ICP1L
ICCSIH2IREH_1
ICP1H
P0CSIH2IRE_1
P0P1
P1CSIH2IRE_1
P1P1
P2CSIH2IRE_1
P2P1
TBCSIH2IRE_1
TBP1
MKCSIH2IRE_1
MKP1
RFCSIH2IRE_1
RFP1
CTCSIH2IRE_1
CTP1
ICCSIH2IJC_1
ICP2
ICCSIH2IJCL_1
ICP2L
ICCSIH2IJCH_1
ICP2H
P0CSIH2IJC_1
P0P2
P1CSIH2IJC_1
P1P2
P2CSIH2IJC_1
P2P2
TBCSIH2IJC_1
TBP2
MKCSIH2IJC_1
MKP2
RFCSIH2IJC_1
RFP2
CTCSIH2IJC_1
CTP2
FNC
FNCH
FNRF
FIC
FICH
FIRF
IMR0
IMR0L
IMR0LL
IMR0LH
IMR0H
IMR0HL
IMR0HH
IMR0EIMK0 ... IMR0EIMK31
ICWDTA0
ICWDTA0L
ICWDTA0H
P0WDTA0
P1WDTA0
P2WDTA0
TBWDTA0
MKWDTA0
RFWDTA0
CTWDTA0
ICWDTA1
ICWDTA1L
ICWDTA1H
P0WDTA1
P1WDTA1
P2WDTA1
TBWDTA1
MKWDTA1
RFWDTA1
CTWDTA1
ICP3
ICP3L
ICP3H
P0P3
P1P3
P2P3
TBP3
MKP3
RFP3
CTP3
ICP4
ICP4L
ICP4H
P0P4
P1P4
P2P4
TBP4
MKP4
RFP4
CTP4
ICP5
ICP5L
ICP5H
P0P5
P1P5
P2P5
TBP5
MKP5
RFP5
CTP5
ICP10
ICP10L
ICP10H
P0P10
P1P10
P2P10
TBP10
MKP10
RFP10
CTP10
ICP11
ICP11L
ICP11H
P0P11
P1P11
P2P11
TBP11
MKP11
RFP11
CTP11
ICTAUD0I1
ICTAUD0I1L
ICTAUD0I1H
P0TAUD0I1
P1TAUD0I1
P2TAUD0I1
TBTAUD0I1
MKTAUD0I1
RFTAUD0I1
CTTAUD0I1
ICTAUD0I3
ICTAUD0I3L
ICTAUD0I3H
P0TAUD0I3
P1TAUD0I3
P2TAUD0I3
TBTAUD0I3
MKTAUD0I3
RFTAUD0I3
CTTAUD0I3
ICTAUD0I5
ICTAUD0I5L
ICTAUD0I5H
P0TAUD0I5
P1TAUD0I5
P2TAUD0I5
TBTAUD0I5
MKTAUD0I5
RFTAUD0I5
CTTAUD0I5
ICTAUD0I7
ICTAUD0I7L
ICTAUD0I7H
P0TAUD0I7
P1TAUD0I7
P2TAUD0I7
TBTAUD0I7
MKTAUD0I7
RFTAUD0I7
CTTAUD0I7
ICTAUD0I9
ICTAUD0I9L
ICTAUD0I9H
P0TAUD0I9
P1TAUD0I9
P2TAUD0I9
TBTAUD0I9
MKTAUD0I9
RFTAUD0I9
CTTAUD0I9
ICTAUD0I11
ICTAUD0I11L
ICTAUD0I11H
P0TAUD0I11
P1TAUD0I11
P2TAUD0I11
TBTAUD0I11
MKTAUD0I11
RFTAUD0I11
CTTAUD0I11
ICTAUD0I13
ICTAUD0I13L
ICTAUD0I13H
P0TAUD0I13
P1TAUD0I13
P2TAUD0I13
TBTAUD0I13
MKTAUD0I13
RFTAUD0I13
CTTAUD0I13
ICTAUD0I15
ICTAUD0I15L
ICTAUD0I15H
P0TAUD0I15
P1TAUD0I15
P2TAUD0I15
TBTAUD0I15
MKTAUD0I15
RFTAUD0I15
CTTAUD0I15
ICADCA0ERR
ICADCA0ERRL
ICADCA0ERRH
P0ADCA0ERR
P1ADCA0ERR
P2ADCA0ERR
TBADCA0ERR
MKADCA0ERR
RFADCA0ERR
CTADCA0ERR
ICCSIG0IRE
ICCSIG0IREL
ICCSIG0IREH
P0CSIG0IRE
P1CSIG0IRE
P2CSIG0IRE
TBCSIG0IRE
MKCSIG0IRE
RFCSIG0IRE
CTCSIG0IRE
ICRLIN20
ICRLIN20L
ICRLIN20H
P0RLIN20
P1RLIN20
P2RLIN20
TBRLIN20
MKRLIN20
RFRLIN20
CTRLIN20
ICRLIN21
ICRLIN21L
ICRLIN21H
P0RLIN21
P1RLIN21
P2RLIN21
TBRLIN21
MKRLIN21
RFRLIN21
CTRLIN21
ICDMA0
ICDMA0L
ICDMA0H
P0DMA0
P1DMA0
P2DMA0
TBDMA0
MKDMA0
RFDMA0
CTDMA0
ICDMA1
ICDMA1L
ICDMA1H
P0DMA1
P1DMA1
P2DMA1
TBDMA1
MKDMA1
RFDMA1
CTDMA1
ICDMA2
ICDMA2L
ICDMA2H
P0DMA2
P1DMA2
P2DMA2
TBDMA2
MKDMA2
RFDMA2
CTDMA2
ICDMA3
ICDMA3L
ICDMA3H
P0DMA3
P1DMA3
P2DMA3
TBDMA3
MKDMA3
RFDMA3
CTDMA3
ICDMA4
ICDMA4L
ICDMA4H
P0DMA4
P1DMA4
P2DMA4
TBDMA4
MKDMA4
RFDMA4
CTDMA4
ICDMA5
ICDMA5L
ICDMA5H
P0DMA5
P1DMA5
P2DMA5
TBDMA5
MKDMA5
RFDMA5
CTDMA5
ICDMA6
ICDMA6L
ICDMA6H
P0DMA6
P1DMA6
P2DMA6
TBDMA6
MKDMA6
RFDMA6
CTDMA6
ICDMA7
ICDMA7L
ICDMA7H
P0DMA7
P1DMA7
P2DMA7
TBDMA7
MKDMA7
RFDMA7
CTDMA7
ICDMA8
ICDMA8L
ICDMA8H
P0DMA8
P1DMA8
P2DMA8
TBDMA8
MKDMA8
RFDMA8
CTDMA8
ICDMA9
ICDMA9L
ICDMA9H
P0DMA9
P1DMA9
P2DMA9
TBDMA9
MKDMA9
RFDMA9
CTDMA9
ICDMA10
ICDMA10L
ICDMA10H
P0DMA10
P1DMA10
P2DMA10
TBDMA10
MKDMA10
RFDMA10
CTDMA10
ICDMA11
ICDMA11L
ICDMA11H
P0DMA11
P1DMA11
P2DMA11
TBDMA11
MKDMA11
RFDMA11
CTDMA11
ICDMA12
ICDMA12L
ICDMA12H
P0DMA12
P1DMA12
P2DMA12
TBDMA12
MKDMA12
RFDMA12
CTDMA12
ICDMA13
ICDMA13L
ICDMA13H
P0DMA13
P1DMA13
P2DMA13
TBDMA13
MKDMA13
RFDMA13
CTDMA13
ICDMA14
ICDMA14L
ICDMA14H
P0DMA14
P1DMA14
P2DMA14
TBDMA14
MKDMA14
RFDMA14
CTDMA14
ICDMA15
ICDMA15L
ICDMA15H
P0DMA15
P1DMA15
P2DMA15
TBDMA15
MKDMA15
RFDMA15
CTDMA15
ICRIIC0TI
ICRIIC0TIL
ICRIIC0TIH
P0RIIC0TI
P1RIIC0TI
P2RIIC0TI
TBRIIC0TI
MKRIIC0TI
RFRIIC0TI
CTRIIC0TI
ICRIIC0TEI
ICRIIC0TEIL
ICRIIC0TEIH
P0RIIC0TEI
P1RIIC0TEI
P2RIIC0TEI
TBRIIC0TEI
MKRIIC0TEI
RFRIIC0TEI
CTRIIC0TEI
ICRIIC0RI
ICRIIC0RIL
ICRIIC0RIH
P0RIIC0RI
P1RIIC0RI
P2RIIC0RI
TBRIIC0RI
MKRIIC0RI
RFRIIC0RI
CTRIIC0RI
ICRIIC0EE
ICRIIC0EEL
ICRIIC0EEH
P0RIIC0EE
P1RIIC0EE
P2RIIC0EE
TBRIIC0EE
MKRIIC0EE
RFRIIC0EE
CTRIIC0EE
ICTAUJ0I0
ICTAUJ0I0L
ICTAUJ0I0H
P0TAUJ0I0
P1TAUJ0I0
P2TAUJ0I0
TBTAUJ0I0
MKTAUJ0I0
RFTAUJ0I0
CTTAUJ0I0
ICTAUJ0I1
ICTAUJ0I1L
ICTAUJ0I1H
P0TAUJ0I1
P1TAUJ0I1
P2TAUJ0I1
TBTAUJ0I1
MKTAUJ0I1
RFTAUJ0I1
CTTAUJ0I1
ICTAUJ0I2
ICTAUJ0I2L
ICTAUJ0I2H
P0TAUJ0I2
P1TAUJ0I2
P2TAUJ0I2
TBTAUJ0I2
MKTAUJ0I2
RFTAUJ0I2
CTTAUJ0I2
ICTAUJ0I3
ICTAUJ0I3L
ICTAUJ0I3H
P0TAUJ0I3
P1TAUJ0I3
P2TAUJ0I3
TBTAUJ0I3
MKTAUJ0I3
RFTAUJ0I3
CTTAUJ0I3
ICOSTM0
ICOSTM0L
ICOSTM0H
P0OSTM0
P1OSTM0
P2OSTM0
TBOSTM0
MKOSTM0
RFOSTM0
CTOSTM0
ICENCA0IOV
ICPWGA4
ICENCA0IOVL
ICPWGA4L
ICENCA0IOVH
ICPWGA4H
P0ENCA0IOV
P0PWGA4
P1ENCA0IOV
P1PWGA4
P2ENCA0IOV
P2PWGA4
TBENCA0IOV
TBPWGA4
MKENCA0IOV
MKPWGA4
RFENCA0IOV
RFPWGA4
CTENCA0IOV
CTPWGA4
ICENCA0IUD
ICPWGA5
ICENCA0IUDL
ICPWGA5L
ICENCA0IUDH
ICPWGA5H
P0ENCA0IUD
P0PWGA5
P1ENCA0IUD
P1PWGA5
P2ENCA0IUD
P2PWGA5
TBENCA0IUD
TBPWGA5
MKENCA0IUD
MKPWGA5
RFENCA0IUD
RFPWGA5
CTENCA0IUD
CTPWGA5
ICENCA0I0
ICPWGA6
ICENCA0I0L
ICPWGA6L
ICENCA0I0H
ICPWGA6H
P0ENCA0I0
P0PWGA6
P1ENCA0I0
P1PWGA6
P2ENCA0I0
P2PWGA6
TBENCA0I0
TBPWGA6
MKENCA0I0
MKPWGA6
RFENCA0I0
RFPWGA6
CTENCA0I0
CTPWGA6
ICENCA0I1
ICPWGA7
ICENCA0I1L
ICPWGA7L
ICENCA0I1H
ICPWGA7H
P0ENCA0I1
P0PWGA7
P1ENCA0I1
P1PWGA7
P2ENCA0I1
P2PWGA7
TBENCA0I1
TBPWGA7
MKENCA0I1
MKPWGA7
RFENCA0I1
RFPWGA7
CTENCA0I1
CTPWGA7
ICENCA0IEC
ICENCA0IECL
ICENCA0IECH
P0ENCA0IEC
P1ENCA0IEC
P2ENCA0IEC
TBENCA0IEC
MKENCA0IEC
RFENCA0IEC
CTENCA0IEC
ICKR0
ICKR0L
ICKR0H
P0KR0
P1KR0
P2KR0
TBKR0
MKKR0
RFKR0
CTKR0
ICQFULL
ICQFULLL
ICQFULLH
P0QFULL
P1QFULL
P2QFULL
TBQFULL
MKQFULL
RFQFULL
CTQFULL
ICPWGA0
ICPWGA0L
ICPWGA0H
P0PWGA0
P1PWGA0
P2PWGA0
TBPWGA0
MKPWGA0
RFPWGA0
CTPWGA0
ICPWGA1
ICPWGA1L
ICPWGA1H
P0PWGA1
P1PWGA1
P2PWGA1
TBPWGA1
MKPWGA1
RFPWGA1
CTPWGA1
ICPWGA2
ICPWGA2L
ICPWGA2H
P0PWGA2
P1PWGA2
P2PWGA2
TBPWGA2
MKPWGA2
RFPWGA2
CTPWGA2
ICPWGA3
ICPWGA3L
ICPWGA3H
P0PWGA3
P1PWGA3
P2PWGA3
TBPWGA3
MKPWGA3
RFPWGA3
CTPWGA3
ICPWGA8
ICPWGA8L
ICPWGA8H
P0PWGA8
P1PWGA8
P2PWGA8
TBPWGA8
MKPWGA8
RFPWGA8
CTPWGA8
ICPWGA9
ICPWGA9L
ICPWGA9H
P0PWGA9
P1PWGA9
P2PWGA9
TBPWGA9
MKPWGA9
RFPWGA9
CTPWGA9
ICPWGA10
ICPWGA10L
ICPWGA10H
P0PWGA10
P1PWGA10
P2PWGA10
TBPWGA10
MKPWGA10
RFPWGA10
CTPWGA10
ICPWGA11
ICPWGA11L
ICPWGA11H
P0PWGA11
P1PWGA11
P2PWGA11
TBPWGA11
MKPWGA11
RFPWGA11
CTPWGA11
ICPWGA12
ICPWGA12L
ICPWGA12H
P0PWGA12
P1PWGA12
P2PWGA12
TBPWGA12
MKPWGA12
RFPWGA12
CTPWGA12
ICPWGA13
ICPWGA13L
ICPWGA13H
P0PWGA13
P1PWGA13
P2PWGA13
TBPWGA13
MKPWGA13
RFPWGA13
CTPWGA13
ICPWGA14
ICPWGA14L
ICPWGA14H
P0PWGA14
P1PWGA14
P2PWGA14
TBPWGA14
MKPWGA14
RFPWGA14
CTPWGA14
ICPWGA15
ICPWGA15L
ICPWGA15H
P0PWGA15
P1PWGA15
P2PWGA15
TBPWGA15
MKPWGA15
RFPWGA15
CTPWGA15
ICFLERR
ICFLERRL
ICFLERRH
P0FLERR
P1FLERR
P2FLERR
TBFLERR
MKFLERR
RFFLERR
CTFLERR
ICFLENDNM
ICFLENDNML
ICFLENDNMH
P0FLENDNM
P1FLENDNM
P2FLENDNM
TBFLENDNM
MKFLENDNM
RFFLENDNM
CTFLENDNM
ICCWEND
ICCWENDL
ICCWENDH
P0CWEND
P1CWEND
P2CWEND
TBCWEND
MKCWEND
RFCWEND
CTCWEND
ICRCAN1ERR
ICRCAN1ERRL
ICRCAN1ERRH
P0RCAN1ERR
P1RCAN1ERR
P2RCAN1ERR
TBRCAN1ERR
MKRCAN1ERR
RFRCAN1ERR
CTRCAN1ERR
ICRCAN1REC
ICRCAN1RECL
ICRCAN1RECH
P0RCAN1REC
P1RCAN1REC
P2RCAN1REC
TBRCAN1REC
MKRCAN1REC
RFRCAN1REC
CTRCAN1REC
ICRCAN1TRX
ICRCAN1TRXL
ICRCAN1TRXH
P0RCAN1TRX
P1RCAN1TRX
P2RCAN1TRX
TBRCAN1TRX
MKRCAN1TRX
RFRCAN1TRX
CTRCAN1TRX
ICCSIH1IC
ICTAPA0IPEK0_2
ICCSIH1ICL
ICTAPA0IPEK0L_2
ICCSIH1ICH
ICTAPA0IPEK0H_2
P0CSIH1IC
P0TAPA0IPEK0_2
P1CSIH1IC
P1TAPA0IPEK0_2
P2CSIH1IC
P2TAPA0IPEK0_2
TBCSIH1IC
TBTAPA0IPEK0_2
MKCSIH1IC
MKTAPA0IPEK0_2
RFCSIH1IC
RFTAPA0IPEK0_2
CTCSIH1IC
CTTAPA0IPEK0_2
ICCSIH1IR
ICTAPA0IVLY0_2
ICCSIH1IRL
ICTAPA0IVLY0L_2
ICCSIH1IRH
ICTAPA0IVLY0H_2
P0CSIH1IR
P0TAPA0IVLY0_2
P1CSIH1IR
P1TAPA0IVLY0_2
P2CSIH1IR
P2TAPA0IVLY0_2
TBCSIH1IR
TBTAPA0IVLY0_2
MKCSIH1IR
MKTAPA0IVLY0_2
RFCSIH1IR
RFTAPA0IVLY0_2
CTCSIH1IR
CTTAPA0IVLY0_2
ICCSIG0IC_2
ICCSIH1IRE
ICCSIG0ICL_2
ICCSIH1IREL
ICCSIG0ICH_2
ICCSIH1IREH
P0CSIG0IC_2
P0CSIH1IRE
P1CSIG0IC_2
P1CSIH1IRE
P2CSIG0IC_2
P2CSIH1IRE
TBCSIG0IC_2
TBCSIH1IRE
MKCSIG0IC_2
MKCSIH1IRE
RFCSIG0IC_2
RFCSIH1IRE
CTCSIG0IC_2
CTCSIH1IRE
ICCSIG0IR_2
ICCSIH1IJC
ICCSIG0IRL_2
ICCSIH1IJCL
ICCSIG0IRH_2
ICCSIH1IJCH
P0CSIG0IR_2
P0CSIH1IJC
P1CSIG0IR_2
P1CSIH1IJC
P2CSIG0IR_2
P2CSIH1IJC
TBCSIG0IR_2
TBCSIH1IJC
MKCSIG0IR_2
MKCSIH1IJC
RFCSIG0IR_2
RFCSIH1IJC
CTCSIG0IR_2
CTCSIH1IJC
ICRLIN31
ICRLIN31L
ICRLIN31H
P0RLIN31
P1RLIN31
P2RLIN31
TBRLIN31
MKRLIN31
RFRLIN31
CTRLIN31
ICRLIN31UR0
ICRLIN31UR0L
ICRLIN31UR0H
P0RLIN31UR0
P1RLIN31UR0
P2RLIN31UR0
TBRLIN31UR0
MKRLIN31UR0
RFRLIN31UR0
CTRLIN31UR0
ICRLIN31UR1
ICRLIN31UR1L
ICRLIN31UR1H
P0RLIN31UR1
P1RLIN31UR1
P2RLIN31UR1
TBRLIN31UR1
MKRLIN31UR1
RFRLIN31UR1
CTRLIN31UR1
ICRLIN31UR2
ICRLIN31UR2L
ICRLIN31UR2H
P0RLIN31UR2
P1RLIN31UR2
P2RLIN31UR2
TBRLIN31UR2
MKRLIN31UR2
RFRLIN31UR2
CTRLIN31UR2
ICPWGA20
ICPWGA20L
ICPWGA20H
P0PWGA20
P1PWGA20
P2PWGA20
TBPWGA20
MKPWGA20
RFPWGA20
CTPWGA20
ICPWGA21
ICPWGA21L
ICPWGA21H
P0PWGA21
P1PWGA21
P2PWGA21
TBPWGA21
MKPWGA21
RFPWGA21
CTPWGA21
ICPWGA22
ICPWGA22L
ICPWGA22H
P0PWGA22
P1PWGA22
P2PWGA22
TBPWGA22
MKPWGA22
RFPWGA22
CTPWGA22
ICPWGA23
ICPWGA23L
ICPWGA23H
P0PWGA23
P1PWGA23
P2PWGA23
TBPWGA23
MKPWGA23
RFPWGA23
CTPWGA23
ICP6
ICP6L
ICP6H
P0P6
P1P6
P2P6
TBP6
MKP6
RFP6
CTP6
ICP7
ICP7L
ICP7H
P0P7
P1P7
P2P7
TBP7
MKP7
RFP7
CTP7
ICP8
ICP8L
ICP8H
P0P8
P1P8
P2P8
TBP8
MKP8
RFP8
CTP8
ICP12
ICP12L
ICP12H
P0P12
P1P12
P2P12
TBP12
MKP12
RFP12
CTP12
ICCSIH2IC
ICTAUD0I0_2
ICCSIH2ICL
ICTAUD0I0L_2
ICCSIH2ICH
ICTAUD0I0H_2
P0CSIH2IC
P0TAUD0I0_2
P1CSIH2IC
P1TAUD0I0_2
P2CSIH2IC
P2TAUD0I0_2
TBCSIH2IC
TBTAUD0I0_2
MKCSIH2IC
MKTAUD0I0_2
RFCSIH2IC
RFTAUD0I0_2
CTCSIH2IC
CTTAUD0I0_2
ICCSIH2IR
ICP0_2
ICCSIH2IRL
ICP0L_2
ICCSIH2IRH
ICP0H_2
P0CSIH2IR
P0P0_2
P1CSIH2IR
P1P0_2
P2CSIH2IR
P2P0_2
TBCSIH2IR
TBP0_2
MKCSIH2IR
MKP0_2
RFCSIH2IR
RFP0_2
CTCSIH2IR
CTP0_2
ICCSIH2IRE
ICP1_2
ICCSIH2IREL
ICP1L_2
ICCSIH2IREH
ICP1H_2
P0CSIH2IRE
P0P1_2
P1CSIH2IRE
P1P1_2
P2CSIH2IRE
P2P1_2
TBCSIH2IRE
TBP1_2
MKCSIH2IRE
MKP1_2
RFCSIH2IRE
RFP1_2
CTCSIH2IRE
CTP1_2
ICCSIH2IJC
ICP2_2
ICCSIH2IJCL
ICP2L_2
ICCSIH2IJCH
ICP2H_2
P0CSIH2IJC
P0P2_2
P1CSIH2IJC
P1P2_2
P2CSIH2IJC
P2P2_2
TBCSIH2IJC
TBP2_2
MKCSIH2IJC
MKP2_2
RFCSIH2IJC
RFP2_2
CTCSIH2IJC
CTP2_2
ICTAUB0I0
ICTAUB0I0L
ICTAUB0I0H
P0TAUB0I0
P1TAUB0I0
P2TAUB0I0
TBTAUB0I0
MKTAUB0I0
RFTAUB0I0
CTTAUB0I0
ICTAUB0I1
ICTAUB0I1L
ICTAUB0I1H
P0TAUB0I1
P1TAUB0I1
P2TAUB0I1
TBTAUB0I1
MKTAUB0I1
RFTAUB0I1
CTTAUB0I1
ICTAUB0I2
ICTAUB0I2L
ICTAUB0I2H
P0TAUB0I2
P1TAUB0I2
P2TAUB0I2
TBTAUB0I2
MKTAUB0I2
RFTAUB0I2
CTTAUB0I2
ICPWGA16
ICTAUB0I3
ICPWGA16L
ICTAUB0I3L
ICPWGA16H
ICTAUB0I3H
P0PWGA16
P0TAUB0I3
P1PWGA16
P1TAUB0I3
P2PWGA16
P2TAUB0I3
TBPWGA16
TBTAUB0I3
MKPWGA16
MKTAUB0I3
RFPWGA16
RFTAUB0I3
CTPWGA16
CTTAUB0I3
ICTAUB0I4
ICTAUB0I4L
ICTAUB0I4H
P0TAUB0I4
P1TAUB0I4
P2TAUB0I4
TBTAUB0I4
MKTAUB0I4
RFTAUB0I4
CTTAUB0I4
ICPWGA17
ICTAUB0I5
ICPWGA17L
ICTAUB0I5L
ICPWGA17H
ICTAUB0I5H
P0PWGA17
P0TAUB0I5
P1PWGA17
P1TAUB0I5
P2PWGA17
P2TAUB0I5
TBPWGA17
TBTAUB0I5
MKPWGA17
MKTAUB0I5
RFPWGA17
RFTAUB0I5
CTPWGA17
CTTAUB0I5
ICTAUB0I6
ICTAUB0I6L
ICTAUB0I6H
P0TAUB0I6
P1TAUB0I6
P2TAUB0I6
TBTAUB0I6
MKTAUB0I6
RFTAUB0I6
CTTAUB0I6
ICPWGA18
ICTAUB0I7
ICPWGA18L
ICTAUB0I7L
ICPWGA18H
ICTAUB0I7H
P0PWGA18
P0TAUB0I7
P1PWGA18
P1TAUB0I7
P2PWGA18
P2TAUB0I7
TBPWGA18
TBTAUB0I7
MKPWGA18
MKTAUB0I7
RFPWGA18
RFTAUB0I7
CTPWGA18
CTTAUB0I7
ICTAUB0I8
ICTAUB0I8L
ICTAUB0I8H
P0TAUB0I8
P1TAUB0I8
P2TAUB0I8
TBTAUB0I8
MKTAUB0I8
RFTAUB0I8
CTTAUB0I8
ICPWGA19
ICTAUB0I9
ICPWGA19L
ICTAUB0I9L
ICPWGA19H
ICTAUB0I9H
P0PWGA19
P0TAUB0I9
P1PWGA19
P1TAUB0I9
P2PWGA19
P2TAUB0I9
TBPWGA19
TBTAUB0I9
MKPWGA19
MKTAUB0I9
RFPWGA19
RFTAUB0I9
CTPWGA19
CTTAUB0I9
ICTAUB0I10
ICTAUB0I10L
ICTAUB0I10H
P0TAUB0I10
P1TAUB0I10
P2TAUB0I10
TBTAUB0I10
MKTAUB0I10
RFTAUB0I10
CTTAUB0I10
ICPWGA26
ICTAUB0I11
ICPWGA26L
ICTAUB0I11L
ICPWGA26H
ICTAUB0I11H
P0PWGA26
P0TAUB0I11
P1PWGA26
P1TAUB0I11
P2PWGA26
P2TAUB0I11
TBPWGA26
TBTAUB0I11
MKPWGA26
MKTAUB0I11
RFPWGA26
RFTAUB0I11
CTPWGA26
CTTAUB0I11
ICTAUB0I12
ICTAUB0I12L
ICTAUB0I12H
P0TAUB0I12
P1TAUB0I12
P2TAUB0I12
TBTAUB0I12
MKTAUB0I12
RFTAUB0I12
CTTAUB0I12
ICPWGA30
ICTAUB0I13
ICPWGA30L
ICTAUB0I13L
ICPWGA30H
ICTAUB0I13H
P0PWGA30
P0TAUB0I13
P1PWGA30
P1TAUB0I13
P2PWGA30
P2TAUB0I13
TBPWGA30
TBTAUB0I13
MKPWGA30
MKTAUB0I13
RFPWGA30
RFTAUB0I13
CTPWGA30
CTTAUB0I13
ICTAUB0I14
ICTAUB0I14L
ICTAUB0I14H
P0TAUB0I14
P1TAUB0I14
P2TAUB0I14
TBTAUB0I14
MKTAUB0I14
RFTAUB0I14
CTTAUB0I14
ICPWGA31
ICTAUB0I15
ICPWGA31L
ICTAUB0I15L
ICPWGA31H
ICTAUB0I15H
P0PWGA31
P0TAUB0I15
P1PWGA31
P1TAUB0I15
P2PWGA31
P2TAUB0I15
TBPWGA31
TBTAUB0I15
MKPWGA31
MKTAUB0I15
RFPWGA31
RFTAUB0I15
CTPWGA31
CTTAUB0I15
ICCSIH3IC
ICTAUD0I2_2
ICCSIH3ICL
ICTAUD0I2L_2
ICCSIH3ICH
ICTAUD0I2H_2
P0CSIH3IC
P0TAUD0I2_2
P1CSIH3IC
P1TAUD0I2_2
P2CSIH3IC
P2TAUD0I2_2
TBCSIH3IC
TBTAUD0I2_2
MKCSIH3IC
MKTAUD0I2_2
RFCSIH3IC
RFTAUD0I2_2
CTCSIH3IC
CTTAUD0I2_2
ICCSIH3IR
ICTAUD0I10_2
ICCSIH3IRL
ICTAUD0I10L_2
ICCSIH3IRH
ICTAUD0I10H_2
P0CSIH3IR
P0TAUD0I10_2
P1CSIH3IR
P1TAUD0I10_2
P2CSIH3IR
P2TAUD0I10_2
TBCSIH3IR
TBTAUD0I10_2
MKCSIH3IR
MKTAUD0I10_2
RFCSIH3IR
RFTAUD0I10_2
CTCSIH3IR
CTTAUD0I10_2
ICCSIH3IRE
ICTAUD0I12_2
ICCSIH3IREL
ICTAUD0I12L_2
ICCSIH3IREH
ICTAUD0I12H_2
P0CSIH3IRE
P0TAUD0I12_2
P1CSIH3IRE
P1TAUD0I12_2
P2CSIH3IRE
P2TAUD0I12_2
TBCSIH3IRE
TBTAUD0I12_2
MKCSIH3IRE
MKTAUD0I12_2
RFCSIH3IRE
RFTAUD0I12_2
CTCSIH3IRE
CTTAUD0I12_2
ICCSIH3IJC
ICTAUD0I14_2
ICCSIH3IJCL
ICTAUD0I14L_2
ICCSIH3IJCH
ICTAUD0I14H_2
P0CSIH3IJC
P0TAUD0I14_2
P1CSIH3IJC
P1TAUD0I14_2
P2CSIH3IJC
P2TAUD0I14_2
TBCSIH3IJC
TBTAUD0I14_2
MKCSIH3IJC
MKTAUD0I14_2
RFCSIH3IJC
RFTAUD0I14_2
CTCSIH3IJC
CTTAUD0I14_2
ICRLIN22
ICRLIN22L
ICRLIN22H
P0RLIN22
P1RLIN22
P2RLIN22
TBRLIN22
MKRLIN22
RFRLIN22
CTRLIN22
ICRLIN23
ICRLIN23L
ICRLIN23H
P0RLIN23
P1RLIN23
P2RLIN23
TBRLIN23
MKRLIN23
RFRLIN23
CTRLIN23
ICRLIN32
ICRLIN32L
ICRLIN32H
P0RLIN32
P1RLIN32
P2RLIN32
TBRLIN32
MKRLIN32
RFRLIN32
CTRLIN32
ICRLIN32UR0
ICRLIN32UR0L
ICRLIN32UR0H
P0RLIN32UR0
P1RLIN32UR0
P2RLIN32UR0
TBRLIN32UR0
MKRLIN32UR0
RFRLIN32UR0
CTRLIN32UR0
ICRLIN32UR1
ICRLIN32UR1L
ICRLIN32UR1H
P0RLIN32UR1
P1RLIN32UR1
P2RLIN32UR1
TBRLIN32UR1
MKRLIN32UR1
RFRLIN32UR1
CTRLIN32UR1
ICRLIN32UR2
ICRLIN32UR2L
ICRLIN32UR2H
P0RLIN32UR2
P1RLIN32UR2
P2RLIN32UR2
TBRLIN32UR2
MKRLIN32UR2
RFRLIN32UR2
CTRLIN32UR2
ICTAUJ1I0
ICTAUJ1I0L
ICTAUJ1I0H
P0TAUJ1I0
P1TAUJ1I0
P2TAUJ1I0
TBTAUJ1I0
MKTAUJ1I0
RFTAUJ1I0
CTTAUJ1I0
ICTAUJ1I1
ICTAUJ1I1L
ICTAUJ1I1H
P0TAUJ1I1
P1TAUJ1I1
P2TAUJ1I1
TBTAUJ1I1
MKTAUJ1I1
RFTAUJ1I1
CTTAUJ1I1
ICTAUJ1I2
ICTAUJ1I2L
ICTAUJ1I2H
P0TAUJ1I2
P1TAUJ1I2
P2TAUJ1I2
TBTAUJ1I2
MKTAUJ1I2
RFTAUJ1I2
CTTAUJ1I2
ICTAUJ1I3
ICTAUJ1I3L
ICTAUJ1I3H
P0TAUJ1I3
P1TAUJ1I3
P2TAUJ1I3
TBTAUJ1I3
MKTAUJ1I3
RFTAUJ1I3
CTTAUJ1I3
ICPWGA24
ICPWGA24L
ICPWGA24H
P0PWGA24
P1PWGA24
P2PWGA24
TBPWGA24
MKPWGA24
RFPWGA24
CTPWGA24
ICPWGA25
ICPWGA25L
ICPWGA25H
P0PWGA25
P1PWGA25
P2PWGA25
TBPWGA25
MKPWGA25
RFPWGA25
CTPWGA25
ICPWGA27
ICPWGA27L
ICPWGA27H
P0PWGA27
P1PWGA27
P2PWGA27
TBPWGA27
MKPWGA27
RFPWGA27
CTPWGA27
ICPWGA28
ICPWGA28L
ICPWGA28H
P0PWGA28
P1PWGA28
P2PWGA28
TBPWGA28
MKPWGA28
RFPWGA28
CTPWGA28
ICPWGA29
ICPWGA29L
ICPWGA29H
P0PWGA29
P1PWGA29
P2PWGA29
TBPWGA29
MKPWGA29
RFPWGA29
CTPWGA29
ICPWGA32
ICPWGA32L
ICPWGA32H
P0PWGA32
P1PWGA32
P2PWGA32
TBPWGA32
MKPWGA32
RFPWGA32
CTPWGA32
ICPWGA33
ICPWGA33L
ICPWGA33H
P0PWGA33
P1PWGA33
P2PWGA33
TBPWGA33
MKPWGA33
RFPWGA33
CTPWGA33
ICPWGA34
ICPWGA34L
ICPWGA34H
P0PWGA34
P1PWGA34
P2PWGA34
TBPWGA34
MKPWGA34
RFPWGA34
CTPWGA34
ICPWGA35
ICPWGA35L
ICPWGA35H
P0PWGA35
P1PWGA35
P2PWGA35
TBPWGA35
MKPWGA35
RFPWGA35
CTPWGA35
ICPWGA36
ICPWGA36L
ICPWGA36H
P0PWGA36
P1PWGA36
P2PWGA36
TBPWGA36
MKPWGA36
RFPWGA36
CTPWGA36
ICPWGA37
ICPWGA37L
ICPWGA37H
P0PWGA37
P1PWGA37
P2PWGA37
TBPWGA37
MKPWGA37
RFPWGA37
CTPWGA37
ICPWGA38
ICPWGA38L
ICPWGA38H
P0PWGA38
P1PWGA38
P2PWGA38
TBPWGA38
MKPWGA38
RFPWGA38
CTPWGA38
ICPWGA39
ICPWGA39L
ICPWGA39H
P0PWGA39
P1PWGA39
P2PWGA39
TBPWGA39
MKPWGA39
RFPWGA39
CTPWGA39
ICPWGA40
ICPWGA40L
ICPWGA40H
P0PWGA40
P1PWGA40
P2PWGA40
TBPWGA40
MKPWGA40
RFPWGA40
CTPWGA40
ICPWGA41
ICPWGA41L
ICPWGA41H
P0PWGA41
P1PWGA41
P2PWGA41
TBPWGA41
MKPWGA41
RFPWGA41
CTPWGA41
ICPWGA42
ICPWGA42L
ICPWGA42H
P0PWGA42
P1PWGA42
P2PWGA42
TBPWGA42
MKPWGA42
RFPWGA42
CTPWGA42
ICPWGA43
ICPWGA43L
ICPWGA43H
P0PWGA43
P1PWGA43
P2PWGA43
TBPWGA43
MKPWGA43
RFPWGA43
CTPWGA43
ICPWGA44
ICPWGA44L
ICPWGA44H
P0PWGA44
P1PWGA44
P2PWGA44
TBPWGA44
MKPWGA44
RFPWGA44
CTPWGA44
ICPWGA45
ICPWGA45L
ICPWGA45H
P0PWGA45
P1PWGA45
P2PWGA45
TBPWGA45
MKPWGA45
RFPWGA45
CTPWGA45
ICPWGA46
ICPWGA46L
ICPWGA46H
P0PWGA46
P1PWGA46
P2PWGA46
TBPWGA46
MKPWGA46
RFPWGA46
CTPWGA46
ICPWGA47
ICPWGA47L
ICPWGA47H
P0PWGA47
P1PWGA47
P2PWGA47
TBPWGA47
MKPWGA47
RFPWGA47
CTPWGA47
ICP9
ICP9L
ICP9H
P0P9
P1P9
P2P9
TBP9
MKP9
RFP9
CTP9
ICP13
ICP13L
ICP13H
P0P13
P1P13
P2P13
TBP13
MKP13
RFP13
CTP13
ICP14
ICP14L
ICP14H
P0P14
P1P14
P2P14
TBP14
MKP14
RFP14
CTP14
ICP15
ICP15L
ICP15H
P0P15
P1P15
P2P15
TBP15
MKP15
RFP15
CTP15
ICRTCA01S
ICRTCA01SL
ICRTCA01SH
P0RTCA01S
P1RTCA01S
P2RTCA01S
TBRTCA01S
MKRTCA01S
RFRTCA01S
CTRTCA01S
ICRTCA0AL
ICRTCA0ALL
ICRTCA0ALH
P0RTCA0AL
P1RTCA0AL
P2RTCA0AL
TBRTCA0AL
MKRTCA0AL
RFRTCA0AL
CTRTCA0AL
ICRTCA0R
ICRTCA0RL
ICRTCA0RH
P0RTCA0R
P1RTCA0R
P2RTCA0R
TBRTCA0R
MKRTCA0R
RFRTCA0R
CTRTCA0R
ICADCA1ERR
ICADCA1ERRL
ICADCA1ERRH
P0ADCA1ERR
P1ADCA1ERR
P2ADCA1ERR
TBADCA1ERR
MKADCA1ERR
RFADCA1ERR
CTADCA1ERR
ICADCA1I0
ICADCA1I0L
ICADCA1I0H
P0ADCA1I0
P1ADCA1I0
P2ADCA1I0
TBADCA1I0
MKADCA1I0
RFADCA1I0
CTADCA1I0
ICADCA1I1
ICADCA1I1L
ICADCA1I1H
P0ADCA1I1
P1ADCA1I1
P2ADCA1I1
TBADCA1I1
MKADCA1I1
RFADCA1I1
CTADCA1I1
ICADCA1I2
ICADCA1I2L
ICADCA1I2H
P0ADCA1I2
P1ADCA1I2
P2ADCA1I2
TBADCA1I2
MKADCA1I2
RFADCA1I2
CTADCA1I2
ICRCAN2ERR
ICRCAN2ERRL
ICRCAN2ERRH
P0RCAN2ERR
P1RCAN2ERR
P2RCAN2ERR
TBRCAN2ERR
MKRCAN2ERR
RFRCAN2ERR
CTRCAN2ERR
ICRCAN2REC
ICRCAN2RECL
ICRCAN2RECH
P0RCAN2REC
P1RCAN2REC
P2RCAN2REC
TBRCAN2REC
MKRCAN2REC
RFRCAN2REC
CTRCAN2REC
ICRCAN2TRX
ICRCAN2TRXL
ICRCAN2TRXH
P0RCAN2TRX
P1RCAN2TRX
P2RCAN2TRX
TBRCAN2TRX
MKRCAN2TRX
RFRCAN2TRX
CTRCAN2TRX
ICRCAN3ERR
ICRCAN3ERRL
ICRCAN3ERRH
P0RCAN3ERR
P1RCAN3ERR
P2RCAN3ERR
TBRCAN3ERR
MKRCAN3ERR
RFRCAN3ERR
CTRCAN3ERR
ICRCAN3REC
ICRCAN3RECL
ICRCAN3RECH
P0RCAN3REC
P1RCAN3REC
P2RCAN3REC
TBRCAN3REC
MKRCAN3REC
RFRCAN3REC
CTRCAN3REC
ICRCAN3TRX
ICRCAN3TRXL
ICRCAN3TRXH
P0RCAN3TRX
P1RCAN3TRX
P2RCAN3TRX
TBRCAN3TRX
MKRCAN3TRX
RFRCAN3TRX
CTRCAN3TRX
ICCSIG1IC
ICCSIG1ICL
ICCSIG1ICH
P0CSIG1IC
P1CSIG1IC
P2CSIG1IC
TBCSIG1IC
MKCSIG1IC
RFCSIG1IC
CTCSIG1IC
ICCSIG1IR
ICCSIG1IRL
ICCSIG1IRH
P0CSIG1IR
P1CSIG1IR
P2CSIG1IR
TBCSIG1IR
MKCSIG1IR
RFCSIG1IR
CTCSIG1IR
ICCSIG1IRE
ICCSIG1IREL
ICCSIG1IREH
P0CSIG1IRE
P1CSIG1IRE
P2CSIG1IRE
TBCSIG1IRE
MKCSIG1IRE
RFCSIG1IRE
CTCSIG1IRE
ICRLIN24
ICRLIN24L
ICRLIN24H
P0RLIN24
P1RLIN24
P2RLIN24
TBRLIN24
MKRLIN24
RFRLIN24
CTRLIN24
ICRLIN25
ICRLIN25L
ICRLIN25H
P0RLIN25
P1RLIN25
P2RLIN25
TBRLIN25
MKRLIN25
RFRLIN25
CTRLIN25
ICRLIN33
ICRLIN33L
ICRLIN33H
P0RLIN33
P1RLIN33
P2RLIN33
TBRLIN33
MKRLIN33
RFRLIN33
CTRLIN33
ICRLIN33UR0
ICRLIN33UR0L
ICRLIN33UR0H
P0RLIN33UR0
P1RLIN33UR0
P2RLIN33UR0
TBRLIN33UR0
MKRLIN33UR0
RFRLIN33UR0
CTRLIN33UR0
ICRLIN33UR1
ICRLIN33UR1L
ICRLIN33UR1H
P0RLIN33UR1
P1RLIN33UR1
P2RLIN33UR1
TBRLIN33UR1
MKRLIN33UR1
RFRLIN33UR1
CTRLIN33UR1
ICRLIN33UR2
ICRLIN33UR2L
ICRLIN33UR2H
P0RLIN33UR2
P1RLIN33UR2
P2RLIN33UR2
TBRLIN33UR2
MKRLIN33UR2
RFRLIN33UR2
CTRLIN33UR2
ICRLIN34
ICRLIN34L
ICRLIN34H
P0RLIN34
P1RLIN34
P2RLIN34
TBRLIN34
MKRLIN34
RFRLIN34
CTRLIN34
ICRLIN34UR0
ICRLIN34UR0L
ICRLIN34UR0H
P0RLIN34UR0
P1RLIN34UR0
P2RLIN34UR0
TBRLIN34UR0
MKRLIN34UR0
RFRLIN34UR0
CTRLIN34UR0
ICRLIN34UR1
ICRLIN34UR1L
ICRLIN34UR1H
P0RLIN34UR1
P1RLIN34UR1
P2RLIN34UR1
TBRLIN34UR1
MKRLIN34UR1
RFRLIN34UR1
CTRLIN34UR1
ICRLIN34UR2
ICRLIN34UR2L
ICRLIN34UR2H
P0RLIN34UR2
P1RLIN34UR2
P2RLIN34UR2
TBRLIN34UR2
MKRLIN34UR2
RFRLIN34UR2
CTRLIN34UR2
ICRLIN35
ICRLIN35L
ICRLIN35H
P0RLIN35
P1RLIN35
P2RLIN35
TBRLIN35
MKRLIN35
RFRLIN35
CTRLIN35
ICRLIN35UR0
ICRLIN35UR0L
ICRLIN35UR0H
P0RLIN35UR0
P1RLIN35UR0
P2RLIN35UR0
TBRLIN35UR0
MKRLIN35UR0
RFRLIN35UR0
CTRLIN35UR0
ICRLIN35UR1
ICRLIN35UR1L
ICRLIN35UR1H
P0RLIN35UR1
P1RLIN35UR1
P2RLIN35UR1
TBRLIN35UR1
MKRLIN35UR1
RFRLIN35UR1
CTRLIN35UR1
ICRLIN35UR2
ICRLIN35UR2L
ICRLIN35UR2H
P0RLIN35UR2
P1RLIN35UR2
P2RLIN35UR2
TBRLIN35UR2
MKRLIN35UR2
RFRLIN35UR2
CTRLIN35UR2
ICPWGA48
ICPWGA48L
ICPWGA48H
P0PWGA48
P1PWGA48
P2PWGA48
TBPWGA48
MKPWGA48
RFPWGA48
CTPWGA48
ICPWGA49
ICPWGA49L
ICPWGA49H
P0PWGA49
P1PWGA49
P2PWGA49
TBPWGA49
MKPWGA49
RFPWGA49
CTPWGA49
ICPWGA50
ICPWGA50L
ICPWGA50H
P0PWGA50
P1PWGA50
P2PWGA50
TBPWGA50
MKPWGA50
RFPWGA50
CTPWGA50
ICPWGA51
ICPWGA51L
ICPWGA51H
P0PWGA51
P1PWGA51
P2PWGA51
TBPWGA51
MKPWGA51
RFPWGA51
CTPWGA51
ICPWGA52
ICPWGA52L
ICPWGA52H
P0PWGA52
P1PWGA52
P2PWGA52
TBPWGA52
MKPWGA52
RFPWGA52
CTPWGA52
ICPWGA53
ICPWGA53L
ICPWGA53H
P0PWGA53
P1PWGA53
P2PWGA53
TBPWGA53
MKPWGA53
RFPWGA53
CTPWGA53
ICPWGA54
ICPWGA54L
ICPWGA54H
P0PWGA54
P1PWGA54
P2PWGA54
TBPWGA54
MKPWGA54
RFPWGA54
CTPWGA54
ICPWGA55
ICPWGA55L
ICPWGA55H
P0PWGA55
P1PWGA55
P2PWGA55
TBPWGA55
MKPWGA55
RFPWGA55
CTPWGA55
ICPWGA56
ICPWGA56L
ICPWGA56H
P0PWGA56
P1PWGA56
P2PWGA56
TBPWGA56
MKPWGA56
RFPWGA56
CTPWGA56
ICPWGA57
ICPWGA57L
ICPWGA57H
P0PWGA57
P1PWGA57
P2PWGA57
TBPWGA57
MKPWGA57
RFPWGA57
CTPWGA57
ICPWGA58
ICPWGA58L
ICPWGA58H
P0PWGA58
P1PWGA58
P2PWGA58
TBPWGA58
MKPWGA58
RFPWGA58
CTPWGA58
ICPWGA59
ICPWGA59L
ICPWGA59H
P0PWGA59
P1PWGA59
P2PWGA59
TBPWGA59
MKPWGA59
RFPWGA59
CTPWGA59
ICPWGA60
ICPWGA60L
ICPWGA60H
P0PWGA60
P1PWGA60
P2PWGA60
TBPWGA60
MKPWGA60
RFPWGA60
CTPWGA60
ICPWGA61
ICPWGA61L
ICPWGA61H
P0PWGA61
P1PWGA61
P2PWGA61
TBPWGA61
MKPWGA61
RFPWGA61
CTPWGA61
ICPWGA62
ICPWGA62L
ICPWGA62H
P0PWGA62
P1PWGA62
P2PWGA62
TBPWGA62
MKPWGA62
RFPWGA62
CTPWGA62
ICPWGA63
ICPWGA63L
ICPWGA63H
P0PWGA63
P1PWGA63
P2PWGA63
TBPWGA63
MKPWGA63
RFPWGA63
CTPWGA63
ICTAUB1I0
ICTAUB1I0L
ICTAUB1I0H
P0TAUB1I0
P1TAUB1I0
P2TAUB1I0
TBTAUB1I0
MKTAUB1I0
RFTAUB1I0
CTTAUB1I0
ICTAUB1I1
ICTAUB1I1L
ICTAUB1I1H
P0TAUB1I1
P1TAUB1I1
P2TAUB1I1
TBTAUB1I1
MKTAUB1I1
RFTAUB1I1
CTTAUB1I1
ICTAUB1I2
ICTAUB1I2L
ICTAUB1I2H
P0TAUB1I2
P1TAUB1I2
P2TAUB1I2
TBTAUB1I2
MKTAUB1I2
RFTAUB1I2
CTTAUB1I2
ICTAUB1I3
ICTAUB1I3L
ICTAUB1I3H
P0TAUB1I3
P1TAUB1I3
P2TAUB1I3
TBTAUB1I3
MKTAUB1I3
RFTAUB1I3
CTTAUB1I3
ICTAUB1I4
ICTAUB1I4L
ICTAUB1I4H
P0TAUB1I4
P1TAUB1I4
P2TAUB1I4
TBTAUB1I4
MKTAUB1I4
RFTAUB1I4
CTTAUB1I4
ICTAUB1I5
ICTAUB1I5L
ICTAUB1I5H
P0TAUB1I5
P1TAUB1I5
P2TAUB1I5
TBTAUB1I5
MKTAUB1I5
RFTAUB1I5
CTTAUB1I5
ICTAUB1I6
ICTAUB1I6L
ICTAUB1I6H
P0TAUB1I6
P1TAUB1I6
P2TAUB1I6
TBTAUB1I6
MKTAUB1I6
RFTAUB1I6
CTTAUB1I6
ICTAUB1I7
ICTAUB1I7L
ICTAUB1I7H
P0TAUB1I7
P1TAUB1I7
P2TAUB1I7
TBTAUB1I7
MKTAUB1I7
RFTAUB1I7
CTTAUB1I7
ICTAUB1I8
ICTAUB1I8L
ICTAUB1I8H
P0TAUB1I8
P1TAUB1I8
P2TAUB1I8
TBTAUB1I8
MKTAUB1I8
RFTAUB1I8
CTTAUB1I8
ICTAUB1I9
ICTAUB1I9L
ICTAUB1I9H
P0TAUB1I9
P1TAUB1I9
P2TAUB1I9
TBTAUB1I9
MKTAUB1I9
RFTAUB1I9
CTTAUB1I9
ICTAUB1I10
ICTAUB1I10L
ICTAUB1I10H
P0TAUB1I10
P1TAUB1I10
P2TAUB1I10
TBTAUB1I10
MKTAUB1I10
RFTAUB1I10
CTTAUB1I10
ICTAUB1I11
ICTAUB1I11L
ICTAUB1I11H
P0TAUB1I11
P1TAUB1I11
P2TAUB1I11
TBTAUB1I11
MKTAUB1I11
RFTAUB1I11
CTTAUB1I11
ICTAUB1I12
ICTAUB1I12L
ICTAUB1I12H
P0TAUB1I12
P1TAUB1I12
P2TAUB1I12
TBTAUB1I12
MKTAUB1I12
RFTAUB1I12
CTTAUB1I12
ICTAUB1I13
ICTAUB1I13L
ICTAUB1I13H
P0TAUB1I13
P1TAUB1I13
P2TAUB1I13
TBTAUB1I13
MKTAUB1I13
RFTAUB1I13
CTTAUB1I13
ICTAUB1I14
ICTAUB1I14L
ICTAUB1I14H
P0TAUB1I14
P1TAUB1I14
P2TAUB1I14
TBTAUB1I14
MKTAUB1I14
RFTAUB1I14
CTTAUB1I14
ICTAUB1I15
ICTAUB1I15L
ICTAUB1I15H
P0TAUB1I15
P1TAUB1I15
P2TAUB1I15
TBTAUB1I15
MKTAUB1I15
RFTAUB1I15
CTTAUB1I15
ICRCAN4ERR
ICRCAN4ERRL
ICRCAN4ERRH
P0RCAN4ERR
P1RCAN4ERR
P2RCAN4ERR
TBRCAN4ERR
MKRCAN4ERR
RFRCAN4ERR
CTRCAN4ERR
ICRCAN4REC
ICRCAN4RECL
ICRCAN4RECH
P0RCAN4REC
P1RCAN4REC
P2RCAN4REC
TBRCAN4REC
MKRCAN4REC
RFRCAN4REC
CTRCAN4REC
ICRCAN4TRX
ICRCAN4TRXL
ICRCAN4TRXH
P0RCAN4TRX
P1RCAN4TRX
P2RCAN4TRX
TBRCAN4TRX
MKRCAN4TRX
RFRCAN4TRX
CTRCAN4TRX
ICRLIN26
ICRLIN26L
ICRLIN26H
P0RLIN26
P1RLIN26
P2RLIN26
TBRLIN26
MKRLIN26
RFRLIN26
CTRLIN26
ICRLIN27
ICRLIN27L
ICRLIN27H
P0RLIN27
P1RLIN27
P2RLIN27
TBRLIN27
MKRLIN27
RFRLIN27
CTRLIN27
ICPWGA64
ICPWGA64L
ICPWGA64H
P0PWGA64
P1PWGA64
P2PWGA64
TBPWGA64
MKPWGA64
RFPWGA64
CTPWGA64
ICPWGA65
ICPWGA65L
ICPWGA65H
P0PWGA65
P1PWGA65
P2PWGA65
TBPWGA65
MKPWGA65
RFPWGA65
CTPWGA65
ICPWGA66
ICPWGA66L
ICPWGA66H
P0PWGA66
P1PWGA66
P2PWGA66
TBPWGA66
MKPWGA66
RFPWGA66
CTPWGA66
ICPWGA67
ICPWGA67L
ICPWGA67H
P0PWGA67
P1PWGA67
P2PWGA67
TBPWGA67
MKPWGA67
RFPWGA67
CTPWGA67
ICPWGA68
ICPWGA68L
ICPWGA68H
P0PWGA68
P1PWGA68
P2PWGA68
TBPWGA68
MKPWGA68
RFPWGA68
CTPWGA68
ICPWGA69
ICPWGA69L
ICPWGA69H
P0PWGA69
P1PWGA69
P2PWGA69
TBPWGA69
MKPWGA69
RFPWGA69
CTPWGA69
ICPWGA70
ICPWGA70L
ICPWGA70H
P0PWGA70
P1PWGA70
P2PWGA70
TBPWGA70
MKPWGA70
RFPWGA70
CTPWGA70
ICPWGA71
ICPWGA71L
ICPWGA71H
P0PWGA71
P1PWGA71
P2PWGA71
TBPWGA71
MKPWGA71
RFPWGA71
CTPWGA71
ICRLIN28
ICRLIN28L
ICRLIN28H
P0RLIN28
P1RLIN28
P2RLIN28
TBRLIN28
MKRLIN28
RFRLIN28
CTRLIN28
ICRLIN29
ICRLIN29L
ICRLIN29H
P0RLIN29
P1RLIN29
P2RLIN29
TBRLIN29
MKRLIN29
RFRLIN29
CTRLIN29
ICRCAN5ERR
ICRCAN5ERRL
ICRCAN5ERRH
P0RCAN5ERR
P1RCAN5ERR
P2RCAN5ERR
TBRCAN5ERR
MKRCAN5ERR
RFRCAN5ERR
CTRCAN5ERR
ICRCAN5REC
ICRCAN5RECL
ICRCAN5RECH
P0RCAN5REC
P1RCAN5REC
P2RCAN5REC
TBRCAN5REC
MKRCAN5REC
RFRCAN5REC
CTRCAN5REC
ICRCAN5TRX
ICRCAN5TRXL
ICRCAN5TRXH
P0RCAN5TRX
P1RCAN5TRX
P2RCAN5TRX
TBRCAN5TRX
MKRCAN5TRX
RFRCAN5TRX
CTRCAN5TRX
IMR1
IMR1L
IMR1LL
IMR1LH
IMR1H
IMR1HL
IMR1HH
IMR1EIMK32 ... IMR1EIMK47
IMR1EIMK49 ... IMR1EIMK63
IMR2
IMR2L
IMR2LL
IMR2LH
IMR2H
IMR2HL
IMR2HH
IMR2EIMK64 ... IMR2EIMK95
IMR3
IMR3L
IMR3LL
IMR3LH
IMR3H
IMR3HL
IMR3HH
IMR3EIMK102 ... IMR3EIMK127
IMR4
IMR4L
IMR4LL
IMR4LH
IMR4H
IMR4HL
IMR4HH
IMR4EIMK134 ... IMR4EIMK159
IMR5
IMR5L
IMR5LL
IMR5H
IMR5HL
IMR5HH
IMR5EIMK160 ... IMR5EIMK163
IMR5EIMK176 ... IMR5EIMK191
IMR6
IMR6L
IMR6LL
IMR6LH
IMR6H
IMR6HL
IMR6HH
IMR6EIMK192 ... IMR6EIMK207
IMR6EIMK209 ... IMR6EIMK223
IMR7
IMR7L
IMR7LL
IMR7LH
IMR7H
IMR7HL
IMR7HH
IMR7EIMK224 ... IMR7EIMK255
IMR8
IMR8L
IMR8LL
IMR8LH
IMR8H
IMR8HL
IMR8HH
IMR8EIMK256 ... IMR8EIMK281
SELF.ID0 ... SELF.ID3
SELF.IDST.UINT32
SELF.IDST.UINT16[L]
SELF.IDST.UINT8[LL]
FACI.FPMON
FACI.FASTAT
FACI.FAEINT
FACI.FAREASELC
FACI.FSADDR
FACI.FEADDR
FACI.FCURAME
FACI.FSTATR.UINT32
FACI.FSTATR.UINT16[L/H]
FACI.FSTATR.UINT8[LL/LH/HL]
FACI.FENTRYR
FACI.FPROTR
FACI.FSUINITR
FACI.FLKSTAT
FACI.FRFSTEADR
FACI.FRTSTAT
FACI.FCMDR
FACI.FPESTAT
FACI.FBCCNT
FACI.FBCSTAT
FACI.FPSADDR
FACI.FCPSR
FACI.FPCKAR
FACI.FECCEMON
FACI.FECCTMD
FACI.FDMYECC
PFSS.BWCBUFEN
CCIB.FCUFAREA
RIIC0.CR1.UINT32
RIIC0.CR1.UINT16[L/H]
RIIC0.CR1.UINT8[LL/LH/HL/HH]
RIIC0.CR2.UINT32
RIIC0.CR2.UINT16[L/H]
RIIC0.CR2.UINT8[LL/LH/HL/HH]
RIIC0.MR1.UINT32
RIIC0.MR1.UINT16[L/H]
RIIC0.MR1.UINT8[LL/LH/HL/HH]
RIIC0.MR2.UINT32
RIIC0.MR2.UINT16[L/H]
RIIC0.MR2.UINT8[LL/LH/HL/HH]
RIIC0.MR3.UINT32
RIIC0.MR3.UINT16[L/H]
RIIC0.MR3.UINT8[LL/LH/HL/HH]
RIIC0.FER.UINT32
RIIC0.FER.UINT16[L/H]
RIIC0.FER.UINT8[LL/LH/HL/HH]
RIIC0.SER.UINT32
RIIC0.SER.UINT16[L/H]
RIIC0.SER.UINT8[LL/LH/HL/HH]
RIIC0.IER.UINT32
RIIC0.IER.UINT16[L/H]
RIIC0.IER.UINT8[LL/LH/HL/HH]
RIIC0.SR1.UINT32
RIIC0.SR1.UINT16[L/H]
RIIC0.SR1.UINT8[LL/LH/HL/HH]
RIIC0.SR2.UINT32
RIIC0.SR2.UINT16[L/H]
RIIC0.SR2.UINT8[LL/LH/HL/HH]
RIIC0.SAR0.UINT32
RIIC0.SAR0.UINT16[L/H]
RIIC0.SAR0.UINT8[LL/LH/HL/HH]
RIIC0.SAR1.UINT32
RIIC0.SAR1.UINT16[L/H]
RIIC0.SAR1.UINT8[LL/LH/HL/HH]
RIIC0.SAR2.UINT32
RIIC0.SAR2.UINT16[L/H]
RIIC0.SAR2.UINT8[LL/LH/HL/HH]
RIIC0.BRL.UINT32
RIIC0.BRL.UINT16[L/H]
RIIC0.BRL.UINT8[LL/LH/HL/HH]
RIIC0.BRH.UINT32
RIIC0.BRH.UINT16[L/H]
RIIC0.BRH.UINT8[LL/LH/HL/HH]
RIIC0.DRT.UINT32
RIIC0.DRT.UINT16[L/H]
RIIC0.DRT.UINT8[LL/LH/HL/HH]
RIIC0.DRR.UINT32
RIIC0.DRR.UINT16[L/H]
RIIC0.DRR.UINT8[LL/LH/HL/HH]
SCDS.PRDNAME1 ... SCDS.PRDNAME3
RLN240.GLWBR
RLN240.GLBRP0
RLN240.GLBRP1
RLN240.GLSTC
RLN2400.L0MD
RLN2400.L0BFC
RLN2400.L0SC
RLN2400.L0WUP
RLN2400.L0IE
RLN2400.L0EDE
RLN2400.L0CUC
RLN2400.L0TRC
RLN2400.L0MST
RLN2400.L0ST
RLN2400.L0EST
RLN2400.L0DFC
RLN2400.L0IDB
RLN2400.L0CBR
RLN2400.L0DBR1 ... RLN2400.L0DBR8
RLN2401.L1MD
RLN2401.L1BFC
RLN2401.L1SC
RLN2401.L1WUP
RLN2401.L1IE
RLN2401.L1EDE
RLN2401.L1CUC
RLN2401.L1TRC
RLN2401.L1MST
RLN2401.L1ST
RLN2401.L1EST
RLN2401.L1DFC
RLN2401.L1IDB
RLN2401.L1CBR
RLN2401.L1DBR1 ... RLN2401.L1DBR8
RLN2402.L2MD
RLN2402.L2BFC
RLN2402.L2SC
RLN2402.L2WUP
RLN2402.L2IE
RLN2402.L2EDE
RLN2402.L2CUC
RLN2402.L2TRC
RLN2402.L2MST
RLN2402.L2ST
RLN2402.L2EST
RLN2402.L2DFC
RLN2402.L2IDB
RLN2402.L2CBR
RLN2402.L2DBR1 ... RLN2402.L2DBR8
RLN2403.L3MD
RLN2403.L3BFC
RLN2403.L3SC
RLN2403.L3WUP
RLN2403.L3IE
RLN2403.L3EDE
RLN2403.L3CUC
RLN2403.L3TRC
RLN2403.L3MST
RLN2403.L3ST
RLN2403.L3EST
RLN2403.L3DFC
RLN2403.L3IDB
RLN2403.L3CBR
RLN2403.L3DBR1 ... RLN2403.L3DBR8
RLN241.GLWBR
RLN241.GLBRP0
RLN241.GLBRP1
RLN241.GLSTC
RLN2414.L0MD
RLN2414.L0BFC
RLN2414.L0SC
RLN2414.L0WUP
RLN2414.L0IE
RLN2414.L0EDE
RLN2414.L0CUC
RLN2414.L0TRC
RLN2414.L0MST
RLN2414.L0ST
RLN2414.L0EST
RLN2414.L0DFC
RLN2414.L0IDB
RLN2414.L0CBR
RLN2414.L0DBR1 ... RLN2414.L0DBR8
RLN2415.L1MD
RLN2415.L1BFC
RLN2415.L1SC
RLN2415.L1WUP
RLN2415.L1IE
RLN2415.L1EDE
RLN2415.L1CUC
RLN2415.L1TRC
RLN2415.L1MST
RLN2415.L1ST
RLN2415.L1EST
RLN2415.L1DFC
RLN2415.L1IDB
RLN2415.L1CBR
RLN2415.L1DBR1 ... RLN2415.L1DBR8
RLN2416.L2MD
RLN2416.L2BFC
RLN2416.L2SC
RLN2416.L2WUP
RLN2416.L2IE
RLN2416.L2EDE
RLN2416.L2CUC
RLN2416.L2TRC
RLN2416.L2MST
RLN2416.L2ST
RLN2416.L2EST
RLN2416.L2DFC
RLN2416.L2IDB
RLN2416.L2CBR
RLN2416.L2DBR1 ... RLN2416.L2DBR8
RLN2417.L3MD
RLN2417.L3BFC
RLN2417.L3SC
RLN2417.L3WUP
RLN2417.L3IE
RLN2417.L3EDE
RLN2417.L3CUC
RLN2417.L3TRC
RLN2417.L3MST
RLN2417.L3ST
RLN2417.L3EST
RLN2417.L3DFC
RLN2417.L3IDB
RLN2417.L3CBR
RLN2417.L3DBR1 ... RLN2417.L3DBR8
RLN210.GLWBR
RLN210.GLBRP0
RLN210.GLBRP1
RLN210.GLSTC
RLN2108.L0MD
RLN2108.L0BFC
RLN2108.L0SC
RLN2108.L0WUP
RLN2108.L0IE
RLN2108.L0EDE
RLN2108.L0CUC
RLN2108.L0TRC
RLN2108.L0MST
RLN2108.L0ST
RLN2108.L0EST
RLN2108.L0DFC
RLN2108.L0IDB
RLN2108.L0CBR
RLN2108.L0DBR1 ... RLN2108.L0DBR8
RLN211.GLWBR
RLN211.GLBRP0
RLN211.GLBRP1
RLN211.GLSTC
RLN2119.L0MD
RLN2119.L0BFC
RLN2119.L0SC
RLN2119.L0WUP
RLN2119.L0IE
RLN2119.L0EDE
RLN2119.L0CUC
RLN2119.L0TRC
RLN2119.L0MST
RLN2119.L0ST
RLN2119.L0EST
RLN2119.L0DFC
RLN2119.L0IDB
RLN2119.L0CBR
RLN2119.L0DBR1 ... RLN2119.L0DBR8
RLN30.LWBR
RLN30.LBRP01.UINT16
RLN30.LBRP01.UINT8[L/H]
RLN30.LBRP01.REGS8.LBRP0.UINT8
RLN30.LBRP01.REGS8.LBRP1.UINT8
RLN30.LSTC
RLN30.LMD
RLN30.LBFC
RLN30.LSC
RLN30.LWUP
RLN30.LIE
RLN30.LEDE
RLN30.LCUC
RLN30.LTRC
RLN30.LMST
RLN30.LST
RLN30.LEST
RLN30.LDFC
RLN30.LIDB
RLN30.LCBR
RLN30.LUDB0
RLN30.LDBR1 ... RLN30.LDBR8
RLN30.LUOER
RLN30.LUOR1
RLN30.LUTDR.UINT16
RLN30.LUTDR.UINT8[L/H]
RLN30.LURDR.UINT16
RLN30.LURDR.UINT8[L/H]
RLN30.LUWTDR.UINT16
RLN30.LUWTDR.UINT8[L/H]
RLN31.LWBR
RLN31.LBRP01.UINT16
RLN31.LBRP01.UINT8[L/H]
RLN31.LBRP01.REGS8.LBRP0.UINT8
RLN31.LBRP01.REGS8.LBRP1.UINT8
RLN31.LSTC
RLN31.LMD
RLN31.LBFC
RLN31.LSC
RLN31.LWUP
RLN31.LIE
RLN31.LEDE
RLN31.LCUC
RLN31.LTRC
RLN31.LMST
RLN31.LST
RLN31.LEST
RLN31.LDFC
RLN31.LIDB
RLN31.LCBR
RLN31.LUDB0
RLN31.LDBR1 ... RLN31.LDBR8
RLN31.LUOER
RLN31.LUOR1
RLN31.LUTDR.UINT16
RLN31.LUTDR.UINT8[L/H]
RLN31.LURDR.UINT16
RLN31.LURDR.UINT8[L/H]
RLN31.LUWTDR.UINT16
RLN31.LUWTDR.UINT8[L/H]
RLN32.LWBR
RLN32.LBRP01.UINT16
RLN32.LBRP01.UINT8[L/H]
RLN32.LBRP01.REGS8.LBRP0.UINT8
RLN32.LBRP01.REGS8.LBRP1.UINT8
RLN32.LSTC
RLN32.LMD
RLN32.LBFC
RLN32.LSC
RLN32.LWUP
RLN32.LIE
RLN32.LEDE
RLN32.LCUC
RLN32.LTRC
RLN32.LMST
RLN32.LST
RLN32.LEST
RLN32.LDFC
RLN32.LIDB
RLN32.LCBR
RLN32.LUDB0
RLN32.LDBR1 ... RLN32.LDBR8
RLN32.LUOER
RLN32.LUOR1
RLN32.LUTDR.UINT16
RLN32.LUTDR.UINT8[L/H]
RLN32.LURDR.UINT16
RLN32.LURDR.UINT8[L/H]
RLN32.LUWTDR.UINT16
RLN32.LUWTDR.UINT8[L/H]
RLN33.LWBR
RLN33.LBRP01.UINT16
RLN33.LBRP01.UINT8[L/H]
RLN33.LBRP01.REGS8.LBRP0.UINT8
RLN33.LBRP01.REGS8.LBRP1.UINT8
RLN33.LSTC
RLN33.LMD
RLN33.LBFC
RLN33.LSC
RLN33.LWUP
RLN33.LIE
RLN33.LEDE
RLN33.LCUC
RLN33.LTRC
RLN33.LMST
RLN33.LST
RLN33.LEST
RLN33.LDFC
RLN33.LIDB
RLN33.LCBR
RLN33.LUDB0
RLN33.LDBR1 ... RLN33.LDBR8
RLN33.LUOER
RLN33.LUOR1
RLN33.LUTDR.UINT16
RLN33.LUTDR.UINT8[L/H]
RLN33.LURDR.UINT16
RLN33.LURDR.UINT8[L/H]
RLN33.LUWTDR.UINT16
RLN33.LUWTDR.UINT8[L/H]
RLN34.LWBR
RLN34.LBRP01.UINT16
RLN34.LBRP01.UINT8[L/H]
RLN34.LBRP01.REGS8.LBRP0.UINT8
RLN34.LBRP01.REGS8.LBRP1.UINT8
RLN34.LSTC
RLN34.LMD
RLN34.LBFC
RLN34.LSC
RLN34.LWUP
RLN34.LIE
RLN34.LEDE
RLN34.LCUC
RLN34.LTRC
RLN34.LMST
RLN34.LST
RLN34.LEST
RLN34.LDFC
RLN34.LIDB
RLN34.LCBR
RLN34.LUDB0
RLN34.LDBR1 ... RLN34.LDBR8
RLN34.LUOER
RLN34.LUOR1
RLN34.LUTDR.UINT16
RLN34.LUTDR.UINT8[L/H]
RLN34.LURDR.UINT16
RLN34.LURDR.UINT8[L/H]
RLN34.LUWTDR.UINT16
RLN34.LUWTDR.UINT8[L/H]
RLN35.LWBR
RLN35.LBRP01.UINT16
RLN35.LBRP01.UINT8[L/H]
RLN35.LBRP01.REGS8.LBRP0.UINT8
RLN35.LBRP01.REGS8.LBRP1.UINT8
RLN35.LSTC
RLN35.LMD
RLN35.LBFC
RLN35.LSC
RLN35.LWUP
RLN35.LIE
RLN35.LEDE
RLN35.LCUC
RLN35.LTRC
RLN35.LMST
RLN35.LST
RLN35.LEST
RLN35.LDFC
RLN35.LIDB
RLN35.LCBR
RLN35.LUDB0
RLN35.LDBR1 ... RLN35.LDBR8
RLN35.LUOER
RLN35.LUOR1
RLN35.LUTDR.UINT16
RLN35.LUTDR.UINT8[L/H]
RLN35.LURDR.UINT16
RLN35.LURDR.UINT8[L/H]
RLN35.LUWTDR.UINT16
RLN35.LUWTDR.UINT8[L/H]
RSCAN0.C0CFG.UINT32
RSCAN0.C0CFG.UINT16[L/H]
RSCAN0.C0CFG.UINT8[LL/LH/HL/HH]
RSCAN0.C0CTR.UINT32
RSCAN0.C0CTR.UINT16[L/H]
RSCAN0.C0CTR.UINT8[LL/LH/HL/HH]
RSCAN0.C0STS.UINT32
RSCAN0.C0STS.UINT16[L/H]
RSCAN0.C0STS.UINT8[LL/HL/HH]
RSCAN0.C0ERFL.UINT32
RSCAN0.C0ERFL.UINT16[L/H]
RSCAN0.C0ERFL.UINT8[LL/LH/HL/HH]
RSCAN0.C1CFG.UINT32
RSCAN0.C1CFG.UINT16[L/H]
RSCAN0.C1CFG.UINT8[LL/LH/HL/HH]
RSCAN0.C1CTR.UINT32
RSCAN0.C1CTR.UINT16[L/H]
RSCAN0.C1CTR.UINT8[LL/LH/HL/HH]
RSCAN0.C1STS.UINT32
RSCAN0.C1STS.UINT16[L/H]
RSCAN0.C1STS.UINT8[LL/HL/HH]
RSCAN0.C1ERFL.UINT32
RSCAN0.C1ERFL.UINT16[L/H]
RSCAN0.C1ERFL.UINT8[LL/LH/HL/HH]
RSCAN0.C2CFG.UINT32
RSCAN0.C2CFG.UINT16[L/H]
RSCAN0.C2CFG.UINT8[LL/LH/HL/HH]
RSCAN0.C2CTR.UINT32
RSCAN0.C2CTR.UINT16[L/H]
RSCAN0.C2CTR.UINT8[LL/LH/HL/HH]
RSCAN0.C2STS.UINT32
RSCAN0.C2STS.UINT16[L/H]
RSCAN0.C2STS.UINT8[LL/HL/HH]
RSCAN0.C2ERFL.UINT32
RSCAN0.C2ERFL.UINT16[L/H]
RSCAN0.C2ERFL.UINT8[LL/LH/HL/HH]
RSCAN0.C3CFG.UINT32
RSCAN0.C3CFG.UINT16[L/H]
RSCAN0.C3CFG.UINT8[LL/LH/HL/HH]
RSCAN0.C3CTR.UINT32
RSCAN0.C3CTR.UINT16[L/H]
RSCAN0.C3CTR.UINT8[LL/LH/HL/HH]
RSCAN0.C3STS.UINT32
RSCAN0.C3STS.UINT16[L/H]
RSCAN0.C3STS.UINT8[LL/HL/HH]
RSCAN0.C3ERFL.UINT32
RSCAN0.C3ERFL.UINT16[L/H]
RSCAN0.C3ERFL.UINT8[LL/LH/HL/HH]
RSCAN0.C4CFG.UINT32
RSCAN0.C4CFG.UINT16[L/H]
RSCAN0.C4CFG.UINT8[LL/LH/HL/HH]
RSCAN0.C4CTR.UINT32
RSCAN0.C4CTR.UINT16[L/H]
RSCAN0.C4CTR.UINT8[LL/LH/HL/HH]
RSCAN0.C4STS.UINT32
RSCAN0.C4STS.UINT16[L/H]
RSCAN0.C4STS.UINT8[LL/HL/HH]
RSCAN0.C4ERFL.UINT32
RSCAN0.C4ERFL.UINT16[L/H]
RSCAN0.C4ERFL.UINT8[LL/LH/HL/HH]
RSCAN0.C5CFG.UINT32
RSCAN0.C5CFG.UINT16[L/H]
RSCAN0.C5CFG.UINT8[LL/LH/HL/HH]
RSCAN0.C5CTR.UINT32
RSCAN0.C5CTR.UINT16[L/H]
RSCAN0.C5CTR.UINT8[LL/LH/HL/HH]
RSCAN0.C5STS.UINT32
RSCAN0.C5STS.UINT16[L/H]
RSCAN0.C5STS.UINT8[LL/HL/HH]
RSCAN0.C5ERFL.UINT32
RSCAN0.C5ERFL.UINT16[L/H]
RSCAN0.C5ERFL.UINT8[LL/LH/HL/HH]
RSCAN0.GCFG.UINT32
RSCAN0.GCFG.UINT16[L/H]
RSCAN0.GCFG.UINT8[LL/LH/HL/HH]
RSCAN0.GCTR.UINT32
RSCAN0.GCTR.UINT16[L/H]
RSCAN0.GCTR.UINT8[LL/LH/HL]
RSCAN0.GSTS.UINT32
RSCAN0.GSTS.UINT16[L]
RSCAN0.GSTS.UINT8[LL]
RSCAN0.GERFL.UINT32
RSCAN0.GERFL.UINT16[L]
RSCAN0.GERFL.UINT8[LL]
RSCAN0.GTSC.UINT32
RSCAN0.GTSC.UINT16[L]
RSCAN0.GAFLECTR.UINT32
RSCAN0.GAFLECTR.UINT16[L]
RSCAN0.GAFLECTR.UINT8[LL/LH]
RSCAN0.GAFLCFG0.UINT32
RSCAN0.GAFLCFG0.UINT16[L/H]
RSCAN0.GAFLCFG0.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLCFG1.UINT32
RSCAN0.GAFLCFG1.UINT16[H]
RSCAN0.GAFLCFG1.UINT8[HL/HH]
RSCAN0.RMNB.UINT32
RSCAN0.RMNB.UINT16[L]
RSCAN0.RMNB.UINT8[LL]
RSCAN0.RMND0.UINT32
RSCAN0.RMND0.UINT16[L/H]
RSCAN0.RMND0.UINT8[LL/LH/HL/HH]
RSCAN0.RMND1.UINT32
RSCAN0.RMND1.UINT16[L/H]
RSCAN0.RMND1.UINT8[LL/LH/HL/HH]
RSCAN0.RMND2.UINT32
RSCAN0.RMND2.UINT16[L/H]
RSCAN0.RMND2.UINT8[LL/LH/HL/HH]
RSCAN0.RFCC0.UINT32
RSCAN0.RFCC0.UINT16[L]
RSCAN0.RFCC0.UINT8[LL/LH]
RSCAN0.RFCC1.UINT32
RSCAN0.RFCC1.UINT16[L]
RSCAN0.RFCC1.UINT8[LL/LH]
RSCAN0.RFCC2.UINT32
RSCAN0.RFCC2.UINT16[L]
RSCAN0.RFCC2.UINT8[LL/LH]
RSCAN0.RFCC3.UINT32
RSCAN0.RFCC3.UINT16[L]
RSCAN0.RFCC3.UINT8[LL/LH]
RSCAN0.RFCC4.UINT32
RSCAN0.RFCC4.UINT16[L]
RSCAN0.RFCC4.UINT8[LL/LH]
RSCAN0.RFCC5.UINT32
RSCAN0.RFCC5.UINT16[L]
RSCAN0.RFCC5.UINT8[LL/LH]
RSCAN0.RFCC6.UINT32
RSCAN0.RFCC6.UINT16[L]
RSCAN0.RFCC6.UINT8[LL/LH]
RSCAN0.RFCC7.UINT32
RSCAN0.RFCC7.UINT16[L]
RSCAN0.RFCC7.UINT8[LL/LH]
RSCAN0.RFSTS0.UINT32
RSCAN0.RFSTS0.UINT16[L]
RSCAN0.RFSTS0.UINT8[LL/LH]
RSCAN0.RFSTS1.UINT32
RSCAN0.RFSTS1.UINT16[L]
RSCAN0.RFSTS1.UINT8[LL/LH]
RSCAN0.RFSTS2.UINT32
RSCAN0.RFSTS2.UINT16[L]
RSCAN0.RFSTS2.UINT8[LL/LH]
RSCAN0.RFSTS3.UINT32
RSCAN0.RFSTS3.UINT16[L]
RSCAN0.RFSTS3.UINT8[LL/LH]
RSCAN0.RFSTS4.UINT32
RSCAN0.RFSTS4.UINT16[L]
RSCAN0.RFSTS4.UINT8[LL/LH]
RSCAN0.RFSTS5.UINT32
RSCAN0.RFSTS5.UINT16[L]
RSCAN0.RFSTS5.UINT8[LL/LH]
RSCAN0.RFSTS6.UINT32
RSCAN0.RFSTS6.UINT16[L]
RSCAN0.RFSTS6.UINT8[LL/LH]
RSCAN0.RFSTS7.UINT32
RSCAN0.RFSTS7.UINT16[L]
RSCAN0.RFSTS7.UINT8[LL/LH]
RSCAN0.RFPCTR0.UINT32
RSCAN0.RFPCTR0.UINT16[L]
RSCAN0.RFPCTR0.UINT8[LL]
RSCAN0.RFPCTR1.UINT32
RSCAN0.RFPCTR1.UINT16[L]
RSCAN0.RFPCTR1.UINT8[LL]
RSCAN0.RFPCTR2.UINT32
RSCAN0.RFPCTR2.UINT16[L]
RSCAN0.RFPCTR2.UINT8[LL]
RSCAN0.RFPCTR3.UINT32
RSCAN0.RFPCTR3.UINT16[L]
RSCAN0.RFPCTR3.UINT8[LL]
RSCAN0.RFPCTR4.UINT32
RSCAN0.RFPCTR4.UINT16[L]
RSCAN0.RFPCTR4.UINT8[LL]
RSCAN0.RFPCTR5.UINT32
RSCAN0.RFPCTR5.UINT16[L]
RSCAN0.RFPCTR5.UINT8[LL]
RSCAN0.RFPCTR6.UINT32
RSCAN0.RFPCTR6.UINT16[L]
RSCAN0.RFPCTR6.UINT8[LL]
RSCAN0.RFPCTR7.UINT32
RSCAN0.RFPCTR7.UINT16[L]
RSCAN0.RFPCTR7.UINT8[LL]
RSCAN0.CFCC0.UINT32
RSCAN0.CFCC0.UINT16[L/H]
RSCAN0.CFCC0.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC1.UINT32
RSCAN0.CFCC1.UINT16[L/H]
RSCAN0.CFCC1.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC2.UINT32
RSCAN0.CFCC2.UINT16[L/H]
RSCAN0.CFCC2.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC3.UINT32
RSCAN0.CFCC3.UINT16[L/H]
RSCAN0.CFCC3.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC4.UINT32
RSCAN0.CFCC4.UINT16[L/H]
RSCAN0.CFCC4.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC5.UINT32
RSCAN0.CFCC5.UINT16[L/H]
RSCAN0.CFCC5.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC6.UINT32
RSCAN0.CFCC6.UINT16[L/H]
RSCAN0.CFCC6.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC7.UINT32
RSCAN0.CFCC7.UINT16[L/H]
RSCAN0.CFCC7.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC8.UINT32
RSCAN0.CFCC8.UINT16[L/H]
RSCAN0.CFCC8.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC9.UINT32
RSCAN0.CFCC9.UINT16[L/H]
RSCAN0.CFCC9.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC10.UINT32
RSCAN0.CFCC10.UINT16[L/H]
RSCAN0.CFCC10.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC11.UINT32
RSCAN0.CFCC11.UINT16[L/H]
RSCAN0.CFCC11.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC12.UINT32
RSCAN0.CFCC12.UINT16[L/H]
RSCAN0.CFCC12.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC13.UINT32
RSCAN0.CFCC13.UINT16[L/H]
RSCAN0.CFCC13.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC14.UINT32
RSCAN0.CFCC14.UINT16[L/H]
RSCAN0.CFCC14.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC15.UINT32
RSCAN0.CFCC15.UINT16[L/H]
RSCAN0.CFCC15.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC16.UINT32
RSCAN0.CFCC16.UINT16[L/H]
RSCAN0.CFCC16.UINT8[LL/LH/HL/HH]
RSCAN0.CFCC17.UINT32
RSCAN0.CFCC17.UINT16[L/H]
RSCAN0.CFCC17.UINT8[LL/LH/HL/HH]
RSCAN0.CFSTS0.UINT32
RSCAN0.CFSTS0.UINT16[L]
RSCAN0.CFSTS0.UINT8[LL/LH]
RSCAN0.CFSTS1.UINT32
RSCAN0.CFSTS1.UINT16[L]
RSCAN0.CFSTS1.UINT8[LL/LH]
RSCAN0.CFSTS2.UINT32
RSCAN0.CFSTS2.UINT16[L]
RSCAN0.CFSTS2.UINT8[LL/LH]
RSCAN0.CFSTS3.UINT32
RSCAN0.CFSTS3.UINT16[L]
RSCAN0.CFSTS3.UINT8[LL/LH]
RSCAN0.CFSTS4.UINT32
RSCAN0.CFSTS4.UINT16[L]
RSCAN0.CFSTS4.UINT8[LL/LH]
RSCAN0.CFSTS5.UINT32
RSCAN0.CFSTS5.UINT16[L]
RSCAN0.CFSTS5.UINT8[LL/LH]
RSCAN0.CFSTS6.UINT32
RSCAN0.CFSTS6.UINT16[L]
RSCAN0.CFSTS6.UINT8[LL/LH]
RSCAN0.CFSTS7.UINT32
RSCAN0.CFSTS7.UINT16[L]
RSCAN0.CFSTS7.UINT8[LL/LH]
RSCAN0.CFSTS8.UINT32
RSCAN0.CFSTS8.UINT16[L]
RSCAN0.CFSTS8.UINT8[LL/LH]
RSCAN0.CFSTS9.UINT32
RSCAN0.CFSTS9.UINT16[L]
RSCAN0.CFSTS9.UINT8[LL/LH]
RSCAN0.CFSTS10.UINT32
RSCAN0.CFSTS10.UINT16[L]
RSCAN0.CFSTS10.UINT8[LL/LH]
RSCAN0.CFSTS11.UINT32
RSCAN0.CFSTS11.UINT16[L]
RSCAN0.CFSTS11.UINT8[LL/LH]
RSCAN0.CFSTS12.UINT32
RSCAN0.CFSTS12.UINT16[L]
RSCAN0.CFSTS12.UINT8[LL/LH]
RSCAN0.CFSTS13.UINT32
RSCAN0.CFSTS13.UINT16[L]
RSCAN0.CFSTS13.UINT8[LL/LH]
RSCAN0.CFSTS14.UINT32
RSCAN0.CFSTS14.UINT16[L]
RSCAN0.CFSTS14.UINT8[LL/LH]
RSCAN0.CFSTS15.UINT32
RSCAN0.CFSTS15.UINT16[L]
RSCAN0.CFSTS15.UINT8[LL/LH]
RSCAN0.CFSTS16.UINT32
RSCAN0.CFSTS16.UINT16[L]
RSCAN0.CFSTS16.UINT8[LL/LH]
RSCAN0.CFSTS17.UINT32
RSCAN0.CFSTS17.UINT16[L]
RSCAN0.CFSTS17.UINT8[LL/LH]
RSCAN0.CFPCTR0.UINT32
RSCAN0.CFPCTR0.UINT16[L]
RSCAN0.CFPCTR0.UINT8[LL]
RSCAN0.CFPCTR1.UINT32
RSCAN0.CFPCTR1.UINT16[L]
RSCAN0.CFPCTR1.UINT8[LL]
RSCAN0.CFPCTR2.UINT32
RSCAN0.CFPCTR2.UINT16[L]
RSCAN0.CFPCTR2.UINT8[LL]
RSCAN0.CFPCTR3.UINT32
RSCAN0.CFPCTR3.UINT16[L]
RSCAN0.CFPCTR3.UINT8[LL]
RSCAN0.CFPCTR4.UINT32
RSCAN0.CFPCTR4.UINT16[L]
RSCAN0.CFPCTR4.UINT8[LL]
RSCAN0.CFPCTR5.UINT32
RSCAN0.CFPCTR5.UINT16[L]
RSCAN0.CFPCTR5.UINT8[LL]
RSCAN0.CFPCTR6.UINT32
RSCAN0.CFPCTR6.UINT16[L]
RSCAN0.CFPCTR6.UINT8[LL]
RSCAN0.CFPCTR7.UINT32
RSCAN0.CFPCTR7.UINT16[L]
RSCAN0.CFPCTR7.UINT8[LL]
RSCAN0.CFPCTR8.UINT32
RSCAN0.CFPCTR8.UINT16[L]
RSCAN0.CFPCTR8.UINT8[LL]
RSCAN0.CFPCTR9.UINT32
RSCAN0.CFPCTR9.UINT16[L]
RSCAN0.CFPCTR9.UINT8[LL]
RSCAN0.CFPCTR10.UINT32
RSCAN0.CFPCTR10.UINT16[L]
RSCAN0.CFPCTR10.UINT8[LL]
RSCAN0.CFPCTR11.UINT32
RSCAN0.CFPCTR11.UINT16[L]
RSCAN0.CFPCTR11.UINT8[LL]
RSCAN0.CFPCTR12.UINT32
RSCAN0.CFPCTR12.UINT16[L]
RSCAN0.CFPCTR12.UINT8[LL]
RSCAN0.CFPCTR13.UINT32
RSCAN0.CFPCTR13.UINT16[L]
RSCAN0.CFPCTR13.UINT8[LL]
RSCAN0.CFPCTR14.UINT32
RSCAN0.CFPCTR14.UINT16[L]
RSCAN0.CFPCTR14.UINT8[LL]
RSCAN0.CFPCTR15.UINT32
RSCAN0.CFPCTR15.UINT16[L]
RSCAN0.CFPCTR15.UINT8[LL]
RSCAN0.CFPCTR16.UINT32
RSCAN0.CFPCTR16.UINT16[L]
RSCAN0.CFPCTR16.UINT8[LL]
RSCAN0.CFPCTR17.UINT32
RSCAN0.CFPCTR17.UINT16[L]
RSCAN0.CFPCTR17.UINT8[LL]
RSCAN0.FESTS.UINT32
RSCAN0.FESTS.UINT16[L/H]
RSCAN0.FESTS.UINT8[LL/LH/HL/HH]
RSCAN0.FFSTS.UINT32
RSCAN0.FFSTS.UINT16[L/H]
RSCAN0.FFSTS.UINT8[LL/LH/HL/HH]
RSCAN0.FMSTS.UINT32
RSCAN0.FMSTS.UINT16[L/H]
RSCAN0.FMSTS.UINT8[LL/LH/HL/HH]
RSCAN0.RFISTS.UINT32
RSCAN0.RFISTS.UINT16[L]
RSCAN0.RFISTS.UINT8[LL]
RSCAN0.CFRISTS.UINT32
RSCAN0.CFRISTS.UINT16[L/H]
RSCAN0.CFRISTS.UINT8[LL/LH/HL]
RSCAN0.CFTISTS.UINT32
RSCAN0.CFTISTS.UINT16[L/H]
RSCAN0.CFTISTS.UINT8[LL/LH/HL]
RSCAN0.TMC0 ... RSCAN0.TMC95
RSCAN0.TMSTS0 ... RSCAN0.TMSTS95
RSCAN0.TMTRSTS0.UINT32
RSCAN0.TMTRSTS0.UINT16[L/H]
RSCAN0.TMTRSTS0.UINT8[LL/LH/HL/HH]
RSCAN0.TMTRSTS1.UINT32
RSCAN0.TMTRSTS1.UINT16[L/H]
RSCAN0.TMTRSTS1.UINT8[LL/LH/HL/HH]
RSCAN0.TMTRSTS2.UINT32
RSCAN0.TMTRSTS2.UINT16[L/H]
RSCAN0.TMTRSTS2.UINT8[LL/LH/HL/HH]
RSCAN0.TMTARSTS0.UINT32
RSCAN0.TMTARSTS0.UINT16[L/H]
RSCAN0.TMTARSTS0.UINT8[LL/LH/HL/HH]
RSCAN0.TMTARSTS1.UINT32
RSCAN0.TMTARSTS1.UINT16[L/H]
RSCAN0.TMTARSTS1.UINT8[LL/LH/HL/HH]
RSCAN0.TMTARSTS2.UINT32
RSCAN0.TMTARSTS2.UINT16[L/H]
RSCAN0.TMTARSTS2.UINT8[LL/LH/HL/HH]
RSCAN0.TMTCSTS0.UINT32
RSCAN0.TMTCSTS0.UINT16[L/H]
RSCAN0.TMTCSTS0.UINT8[LL/LH/HL/HH]
RSCAN0.TMTCSTS1.UINT32
RSCAN0.TMTCSTS1.UINT16[L/H]
RSCAN0.TMTCSTS1.UINT8[LL/LH/HL/HH]
RSCAN0.TMTCSTS2.UINT32
RSCAN0.TMTCSTS2.UINT16[L/H]
RSCAN0.TMTCSTS2.UINT8[LL/LH/HL/HH]
RSCAN0.TMTASTS0.UINT32
RSCAN0.TMTASTS0.UINT16[L/H]
RSCAN0.TMTASTS0.UINT8[LL/LH/HL/HH]
RSCAN0.TMTASTS1.UINT32
RSCAN0.TMTASTS1.UINT16[L/H]
RSCAN0.TMTASTS1.UINT8[LL/LH/HL/HH]
RSCAN0.TMTASTS2.UINT32
RSCAN0.TMTASTS2.UINT16[L/H]
RSCAN0.TMTASTS2.UINT8[LL/LH/HL/HH]
RSCAN0.TMIEC0.UINT32
RSCAN0.TMIEC0.UINT16[L/H]
RSCAN0.TMIEC0.UINT8[LL/LH/HL/HH]
RSCAN0.TMIEC1.UINT32
RSCAN0.TMIEC1.UINT16[L/H]
RSCAN0.TMIEC1.UINT8[LL/LH/HL/HH]
RSCAN0.TMIEC2.UINT32
RSCAN0.TMIEC2.UINT16[L/H]
RSCAN0.TMIEC2.UINT8[LL/LH/HL/HH]
RSCAN0.TXQCC0.UINT32
RSCAN0.TXQCC0.UINT16[L]
RSCAN0.TXQCC0.UINT8[LL/LH]
RSCAN0.TXQCC1.UINT32
RSCAN0.TXQCC1.UINT16[L]
RSCAN0.TXQCC1.UINT8[LL/LH]
RSCAN0.TXQCC2.UINT32
RSCAN0.TXQCC2.UINT16[L]
RSCAN0.TXQCC2.UINT8[LL/LH]
RSCAN0.TXQCC3.UINT32
RSCAN0.TXQCC3.UINT16[L]
RSCAN0.TXQCC3.UINT8[LL/LH]
RSCAN0.TXQCC4.UINT32
RSCAN0.TXQCC4.UINT16[L]
RSCAN0.TXQCC4.UINT8[LL/LH]
RSCAN0.TXQCC5.UINT32
RSCAN0.TXQCC5.UINT16[L]
RSCAN0.TXQCC5.UINT8[LL/LH]
RSCAN0.TXQSTS0.UINT32
RSCAN0.TXQSTS0.UINT16[L]
RSCAN0.TXQSTS0.UINT8[LL]
RSCAN0.TXQSTS1.UINT32
RSCAN0.TXQSTS1.UINT16[L]
RSCAN0.TXQSTS1.UINT8[LL]
RSCAN0.TXQSTS2.UINT32
RSCAN0.TXQSTS2.UINT16[L]
RSCAN0.TXQSTS2.UINT8[LL]
RSCAN0.TXQSTS3.UINT32
RSCAN0.TXQSTS3.UINT16[L]
RSCAN0.TXQSTS3.UINT8[LL]
RSCAN0.TXQSTS4.UINT32
RSCAN0.TXQSTS4.UINT16[L]
RSCAN0.TXQSTS4.UINT8[LL]
RSCAN0.TXQSTS5.UINT32
RSCAN0.TXQSTS5.UINT16[L]
RSCAN0.TXQSTS5.UINT8[LL]
RSCAN0.TXQPCTR0.UINT32
RSCAN0.TXQPCTR0.UINT16[L]
RSCAN0.TXQPCTR0.UINT8[LL]
RSCAN0.TXQPCTR1.UINT32
RSCAN0.TXQPCTR1.UINT16[L]
RSCAN0.TXQPCTR1.UINT8[LL]
RSCAN0.TXQPCTR2.UINT32
RSCAN0.TXQPCTR2.UINT16[L]
RSCAN0.TXQPCTR2.UINT8[LL]
RSCAN0.TXQPCTR3.UINT32
RSCAN0.TXQPCTR3.UINT16[L]
RSCAN0.TXQPCTR3.UINT8[LL]
RSCAN0.TXQPCTR4.UINT32
RSCAN0.TXQPCTR4.UINT16[L]
RSCAN0.TXQPCTR4.UINT8[LL]
RSCAN0.TXQPCTR5.UINT32
RSCAN0.TXQPCTR5.UINT16[L]
RSCAN0.TXQPCTR5.UINT8[LL]
RSCAN0.THLCC0.UINT32
RSCAN0.THLCC0.UINT16[L]
RSCAN0.THLCC0.UINT8[LL/LH]
RSCAN0.THLCC1.UINT32
RSCAN0.THLCC1.UINT16[L]
RSCAN0.THLCC1.UINT8[LL/LH]
RSCAN0.THLCC2.UINT32
RSCAN0.THLCC2.UINT16[L]
RSCAN0.THLCC2.UINT8[LL/LH]
RSCAN0.THLCC3.UINT32
RSCAN0.THLCC3.UINT16[L]
RSCAN0.THLCC3.UINT8[LL/LH]
RSCAN0.THLCC4.UINT32
RSCAN0.THLCC4.UINT16[L]
RSCAN0.THLCC4.UINT8[LL/LH]
RSCAN0.THLCC5.UINT32
RSCAN0.THLCC5.UINT16[L]
RSCAN0.THLCC5.UINT8[LL/LH]
RSCAN0.THLSTS0.UINT32
RSCAN0.THLSTS0.UINT16[L]
RSCAN0.THLSTS0.UINT8[LL/LH]
RSCAN0.THLSTS1.UINT32
RSCAN0.THLSTS1.UINT16[L]
RSCAN0.THLSTS1.UINT8[LL/LH]
RSCAN0.THLSTS2.UINT32
RSCAN0.THLSTS2.UINT16[L]
RSCAN0.THLSTS2.UINT8[LL/LH]
RSCAN0.THLSTS3.UINT32
RSCAN0.THLSTS3.UINT16[L]
RSCAN0.THLSTS3.UINT8[LL/LH]
RSCAN0.THLSTS4.UINT32
RSCAN0.THLSTS4.UINT16[L]
RSCAN0.THLSTS4.UINT8[LL/LH]
RSCAN0.THLSTS5.UINT32
RSCAN0.THLSTS5.UINT16[L]
RSCAN0.THLSTS5.UINT8[LL/LH]
RSCAN0.THLPCTR0.UINT32
RSCAN0.THLPCTR0.UINT16[L]
RSCAN0.THLPCTR0.UINT8[LL]
RSCAN0.THLPCTR1.UINT32
RSCAN0.THLPCTR1.UINT16[L]
RSCAN0.THLPCTR1.UINT8[LL]
RSCAN0.THLPCTR2.UINT32
RSCAN0.THLPCTR2.UINT16[L]
RSCAN0.THLPCTR2.UINT8[LL]
RSCAN0.THLPCTR3.UINT32
RSCAN0.THLPCTR3.UINT16[L]
RSCAN0.THLPCTR3.UINT8[LL]
RSCAN0.THLPCTR4.UINT32
RSCAN0.THLPCTR4.UINT16[L]
RSCAN0.THLPCTR4.UINT8[LL]
RSCAN0.THLPCTR5.UINT32
RSCAN0.THLPCTR5.UINT16[L]
RSCAN0.THLPCTR5.UINT8[LL]
RSCAN0.GTINTSTS0.UINT32
RSCAN0.GTINTSTS0.UINT16[L/H]
RSCAN0.GTINTSTS0.UINT8[LL/LH/HL/HH]
RSCAN0.GTINTSTS1.UINT32
RSCAN0.GTINTSTS1.UINT16[L]
RSCAN0.GTINTSTS1.UINT8[LL/LH]
RSCAN0.GTSTCFG.UINT32
RSCAN0.GTSTCFG.UINT16[L/H]
RSCAN0.GTSTCFG.UINT8[LL/HL]
RSCAN0.GTSTCTR.UINT32
RSCAN0.GTSTCTR.UINT16[L]
RSCAN0.GTSTCTR.UINT8[LL]
RSCAN0.GLOCKK.UINT32
RSCAN0.GLOCKK.UINT16[L]
RSCAN0.GAFLID0.UINT32
RSCAN0.GAFLID0.UINT16[L/H]
RSCAN0.GAFLID0.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM0.UINT32
RSCAN0.GAFLM0.UINT16[L/H]
RSCAN0.GAFLM0.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP00.UINT32
RSCAN0.GAFLP00.UINT16[L/H]
RSCAN0.GAFLP00.UINT8[LH/HL/HH]
RSCAN0.GAFLP10.UINT32
RSCAN0.GAFLP10.UINT16[L/H]
RSCAN0.GAFLP10.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID1.UINT32
RSCAN0.GAFLID1.UINT16[L/H]
RSCAN0.GAFLID1.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM1.UINT32
RSCAN0.GAFLM1.UINT16[L/H]
RSCAN0.GAFLM1.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP01.UINT32
RSCAN0.GAFLP01.UINT16[L/H]
RSCAN0.GAFLP01.UINT8[LH/HL/HH]
RSCAN0.GAFLP11.UINT32
RSCAN0.GAFLP11.UINT16[L/H]
RSCAN0.GAFLP11.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID2.UINT32
RSCAN0.GAFLID2.UINT16[L/H]
RSCAN0.GAFLID2.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM2.UINT32
RSCAN0.GAFLM2.UINT16[L/H]
RSCAN0.GAFLM2.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP02.UINT32
RSCAN0.GAFLP02.UINT16[L/H]
RSCAN0.GAFLP02.UINT8[LH/HL/HH]
RSCAN0.GAFLP12.UINT32
RSCAN0.GAFLP12.UINT16[L/H]
RSCAN0.GAFLP12.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID3.UINT32
RSCAN0.GAFLID3.UINT16[L/H]
RSCAN0.GAFLID3.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM3.UINT32
RSCAN0.GAFLM3.UINT16[L/H]
RSCAN0.GAFLM3.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP03.UINT32
RSCAN0.GAFLP03.UINT16[L/H]
RSCAN0.GAFLP03.UINT8[LH/HL/HH]
RSCAN0.GAFLP13.UINT32
RSCAN0.GAFLP13.UINT16[L/H]
RSCAN0.GAFLP13.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID4.UINT32
RSCAN0.GAFLID4.UINT16[L/H]
RSCAN0.GAFLID4.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM4.UINT32
RSCAN0.GAFLM4.UINT16[L/H]
RSCAN0.GAFLM4.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP04.UINT32
RSCAN0.GAFLP04.UINT16[L/H]
RSCAN0.GAFLP04.UINT8[LH/HL/HH]
RSCAN0.GAFLP14.UINT32
RSCAN0.GAFLP14.UINT16[L/H]
RSCAN0.GAFLP14.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID5.UINT32
RSCAN0.GAFLID5.UINT16[L/H]
RSCAN0.GAFLID5.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM5.UINT32
RSCAN0.GAFLM5.UINT16[L/H]
RSCAN0.GAFLM5.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP05.UINT32
RSCAN0.GAFLP05.UINT16[L/H]
RSCAN0.GAFLP05.UINT8[LH/HL/HH]
RSCAN0.GAFLP15.UINT32
RSCAN0.GAFLP15.UINT16[L/H]
RSCAN0.GAFLP15.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID6.UINT32
RSCAN0.GAFLID6.UINT16[L/H]
RSCAN0.GAFLID6.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM6.UINT32
RSCAN0.GAFLM6.UINT16[L/H]
RSCAN0.GAFLM6.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP06.UINT32
RSCAN0.GAFLP06.UINT16[L/H]
RSCAN0.GAFLP06.UINT8[LH/HL/HH]
RSCAN0.GAFLP16.UINT32
RSCAN0.GAFLP16.UINT16[L/H]
RSCAN0.GAFLP16.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID7.UINT32
RSCAN0.GAFLID7.UINT16[L/H]
RSCAN0.GAFLID7.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM7.UINT32
RSCAN0.GAFLM7.UINT16[L/H]
RSCAN0.GAFLM7.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP07.UINT32
RSCAN0.GAFLP07.UINT16[L/H]
RSCAN0.GAFLP07.UINT8[LH/HL/HH]
RSCAN0.GAFLP17.UINT32
RSCAN0.GAFLP17.UINT16[L/H]
RSCAN0.GAFLP17.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID8.UINT32
RSCAN0.GAFLID8.UINT16[L/H]
RSCAN0.GAFLID8.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM8.UINT32
RSCAN0.GAFLM8.UINT16[L/H]
RSCAN0.GAFLM8.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP08.UINT32
RSCAN0.GAFLP08.UINT16[L/H]
RSCAN0.GAFLP08.UINT8[LH/HL/HH]
RSCAN0.GAFLP18.UINT32
RSCAN0.GAFLP18.UINT16[L/H]
RSCAN0.GAFLP18.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID9.UINT32
RSCAN0.GAFLID9.UINT16[L/H]
RSCAN0.GAFLID9.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM9.UINT32
RSCAN0.GAFLM9.UINT16[L/H]
RSCAN0.GAFLM9.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP09.UINT32
RSCAN0.GAFLP09.UINT16[L/H]
RSCAN0.GAFLP09.UINT8[LH/HL/HH]
RSCAN0.GAFLP19.UINT32
RSCAN0.GAFLP19.UINT16[L/H]
RSCAN0.GAFLP19.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID10.UINT32
RSCAN0.GAFLID10.UINT16[L/H]
RSCAN0.GAFLID10.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM10.UINT32
RSCAN0.GAFLM10.UINT16[L/H]
RSCAN0.GAFLM10.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP010.UINT32
RSCAN0.GAFLP010.UINT16[L/H]
RSCAN0.GAFLP010.UINT8[LH/HL/HH]
RSCAN0.GAFLP110.UINT32
RSCAN0.GAFLP110.UINT16[L/H]
RSCAN0.GAFLP110.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID11.UINT32
RSCAN0.GAFLID11.UINT16[L/H]
RSCAN0.GAFLID11.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM11.UINT32
RSCAN0.GAFLM11.UINT16[L/H]
RSCAN0.GAFLM11.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP011.UINT32
RSCAN0.GAFLP011.UINT16[L/H]
RSCAN0.GAFLP011.UINT8[LH/HL/HH]
RSCAN0.GAFLP111.UINT32
RSCAN0.GAFLP111.UINT16[L/H]
RSCAN0.GAFLP111.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID12.UINT32
RSCAN0.GAFLID12.UINT16[L/H]
RSCAN0.GAFLID12.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM12.UINT32
RSCAN0.GAFLM12.UINT16[L/H]
RSCAN0.GAFLM12.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP012.UINT32
RSCAN0.GAFLP012.UINT16[L/H]
RSCAN0.GAFLP012.UINT8[LH/HL/HH]
RSCAN0.GAFLP112.UINT32
RSCAN0.GAFLP112.UINT16[L/H]
RSCAN0.GAFLP112.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID13.UINT32
RSCAN0.GAFLID13.UINT16[L/H]
RSCAN0.GAFLID13.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM13.UINT32
RSCAN0.GAFLM13.UINT16[L/H]
RSCAN0.GAFLM13.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP013.UINT32
RSCAN0.GAFLP013.UINT16[L/H]
RSCAN0.GAFLP013.UINT8[LH/HL/HH]
RSCAN0.GAFLP113.UINT32
RSCAN0.GAFLP113.UINT16[L/H]
RSCAN0.GAFLP113.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID14.UINT32
RSCAN0.GAFLID14.UINT16[L/H]
RSCAN0.GAFLID14.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM14.UINT32
RSCAN0.GAFLM14.UINT16[L/H]
RSCAN0.GAFLM14.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP014.UINT32
RSCAN0.GAFLP014.UINT16[L/H]
RSCAN0.GAFLP014.UINT8[LH/HL/HH]
RSCAN0.GAFLP114.UINT32
RSCAN0.GAFLP114.UINT16[L/H]
RSCAN0.GAFLP114.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLID15.UINT32
RSCAN0.GAFLID15.UINT16[L/H]
RSCAN0.GAFLID15.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLM15.UINT32
RSCAN0.GAFLM15.UINT16[L/H]
RSCAN0.GAFLM15.UINT8[LL/LH/HL/HH]
RSCAN0.GAFLP015.UINT32
RSCAN0.GAFLP015.UINT16[L/H]
RSCAN0.GAFLP015.UINT8[LH/HL/HH]
RSCAN0.GAFLP115.UINT32
RSCAN0.GAFLP115.UINT16[L/H]
RSCAN0.GAFLP115.UINT8[LL/LH/HL/HH]
RSCAN0.RMID0.UINT32
RSCAN0.RMID0.UINT16[L/H]
RSCAN0.RMID0.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR0.UINT32
RSCAN0.RMPTR0.UINT16[L/H]
RSCAN0.RMPTR0.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF00.UINT32
RSCAN0.RMDF00.UINT16[L/H]
RSCAN0.RMDF00.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF10.UINT32
RSCAN0.RMDF10.UINT16[L/H]
RSCAN0.RMDF10.UINT8[LL/LH/HL/HH]
RSCAN0.RMID1.UINT32
RSCAN0.RMID1.UINT16[L/H]
RSCAN0.RMID1.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR1.UINT32
RSCAN0.RMPTR1.UINT16[L/H]
RSCAN0.RMPTR1.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF01.UINT32
RSCAN0.RMDF01.UINT16[L/H]
RSCAN0.RMDF01.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF11.UINT32
RSCAN0.RMDF11.UINT16[L/H]
RSCAN0.RMDF11.UINT8[LL/LH/HL/HH]
RSCAN0.RMID2.UINT32
RSCAN0.RMID2.UINT16[L/H]
RSCAN0.RMID2.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR2.UINT32
RSCAN0.RMPTR2.UINT16[L/H]
RSCAN0.RMPTR2.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF02.UINT32
RSCAN0.RMDF02.UINT16[L/H]
RSCAN0.RMDF02.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF12.UINT32
RSCAN0.RMDF12.UINT16[L/H]
RSCAN0.RMDF12.UINT8[LL/LH/HL/HH]
RSCAN0.RMID3.UINT32
RSCAN0.RMID3.UINT16[L/H]
RSCAN0.RMID3.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR3.UINT32
RSCAN0.RMPTR3.UINT16[L/H]
RSCAN0.RMPTR3.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF03.UINT32
RSCAN0.RMDF03.UINT16[L/H]
RSCAN0.RMDF03.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF13.UINT32
RSCAN0.RMDF13.UINT16[L/H]
RSCAN0.RMDF13.UINT8[LL/LH/HL/HH]
RSCAN0.RMID4.UINT32
RSCAN0.RMID4.UINT16[L/H]
RSCAN0.RMID4.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR4.UINT32
RSCAN0.RMPTR4.UINT16[L/H]
RSCAN0.RMPTR4.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF04.UINT32
RSCAN0.RMDF04.UINT16[L/H]
RSCAN0.RMDF04.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF14.UINT32
RSCAN0.RMDF14.UINT16[L/H]
RSCAN0.RMDF14.UINT8[LL/LH/HL/HH]
RSCAN0.RMID5.UINT32
RSCAN0.RMID5.UINT16[L/H]
RSCAN0.RMID5.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR5.UINT32
RSCAN0.RMPTR5.UINT16[L/H]
RSCAN0.RMPTR5.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF05.UINT32
RSCAN0.RMDF05.UINT16[L/H]
RSCAN0.RMDF05.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF15.UINT32
RSCAN0.RMDF15.UINT16[L/H]
RSCAN0.RMDF15.UINT8[LL/LH/HL/HH]
RSCAN0.RMID6.UINT32
RSCAN0.RMID6.UINT16[L/H]
RSCAN0.RMID6.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR6.UINT32
RSCAN0.RMPTR6.UINT16[L/H]
RSCAN0.RMPTR6.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF06.UINT32
RSCAN0.RMDF06.UINT16[L/H]
RSCAN0.RMDF06.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF16.UINT32
RSCAN0.RMDF16.UINT16[L/H]
RSCAN0.RMDF16.UINT8[LL/LH/HL/HH]
RSCAN0.RMID7.UINT32
RSCAN0.RMID7.UINT16[L/H]
RSCAN0.RMID7.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR7.UINT32
RSCAN0.RMPTR7.UINT16[L/H]
RSCAN0.RMPTR7.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF07.UINT32
RSCAN0.RMDF07.UINT16[L/H]
RSCAN0.RMDF07.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF17.UINT32
RSCAN0.RMDF17.UINT16[L/H]
RSCAN0.RMDF17.UINT8[LL/LH/HL/HH]
RSCAN0.RMID8.UINT32
RSCAN0.RMID8.UINT16[L/H]
RSCAN0.RMID8.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR8.UINT32
RSCAN0.RMPTR8.UINT16[L/H]
RSCAN0.RMPTR8.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF08.UINT32
RSCAN0.RMDF08.UINT16[L/H]
RSCAN0.RMDF08.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF18.UINT32
RSCAN0.RMDF18.UINT16[L/H]
RSCAN0.RMDF18.UINT8[LL/LH/HL/HH]
RSCAN0.RMID9.UINT32
RSCAN0.RMID9.UINT16[L/H]
RSCAN0.RMID9.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR9.UINT32
RSCAN0.RMPTR9.UINT16[L/H]
RSCAN0.RMPTR9.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF09.UINT32
RSCAN0.RMDF09.UINT16[L/H]
RSCAN0.RMDF09.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF19.UINT32
RSCAN0.RMDF19.UINT16[L/H]
RSCAN0.RMDF19.UINT8[LL/LH/HL/HH]
RSCAN0.RMID10.UINT32
RSCAN0.RMID10.UINT16[L/H]
RSCAN0.RMID10.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR10.UINT32
RSCAN0.RMPTR10.UINT16[L/H]
RSCAN0.RMPTR10.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF010.UINT32
RSCAN0.RMDF010.UINT16[L/H]
RSCAN0.RMDF010.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF110.UINT32
RSCAN0.RMDF110.UINT16[L/H]
RSCAN0.RMDF110.UINT8[LL/LH/HL/HH]
RSCAN0.RMID11.UINT32
RSCAN0.RMID11.UINT16[L/H]
RSCAN0.RMID11.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR11.UINT32
RSCAN0.RMPTR11.UINT16[L/H]
RSCAN0.RMPTR11.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF011.UINT32
RSCAN0.RMDF011.UINT16[L/H]
RSCAN0.RMDF011.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF111.UINT32
RSCAN0.RMDF111.UINT16[L/H]
RSCAN0.RMDF111.UINT8[LL/LH/HL/HH]
RSCAN0.RMID12.UINT32
RSCAN0.RMID12.UINT16[L/H]
RSCAN0.RMID12.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR12.UINT32
RSCAN0.RMPTR12.UINT16[L/H]
RSCAN0.RMPTR12.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF012.UINT32
RSCAN0.RMDF012.UINT16[L/H]
RSCAN0.RMDF012.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF112.UINT32
RSCAN0.RMDF112.UINT16[L/H]
RSCAN0.RMDF112.UINT8[LL/LH/HL/HH]
RSCAN0.RMID13.UINT32
RSCAN0.RMID13.UINT16[L/H]
RSCAN0.RMID13.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR13.UINT32
RSCAN0.RMPTR13.UINT16[L/H]
RSCAN0.RMPTR13.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF013.UINT32
RSCAN0.RMDF013.UINT16[L/H]
RSCAN0.RMDF013.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF113.UINT32
RSCAN0.RMDF113.UINT16[L/H]
RSCAN0.RMDF113.UINT8[LL/LH/HL/HH]
RSCAN0.RMID14.UINT32
RSCAN0.RMID14.UINT16[L/H]
RSCAN0.RMID14.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR14.UINT32
RSCAN0.RMPTR14.UINT16[L/H]
RSCAN0.RMPTR14.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF014.UINT32
RSCAN0.RMDF014.UINT16[L/H]
RSCAN0.RMDF014.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF114.UINT32
RSCAN0.RMDF114.UINT16[L/H]
RSCAN0.RMDF114.UINT8[LL/LH/HL/HH]
RSCAN0.RMID15.UINT32
RSCAN0.RMID15.UINT16[L/H]
RSCAN0.RMID15.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR15.UINT32
RSCAN0.RMPTR15.UINT16[L/H]
RSCAN0.RMPTR15.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF015.UINT32
RSCAN0.RMDF015.UINT16[L/H]
RSCAN0.RMDF015.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF115.UINT32
RSCAN0.RMDF115.UINT16[L/H]
RSCAN0.RMDF115.UINT8[LL/LH/HL/HH]
RSCAN0.RMID16.UINT32
RSCAN0.RMID16.UINT16[L/H]
RSCAN0.RMID16.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR16.UINT32
RSCAN0.RMPTR16.UINT16[L/H]
RSCAN0.RMPTR16.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF016.UINT32
RSCAN0.RMDF016.UINT16[L/H]
RSCAN0.RMDF016.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF116.UINT32
RSCAN0.RMDF116.UINT16[L/H]
RSCAN0.RMDF116.UINT8[LL/LH/HL/HH]
RSCAN0.RMID17.UINT32
RSCAN0.RMID17.UINT16[L/H]
RSCAN0.RMID17.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR17.UINT32
RSCAN0.RMPTR17.UINT16[L/H]
RSCAN0.RMPTR17.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF017.UINT32
RSCAN0.RMDF017.UINT16[L/H]
RSCAN0.RMDF017.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF117.UINT32
RSCAN0.RMDF117.UINT16[L/H]
RSCAN0.RMDF117.UINT8[LL/LH/HL/HH]
RSCAN0.RMID18.UINT32
RSCAN0.RMID18.UINT16[L/H]
RSCAN0.RMID18.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR18.UINT32
RSCAN0.RMPTR18.UINT16[L/H]
RSCAN0.RMPTR18.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF018.UINT32
RSCAN0.RMDF018.UINT16[L/H]
RSCAN0.RMDF018.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF118.UINT32
RSCAN0.RMDF118.UINT16[L/H]
RSCAN0.RMDF118.UINT8[LL/LH/HL/HH]
RSCAN0.RMID19.UINT32
RSCAN0.RMID19.UINT16[L/H]
RSCAN0.RMID19.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR19.UINT32
RSCAN0.RMPTR19.UINT16[L/H]
RSCAN0.RMPTR19.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF019.UINT32
RSCAN0.RMDF019.UINT16[L/H]
RSCAN0.RMDF019.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF119.UINT32
RSCAN0.RMDF119.UINT16[L/H]
RSCAN0.RMDF119.UINT8[LL/LH/HL/HH]
RSCAN0.RMID20.UINT32
RSCAN0.RMID20.UINT16[L/H]
RSCAN0.RMID20.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR20.UINT32
RSCAN0.RMPTR20.UINT16[L/H]
RSCAN0.RMPTR20.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF020.UINT32
RSCAN0.RMDF020.UINT16[L/H]
RSCAN0.RMDF020.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF120.UINT32
RSCAN0.RMDF120.UINT16[L/H]
RSCAN0.RMDF120.UINT8[LL/LH/HL/HH]
RSCAN0.RMID21.UINT32
RSCAN0.RMID21.UINT16[L/H]
RSCAN0.RMID21.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR21.UINT32
RSCAN0.RMPTR21.UINT16[L/H]
RSCAN0.RMPTR21.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF021.UINT32
RSCAN0.RMDF021.UINT16[L/H]
RSCAN0.RMDF021.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF121.UINT32
RSCAN0.RMDF121.UINT16[L/H]
RSCAN0.RMDF121.UINT8[LL/LH/HL/HH]
RSCAN0.RMID22.UINT32
RSCAN0.RMID22.UINT16[L/H]
RSCAN0.RMID22.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR22.UINT32
RSCAN0.RMPTR22.UINT16[L/H]
RSCAN0.RMPTR22.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF022.UINT32
RSCAN0.RMDF022.UINT16[L/H]
RSCAN0.RMDF022.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF122.UINT32
RSCAN0.RMDF122.UINT16[L/H]
RSCAN0.RMDF122.UINT8[LL/LH/HL/HH]
RSCAN0.RMID23.UINT32
RSCAN0.RMID23.UINT16[L/H]
RSCAN0.RMID23.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR23.UINT32
RSCAN0.RMPTR23.UINT16[L/H]
RSCAN0.RMPTR23.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF023.UINT32
RSCAN0.RMDF023.UINT16[L/H]
RSCAN0.RMDF023.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF123.UINT32
RSCAN0.RMDF123.UINT16[L/H]
RSCAN0.RMDF123.UINT8[LL/LH/HL/HH]
RSCAN0.RMID24.UINT32
RSCAN0.RMID24.UINT16[L/H]
RSCAN0.RMID24.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR24.UINT32
RSCAN0.RMPTR24.UINT16[L/H]
RSCAN0.RMPTR24.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF024.UINT32
RSCAN0.RMDF024.UINT16[L/H]
RSCAN0.RMDF024.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF124.UINT32
RSCAN0.RMDF124.UINT16[L/H]
RSCAN0.RMDF124.UINT8[LL/LH/HL/HH]
RSCAN0.RMID25.UINT32
RSCAN0.RMID25.UINT16[L/H]
RSCAN0.RMID25.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR25.UINT32
RSCAN0.RMPTR25.UINT16[L/H]
RSCAN0.RMPTR25.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF025.UINT32
RSCAN0.RMDF025.UINT16[L/H]
RSCAN0.RMDF025.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF125.UINT32
RSCAN0.RMDF125.UINT16[L/H]
RSCAN0.RMDF125.UINT8[LL/LH/HL/HH]
RSCAN0.RMID26.UINT32
RSCAN0.RMID26.UINT16[L/H]
RSCAN0.RMID26.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR26.UINT32
RSCAN0.RMPTR26.UINT16[L/H]
RSCAN0.RMPTR26.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF026.UINT32
RSCAN0.RMDF026.UINT16[L/H]
RSCAN0.RMDF026.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF126.UINT32
RSCAN0.RMDF126.UINT16[L/H]
RSCAN0.RMDF126.UINT8[LL/LH/HL/HH]
RSCAN0.RMID27.UINT32
RSCAN0.RMID27.UINT16[L/H]
RSCAN0.RMID27.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR27.UINT32
RSCAN0.RMPTR27.UINT16[L/H]
RSCAN0.RMPTR27.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF027.UINT32
RSCAN0.RMDF027.UINT16[L/H]
RSCAN0.RMDF027.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF127.UINT32
RSCAN0.RMDF127.UINT16[L/H]
RSCAN0.RMDF127.UINT8[LL/LH/HL/HH]
RSCAN0.RMID28.UINT32
RSCAN0.RMID28.UINT16[L/H]
RSCAN0.RMID28.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR28.UINT32
RSCAN0.RMPTR28.UINT16[L/H]
RSCAN0.RMPTR28.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF028.UINT32
RSCAN0.RMDF028.UINT16[L/H]
RSCAN0.RMDF028.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF128.UINT32
RSCAN0.RMDF128.UINT16[L/H]
RSCAN0.RMDF128.UINT8[LL/LH/HL/HH]
RSCAN0.RMID29.UINT32
RSCAN0.RMID29.UINT16[L/H]
RSCAN0.RMID29.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR29.UINT32
RSCAN0.RMPTR29.UINT16[L/H]
RSCAN0.RMPTR29.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF029.UINT32
RSCAN0.RMDF029.UINT16[L/H]
RSCAN0.RMDF029.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF129.UINT32
RSCAN0.RMDF129.UINT16[L/H]
RSCAN0.RMDF129.UINT8[LL/LH/HL/HH]
RSCAN0.RMID30.UINT32
RSCAN0.RMID30.UINT16[L/H]
RSCAN0.RMID30.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR30.UINT32
RSCAN0.RMPTR30.UINT16[L/H]
RSCAN0.RMPTR30.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF030.UINT32
RSCAN0.RMDF030.UINT16[L/H]
RSCAN0.RMDF030.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF130.UINT32
RSCAN0.RMDF130.UINT16[L/H]
RSCAN0.RMDF130.UINT8[LL/LH/HL/HH]
RSCAN0.RMID31.UINT32
RSCAN0.RMID31.UINT16[L/H]
RSCAN0.RMID31.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR31.UINT32
RSCAN0.RMPTR31.UINT16[L/H]
RSCAN0.RMPTR31.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF031.UINT32
RSCAN0.RMDF031.UINT16[L/H]
RSCAN0.RMDF031.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF131.UINT32
RSCAN0.RMDF131.UINT16[L/H]
RSCAN0.RMDF131.UINT8[LL/LH/HL/HH]
RSCAN0.RMID32.UINT32
RSCAN0.RMID32.UINT16[L/H]
RSCAN0.RMID32.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR32.UINT32
RSCAN0.RMPTR32.UINT16[L/H]
RSCAN0.RMPTR32.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF032.UINT32
RSCAN0.RMDF032.UINT16[L/H]
RSCAN0.RMDF032.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF132.UINT32
RSCAN0.RMDF132.UINT16[L/H]
RSCAN0.RMDF132.UINT8[LL/LH/HL/HH]
RSCAN0.RMID33.UINT32
RSCAN0.RMID33.UINT16[L/H]
RSCAN0.RMID33.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR33.UINT32
RSCAN0.RMPTR33.UINT16[L/H]
RSCAN0.RMPTR33.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF033.UINT32
RSCAN0.RMDF033.UINT16[L/H]
RSCAN0.RMDF033.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF133.UINT32
RSCAN0.RMDF133.UINT16[L/H]
RSCAN0.RMDF133.UINT8[LL/LH/HL/HH]
RSCAN0.RMID34.UINT32
RSCAN0.RMID34.UINT16[L/H]
RSCAN0.RMID34.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR34.UINT32
RSCAN0.RMPTR34.UINT16[L/H]
RSCAN0.RMPTR34.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF034.UINT32
RSCAN0.RMDF034.UINT16[L/H]
RSCAN0.RMDF034.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF134.UINT32
RSCAN0.RMDF134.UINT16[L/H]
RSCAN0.RMDF134.UINT8[LL/LH/HL/HH]
RSCAN0.RMID35.UINT32
RSCAN0.RMID35.UINT16[L/H]
RSCAN0.RMID35.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR35.UINT32
RSCAN0.RMPTR35.UINT16[L/H]
RSCAN0.RMPTR35.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF035.UINT32
RSCAN0.RMDF035.UINT16[L/H]
RSCAN0.RMDF035.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF135.UINT32
RSCAN0.RMDF135.UINT16[L/H]
RSCAN0.RMDF135.UINT8[LL/LH/HL/HH]
RSCAN0.RMID36.UINT32
RSCAN0.RMID36.UINT16[L/H]
RSCAN0.RMID36.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR36.UINT32
RSCAN0.RMPTR36.UINT16[L/H]
RSCAN0.RMPTR36.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF036.UINT32
RSCAN0.RMDF036.UINT16[L/H]
RSCAN0.RMDF036.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF136.UINT32
RSCAN0.RMDF136.UINT16[L/H]
RSCAN0.RMDF136.UINT8[LL/LH/HL/HH]
RSCAN0.RMID37.UINT32
RSCAN0.RMID37.UINT16[L/H]
RSCAN0.RMID37.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR37.UINT32
RSCAN0.RMPTR37.UINT16[L/H]
RSCAN0.RMPTR37.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF037.UINT32
RSCAN0.RMDF037.UINT16[L/H]
RSCAN0.RMDF037.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF137.UINT32
RSCAN0.RMDF137.UINT16[L/H]
RSCAN0.RMDF137.UINT8[LL/LH/HL/HH]
RSCAN0.RMID38.UINT32
RSCAN0.RMID38.UINT16[L/H]
RSCAN0.RMID38.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR38.UINT32
RSCAN0.RMPTR38.UINT16[L/H]
RSCAN0.RMPTR38.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF038.UINT32
RSCAN0.RMDF038.UINT16[L/H]
RSCAN0.RMDF038.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF138.UINT32
RSCAN0.RMDF138.UINT16[L/H]
RSCAN0.RMDF138.UINT8[LL/LH/HL/HH]
RSCAN0.RMID39.UINT32
RSCAN0.RMID39.UINT16[L/H]
RSCAN0.RMID39.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR39.UINT32
RSCAN0.RMPTR39.UINT16[L/H]
RSCAN0.RMPTR39.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF039.UINT32
RSCAN0.RMDF039.UINT16[L/H]
RSCAN0.RMDF039.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF139.UINT32
RSCAN0.RMDF139.UINT16[L/H]
RSCAN0.RMDF139.UINT8[LL/LH/HL/HH]
RSCAN0.RMID40.UINT32
RSCAN0.RMID40.UINT16[L/H]
RSCAN0.RMID40.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR40.UINT32
RSCAN0.RMPTR40.UINT16[L/H]
RSCAN0.RMPTR40.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF040.UINT32
RSCAN0.RMDF040.UINT16[L/H]
RSCAN0.RMDF040.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF140.UINT32
RSCAN0.RMDF140.UINT16[L/H]
RSCAN0.RMDF140.UINT8[LL/LH/HL/HH]
RSCAN0.RMID41.UINT32
RSCAN0.RMID41.UINT16[L/H]
RSCAN0.RMID41.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR41.UINT32
RSCAN0.RMPTR41.UINT16[L/H]
RSCAN0.RMPTR41.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF041.UINT32
RSCAN0.RMDF041.UINT16[L/H]
RSCAN0.RMDF041.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF141.UINT32
RSCAN0.RMDF141.UINT16[L/H]
RSCAN0.RMDF141.UINT8[LL/LH/HL/HH]
RSCAN0.RMID42.UINT32
RSCAN0.RMID42.UINT16[L/H]
RSCAN0.RMID42.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR42.UINT32
RSCAN0.RMPTR42.UINT16[L/H]
RSCAN0.RMPTR42.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF042.UINT32
RSCAN0.RMDF042.UINT16[L/H]
RSCAN0.RMDF042.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF142.UINT32
RSCAN0.RMDF142.UINT16[L/H]
RSCAN0.RMDF142.UINT8[LL/LH/HL/HH]
RSCAN0.RMID43.UINT32
RSCAN0.RMID43.UINT16[L/H]
RSCAN0.RMID43.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR43.UINT32
RSCAN0.RMPTR43.UINT16[L/H]
RSCAN0.RMPTR43.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF043.UINT32
RSCAN0.RMDF043.UINT16[L/H]
RSCAN0.RMDF043.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF143.UINT32
RSCAN0.RMDF143.UINT16[L/H]
RSCAN0.RMDF143.UINT8[LL/LH/HL/HH]
RSCAN0.RMID44.UINT32
RSCAN0.RMID44.UINT16[L/H]
RSCAN0.RMID44.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR44.UINT32
RSCAN0.RMPTR44.UINT16[L/H]
RSCAN0.RMPTR44.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF044.UINT32
RSCAN0.RMDF044.UINT16[L/H]
RSCAN0.RMDF044.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF144.UINT32
RSCAN0.RMDF144.UINT16[L/H]
RSCAN0.RMDF144.UINT8[LL/LH/HL/HH]
RSCAN0.RMID45.UINT32
RSCAN0.RMID45.UINT16[L/H]
RSCAN0.RMID45.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR45.UINT32
RSCAN0.RMPTR45.UINT16[L/H]
RSCAN0.RMPTR45.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF045.UINT32
RSCAN0.RMDF045.UINT16[L/H]
RSCAN0.RMDF045.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF145.UINT32
RSCAN0.RMDF145.UINT16[L/H]
RSCAN0.RMDF145.UINT8[LL/LH/HL/HH]
RSCAN0.RMID46.UINT32
RSCAN0.RMID46.UINT16[L/H]
RSCAN0.RMID46.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR46.UINT32
RSCAN0.RMPTR46.UINT16[L/H]
RSCAN0.RMPTR46.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF046.UINT32
RSCAN0.RMDF046.UINT16[L/H]
RSCAN0.RMDF046.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF146.UINT32
RSCAN0.RMDF146.UINT16[L/H]
RSCAN0.RMDF146.UINT8[LL/LH/HL/HH]
RSCAN0.RMID47.UINT32
RSCAN0.RMID47.UINT16[L/H]
RSCAN0.RMID47.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR47.UINT32
RSCAN0.RMPTR47.UINT16[L/H]
RSCAN0.RMPTR47.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF047.UINT32
RSCAN0.RMDF047.UINT16[L/H]
RSCAN0.RMDF047.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF147.UINT32
RSCAN0.RMDF147.UINT16[L/H]
RSCAN0.RMDF147.UINT8[LL/LH/HL/HH]
RSCAN0.RMID48.UINT32
RSCAN0.RMID48.UINT16[L/H]
RSCAN0.RMID48.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR48.UINT32
RSCAN0.RMPTR48.UINT16[L/H]
RSCAN0.RMPTR48.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF048.UINT32
RSCAN0.RMDF048.UINT16[L/H]
RSCAN0.RMDF048.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF148.UINT32
RSCAN0.RMDF148.UINT16[L/H]
RSCAN0.RMDF148.UINT8[LL/LH/HL/HH]
RSCAN0.RMID49.UINT32
RSCAN0.RMID49.UINT16[L/H]
RSCAN0.RMID49.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR49.UINT32
RSCAN0.RMPTR49.UINT16[L/H]
RSCAN0.RMPTR49.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF049.UINT32
RSCAN0.RMDF049.UINT16[L/H]
RSCAN0.RMDF049.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF149.UINT32
RSCAN0.RMDF149.UINT16[L/H]
RSCAN0.RMDF149.UINT8[LL/LH/HL/HH]
RSCAN0.RMID50.UINT32
RSCAN0.RMID50.UINT16[L/H]
RSCAN0.RMID50.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR50.UINT32
RSCAN0.RMPTR50.UINT16[L/H]
RSCAN0.RMPTR50.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF050.UINT32
RSCAN0.RMDF050.UINT16[L/H]
RSCAN0.RMDF050.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF150.UINT32
RSCAN0.RMDF150.UINT16[L/H]
RSCAN0.RMDF150.UINT8[LL/LH/HL/HH]
RSCAN0.RMID51.UINT32
RSCAN0.RMID51.UINT16[L/H]
RSCAN0.RMID51.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR51.UINT32
RSCAN0.RMPTR51.UINT16[L/H]
RSCAN0.RMPTR51.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF051.UINT32
RSCAN0.RMDF051.UINT16[L/H]
RSCAN0.RMDF051.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF151.UINT32
RSCAN0.RMDF151.UINT16[L/H]
RSCAN0.RMDF151.UINT8[LL/LH/HL/HH]
RSCAN0.RMID52.UINT32
RSCAN0.RMID52.UINT16[L/H]
RSCAN0.RMID52.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR52.UINT32
RSCAN0.RMPTR52.UINT16[L/H]
RSCAN0.RMPTR52.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF052.UINT32
RSCAN0.RMDF052.UINT16[L/H]
RSCAN0.RMDF052.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF152.UINT32
RSCAN0.RMDF152.UINT16[L/H]
RSCAN0.RMDF152.UINT8[LL/LH/HL/HH]
RSCAN0.RMID53.UINT32
RSCAN0.RMID53.UINT16[L/H]
RSCAN0.RMID53.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR53.UINT32
RSCAN0.RMPTR53.UINT16[L/H]
RSCAN0.RMPTR53.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF053.UINT32
RSCAN0.RMDF053.UINT16[L/H]
RSCAN0.RMDF053.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF153.UINT32
RSCAN0.RMDF153.UINT16[L/H]
RSCAN0.RMDF153.UINT8[LL/LH/HL/HH]
RSCAN0.RMID54.UINT32
RSCAN0.RMID54.UINT16[L/H]
RSCAN0.RMID54.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR54.UINT32
RSCAN0.RMPTR54.UINT16[L/H]
RSCAN0.RMPTR54.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF054.UINT32
RSCAN0.RMDF054.UINT16[L/H]
RSCAN0.RMDF054.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF154.UINT32
RSCAN0.RMDF154.UINT16[L/H]
RSCAN0.RMDF154.UINT8[LL/LH/HL/HH]
RSCAN0.RMID55.UINT32
RSCAN0.RMID55.UINT16[L/H]
RSCAN0.RMID55.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR55.UINT32
RSCAN0.RMPTR55.UINT16[L/H]
RSCAN0.RMPTR55.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF055.UINT32
RSCAN0.RMDF055.UINT16[L/H]
RSCAN0.RMDF055.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF155.UINT32
RSCAN0.RMDF155.UINT16[L/H]
RSCAN0.RMDF155.UINT8[LL/LH/HL/HH]
RSCAN0.RMID56.UINT32
RSCAN0.RMID56.UINT16[L/H]
RSCAN0.RMID56.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR56.UINT32
RSCAN0.RMPTR56.UINT16[L/H]
RSCAN0.RMPTR56.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF056.UINT32
RSCAN0.RMDF056.UINT16[L/H]
RSCAN0.RMDF056.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF156.UINT32
RSCAN0.RMDF156.UINT16[L/H]
RSCAN0.RMDF156.UINT8[LL/LH/HL/HH]
RSCAN0.RMID57.UINT32
RSCAN0.RMID57.UINT16[L/H]
RSCAN0.RMID57.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR57.UINT32
RSCAN0.RMPTR57.UINT16[L/H]
RSCAN0.RMPTR57.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF057.UINT32
RSCAN0.RMDF057.UINT16[L/H]
RSCAN0.RMDF057.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF157.UINT32
RSCAN0.RMDF157.UINT16[L/H]
RSCAN0.RMDF157.UINT8[LL/LH/HL/HH]
RSCAN0.RMID58.UINT32
RSCAN0.RMID58.UINT16[L/H]
RSCAN0.RMID58.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR58.UINT32
RSCAN0.RMPTR58.UINT16[L/H]
RSCAN0.RMPTR58.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF058.UINT32
RSCAN0.RMDF058.UINT16[L/H]
RSCAN0.RMDF058.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF158.UINT32
RSCAN0.RMDF158.UINT16[L/H]
RSCAN0.RMDF158.UINT8[LL/LH/HL/HH]
RSCAN0.RMID59.UINT32
RSCAN0.RMID59.UINT16[L/H]
RSCAN0.RMID59.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR59.UINT32
RSCAN0.RMPTR59.UINT16[L/H]
RSCAN0.RMPTR59.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF059.UINT32
RSCAN0.RMDF059.UINT16[L/H]
RSCAN0.RMDF059.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF159.UINT32
RSCAN0.RMDF159.UINT16[L/H]
RSCAN0.RMDF159.UINT8[LL/LH/HL/HH]
RSCAN0.RMID60.UINT32
RSCAN0.RMID60.UINT16[L/H]
RSCAN0.RMID60.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR60.UINT32
RSCAN0.RMPTR60.UINT16[L/H]
RSCAN0.RMPTR60.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF060.UINT32
RSCAN0.RMDF060.UINT16[L/H]
RSCAN0.RMDF060.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF160.UINT32
RSCAN0.RMDF160.UINT16[L/H]
RSCAN0.RMDF160.UINT8[LL/LH/HL/HH]
RSCAN0.RMID61.UINT32
RSCAN0.RMID61.UINT16[L/H]
RSCAN0.RMID61.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR61.UINT32
RSCAN0.RMPTR61.UINT16[L/H]
RSCAN0.RMPTR61.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF061.UINT32
RSCAN0.RMDF061.UINT16[L/H]
RSCAN0.RMDF061.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF161.UINT32
RSCAN0.RMDF161.UINT16[L/H]
RSCAN0.RMDF161.UINT8[LL/LH/HL/HH]
RSCAN0.RMID62.UINT32
RSCAN0.RMID62.UINT16[L/H]
RSCAN0.RMID62.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR62.UINT32
RSCAN0.RMPTR62.UINT16[L/H]
RSCAN0.RMPTR62.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF062.UINT32
RSCAN0.RMDF062.UINT16[L/H]
RSCAN0.RMDF062.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF162.UINT32
RSCAN0.RMDF162.UINT16[L/H]
RSCAN0.RMDF162.UINT8[LL/LH/HL/HH]
RSCAN0.RMID63.UINT32
RSCAN0.RMID63.UINT16[L/H]
RSCAN0.RMID63.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR63.UINT32
RSCAN0.RMPTR63.UINT16[L/H]
RSCAN0.RMPTR63.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF063.UINT32
RSCAN0.RMDF063.UINT16[L/H]
RSCAN0.RMDF063.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF163.UINT32
RSCAN0.RMDF163.UINT16[L/H]
RSCAN0.RMDF163.UINT8[LL/LH/HL/HH]
RSCAN0.RMID64.UINT32
RSCAN0.RMID64.UINT16[L/H]
RSCAN0.RMID64.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR64.UINT32
RSCAN0.RMPTR64.UINT16[L/H]
RSCAN0.RMPTR64.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF064.UINT32
RSCAN0.RMDF064.UINT16[L/H]
RSCAN0.RMDF064.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF164.UINT32
RSCAN0.RMDF164.UINT16[L/H]
RSCAN0.RMDF164.UINT8[LL/LH/HL/HH]
RSCAN0.RMID65.UINT32
RSCAN0.RMID65.UINT16[L/H]
RSCAN0.RMID65.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR65.UINT32
RSCAN0.RMPTR65.UINT16[L/H]
RSCAN0.RMPTR65.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF065.UINT32
RSCAN0.RMDF065.UINT16[L/H]
RSCAN0.RMDF065.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF165.UINT32
RSCAN0.RMDF165.UINT16[L/H]
RSCAN0.RMDF165.UINT8[LL/LH/HL/HH]
RSCAN0.RMID66.UINT32
RSCAN0.RMID66.UINT16[L/H]
RSCAN0.RMID66.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR66.UINT32
RSCAN0.RMPTR66.UINT16[L/H]
RSCAN0.RMPTR66.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF066.UINT32
RSCAN0.RMDF066.UINT16[L/H]
RSCAN0.RMDF066.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF166.UINT32
RSCAN0.RMDF166.UINT16[L/H]
RSCAN0.RMDF166.UINT8[LL/LH/HL/HH]
RSCAN0.RMID67.UINT32
RSCAN0.RMID67.UINT16[L/H]
RSCAN0.RMID67.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR67.UINT32
RSCAN0.RMPTR67.UINT16[L/H]
RSCAN0.RMPTR67.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF067.UINT32
RSCAN0.RMDF067.UINT16[L/H]
RSCAN0.RMDF067.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF167.UINT32
RSCAN0.RMDF167.UINT16[L/H]
RSCAN0.RMDF167.UINT8[LL/LH/HL/HH]
RSCAN0.RMID68.UINT32
RSCAN0.RMID68.UINT16[L/H]
RSCAN0.RMID68.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR68.UINT32
RSCAN0.RMPTR68.UINT16[L/H]
RSCAN0.RMPTR68.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF068.UINT32
RSCAN0.RMDF068.UINT16[L/H]
RSCAN0.RMDF068.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF168.UINT32
RSCAN0.RMDF168.UINT16[L/H]
RSCAN0.RMDF168.UINT8[LL/LH/HL/HH]
RSCAN0.RMID69.UINT32
RSCAN0.RMID69.UINT16[L/H]
RSCAN0.RMID69.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR69.UINT32
RSCAN0.RMPTR69.UINT16[L/H]
RSCAN0.RMPTR69.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF069.UINT32
RSCAN0.RMDF069.UINT16[L/H]
RSCAN0.RMDF069.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF169.UINT32
RSCAN0.RMDF169.UINT16[L/H]
RSCAN0.RMDF169.UINT8[LL/LH/HL/HH]
RSCAN0.RMID70.UINT32
RSCAN0.RMID70.UINT16[L/H]
RSCAN0.RMID70.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR70.UINT32
RSCAN0.RMPTR70.UINT16[L/H]
RSCAN0.RMPTR70.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF070.UINT32
RSCAN0.RMDF070.UINT16[L/H]
RSCAN0.RMDF070.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF170.UINT32
RSCAN0.RMDF170.UINT16[L/H]
RSCAN0.RMDF170.UINT8[LL/LH/HL/HH]
RSCAN0.RMID71.UINT32
RSCAN0.RMID71.UINT16[L/H]
RSCAN0.RMID71.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR71.UINT32
RSCAN0.RMPTR71.UINT16[L/H]
RSCAN0.RMPTR71.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF071.UINT32
RSCAN0.RMDF071.UINT16[L/H]
RSCAN0.RMDF071.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF171.UINT32
RSCAN0.RMDF171.UINT16[L/H]
RSCAN0.RMDF171.UINT8[LL/LH/HL/HH]
RSCAN0.RMID72.UINT32
RSCAN0.RMID72.UINT16[L/H]
RSCAN0.RMID72.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR72.UINT32
RSCAN0.RMPTR72.UINT16[L/H]
RSCAN0.RMPTR72.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF072.UINT32
RSCAN0.RMDF072.UINT16[L/H]
RSCAN0.RMDF072.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF172.UINT32
RSCAN0.RMDF172.UINT16[L/H]
RSCAN0.RMDF172.UINT8[LL/LH/HL/HH]
RSCAN0.RMID73.UINT32
RSCAN0.RMID73.UINT16[L/H]
RSCAN0.RMID73.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR73.UINT32
RSCAN0.RMPTR73.UINT16[L/H]
RSCAN0.RMPTR73.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF073.UINT32
RSCAN0.RMDF073.UINT16[L/H]
RSCAN0.RMDF073.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF173.UINT32
RSCAN0.RMDF173.UINT16[L/H]
RSCAN0.RMDF173.UINT8[LL/LH/HL/HH]
RSCAN0.RMID74.UINT32
RSCAN0.RMID74.UINT16[L/H]
RSCAN0.RMID74.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR74.UINT32
RSCAN0.RMPTR74.UINT16[L/H]
RSCAN0.RMPTR74.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF074.UINT32
RSCAN0.RMDF074.UINT16[L/H]
RSCAN0.RMDF074.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF174.UINT32
RSCAN0.RMDF174.UINT16[L/H]
RSCAN0.RMDF174.UINT8[LL/LH/HL/HH]
RSCAN0.RMID75.UINT32
RSCAN0.RMID75.UINT16[L/H]
RSCAN0.RMID75.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR75.UINT32
RSCAN0.RMPTR75.UINT16[L/H]
RSCAN0.RMPTR75.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF075.UINT32
RSCAN0.RMDF075.UINT16[L/H]
RSCAN0.RMDF075.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF175.UINT32
RSCAN0.RMDF175.UINT16[L/H]
RSCAN0.RMDF175.UINT8[LL/LH/HL/HH]
RSCAN0.RMID76.UINT32
RSCAN0.RMID76.UINT16[L/H]
RSCAN0.RMID76.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR76.UINT32
RSCAN0.RMPTR76.UINT16[L/H]
RSCAN0.RMPTR76.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF076.UINT32
RSCAN0.RMDF076.UINT16[L/H]
RSCAN0.RMDF076.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF176.UINT32
RSCAN0.RMDF176.UINT16[L/H]
RSCAN0.RMDF176.UINT8[LL/LH/HL/HH]
RSCAN0.RMID77.UINT32
RSCAN0.RMID77.UINT16[L/H]
RSCAN0.RMID77.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR77.UINT32
RSCAN0.RMPTR77.UINT16[L/H]
RSCAN0.RMPTR77.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF077.UINT32
RSCAN0.RMDF077.UINT16[L/H]
RSCAN0.RMDF077.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF177.UINT32
RSCAN0.RMDF177.UINT16[L/H]
RSCAN0.RMDF177.UINT8[LL/LH/HL/HH]
RSCAN0.RMID78.UINT32
RSCAN0.RMID78.UINT16[L/H]
RSCAN0.RMID78.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR78.UINT32
RSCAN0.RMPTR78.UINT16[L/H]
RSCAN0.RMPTR78.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF078.UINT32
RSCAN0.RMDF078.UINT16[L/H]
RSCAN0.RMDF078.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF178.UINT32
RSCAN0.RMDF178.UINT16[L/H]
RSCAN0.RMDF178.UINT8[LL/LH/HL/HH]
RSCAN0.RMID79.UINT32
RSCAN0.RMID79.UINT16[L/H]
RSCAN0.RMID79.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR79.UINT32
RSCAN0.RMPTR79.UINT16[L/H]
RSCAN0.RMPTR79.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF079.UINT32
RSCAN0.RMDF079.UINT16[L/H]
RSCAN0.RMDF079.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF179.UINT32
RSCAN0.RMDF179.UINT16[L/H]
RSCAN0.RMDF179.UINT8[LL/LH/HL/HH]
RSCAN0.RMID80.UINT32
RSCAN0.RMID80.UINT16[L/H]
RSCAN0.RMID80.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR80.UINT32
RSCAN0.RMPTR80.UINT16[L/H]
RSCAN0.RMPTR80.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF080.UINT32
RSCAN0.RMDF080.UINT16[L/H]
RSCAN0.RMDF080.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF180.UINT32
RSCAN0.RMDF180.UINT16[L/H]
RSCAN0.RMDF180.UINT8[LL/LH/HL/HH]
RSCAN0.RMID81.UINT32
RSCAN0.RMID81.UINT16[L/H]
RSCAN0.RMID81.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR81.UINT32
RSCAN0.RMPTR81.UINT16[L/H]
RSCAN0.RMPTR81.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF081.UINT32
RSCAN0.RMDF081.UINT16[L/H]
RSCAN0.RMDF081.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF181.UINT32
RSCAN0.RMDF181.UINT16[L/H]
RSCAN0.RMDF181.UINT8[LL/LH/HL/HH]
RSCAN0.RMID82.UINT32
RSCAN0.RMID82.UINT16[L/H]
RSCAN0.RMID82.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR82.UINT32
RSCAN0.RMPTR82.UINT16[L/H]
RSCAN0.RMPTR82.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF082.UINT32
RSCAN0.RMDF082.UINT16[L/H]
RSCAN0.RMDF082.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF182.UINT32
RSCAN0.RMDF182.UINT16[L/H]
RSCAN0.RMDF182.UINT8[LL/LH/HL/HH]
RSCAN0.RMID83.UINT32
RSCAN0.RMID83.UINT16[L/H]
RSCAN0.RMID83.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR83.UINT32
RSCAN0.RMPTR83.UINT16[L/H]
RSCAN0.RMPTR83.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF083.UINT32
RSCAN0.RMDF083.UINT16[L/H]
RSCAN0.RMDF083.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF183.UINT32
RSCAN0.RMDF183.UINT16[L/H]
RSCAN0.RMDF183.UINT8[LL/LH/HL/HH]
RSCAN0.RMID84.UINT32
RSCAN0.RMID84.UINT16[L/H]
RSCAN0.RMID84.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR84.UINT32
RSCAN0.RMPTR84.UINT16[L/H]
RSCAN0.RMPTR84.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF084.UINT32
RSCAN0.RMDF084.UINT16[L/H]
RSCAN0.RMDF084.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF184.UINT32
RSCAN0.RMDF184.UINT16[L/H]
RSCAN0.RMDF184.UINT8[LL/LH/HL/HH]
RSCAN0.RMID85.UINT32
RSCAN0.RMID85.UINT16[L/H]
RSCAN0.RMID85.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR85.UINT32
RSCAN0.RMPTR85.UINT16[L/H]
RSCAN0.RMPTR85.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF085.UINT32
RSCAN0.RMDF085.UINT16[L/H]
RSCAN0.RMDF085.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF185.UINT32
RSCAN0.RMDF185.UINT16[L/H]
RSCAN0.RMDF185.UINT8[LL/LH/HL/HH]
RSCAN0.RMID86.UINT32
RSCAN0.RMID86.UINT16[L/H]
RSCAN0.RMID86.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR86.UINT32
RSCAN0.RMPTR86.UINT16[L/H]
RSCAN0.RMPTR86.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF086.UINT32
RSCAN0.RMDF086.UINT16[L/H]
RSCAN0.RMDF086.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF186.UINT32
RSCAN0.RMDF186.UINT16[L/H]
RSCAN0.RMDF186.UINT8[LL/LH/HL/HH]
RSCAN0.RMID87.UINT32
RSCAN0.RMID87.UINT16[L/H]
RSCAN0.RMID87.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR87.UINT32
RSCAN0.RMPTR87.UINT16[L/H]
RSCAN0.RMPTR87.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF087.UINT32
RSCAN0.RMDF087.UINT16[L/H]
RSCAN0.RMDF087.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF187.UINT32
RSCAN0.RMDF187.UINT16[L/H]
RSCAN0.RMDF187.UINT8[LL/LH/HL/HH]
RSCAN0.RMID88.UINT32
RSCAN0.RMID88.UINT16[L/H]
RSCAN0.RMID88.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR88.UINT32
RSCAN0.RMPTR88.UINT16[L/H]
RSCAN0.RMPTR88.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF088.UINT32
RSCAN0.RMDF088.UINT16[L/H]
RSCAN0.RMDF088.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF188.UINT32
RSCAN0.RMDF188.UINT16[L/H]
RSCAN0.RMDF188.UINT8[LL/LH/HL/HH]
RSCAN0.RMID89.UINT32
RSCAN0.RMID89.UINT16[L/H]
RSCAN0.RMID89.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR89.UINT32
RSCAN0.RMPTR89.UINT16[L/H]
RSCAN0.RMPTR89.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF089.UINT32
RSCAN0.RMDF089.UINT16[L/H]
RSCAN0.RMDF089.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF189.UINT32
RSCAN0.RMDF189.UINT16[L/H]
RSCAN0.RMDF189.UINT8[LL/LH/HL/HH]
RSCAN0.RMID90.UINT32
RSCAN0.RMID90.UINT16[L/H]
RSCAN0.RMID90.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR90.UINT32
RSCAN0.RMPTR90.UINT16[L/H]
RSCAN0.RMPTR90.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF090.UINT32
RSCAN0.RMDF090.UINT16[L/H]
RSCAN0.RMDF090.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF190.UINT32
RSCAN0.RMDF190.UINT16[L/H]
RSCAN0.RMDF190.UINT8[LL/LH/HL/HH]
RSCAN0.RMID91.UINT32
RSCAN0.RMID91.UINT16[L/H]
RSCAN0.RMID91.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR91.UINT32
RSCAN0.RMPTR91.UINT16[L/H]
RSCAN0.RMPTR91.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF091.UINT32
RSCAN0.RMDF091.UINT16[L/H]
RSCAN0.RMDF091.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF191.UINT32
RSCAN0.RMDF191.UINT16[L/H]
RSCAN0.RMDF191.UINT8[LL/LH/HL/HH]
RSCAN0.RMID92.UINT32
RSCAN0.RMID92.UINT16[L/H]
RSCAN0.RMID92.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR92.UINT32
RSCAN0.RMPTR92.UINT16[L/H]
RSCAN0.RMPTR92.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF092.UINT32
RSCAN0.RMDF092.UINT16[L/H]
RSCAN0.RMDF092.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF192.UINT32
RSCAN0.RMDF192.UINT16[L/H]
RSCAN0.RMDF192.UINT8[LL/LH/HL/HH]
RSCAN0.RMID93.UINT32
RSCAN0.RMID93.UINT16[L/H]
RSCAN0.RMID93.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR93.UINT32
RSCAN0.RMPTR93.UINT16[L/H]
RSCAN0.RMPTR93.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF093.UINT32
RSCAN0.RMDF093.UINT16[L/H]
RSCAN0.RMDF093.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF193.UINT32
RSCAN0.RMDF193.UINT16[L/H]
RSCAN0.RMDF193.UINT8[LL/LH/HL/HH]
RSCAN0.RMID94.UINT32
RSCAN0.RMID94.UINT16[L/H]
RSCAN0.RMID94.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR94.UINT32
RSCAN0.RMPTR94.UINT16[L/H]
RSCAN0.RMPTR94.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF094.UINT32
RSCAN0.RMDF094.UINT16[L/H]
RSCAN0.RMDF094.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF194.UINT32
RSCAN0.RMDF194.UINT16[L/H]
RSCAN0.RMDF194.UINT8[LL/LH/HL/HH]
RSCAN0.RMID95.UINT32
RSCAN0.RMID95.UINT16[L/H]
RSCAN0.RMID95.UINT8[LL/LH/HL/HH]
RSCAN0.RMPTR95.UINT32
RSCAN0.RMPTR95.UINT16[L/H]
RSCAN0.RMPTR95.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF095.UINT32
RSCAN0.RMDF095.UINT16[L/H]
RSCAN0.RMDF095.UINT8[LL/LH/HL/HH]
RSCAN0.RMDF195.UINT32
RSCAN0.RMDF195.UINT16[L/H]
RSCAN0.RMDF195.UINT8[LL/LH/HL/HH]
RSCAN0.RFID0.UINT32
RSCAN0.RFID0.UINT16[L/H]
RSCAN0.RFID0.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR0.UINT32
RSCAN0.RFPTR0.UINT16[L/H]
RSCAN0.RFPTR0.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF00.UINT32
RSCAN0.RFDF00.UINT16[L/H]
RSCAN0.RFDF00.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF10.UINT32
RSCAN0.RFDF10.UINT16[L/H]
RSCAN0.RFDF10.UINT8[LL/LH/HL/HH]
RSCAN0.RFID1.UINT32
RSCAN0.RFID1.UINT16[L/H]
RSCAN0.RFID1.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR1.UINT32
RSCAN0.RFPTR1.UINT16[L/H]
RSCAN0.RFPTR1.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF01.UINT32
RSCAN0.RFDF01.UINT16[L/H]
RSCAN0.RFDF01.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF11.UINT32
RSCAN0.RFDF11.UINT16[L/H]
RSCAN0.RFDF11.UINT8[LL/LH/HL/HH]
RSCAN0.RFID2.UINT32
RSCAN0.RFID2.UINT16[L/H]
RSCAN0.RFID2.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR2.UINT32
RSCAN0.RFPTR2.UINT16[L/H]
RSCAN0.RFPTR2.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF02.UINT32
RSCAN0.RFDF02.UINT16[L/H]
RSCAN0.RFDF02.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF12.UINT32
RSCAN0.RFDF12.UINT16[L/H]
RSCAN0.RFDF12.UINT8[LL/LH/HL/HH]
RSCAN0.RFID3.UINT32
RSCAN0.RFID3.UINT16[L/H]
RSCAN0.RFID3.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR3.UINT32
RSCAN0.RFPTR3.UINT16[L/H]
RSCAN0.RFPTR3.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF03.UINT32
RSCAN0.RFDF03.UINT16[L/H]
RSCAN0.RFDF03.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF13.UINT32
RSCAN0.RFDF13.UINT16[L/H]
RSCAN0.RFDF13.UINT8[LL/LH/HL/HH]
RSCAN0.RFID4.UINT32
RSCAN0.RFID4.UINT16[L/H]
RSCAN0.RFID4.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR4.UINT32
RSCAN0.RFPTR4.UINT16[L/H]
RSCAN0.RFPTR4.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF04.UINT32
RSCAN0.RFDF04.UINT16[L/H]
RSCAN0.RFDF04.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF14.UINT32
RSCAN0.RFDF14.UINT16[L/H]
RSCAN0.RFDF14.UINT8[LL/LH/HL/HH]
RSCAN0.RFID5.UINT32
RSCAN0.RFID5.UINT16[L/H]
RSCAN0.RFID5.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR5.UINT32
RSCAN0.RFPTR5.UINT16[L/H]
RSCAN0.RFPTR5.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF05.UINT32
RSCAN0.RFDF05.UINT16[L/H]
RSCAN0.RFDF05.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF15.UINT32
RSCAN0.RFDF15.UINT16[L/H]
RSCAN0.RFDF15.UINT8[LL/LH/HL/HH]
RSCAN0.RFID6.UINT32
RSCAN0.RFID6.UINT16[L/H]
RSCAN0.RFID6.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR6.UINT32
RSCAN0.RFPTR6.UINT16[L/H]
RSCAN0.RFPTR6.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF06.UINT32
RSCAN0.RFDF06.UINT16[L/H]
RSCAN0.RFDF06.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF16.UINT32
RSCAN0.RFDF16.UINT16[L/H]
RSCAN0.RFDF16.UINT8[LL/LH/HL/HH]
RSCAN0.RFID7.UINT32
RSCAN0.RFID7.UINT16[L/H]
RSCAN0.RFID7.UINT8[LL/LH/HL/HH]
RSCAN0.RFPTR7.UINT32
RSCAN0.RFPTR7.UINT16[L/H]
RSCAN0.RFPTR7.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF07.UINT32
RSCAN0.RFDF07.UINT16[L/H]
RSCAN0.RFDF07.UINT8[LL/LH/HL/HH]
RSCAN0.RFDF17.UINT32
RSCAN0.RFDF17.UINT16[L/H]
RSCAN0.RFDF17.UINT8[LL/LH/HL/HH]
RSCAN0.CFID0.UINT32
RSCAN0.CFID0.UINT16[L/H]
RSCAN0.CFID0.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR0.UINT32
RSCAN0.CFPTR0.UINT16[L/H]
RSCAN0.CFPTR0.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF00.UINT32
RSCAN0.CFDF00.UINT16[L/H]
RSCAN0.CFDF00.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF10.UINT32
RSCAN0.CFDF10.UINT16[L/H]
RSCAN0.CFDF10.UINT8[LL/LH/HL/HH]
RSCAN0.CFID1.UINT32
RSCAN0.CFID1.UINT16[L/H]
RSCAN0.CFID1.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR1.UINT32
RSCAN0.CFPTR1.UINT16[L/H]
RSCAN0.CFPTR1.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF01.UINT32
RSCAN0.CFDF01.UINT16[L/H]
RSCAN0.CFDF01.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF11.UINT32
RSCAN0.CFDF11.UINT16[L/H]
RSCAN0.CFDF11.UINT8[LL/LH/HL/HH]
RSCAN0.CFID2.UINT32
RSCAN0.CFID2.UINT16[L/H]
RSCAN0.CFID2.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR2.UINT32
RSCAN0.CFPTR2.UINT16[L/H]
RSCAN0.CFPTR2.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF02.UINT32
RSCAN0.CFDF02.UINT16[L/H]
RSCAN0.CFDF02.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF12.UINT32
RSCAN0.CFDF12.UINT16[L/H]
RSCAN0.CFDF12.UINT8[LL/LH/HL/HH]
RSCAN0.CFID3.UINT32
RSCAN0.CFID3.UINT16[L/H]
RSCAN0.CFID3.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR3.UINT32
RSCAN0.CFPTR3.UINT16[L/H]
RSCAN0.CFPTR3.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF03.UINT32
RSCAN0.CFDF03.UINT16[L/H]
RSCAN0.CFDF03.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF13.UINT32
RSCAN0.CFDF13.UINT16[L/H]
RSCAN0.CFDF13.UINT8[LL/LH/HL/HH]
RSCAN0.CFID4.UINT32
RSCAN0.CFID4.UINT16[L/H]
RSCAN0.CFID4.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR4.UINT32
RSCAN0.CFPTR4.UINT16[L/H]
RSCAN0.CFPTR4.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF04.UINT32
RSCAN0.CFDF04.UINT16[L/H]
RSCAN0.CFDF04.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF14.UINT32
RSCAN0.CFDF14.UINT16[L/H]
RSCAN0.CFDF14.UINT8[LL/LH/HL/HH]
RSCAN0.CFID5.UINT32
RSCAN0.CFID5.UINT16[L/H]
RSCAN0.CFID5.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR5.UINT32
RSCAN0.CFPTR5.UINT16[L/H]
RSCAN0.CFPTR5.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF05.UINT32
RSCAN0.CFDF05.UINT16[L/H]
RSCAN0.CFDF05.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF15.UINT32
RSCAN0.CFDF15.UINT16[L/H]
RSCAN0.CFDF15.UINT8[LL/LH/HL/HH]
RSCAN0.CFID6.UINT32
RSCAN0.CFID6.UINT16[L/H]
RSCAN0.CFID6.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR6.UINT32
RSCAN0.CFPTR6.UINT16[L/H]
RSCAN0.CFPTR6.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF06.UINT32
RSCAN0.CFDF06.UINT16[L/H]
RSCAN0.CFDF06.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF16.UINT32
RSCAN0.CFDF16.UINT16[L/H]
RSCAN0.CFDF16.UINT8[LL/LH/HL/HH]
RSCAN0.CFID7.UINT32
RSCAN0.CFID7.UINT16[L/H]
RSCAN0.CFID7.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR7.UINT32
RSCAN0.CFPTR7.UINT16[L/H]
RSCAN0.CFPTR7.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF07.UINT32
RSCAN0.CFDF07.UINT16[L/H]
RSCAN0.CFDF07.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF17.UINT32
RSCAN0.CFDF17.UINT16[L/H]
RSCAN0.CFDF17.UINT8[LL/LH/HL/HH]
RSCAN0.CFID8.UINT32
RSCAN0.CFID8.UINT16[L/H]
RSCAN0.CFID8.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR8.UINT32
RSCAN0.CFPTR8.UINT16[L/H]
RSCAN0.CFPTR8.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF08.UINT32
RSCAN0.CFDF08.UINT16[L/H]
RSCAN0.CFDF08.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF18.UINT32
RSCAN0.CFDF18.UINT16[L/H]
RSCAN0.CFDF18.UINT8[LL/LH/HL/HH]
RSCAN0.CFID9.UINT32
RSCAN0.CFID9.UINT16[L/H]
RSCAN0.CFID9.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR9.UINT32
RSCAN0.CFPTR9.UINT16[L/H]
RSCAN0.CFPTR9.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF09.UINT32
RSCAN0.CFDF09.UINT16[L/H]
RSCAN0.CFDF09.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF19.UINT32
RSCAN0.CFDF19.UINT16[L/H]
RSCAN0.CFDF19.UINT8[LL/LH/HL/HH]
RSCAN0.CFID10.UINT32
RSCAN0.CFID10.UINT16[L/H]
RSCAN0.CFID10.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR10.UINT32
RSCAN0.CFPTR10.UINT16[L/H]
RSCAN0.CFPTR10.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF010.UINT32
RSCAN0.CFDF010.UINT16[L/H]
RSCAN0.CFDF010.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF110.UINT32
RSCAN0.CFDF110.UINT16[L/H]
RSCAN0.CFDF110.UINT8[LL/LH/HL/HH]
RSCAN0.CFID11.UINT32
RSCAN0.CFID11.UINT16[L/H]
RSCAN0.CFID11.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR11.UINT32
RSCAN0.CFPTR11.UINT16[L/H]
RSCAN0.CFPTR11.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF011.UINT32
RSCAN0.CFDF011.UINT16[L/H]
RSCAN0.CFDF011.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF111.UINT32
RSCAN0.CFDF111.UINT16[L/H]
RSCAN0.CFDF111.UINT8[LL/LH/HL/HH]
RSCAN0.CFID12.UINT32
RSCAN0.CFID12.UINT16[L/H]
RSCAN0.CFID12.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR12.UINT32
RSCAN0.CFPTR12.UINT16[L/H]
RSCAN0.CFPTR12.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF012.UINT32
RSCAN0.CFDF012.UINT16[L/H]
RSCAN0.CFDF012.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF112.UINT32
RSCAN0.CFDF112.UINT16[L/H]
RSCAN0.CFDF112.UINT8[LL/LH/HL/HH]
RSCAN0.CFID13.UINT32
RSCAN0.CFID13.UINT16[L/H]
RSCAN0.CFID13.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR13.UINT32
RSCAN0.CFPTR13.UINT16[L/H]
RSCAN0.CFPTR13.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF013.UINT32
RSCAN0.CFDF013.UINT16[L/H]
RSCAN0.CFDF013.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF113.UINT32
RSCAN0.CFDF113.UINT16[L/H]
RSCAN0.CFDF113.UINT8[LL/LH/HL/HH]
RSCAN0.CFID14.UINT32
RSCAN0.CFID14.UINT16[L/H]
RSCAN0.CFID14.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR14.UINT32
RSCAN0.CFPTR14.UINT16[L/H]
RSCAN0.CFPTR14.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF014.UINT32
RSCAN0.CFDF014.UINT16[L/H]
RSCAN0.CFDF014.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF114.UINT32
RSCAN0.CFDF114.UINT16[L/H]
RSCAN0.CFDF114.UINT8[LL/LH/HL/HH]
RSCAN0.CFID15.UINT32
RSCAN0.CFID15.UINT16[L/H]
RSCAN0.CFID15.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR15.UINT32
RSCAN0.CFPTR15.UINT16[L/H]
RSCAN0.CFPTR15.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF015.UINT32
RSCAN0.CFDF015.UINT16[L/H]
RSCAN0.CFDF015.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF115.UINT32
RSCAN0.CFDF115.UINT16[L/H]
RSCAN0.CFDF115.UINT8[LL/LH/HL/HH]
RSCAN0.CFID16.UINT32
RSCAN0.CFID16.UINT16[L/H]
RSCAN0.CFID16.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR16.UINT32
RSCAN0.CFPTR16.UINT16[L/H]
RSCAN0.CFPTR16.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF016.UINT32
RSCAN0.CFDF016.UINT16[L/H]
RSCAN0.CFDF016.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF116.UINT32
RSCAN0.CFDF116.UINT16[L/H]
RSCAN0.CFDF116.UINT8[LL/LH/HL/HH]
RSCAN0.CFID17.UINT32
RSCAN0.CFID17.UINT16[L/H]
RSCAN0.CFID17.UINT8[LL/LH/HL/HH]
RSCAN0.CFPTR17.UINT32
RSCAN0.CFPTR17.UINT16[L/H]
RSCAN0.CFPTR17.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF017.UINT32
RSCAN0.CFDF017.UINT16[L/H]
RSCAN0.CFDF017.UINT8[LL/LH/HL/HH]
RSCAN0.CFDF117.UINT32
RSCAN0.CFDF117.UINT16[L/H]
RSCAN0.CFDF117.UINT8[LL/LH/HL/HH]
RSCAN0.TMID0.UINT32
RSCAN0.TMID0.UINT16[L/H]
RSCAN0.TMID0.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR0.UINT32
RSCAN0.TMPTR0.UINT16[H]
RSCAN0.TMPTR0.UINT8[HL/HH]
RSCAN0.TMDF00.UINT32
RSCAN0.TMDF00.UINT16[L/H]
RSCAN0.TMDF00.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF10.UINT32
RSCAN0.TMDF10.UINT16[L/H]
RSCAN0.TMDF10.UINT8[LL/LH/HL/HH]
RSCAN0.TMID1.UINT32
RSCAN0.TMID1.UINT16[L/H]
RSCAN0.TMID1.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR1.UINT32
RSCAN0.TMPTR1.UINT16[H]
RSCAN0.TMPTR1.UINT8[HL/HH]
RSCAN0.TMDF01.UINT32
RSCAN0.TMDF01.UINT16[L/H]
RSCAN0.TMDF01.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF11.UINT32
RSCAN0.TMDF11.UINT16[L/H]
RSCAN0.TMDF11.UINT8[LL/LH/HL/HH]
RSCAN0.TMID2.UINT32
RSCAN0.TMID2.UINT16[L/H]
RSCAN0.TMID2.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR2.UINT32
RSCAN0.TMPTR2.UINT16[H]
RSCAN0.TMPTR2.UINT8[HL/HH]
RSCAN0.TMDF02.UINT32
RSCAN0.TMDF02.UINT16[L/H]
RSCAN0.TMDF02.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF12.UINT32
RSCAN0.TMDF12.UINT16[L/H]
RSCAN0.TMDF12.UINT8[LL/LH/HL/HH]
RSCAN0.TMID3.UINT32
RSCAN0.TMID3.UINT16[L/H]
RSCAN0.TMID3.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR3.UINT32
RSCAN0.TMPTR3.UINT16[H]
RSCAN0.TMPTR3.UINT8[HL/HH]
RSCAN0.TMDF03.UINT32
RSCAN0.TMDF03.UINT16[L/H]
RSCAN0.TMDF03.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF13.UINT32
RSCAN0.TMDF13.UINT16[L/H]
RSCAN0.TMDF13.UINT8[LL/LH/HL/HH]
RSCAN0.TMID4.UINT32
RSCAN0.TMID4.UINT16[L/H]
RSCAN0.TMID4.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR4.UINT32
RSCAN0.TMPTR4.UINT16[H]
RSCAN0.TMPTR4.UINT8[HL/HH]
RSCAN0.TMDF04.UINT32
RSCAN0.TMDF04.UINT16[L/H]
RSCAN0.TMDF04.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF14.UINT32
RSCAN0.TMDF14.UINT16[L/H]
RSCAN0.TMDF14.UINT8[LL/LH/HL/HH]
RSCAN0.TMID5.UINT32
RSCAN0.TMID5.UINT16[L/H]
RSCAN0.TMID5.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR5.UINT32
RSCAN0.TMPTR5.UINT16[H]
RSCAN0.TMPTR5.UINT8[HL/HH]
RSCAN0.TMDF05.UINT32
RSCAN0.TMDF05.UINT16[L/H]
RSCAN0.TMDF05.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF15.UINT32
RSCAN0.TMDF15.UINT16[L/H]
RSCAN0.TMDF15.UINT8[LL/LH/HL/HH]
RSCAN0.TMID6.UINT32
RSCAN0.TMID6.UINT16[L/H]
RSCAN0.TMID6.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR6.UINT32
RSCAN0.TMPTR6.UINT16[H]
RSCAN0.TMPTR6.UINT8[HL/HH]
RSCAN0.TMDF06.UINT32
RSCAN0.TMDF06.UINT16[L/H]
RSCAN0.TMDF06.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF16.UINT32
RSCAN0.TMDF16.UINT16[L/H]
RSCAN0.TMDF16.UINT8[LL/LH/HL/HH]
RSCAN0.TMID7.UINT32
RSCAN0.TMID7.UINT16[L/H]
RSCAN0.TMID7.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR7.UINT32
RSCAN0.TMPTR7.UINT16[H]
RSCAN0.TMPTR7.UINT8[HL/HH]
RSCAN0.TMDF07.UINT32
RSCAN0.TMDF07.UINT16[L/H]
RSCAN0.TMDF07.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF17.UINT32
RSCAN0.TMDF17.UINT16[L/H]
RSCAN0.TMDF17.UINT8[LL/LH/HL/HH]
RSCAN0.TMID8.UINT32
RSCAN0.TMID8.UINT16[L/H]
RSCAN0.TMID8.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR8.UINT32
RSCAN0.TMPTR8.UINT16[H]
RSCAN0.TMPTR8.UINT8[HL/HH]
RSCAN0.TMDF08.UINT32
RSCAN0.TMDF08.UINT16[L/H]
RSCAN0.TMDF08.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF18.UINT32
RSCAN0.TMDF18.UINT16[L/H]
RSCAN0.TMDF18.UINT8[LL/LH/HL/HH]
RSCAN0.TMID9.UINT32
RSCAN0.TMID9.UINT16[L/H]
RSCAN0.TMID9.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR9.UINT32
RSCAN0.TMPTR9.UINT16[H]
RSCAN0.TMPTR9.UINT8[HL/HH]
RSCAN0.TMDF09.UINT32
RSCAN0.TMDF09.UINT16[L/H]
RSCAN0.TMDF09.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF19.UINT32
RSCAN0.TMDF19.UINT16[L/H]
RSCAN0.TMDF19.UINT8[LL/LH/HL/HH]
RSCAN0.TMID10.UINT32
RSCAN0.TMID10.UINT16[L/H]
RSCAN0.TMID10.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR10.UINT32
RSCAN0.TMPTR10.UINT16[H]
RSCAN0.TMPTR10.UINT8[HL/HH]
RSCAN0.TMDF010.UINT32
RSCAN0.TMDF010.UINT16[L/H]
RSCAN0.TMDF010.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF110.UINT32
RSCAN0.TMDF110.UINT16[L/H]
RSCAN0.TMDF110.UINT8[LL/LH/HL/HH]
RSCAN0.TMID11.UINT32
RSCAN0.TMID11.UINT16[L/H]
RSCAN0.TMID11.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR11.UINT32
RSCAN0.TMPTR11.UINT16[H]
RSCAN0.TMPTR11.UINT8[HL/HH]
RSCAN0.TMDF011.UINT32
RSCAN0.TMDF011.UINT16[L/H]
RSCAN0.TMDF011.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF111.UINT32
RSCAN0.TMDF111.UINT16[L/H]
RSCAN0.TMDF111.UINT8[LL/LH/HL/HH]
RSCAN0.TMID12.UINT32
RSCAN0.TMID12.UINT16[L/H]
RSCAN0.TMID12.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR12.UINT32
RSCAN0.TMPTR12.UINT16[H]
RSCAN0.TMPTR12.UINT8[HL/HH]
RSCAN0.TMDF012.UINT32
RSCAN0.TMDF012.UINT16[L/H]
RSCAN0.TMDF012.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF112.UINT32
RSCAN0.TMDF112.UINT16[L/H]
RSCAN0.TMDF112.UINT8[LL/LH/HL/HH]
RSCAN0.TMID13.UINT32
RSCAN0.TMID13.UINT16[L/H]
RSCAN0.TMID13.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR13.UINT32
RSCAN0.TMPTR13.UINT16[H]
RSCAN0.TMPTR13.UINT8[HL/HH]
RSCAN0.TMDF013.UINT32
RSCAN0.TMDF013.UINT16[L/H]
RSCAN0.TMDF013.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF113.UINT32
RSCAN0.TMDF113.UINT16[L/H]
RSCAN0.TMDF113.UINT8[LL/LH/HL/HH]
RSCAN0.TMID14.UINT32
RSCAN0.TMID14.UINT16[L/H]
RSCAN0.TMID14.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR14.UINT32
RSCAN0.TMPTR14.UINT16[H]
RSCAN0.TMPTR14.UINT8[HL/HH]
RSCAN0.TMDF014.UINT32
RSCAN0.TMDF014.UINT16[L/H]
RSCAN0.TMDF014.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF114.UINT32
RSCAN0.TMDF114.UINT16[L/H]
RSCAN0.TMDF114.UINT8[LL/LH/HL/HH]
RSCAN0.TMID15.UINT32
RSCAN0.TMID15.UINT16[L/H]
RSCAN0.TMID15.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR15.UINT32
RSCAN0.TMPTR15.UINT16[H]
RSCAN0.TMPTR15.UINT8[HL/HH]
RSCAN0.TMDF015.UINT32
RSCAN0.TMDF015.UINT16[L/H]
RSCAN0.TMDF015.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF115.UINT32
RSCAN0.TMDF115.UINT16[L/H]
RSCAN0.TMDF115.UINT8[LL/LH/HL/HH]
RSCAN0.TMID16.UINT32
RSCAN0.TMID16.UINT16[L/H]
RSCAN0.TMID16.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR16.UINT32
RSCAN0.TMPTR16.UINT16[H]
RSCAN0.TMPTR16.UINT8[HL/HH]
RSCAN0.TMDF016.UINT32
RSCAN0.TMDF016.UINT16[L/H]
RSCAN0.TMDF016.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF116.UINT32
RSCAN0.TMDF116.UINT16[L/H]
RSCAN0.TMDF116.UINT8[LL/LH/HL/HH]
RSCAN0.TMID17.UINT32
RSCAN0.TMID17.UINT16[L/H]
RSCAN0.TMID17.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR17.UINT32
RSCAN0.TMPTR17.UINT16[H]
RSCAN0.TMPTR17.UINT8[HL/HH]
RSCAN0.TMDF017.UINT32
RSCAN0.TMDF017.UINT16[L/H]
RSCAN0.TMDF017.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF117.UINT32
RSCAN0.TMDF117.UINT16[L/H]
RSCAN0.TMDF117.UINT8[LL/LH/HL/HH]
RSCAN0.TMID18.UINT32
RSCAN0.TMID18.UINT16[L/H]
RSCAN0.TMID18.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR18.UINT32
RSCAN0.TMPTR18.UINT16[H]
RSCAN0.TMPTR18.UINT8[HL/HH]
RSCAN0.TMDF018.UINT32
RSCAN0.TMDF018.UINT16[L/H]
RSCAN0.TMDF018.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF118.UINT32
RSCAN0.TMDF118.UINT16[L/H]
RSCAN0.TMDF118.UINT8[LL/LH/HL/HH]
RSCAN0.TMID19.UINT32
RSCAN0.TMID19.UINT16[L/H]
RSCAN0.TMID19.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR19.UINT32
RSCAN0.TMPTR19.UINT16[H]
RSCAN0.TMPTR19.UINT8[HL/HH]
RSCAN0.TMDF019.UINT32
RSCAN0.TMDF019.UINT16[L/H]
RSCAN0.TMDF019.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF119.UINT32
RSCAN0.TMDF119.UINT16[L/H]
RSCAN0.TMDF119.UINT8[LL/LH/HL/HH]
RSCAN0.TMID20.UINT32
RSCAN0.TMID20.UINT16[L/H]
RSCAN0.TMID20.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR20.UINT32
RSCAN0.TMPTR20.UINT16[H]
RSCAN0.TMPTR20.UINT8[HL/HH]
RSCAN0.TMDF020.UINT32
RSCAN0.TMDF020.UINT16[L/H]
RSCAN0.TMDF020.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF120.UINT32
RSCAN0.TMDF120.UINT16[L/H]
RSCAN0.TMDF120.UINT8[LL/LH/HL/HH]
RSCAN0.TMID21.UINT32
RSCAN0.TMID21.UINT16[L/H]
RSCAN0.TMID21.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR21.UINT32
RSCAN0.TMPTR21.UINT16[H]
RSCAN0.TMPTR21.UINT8[HL/HH]
RSCAN0.TMDF021.UINT32
RSCAN0.TMDF021.UINT16[L/H]
RSCAN0.TMDF021.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF121.UINT32
RSCAN0.TMDF121.UINT16[L/H]
RSCAN0.TMDF121.UINT8[LL/LH/HL/HH]
RSCAN0.TMID22.UINT32
RSCAN0.TMID22.UINT16[L/H]
RSCAN0.TMID22.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR22.UINT32
RSCAN0.TMPTR22.UINT16[H]
RSCAN0.TMPTR22.UINT8[HL/HH]
RSCAN0.TMDF022.UINT32
RSCAN0.TMDF022.UINT16[L/H]
RSCAN0.TMDF022.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF122.UINT32
RSCAN0.TMDF122.UINT16[L/H]
RSCAN0.TMDF122.UINT8[LL/LH/HL/HH]
RSCAN0.TMID23.UINT32
RSCAN0.TMID23.UINT16[L/H]
RSCAN0.TMID23.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR23.UINT32
RSCAN0.TMPTR23.UINT16[H]
RSCAN0.TMPTR23.UINT8[HL/HH]
RSCAN0.TMDF023.UINT32
RSCAN0.TMDF023.UINT16[L/H]
RSCAN0.TMDF023.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF123.UINT32
RSCAN0.TMDF123.UINT16[L/H]
RSCAN0.TMDF123.UINT8[LL/LH/HL/HH]
RSCAN0.TMID24.UINT32
RSCAN0.TMID24.UINT16[L/H]
RSCAN0.TMID24.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR24.UINT32
RSCAN0.TMPTR24.UINT16[H]
RSCAN0.TMPTR24.UINT8[HL/HH]
RSCAN0.TMDF024.UINT32
RSCAN0.TMDF024.UINT16[L/H]
RSCAN0.TMDF024.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF124.UINT32
RSCAN0.TMDF124.UINT16[L/H]
RSCAN0.TMDF124.UINT8[LL/LH/HL/HH]
RSCAN0.TMID25.UINT32
RSCAN0.TMID25.UINT16[L/H]
RSCAN0.TMID25.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR25.UINT32
RSCAN0.TMPTR25.UINT16[H]
RSCAN0.TMPTR25.UINT8[HL/HH]
RSCAN0.TMDF025.UINT32
RSCAN0.TMDF025.UINT16[L/H]
RSCAN0.TMDF025.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF125.UINT32
RSCAN0.TMDF125.UINT16[L/H]
RSCAN0.TMDF125.UINT8[LL/LH/HL/HH]
RSCAN0.TMID26.UINT32
RSCAN0.TMID26.UINT16[L/H]
RSCAN0.TMID26.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR26.UINT32
RSCAN0.TMPTR26.UINT16[H]
RSCAN0.TMPTR26.UINT8[HL/HH]
RSCAN0.TMDF026.UINT32
RSCAN0.TMDF026.UINT16[L/H]
RSCAN0.TMDF026.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF126.UINT32
RSCAN0.TMDF126.UINT16[L/H]
RSCAN0.TMDF126.UINT8[LL/LH/HL/HH]
RSCAN0.TMID27.UINT32
RSCAN0.TMID27.UINT16[L/H]
RSCAN0.TMID27.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR27.UINT32
RSCAN0.TMPTR27.UINT16[H]
RSCAN0.TMPTR27.UINT8[HL/HH]
RSCAN0.TMDF027.UINT32
RSCAN0.TMDF027.UINT16[L/H]
RSCAN0.TMDF027.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF127.UINT32
RSCAN0.TMDF127.UINT16[L/H]
RSCAN0.TMDF127.UINT8[LL/LH/HL/HH]
RSCAN0.TMID28.UINT32
RSCAN0.TMID28.UINT16[L/H]
RSCAN0.TMID28.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR28.UINT32
RSCAN0.TMPTR28.UINT16[H]
RSCAN0.TMPTR28.UINT8[HL/HH]
RSCAN0.TMDF028.UINT32
RSCAN0.TMDF028.UINT16[L/H]
RSCAN0.TMDF028.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF128.UINT32
RSCAN0.TMDF128.UINT16[L/H]
RSCAN0.TMDF128.UINT8[LL/LH/HL/HH]
RSCAN0.TMID29.UINT32
RSCAN0.TMID29.UINT16[L/H]
RSCAN0.TMID29.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR29.UINT32
RSCAN0.TMPTR29.UINT16[H]
RSCAN0.TMPTR29.UINT8[HL/HH]
RSCAN0.TMDF029.UINT32
RSCAN0.TMDF029.UINT16[L/H]
RSCAN0.TMDF029.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF129.UINT32
RSCAN0.TMDF129.UINT16[L/H]
RSCAN0.TMDF129.UINT8[LL/LH/HL/HH]
RSCAN0.TMID30.UINT32
RSCAN0.TMID30.UINT16[L/H]
RSCAN0.TMID30.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR30.UINT32
RSCAN0.TMPTR30.UINT16[H]
RSCAN0.TMPTR30.UINT8[HL/HH]
RSCAN0.TMDF030.UINT32
RSCAN0.TMDF030.UINT16[L/H]
RSCAN0.TMDF030.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF130.UINT32
RSCAN0.TMDF130.UINT16[L/H]
RSCAN0.TMDF130.UINT8[LL/LH/HL/HH]
RSCAN0.TMID31.UINT32
RSCAN0.TMID31.UINT16[L/H]
RSCAN0.TMID31.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR31.UINT32
RSCAN0.TMPTR31.UINT16[H]
RSCAN0.TMPTR31.UINT8[HL/HH]
RSCAN0.TMDF031.UINT32
RSCAN0.TMDF031.UINT16[L/H]
RSCAN0.TMDF031.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF131.UINT32
RSCAN0.TMDF131.UINT16[L/H]
RSCAN0.TMDF131.UINT8[LL/LH/HL/HH]
RSCAN0.TMID32.UINT32
RSCAN0.TMID32.UINT16[L/H]
RSCAN0.TMID32.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR32.UINT32
RSCAN0.TMPTR32.UINT16[H]
RSCAN0.TMPTR32.UINT8[HL/HH]
RSCAN0.TMDF032.UINT32
RSCAN0.TMDF032.UINT16[L/H]
RSCAN0.TMDF032.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF132.UINT32
RSCAN0.TMDF132.UINT16[L/H]
RSCAN0.TMDF132.UINT8[LL/LH/HL/HH]
RSCAN0.TMID33.UINT32
RSCAN0.TMID33.UINT16[L/H]
RSCAN0.TMID33.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR33.UINT32
RSCAN0.TMPTR33.UINT16[H]
RSCAN0.TMPTR33.UINT8[HL/HH]
RSCAN0.TMDF033.UINT32
RSCAN0.TMDF033.UINT16[L/H]
RSCAN0.TMDF033.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF133.UINT32
RSCAN0.TMDF133.UINT16[L/H]
RSCAN0.TMDF133.UINT8[LL/LH/HL/HH]
RSCAN0.TMID34.UINT32
RSCAN0.TMID34.UINT16[L/H]
RSCAN0.TMID34.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR34.UINT32
RSCAN0.TMPTR34.UINT16[H]
RSCAN0.TMPTR34.UINT8[HL/HH]
RSCAN0.TMDF034.UINT32
RSCAN0.TMDF034.UINT16[L/H]
RSCAN0.TMDF034.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF134.UINT32
RSCAN0.TMDF134.UINT16[L/H]
RSCAN0.TMDF134.UINT8[LL/LH/HL/HH]
RSCAN0.TMID35.UINT32
RSCAN0.TMID35.UINT16[L/H]
RSCAN0.TMID35.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR35.UINT32
RSCAN0.TMPTR35.UINT16[H]
RSCAN0.TMPTR35.UINT8[HL/HH]
RSCAN0.TMDF035.UINT32
RSCAN0.TMDF035.UINT16[L/H]
RSCAN0.TMDF035.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF135.UINT32
RSCAN0.TMDF135.UINT16[L/H]
RSCAN0.TMDF135.UINT8[LL/LH/HL/HH]
RSCAN0.TMID36.UINT32
RSCAN0.TMID36.UINT16[L/H]
RSCAN0.TMID36.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR36.UINT32
RSCAN0.TMPTR36.UINT16[H]
RSCAN0.TMPTR36.UINT8[HL/HH]
RSCAN0.TMDF036.UINT32
RSCAN0.TMDF036.UINT16[L/H]
RSCAN0.TMDF036.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF136.UINT32
RSCAN0.TMDF136.UINT16[L/H]
RSCAN0.TMDF136.UINT8[LL/LH/HL/HH]
RSCAN0.TMID37.UINT32
RSCAN0.TMID37.UINT16[L/H]
RSCAN0.TMID37.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR37.UINT32
RSCAN0.TMPTR37.UINT16[H]
RSCAN0.TMPTR37.UINT8[HL/HH]
RSCAN0.TMDF037.UINT32
RSCAN0.TMDF037.UINT16[L/H]
RSCAN0.TMDF037.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF137.UINT32
RSCAN0.TMDF137.UINT16[L/H]
RSCAN0.TMDF137.UINT8[LL/LH/HL/HH]
RSCAN0.TMID38.UINT32
RSCAN0.TMID38.UINT16[L/H]
RSCAN0.TMID38.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR38.UINT32
RSCAN0.TMPTR38.UINT16[H]
RSCAN0.TMPTR38.UINT8[HL/HH]
RSCAN0.TMDF038.UINT32
RSCAN0.TMDF038.UINT16[L/H]
RSCAN0.TMDF038.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF138.UINT32
RSCAN0.TMDF138.UINT16[L/H]
RSCAN0.TMDF138.UINT8[LL/LH/HL/HH]
RSCAN0.TMID39.UINT32
RSCAN0.TMID39.UINT16[L/H]
RSCAN0.TMID39.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR39.UINT32
RSCAN0.TMPTR39.UINT16[H]
RSCAN0.TMPTR39.UINT8[HL/HH]
RSCAN0.TMDF039.UINT32
RSCAN0.TMDF039.UINT16[L/H]
RSCAN0.TMDF039.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF139.UINT32
RSCAN0.TMDF139.UINT16[L/H]
RSCAN0.TMDF139.UINT8[LL/LH/HL/HH]
RSCAN0.TMID40.UINT32
RSCAN0.TMID40.UINT16[L/H]
RSCAN0.TMID40.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR40.UINT32
RSCAN0.TMPTR40.UINT16[H]
RSCAN0.TMPTR40.UINT8[HL/HH]
RSCAN0.TMDF040.UINT32
RSCAN0.TMDF040.UINT16[L/H]
RSCAN0.TMDF040.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF140.UINT32
RSCAN0.TMDF140.UINT16[L/H]
RSCAN0.TMDF140.UINT8[LL/LH/HL/HH]
RSCAN0.TMID41.UINT32
RSCAN0.TMID41.UINT16[L/H]
RSCAN0.TMID41.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR41.UINT32
RSCAN0.TMPTR41.UINT16[H]
RSCAN0.TMPTR41.UINT8[HL/HH]
RSCAN0.TMDF041.UINT32
RSCAN0.TMDF041.UINT16[L/H]
RSCAN0.TMDF041.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF141.UINT32
RSCAN0.TMDF141.UINT16[L/H]
RSCAN0.TMDF141.UINT8[LL/LH/HL/HH]
RSCAN0.TMID42.UINT32
RSCAN0.TMID42.UINT16[L/H]
RSCAN0.TMID42.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR42.UINT32
RSCAN0.TMPTR42.UINT16[H]
RSCAN0.TMPTR42.UINT8[HL/HH]
RSCAN0.TMDF042.UINT32
RSCAN0.TMDF042.UINT16[L/H]
RSCAN0.TMDF042.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF142.UINT32
RSCAN0.TMDF142.UINT16[L/H]
RSCAN0.TMDF142.UINT8[LL/LH/HL/HH]
RSCAN0.TMID43.UINT32
RSCAN0.TMID43.UINT16[L/H]
RSCAN0.TMID43.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR43.UINT32
RSCAN0.TMPTR43.UINT16[H]
RSCAN0.TMPTR43.UINT8[HL/HH]
RSCAN0.TMDF043.UINT32
RSCAN0.TMDF043.UINT16[L/H]
RSCAN0.TMDF043.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF143.UINT32
RSCAN0.TMDF143.UINT16[L/H]
RSCAN0.TMDF143.UINT8[LL/LH/HL/HH]
RSCAN0.TMID44.UINT32
RSCAN0.TMID44.UINT16[L/H]
RSCAN0.TMID44.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR44.UINT32
RSCAN0.TMPTR44.UINT16[H]
RSCAN0.TMPTR44.UINT8[HL/HH]
RSCAN0.TMDF044.UINT32
RSCAN0.TMDF044.UINT16[L/H]
RSCAN0.TMDF044.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF144.UINT32
RSCAN0.TMDF144.UINT16[L/H]
RSCAN0.TMDF144.UINT8[LL/LH/HL/HH]
RSCAN0.TMID45.UINT32
RSCAN0.TMID45.UINT16[L/H]
RSCAN0.TMID45.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR45.UINT32
RSCAN0.TMPTR45.UINT16[H]
RSCAN0.TMPTR45.UINT8[HL/HH]
RSCAN0.TMDF045.UINT32
RSCAN0.TMDF045.UINT16[L/H]
RSCAN0.TMDF045.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF145.UINT32
RSCAN0.TMDF145.UINT16[L/H]
RSCAN0.TMDF145.UINT8[LL/LH/HL/HH]
RSCAN0.TMID46.UINT32
RSCAN0.TMID46.UINT16[L/H]
RSCAN0.TMID46.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR46.UINT32
RSCAN0.TMPTR46.UINT16[H]
RSCAN0.TMPTR46.UINT8[HL/HH]
RSCAN0.TMDF046.UINT32
RSCAN0.TMDF046.UINT16[L/H]
RSCAN0.TMDF046.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF146.UINT32
RSCAN0.TMDF146.UINT16[L/H]
RSCAN0.TMDF146.UINT8[LL/LH/HL/HH]
RSCAN0.TMID47.UINT32
RSCAN0.TMID47.UINT16[L/H]
RSCAN0.TMID47.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR47.UINT32
RSCAN0.TMPTR47.UINT16[H]
RSCAN0.TMPTR47.UINT8[HL/HH]
RSCAN0.TMDF047.UINT32
RSCAN0.TMDF047.UINT16[L/H]
RSCAN0.TMDF047.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF147.UINT32
RSCAN0.TMDF147.UINT16[L/H]
RSCAN0.TMDF147.UINT8[LL/LH/HL/HH]
RSCAN0.TMID48.UINT32
RSCAN0.TMID48.UINT16[L/H]
RSCAN0.TMID48.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR48.UINT32
RSCAN0.TMPTR48.UINT16[H]
RSCAN0.TMPTR48.UINT8[HL/HH]
RSCAN0.TMDF048.UINT32
RSCAN0.TMDF048.UINT16[L/H]
RSCAN0.TMDF048.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF148.UINT32
RSCAN0.TMDF148.UINT16[L/H]
RSCAN0.TMDF148.UINT8[LL/LH/HL/HH]
RSCAN0.TMID49.UINT32
RSCAN0.TMID49.UINT16[L/H]
RSCAN0.TMID49.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR49.UINT32
RSCAN0.TMPTR49.UINT16[H]
RSCAN0.TMPTR49.UINT8[HL/HH]
RSCAN0.TMDF049.UINT32
RSCAN0.TMDF049.UINT16[L/H]
RSCAN0.TMDF049.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF149.UINT32
RSCAN0.TMDF149.UINT16[L/H]
RSCAN0.TMDF149.UINT8[LL/LH/HL/HH]
RSCAN0.TMID50.UINT32
RSCAN0.TMID50.UINT16[L/H]
RSCAN0.TMID50.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR50.UINT32
RSCAN0.TMPTR50.UINT16[H]
RSCAN0.TMPTR50.UINT8[HL/HH]
RSCAN0.TMDF050.UINT32
RSCAN0.TMDF050.UINT16[L/H]
RSCAN0.TMDF050.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF150.UINT32
RSCAN0.TMDF150.UINT16[L/H]
RSCAN0.TMDF150.UINT8[LL/LH/HL/HH]
RSCAN0.TMID51.UINT32
RSCAN0.TMID51.UINT16[L/H]
RSCAN0.TMID51.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR51.UINT32
RSCAN0.TMPTR51.UINT16[H]
RSCAN0.TMPTR51.UINT8[HL/HH]
RSCAN0.TMDF051.UINT32
RSCAN0.TMDF051.UINT16[L/H]
RSCAN0.TMDF051.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF151.UINT32
RSCAN0.TMDF151.UINT16[L/H]
RSCAN0.TMDF151.UINT8[LL/LH/HL/HH]
RSCAN0.TMID52.UINT32
RSCAN0.TMID52.UINT16[L/H]
RSCAN0.TMID52.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR52.UINT32
RSCAN0.TMPTR52.UINT16[H]
RSCAN0.TMPTR52.UINT8[HL/HH]
RSCAN0.TMDF052.UINT32
RSCAN0.TMDF052.UINT16[L/H]
RSCAN0.TMDF052.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF152.UINT32
RSCAN0.TMDF152.UINT16[L/H]
RSCAN0.TMDF152.UINT8[LL/LH/HL/HH]
RSCAN0.TMID53.UINT32
RSCAN0.TMID53.UINT16[L/H]
RSCAN0.TMID53.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR53.UINT32
RSCAN0.TMPTR53.UINT16[H]
RSCAN0.TMPTR53.UINT8[HL/HH]
RSCAN0.TMDF053.UINT32
RSCAN0.TMDF053.UINT16[L/H]
RSCAN0.TMDF053.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF153.UINT32
RSCAN0.TMDF153.UINT16[L/H]
RSCAN0.TMDF153.UINT8[LL/LH/HL/HH]
RSCAN0.TMID54.UINT32
RSCAN0.TMID54.UINT16[L/H]
RSCAN0.TMID54.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR54.UINT32
RSCAN0.TMPTR54.UINT16[H]
RSCAN0.TMPTR54.UINT8[HL/HH]
RSCAN0.TMDF054.UINT32
RSCAN0.TMDF054.UINT16[L/H]
RSCAN0.TMDF054.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF154.UINT32
RSCAN0.TMDF154.UINT16[L/H]
RSCAN0.TMDF154.UINT8[LL/LH/HL/HH]
RSCAN0.TMID55.UINT32
RSCAN0.TMID55.UINT16[L/H]
RSCAN0.TMID55.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR55.UINT32
RSCAN0.TMPTR55.UINT16[H]
RSCAN0.TMPTR55.UINT8[HL/HH]
RSCAN0.TMDF055.UINT32
RSCAN0.TMDF055.UINT16[L/H]
RSCAN0.TMDF055.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF155.UINT32
RSCAN0.TMDF155.UINT16[L/H]
RSCAN0.TMDF155.UINT8[LL/LH/HL/HH]
RSCAN0.TMID56.UINT32
RSCAN0.TMID56.UINT16[L/H]
RSCAN0.TMID56.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR56.UINT32
RSCAN0.TMPTR56.UINT16[H]
RSCAN0.TMPTR56.UINT8[HL/HH]
RSCAN0.TMDF056.UINT32
RSCAN0.TMDF056.UINT16[L/H]
RSCAN0.TMDF056.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF156.UINT32
RSCAN0.TMDF156.UINT16[L/H]
RSCAN0.TMDF156.UINT8[LL/LH/HL/HH]
RSCAN0.TMID57.UINT32
RSCAN0.TMID57.UINT16[L/H]
RSCAN0.TMID57.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR57.UINT32
RSCAN0.TMPTR57.UINT16[H]
RSCAN0.TMPTR57.UINT8[HL/HH]
RSCAN0.TMDF057.UINT32
RSCAN0.TMDF057.UINT16[L/H]
RSCAN0.TMDF057.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF157.UINT32
RSCAN0.TMDF157.UINT16[L/H]
RSCAN0.TMDF157.UINT8[LL/LH/HL/HH]
RSCAN0.TMID58.UINT32
RSCAN0.TMID58.UINT16[L/H]
RSCAN0.TMID58.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR58.UINT32
RSCAN0.TMPTR58.UINT16[H]
RSCAN0.TMPTR58.UINT8[HL/HH]
RSCAN0.TMDF058.UINT32
RSCAN0.TMDF058.UINT16[L/H]
RSCAN0.TMDF058.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF158.UINT32
RSCAN0.TMDF158.UINT16[L/H]
RSCAN0.TMDF158.UINT8[LL/LH/HL/HH]
RSCAN0.TMID59.UINT32
RSCAN0.TMID59.UINT16[L/H]
RSCAN0.TMID59.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR59.UINT32
RSCAN0.TMPTR59.UINT16[H]
RSCAN0.TMPTR59.UINT8[HL/HH]
RSCAN0.TMDF059.UINT32
RSCAN0.TMDF059.UINT16[L/H]
RSCAN0.TMDF059.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF159.UINT32
RSCAN0.TMDF159.UINT16[L/H]
RSCAN0.TMDF159.UINT8[LL/LH/HL/HH]
RSCAN0.TMID60.UINT32
RSCAN0.TMID60.UINT16[L/H]
RSCAN0.TMID60.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR60.UINT32
RSCAN0.TMPTR60.UINT16[H]
RSCAN0.TMPTR60.UINT8[HL/HH]
RSCAN0.TMDF060.UINT32
RSCAN0.TMDF060.UINT16[L/H]
RSCAN0.TMDF060.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF160.UINT32
RSCAN0.TMDF160.UINT16[L/H]
RSCAN0.TMDF160.UINT8[LL/LH/HL/HH]
RSCAN0.TMID61.UINT32
RSCAN0.TMID61.UINT16[L/H]
RSCAN0.TMID61.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR61.UINT32
RSCAN0.TMPTR61.UINT16[H]
RSCAN0.TMPTR61.UINT8[HL/HH]
RSCAN0.TMDF061.UINT32
RSCAN0.TMDF061.UINT16[L/H]
RSCAN0.TMDF061.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF161.UINT32
RSCAN0.TMDF161.UINT16[L/H]
RSCAN0.TMDF161.UINT8[LL/LH/HL/HH]
RSCAN0.TMID62.UINT32
RSCAN0.TMID62.UINT16[L/H]
RSCAN0.TMID62.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR62.UINT32
RSCAN0.TMPTR62.UINT16[H]
RSCAN0.TMPTR62.UINT8[HL/HH]
RSCAN0.TMDF062.UINT32
RSCAN0.TMDF062.UINT16[L/H]
RSCAN0.TMDF062.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF162.UINT32
RSCAN0.TMDF162.UINT16[L/H]
RSCAN0.TMDF162.UINT8[LL/LH/HL/HH]
RSCAN0.TMID63.UINT32
RSCAN0.TMID63.UINT16[L/H]
RSCAN0.TMID63.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR63.UINT32
RSCAN0.TMPTR63.UINT16[H]
RSCAN0.TMPTR63.UINT8[HL/HH]
RSCAN0.TMDF063.UINT32
RSCAN0.TMDF063.UINT16[L/H]
RSCAN0.TMDF063.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF163.UINT32
RSCAN0.TMDF163.UINT16[L/H]
RSCAN0.TMDF163.UINT8[LL/LH/HL/HH]
RSCAN0.TMID64.UINT32
RSCAN0.TMID64.UINT16[L/H]
RSCAN0.TMID64.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR64.UINT32
RSCAN0.TMPTR64.UINT16[H]
RSCAN0.TMPTR64.UINT8[HL/HH]
RSCAN0.TMDF064.UINT32
RSCAN0.TMDF064.UINT16[L/H]
RSCAN0.TMDF064.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF164.UINT32
RSCAN0.TMDF164.UINT16[L/H]
RSCAN0.TMDF164.UINT8[LL/LH/HL/HH]
RSCAN0.TMID65.UINT32
RSCAN0.TMID65.UINT16[L/H]
RSCAN0.TMID65.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR65.UINT32
RSCAN0.TMPTR65.UINT16[H]
RSCAN0.TMPTR65.UINT8[HL/HH]
RSCAN0.TMDF065.UINT32
RSCAN0.TMDF065.UINT16[L/H]
RSCAN0.TMDF065.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF165.UINT32
RSCAN0.TMDF165.UINT16[L/H]
RSCAN0.TMDF165.UINT8[LL/LH/HL/HH]
RSCAN0.TMID66.UINT32
RSCAN0.TMID66.UINT16[L/H]
RSCAN0.TMID66.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR66.UINT32
RSCAN0.TMPTR66.UINT16[H]
RSCAN0.TMPTR66.UINT8[HL/HH]
RSCAN0.TMDF066.UINT32
RSCAN0.TMDF066.UINT16[L/H]
RSCAN0.TMDF066.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF166.UINT32
RSCAN0.TMDF166.UINT16[L/H]
RSCAN0.TMDF166.UINT8[LL/LH/HL/HH]
RSCAN0.TMID67.UINT32
RSCAN0.TMID67.UINT16[L/H]
RSCAN0.TMID67.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR67.UINT32
RSCAN0.TMPTR67.UINT16[H]
RSCAN0.TMPTR67.UINT8[HL/HH]
RSCAN0.TMDF067.UINT32
RSCAN0.TMDF067.UINT16[L/H]
RSCAN0.TMDF067.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF167.UINT32
RSCAN0.TMDF167.UINT16[L/H]
RSCAN0.TMDF167.UINT8[LL/LH/HL/HH]
RSCAN0.TMID68.UINT32
RSCAN0.TMID68.UINT16[L/H]
RSCAN0.TMID68.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR68.UINT32
RSCAN0.TMPTR68.UINT16[H]
RSCAN0.TMPTR68.UINT8[HL/HH]
RSCAN0.TMDF068.UINT32
RSCAN0.TMDF068.UINT16[L/H]
RSCAN0.TMDF068.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF168.UINT32
RSCAN0.TMDF168.UINT16[L/H]
RSCAN0.TMDF168.UINT8[LL/LH/HL/HH]
RSCAN0.TMID69.UINT32
RSCAN0.TMID69.UINT16[L/H]
RSCAN0.TMID69.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR69.UINT32
RSCAN0.TMPTR69.UINT16[H]
RSCAN0.TMPTR69.UINT8[HL/HH]
RSCAN0.TMDF069.UINT32
RSCAN0.TMDF069.UINT16[L/H]
RSCAN0.TMDF069.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF169.UINT32
RSCAN0.TMDF169.UINT16[L/H]
RSCAN0.TMDF169.UINT8[LL/LH/HL/HH]
RSCAN0.TMID70.UINT32
RSCAN0.TMID70.UINT16[L/H]
RSCAN0.TMID70.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR70.UINT32
RSCAN0.TMPTR70.UINT16[H]
RSCAN0.TMPTR70.UINT8[HL/HH]
RSCAN0.TMDF070.UINT32
RSCAN0.TMDF070.UINT16[L/H]
RSCAN0.TMDF070.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF170.UINT32
RSCAN0.TMDF170.UINT16[L/H]
RSCAN0.TMDF170.UINT8[LL/LH/HL/HH]
RSCAN0.TMID71.UINT32
RSCAN0.TMID71.UINT16[L/H]
RSCAN0.TMID71.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR71.UINT32
RSCAN0.TMPTR71.UINT16[H]
RSCAN0.TMPTR71.UINT8[HL/HH]
RSCAN0.TMDF071.UINT32
RSCAN0.TMDF071.UINT16[L/H]
RSCAN0.TMDF071.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF171.UINT32
RSCAN0.TMDF171.UINT16[L/H]
RSCAN0.TMDF171.UINT8[LL/LH/HL/HH]
RSCAN0.TMID72.UINT32
RSCAN0.TMID72.UINT16[L/H]
RSCAN0.TMID72.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR72.UINT32
RSCAN0.TMPTR72.UINT16[H]
RSCAN0.TMPTR72.UINT8[HL/HH]
RSCAN0.TMDF072.UINT32
RSCAN0.TMDF072.UINT16[L/H]
RSCAN0.TMDF072.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF172.UINT32
RSCAN0.TMDF172.UINT16[L/H]
RSCAN0.TMDF172.UINT8[LL/LH/HL/HH]
RSCAN0.TMID73.UINT32
RSCAN0.TMID73.UINT16[L/H]
RSCAN0.TMID73.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR73.UINT32
RSCAN0.TMPTR73.UINT16[H]
RSCAN0.TMPTR73.UINT8[HL/HH]
RSCAN0.TMDF073.UINT32
RSCAN0.TMDF073.UINT16[L/H]
RSCAN0.TMDF073.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF173.UINT32
RSCAN0.TMDF173.UINT16[L/H]
RSCAN0.TMDF173.UINT8[LL/LH/HL/HH]
RSCAN0.TMID74.UINT32
RSCAN0.TMID74.UINT16[L/H]
RSCAN0.TMID74.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR74.UINT32
RSCAN0.TMPTR74.UINT16[H]
RSCAN0.TMPTR74.UINT8[HL/HH]
RSCAN0.TMDF074.UINT32
RSCAN0.TMDF074.UINT16[L/H]
RSCAN0.TMDF074.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF174.UINT32
RSCAN0.TMDF174.UINT16[L/H]
RSCAN0.TMDF174.UINT8[LL/LH/HL/HH]
RSCAN0.TMID75.UINT32
RSCAN0.TMID75.UINT16[L/H]
RSCAN0.TMID75.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR75.UINT32
RSCAN0.TMPTR75.UINT16[H]
RSCAN0.TMPTR75.UINT8[HL/HH]
RSCAN0.TMDF075.UINT32
RSCAN0.TMDF075.UINT16[L/H]
RSCAN0.TMDF075.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF175.UINT32
RSCAN0.TMDF175.UINT16[L/H]
RSCAN0.TMDF175.UINT8[LL/LH/HL/HH]
RSCAN0.TMID76.UINT32
RSCAN0.TMID76.UINT16[L/H]
RSCAN0.TMID76.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR76.UINT32
RSCAN0.TMPTR76.UINT16[H]
RSCAN0.TMPTR76.UINT8[HL/HH]
RSCAN0.TMDF076.UINT32
RSCAN0.TMDF076.UINT16[L/H]
RSCAN0.TMDF076.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF176.UINT32
RSCAN0.TMDF176.UINT16[L/H]
RSCAN0.TMDF176.UINT8[LL/LH/HL/HH]
RSCAN0.TMID77.UINT32
RSCAN0.TMID77.UINT16[L/H]
RSCAN0.TMID77.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR77.UINT32
RSCAN0.TMPTR77.UINT16[H]
RSCAN0.TMPTR77.UINT8[HL/HH]
RSCAN0.TMDF077.UINT32
RSCAN0.TMDF077.UINT16[L/H]
RSCAN0.TMDF077.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF177.UINT32
RSCAN0.TMDF177.UINT16[L/H]
RSCAN0.TMDF177.UINT8[LL/LH/HL/HH]
RSCAN0.TMID78.UINT32
RSCAN0.TMID78.UINT16[L/H]
RSCAN0.TMID78.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR78.UINT32
RSCAN0.TMPTR78.UINT16[H]
RSCAN0.TMPTR78.UINT8[HL/HH]
RSCAN0.TMDF078.UINT32
RSCAN0.TMDF078.UINT16[L/H]
RSCAN0.TMDF078.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF178.UINT32
RSCAN0.TMDF178.UINT16[L/H]
RSCAN0.TMDF178.UINT8[LL/LH/HL/HH]
RSCAN0.TMID79.UINT32
RSCAN0.TMID79.UINT16[L/H]
RSCAN0.TMID79.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR79.UINT32
RSCAN0.TMPTR79.UINT16[H]
RSCAN0.TMPTR79.UINT8[HL/HH]
RSCAN0.TMDF079.UINT32
RSCAN0.TMDF079.UINT16[L/H]
RSCAN0.TMDF079.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF179.UINT32
RSCAN0.TMDF179.UINT16[L/H]
RSCAN0.TMDF179.UINT8[LL/LH/HL/HH]
RSCAN0.TMID80.UINT32
RSCAN0.TMID80.UINT16[L/H]
RSCAN0.TMID80.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR80.UINT32
RSCAN0.TMPTR80.UINT16[H]
RSCAN0.TMPTR80.UINT8[HL/HH]
RSCAN0.TMDF080.UINT32
RSCAN0.TMDF080.UINT16[L/H]
RSCAN0.TMDF080.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF180.UINT32
RSCAN0.TMDF180.UINT16[L/H]
RSCAN0.TMDF180.UINT8[LL/LH/HL/HH]
RSCAN0.TMID81.UINT32
RSCAN0.TMID81.UINT16[L/H]
RSCAN0.TMID81.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR81.UINT32
RSCAN0.TMPTR81.UINT16[H]
RSCAN0.TMPTR81.UINT8[HL/HH]
RSCAN0.TMDF081.UINT32
RSCAN0.TMDF081.UINT16[L/H]
RSCAN0.TMDF081.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF181.UINT32
RSCAN0.TMDF181.UINT16[L/H]
RSCAN0.TMDF181.UINT8[LL/LH/HL/HH]
RSCAN0.TMID82.UINT32
RSCAN0.TMID82.UINT16[L/H]
RSCAN0.TMID82.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR82.UINT32
RSCAN0.TMPTR82.UINT16[H]
RSCAN0.TMPTR82.UINT8[HL/HH]
RSCAN0.TMDF082.UINT32
RSCAN0.TMDF082.UINT16[L/H]
RSCAN0.TMDF082.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF182.UINT32
RSCAN0.TMDF182.UINT16[L/H]
RSCAN0.TMDF182.UINT8[LL/LH/HL/HH]
RSCAN0.TMID83.UINT32
RSCAN0.TMID83.UINT16[L/H]
RSCAN0.TMID83.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR83.UINT32
RSCAN0.TMPTR83.UINT16[H]
RSCAN0.TMPTR83.UINT8[HL/HH]
RSCAN0.TMDF083.UINT32
RSCAN0.TMDF083.UINT16[L/H]
RSCAN0.TMDF083.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF183.UINT32
RSCAN0.TMDF183.UINT16[L/H]
RSCAN0.TMDF183.UINT8[LL/LH/HL/HH]
RSCAN0.TMID84.UINT32
RSCAN0.TMID84.UINT16[L/H]
RSCAN0.TMID84.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR84.UINT32
RSCAN0.TMPTR84.UINT16[H]
RSCAN0.TMPTR84.UINT8[HL/HH]
RSCAN0.TMDF084.UINT32
RSCAN0.TMDF084.UINT16[L/H]
RSCAN0.TMDF084.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF184.UINT32
RSCAN0.TMDF184.UINT16[L/H]
RSCAN0.TMDF184.UINT8[LL/LH/HL/HH]
RSCAN0.TMID85.UINT32
RSCAN0.TMID85.UINT16[L/H]
RSCAN0.TMID85.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR85.UINT32
RSCAN0.TMPTR85.UINT16[H]
RSCAN0.TMPTR85.UINT8[HL/HH]
RSCAN0.TMDF085.UINT32
RSCAN0.TMDF085.UINT16[L/H]
RSCAN0.TMDF085.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF185.UINT32
RSCAN0.TMDF185.UINT16[L/H]
RSCAN0.TMDF185.UINT8[LL/LH/HL/HH]
RSCAN0.TMID86.UINT32
RSCAN0.TMID86.UINT16[L/H]
RSCAN0.TMID86.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR86.UINT32
RSCAN0.TMPTR86.UINT16[H]
RSCAN0.TMPTR86.UINT8[HL/HH]
RSCAN0.TMDF086.UINT32
RSCAN0.TMDF086.UINT16[L/H]
RSCAN0.TMDF086.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF186.UINT32
RSCAN0.TMDF186.UINT16[L/H]
RSCAN0.TMDF186.UINT8[LL/LH/HL/HH]
RSCAN0.TMID87.UINT32
RSCAN0.TMID87.UINT16[L/H]
RSCAN0.TMID87.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR87.UINT32
RSCAN0.TMPTR87.UINT16[H]
RSCAN0.TMPTR87.UINT8[HL/HH]
RSCAN0.TMDF087.UINT32
RSCAN0.TMDF087.UINT16[L/H]
RSCAN0.TMDF087.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF187.UINT32
RSCAN0.TMDF187.UINT16[L/H]
RSCAN0.TMDF187.UINT8[LL/LH/HL/HH]
RSCAN0.TMID88.UINT32
RSCAN0.TMID88.UINT16[L/H]
RSCAN0.TMID88.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR88.UINT32
RSCAN0.TMPTR88.UINT16[H]
RSCAN0.TMPTR88.UINT8[HL/HH]
RSCAN0.TMDF088.UINT32
RSCAN0.TMDF088.UINT16[L/H]
RSCAN0.TMDF088.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF188.UINT32
RSCAN0.TMDF188.UINT16[L/H]
RSCAN0.TMDF188.UINT8[LL/LH/HL/HH]
RSCAN0.TMID89.UINT32
RSCAN0.TMID89.UINT16[L/H]
RSCAN0.TMID89.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR89.UINT32
RSCAN0.TMPTR89.UINT16[H]
RSCAN0.TMPTR89.UINT8[HL/HH]
RSCAN0.TMDF089.UINT32
RSCAN0.TMDF089.UINT16[L/H]
RSCAN0.TMDF089.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF189.UINT32
RSCAN0.TMDF189.UINT16[L/H]
RSCAN0.TMDF189.UINT8[LL/LH/HL/HH]
RSCAN0.TMID90.UINT32
RSCAN0.TMID90.UINT16[L/H]
RSCAN0.TMID90.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR90.UINT32
RSCAN0.TMPTR90.UINT16[H]
RSCAN0.TMPTR90.UINT8[HL/HH]
RSCAN0.TMDF090.UINT32
RSCAN0.TMDF090.UINT16[L/H]
RSCAN0.TMDF090.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF190.UINT32
RSCAN0.TMDF190.UINT16[L/H]
RSCAN0.TMDF190.UINT8[LL/LH/HL/HH]
RSCAN0.TMID91.UINT32
RSCAN0.TMID91.UINT16[L/H]
RSCAN0.TMID91.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR91.UINT32
RSCAN0.TMPTR91.UINT16[H]
RSCAN0.TMPTR91.UINT8[HL/HH]
RSCAN0.TMDF091.UINT32
RSCAN0.TMDF091.UINT16[L/H]
RSCAN0.TMDF091.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF191.UINT32
RSCAN0.TMDF191.UINT16[L/H]
RSCAN0.TMDF191.UINT8[LL/LH/HL/HH]
RSCAN0.TMID92.UINT32
RSCAN0.TMID92.UINT16[L/H]
RSCAN0.TMID92.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR92.UINT32
RSCAN0.TMPTR92.UINT16[H]
RSCAN0.TMPTR92.UINT8[HL/HH]
RSCAN0.TMDF092.UINT32
RSCAN0.TMDF092.UINT16[L/H]
RSCAN0.TMDF092.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF192.UINT32
RSCAN0.TMDF192.UINT16[L/H]
RSCAN0.TMDF192.UINT8[LL/LH/HL/HH]
RSCAN0.TMID93.UINT32
RSCAN0.TMID93.UINT16[L/H]
RSCAN0.TMID93.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR93.UINT32
RSCAN0.TMPTR93.UINT16[H]
RSCAN0.TMPTR93.UINT8[HL/HH]
RSCAN0.TMDF093.UINT32
RSCAN0.TMDF093.UINT16[L/H]
RSCAN0.TMDF093.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF193.UINT32
RSCAN0.TMDF193.UINT16[L/H]
RSCAN0.TMDF193.UINT8[LL/LH/HL/HH]
RSCAN0.TMID94.UINT32
RSCAN0.TMID94.UINT16[L/H]
RSCAN0.TMID94.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR94.UINT32
RSCAN0.TMPTR94.UINT16[H]
RSCAN0.TMPTR94.UINT8[HL/HH]
RSCAN0.TMDF094.UINT32
RSCAN0.TMDF094.UINT16[L/H]
RSCAN0.TMDF094.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF194.UINT32
RSCAN0.TMDF194.UINT16[L/H]
RSCAN0.TMDF194.UINT8[LL/LH/HL/HH]
RSCAN0.TMID95.UINT32
RSCAN0.TMID95.UINT16[L/H]
RSCAN0.TMID95.UINT8[LL/LH/HL/HH]
RSCAN0.TMPTR95.UINT32
RSCAN0.TMPTR95.UINT16[H]
RSCAN0.TMPTR95.UINT8[HL/HH]
RSCAN0.TMDF095.UINT32
RSCAN0.TMDF095.UINT16[L/H]
RSCAN0.TMDF095.UINT8[LL/LH/HL/HH]
RSCAN0.TMDF195.UINT32
RSCAN0.TMDF195.UINT16[L/H]
RSCAN0.TMDF195.UINT8[LL/LH/HL/HH]
RSCAN0.THLACC0.UINT32
RSCAN0.THLACC0.UINT16[L]
RSCAN0.THLACC0.UINT8[LL/LH]
RSCAN0.THLACC1.UINT32
RSCAN0.THLACC1.UINT16[L]
RSCAN0.THLACC1.UINT8[LL/LH]
RSCAN0.THLACC2.UINT32
RSCAN0.THLACC2.UINT16[L]
RSCAN0.THLACC2.UINT8[LL/LH]
RSCAN0.THLACC3.UINT32
RSCAN0.THLACC3.UINT16[L]
RSCAN0.THLACC3.UINT8[LL/LH]
RSCAN0.THLACC4.UINT32
RSCAN0.THLACC4.UINT16[L]
RSCAN0.THLACC4.UINT8[LL/LH]
RSCAN0.THLACC5.UINT32
RSCAN0.THLACC5.UINT16[L]
RSCAN0.THLACC5.UINT8[LL/LH]
RSCAN0.RPGACC0.UINT32
RSCAN0.RPGACC0.UINT16[L/H]
RSCAN0.RPGACC0.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC1.UINT32
RSCAN0.RPGACC1.UINT16[L/H]
RSCAN0.RPGACC1.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC2.UINT32
RSCAN0.RPGACC2.UINT16[L/H]
RSCAN0.RPGACC2.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC3.UINT32
RSCAN0.RPGACC3.UINT16[L/H]
RSCAN0.RPGACC3.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC4.UINT32
RSCAN0.RPGACC4.UINT16[L/H]
RSCAN0.RPGACC4.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC5.UINT32
RSCAN0.RPGACC5.UINT16[L/H]
RSCAN0.RPGACC5.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC6.UINT32
RSCAN0.RPGACC6.UINT16[L/H]
RSCAN0.RPGACC6.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC7.UINT32
RSCAN0.RPGACC7.UINT16[L/H]
RSCAN0.RPGACC7.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC8.UINT32
RSCAN0.RPGACC8.UINT16[L/H]
RSCAN0.RPGACC8.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC9.UINT32
RSCAN0.RPGACC9.UINT16[L/H]
RSCAN0.RPGACC9.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC10.UINT32
RSCAN0.RPGACC10.UINT16[L/H]
RSCAN0.RPGACC10.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC11.UINT32
RSCAN0.RPGACC11.UINT16[L/H]
RSCAN0.RPGACC11.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC12.UINT32
RSCAN0.RPGACC12.UINT16[L/H]
RSCAN0.RPGACC12.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC13.UINT32
RSCAN0.RPGACC13.UINT16[L/H]
RSCAN0.RPGACC13.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC14.UINT32
RSCAN0.RPGACC14.UINT16[L/H]
RSCAN0.RPGACC14.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC15.UINT32
RSCAN0.RPGACC15.UINT16[L/H]
RSCAN0.RPGACC15.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC16.UINT32
RSCAN0.RPGACC16.UINT16[L/H]
RSCAN0.RPGACC16.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC17.UINT32
RSCAN0.RPGACC17.UINT16[L/H]
RSCAN0.RPGACC17.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC18.UINT32
RSCAN0.RPGACC18.UINT16[L/H]
RSCAN0.RPGACC18.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC19.UINT32
RSCAN0.RPGACC19.UINT16[L/H]
RSCAN0.RPGACC19.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC20.UINT32
RSCAN0.RPGACC20.UINT16[L/H]
RSCAN0.RPGACC20.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC21.UINT32
RSCAN0.RPGACC21.UINT16[L/H]
RSCAN0.RPGACC21.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC22.UINT32
RSCAN0.RPGACC22.UINT16[L/H]
RSCAN0.RPGACC22.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC23.UINT32
RSCAN0.RPGACC23.UINT16[L/H]
RSCAN0.RPGACC23.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC24.UINT32
RSCAN0.RPGACC24.UINT16[L/H]
RSCAN0.RPGACC24.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC25.UINT32
RSCAN0.RPGACC25.UINT16[L/H]
RSCAN0.RPGACC25.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC26.UINT32
RSCAN0.RPGACC26.UINT16[L/H]
RSCAN0.RPGACC26.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC27.UINT32
RSCAN0.RPGACC27.UINT16[L/H]
RSCAN0.RPGACC27.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC28.UINT32
RSCAN0.RPGACC28.UINT16[L/H]
RSCAN0.RPGACC28.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC29.UINT32
RSCAN0.RPGACC29.UINT16[L/H]
RSCAN0.RPGACC29.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC30.UINT32
RSCAN0.RPGACC30.UINT16[L/H]
RSCAN0.RPGACC30.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC31.UINT32
RSCAN0.RPGACC31.UINT16[L/H]
RSCAN0.RPGACC31.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC32.UINT32
RSCAN0.RPGACC32.UINT16[L/H]
RSCAN0.RPGACC32.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC33.UINT32
RSCAN0.RPGACC33.UINT16[L/H]
RSCAN0.RPGACC33.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC34.UINT32
RSCAN0.RPGACC34.UINT16[L/H]
RSCAN0.RPGACC34.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC35.UINT32
RSCAN0.RPGACC35.UINT16[L/H]
RSCAN0.RPGACC35.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC36.UINT32
RSCAN0.RPGACC36.UINT16[L/H]
RSCAN0.RPGACC36.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC37.UINT32
RSCAN0.RPGACC37.UINT16[L/H]
RSCAN0.RPGACC37.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC38.UINT32
RSCAN0.RPGACC38.UINT16[L/H]
RSCAN0.RPGACC38.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC39.UINT32
RSCAN0.RPGACC39.UINT16[L/H]
RSCAN0.RPGACC39.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC40.UINT32
RSCAN0.RPGACC40.UINT16[L/H]
RSCAN0.RPGACC40.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC41.UINT32
RSCAN0.RPGACC41.UINT16[L/H]
RSCAN0.RPGACC41.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC42.UINT32
RSCAN0.RPGACC42.UINT16[L/H]
RSCAN0.RPGACC42.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC43.UINT32
RSCAN0.RPGACC43.UINT16[L/H]
RSCAN0.RPGACC43.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC44.UINT32
RSCAN0.RPGACC44.UINT16[L/H]
RSCAN0.RPGACC44.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC45.UINT32
RSCAN0.RPGACC45.UINT16[L/H]
RSCAN0.RPGACC45.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC46.UINT32
RSCAN0.RPGACC46.UINT16[L/H]
RSCAN0.RPGACC46.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC47.UINT32
RSCAN0.RPGACC47.UINT16[L/H]
RSCAN0.RPGACC47.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC48.UINT32
RSCAN0.RPGACC48.UINT16[L/H]
RSCAN0.RPGACC48.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC49.UINT32
RSCAN0.RPGACC49.UINT16[L/H]
RSCAN0.RPGACC49.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC50.UINT32
RSCAN0.RPGACC50.UINT16[L/H]
RSCAN0.RPGACC50.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC51.UINT32
RSCAN0.RPGACC51.UINT16[L/H]
RSCAN0.RPGACC51.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC52.UINT32
RSCAN0.RPGACC52.UINT16[L/H]
RSCAN0.RPGACC52.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC53.UINT32
RSCAN0.RPGACC53.UINT16[L/H]
RSCAN0.RPGACC53.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC54.UINT32
RSCAN0.RPGACC54.UINT16[L/H]
RSCAN0.RPGACC54.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC55.UINT32
RSCAN0.RPGACC55.UINT16[L/H]
RSCAN0.RPGACC55.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC56.UINT32
RSCAN0.RPGACC56.UINT16[L/H]
RSCAN0.RPGACC56.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC57.UINT32
RSCAN0.RPGACC57.UINT16[L/H]
RSCAN0.RPGACC57.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC58.UINT32
RSCAN0.RPGACC58.UINT16[L/H]
RSCAN0.RPGACC58.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC59.UINT32
RSCAN0.RPGACC59.UINT16[L/H]
RSCAN0.RPGACC59.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC60.UINT32
RSCAN0.RPGACC60.UINT16[L/H]
RSCAN0.RPGACC60.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC61.UINT32
RSCAN0.RPGACC61.UINT16[L/H]
RSCAN0.RPGACC61.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC62.UINT32
RSCAN0.RPGACC62.UINT16[L/H]
RSCAN0.RPGACC62.UINT8[LL/LH/HL/HH]
RSCAN0.RPGACC63.UINT32
RSCAN0.RPGACC63.UINT16[L/H]
RSCAN0.RPGACC63.UINT8[LL/LH/HL/HH]
CSIH0.CTL0.UINT8
CSIH0.CTL0.BIT.MBS
CSIH0.CTL0.BIT.JOBE
CSIH0.CTL0.BIT.RXE
CSIH0.CTL0.BIT.TXE
CSIH0.CTL0.BIT.PWR
CSIH0.STR0
CSIH0.STCR0
CSIH0.CTL1
CSIH0.CTL2
CSIH0.EMU.UINT8
CSIH0.EMU.BIT.SVSDIS
CSIH0.MCTL1
CSIH0.MCTL2
CSIH0.TX0W
CSIH0.TX0H
CSIH0.RX0W
CSIH0.RX0H
CSIH0.MRWP0
CSIH0.MCTL0
CSIH0.CFG0 ... CSIH0.CFG7
CSIH0.BRS0 ... CSIH0.BRS3
CSIH1.CTL0.UINT8
CSIH1.CTL0.BIT.MBS
CSIH1.CTL0.BIT.JOBE
CSIH1.CTL0.BIT.RXE
CSIH1.CTL0.BIT.TXE
CSIH1.CTL0.BIT.PWR
CSIH1.STR0
CSIH1.STCR0
CSIH1.CTL1
CSIH1.CTL2
CSIH1.EMU.UINT8
CSIH1.EMU.BIT.SVSDIS
CSIH1.MCTL1
CSIH1.MCTL2
CSIH1.TX0W
CSIH1.TX0H
CSIH1.RX0W
CSIH1.RX0H
CSIH1.MRWP0
CSIH1.MCTL0
CSIH1.CFG0 ... CSIH1.CFG5
CSIH1.BRS0 ... CSIH1.BRS3
CSIH2.CTL0.UINT8
CSIH2.CTL0.BIT.MBS
CSIH2.CTL0.BIT.JOBE
CSIH2.CTL0.BIT.RXE
CSIH2.CTL0.BIT.TXE
CSIH2.CTL0.BIT.PWR
CSIH2.STR0
CSIH2.STCR0
CSIH2.CTL1
CSIH2.CTL2
CSIH2.EMU.UINT8
CSIH2.EMU.BIT.SVSDIS
CSIH2.MCTL1
CSIH2.MCTL2
CSIH2.TX0W
CSIH2.TX0H
CSIH2.RX0W
CSIH2.RX0H
CSIH2.MRWP0
CSIH2.MCTL0
CSIH2.CFG0 ... CSIH2.CFG5
CSIH2.BRS0 ... CSIH2.BRS3
CSIH3.CTL0.UINT8
CSIH3.CTL0.BIT.MBS
CSIH3.CTL0.BIT.JOBE
CSIH3.CTL0.BIT.RXE
CSIH3.CTL0.BIT.TXE
CSIH3.CTL0.BIT.PWR
CSIH3.STR0
CSIH3.STCR0
CSIH3.CTL1
CSIH3.CTL2
CSIH3.EMU.UINT8
CSIH3.EMU.BIT.SVSDIS
CSIH3.MCTL1
CSIH3.MCTL2
CSIH3.TX0W
CSIH3.TX0H
CSIH3.RX0W
CSIH3.RX0H
CSIH3.MRWP0
CSIH3.MCTL0
CSIH3.CFG0 ... CSIH3.CFG3
CSIH3.BRS0 ... CSIH3.BRS3
CSIG0.CTL0.UINT8
CSIG0.CTL0.BIT.RXE
CSIG0.CTL0.BIT.TXE
CSIG0.CTL0.BIT.PWR
CSIG0.STR0
CSIG0.STCR0
CSIG0.CTL1
CSIG0.CTL2
CSIG0.EMU.UINT8
CSIG0.EMU.BIT.SVSDIS
CSIG0.BCTL0.UINT8
CSIG0.BCTL0.BIT.SCE
CSIG0.TX0W
CSIG0.TX0H
CSIG0.RX0
CSIG0.CFG0
CSIG1.CTL0.UINT8
CSIG1.CTL0.BIT.RXE
CSIG1.CTL0.BIT.TXE
CSIG1.CTL0.BIT.PWR
CSIG1.STR0
CSIG1.STCR0
CSIG1.CTL1
CSIG1.CTL2
CSIG1.EMU.UINT8
CSIG1.EMU.BIT.SVSDIS
CSIG1.BCTL0.UINT8
CSIG1.BCTL0.BIT.SCE
CSIG1.TX0W
CSIG1.TX0H
CSIG1.RX0
CSIG1.CFG0
PIC0.SST
PIC0.SSER0
PIC0.SSER2
PIC0.HIZCEN0
PIC0.ADTEN400 ... PIC0.ADTEN402
PIC0.REG200 ... PIC0.REG203
PIC0.REG30
PIC0.REG31
TAUD0.CDR0 ... TAUD0.CDR15
TAUD0.TOL
TAUD0.RDT
TAUD0.RSF
TAUD0.TRO
TAUD0.TME
TAUD0.TDL
TAUD0.TO
TAUD0.TOE
TAUD0.CNT0 ... TAUD0.CNT15
TAUD0.CMUR0 ... TAUD0.CMUR15
TAUD0.CSR0 ... TAUD0.CSR15
TAUD0.CSC0 ... TAUD0.CSC15
TAUD0.TE
TAUD0.TS
TAUD0.TT
TAUD0.CMOR0 ... TAUD0.CMOR15
TAUD0.TPS
TAUD0.BRS
TAUD0.TOM
TAUD0.TOC
TAUD0.TDE
TAUD0.TDM
TAUD0.TRE
TAUD0.TRC
TAUD0.RDE
TAUD0.RDM
TAUD0.RDS
TAUD0.RDC
TAUD0.EMU
TAUB0.CDR0 ... TAUB0.CDR15
TAUB0.TOL
TAUB0.RDT
TAUB0.RSF
TAUB0.TDL
TAUB0.TO
TAUB0.TOE
TAUB0.CNT0 ... TAUB0.CNT15
TAUB0.CMUR0 ... TAUB0.CMUR15
TAUB0.CSR0 ... TAUB0.CSR15
TAUB0.CSC0 ... TAUB0.CSC15
TAUB0.TE
TAUB0.TS
TAUB0.TT
TAUB0.CMOR0 ... TAUB0.CMOR15
TAUB0.TPS
TAUB0.TOM
TAUB0.TOC
TAUB0.TDE
TAUB0.RDE
TAUB0.RDM
TAUB0.RDS
TAUB0.RDC
TAUB0.EMU
TAUB1.CDR0 ... TAUB1.CDR15
TAUB1.TOL
TAUB1.RDT
TAUB1.RSF
TAUB1.TDL
TAUB1.TO
TAUB1.TOE
TAUB1.CNT0 ... TAUB1.CNT15
TAUB1.CMUR0 ... TAUB1.CMUR15
TAUB1.CSR0 ... TAUB1.CSR15
TAUB1.CSC0 ... TAUB1.CSC15
TAUB1.TE
TAUB1.TS
TAUB1.TT
TAUB1.CMOR0 ... TAUB1.CMOR15
TAUB1.TPS
TAUB1.TOM
TAUB1.TOC
TAUB1.TDE
TAUB1.RDE
TAUB1.RDM
TAUB1.RDS
TAUB1.RDC
TAUB1.EMU
TAUJ0.CDR0 ... TAUJ0.CDR3
TAUJ0.CNT0 ... TAUJ0.CNT3
TAUJ0.CMUR0 ... TAUJ0.CMUR3
TAUJ0.CSR0 ... TAUJ0.CSR3
TAUJ0.CSC0 ... TAUJ0.CSC3
TAUJ0.TE
TAUJ0.TS
TAUJ0.TT
TAUJ0.TO
TAUJ0.TOE
TAUJ0.TOL
TAUJ0.RDT
TAUJ0.RSF
TAUJ0.CMOR0 ... TAUJ0.CMOR3
TAUJ0.TPS
TAUJ0.BRS
TAUJ0.TOM
TAUJ0.TOC
TAUJ0.RDE
TAUJ0.RDM
TAUJ0.EMU
TAUJ1.CDR0 ... TAUJ1.CDR3
TAUJ1.CNT0 ... TAUJ1.CNT3
TAUJ1.CMUR0 ... TAUJ1.CMUR3
TAUJ1.CSR0 ... TAUJ1.CSR3
TAUJ1.CSC0 ... TAUJ1.CSC3
TAUJ1.TE
TAUJ1.TS
TAUJ1.TT
TAUJ1.TO
TAUJ1.TOE
TAUJ1.TOL
TAUJ1.RDT
TAUJ1.RSF
TAUJ1.CMOR0 ... TAUJ1.CMOR3
TAUJ1.TPS
TAUJ1.BRS
TAUJ1.TOM
TAUJ1.TOC
TAUJ1.RDE
TAUJ1.RDM
TAUJ1.EMU
PWSA0.CTL
PWSA0.STR
PWSA0.STC
PWSA0.EMU
PWSA0.QUE0 ... PWSA0.QUE7
PWSA0.PVCR00_01
PWSA0.PVCR02_03
PWSA0.PVCR04_05
PWSA0.PVCR06_07
PWSA0.PVCR08_09
PWSA0.PVCR10_11
PWSA0.PVCR12_13
PWSA0.PVCR14_15
PWSA0.PVCR16_17
PWSA0.PVCR18_19
PWSA0.PVCR20_21
PWSA0.PVCR22_23
PWSA0.PVCR24_25
PWSA0.PVCR26_27
PWSA0.PVCR28_29
PWSA0.PVCR30_31
PWSA0.PVCR32_33
PWSA0.PVCR34_35
PWSA0.PVCR36_37
PWSA0.PVCR38_39
PWSA0.PVCR40_41
PWSA0.PVCR42_43
PWSA0.PVCR44_45
PWSA0.PVCR46_47
PWSA0.PVCR48_49
PWSA0.PVCR50_51
PWSA0.PVCR52_53
PWSA0.PVCR54_55
PWSA0.PVCR56_57
PWSA0.PVCR58_59
PWSA0.PVCR60_61
PWSA0.PVCR62_63
PWSA0.PVCR64_65
PWSA0.PVCR66_67
PWSA0.PVCR68_69
PWSA0.PVCR70_71
PWGA0.CSDR
PWGA0.CRDR
PWGA0.CTDR
PWGA0.RDT
PWGA0.RSF
PWGA0.CNT
PWGA0.CTL
PWGA0.CSBR
PWGA0.CRBR
PWGA0.CTBR
PWGA1.CSDR
PWGA1.CRDR
PWGA1.CTDR
PWGA1.RDT
PWGA1.RSF
PWGA1.CNT
PWGA1.CTL
PWGA1.CSBR
PWGA1.CRBR
PWGA1.CTBR
PWGA2.CSDR
PWGA2.CRDR
PWGA2.CTDR
PWGA2.RDT
PWGA2.RSF
PWGA2.CNT
PWGA2.CTL
PWGA2.CSBR
PWGA2.CRBR
PWGA2.CTBR
PWGA3.CSDR
PWGA3.CRDR
PWGA3.CTDR
PWGA3.RDT
PWGA3.RSF
PWGA3.CNT
PWGA3.CTL
PWGA3.CSBR
PWGA3.CRBR
PWGA3.CTBR
PWGA4.CSDR
PWGA4.CRDR
PWGA4.CTDR
PWGA4.RDT
PWGA4.RSF
PWGA4.CNT
PWGA4.CTL
PWGA4.CSBR
PWGA4.CRBR
PWGA4.CTBR
PWGA5.CSDR
PWGA5.CRDR
PWGA5.CTDR
PWGA5.RDT
PWGA5.RSF
PWGA5.CNT
PWGA5.CTL
PWGA5.CSBR
PWGA5.CRBR
PWGA5.CTBR
PWGA6.CSDR
PWGA6.CRDR
PWGA6.CTDR
PWGA6.RDT
PWGA6.RSF
PWGA6.CNT
PWGA6.CTL
PWGA6.CSBR
PWGA6.CRBR
PWGA6.CTBR
PWGA7.CSDR
PWGA7.CRDR
PWGA7.CTDR
PWGA7.RDT
PWGA7.RSF
PWGA7.CNT
PWGA7.CTL
PWGA7.CSBR
PWGA7.CRBR
PWGA7.CTBR
PWGA8.CSDR
PWGA8.CRDR
PWGA8.CTDR
PWGA8.RDT
PWGA8.RSF
PWGA8.CNT
PWGA8.CTL
PWGA8.CSBR
PWGA8.CRBR
PWGA8.CTBR
PWGA9.CSDR
PWGA9.CRDR
PWGA9.CTDR
PWGA9.RDT
PWGA9.RSF
PWGA9.CNT
PWGA9.CTL
PWGA9.CSBR
PWGA9.CRBR
PWGA9.CTBR
PWGA10.CSDR
PWGA10.CRDR
PWGA10.CTDR
PWGA10.RDT
PWGA10.RSF
PWGA10.CNT
PWGA10.CTL
PWGA10.CSBR
PWGA10.CRBR
PWGA10.CTBR
PWGA11.CSDR
PWGA11.CRDR
PWGA11.CTDR
PWGA11.RDT
PWGA11.RSF
PWGA11.CNT
PWGA11.CTL
PWGA11.CSBR
PWGA11.CRBR
PWGA11.CTBR
PWGA12.CSDR
PWGA12.CRDR
PWGA12.CTDR
PWGA12.RDT
PWGA12.RSF
PWGA12.CNT
PWGA12.CTL
PWGA12.CSBR
PWGA12.CRBR
PWGA12.CTBR
PWGA13.CSDR
PWGA13.CRDR
PWGA13.CTDR
PWGA13.RDT
PWGA13.RSF
PWGA13.CNT
PWGA13.CTL
PWGA13.CSBR
PWGA13.CRBR
PWGA13.CTBR
PWGA14.CSDR
PWGA14.CRDR
PWGA14.CTDR
PWGA14.RDT
PWGA14.RSF
PWGA14.CNT
PWGA14.CTL
PWGA14.CSBR
PWGA14.CRBR
PWGA14.CTBR
PWGA15.CSDR
PWGA15.CRDR
PWGA15.CTDR
PWGA15.RDT
PWGA15.RSF
PWGA15.CNT
PWGA15.CTL
PWGA15.CSBR
PWGA15.CRBR
PWGA15.CTBR
PWGA16.CSDR
PWGA16.CRDR
PWGA16.CTDR
PWGA16.RDT
PWGA16.RSF
PWGA16.CNT
PWGA16.CTL
PWGA16.CSBR
PWGA16.CRBR
PWGA16.CTBR
PWGA17.CSDR
PWGA17.CRDR
PWGA17.CTDR
PWGA17.RDT
PWGA17.RSF
PWGA17.CNT
PWGA17.CTL
PWGA17.CSBR
PWGA17.CRBR
PWGA17.CTBR
PWGA18.CSDR
PWGA18.CRDR
PWGA18.CTDR
PWGA18.RDT
PWGA18.RSF
PWGA18.CNT
PWGA18.CTL
PWGA18.CSBR
PWGA18.CRBR
PWGA18.CTBR
PWGA19.CSDR
PWGA19.CRDR
PWGA19.CTDR
PWGA19.RDT
PWGA19.RSF
PWGA19.CNT
PWGA19.CTL
PWGA19.CSBR
PWGA19.CRBR
PWGA19.CTBR
PWGA20.CSDR
PWGA20.CRDR
PWGA20.CTDR
PWGA20.RDT
PWGA20.RSF
PWGA20.CNT
PWGA20.CTL
PWGA20.CSBR
PWGA20.CRBR
PWGA20.CTBR
PWGA21.CSDR
PWGA21.CRDR
PWGA21.CTDR
PWGA21.RDT
PWGA21.RSF
PWGA21.CNT
PWGA21.CTL
PWGA21.CSBR
PWGA21.CRBR
PWGA21.CTBR
PWGA22.CSDR
PWGA22.CRDR
PWGA22.CTDR
PWGA22.RDT
PWGA22.RSF
PWGA22.CNT
PWGA22.CTL
PWGA22.CSBR
PWGA22.CRBR
PWGA22.CTBR
PWGA23.CSDR
PWGA23.CRDR
PWGA23.CTDR
PWGA23.RDT
PWGA23.RSF
PWGA23.CNT
PWGA23.CTL
PWGA23.CSBR
PWGA23.CRBR
PWGA23.CTBR
PWGA24.CSDR
PWGA24.CRDR
PWGA24.CTDR
PWGA24.RDT
PWGA24.RSF
PWGA24.CNT
PWGA24.CTL
PWGA24.CSBR
PWGA24.CRBR
PWGA24.CTBR
PWGA25.CSDR
PWGA25.CRDR
PWGA25.CTDR
PWGA25.RDT
PWGA25.RSF
PWGA25.CNT
PWGA25.CTL
PWGA25.CSBR
PWGA25.CRBR
PWGA25.CTBR
PWGA26.CSDR
PWGA26.CRDR
PWGA26.CTDR
PWGA26.RDT
PWGA26.RSF
PWGA26.CNT
PWGA26.CTL
PWGA26.CSBR
PWGA26.CRBR
PWGA26.CTBR
PWGA27.CSDR
PWGA27.CRDR
PWGA27.CTDR
PWGA27.RDT
PWGA27.RSF
PWGA27.CNT
PWGA27.CTL
PWGA27.CSBR
PWGA27.CRBR
PWGA27.CTBR
PWGA28.CSDR
PWGA28.CRDR
PWGA28.CTDR
PWGA28.RDT
PWGA28.RSF
PWGA28.CNT
PWGA28.CTL
PWGA28.CSBR
PWGA28.CRBR
PWGA28.CTBR
PWGA29.CSDR
PWGA29.CRDR
PWGA29.CTDR
PWGA29.RDT
PWGA29.RSF
PWGA29.CNT
PWGA29.CTL
PWGA29.CSBR
PWGA29.CRBR
PWGA29.CTBR
PWGA30.CSDR
PWGA30.CRDR
PWGA30.CTDR
PWGA30.RDT
PWGA30.RSF
PWGA30.CNT
PWGA30.CTL
PWGA30.CSBR
PWGA30.CRBR
PWGA30.CTBR
PWGA31.CSDR
PWGA31.CRDR
PWGA31.CTDR
PWGA31.RDT
PWGA31.RSF
PWGA31.CNT
PWGA31.CTL
PWGA31.CSBR
PWGA31.CRBR
PWGA31.CTBR
PWGA32.CSDR
PWGA32.CRDR
PWGA32.CTDR
PWGA32.RDT
PWGA32.RSF
PWGA32.CNT
PWGA32.CTL
PWGA32.CSBR
PWGA32.CRBR
PWGA32.CTBR
PWGA33.CSDR
PWGA33.CRDR
PWGA33.CTDR
PWGA33.RDT
PWGA33.RSF
PWGA33.CNT
PWGA33.CTL
PWGA33.CSBR
PWGA33.CRBR
PWGA33.CTBR
PWGA34.CSDR
PWGA34.CRDR
PWGA34.CTDR
PWGA34.RDT
PWGA34.RSF
PWGA34.CNT
PWGA34.CTL
PWGA34.CSBR
PWGA34.CRBR
PWGA34.CTBR
PWGA35.CSDR
PWGA35.CRDR
PWGA35.CTDR
PWGA35.RDT
PWGA35.RSF
PWGA35.CNT
PWGA35.CTL
PWGA35.CSBR
PWGA35.CRBR
PWGA35.CTBR
PWGA36.CSDR
PWGA36.CRDR
PWGA36.CTDR
PWGA36.RDT
PWGA36.RSF
PWGA36.CNT
PWGA36.CTL
PWGA36.CSBR
PWGA36.CRBR
PWGA36.CTBR
PWGA37.CSDR
PWGA37.CRDR
PWGA37.CTDR
PWGA37.RDT
PWGA37.RSF
PWGA37.CNT
PWGA37.CTL
PWGA37.CSBR
PWGA37.CRBR
PWGA37.CTBR
PWGA38.CSDR
PWGA38.CRDR
PWGA38.CTDR
PWGA38.RDT
PWGA38.RSF
PWGA38.CNT
PWGA38.CTL
PWGA38.CSBR
PWGA38.CRBR
PWGA38.CTBR
PWGA39.CSDR
PWGA39.CRDR
PWGA39.CTDR
PWGA39.RDT
PWGA39.RSF
PWGA39.CNT
PWGA39.CTL
PWGA39.CSBR
PWGA39.CRBR
PWGA39.CTBR
PWGA40.CSDR
PWGA40.CRDR
PWGA40.CTDR
PWGA40.RDT
PWGA40.RSF
PWGA40.CNT
PWGA40.CTL
PWGA40.CSBR
PWGA40.CRBR
PWGA40.CTBR
PWGA41.CSDR
PWGA41.CRDR
PWGA41.CTDR
PWGA41.RDT
PWGA41.RSF
PWGA41.CNT
PWGA41.CTL
PWGA41.CSBR
PWGA41.CRBR
PWGA41.CTBR
PWGA42.CSDR
PWGA42.CRDR
PWGA42.CTDR
PWGA42.RDT
PWGA42.RSF
PWGA42.CNT
PWGA42.CTL
PWGA42.CSBR
PWGA42.CRBR
PWGA42.CTBR
PWGA43.CSDR
PWGA43.CRDR
PWGA43.CTDR
PWGA43.RDT
PWGA43.RSF
PWGA43.CNT
PWGA43.CTL
PWGA43.CSBR
PWGA43.CRBR
PWGA43.CTBR
PWGA44.CSDR
PWGA44.CRDR
PWGA44.CTDR
PWGA44.RDT
PWGA44.RSF
PWGA44.CNT
PWGA44.CTL
PWGA44.CSBR
PWGA44.CRBR
PWGA44.CTBR
PWGA45.CSDR
PWGA45.CRDR
PWGA45.CTDR
PWGA45.RDT
PWGA45.RSF
PWGA45.CNT
PWGA45.CTL
PWGA45.CSBR
PWGA45.CRBR
PWGA45.CTBR
PWGA46.CSDR
PWGA46.CRDR
PWGA46.CTDR
PWGA46.RDT
PWGA46.RSF
PWGA46.CNT
PWGA46.CTL
PWGA46.CSBR
PWGA46.CRBR
PWGA46.CTBR
PWGA47.CSDR
PWGA47.CRDR
PWGA47.CTDR
PWGA47.RDT
PWGA47.RSF
PWGA47.CNT
PWGA47.CTL
PWGA47.CSBR
PWGA47.CRBR
PWGA47.CTBR
PWGA48.CSDR
PWGA48.CRDR
PWGA48.CTDR
PWGA48.RDT
PWGA48.RSF
PWGA48.CNT
PWGA48.CTL
PWGA48.CSBR
PWGA48.CRBR
PWGA48.CTBR
PWGA49.CSDR
PWGA49.CRDR
PWGA49.CTDR
PWGA49.RDT
PWGA49.RSF
PWGA49.CNT
PWGA49.CTL
PWGA49.CSBR
PWGA49.CRBR
PWGA49.CTBR
PWGA50.CSDR
PWGA50.CRDR
PWGA50.CTDR
PWGA50.RDT
PWGA50.RSF
PWGA50.CNT
PWGA50.CTL
PWGA50.CSBR
PWGA50.CRBR
PWGA50.CTBR
PWGA51.CSDR
PWGA51.CRDR
PWGA51.CTDR
PWGA51.RDT
PWGA51.RSF
PWGA51.CNT
PWGA51.CTL
PWGA51.CSBR
PWGA51.CRBR
PWGA51.CTBR
PWGA52.CSDR
PWGA52.CRDR
PWGA52.CTDR
PWGA52.RDT
PWGA52.RSF
PWGA52.CNT
PWGA52.CTL
PWGA52.CSBR
PWGA52.CRBR
PWGA52.CTBR
PWGA53.CSDR
PWGA53.CRDR
PWGA53.CTDR
PWGA53.RDT
PWGA53.RSF
PWGA53.CNT
PWGA53.CTL
PWGA53.CSBR
PWGA53.CRBR
PWGA53.CTBR
PWGA54.CSDR
PWGA54.CRDR
PWGA54.CTDR
PWGA54.RDT
PWGA54.RSF
PWGA54.CNT
PWGA54.CTL
PWGA54.CSBR
PWGA54.CRBR
PWGA54.CTBR
PWGA55.CSDR
PWGA55.CRDR
PWGA55.CTDR
PWGA55.RDT
PWGA55.RSF
PWGA55.CNT
PWGA55.CTL
PWGA55.CSBR
PWGA55.CRBR
PWGA55.CTBR
PWGA56.CSDR
PWGA56.CRDR
PWGA56.CTDR
PWGA56.RDT
PWGA56.RSF
PWGA56.CNT
PWGA56.CTL
PWGA56.CSBR
PWGA56.CRBR
PWGA56.CTBR
PWGA57.CSDR
PWGA57.CRDR
PWGA57.CTDR
PWGA57.RDT
PWGA57.RSF
PWGA57.CNT
PWGA57.CTL
PWGA57.CSBR
PWGA57.CRBR
PWGA57.CTBR
PWGA58.CSDR
PWGA58.CRDR
PWGA58.CTDR
PWGA58.RDT
PWGA58.RSF
PWGA58.CNT
PWGA58.CTL
PWGA58.CSBR
PWGA58.CRBR
PWGA58.CTBR
PWGA59.CSDR
PWGA59.CRDR
PWGA59.CTDR
PWGA59.RDT
PWGA59.RSF
PWGA59.CNT
PWGA59.CTL
PWGA59.CSBR
PWGA59.CRBR
PWGA59.CTBR
PWGA60.CSDR
PWGA60.CRDR
PWGA60.CTDR
PWGA60.RDT
PWGA60.RSF
PWGA60.CNT
PWGA60.CTL
PWGA60.CSBR
PWGA60.CRBR
PWGA60.CTBR
PWGA61.CSDR
PWGA61.CRDR
PWGA61.CTDR
PWGA61.RDT
PWGA61.RSF
PWGA61.CNT
PWGA61.CTL
PWGA61.CSBR
PWGA61.CRBR
PWGA61.CTBR
PWGA62.CSDR
PWGA62.CRDR
PWGA62.CTDR
PWGA62.RDT
PWGA62.RSF
PWGA62.CNT
PWGA62.CTL
PWGA62.CSBR
PWGA62.CRBR
PWGA62.CTBR
PWGA63.CSDR
PWGA63.CRDR
PWGA63.CTDR
PWGA63.RDT
PWGA63.RSF
PWGA63.CNT
PWGA63.CTL
PWGA63.CSBR
PWGA63.CRBR
PWGA63.CTBR
PWGA64.CSDR
PWGA64.CRDR
PWGA64.CTDR
PWGA64.RDT
PWGA64.RSF
PWGA64.CNT
PWGA64.CTL
PWGA64.CSBR
PWGA64.CRBR
PWGA64.CTBR
PWGA65.CSDR
PWGA65.CRDR
PWGA65.CTDR
PWGA65.RDT
PWGA65.RSF
PWGA65.CNT
PWGA65.CTL
PWGA65.CSBR
PWGA65.CRBR
PWGA65.CTBR
PWGA66.CSDR
PWGA66.CRDR
PWGA66.CTDR
PWGA66.RDT
PWGA66.RSF
PWGA66.CNT
PWGA66.CTL
PWGA66.CSBR
PWGA66.CRBR
PWGA66.CTBR
PWGA67.CSDR
PWGA67.CRDR
PWGA67.CTDR
PWGA67.RDT
PWGA67.RSF
PWGA67.CNT
PWGA67.CTL
PWGA67.CSBR
PWGA67.CRBR
PWGA67.CTBR
PWGA68.CSDR
PWGA68.CRDR
PWGA68.CTDR
PWGA68.RDT
PWGA68.RSF
PWGA68.CNT
PWGA68.CTL
PWGA68.CSBR
PWGA68.CRBR
PWGA68.CTBR
PWGA69.CSDR
PWGA69.CRDR
PWGA69.CTDR
PWGA69.RDT
PWGA69.RSF
PWGA69.CNT
PWGA69.CTL
PWGA69.CSBR
PWGA69.CRBR
PWGA69.CTBR
PWGA70.CSDR
PWGA70.CRDR
PWGA70.CTDR
PWGA70.RDT
PWGA70.RSF
PWGA70.CNT
PWGA70.CTL
PWGA70.CSBR
PWGA70.CRBR
PWGA70.CTBR
PWGA71.CSDR
PWGA71.CRDR
PWGA71.CTDR
PWGA71.RDT
PWGA71.RSF
PWGA71.CNT
PWGA71.CTL
PWGA71.CSBR
PWGA71.CRBR
PWGA71.CTBR
PWBA0.BRS0 ... PWBA0.BRS3
PWBA0.TE
PWBA0.TS
PWBA0.TT
PWBA0.EMU
RTCA0.CTL0.UINT8
RTCA0.CTL0.BIT.SLSB
RTCA0.CTL0.BIT.AMPM
RTCA0.CTL0.BIT.CEST
RTCA0.CTL0.BIT.CE
RTCA0.CTL1.UINT8
RTCA0.CTL1.BIT.CT0 ... RTCA0.CTL1.BIT.CT2
RTCA0.CTL1.BIT.EN1S
RTCA0.CTL1.BIT.ENALM
RTCA0.CTL1.BIT.EN1HZ
RTCA0.CTL2.UINT8
RTCA0.CTL2.BIT.WAIT
RTCA0.CTL2.BIT.WST
RTCA0.CTL2.BIT.RSUB
RTCA0.CTL2.BIT.RSST
RTCA0.CTL2.BIT.WSST
RTCA0.CTL2.BIT.WUST
RTCA0.SUBC
RTCA0.SRBU
RTCA0.SEC
RTCA0.MIN
RTCA0.HOUR
RTCA0.WEEK
RTCA0.DAY
RTCA0.MONTH
RTCA0.YEAR
RTCA0.TIME
RTCA0.CAL
RTCA0.SUBU
RTCA0.SCMP
RTCA0.ALM
RTCA0.ALH
RTCA0.ALW
RTCA0.SECC
RTCA0.MINC
RTCA0.HOURC
RTCA0.WEEKC
RTCA0.DAYC
RTCA0.MONC
RTCA0.YEARC
RTCA0.TIMEC
RTCA0.CALC
RTCA0.EMU.UINT8
RTCA0.EMU.BIT.SVSDIS
ENCA0.CCR0
ENCA0.CCR1
ENCA0.CNT
ENCA0.FLG
ENCA0.FGC
ENCA0.TE
ENCA0.TS
ENCA0.TT
ENCA0.IOC0
ENCA0.CTL
ENCA0.IOC1
ENCA0.EMU
TAPA0.FLG
TAPA0.ACWE
TAPA0.ACTS
TAPA0.ACTT
TAPA0.OPHS
TAPA0.OPHT
TAPA0.CTL0
TAPA0.CTL1
TAPA0.EMU
OSTM0.CMP
OSTM0.CNT
OSTM0.TE
OSTM0.TS
OSTM0.TT
OSTM0.CTL
OSTM0.EMU
WDTA0.WDTE
WDTA0.EVAC
WDTA0.REF
WDTA0.MD
WDTA1.WDTE
WDTA1.EVAC
WDTA1.REF
WDTA1.MD
ADCA0.VCR00.UINT32
ADCA0.VCR00.UINT16[L]
ADCA0.VCR00.UINT8[LL/LH]
ADCA0.VCR01.UINT32
ADCA0.VCR01.UINT16[L]
ADCA0.VCR01.UINT8[LL/LH]
ADCA0.VCR02.UINT32
ADCA0.VCR02.UINT16[L]
ADCA0.VCR02.UINT8[LL/LH]
ADCA0.VCR03.UINT32
ADCA0.VCR03.UINT16[L]
ADCA0.VCR03.UINT8[LL/LH]
ADCA0.VCR04.UINT32
ADCA0.VCR04.UINT16[L]
ADCA0.VCR04.UINT8[LL/LH]
ADCA0.VCR05.UINT32
ADCA0.VCR05.UINT16[L]
ADCA0.VCR05.UINT8[LL/LH]
ADCA0.VCR06.UINT32
ADCA0.VCR06.UINT16[L]
ADCA0.VCR06.UINT8[LL/LH]
ADCA0.VCR07.UINT32
ADCA0.VCR07.UINT16[L]
ADCA0.VCR07.UINT8[LL/LH]
ADCA0.VCR08.UINT32
ADCA0.VCR08.UINT16[L]
ADCA0.VCR08.UINT8[LL/LH]
ADCA0.VCR09.UINT32
ADCA0.VCR09.UINT16[L]
ADCA0.VCR09.UINT8[LL/LH]
ADCA0.VCR10.UINT32
ADCA0.VCR10.UINT16[L]
ADCA0.VCR10.UINT8[LL/LH]
ADCA0.VCR11.UINT32
ADCA0.VCR11.UINT16[L]
ADCA0.VCR11.UINT8[LL/LH]
ADCA0.VCR12.UINT32
ADCA0.VCR12.UINT16[L]
ADCA0.VCR12.UINT8[LL/LH]
ADCA0.VCR13.UINT32
ADCA0.VCR13.UINT16[L]
ADCA0.VCR13.UINT8[LL/LH]
ADCA0.VCR14.UINT32
ADCA0.VCR14.UINT16[L]
ADCA0.VCR14.UINT8[LL/LH]
ADCA0.VCR15.UINT32
ADCA0.VCR15.UINT16[L]
ADCA0.VCR15.UINT8[LL/LH]
ADCA0.VCR16.UINT32
ADCA0.VCR16.UINT16[L]
ADCA0.VCR16.UINT8[LL/LH]
ADCA0.VCR17.UINT32
ADCA0.VCR17.UINT16[L]
ADCA0.VCR17.UINT8[LL/LH]
ADCA0.VCR18.UINT32
ADCA0.VCR18.UINT16[L]
ADCA0.VCR18.UINT8[LL/LH]
ADCA0.VCR19.UINT32
ADCA0.VCR19.UINT16[L]
ADCA0.VCR19.UINT8[LL/LH]
ADCA0.VCR20.UINT32
ADCA0.VCR20.UINT16[L]
ADCA0.VCR20.UINT8[LL/LH]
ADCA0.VCR21.UINT32
ADCA0.VCR21.UINT16[L]
ADCA0.VCR21.UINT8[LL/LH]
ADCA0.VCR22.UINT32
ADCA0.VCR22.UINT16[L]
ADCA0.VCR22.UINT8[LL/LH]
ADCA0.VCR23.UINT32
ADCA0.VCR23.UINT16[L]
ADCA0.VCR23.UINT8[LL/LH]
ADCA0.VCR24.UINT32
ADCA0.VCR24.UINT16[L]
ADCA0.VCR24.UINT8[LL/LH]
ADCA0.VCR25.UINT32
ADCA0.VCR25.UINT16[L]
ADCA0.VCR25.UINT8[LL/LH]
ADCA0.VCR26.UINT32
ADCA0.VCR26.UINT16[L]
ADCA0.VCR26.UINT8[LL/LH]
ADCA0.VCR27.UINT32
ADCA0.VCR27.UINT16[L]
ADCA0.VCR27.UINT8[LL/LH]
ADCA0.VCR28.UINT32
ADCA0.VCR28.UINT16[L]
ADCA0.VCR28.UINT8[LL/LH]
ADCA0.VCR29.UINT32
ADCA0.VCR29.UINT16[L]
ADCA0.VCR29.UINT8[LL/LH]
ADCA0.VCR30.UINT32
ADCA0.VCR30.UINT16[L]
ADCA0.VCR30.UINT8[LL/LH]
ADCA0.VCR31.UINT32
ADCA0.VCR31.UINT16[L]
ADCA0.VCR31.UINT8[LL/LH]
ADCA0.VCR32.UINT32
ADCA0.VCR32.UINT16[L]
ADCA0.VCR32.UINT8[LL/LH]
ADCA0.VCR33.UINT32
ADCA0.VCR33.UINT16[L]
ADCA0.VCR33.UINT8[LL/LH]
ADCA0.VCR34.UINT32
ADCA0.VCR34.UINT16[L]
ADCA0.VCR34.UINT8[LL/LH]
ADCA0.VCR35.UINT32
ADCA0.VCR35.UINT16[L]
ADCA0.VCR35.UINT8[LL/LH]
ADCA0.VCR36.UINT32
ADCA0.VCR36.UINT16[L]
ADCA0.VCR36.UINT8[LL/LH]
ADCA0.VCR37.UINT32
ADCA0.VCR37.UINT16[L]
ADCA0.VCR37.UINT8[LL/LH]
ADCA0.VCR38.UINT32
ADCA0.VCR38.UINT16[L]
ADCA0.VCR38.UINT8[LL/LH]
ADCA0.VCR39.UINT32
ADCA0.VCR39.UINT16[L]
ADCA0.VCR39.UINT8[LL/LH]
ADCA0.VCR40.UINT32
ADCA0.VCR40.UINT16[L]
ADCA0.VCR40.UINT8[LL/LH]
ADCA0.VCR41.UINT32
ADCA0.VCR41.UINT16[L]
ADCA0.VCR41.UINT8[LL/LH]
ADCA0.VCR42.UINT32
ADCA0.VCR42.UINT16[L]
ADCA0.VCR42.UINT8[LL/LH]
ADCA0.VCR43.UINT32
ADCA0.VCR43.UINT16[L]
ADCA0.VCR43.UINT8[LL/LH]
ADCA0.VCR44.UINT32
ADCA0.VCR44.UINT16[L]
ADCA0.VCR44.UINT8[LL/LH]
ADCA0.VCR45.UINT32
ADCA0.VCR45.UINT16[L]
ADCA0.VCR45.UINT8[LL/LH]
ADCA0.VCR46.UINT32
ADCA0.VCR46.UINT16[L]
ADCA0.VCR46.UINT8[LL/LH]
ADCA0.VCR47.UINT32
ADCA0.VCR47.UINT16[L]
ADCA0.VCR47.UINT8[LL/LH]
ADCA0.VCR48.UINT32
ADCA0.VCR48.UINT16[L]
ADCA0.VCR48.UINT8[LL/LH]
ADCA0.VCR49.UINT32
ADCA0.VCR49.UINT16[L]
ADCA0.VCR49.UINT8[LL/LH]
ADCA0.PWDVCR.UINT32
ADCA0.PWDVCR.UINT16[L]
ADCA0.PWDVCR.UINT8[LL/LH]
ADCA0.DR00.UINT32
ADCA0.DR00.UINT16[L/H]
ADCA0.DR02.UINT32
ADCA0.DR02.UINT16[L/H]
ADCA0.DR04.UINT32
ADCA0.DR04.UINT16[L/H]
ADCA0.DR06.UINT32
ADCA0.DR06.UINT16[L/H]
ADCA0.DR08.UINT32
ADCA0.DR08.UINT16[L/H]
ADCA0.DR10.UINT32
ADCA0.DR10.UINT16[L/H]
ADCA0.DR12.UINT32
ADCA0.DR12.UINT16[L/H]
ADCA0.DR14.UINT32
ADCA0.DR14.UINT16[L/H]
ADCA0.DR16.UINT32
ADCA0.DR16.UINT16[L/H]
ADCA0.DR18.UINT32
ADCA0.DR18.UINT16[L/H]
ADCA0.DR20.UINT32
ADCA0.DR20.UINT16[L/H]
ADCA0.DR22.UINT32
ADCA0.DR22.UINT16[L/H]
ADCA0.DR24.UINT32
ADCA0.DR24.UINT16[L/H]
ADCA0.DR26.UINT32
ADCA0.DR26.UINT16[L/H]
ADCA0.DR28.UINT32
ADCA0.DR28.UINT16[L/H]
ADCA0.DR30.UINT32
ADCA0.DR30.UINT16[L/H]
ADCA0.DR32.UINT32
ADCA0.DR32.UINT16[L/H]
ADCA0.DR34.UINT32
ADCA0.DR34.UINT16[L/H]
ADCA0.DR36.UINT32
ADCA0.DR36.UINT16[L/H]
ADCA0.DR38.UINT32
ADCA0.DR38.UINT16[L/H]
ADCA0.DR40.UINT32
ADCA0.DR40.UINT16[L/H]
ADCA0.DR42.UINT32
ADCA0.DR42.UINT16[L/H]
ADCA0.DR44.UINT32
ADCA0.DR44.UINT16[L/H]
ADCA0.DR46.UINT32
ADCA0.DR46.UINT16[L/H]
ADCA0.DR48.UINT32
ADCA0.DR48.UINT16[L/H]
ADCA0.PWDTSNDR.UINT32
ADCA0.PWDTSNDR.UINT16[H]
ADCA0.DIR00 ... ADCA0.DIR49
ADCA0.PWDDIR
ADCA0.ADHALTR.UINT32
ADCA0.ADHALTR.UINT16[L]
ADCA0.ADHALTR.UINT8[LL]
ADCA0.ADCR.UINT32
ADCA0.ADCR.UINT16[L]
ADCA0.ADCR.UINT8[LL]
ADCA0.SGSTR.UINT32
ADCA0.SGSTR.UINT16[L]
ADCA0.MPXCURR.UINT32
ADCA0.MPXCURR.UINT16[L]
ADCA0.MPXCURR.UINT8[LL]
ADCA0.THSMPSTCR.UINT32
ADCA0.THSMPSTCR.UINT16[L]
ADCA0.THSMPSTCR.UINT8[LL]
ADCA0.THCR.UINT32
ADCA0.THCR.UINT16[L]
ADCA0.THCR.UINT8[LL]
ADCA0.THAHLDSTCR.UINT32
ADCA0.THAHLDSTCR.UINT16[L]
ADCA0.THAHLDSTCR.UINT8[LL]
ADCA0.THBHLDSTCR.UINT32
ADCA0.THBHLDSTCR.UINT16[L]
ADCA0.THBHLDSTCR.UINT8[LL]
ADCA0.THACR.UINT32
ADCA0.THACR.UINT16[L]
ADCA0.THACR.UINT8[LL]
ADCA0.THBCR.UINT32
ADCA0.THBCR.UINT16[L]
ADCA0.THBCR.UINT8[LL]
ADCA0.THER.UINT32
ADCA0.THER.UINT16[L]
ADCA0.THER.UINT8[LL]
ADCA0.THGSR.UINT32
ADCA0.THGSR.UINT16[L]
ADCA0.THGSR.UINT8[LL]
ADCA0.SFTCR.UINT32
ADCA0.SFTCR.UINT16[L]
ADCA0.SFTCR.UINT8[LL]
ADCA0.ULLMTBR0.UINT32
ADCA0.ULLMTBR0.UINT16[L/H]
ADCA0.ULLMTBR1.UINT32
ADCA0.ULLMTBR1.UINT16[L/H]
ADCA0.ULLMTBR2.UINT32
ADCA0.ULLMTBR2.UINT16[L/H]
ADCA0.ECR.UINT32
ADCA0.ECR.UINT16[L]
ADCA0.ECR.UINT8[LL]
ADCA0.ULER.UINT32
ADCA0.ULER.UINT16[L]
ADCA0.ULER.UINT8[LL/LH]
ADCA0.OWER.UINT32
ADCA0.OWER.UINT16[L]
ADCA0.OWER.UINT8[LL]
ADCA0.DGCTL0.UINT32
ADCA0.DGCTL0.UINT16[L]
ADCA0.DGCTL0.UINT8[LL]
ADCA0.DGCTL1.UINT32
ADCA0.DGCTL1.UINT16[L]
ADCA0.PDCTL1.UINT32
ADCA0.PDCTL1.UINT16[L]
ADCA0.PDCTL2.UINT32
ADCA0.PDCTL2.UINT16[L/H]
ADCA0.PDCTL2.UINT8[LL/LH/HL]
ADCA0.SMPCR.UINT32
ADCA0.SMPCR.UINT16[L]
ADCA0.SMPCR.UINT8[LL]
ADCA0.EMU
ADCA0.SGSTCR1.UINT32
ADCA0.SGSTCR1.UINT16[L]
ADCA0.SGSTCR1.UINT8[LL]
ADCA0.SGCR1.UINT32
ADCA0.SGCR1.UINT16[L]
ADCA0.SGCR1.UINT8[LL]
ADCA0.SGVCSP1.UINT32
ADCA0.SGVCSP1.UINT16[L]
ADCA0.SGVCSP1.UINT8[LL]
ADCA0.SGVCEP1.UINT32
ADCA0.SGVCEP1.UINT16[L]
ADCA0.SGVCEP1.UINT8[LL]
ADCA0.SGMCYCR1.UINT32
ADCA0.SGMCYCR1.UINT16[L]
ADCA0.SGMCYCR1.UINT8[LL]
ADCA0.SGSEFCR1.UINT32
ADCA0.SGSEFCR1.UINT16[L]
ADCA0.SGSEFCR1.UINT8[LL]
ADCA0.SGTSEL1.UINT32
ADCA0.SGTSEL1.UINT16[L]
ADCA0.SGSTCR2.UINT32
ADCA0.SGSTCR2.UINT16[L]
ADCA0.SGSTCR2.UINT8[LL]
ADCA0.SGCR2.UINT32
ADCA0.SGCR2.UINT16[L]
ADCA0.SGCR2.UINT8[LL]
ADCA0.SGVCSP2.UINT32
ADCA0.SGVCSP2.UINT16[L]
ADCA0.SGVCSP2.UINT8[LL]
ADCA0.SGVCEP2.UINT32
ADCA0.SGVCEP2.UINT16[L]
ADCA0.SGVCEP2.UINT8[LL]
ADCA0.SGMCYCR2.UINT32
ADCA0.SGMCYCR2.UINT16[L]
ADCA0.SGMCYCR2.UINT8[LL]
ADCA0.SGSEFCR2.UINT32
ADCA0.SGSEFCR2.UINT16[L]
ADCA0.SGSEFCR2.UINT8[LL]
ADCA0.SGTSEL2.UINT32
ADCA0.SGTSEL2.UINT16[L]
ADCA0.SGSTCR3.UINT32
ADCA0.SGSTCR3.UINT16[L]
ADCA0.SGSTCR3.UINT8[LL]
ADCA0.SGCR3.UINT32
ADCA0.SGCR3.UINT16[L]
ADCA0.SGCR3.UINT8[LL]
ADCA0.SGVCSP3.UINT32
ADCA0.SGVCSP3.UINT16[L]
ADCA0.SGVCSP3.UINT8[LL]
ADCA0.SGVCEP3.UINT32
ADCA0.SGVCEP3.UINT16[L]
ADCA0.SGVCEP3.UINT8[LL]
ADCA0.SGMCYCR3.UINT32
ADCA0.SGMCYCR3.UINT16[L]
ADCA0.SGMCYCR3.UINT8[LL]
ADCA0.SGSEFCR3.UINT32
ADCA0.SGSEFCR3.UINT16[L]
ADCA0.SGSEFCR3.UINT8[LL]
ADCA0.SGTSEL3.UINT32
ADCA0.SGTSEL3.UINT16[L]
ADCA0.PWDSGCR.UINT32
ADCA0.PWDSGCR.UINT16[L]
ADCA0.PWDSGCR.UINT8[LL]
ADCA0.PWDSGSEFCR.UINT32
ADCA0.PWDSGSEFCR.UINT16[L]
ADCA0.PWDSGSEFCR.UINT8[LL]
ADCA1.VCR00.UINT32
ADCA1.VCR00.UINT16[L]
ADCA1.VCR00.UINT8[LL/LH]
ADCA1.VCR01.UINT32
ADCA1.VCR01.UINT16[L]
ADCA1.VCR01.UINT8[LL/LH]
ADCA1.VCR02.UINT32
ADCA1.VCR02.UINT16[L]
ADCA1.VCR02.UINT8[LL/LH]
ADCA1.VCR03.UINT32
ADCA1.VCR03.UINT16[L]
ADCA1.VCR03.UINT8[LL/LH]
ADCA1.VCR04.UINT32
ADCA1.VCR04.UINT16[L]
ADCA1.VCR04.UINT8[LL/LH]
ADCA1.VCR05.UINT32
ADCA1.VCR05.UINT16[L]
ADCA1.VCR05.UINT8[LL/LH]
ADCA1.VCR06.UINT32
ADCA1.VCR06.UINT16[L]
ADCA1.VCR06.UINT8[LL/LH]
ADCA1.VCR07.UINT32
ADCA1.VCR07.UINT16[L]
ADCA1.VCR07.UINT8[LL/LH]
ADCA1.VCR08.UINT32
ADCA1.VCR08.UINT16[L]
ADCA1.VCR08.UINT8[LL/LH]
ADCA1.VCR09.UINT32
ADCA1.VCR09.UINT16[L]
ADCA1.VCR09.UINT8[LL/LH]
ADCA1.VCR10.UINT32
ADCA1.VCR10.UINT16[L]
ADCA1.VCR10.UINT8[LL/LH]
ADCA1.VCR11.UINT32
ADCA1.VCR11.UINT16[L]
ADCA1.VCR11.UINT8[LL/LH]
ADCA1.VCR12.UINT32
ADCA1.VCR12.UINT16[L]
ADCA1.VCR12.UINT8[LL/LH]
ADCA1.VCR13.UINT32
ADCA1.VCR13.UINT16[L]
ADCA1.VCR13.UINT8[LL/LH]
ADCA1.VCR14.UINT32
ADCA1.VCR14.UINT16[L]
ADCA1.VCR14.UINT8[LL/LH]
ADCA1.VCR15.UINT32
ADCA1.VCR15.UINT16[L]
ADCA1.VCR15.UINT8[LL/LH]
ADCA1.VCR16.UINT32
ADCA1.VCR16.UINT16[L]
ADCA1.VCR16.UINT8[LL/LH]
ADCA1.VCR17.UINT32
ADCA1.VCR17.UINT16[L]
ADCA1.VCR17.UINT8[LL/LH]
ADCA1.VCR18.UINT32
ADCA1.VCR18.UINT16[L]
ADCA1.VCR18.UINT8[LL/LH]
ADCA1.VCR19.UINT32
ADCA1.VCR19.UINT16[L]
ADCA1.VCR19.UINT8[LL/LH]
ADCA1.VCR20.UINT32
ADCA1.VCR20.UINT16[L]
ADCA1.VCR20.UINT8[LL/LH]
ADCA1.VCR21.UINT32
ADCA1.VCR21.UINT16[L]
ADCA1.VCR21.UINT8[LL/LH]
ADCA1.VCR22.UINT32
ADCA1.VCR22.UINT16[L]
ADCA1.VCR22.UINT8[LL/LH]
ADCA1.VCR23.UINT32
ADCA1.VCR23.UINT16[L]
ADCA1.VCR23.UINT8[LL/LH]
ADCA1.PWDVCR.UINT32
ADCA1.PWDVCR.UINT16[L]
ADCA1.PWDVCR.UINT8[LL/LH]
ADCA1.DR00.UINT32
ADCA1.DR00.UINT16[L/H]
ADCA1.DR02.UINT32
ADCA1.DR02.UINT16[L/H]
ADCA1.DR04.UINT32
ADCA1.DR04.UINT16[L/H]
ADCA1.DR06.UINT32
ADCA1.DR06.UINT16[L/H]
ADCA1.DR08.UINT32
ADCA1.DR08.UINT16[L/H]
ADCA1.DR10.UINT32
ADCA1.DR10.UINT16[L/H]
ADCA1.DR12.UINT32
ADCA1.DR12.UINT16[L/H]
ADCA1.DR14.UINT32
ADCA1.DR14.UINT16[L/H]
ADCA1.DR16.UINT32
ADCA1.DR16.UINT16[L/H]
ADCA1.DR18.UINT32
ADCA1.DR18.UINT16[L/H]
ADCA1.DR20.UINT32
ADCA1.DR20.UINT16[L/H]
ADCA1.DR22.UINT32
ADCA1.DR22.UINT16[L/H]
ADCA1.PWDTSNDR.UINT32
ADCA1.PWDTSNDR.UINT16[H]
ADCA1.DIR00 ... ADCA1.DIR23
ADCA1.PWDDIR
ADCA1.ADHALTR.UINT32
ADCA1.ADHALTR.UINT16[L]
ADCA1.ADHALTR.UINT8[LL]
ADCA1.ADCR.UINT32
ADCA1.ADCR.UINT16[L]
ADCA1.ADCR.UINT8[LL]
ADCA1.SGSTR.UINT32
ADCA1.SGSTR.UINT16[L]
ADCA1.SFTCR.UINT32
ADCA1.SFTCR.UINT16[L]
ADCA1.SFTCR.UINT8[LL]
ADCA1.ULLMTBR0.UINT32
ADCA1.ULLMTBR0.UINT16[L/H]
ADCA1.ULLMTBR1.UINT32
ADCA1.ULLMTBR1.UINT16[L/H]
ADCA1.ULLMTBR2.UINT32
ADCA1.ULLMTBR2.UINT16[L/H]
ADCA1.ECR.UINT32
ADCA1.ECR.UINT16[L]
ADCA1.ECR.UINT8[LL]
ADCA1.ULER.UINT32
ADCA1.ULER.UINT16[L]
ADCA1.ULER.UINT8[LL/LH]
ADCA1.OWER.UINT32
ADCA1.OWER.UINT16[L]
ADCA1.OWER.UINT8[LL]
ADCA1.DGCTL0.UINT32
ADCA1.DGCTL0.UINT16[L]
ADCA1.DGCTL0.UINT8[LL]
ADCA1.DGCTL1.UINT32
ADCA1.DGCTL1.UINT16[L]
ADCA1.PDCTL1.UINT32
ADCA1.PDCTL1.UINT16[L]
ADCA1.PDCTL2.UINT32
ADCA1.PDCTL2.UINT16[L]
ADCA1.PDCTL2.UINT8[LL]
ADCA1.SMPCR.UINT32
ADCA1.SMPCR.UINT16[L]
ADCA1.SMPCR.UINT8[LL]
ADCA1.EMU
ADCA1.SGSTCR1.UINT32
ADCA1.SGSTCR1.UINT16[L]
ADCA1.SGSTCR1.UINT8[LL]
ADCA1.SGCR1.UINT32
ADCA1.SGCR1.UINT16[L]
ADCA1.SGCR1.UINT8[LL]
ADCA1.SGVCSP1.UINT32
ADCA1.SGVCSP1.UINT16[L]
ADCA1.SGVCSP1.UINT8[LL]
ADCA1.SGVCEP1.UINT32
ADCA1.SGVCEP1.UINT16[L]
ADCA1.SGVCEP1.UINT8[LL]
ADCA1.SGMCYCR1.UINT32
ADCA1.SGMCYCR1.UINT16[L]
ADCA1.SGMCYCR1.UINT8[LL]
ADCA1.SGSEFCR1.UINT32
ADCA1.SGSEFCR1.UINT16[L]
ADCA1.SGSEFCR1.UINT8[LL]
ADCA1.SGTSEL1.UINT32
ADCA1.SGTSEL1.UINT16[L]
ADCA1.SGSTCR2.UINT32
ADCA1.SGSTCR2.UINT16[L]
ADCA1.SGSTCR2.UINT8[LL]
ADCA1.SGCR2.UINT32
ADCA1.SGCR2.UINT16[L]
ADCA1.SGCR2.UINT8[LL]
ADCA1.SGVCSP2.UINT32
ADCA1.SGVCSP2.UINT16[L]
ADCA1.SGVCSP2.UINT8[LL]
ADCA1.SGVCEP2.UINT32
ADCA1.SGVCEP2.UINT16[L]
ADCA1.SGVCEP2.UINT8[LL]
ADCA1.SGMCYCR2.UINT32
ADCA1.SGMCYCR2.UINT16[L]
ADCA1.SGMCYCR2.UINT8[LL]
ADCA1.SGSEFCR2.UINT32
ADCA1.SGSEFCR2.UINT16[L]
ADCA1.SGSEFCR2.UINT8[LL]
ADCA1.SGTSEL2.UINT32
ADCA1.SGTSEL2.UINT16[L]
ADCA1.SGSTCR3.UINT32
ADCA1.SGSTCR3.UINT16[L]
ADCA1.SGSTCR3.UINT8[LL]
ADCA1.SGCR3.UINT32
ADCA1.SGCR3.UINT16[L]
ADCA1.SGCR3.UINT8[LL]
ADCA1.SGVCSP3.UINT32
ADCA1.SGVCSP3.UINT16[L]
ADCA1.SGVCSP3.UINT8[LL]
ADCA1.SGVCEP3.UINT32
ADCA1.SGVCEP3.UINT16[L]
ADCA1.SGVCEP3.UINT8[LL]
ADCA1.SGMCYCR3.UINT32
ADCA1.SGMCYCR3.UINT16[L]
ADCA1.SGMCYCR3.UINT8[LL]
ADCA1.SGSEFCR3.UINT32
ADCA1.SGSEFCR3.UINT16[L]
ADCA1.SGSEFCR3.UINT8[LL]
ADCA1.SGTSEL3.UINT32
ADCA1.SGTSEL3.UINT16[L]
ADCA1.PWDSGCR.UINT32
ADCA1.PWDSGCR.UINT16[L]
ADCA1.PWDSGCR.UINT8[LL]
ADCA1.PWDSGSEFCR.UINT32
ADCA1.PWDSGSEFCR.UINT16[L]
ADCA1.PWDSGSEFCR.UINT8[LL]
DCRA0.CIN
DCRA0.COUT
DCRA0.CTL
DCRA1.CIN
DCRA1.COUT
DCRA1.CTL
DCRA2.CIN
DCRA2.COUT
DCRA2.CTL
DCRA3.CIN
DCRA3.COUT
DCRA3.CTL
KR0.KRM.UINT8
KR0.KRM.BIT.KRM0 ... KR0.KRM.BIT.KRM7
CLMA0.CTL0
CLMA0.CMPL
CLMA0.CMPH
CLMA0.PCMD
CLMA0.PS
CLMA0.EMU0
CLMA.TEST
CLMA.TESTS
CLMA1.CTL0
CLMA1.CMPL
CLMA1.CMPH
CLMA1.PCMD
CLMA1.PS
CLMA1.EMU0
CLMA2.CTL0
CLMA2.CMPL
CLMA2.CMPH
CLMA2.PCMD
CLMA2.PS
CLMA2.EMU0
*/
#endif
