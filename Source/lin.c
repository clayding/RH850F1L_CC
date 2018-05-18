#include "lin.h"
#include "r_memb.h"

#define LinIntHandleNUM     16


void *LIST_CONCAT(int_handle_list,_list) = NULL;
list_t int_handle_list = (list_t)&LIST_CONCAT(int_handle_list,_list);

R_MEMB(IntHandleMemb,struct uiLin2IntHandleList, LinIntHandleNUM);

/******************************************************************************/
/**######  #       ### #     #  #####        #     #    #    ######  #######***/ 
/**#     # #        #  ##    # #     #       #     #   # #   #     #    #   ***/ 
/**#     # #        #  # #   #       #       #     #  #   #  #     #    #   ***/ 
/**######  #        #  #  #  #  #####        #     # #     # ######     #   ***/ 
/**#   #   #        #  #   # #       #       #     # ####### #   #      #   ***/ 
/**#    #  #        #  #    ## #     #       #     # #     # #    #     #   ***/ 
/**#     # ####### ### #     #  #####         #####  #     # #     #    #   ***/
/******************************************************************************/
#define LIN3_INDEX_USED     1

#define LIN3_MASTER_TEST    0 //the switch between master and slave
#define LIN3_SLAVE_TEST     0 //!LIN3_MASTER_TEST

#define LIN2_MASTER_TEST 	!LIN3_SLAVE_TEST

#define LIN3_RESP_FROM_MASTER	0  // response direction 1: Master---> Slave, 0 :Slave---->Master


void (*lin3_func_excute)(void);

void lin3_init(void)
{
    LIN3_InitTypeDef lin31;

    memset(&lin31,0,sizeof(lin31));

    lin31.linn = LIN3_INDEX_USED;
#if LIN3_MASTER_TEST
    lin31.mode = LIN3_MASTER;
#else //LIN3_SLAVE_TEST
    lin31.mode = LIN3_SLAVE_FIXED;
#endif
    lin31.baudrate = 19200;
#if LIN3_MASTER_TEST
    lin31.cfg_param.break_delim_width = 0x00;// 2Tbits
    lin31.cfg_param.break_width = 0x01;// 14 Tbits
#else
    lin31.cfg_param.rx_break_detect_width = 1;//1: Low-level width of 10.5 Tbits or longer is detected
#endif
    lin31.cfg_param.inter_byte_space = 0x01; //1 Tbit
    lin31.cfg_param.resp_space = 0x01;// 1 Tbit
    lin31.cfg_param.wu_tx_ll_width = 0x01;//2Tbits;

    lin31.int_out_sel = 1;/*RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and
                        RLIN3n status interrupt are used.*/
    lin31.int_en_mask = LIN3_EN_HDR_TX_INT_MASK | LIN3_ERR_DETECT_INT_MASK;

#if LIN3_MASTER_TEST
    lin31.int_en_mask |= LIN3_FRM_WU_TX_INT_MASK | LIN3_FRM_WU_RX_INT_MASK;
#else
    lin31.int_en_mask |= LIN3_RES_WU_TX_INT_MASK | LIN3_RES_WU_RX_INT_MASK;
#endif

    lin31.timeout_err_sel = 0;// Response timeout error

    lin31.err_en_mask = LIN3_FRM_ERR_DETECT_MASK | LIN3_TIO_ERR_DETECT_MASK | LIN3_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask
#if LIN3_MASTER_TEST
    lin31.err_en_mask |= LIN3_PHB_ERR_DETECT_MASK;
#else
    lin31.err_en_mask |= LIN3_IDP_ERR_DETECT_MASK;
#endif

    LIN3_Init(&lin31);

#if LIN3_MASTER_TEST
    lin3_func_excute = lin3_master_excute;
#else
    lin3_func_excute = lin3_slave_excute;
#endif
}

void lin3_self_mode_init(void)
{
    LIN3_InitTypeDef lin31;

    memset(&lin31,0,sizeof(lin31));

    lin31.linn = LIN3_INDEX_USED;
    lin31.mode = LIN3_MASTER;
    lin31.baudrate = 19200;

    lin31.cfg_param.break_delim_width = 0x01;// 2Tbits
    lin31.cfg_param.break_width = 0x01;// 14 Tbits
    lin31.cfg_param.inter_byte_space = 0x01; //1 Tbit
    lin31.cfg_param.resp_space = 0x01;// 1 Tbit
    lin31.cfg_param.wu_tx_ll_width = 0x01;//2Tbits;

    lin31.int_out_sel = 1;/*RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and
                        RLIN3n status interrupt are used.*/
    lin31.int_en_mask = LIN3_EN_HDR_TX_INT_MASK | LIN3_ERR_DETECT_INT_MASK |
        LIN3_FRM_WU_TX_INT_MASK;
    lin31.timeout_err_sel = 0;// Response timeout error

    lin31.err_en_mask = LIN3_FRM_ERR_DETECT_MASK | LIN3_PHB_ERR_DETECT_MASK | LIN3_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask

    RLIN3_Self_Mode_Init(&lin31);
}


void lin3_master_excute(void)
{
    uint8_t resp_data[10] = "abcdefg";
    LIN3_Frm_InfoTypeDef lin3_frm;
	static uint8_t test_frm_id = 0x30;
    memset(&lin3_frm,0,sizeof(lin3_frm));

    lin3_frm.frm_id = test_frm_id++;
    lin3_frm.frm_sep = 0;
    lin3_frm.resp_dir = LIN3_RESP_FROM_MASTER;//response direction 1:transmit 0:receive

    LIN3_Master_Process(LIN3_INDEX_USED,&lin3_frm,7,resp_data);
	
	if(test_frm_id == 0x3f)
		test_frm_id = 0x30;
}

void lin3_slave_excute(void)
{
    __IO uint8_t resp_data[10] = "12345678";

    LIN3_Frm_InfoTypeDef lin3_frm;

    memset(&lin3_frm,0,sizeof(lin3_frm));

    lin3_frm.resp_dir = !LIN3_RESP_FROM_MASTER;// 1:transmit 0:receive

    LIN3_Slave_Process(LIN3_INDEX_USED,&lin3_frm,7,resp_data);
}

extern uint8_t lin_master_sent_count;//defined in main.c

void lin_test_excute()
{
#if LIN3_MASTER_TEST
    if(lin_master_sent_count){
		INFOR("LIN3 Master send....\n");
		lin3_master_excute();
		lin_master_sent_count--;
	}
#endif
#if LIN3_SLAVE_TEST
	lin3_slave_excute();
#endif

#if LIN2_MASTER_TEST 
    if(lin_master_sent_count){
		INFOR("LIN2 Master send....\n");
		lin2_master_excute();
		lin_master_sent_count--;
	}
#endif
}

/******************************************************************************/
/*******************######  #       ### #     #  ##### ************************/ 
/*******************#     # #        #  ##    # #     #************************/ 
/*******************#     # #        #  # #   #       #************************/ 
/*******************######  #        #  #  #  #  ##### ************************/ 
/*******************#   #   #        #  #   # # #      ************************/ 
/*******************#    #  #        #  #    ## #      ************************/ 
/*******************#     # ####### ### #     # #######************************/ 
/*Note:
All the below functions defined according to the requirement of the Gearchief*/
/******************************************************************************/

void Lin2Init(struct uiLin2InitStruct* uiLin2Init_p)
{
    static bool err_list_init = 0;

    if(!err_list_init){
        err_list_init = 1;
        list_init(int_handle_list);
    }
    
    uiLinCreateIntHandleInstance(uiLin2Init_p->uiLinm,uiLin2Init_p->uiLin2IntHandler);
#define LIN2_SELF_TEST_MODE 1
#ifdef LIN2_SELF_TEST_MODE
    RLIN2_Self_Mode_Init((LIN2_InitTypeDef*)uiLin2Init_p);
#else
    LIN2_Init((LIN2_InitTypeDef*)uiLin2Init_p);
#endif
}

void uiLin2ErrDefaultHandle(void)
{
    printf("uiLin2ErrDefaultHandle\n");
}

void uiLin2CompleteDefaultHandle(void)
{
    printf("uiLin2CompleteDefaultHandle\n");
}
/**
  * @brief  Fills each uiLin2Init_p member with its default value.
  * @param  uiLin2Init_p : pointer to a struct uiLin2Init structure which will be initialized.
  * @retval None
  */
void Lin2InitStructInit(struct uiLin2InitStruct* uiLin2Init_p)
{
/*--------------- Reset lin2 init structure parameters values -----------------*/
    /* Initialize the uiLinm member */
    uiLin2Init_p->uiLinm = LIN21;
    /* initialize the uiBaudrate member */
    uiLin2Init_p->uiBaudrate = 19200;
    /* initialize the uiLin2Config member */
    uiLin2Init_p->uiLin2Config.uiBreak_delim_width = 0x00;// 1Tbits;
    uiLin2Init_p->uiLin2Config.uiBreak_width = 0x00; //13Tbits
    uiLin2Init_p->uiLin2Config.uiInter_byte_space = 0x01; //1 Tbit
    uiLin2Init_p->uiLin2Config.uiResp_space = 0x01;//1 Tbit
    uiLin2Init_p->uiLin2Config.uiWu_tx_ll_width= 0x01;//2Tbis
    /* Initialize the uiInt_en_mask member */
    uiLin2Init_p->uiInt_en_mask = LIN2_ERR_DETECT_INT_MASK | LIN2_FRM_WU_RX_INT_MASK | 
        LIN2_FRM_WU_TX_INT_MASK;
    /* Initialize the err_en_mask member */
    uiLin2Init_p->err_en_mask = LIN2_FRM_ERR_DETECT_MASK | LIN2_TIO_ERR_DETECT_MASK |
        LIN2_PHB_ERR_DETECT_MASK | LIN2_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask
	//deflaut interrupt handle function
    uiLin2Init_p->uiLin2IntHandler->uiLin2ErrHandler = uiLin2ErrDefaultHandle;
    uiLin2Init_p->uiLin2IntHandler->uiLin2CompleteHandler = uiLin2ErrDefaultHandle;
}
// response direction 1: Master---> Slave, 0 :Slave---->Master
#define LIN2_RESP_FROM_MASTER	1
#define LIN2_RESP_TO_MASTER	    0

uint8_t uiLin2GetMessage(uint8_t uiLinm,uint8_t uiID,uint8_t uiSelfTestLength,uint8_t *pMessage)
{
    uint8_t recv_len = 0;
    LIN2_Frm_InfoTypeDef lin2_frm;
    memset(&lin2_frm,0,sizeof(lin2_frm));

    lin2_frm.frm_id = uiID;
    lin2_frm.resp_dir = LIN2_RESP_TO_MASTER;//response direction 1:transmit 0:receive

    recv_len = LIN2_Master_Process(uiLinm,&lin2_frm,uiSelfTestLength,pMessage);

    return recv_len;
}

void uiLin2PutMessage(uint8_t uiLinm,uint8_t uiID,uint8_t uiLength,uint8_t *pMessage)
{
    LIN2_Frm_InfoTypeDef lin2_frm;
    memset(&lin2_frm,0,sizeof(lin2_frm));

    lin2_frm.frm_id = uiID;
    lin2_frm.resp_dir = LIN2_RESP_FROM_MASTER;//response direction 1:transmit 0:receive

    LIN2_Master_Process(uiLinm,&lin2_frm,uiLength,pMessage);
}
struct uiLin2IntHandleList* uiLinCreateIntHandleInstance(uint8_t uiLinIndex,
    uiLin2IntHandlerStruct* uiLin2IntHandler)
{
    struct uiLin2IntHandleList *IntHandleInstance = NULL;
    //Lookup for the existing instance
    IntHandleInstance = uiLinPopInstanceFromList(uiLinIndex);
    if(IntHandleInstance == NULL){ //Not found

        IntHandleInstance = memb_alloc(&IntHandleMemb);//create new

        if(IntHandleInstance == NULL){
            ERROR("No no enough IntHandleMemb \n");
            return NULL;
        }
        
        IntHandleInstance->uiLinIndex = uiLinIndex;
    }
    IntHandleInstance->uiLin2IntHandler = uiLin2IntHandler;

    list_add(int_handle_list,IntHandleInstance);
	
	return IntHandleInstance;
}

struct uiLin2IntHandleList* uiLinPopInstanceFromList(uint8_t uiLinIndex)
{
    struct uiLin2IntHandleList* IntHandleInstance  = NULL;
	IntHandleInstance = list_head(int_handle_list);
    
    while(IntHandleInstance != NULL){
		if(IntHandleInstance->uiLinIndex == uiLinIndex){
            return IntHandleInstance;
        }
        IntHandleInstance = list_item_next(IntHandleInstance);
	}
    printf("Not found the IntHandleInstance with its index:%d\n",uiLinIndex);
    return NULL;
}

void uiLin2FreeIntHandleInstance(uint8_t uiLinIndex)
{
    struct uiLin2IntHandleList* IntHandleInstance  = NULL;
    IntHandleInstance = list_head(int_handle_list);
    while(IntHandleInstance != NULL){
		if(IntHandleInstance->uiLinIndex == uiLinIndex){
            list_remove(int_handle_list,IntHandleInstance);
            memb_free(&IntHandleMemb,IntHandleInstance); //Found it
        }
        IntHandleInstance = list_item_next(IntHandleInstance);
	}
}

void uiLin2FreeIntHandleList(void)
{
    struct uiLin2IntHandleList* IntHandleInstance = NULL;
    IntHandleInstance = list_pop(int_handle_list);
    while(IntHandleInstance != NULL)
    {
        printf("free IntHandleInstance:%p\n",IntHandleInstance);
        memb_free(&IntHandleMemb, IntHandleInstance);
        IntHandleInstance = list_pop(int_handle_list);
    }
}
/*********************************TEST AREA************************************/
void lin2_init(void)
{
    struct uiLin2InitStruct uiLin2InitStruct;
    //bzero
    memset(&uiLin2InitStruct,0,sizeof(uiLin2InitStruct));
    //default setting
    Lin2InitStructInit(&uiLin2InitStruct);
    //initialization
    Lin2Init(&uiLin2InitStruct);
}

#define LIN2_INDEX_USED     LIN21 //the lin2m
#define LIN2_RECV_TEST      1     //recv response data test

void lin2_master_excute(void)
{
    uint8_t resp_data[10] = "abcdefg",len = 7;
	static uint8_t test_frm_id = 0x30;
#if LIN2_RECV_TEST
    len = uiLin2GetMessage(LIN2_INDEX_USED,test_frm_id,len,resp_data);
#else
    uiLin2PutMessage(LIN2_INDEX_USED,test_frm_id,len,resp_data);
#endif
	if(test_frm_id == 0x3f)
		test_frm_id = 0x30;
/********************************Dump data*************************************/
#define  DUMP_DATA_ENABLE //
//#define DUMP_STRING_ENABLE
#ifdef DUMP_DATA_ENABLE
    if(len > 0){//dump the sent/recv data
        uint8_t dump_data[64] = {0};
        memcpy(&dump_data,resp_data,len);
        INFOR("LIN2%d master id:0x%x %s response len:%d ",LIN2_INDEX_USED,
        test_frm_id,LIN2_RECV_TEST == 0 ?"send":"recv",len);
#ifdef DUMP_STRING_ENABLE
        dump_data[len] = '\0';
        INFOR("data:%s\n",dump_data);
#else
		{
			uint8_t i = 0;
			INFOR("data:");
			for(;i < len;i++)
				INFOR("%x ",dump_data[i]);
			INFOR("\n");
		}
#endif

    }
#endif
/********************************Dump data*************************************/
}
