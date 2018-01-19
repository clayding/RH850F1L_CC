/**
  ******************************************************************************
  * @file    rh850f1l_wdta.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   15-January-2018
  * @brief   Window Watchdog Timer module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Window Watchdog Time peripheral:
  *           + Initialization and de-initialization functions
  *           + Window Watchdog Timer functions
  ******************************************************************************
  */
#include "rh850f1l_wdta.h"

#define WDTAn_PARAM(_UNIT_) if(_UNIT_ == _WDTA0) \
                                wdta_param = &_WDTA0_param; \
                            else  \
                                wdta_param = &_WDTA1_param;

static struct WDTA_param *wdta_param  = NULL;
static struct WDTA_param _WDTA0_param,_WDTA1_param;

void WDTA_Get_OPB(void)
{
    //TODO
    /*Flash Option BA3FFFCF  -- WDTA0 bits
    1011  1010  0 1 0 1  1 1 1 1 1111 1111 1100 1111
                 |    |  | \ | /
               VAC   |  EN [18:16] ---overflow interval time
                  soft or default
    BABFFFCF ---- WDTA1 bits
    1011  1 0 1 0  1 1 0 1  1 1 1 1 1111 1111 1100 1111
            | |   |          \ | /
          VAC |   EN          [18:16] ---overflow interval time
           soft or default

    if bit[20] WDTA0 is enabled
    if bit[22] == 1 then is_vac_enabled = 1; otherwise is_vac_enabled = 0;
    if bit[20] == 1 then software trigger start mode ,otherwise default start

    if bit[23] WDTA1 is enabled
    if bit[26] == 1 then is_vac_enabled = 1; otherwise is_vac_enabled = 0;
    if bit[24] == 1 then then software trigger start mode ,otherwise default start
    */
}

/**
  * @brief This function called to init all necessary paramters including setting the WDTA
  *        mode register before the timer starts
  * @param  unit- _WDTA0 or _WDTA1 ,select which timer chossen to be initialized.
  * @param mode the pointer to WDTA_MODE_TypeDef, just set the struct before set
  */
void WDTA_Init(WDTA_UNIT_Type unit, WDTA_MODE_TypeDef *mode)
{
    WDTAn_PARAM(unit);

    wdta_param->expect_tm =  0xAC;

    WDTA_Mode_Config(unit,mode);

    //WDTA_Get_OPB()  // read the start-up option from the flash
    wdta_param->is_vac_enabled = 1;
    if(wdta_param->is_vac_enabled){

        wdta_param->ref_val =__GET_WDTA_REFER_VALUE(unit);

        wdta_param->expect_tm -= wdta_param->ref_val;
        wdta_param->next_ref_value = ROTATE_LEFT(wdta_param->expect_tm,8,1);
    }

}
/**
  * @brief This function called to start the timer
  * @param  unit- _WDTA0 or _WDTA1 ,select which timer chossen to be initialized.
  */
void WDTA_Start(WDTA_UNIT_Type unit)
{
    WDTAn_PARAM(unit);

    if(!wdta_param->is_vac_enabled){
    	__ENABLE_WDTA(unit);
    }else{
    	__ENABLE_WDTA_VAC(unit, wdta_param->expect_tm);
    }
}

/**
  * @brief This function called to  the WDTA mode register before the timer starts
  * @param  unit- _WDTA0 or _WDTA1 ,select which timer chossen to be initialized.
  * @param mode the pointer to WDTA_MODE_TypeDef, just set the struct before set
  */
void WDTA_Mode_Config(WDTA_UNIT_Type unit, WDTA_MODE_TypeDef *mode)
{
    __IO uint8_t set_mode = 0;
    set_mode = (mode->inter_time << 4) | (mode->int_en << 3) | (mode->err_mode << 2) |(mode->ws);
    __SET_WDTA_MODE(unit, set_mode);
}

/**
  * @brief This function called to restart the timer
  * @param  unit- _WDTA0 or _WDTA1 ,select which timer chossen to be initialized.
  */
void WDTA_Reload(WDTA_UNIT_Type unit)
{
    WDTAn_PARAM(unit);

    wdta_param->expect_tm = 0xAC;

    if(!wdta_param->is_vac_enabled){
        __ENABLE_WDTA(unit);
    }else{
        wdta_param->expect_tm -= wdta_param->next_ref_value;
        wdta_param->next_ref_value = ROTATE_LEFT(wdta_param->expect_tm,8,1);
        __ENABLE_WDTA_VAC(unit, wdta_param->expect_tm);
    }
}
