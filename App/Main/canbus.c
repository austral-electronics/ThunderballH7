#include "common.h"

FDCAN_TxHeaderTypeDef   TxHeader;
FDCAN_RxHeaderTypeDef   RxHeader;
uint8_t                 TxData[8];
uint8_t                 RxData[8];

/**
  * @brief FDCAN1 Initialization Function : Rapid Testing without CubeMX Code generation
  * @param None
  * @retval None
  * https://github.com/STMicroelectronics/STM32CubeH7/blob/master/Projects/STM32H743I-EVAL/Examples/FDCAN/FDCAN_Classic_Frame_Networking/Src/main.c
  * Line 218
  * 
  * Bit Timing Calculator :
  * http://www.bittiming.can-wiki.info/
  * https://www.kvaser.com/support/calculators/can-fd-bit-timing-calculator/
  * https://www.nxp.com/docs/en/application-note/AN1798.pdf
  * 
  */
static void MX_FDCAN1_Init2(void)
{
/* Bit time configuration:
    fdcan_ker_ck               = 40 MHz  -> 10Mhz
    Time_quantum (tq)          = 25 ns -> 100ns
    Synchronization_segment    = 1 tq
    Propagation_segment        = 23 tq
    Phase_segment_1            = 8 tq
    Phase_segment_2            = 8 tq
    Synchronization_Jump_width = 8 tq
    Bit_length                 = 40 tq = 1 µs -> 4us
    Bit_rate                   = 1 MBit/s -> 250Kb
  */

  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = DISABLE;         // DISABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;          // DISABLE;
  /*
  hfdcan1.Init.NominalPrescaler = 0x1;              // tq = NominalPrescaler x (1/fdcan_ker_ck)
  hfdcan1.Init.NominalSyncJumpWidth = 0x8;          // 2;
  hfdcan1.Init.NominalTimeSeg1 = 0x1F;              // 37; NominalTimeSeg1 = Propagation_segment + Phase_segment_1
  hfdcan1.Init.NominalTimeSeg2 = 0x8;               // 2;
*/

  hfdcan1.Init.NominalPrescaler = 5;              // tq = NominalPrescaler x (1/fdcan_ker_ck)
  hfdcan1.Init.NominalSyncJumpWidth = 1;          // 2;
  hfdcan1.Init.NominalTimeSeg1 = 6;              // 37; NominalTimeSeg1 = Propagation_segment + Phase_segment_1
  hfdcan1.Init.NominalTimeSeg2 = 1;               // 2;



  hfdcan1.Init.DataPrescaler = hfdcan1.Init.NominalPrescaler;
  hfdcan1.Init.DataSyncJumpWidth = hfdcan1.Init.NominalSyncJumpWidth;
  hfdcan1.Init.DataTimeSeg1 =   hfdcan1.Init.NominalTimeSeg1;
  hfdcan1.Init.DataTimeSeg2 =  hfdcan1.Init.NominalTimeSeg2;


/*  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 9;
  hfdcan1.Init.DataTimeSeg1 = 30;
  hfdcan1.Init.DataTimeSeg2 = 9; */

  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 0;                   //0;
  hfdcan1.Init.ExtFiltersNbr = 0;
  hfdcan1.Init.RxFifo0ElmtsNbr = 32;                //1;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxFifo1ElmtsNbr = 0;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 0;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 1;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
}


bool InitCAN(void){
    MX_FDCAN1_Init2();
    if(HAL_FDCAN_Start(&hfdcan1)!= HAL_OK)
    {
        return false;
    }
    if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
    {
        return false;
    }
    TxHeader.IdType = FDCAN_EXTENDED_ID;                        // FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;            // FDCAN_ESI_PASSIVE
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;                      // FDCAN_FD_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;

    return true;
}

// Test sending an NMEA2000 Heading sentence @ 250KB

bool TransmitCAN_Test(FDCAN_HandleTypeDef *hfdcan){
    TxData[1]=1;		                // Vessel Heading data high
    TxData[2]=0xEA;
    TxData[3]=0x00;
    TxData[4]=0x00;
    TxData[5]=0xFF;
    TxData[6]=0x7F;
    TxData[7]=0xFD;
    TxHeader.Identifier = 0x9F11261;	// Vessel Heading PGN + Source
    TxHeader.DataLength = 8;
    if (HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &TxHeader, TxData)!= HAL_OK)
    {
        // Error_Handler();
        return false;
    }

    return true;
}


void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
  {
    HAL_GPIO_TogglePin(CMD_LED_GPIO_Port, CMD_LED_Pin);     // Toggle backlight

    /* Retreive Rx messages from RX FIFO0 */
    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
    {
      /* Reception Error */
    //   Error_Handler();
    }

    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
    {
      /* Notification Error */
    //   Error_Handler();
    }
  }
}