#ifndef __Dbus_h
#define __Dbus_h

#include "usart.h"
#include <math.h>
#include <string.h>

#define DBUS_MAX_LEN (50)
#define DBUS_BUF_LEN (18)
#define DBUS_HUART huart3
#define rc_Init {0, 0, 0, 0, 0, 0, 0}

typedef __packed struct {
    int16_t ch0;
    int16_t ch1;
    int16_t ch2;
    int16_t ch3;
    int16_t roll;
    uint8_t s1;
    uint8_t s2;
} rc_info_t;

extern rc_info_t rc;

extern uint8_t dbus_buf[DBUS_BUF_LEN]; // 存储接收到的遥控器数据

static int uart_receive_dma_no_it(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
void Dbus_uart_Init(void);
void rc_callback_handler(rc_info_t *rc, uint8_t *buff);
uint16_t dma_current_data_counter(DMA_Stream_TypeDef *dma_stream);
static void uart_rx_idle_callback(UART_HandleTypeDef *huart);
void uart_receive_handle(UART_HandleTypeDef *huart);

#endif

