#include "Dbus.h"
#include "math.h"
#include "stdio.h"

rc_info_t rc = rc_Init;
uint8_t dbus_buf[DBUS_BUF_LEN];

static int uart_receive_dma_no_it(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size) {
    uint32_t tmp1 = 0;
    tmp1 = huart->RxState;
    if ((tmp1 == HAL_UART_STATE_READY) || (Size == 0)) { // 接收数据的函数
        if (pData == NULL || Size == 0U) {
            return HAL_ERROR;
        }

        huart->pRxBuffPtr = pData;
        huart->RxXferSize = Size;
        huart->RxXferCount = HAL_UART_ERROR_NONE;

        // 启动DMA接收
        HAL_DMA_Start(huart->hdmarx, (uint32_t)&huart->Instance->DR, (uint32_t)pData, Size);

        // 使能UART的DMA接收,可以理解为开开关
        SET_BIT(huart->Instance->CR3, USART_CR3_DMAR);

        return HAL_OK;
    } else {
        return HAL_BUSY;
    }
}

void Dbus_uart_Init(void) {
    __HAL_UART_CLEAR_IDLEFLAG(&DBUS_HUART);                      // 清除IDLE空闲标志
    __HAL_UART_ENABLE_IT(&DBUS_HUART, UART_IT_IDLE);             // 使能IDLE中断
    uart_receive_dma_no_it(&DBUS_HUART, dbus_buf, DBUS_MAX_LEN); // 开启接收
}

void rc_callback_handler(rc_info_t *rc, uint8_t *buff) {
    rc->ch0 = ((buff[0] | buff[1] << 8) & 0x07FF);
		rc->ch0 -= 1024;
    rc->ch1 = ((buff[1] >> 3 | buff[2] << 5) & 0x07FF);
		rc->ch1 -= 1024;
    rc->ch2 = ((buff[2] >> 6 | buff[3] << 2 | buff[4] << 10) & 0x07FF);
		rc->ch2 -= 1024;
    rc->ch3 = ((buff[4] >> 1 | buff[5] << 7) & 0x07FF);
		rc->ch3 -= 1024;
		rc->roll = (buff[16] | (buff[17] << 8)) & 0x07FF;  //左上角滚轮
		rc->roll -= 1024;
    rc->s1 = (buff[5] >> 4 & 0x000C) >> 2;
    rc->s2 = (buff[5] >> 4 & 0x0003);

//    if ((fabs(rc->ch0) > 660) ||
//        (fabs(rc->ch1) > 660) ||
//        (fabs(rc->ch2) > 660) ||
//        (fabs(rc->ch3) > 660)) {

//    } else {
//        memset(rc, 0, sizeof(rc_info_t));
//    }
}

uint16_t dma_current_data_counter(DMA_Stream_TypeDef *dma_stream) {
    return ((uint16_t)(dma_stream->NDTR));
}

static void uart_rx_idle_callback(UART_HandleTypeDef *huart) {
    __HAL_UART_CLEAR_IDLEFLAG(huart);

    if (huart == &DBUS_HUART) {
        __HAL_DMA_DISABLE(huart->hdmarx); // 失能dma接收

        //if ((DBUS_MAX_LEN - dma_current_data_counter(huart->hdmarx->Instance)) == DBUS_BUF_LEN) {
            rc_callback_handler(&rc, dbus_buf); // 处理数据
        //}
        __HAL_DMA_SET_COUNTER(huart->hdmarx, DBUS_MAX_LEN);
        __HAL_DMA_ENABLE(huart->hdmarx); // 重新使能dma接收
    }
}

void uart_receive_handler(UART_HandleTypeDef *huart) {
    if (__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) && __HAL_UART_GET_IT_SOURCE(huart, UART_IT_IDLE)) {
        uart_rx_idle_callback(huart);
    }
}
