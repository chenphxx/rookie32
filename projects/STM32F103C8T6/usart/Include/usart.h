#ifndef __USART_H
#define	__USART_H


#include "stm32f10x.h"
#include "stdio.h"

#define USART_REC_LEN 200  // 定义最大接收字节数 200

extern u8 USART_RX_BUF[USART_REC_LEN];  // 接收缓冲,最大USART_REC_LEN个字节.末字节为换行符
extern u16 USART_RX_STA;  // 接收状态标记

void usart1_init(int);  // 参数为波特率
void _sys_exit(int);  // 避免使用半主机模式
int fputc(int, FILE*);  // 重定向printf
void USART1_IRQHandler(void);  // 串口中断函数


#endif
