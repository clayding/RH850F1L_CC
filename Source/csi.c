#include "csi.h"


void csi_init(void)
{
    CSIG_InitTypeDef csig_init;

    memset(&csig_init,0,sizeof(csig_init));

    csig_init.csign = 0;
    csig_init.mode = CSI_MODE_MASTER;
    csig_init.transfer_mode =CSI_TRANSMIT_RECEIVE;
    csig_init.data_size = CSI_DATASIZE_8b;
    csig_init.cpol = CSI_CPOL_HIGH;
    csig_init.cpha = CSI_CPHA_1Edge;
    csig_init.nss = CSI_NSS_Soft;
    csig_init.prescaler = CSI_BaudRatePrescaler_4;
    csig_init.clk_fre = 2;
    csig_init.first_bit = 0;

	CSIG_Init(&csig_init);
}

void csi_master_excute(void)
{
    __IO uint8_t resp_data[10] = "abcdefg";
    __IO uint8_t len = 7;

    while(len--)
        CSIG_SendData(0,resp_data[len]);
}

void csi_slave_excute(void)
{
    uint16_t recv_data = 0;

    if(CSIG_Get_Recv_Status(0)){
        recv_data = CSIG_ReceiveData(0);
        INFOR("Recv data:%c\n",recv_data);
    }
}
