#include "usart.h"
#include "delay.h"
#include "iic.h"
#include "096.h"


int main(void)
{
	// 初始化一系列外设
	delay_init();
	usart1_init(115200);

	while (1)
	{
		delay_ms(500);
	}
}
