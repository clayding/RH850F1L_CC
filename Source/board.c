/**
  ******************************************************************************
  * @file    board.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   24-November-2017
  * @brief  Implementation of all the functions in board.h.
  *          This file provides firmware functions implementation to manage the following
  *          functionalities of the specific board.
  ******************************************************************************
  */

#include "board.h"

/****************************TAUB/D Config*************************************/
//#define TAUB0_INTERVAL_MODE_TEST
//#define TAUB0_PWM_OUTPUT_MODE_TEST
//#define TAUD0_INTERVAL_MODE_TEST
//#define TAUD0_PWM_OUTPUT_MODE_TEST
//#define TAUD0_REAL_TIME_OUTPUT_TYPE_1_TEST
//#define TAUD0_REAL_TIME_OUTPUT_TYPE_2_TEST

/************************WDTA Config ******************************************/
//#define WDTA0_TEST
//#define WDTA1_TEST

/************************RTCA Config ******************************************/
#define RTCA0_TEST


/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool mcu_initialized = FALSE;

static void Board_Port_Config(void);

void Board_MCU_Init(void)
{
    if(mcu_initialized == FALSE){
        System_Clock_Config();
    }
    mcu_initialized = TRUE;

    Board_Port_Config();
}

void System_Clock_Config(void)
{

    while(Clock_OSC_Get_Status(R_OSC_TYPE) == OSC_INACTIVE); //HI IntOSC is not actived,just loop
    //while(Clock_ROSC_Get_Status() == OSC_ACTIVED);//Just for test,del later
    //HI Int OSC is actived
    Clock_MOSC_Config(OSC_ENABLE);//Config Main OSC
    Clock_SOSC_Config(OSC_ENABLE);//Config Sub OSC
    Clock_PLL_Config(OSC_ENABLE); //Config PLL
    Clock_Domain_Set(CPUCLK);//set clock domain for cpuclk
    Clock_Domain_Set(IPERI1);//set clock domain for iperi1
    Clock_Domain_Set(IPERI2);//set clock domain for iperi2
    Clock_Domain_Set(AWDTA);//set clock domain for WDTA
    Clock_Domain_Set(ARTCA);
    //Clock_Domain_Set(AFOUT);
    //Clock_Fout_Config();

}

void Board_Port_Config(void)
{
    Port_InitTypeDef port;

    port.pin_mask = PORT_PIN_3;
    port.opt_mode = PORT_MODE;
    port.io_mode = PORT_OUTPUT_MODE;
    port.echar_t = OUTPUT_PP | OUTPUT_LDS;
    port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum10,&port);

    port.pin_mask = PORT_PIN_5;
    //port.opt_mode = PORT_MODE;
    //port.io_mode = PORT_OUTPUT_MODE;
    //port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum8,&port);

    port.pin_mask = PORT_PIN_9;
    port.opt_mode = AF_MODE;
    port.io_mode = PORT_INPUT_MODE;
    port.echar_t = INPUT_PU|INPUT_PD|INPUT_SHMT1;
    port.alter_t = ALT_FUNC_1;
    Port_Init(PortGroupNum0,&port);
#ifdef TAUB0_PWM_OUTPUT_MODE_TEST
    port.pin_mask = PORT_PIN_11;
    port.opt_mode = AF_MODE;
    port.io_mode = PORT_OUTPUT_MODE;
    port.echar_t = OUTPUT_PP | OUTPUT_HDS;
    //port.bmc_t = BIDIRECTION_MODE_ENABLED;
    port.alter_t = ALT_FUNC_4;
    Port_Init(PortGroupNum10,&port);
#endif
#if defined(TAUD0_PWM_OUTPUT_MODE_TEST) || defined(TAUD0_REAL_TIME_OUTPUT_TYPE_1_TEST) || \
    defined(TAUD0_REAL_TIME_OUTPUT_TYPE_2_TEST)
    port.pin_mask = PORT_PIN_0;
    port.opt_mode = AF_MODE;
    port.io_mode = PORT_OUTPUT_MODE;
    port.echar_t = OUTPUT_PP | OUTPUT_HDS;
    //port.bmc_t = BIDIRECTION_MODE_ENABLED;
    port.alter_t = ALT_FUNC_1;
    Port_Init(PortGroupNum10,&port);
#endif
#ifdef TAUD0_REAL_TIME_OUTPUT_TYPE_1_TEST
    port.pin_mask = PORT_PIN_0;
    port.opt_mode = AF_MODE;
    port.io_mode = PORT_OUTPUT_MODE;
    port.echar_t = OUTPUT_PP | OUTPUT_HDS;
    //port.bmc_t = BIDIRECTION_MODE_ENABLED;
    port.alter_t = ALT_FUNC_2;
    Port_Init(PortGroupNum9,&port);
#endif
#if defined(TAUD0_REAL_TIME_OUTPUT_TYPE_2_TEST)
    port.pin_mask = PORT_PIN_0;
    port.opt_mode = AF_MODE;
    port.io_mode = PORT_INPUT_MODE;
    port.echar_t = INPUT_PU|INPUT_PD|INPUT_SHMT1;
    port.bmc_t = BIDIRECTION_MODE_ENABLED;
    port.alter_t = ALT_FUNC_2;
    Port_Init(PortGroupNum9,&port);
#endif
    {
        Eiint_InitTypeDef eiint;
        eiint.eiint_ch = P_12;
        eiint.eiint_ext_int = 1;
        eiint.eiint_process = INT_PROCESS_ENABLE;
        eiint.eiint_refer_method = TABLE_REFER_METHOD;
        eiint.eiint_priority = INT_PRIORITY_7;
        eiint.eiint_detect = EDGE_DETECTION | FALL_EDGE_ENABLE | RISE_EDGE_DISABLE;
        Eiit_Init(&eiint);

        eiint.eiint_ch = 76;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_5;
        Eiit_Init(&eiint);
#if defined (TAUB0_INTERVAL_MODE_TEST) || defined (TAUB0_PWM_OUTPUT_MODE_TEST)
        eiint.eiint_ch = 134;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);
#endif
#ifdef TAUB0_PWM_OUTPUT_MODE_TEST
        eiint.eiint_ch = 135;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);
#endif
#if defined (TAUD0_INTERVAL_MODE_TEST) || defined (TAUD0_PWM_OUTPUT_MODE_TEST) || \
    defined(TAUD0_REAL_TIME_OUTPUT_TYPE_1_TEST) || defined(TAUD0_REAL_TIME_OUTPUT_TYPE_2_TEST)
        eiint.eiint_ch = 0;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);
#endif

#ifdef TAUD0_PWM_OUTPUT_MODE_TEST
        eiint.eiint_ch = 39;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);
#endif

#ifdef WDTA0_TEST //Make sure that the OPBT0 has been set before testing this funtion
	{
        WDTA_MODE_TypeDef wdta_mode;
        wdta_mode.inter_time = WDTA_OVF_LEVEL_7;
        wdta_mode.int_en = WDTA_INIT_ENABLE;
        wdta_mode.err_mode = WDTA_RESET_MODE;
        wdta_mode.ws = WDTA_WS_100_PERCENT;
        WDTA_Init(_WDTA0,&wdta_mode);
        WDTA_Start(_WDTA0);
	}

        eiint.eiint_ch = 32;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);
#endif

#ifdef WDTA1_TEST
	{
        WDTA_MODE_TypeDef wdta_mode;
        wdta_mode.inter_time = WDTA_OVF_LEVEL_7;
        wdta_mode.int_en = WDTA_INIT_ENABLE;
        wdta_mode.err_mode = WDTA_RESET_MODE;
        wdta_mode.ws = WDTA_WS_100_PERCENT;
        WDTA_Init(_WDTA1,&wdta_mode);
        WDTA_Start(_WDTA1);
	}

        eiint.eiint_ch = 33;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);
#endif
#ifdef RTCA0_TEST

    {
        RTCA_INIT_TypeDef rtca_init;
        rtca_init.time_cal.time.second = 0;
        rtca_init.time_cal.time.minute = 20;
        rtca_init.time_cal.time.hour = 10;

        rtca_init.time_cal.calendar.day = 12;
        rtca_init.time_cal.calendar.month =11;
        rtca_init.time_cal.calendar.year = 20;

        RTCA_Init(rtca_init);
    }

        eiint.eiint_ch = 201;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);

#endif
        //OSTM_Init();
        {
#ifdef TAUB0_INTERVAL_MODE_TEST
            TAUB_ChMode_TypeDef ch_mode;
            ch_mode.ch_no = 0;
            ch_mode.clk_sel = TAU_CK0;
            ch_mode.clk_div =10;// 2^10 = 1024 ==> PLCLK/1024 = 40M/1024
            ch_mode.cdr = 0x9896;//0x9896 ==> 39062==> 40M/39062 = 1024 = 2^10
            ch_mode.cnt_clk4cnt_counter = 0;
            ch_mode.mas = 1;
            ch_mode.sts = 0;
            ch_mode.cos = 0;
            ch_mode.md_un.md_bits.high7bit = 0;
            ch_mode.md_un.md_bits.low1bit = 0;
            TAUB_Independent_Init(&ch_mode);
#endif
#ifdef TAUB0_PWM_OUTPUT_MODE_TEST
        {
            TAUB_ChMode_TypeDef ch_mode[2];
            ch_mode[0].ch_no = 0;
            ch_mode[0].clk_sel = TAU_CK0;
            ch_mode[0].cnt_clk4cnt_counter = 0;
            ch_mode[0].clk_div = 4;// 2^4 = 16 ==> PLCLK/16 = 40M/16 = 2500K
            ch_mode[0].cdr = 2500 -1;//1ms
            ch_mode[0].mas = 1;
            ch_mode[0].sts = TAU_STS_SW_TRIG;
            ch_mode[0].cos = 0;
            ch_mode[0].md_un.md_bits.high7bit = TAUB_INTERVAL_MODE;
            ch_mode[0].md_un.md_bits.low1bit = 1;

            ch_mode[0].enable_sim_cfg = 1;//Enables simultaneous rewrite
            ch_mode[0].sim_cfg.ch_ctl = 0;
            ch_mode[0].sim_cfg.sig_gen = 0;
            ch_mode[0].sim_cfg.is_trig_ch = 0;

            ch_mode[0].ch_output_mode.taub_mode = TAUB_SYNCHRONOUS_OUTPUT_MODE_1;

            ch_mode[1] = ch_mode[0];//copy config from ch_mode[0]
            ch_mode[1].ch_no = 1;
            ch_mode[1].cdr = 1250;//1250/2500 = 50% duty cycle
            ch_mode[1].mas = 0;
            ch_mode[1].sts = TAU_STS_INT_TRIG_MASTER;
            ch_mode[1].md_un.md_bits.high7bit = TAUB_ONE_CNT_MODE;

            TAUB_Batch_Init(ch_mode,2);
        }
#endif
#ifdef TAUD0_INTERVAL_MODE_TEST
            TAUD_ChMode_TypeDef ch_mode;
            ch_mode.ch_no = 0;
            ch_mode.clk_sel = TAU_CK0;
            ch_mode.clk_div =10;// 2^10 = 1024 ==> PLCLK/1024 = 40M/1024
            ch_mode.cdr = 0x9896;//0x9896 ==> 39062==> 40M/39062 = 1024 = 2^10
            ch_mode.cnt_clk4cnt_counter = 0;
            ch_mode.mas = 1;
            ch_mode.sts = 0;
            ch_mode.cos = 0;
            ch_mode.md_un.md_bits.high7bit = 0;
            ch_mode.md_un.md_bits.low1bit = 0;
            TAUD_Independent_Init(&ch_mode);
#endif
#ifdef TAUD0_PWM_OUTPUT_MODE_TEST
        {
            TAUD_ChMode_TypeDef ch_mode[2];
            ch_mode[0].ch_no = 0;
            ch_mode[0].clk_sel = TAU_CK0;
            ch_mode[0].cnt_clk4cnt_counter = 0;
            ch_mode[0].clk_div = 4;// 2^4 = 16 ==> PLCLK/16 = 40M/16 = 2500K
            ch_mode[0].cdr = 2500 -1;//1ms
            ch_mode[0].mas = 1;
            ch_mode[0].sts = TAU_STS_SW_TRIG;
            ch_mode[0].cos = 0;
            ch_mode[0].md_un.md_bits.high7bit = TAUD_INTERVAL_MODE;
            ch_mode[0].md_un.md_bits.low1bit = 1;

            ch_mode[0].enable_sim_cfg = 1;//enables simultaneous rewrite
            ch_mode[0].sim_cfg.ch_ctl = 0;
            ch_mode[0].sim_cfg.sig_gen = 0;
            ch_mode[0].sim_cfg.is_trig_ch = 0;

            ch_mode[0].ch_output_mode.taub_mode = TAUD_SYNCHRONOUS_OUTPUT_MODE_1;

            ch_mode[1] = ch_mode[0];//copy config from ch_mode[0]
            ch_mode[1].ch_no = 1;
            ch_mode[1].cdr = 1250;//1250/2500 = 50% duty cycle
            ch_mode[1].mas = 0;
            ch_mode[1].sts = TAU_STS_INT_TRIG_MASTER;
            ch_mode[1].md_un.md_bits.high7bit = TAUD_ONE_CNT_MODE;
            TAUD_Batch_Init(ch_mode,2);
        }
#endif

#ifdef TAUD0_REAL_TIME_OUTPUT_TYPE_1_TEST
        {
            TAUD_ChMode_TypeDef ch_mode[2];
            ch_mode[0].ch_no = 0;
            ch_mode[0].clk_sel = TAU_CK0;
            ch_mode[0].cnt_clk4cnt_counter = 0;
            ch_mode[0].clk_div = 4;// 2^4 = 16 ==> PLCLK/16 = 40M/16 = 2500K
            ch_mode[0].cdr = 2500 -1;//1ms
            ch_mode[0].mas = 0;
            ch_mode[0].sts = TAU_STS_SW_TRIG;
            ch_mode[0].cos = 0;
            ch_mode[0].md_un.md_bits.high7bit = TAUD_INTERVAL_MODE;
            ch_mode[0].md_un.md_bits.low1bit = 1;

            ch_mode[0].enable_sim_cfg = 0;//diables simultaneous rewrite
            ch_mode[0].sim_cfg.ch_ctl = 0;
            ch_mode[0].sim_cfg.sig_gen = 0;
            ch_mode[0].sim_cfg.is_trig_ch = 0;

            ch_mode[0].ch_output_mode.taud_mode = TAUD_INDEPENDENT_OUTPUT_MODE_1_WITH_REAL_TIME;

            ch_mode[1] = ch_mode[0];//copy config from ch_mode[0]
            ch_mode[1].ch_no = 1;
            ch_mode[1].cdr = 1250;//1250/2500 = 50% duty cycle
            ch_mode[1].mas = 0;
            ch_mode[1].sts = TAU_STS_INT_TRIG_MASTER;
            ch_mode[1].md_un.md_bits.high7bit = TAUD_ONE_CNT_MODE;
            TAUD_Batch_Init(ch_mode,2);
        }
#endif

#ifdef TAUD0_REAL_TIME_OUTPUT_TYPE_2_TEST
        {
            TAUD_ChMode_TypeDef ch_mode[2];
            ch_mode[0].ch_no = 0;
            ch_mode[0].clk_sel = TAU_CK0;
            ch_mode[0].cnt_clk4cnt_counter = 0;
            ch_mode[0].clk_div = 4;// 2^4 = 16 ==> PLCLK/16 = 40M/16 = 2500K
            ch_mode[0].cdr = 2500 -1;//1ms
            ch_mode[0].mas = 0;
            ch_mode[0].sts = TAU_STS_EDGE_TIN_TRIG;
            ch_mode[0].cos = 0;
            ch_mode[0].md_un.md_bits.high7bit = TAUD_CAP_MODE;
            ch_mode[0].md_un.md_bits.low1bit = 1;
            ch_mode[0].tin_detect = TAU_TIS_RISE_EDGE;
            ch_mode[0].enable_sim_cfg = 0;//diables simultaneous rewrite

            ch_mode[0].ch_output_mode.taud_mode = TAUD_INDEPENDENT_OUTPUT_MODE_1_WITH_REAL_TIME;

            ch_mode[1] = ch_mode[0];//copy config from ch_mode[0]
            ch_mode[1].ch_no = 1;
            ch_mode[1].cdr = 1250;//1250/2500 = 50% duty cycle
            ch_mode[1].mas = 0;
            ch_mode[1].sts = TAU_STS_INT_TRIG_MASTER;
            ch_mode[1].md_un.md_bits.high7bit = TAUD_ONE_CNT_MODE;
            TAUD_Batch_Init(ch_mode,2);
        }
#endif
        }
    }

}
