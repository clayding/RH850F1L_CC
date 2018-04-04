#include "csi.h"

#define MATSER_SENT_TEST 0

void csi_init(void)
{
    CSIG_InitTypeDef csig_init;
    memset(&csig_init,0,sizeof(csig_init));
#if MATSER_SENT_TEST
    csig_init.csign = 0;
    csig_init.mode = CSI_MODE_MASTER;
    csig_init.transfer_mode =CSI_TRANSMIT_ONLY;
    csig_init.data_size = CSI_DATASIZE_16b;
    csig_init.cpol = CSI_CPOL_HIGH;
    csig_init.cpha = CSI_CPHA_2Edge;
    csig_init.nss = CSI_NSS_Hard;
    csig_init.prescaler = CSI_BaudRatePrescaler_1;
    csig_init.clk_fre = 4;
    csig_init.first_bit = 0;

	CSIG_Init(&csig_init);

    csig_init.csign = 1;
    csig_init.mode = CSI_MODE_SLAVE;
    csig_init.transfer_mode =CSI_RECEIVE_ONLY;
    csig_init.data_size = CSI_DATASIZE_16b;
    csig_init.cpol = CSI_CPOL_HIGH;
    csig_init.cpha = CSI_CPHA_2Edge;
    csig_init.nss = CSI_NSS_Hard;
    csig_init.first_bit = 0;
	CSIG_Init(&csig_init);
#else

    csig_init.csign = 0;
    csig_init.mode = CSI_MODE_MASTER;
    csig_init.transfer_mode =CSI_RECEIVE_ONLY;
    csig_init.data_size = CSI_DATASIZE_16b;
    csig_init.cpol = CSI_CPOL_HIGH;
    csig_init.cpha = CSI_CPHA_2Edge;
    csig_init.nss = CSI_NSS_Hard;
    csig_init.prescaler = CSI_BaudRatePrescaler_1;
    csig_init.clk_fre = 4;
    csig_init.first_bit = 0;

    CSIG_Init(&csig_init);

    csig_init.csign = 1;
    csig_init.mode = CSI_MODE_SLAVE;
    csig_init.transfer_mode = CSI_TRANSMIT_ONLY;
    csig_init.data_size = CSI_DATASIZE_16b;
    csig_init.cpol = CSI_CPOL_HIGH;
    csig_init.cpha = CSI_CPHA_2Edge;
    csig_init.nss = CSI_NSS_Hard;
    csig_init.first_bit = 0;
    CSIG_Init(&csig_init);
#endif
}

void csi0_master_send(void)
{
    __IO uint16_t send_data = 0x6405;

	INFOR("Master send data:0x%x\n",send_data);
    CSIG_SendData(0,send_data);
    while(CSIG_Get_Status(0,0) == 0);
    CSIG_Clear_Status(0,0);
}

void csi0_master_recv(void)
{
    uint16_t recv_data = 0;

    while(CSIG_Get_Status(0,1) == 0);

    recv_data = CSIG_ReceiveData(0);
    INFOR("Master recv data:0x%x\n",recv_data);
    CSIG_Clear_Status(0,1);
}

void csi1_slave_send(void)
{
    __IO uint16_t send_data = 0x7801;
    static uint16_t read_first = 0;
	if(!read_first){
	   CSIG_ReceiveData(0);//Note:have to read the data before send
       INFOR("Read the master rx register before  slave send\n");
       read_first++;
   }

	INFOR("Slave send data:0x%x\n",send_data);
    CSIG_SendData(1,send_data);
    while(CSIG_Get_Status(1,0) == 0);
    CSIG_Clear_Status(1,0);
}


void csi1_slave_recv(void)
{
    uint16_t recv_data = 0;

    while(CSIG_Get_Status(1,1) == 0);

    recv_data = CSIG_ReceiveData(1);
    INFOR("Slave recv data:0x%x\n",recv_data);
    CSIG_Clear_Status(1,1);
}

void csi_test()
{
#if MATSER_SENT_TEST
	INFOR("TEST: master send and slave receive\n");
	csi0_master_send();
    csi1_slave_recv();
#else
	INFOR("TEST: master receive and slave send\n");
	csi1_slave_send();
    csi0_master_recv();

#endif
}
