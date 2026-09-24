#include "stm32f10x.h"
#include "usart.h"


int main(void)
{
	// GPIO初始化

	// 初始化PC13引脚 控制LED闪烁 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  // 使能APB2总线的GPIOC时钟 
	
	GPIO_InitTypeDef GPIO_InitStructure;  // 定义GPIO初始化结构体
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;  // 初始化引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  // 设置引脚速度为50MHz

	GPIO_Init(GPIOC, &GPIO_InitStructure);  // 初始化GPIOC的PC13引脚

	
	while (1)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);  // 设置PC13引脚为高电平，点亮LED灯
		for (int i = 0; i < 1000000; i++);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);  // 低电平, 熄灭
		for (int i = 0; i < 1000000; i++);
	}
}
