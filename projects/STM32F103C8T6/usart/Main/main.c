#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"


int main(void)
{
	delay_init();  // 初始化延时函数
	usart1_init(115200);  // 初始化串口, 波特率为115200
	
	while (1)
	{
		printf("Hello, USART1!\r\n");
		delay_ms(500);  // 延时500ms
	}
}
