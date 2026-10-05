#ifndef __USART_H
#define	__USART_H


#include "stm32f10x.h"
#include "stdio.h"

#define USART_REC_LEN 200  // 定义最大接收字节数 200

extern u8 USART_RX_BUF[USART_REC_LEN];  // 接收缓冲,最大USART_REC_LEN个字节.末字节为换行符
extern u16 USART_RX_STA;  // 接收状态标记

/**
 * @brief usart1初始化
 *        TX-PA9 RX-PA10
 * 
 * @param rate 波特率
 */
void usart1_init(uint32_t rate);

/**
 * @brief 串口1中断服务函数
 * 
 * @param 
 */
void _sys_exit(int x);

/**
 * @brief 重定向printf函数
 * 
 * @param ch 字符
 * @param f 文件指针
 */
int fputc(int ch, FILE* f);

/**
 * @brief 串口中断函数
 */
void USART1_IRQHandler(void);


#endif
