#include "lin.h"
#include "r_memb.h"

#define LinErrHandleNUM     16


void *LIST_CONCAT(error_handle_list,_list) = NULL;
list_t error_handle_list = (list_t)&LIST_CONCAT(error_handle_list,_list);

R_MEMB(ErrHandleMemb,struct uiLin2ErrHandleList, LinErrHandleNUM);

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

    lin3_frm.resp_dir = LIN3_RESP_FROM_MASTER;// 1:transmit 0:receive

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

    if(!err_list_init)
        list_init(error_handle_list);

    LIN2_Init((LIN2_InitTypeDef*)uiLin2Init_p);
}

void uiLin2ErrDefaultHandle(void)
{
    printf("uiLin2ErrDefaultHandle\n");
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
    uiLin2Init_p->uiLin2ErrHandler = uiLin2ErrDefaultHandle;
}


struct uiLin2ErrHandleList* uiLinCreateErrHandleInstance(uint8_t uiLinIndex,
    uiLinErrHandlerCallback uiLin2ErrHandler)
{
    uint8_t i = 0; 
    struct uiLin2ErrHandleList *ErrHandleInstance = NULL;
    //Lookup for the existing instance
    ErrHandleInstance = uiLinPopInstanceFromList(uiLinIndex);
    if(ErrHandleInstance == NULL){

        ErrHandleInstance = memb_alloc(&ErrHandleMemb);

        if(ErrHandleInstance == NULL){
            ERROR("No no enough ErrHandleMemb \n");
            return NULL;
        }
    }
    
    ErrHandleInstance->uiLinm = lin_index;
    ErrHandleInstance->uiLin2ErrHandler =uiLin2ErrHandler;

    list_add(error_handle_list,ErrHandle);
}

static struct uiLin2ErrHandleList* uiLinPopInstanceFromList(uint8_t uiLinIndex)
{
    struct uiLin2ErrHandleList* ErrHandleInstance  = NULL;
	ErrHandleInstance = list_head(error_handle_list);
    
    while(ErrHandleInstance != NULL){
		if(ErrHandleInstance->uiLinIndex == uiLinIndex){
            return ErrHandleInstance;
        }
        ErrHandleInstance = list_item_next(ErrHandleInstance);
	}
    printf("Not found the ErrHandleInstance with its index:%d\n",uiLinIndex);
    return NULL;
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

#define LIN2_INDEX_USED     LIN21

// response direction 1: Master---> Slave, 0 :Slave---->Master
#define LIN2_RESP_FROM_MASTER	1  
#define LIN2_RESP_TO_MASTER	0

void lin2_master_excute(void)
{
    uint8_t resp_data[10] = "abcdefg";
    LIN2_Frm_InfoTypeDef lin2_frm;
	static uint8_t test_frm_id = 0x30;
    memset(&lin2_frm,0,sizeof(lin2_frm));

    lin2_frm.frm_id = test_frm_id++;
    lin2_frm.frm_sep = 0;
    lin2_frm.resp_dir = LIN2_RESP_FROM_MASTER;//response direction 1:transmit 0:receive

    LIN2_Master_Process(LIN2_INDEX_USED,&lin2_frm,7,resp_data);
	
	if(test_frm_id == 0x3f)
		test_frm_id = 0x30;
}
