/**
  ******************************************************************************
  * @file    rh850f1l_csi.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   28-March-2018
  * @brief   CSIG module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of CSIG peripheral:
  *           + Initialization and de-initialization functions
  *           + CSIG functions
  ******************************************************************************
  */
#include "rh850f1l_csi.h"

enum{
    CSIG_INDEX_0 = 0,
    CSIG_INDEX_1,
    CSIG_INDEX_TYPE_MAX,
};

enum {
    CSI_TRANSMISSION = 0,
	CSI_RECEPTION,
	CSI_RECEPTION_FLAG,
	CSI_TYPE_MAX,
};

static uint8_t csig_transfer_stat[CSIG_INDEX_TYPE_MAX][CSI_TYPE_MAX] = {0};

void CSIG_Init(CSIG_InitTypeDef *CSIG_InitStruct)
{
    __IO uint32_t mask = 0,val = 0;

    /*----------------------- CSIGx CTL1  Configuration ----------------------*/
    val = CSIG_InitStruct->cpol | CSIG_InitStruct->nss | 0x02;
	if(CSIG_InitStruct->mode != CSI_MODE_MASTER)
		val |=  (0x01 << CSI_CSIGnSLIT_OFFSET);
    mask = CSI_CSIGnCKR_MASK | CSI_CSIGnSSE_MASK | CSI_CSIGnHSE_MASK |CSI_CSIGnSLIT_MASK;
    __CSIG_SET_CTL1(CSIG_InitStruct->csign,mask,val);

    /*----------------------- CSIGx CTL2  Configuration ----------------------*/
    if(CSIG_InitStruct->mode == CSI_MODE_MASTER){
        val = (uint16_t)(CSIG_InitStruct->prescaler | CSIG_InitStruct->clk_fre);
    }else{
        val = 0x7 << CSI_CSIGnPRS_OFFSET;
    }
    mask = CSI_CSIGnPRS_MASK | CSI_CSIGnBRS_MASK;
    __CSIG_SET_CTL2(CSIG_InitStruct->csign,mask,val);

    /*----------------------- CSIGx CFG0  Configuration ----------------------*/
    val = CSIG_InitStruct->data_size | CSIG_InitStruct->first_bit |
        CSIG_InitStruct->cpha;
    mask = CSI_CSIGnDLS_MASK | CSI_CSIGnDIR_MASK | CSI_CSIGnDAP_MASK;

   	__CSIG_SET_CFG0(CSIG_InitStruct->csign,mask,val);
	
	/*Note:Trigger the reception when master set in receive mode*/
	if(CSIG_InitStruct->mode != CSI_MODE_MASTER || CSIG_InitStruct->transfer_mode != CSI_RECEIVE_ONLY)
    	__CSIG_ENABLE_NEXT_RECEPT(CSIG_InitStruct->csign,0);

    /*----------------------- CSIGx CTL0 Configuration -----------------------*/
    val = CSIG_InitStruct->transfer_mode |(0x01 << CSI_CSIGnPWR_OFFSET) | 0x01;
    mask = CSI_CSIGnPWR_MASK | CSI_CSIGnTXE_MASK | CSI_CSIGnTXE_MASK | CSI_CSIGnMBS_MASK;
    __CSIG_SET_CTL0(CSIG_InitStruct->csign,mask,val);

}


/**
  * @brief  Transmits a Data through the CSI peripheral.
  * @param  CSIGn: where x can be 0 or 1
  * @param  data : data to be transmitted.
  * @retval None
  */
void CSIG_SendData(uint8_t CSIGn, uint16_t data)
{
    /* Write in the CSIGnTX0H register the data to be sent */
    __CSIG_WRITE_DATA(CSIGn,data);
}

/**
  * @brief  Returns the most recent received data by the CSI peripheral.
  * @param  CSIGn: where x can be 0 or 1
  * @retval The value of the received data.
  */
uint16_t CSIG_ReceiveData(uint8_t CSIGn)
{
  /* Return the data in the DR register */
  return  __CSIG_READ_DATA(CSIGn);
}


int8_t CSIG_Get_Status(uint8_t CSIGn,uint8_t direction)
{
    if(CSIGn > 1){
        ERROR("CSIG%d not supported!\n",CSIGn);
        return -1;
    }
    return csig_transfer_stat[CSIGn][direction];
}

void CSIG_Clear_Status(uint8_t CSIGn,uint8_t direction)
{
    if(CSIGn > 1){
        ERROR("CSIG%d not supported!\n",CSIGn);
        return;
    }
    csig_transfer_stat[CSIGn][direction] = 0;
}


#pragma interrupt CSIG0ComStatusIntHandler(channel = 19, enable = false, callt = false, fpu = false)
void CSIG0ComStatusIntHandler(unsigned long eiic)
{
	csig_transfer_stat[CSIG_INDEX_0][CSI_TRANSMISSION] = 1;
}

#pragma interrupt CSIG0RecvIntHandler(channel = 20, enable = false, callt = false, fpu = false)
void CSIG0RecvIntHandler(unsigned long eiic)
{
    csig_transfer_stat[CSIG_INDEX_0][CSI_RECEPTION] = 1;
}

#pragma interrupt CSIG0ComErrorIntHandler(channel = 49, enable = false, callt = false, fpu = false)
void CSIG0ComErrorIntHandler(unsigned long eiic)
{
    while(1);
}

#pragma interrupt CSIG1ComStatusIntHandler(channel = 215, enable = false, callt = false, fpu = false)
void CSIG1ComStatusIntHandler(unsigned long eiic)
{
	csig_transfer_stat[CSIG_INDEX_1][CSI_TRANSMISSION] = 1;
}

#pragma interrupt CSIG1RecvIntHandler(channel = 216, enable = false, callt = false, fpu = false)
void CSIG1RecvIntHandler(unsigned long eiic)
{
    csig_transfer_stat[CSIG_INDEX_1][CSI_RECEPTION] = 1;
}

#pragma interrupt CSIG1ComErrorIntHandler(channel = 217, enable = false, callt = false, fpu = false)
void CSIG1ComErrorIntHandler(unsigned long eiic)
{
    while(1);
}
