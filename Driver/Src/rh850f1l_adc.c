/**
  ******************************************************************************
  * @file    rh850f1l_adc.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    12-April-2018
  * @brief   ADCA module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of ADCA peripheral:
  *           + Initialization and de-initialization functions
  *           + ADCA functions
  ******************************************************************************
  */
#include "rh850f1l_adc.h"

enum{
    ADCA_INDEX_0 = 0,
    ADCA_INDEX_1,
    ADCA_INDEX_TYPE_MAX,
};

enum{
    SG1_END_INT,SG2_END_INT,SG3_END_INT,
	SG_ERR_INT,SG_END_MAX,
};
//indicate the interruption state of SGx
static __IO uint8_t adca_scan_end_int[ADCA_INDEX_TYPE_MAX][SG_END_MAX] = {0};

static bool th_used = FALSE; //T&H set or unset

/**
  * @brief  Initializes the ADCAn peripheral according to the specified
  *   parameters in the ADCA_InitStruct.
  * @param  ADCA_InitStruct: pointer to a ADCA_InitTypeDef structure that
  *   contains the configuration information for the ADCAn peripheral.
  * @retval none
  */
void ADCA_Init(ADCA_InitTypeDef *ADCA_InitStruct)
{
    __IO uint8_t ADCAn = 0; //virtual channel num
    __IO uint8_t sg_opt_num = 0,sg_opt_cnt = 0;
    ADCA_InitTypeDef *p_init = NULL;

	/* Check the parameters */
	assert_param(IS_ALL_NULL(ADCA_InitStruct));
	assert_param(IS_ADCA_ALL_PERIPH(ADCA_InitStruct->adcan));

	p_init = ADCA_InitStruct;
    ADCAn = p_init->adcan;

    //Virtual channel setting
    //ADCA_Set_Virtual_Channel(ADCAn,vh,p_init->vh_set_un,p_init->limit,p_init->pwd_vh_used);
    ADCA_Set_Batch_Virtual_Channel(ADCAn,p_init->vh_set_p,p_init->vh_set_num,
        p_init->limit,p_init->pwd_vh_used);

    //Operation setting
    ADCA_Set_Operation_Ctl(ADCAn,p_init->opt_ctl_un,p_init->samp_time);
    //Error check
    ADCA_Set_Error_Check(ADCAn,p_init->safe_ctl_un,p_init->limit);
    //Self-diagnosis
	if(p_init->sd_ctl_p != NULL)
		ADCA_Set_Self_Diag(ADCAn,p_init->sd_ctl_p);
    //T&H  setting, T&H is used
    if(ADCAn == 0 && p_init->th_set_p !=  NULL)
        ADCA_Set_TH_Operation_Ctl(p_init->th_set_p);
    //SG1-3 operation and trigger enable,PWD trigger enable
    sg_opt_num = ADCA_InitStruct->sg_opt_num;
    for(;sg_opt_cnt < sg_opt_num;sg_opt_cnt++){
        ADCA_Set_SG_Operation(ADCAn,&p_init->sg_opt_p[sg_opt_cnt],p_init->pwd_vh_used);
	}
}
/**
  * @brief  Used to process the single virtual channel setting
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param vh_set_p the pointer to ADCA_VHSetTypeDef,pass the virtual channel setting
  * @param  limit_checked: set the checked flag when if upper limit and lower
  * limit are checked for ADCAnULLMTBRx[x=0 to 2]
  * @param pwd_used 0: self-diagnostic function disable , 1:  self-diagnostic function enable
  * @retval none
  */
void ADCA_Set_Virtual_Channel(uint8_t ADCAn,ADCA_VHSetTypeDef *vh_set_p,
	ADCA_ULLimitSetTypeDef *limit_checked,bool pwd_used)
{
    __IO uint32_t mask = 0;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(limit_checked));

    if(!pwd_used){
        mask = ADC_VCR_MPXE_MASK | ADC_VCR_MPXV_MASK | ADC_CNVCLS_MASK | ADC_VCR_ADIE_MASK | \
            ADC_ULS_MASK | ADC_GCTRL_MASK;

        __ADCA_SET_VC_CTL(ADCAn,vh_set_p->virtual_ch,mask,vh_set_p->vh_set_un.vhset);
    }else{
        uint8_t limit_tab_sel = vh_set_p->vh_set_un.vhset & ADC_ULS_MASK;
        /*if Upper limit and lower limit are checked for ADCAnULLMTBRx[x=0 to 2],
        then setting the checked flag in ADCA_ULLimitSetTypeDef to prevent Upper
        Limit/Lower Limit Table Registers x [x=0 to 2] forgetting to set later*/
        if(limit_tab_sel){
            uint8_t br_index = (limit_tab_sel >> ADC_ULS_OFFSET) & 0x03 - 1;
            limit_checked[br_index].checked = 1;
        }
        mask = ADC_VCR_MPXE_MASK | ADC_VCR_MPXV_MASK | ADC_ULS_MASK | ADC_GCTRL_MASK;
        __ADCA_SET_PWDVC_CTL(ADCAn,mask,vh_set_p->vh_set_un.vhset);
    }
}

/**
  * @brief  Used to process the multiple virtual channels setting
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param vh_set_p: the pointer to ADCA_VHSetTypeDef,pass the virtual channel setting
  * @param  limit_checked: set the checked flag when if upper limit and lower
  * limit are checked for ADCAnULLMTBRx[x=0 to 2]
  * @param pwd_used 0: self-diagnostic function disable , 1:  self-diagnostic function enable
  * @retval none
  */
void ADCA_Set_Batch_Virtual_Channel(uint8_t ADCAn,ADCA_VHSetTypeDef *vh_set_p,uint8_t vh_set_num,
    ADCA_ULLimitSetTypeDef *limit_checked,bool pwd_used)
{
	uint8_t ch_index = 0;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(limit_checked));

	for(;ch_index < vh_set_num;ch_index++){
		ADCA_Set_Virtual_Channel(ADCAn,&vh_set_p[ch_index],limit_checked,pwd_used);
	}
}

/**
  * @brief  Used to process ADC common operation control setting and sampling control setting
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param ctl_un: the union of adc common setting
  * @param samp_time: used to set the sampling time (the number of cycles).
  * @retval none
  */
void ADCA_Set_Operation_Ctl(uint8_t ADCAn, ADCA_OptCtlUnion ctl_un,uint8_t samp_time)
{
    uint32_t mask = 0,val = 0;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));

    mask = ADC_DGON_MASK | ADC_CRAC_MASK | ADC_CTYP_MASK | ADC_SUSMTD_MASK;
    val = ctl_un.opctl;

    //ADC common operation control setting
    __ADCA_SET_COMMON_CTL(ADCAn,mask,val);

    //the samp_time must be 12H or 18H,settings other than above are prohibited
    assert_param(IS_SAMPLING_TIME(samp_time));
    //Sampling control setting
    __ADCA_SET_SAMPLING_TIME(ADCAn,samp_time);
}

/**
  * @brief  used to process error control setting and upper limit/lower limit setting
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param ctl_un: the union of error control setting related to safety control
  * @param limit_p: the pointer to ADCA_ULLimitSetTypeDef,set the threshold for
  * detection of an upper limit or lower limit error in the A/D converted value
  * @retval none
  */
void ADCA_Set_Error_Check(uint8_t ADCAn,ADCA_SafeCtlUnion ctl_un,ADCA_ULLimitSetTypeDef *limit_p)
{
    uint32_t mask = 0,val = 0;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));

    mask = ADC_RDCLRE_MASK | ADC_ULEIE_MASK | ADC_OWEIE_MASK;
    val = ctl_un.safectl;

    //Error control setting
    __ADCA_SET_SAFETY_CTL(ADCAn,mask,val);

    //Upper limit/lower limit setting(for detection of upper limit/lower limit errors)
    if(limit_p != NULL){
        uint8_t br_index = 0;
        for(;br_index < 3;br_index++){
            if(limit_p[br_index].checked && limit_p[br_index].limit_un.limit_tab == 0){
                WARNING("Upper limit and lower limit are checked for ADCAnULLMTBR%d , \
                but the limit table registers %d not be set in corrrect way\n",br_index,br_index);
            }
            if(limit_p[br_index].limit_un.limit_tab != 0){
                __ADCA_SET_LIMIT_TAB(ADCAn,br_index,limit_p[br_index].limit_un.limit_tab);
            }
        }
    }
}

/**
  * @brief  used to process self-diagnostic voltage level setting amd control setting
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param ctl_p: the pointer to ADCA_SDCtlTypeDef,controls the self-diagnostic voltage level
  * and the self-diagnostic channel.
  * @retval none
  */
void ADCA_Set_Self_Diag(uint8_t ADCAn,ADCA_SDCtlTypeDef *ctl_p)
{
    /* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(ctl_p));

    /*Self-diagnostic voltage level setting (when the self-diagnostic function is used)*/
    __ADCA_SELECT_Self_Diag_VOLT_LEVEL(ADCAn,ctl_p->sd_volt_level);

    /*Self-diagnostic control setting (when the self-diagnostic function is used)*/
    __ADCA_SELECT_Self_Diag_CHANNEL(ADCAn,ctl_p->sd_ch_select);
}

/**
  * @brief  used to process T&H common operation control setting,T&H group A/B operation
  * only ADCA0 supports this function.
  * control setting,T&H group selection setting and T&H enable setting.
  * @param set_p: the pointer to ADCA_THSetTypeDef.
  * @retval none
  */
void ADCA_Set_TH_Operation_Ctl(ADCA_THSetTypeDef *set_p)
{
    uint32_t mask = 0;
    ADCA_THGrpOptCtlUnion ctl_un;

	/* Check the parameters */
	assert_param(IS_ALL_NULL(set_p));

    th_used =  TRUE; // T&H set
    //T&H common operation control setting (when T&H is used)
    __ADCA_SET_AUTO_SAMPLING(set_p->auto_samp);

    mask = ADC_HLDCTE_MASK | ADC_HLDTE_MASK | ADC_SGS_MASK;
    //T&H group A operation control setting (when T&H is used)
    //T&H group B operation control setting (when T&H is used)
    ctl_un = set_p->grpa;
    __ADCA_SET_THA_CTL(mask,ctl_un.grp_ctl);

    ctl_un = set_p->grpb;
    __ADCA_SET_THB_CTL(mask,ctl_un.grp_ctl);

    //T&H enable setting (when T&H is used)
    __ADCA_TH_ENABLE(set_p->en_mask);
    //T&H group selection setting (when T&H is used)
    __ADCA_TH_SELECT(set_p->grp_sel_mask);

}

/**
  * @brief  used to process control setting,start/end virtual channel pointer setting
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * and multicycle count setting for the scan groups (SG1 to SG3).
  * @param opt_p: the pointer to ADCA_SGOptTypeDef.
  * @param pwd_used 0: self-diagnostic function disable , 1:  self-diagnostic function enable
  * @retval none
  */
void ADCA_Set_SG_Operation(uint8_t ADCAn,ADCA_SGOptTypeDef *opt_p,bool pwd_used)
{
    uint32_t mask = 0;
    ADCA_SGCtlUnion ctl_un;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(opt_p));

    ctl_un = opt_p->sg_ctl_un;

    mask = ADC_SCANMD_MASK | ADC_SGCRx_ADIE_MASK | ADC_SCT_MASK;

    //set the control register,note that SCANMD should be set 0 for SG2 and SG3
    if(opt_p->sg_index ==  ADCA_SG_INDEX_2 || opt_p->sg_index == ADCA_SG_INDEX_3)
        ctl_un.reg_bits.SCANMD = 0;
    __ADCA_SET_SGx_CTL(ADCAn,opt_p->sg_index,mask,ctl_un.sg_ctl);
    //Start virtual channel pointer setting for the scan groups (SG1 to SG3)
    __ADCA_SET_START_POINTER(ADCAn,opt_p->sg_index,opt_p->start_vhp);
    //End virtual channel pointer setting for the scan groups (SG1 to SG3)
    __ADCA_SET_END_POINTER(ADCAn,opt_p->sg_index,opt_p->end_vhp);
    //Multicycle count setting for the scan groups (SG1 to SG3)
    __ADCA_SET_SCAN_TIME(ADCAn,opt_p->sg_index,opt_p->scan_times);

    /*Set TRGMD of ADCAnSGCR1 to ADCAnSGCR3,Set scan group trigger enable
    (SG1 to SG3)*/
    ctl_un.reg_bits.TRGMD = 1;
    mask = ADC_TRGMD_MASK;
    __ADCA_SET_SGx_CTL(ADCAn,opt_p->sg_index,mask,ctl_un.sg_ctl);

	ADCA_Set_SG_Start_Trigger(ADCAn,opt_p->sg_index,opt_p->hw_trig_ctl);
}

/**
  * @brief  used to enable the software trigger for Scan Groups SG1 to SG3.
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param sg_index: the index of Scan Groups.(sg_index: 1 to 3)
  * @retval none
  */
void ADCA_Enable_SW_Trigger(uint8_t ADCAn,uint8_t sg_index)
{
	uint32_t sg_act = 0;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ADCA_SG_INDEX(sg_index));

    //get the state of SGx(x = 1 to 3)
    sg_act = __ADCA_GET_SG_STAT(ADCAn,0x01 << (ADC_SG1_STAT_OFFSET + sg_index - 1));
    if(!sg_act) //A/D conversion for SGx is completed.
        __ADCA_START_SGx(ADCAn,sg_index); //Start the SGx
}

/**
  * @brief  used to enable the hold trigger for T&H group A and B,only ADCA0
  * supports this function.
  * @param sg_index: the index of Scan Groups.(sg_index: 1 to 3)
  * @retval 0:SGx(x=1-3) selected to group A or B is not enable in hold trigger
  *  1: SGx(x=1-3) selected to group A or B enabled in hold trigger
  */
uint8_t ADCA_Enable_Hold_Trigger(uint8_t sg_index)
{
	/* Check the parameters */
	assert_param(IS_ADCA_SG_INDEX(sg_index));

    //ADCAnTHACR.HLDTE? ADCAnTHBCR.HLDTE?
	//The SGx (x = 1 to 3) trigger selected in SGS[1:0] is selected for the hold
	//start trigger of T&H group A.
    if(__ADCA_GET_THA_CTL_(ADC_HLDTE_MASK) == 0 &&
		__ADCA_GET_THA_CTL_(ADC_SGS_MASK) == sg_index){
		INFOR("Hold start trigger A,SG%d start trigger\n",sg_index);
		__ADCA_START_THA_HOLD();
		return 1;//SGx(x=1-3) selected to group A enabled in hold trigger
	}
	//The SGx (x = 1 to 3) trigger selected in SGS[1:0] is selected for the hold
	//start trigger of T&H group B.
	if(__ADCA_GET_THB_CTL_(ADC_HLDTE_MASK) == 0 &&
		__ADCA_GET_THB_CTL_(ADC_SGS_MASK) == sg_index){
		INFOR("Hold start trigger B,SG%d start trigger\n",sg_index);
    	__ADCA_START_THB_HOLD();
		return 1;//SGx(x=1-3) selected to group B enabled in hold trigger
	}

	return 0; //SGx(x=1-3) selected to group A/B is not enable in hold trigger
}

/**
  * @brief used to start SGx trigger by software or hardware or hold trigger
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param sg_index: the index of Scan Groups.(sg_index: 1 to 3)
  * @param trig_ctl:the hardware trigger input signal type.If hardware trigger
  * disabled,the value of this param is 0.
  * @retval none
  */
void ADCA_Set_SG_Start_Trigger(uint8_t ADCAn,uint8_t sg_index,uint32_t trig_ctl)
{
	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ADCA_SG_INDEX(sg_index));

    if(ADCAn == ADCA_0 && th_used){
        __ADCA_START_TH_SAMPLING(); //T&H sampling start control trigger

		if(ADCA_Enable_Hold_Trigger(sg_index))
			return;// if SGx(x=1-3) selected to group A/B enabled in hold trigger,return
    }

    if(trig_ctl){ //hardware trigger first
		INFOR("Hardware start trigger,SG%d start trigger\n",sg_index);
        __ADCA_ENABLE_HW_TRIGGER(ADCAn,sg_index,trig_ctl);
    }else{
		INFOR("Software start trigger,SG%d start trigger\n",sg_index);
      	ADCA_Enable_SW_Trigger(ADCAn,sg_index);
    }
}

/**
  * @brief used to end A/D conversion
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param sg_index: the index of Scan Groups.(sg_index: 1 to 3)
  * @param halt: force halt flag.
  * @retval none
  */
void ADCA_Set_Conv_End(uint8_t ADCAn,uint8_t sg_index,bool halt)
{
    bool halt_first = FALSE;
    uint32_t sg_ctl = 0,mask = 0;

    /* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ADCA_SG_INDEX(sg_index));

	mask = ADC_SCANMD_MASK | ADC_SGCRx_ADIE_MASK | ADC_SCT_MASK |
		ADC_TRGMD_MASK;
    sg_ctl = __ADCA_GET_SGx_CTL(ADCAn,sg_index,mask);

    //When the hardware trigger is used,ADCAnSGCRx.TRGMD = 0
    //ADCAnPWDSGCR.PWDTRGMD = 0
    if(__ADCA_GET_HW_TRIGGER_STAT(ADCAn,sg_index))
        __ADCA_SET_SGx_CTL(ADCAn,sg_index,ADC_TRGMD_MASK,0);

    if((sg_ctl & ADC_SCANMD_MASK) || halt){
        halt_first = TRUE;
    }
    if(halt_first){
        __ADCA_FORCE_HALT_TRIGGER(ADCAn);//ADCAnADHALTR.HALT = 1
    }

    //Wait for ADCAnSGSTR.SGACT[5:1] = “00000
    while(__ADCA_GET_SG_STAT(ADCAn,0x1F << ADC_SG1_STAT_OFFSET));

    if(!halt_first){
        __ADCA_FORCE_HALT_TRIGGER(ADCAn);//ADCAnADHALTR.HALT = 1
    }
}

/**
  * @brief used to read the A/D conversion result for ADCAnDRj and information
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * incidental to the A/D converted value corresponding to the virtual channel.
  * @param virtual_ch: the virtual channel index
  * @param data_p: the data array to store the A/D conversion result.
  * @retval phy_ch: physical channel number corresponding to the most recent
  * conversion result
  */
int8_t ADCA_Read_Conv_Data(uint8_t ADCAn, uint8_t virtual_ch,uint16_t *data_p)
{
    __IO uint32_t format = 0,reg = 0,mask = 0;
    __IO uint8_t phy_ch = 0;
	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(data_p));

    format = __ADCA_GET_COMMON_CTL(ADCAn,ADC_CRAC_MASK | ADC_CTYP_MASK);
    format = format >> ADC_CTYP_OFFSET;

    mask = ADC_WFLG_MASK | ADC_ID_MASK | ADC_DR_MASK;
    if(ADCAn == 0) //ADC0
        mask |= ADC_DIR_MPXE_MASK | ADC_DIR_MPVR_MASK;

    reg = __ADCA_READ_DATA_INFO(adcn,virtual_ch,mask);
    /*get the physical channel number to be stored is the number corresponding
    to the most recent conversion result*/
    phy_ch = (reg & ADC_ID_MASK) >> ADC_ID_OFFSET;

    //check the alignment of data and extract
    if(format == RIGHT_ALIGN_12BIT_FMT){
        *data_p = reg & 0xFFF;
    }else if(format == LEFT_ALIGN_12BIT_FMT){
        *data_p = (reg >> 4) & 0xFFF;
    }else if(format == RIGHT_ALIGN_10BIT_FMT){
        *data_p = reg & 0x3FF;
    }else{ //data_format == LEFT_ALIGN_10BIT_FMT
        *data_p = (reg >> 6) & 0x3FF;
    }

    return phy_ch;//return the physical channel
}

/**
  * @brief used to read the A/D conversion result for ADCAnDRj and information
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * incidental to the A/D converted value corresponding to all the virtual channels
  * in the SGx.
  * @param virtual_ch: the virtual channel index
  * @param data_p: the data array to store the A/D conversion result.
  * @param phy_ch_p: the pointer to physical channel number corresponding to the most recent
  * conversion result
  * @retval vh_num: return the number of virtual channels got the A/D conversion result.
  */
int8_t ADCA_Read_SG_Conv_Data(uint8_t ADCAn,uint8_t sg_index,uint16_t *data_p,
    uint8_t *phy_ch_p)
{
	__IO uint8_t ch_sptr = 0,ch_eptr = 0,vh_num = 0;

	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(data_p));
	assert_param(IS_ALL_NULL(phy_ch_p));

    ch_sptr = __ADCA_GET_START_POINTER(ADCAn,sg_index);
    ch_eptr = __ADCA_GET_END_POINTER(ADCAn,sg_index);

    if(ch_eptr < ch_sptr){
        ERROR("start pointer must be equal or smaller than end pointer\n");
        return -1;
    }
    for(;ch_sptr <= ch_eptr;ch_sptr++){
        phy_ch_p[vh_num] = ADCA_Read_Conv_Data(ADCAn,ch_sptr,&data_p[vh_num]);
        vh_num++;
    }
    //return the number of virtual channel specified in SGx(x = sg_index, 1 to 3)
    return vh_num;
}

/**
  * @brief used to get the state of SGx (x = 1 to 3)
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param sg_index: the index of Scan Groups.(sg_index: 1 to 3)
  * @retval 1:A/D conversion for SGx is completed and interruption occurred
  * 0:A/D conversion for SGx is not completed or interruption never occurred.
  */
int8_t ADCA_Get_SG_Status(uint8_t ADCAn,uint8_t sg_index)
{
    __IO uint32_t sg_act = 0;
    /* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ADCA_SG_INDEX(sg_index));
    sg_act = __ADCA_GET_SG_STAT(ADCAn,0x01 << (ADC_SG1_STAT_OFFSET + sg_index - 1));
    if(!sg_act && adca_scan_end_int[ADCAn][sg_index - 1])
        return 1;//A/D conversion for SGx is completed and interruption occurred.
    return 0;
}

/**
  * @brief used to clear the state of SGx (x = 1 to 3)
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param sg_index: the index of Scan Groups.(sg_index: 1 to 3)
  * @retval none
  */
void ADCA_Clear_SG_Status(uint8_t ADCAn,uint8_t sg_index)
{
    /* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ADCA_SG_INDEX(sg_index));

    adca_scan_end_int[ADCAn][sg_index - 1] = 0;
}

/**
  * @brief the handle function of error
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @retval none
  */
void ADCA_Err_Handle(uint8_t ADCAn)
{
	/* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));

    //Clear all errors
    __ADCA_CLEAR_ERROR(ADCAn,ADC_ULEC_MASK | ADC_OWEC_MASK);
}

/**
  * @brief used to check the error type.
  * @param ADCAn: the unit of ADCA,0 or 1 optional
  * @param src_err_p: unused
  * @retval err_mask: return the error type mask.this parameter can be a value or
  * combinatiuon of @ref err_type
  */
int8_t ADCA_Err_Checked(uint8_t ADCAn,uint8_t *src_err_p)
{
    __IO uint32_t reg = 0;
	int8_t err_mask = 0;

    /* Check the parameters */
	assert_param(IS_ADCA_ALL_PERIPH(ADCAn));
	assert_param(IS_ALL_NULL(src_err_p));

    if(adca_scan_end_int[ADCAn][SG_ERR_INT]){
        reg = __ADCA_GET_OVERWRITE_ERR(ADCAn,ADC_OWE_MASK | ADC_OWECAP_MASK);
        if(reg & ADC_OWE_MASK){
            err_mask |= ADCA_OVERWRITE_ERR;
            INFOR("ADCA%d overwrite err in phy channel %d \n",ADCAn,reg & ADC_OWECAP_MASK);
        }
        reg = __ADCA_GET_ULLIMIT_ERR_INFO(ADCAn,ADC_UE_MASK | ADC_LE_MASK | ADC_ULSG_MASK | \
			ADC_MPXE_MASK | ADC_MPXV_MASK | ADC_ULECAP_MASK);
        if(reg & (ADC_UE_MASK | ADC_LE_MASK)){
            err_mask |= (reg & (ADC_UE_MASK | ADC_LE_MASK)) >> ADC_LE_OFFSET;
            INFOR("ADCA%d limit err in %s phy ch:%d\n",ADCAn,
                (reg & ADC_ULSG_MASK) == 0 ?"PWD":"SGx",reg & ADC_ULECAP_MASK);
        }
    }
    return err_mask;
}

//ADCA0 Scan group 1 (SG1) end interrupt
#pragma interrupt ADCA0SG1EndIntHandler(channel = 10, enable = false, callt = false, fpu = false)
void ADCA0SG1EndIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_0][SG1_END_INT] = 1;
}

//ADCA0 Scan group 2 (SG2) end interrupt
#pragma interrupt ADCA0SG2EndIntHandler(channel = 11, enable = false, callt = false, fpu = false)
void ADCA0SG2EndIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_0][SG2_END_INT] = 1;
}

//ADCA0 Scan group 3 (SG3) end interrupt
#pragma interrupt ADCA0SG3EndIntHandler(channel = 12, enable = false, callt = false, fpu = false)
void ADCA0SG3EndIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_0][SG3_END_INT] = 1;
}

//ADCA0 A/D error interrupt
#pragma interrupt ADCA0ADEIntHandler(channel = 47, enable = false, callt = false, fpu = false)
void ADCA0ADEIntHandler(unsigned long eiic)
{
   adca_scan_end_int[ADCA_INDEX_0][SG_ERR_INT] = 1;
}


//ADCA1 Scan group 1 (SG1) end interrupt
#pragma interrupt ADCA1SG1EndIntHandler(channel = 205, enable = false, callt = false, fpu = false)
void ADCA1SG1EndIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_1][SG1_END_INT] = 1;
}

//ADCA1 Scan group 2 (SG2) end interrupt
#pragma interrupt ADCA1SG2EndIntHandler(channel = 206, enable = false, callt = false, fpu = false)
void ADCA1SG2EndIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_1][SG2_END_INT] = 1;
}

//ADCA1 Scan group 3 (SG3) end interrupt
#pragma interrupt ADCA1SG3EndIntHandler(channel = 207, enable = false, callt = false, fpu = false)
void ADCA1SG3EndIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_1][SG3_END_INT] = 1;
}

//ADCA1 A/D error interrupt
#pragma interrupt ADCA1ADEIntHandler(channel = 204, enable = false, callt = false, fpu = false)
void ADCA1ADEIntHandler(unsigned long eiic)
{
    adca_scan_end_int[ADCA_INDEX_1][SG_ERR_INT] = 1;
}
