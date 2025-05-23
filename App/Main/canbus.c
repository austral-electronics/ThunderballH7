#include "common.h"

#define BAUDRATE_TEST

FDCAN_TxHeaderTypeDef   TxHeader;
FDCAN_RxHeaderTypeDef   RxHeader;
uint8_t                 TxData[8];
uint8_t                 RxData[8];

/**
  * @brief FDCAN1/2 Initialization Function : Rapid Testing without CubeMX Code generation
  * @param None
  * @retval None
  * 
  *  Bit time configuration: for Clock Rate=10Mhz, BaudRate=250KB/s and Sample-Point=87.5%
  * 
  *  CAN Bit Time Calculation :              http://www.bittiming.can-wiki.info/
  * 
  *  fdcan_ker_ck                          = 10Mhz
  *  Prescaler                             = 5 (2Mhz)
  *  Time_quantum (tq)                     = 0.5 us
  *  Synchronization_Jump_width            = 1 tq
  *  Propagation_segment + Phase_segment_1 = 6 tq        -> !!!! 5tq in CubeMX !!!!
  *  Phase_segment_2                       = 1 tq        -> !!!! 2tq in CubeMX -> Impossible to init NominalTimeSeg2 lowest than 2 !!!!
  *  Bit_length                            = 8 tq = 4us
  *  Bit_rate                              = 250Kb/s
  */
#ifdef BAUDRATE_TEST
static void MX_FDCAN1_Init2(void) {
    hfdcan1.Instance = FDCAN1;
    hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;       // Classic mode
    hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
    hfdcan1.Init.AutoRetransmission = DISABLE;
    hfdcan1.Init.TransmitPause = DISABLE;
    hfdcan1.Init.ProtocolException = DISABLE;
    hfdcan1.Init.NominalPrescaler = 5;
    hfdcan1.Init.NominalSyncJumpWidth = 1;
    hfdcan1.Init.NominalTimeSeg1 = 6;
    hfdcan1.Init.NominalTimeSeg2 = 1;
    hfdcan1.Init.DataPrescaler = hfdcan1.Init.NominalPrescaler;
    hfdcan1.Init.DataSyncJumpWidth = hfdcan1.Init.NominalSyncJumpWidth;
    hfdcan1.Init.DataTimeSeg1 =   hfdcan1.Init.NominalTimeSeg1;
    hfdcan1.Init.DataTimeSeg2 =  hfdcan1.Init.NominalTimeSeg2;
    hfdcan1.Init.MessageRAMOffset = 0;
    hfdcan1.Init.StdFiltersNbr = 0;
    hfdcan1.Init.ExtFiltersNbr = 0;
    hfdcan1.Init.RxFifo0ElmtsNbr = 8;      // 32
    hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxFifo1ElmtsNbr = 0;
    hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxBuffersNbr = 0;
    hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.TxEventsNbr = 0;
    hfdcan1.Init.TxBuffersNbr = 0;
    hfdcan1.Init.TxFifoQueueElmtsNbr = 8;       // 1
    hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
/*
    hfdcan1.msgRam.StandardFilterSA = 0;
    hfdcan1.msgRam.ExtendedFilterSA = 0;
    hfdcan1.msgRam.RxFIFO0SA = 0;
    hfdcan1.msgRam.RxFIFO1SA = 0;
    hfdcan1.msgRam.RxBufferSA = 0;
    hfdcan1.msgRam.TxEventFIFOSA = 0;
    hfdcan1.msgRam.TxBufferSA = 0;
    hfdcan1.msgRam.TxFIFOQSA = 0;
    hfdcan1.msgRam.TTMemorySA = 0;
    hfdcan1.msgRam.EndAddress = 0;
    hfdcan1.ErrorCode = 0;
*/
    if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK) {
        Error_Handler();
    }
}

static void MX_FDCAN2_Init2(void) {
    hfdcan2.Instance = FDCAN2;
    hfdcan2.Init.FrameFormat = FDCAN_FRAME_CLASSIC;       // Classic mode
    hfdcan2.Init.Mode = FDCAN_MODE_NORMAL;
    hfdcan2.Init.AutoRetransmission = DISABLE;
    hfdcan2.Init.TransmitPause = DISABLE;
    hfdcan2.Init.ProtocolException = DISABLE;
    hfdcan2.Init.NominalPrescaler = 5;
    hfdcan2.Init.NominalSyncJumpWidth = 1;
    hfdcan2.Init.NominalTimeSeg1 = 6;
    hfdcan2.Init.NominalTimeSeg2 = 1;
    hfdcan2.Init.DataPrescaler = hfdcan2.Init.NominalPrescaler;
    hfdcan2.Init.DataSyncJumpWidth = hfdcan2.Init.NominalSyncJumpWidth;
    hfdcan2.Init.DataTimeSeg1 =   hfdcan2.Init.NominalTimeSeg1;
    hfdcan2.Init.DataTimeSeg2 =  hfdcan2.Init.NominalTimeSeg2;
    hfdcan2.Init.MessageRAMOffset = hfdcan1.msgRam.EndAddress - SRAMCAN_BASE  ;
//    hfdcan2.Init.MessageRAMOffset = 0;
    hfdcan2.Init.StdFiltersNbr = 0;
    hfdcan2.Init.ExtFiltersNbr = 0;
    hfdcan2.Init.RxFifo0ElmtsNbr = 8;      // 32
    hfdcan2.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan2.Init.RxFifo1ElmtsNbr = 0;
    hfdcan2.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan2.Init.RxBuffersNbr = 0;
    hfdcan2.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan2.Init.TxEventsNbr = 0;
    hfdcan2.Init.TxBuffersNbr = 0;
    hfdcan2.Init.TxFifoQueueElmtsNbr = 16;      // 1
    hfdcan2.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan2.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
/*
    hfdcan2.msgRam.StandardFilterSA = 0;
    hfdcan2.msgRam.ExtendedFilterSA = 0;
    hfdcan2.msgRam.RxFIFO0SA = 0;
    hfdcan2.msgRam.RxFIFO1SA = 0;
    hfdcan2.msgRam.RxBufferSA = 0;
    hfdcan2.msgRam.TxEventFIFOSA = 0;
    hfdcan2.msgRam.TxBufferSA = 0;
    hfdcan2.msgRam.TxFIFOQSA = 0;
    hfdcan2.msgRam.TTMemorySA = 0;
    hfdcan2.msgRam.EndAddress = 0;
    hfdcan2.ErrorCode = 0;
*/
    if (HAL_FDCAN_Init(&hfdcan2) != HAL_OK) {
        Error_Handler();
    }
}
#endif

//------- Init CANbus1 Mode ---------

bool InitCAN1(void) {
    #ifdef BAUDRATE_TEST
        MX_FDCAN1_Init2();        // To test other config than classic mode at 250KB
    #endif

    if(HAL_FDCAN_Start(&hfdcan1)!= HAL_OK) {
        return false;
    }
    if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
        return false;
    }
    TxHeader.IdType = FDCAN_EXTENDED_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;
    return true;
}

//------- Init CANbus2 Mode ---------

bool InitCAN2(void) {
    #ifdef BAUDRATE_TEST
        MX_FDCAN2_Init2();        // To test other config than classic mode at 250KB
    #endif

    if(HAL_FDCAN_Start(&hfdcan2)!= HAL_OK) {
        return false;
    }
    if (HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
        return false;
    }
    TxHeader.IdType = FDCAN_EXTENDED_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;
    return true;
}

//------- Test CANbus1 TX : Send an NMEA2000 Vessel Heading sentence @ 250KB -------

bool TransmitCAN_Test(FDCAN_HandleTypeDef *hfdcan) {
    TxData[0]++;			// SID
    TxData[1]=1;		    // Vessel Heading data high
    TxData[2]=0xEA;         // Vessel Heading data low  : 343.23 Degree Mag
    TxData[3]=0x00;
    TxData[4]=0x00;
    TxData[5]=0xFF;
    TxData[6]=0x7F;
    TxData[7]=0xFD;
    TxHeader.Identifier = 0x9F11261;	// PGN=127250 + Source=97 + Priority=2
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;
    if (HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &TxHeader, TxData)!= HAL_OK) {
        // Error_Handler();
        TxData[1]=1;  // This code is only for breakpoint
        return false;
    }
    return true;
}


//------ Test CANbus 1 or 2 RX : Toggle LED --------

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
    if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET) {
        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK) {          // Retreive Rx messages from RX FIFO0
            //   Error_Handler();                                                                   // Reception Error
        }
        else {                                                                                      // Reception OK
            HAL_GPIO_TogglePin(CMD_LED_GPIO_Port, CMD_LED_Pin);     //!!!!  BREAKPOINT HERE  !!!!!     Toggle Logo backlight on each CANbus Reception
        }
        if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
            //   Error_Handler();                                                                   // Notification Error
        }
    }
}