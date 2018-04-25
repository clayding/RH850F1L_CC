#include "adc.h"

/*********************Only one of macro specified to be 1 as follows **********/
#define SOFTWARE_TRIGGER_TEST	0
#define HARDWARE_TRIGGER_TEST	0
#define ADCA0_HOLD_TRIGGER_TEST	1 //only support for ADCA0

void adc_init(void)
{
    ADCA_InitTypeDef adc;
    ADCA_SGOptTypeDef sgopt[3], *sg_opt_p = NULL;
    ADCA_VHSetTypeDef vhset[16], *vh_set_p = NULL;
    ADCA_THSetTypeDef thset;

    memset(&adc,0,sizeof(adc));
    memset(sgopt,0,sizeof(ADCA_SGOptTypeDef) * ARRAY_SIZE(sgopt));
    memset(vhset,0,sizeof(ADCA_VHSetTypeDef) * ARRAY_SIZE(vhset));
    memset(&thset,0,sizeof(ADCA_THSetTypeDef));

    adc.adcan = ADCA_0; //ADCA0
    {
        uint8_t i = 0;
        for(;i < 16;i++){
            vh_set_p = &vhset[i];
            vh_set_p->virtual_ch = i; //virtual channel 0-15
            vh_set_p->vh_set_un.param_bits.phy_ch = i;//physical channel 0-15
            vh_set_p->vh_set_un.param_bits.limit_sel = 0x01;//01: Upper limit and lower limit are checked for ADCAnULLMTBR0.
        }

        adc.vh_set_p = vhset;
        adc.vh_set_num = 16;//ANI000 to ANI015
    }

    adc.samp_time = 0x12;//12H: 18 cycles (ADCLK = 8 MHz to 32 MHz)

    adc.safe_ctl_un.param_bits.ow_int = 1; //enable A/D Error Interrupt (INT_ADE) on Overwrite Error Detection
    adc.safe_ctl_un.param_bits.ul_int = 1; //enable A/D Error Interrupt (INT_ADE) on Upper/Lower Limit Error Detection

    adc.limit[0].limit_un.param_bits.ulimit =  0x0FFF;
    adc.limit[0].limit_un.param_bits.llimit =  0x0;

#if ADCA0_HOLD_TRIGGER_TEST
    thset.auto_samp = 1;//Automatic sampling is performed.
    thset.grpa.reg_bits.SGS = 0x02;//10: SG2 is selected for T&H group A.
    thset.grpb.reg_bits.SGS = 0x01;//01: SG1 is selected for T&H group B.

    thset.en_mask = TH5_ENABLE_MASK | TH4_ENABLE_MASK | TH3_ENABLE_MASK | \
        TH2_ENABLE_MASK | TH1_ENABLE_MASK | TH0_ENABLE_MASK;
    thset.grp_sel_mask = TH5_SELECT_TO_B_MASK | TH4_SELECT_TO_B_MASK | TH3_SELECT_TO_B_MASK;

	adc.th_set_p = &thset;
#endif

    sg_opt_p = &sgopt[0];
    sg_opt_p->sg_index = 1;//SG1
    sg_opt_p->sg_ctl_un.sg_ctl = 0x11;//INT_SGx is output when the scan for SGx ends
    sg_opt_p->start_vhp = (uint32_t)0x00; //set ADCA0VCR00
    sg_opt_p->end_vhp = (uint32_t)0x04; //set ADCA0VCR04
    sg_opt_p->scan_times = (uint32_t)0x00; //Number of scans = 1
#if HARDWARE_TRIGGER_TEST
	sg_opt_p->hw_trig_ctl = HW_INTTAUD0I7_TRIG;//hardware triggered by INTTAUD0I7
#endif

    sg_opt_p = &sgopt[1];
    sg_opt_p->sg_index = 2;//SG2
    sg_opt_p->sg_ctl_un.sg_ctl = 0x11;//INT_SGx is output when the scan for SGx ends
    sg_opt_p->start_vhp = (uint32_t)0x05; //set ADCA0VCR05
    sg_opt_p->end_vhp = (uint32_t)0x0a; //set ADCA0VCR10
    sg_opt_p->scan_times = (uint32_t)0x00; //Number of scans = 1
#if HARDWARE_TRIGGER_TEST
	sg_opt_p->hw_trig_ctl = HW_INTTAUD0I7_TRIG;//hardware triggered by INTTAUD0I7
#endif

    sg_opt_p = &sgopt[2];
    sg_opt_p->sg_index = 3;//SG3
    sg_opt_p->sg_ctl_un.sg_ctl = 0x11;//INT_SGx is output when the scan for SGx ends
    sg_opt_p->start_vhp = (uint32_t)0x0b; //set ADCA0VCR11
    sg_opt_p->end_vhp = (uint32_t)0x0F; //set ADCA0VCR15
    sg_opt_p->scan_times = (uint32_t)0x00; //Number of scans = 1
#if HARDWARE_TRIGGER_TEST
	sg_opt_p->hw_trig_ctl = HW_INTTAUD0I7_TRIG;//hardware triggered by INTTAUD0I7
#endif

    adc.sg_opt_p = sgopt;
    adc.sg_opt_num = ARRAY_SIZE(sgopt);

    ADCA_Init(&adc);
}


void adca0_test(void)
{
    static uint8_t sg_index = ADCA_SG_INDEX_MIN,vh_num = 0;
    uint8_t phy_ch[ADCAn_PHY_CH_NUM_MAX] = {0};
    uint16_t conv_res[ADCAn_VIR_CH_NUM_MAX] = {0};

    for(;sg_index < (ADCA_SG_INDEX_MAX + 1);sg_index++){
        if(ADCA_Get_SG_Status(0,sg_index) == 1){
            uint8_t inc= 0,j = 0;
            inc = ADCA_Read_SG_Conv_Data(0,sg_index,&conv_res[vh_num],&phy_ch[vh_num]);
			for(;j < inc;j++){
            	printf("%d:%x ",phy_ch[vh_num+j],conv_res[vh_num+j]);
			}
			if(sg_index == ADCA_SG_INDEX_MAX)
				printf("\n\n");
            vh_num += inc;
            ADCA_Clear_SG_Status(0,sg_index);
#if !HARDWARE_TRIGGER_TEST  // repeat the trigger excluding the hardware trigger
			if(ADCA_Enable_Hold_Trigger(sg_index) == 0)
				ADCA_Enable_SW_Trigger(0,sg_index);//trigger repeatedly when software trigger enable
#endif
        }
    }
    if(sg_index == (ADCA_SG_INDEX_MAX + 1)) {
        sg_index = ADCA_SG_INDEX_MIN;
        vh_num = 0;
        memset(conv_res,0,ADCAn_VIR_CH_NUM_MAX);
        memset(phy_ch,0,ADCAn_PHY_CH_NUM_MAX);
    }
    {
        uint8_t err = 0;
        if(ADCA_Err_Checked(0,&err) > 0){
                ADCA_Err_Handle(0);
        }
    }
}
