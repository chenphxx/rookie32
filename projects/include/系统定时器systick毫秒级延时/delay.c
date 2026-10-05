#include "delay.h"


volatile uint32_t g_ms = 0;

void delay_init(void)
{
    SysTick_Config(SystemCoreClock / 1000);  // 72000000 / 1000, 表示1ms产生一次中断
}

void SysTick_Handler(void)
{
    g_ms++;  // 每次SysTick中断时，增加毫秒计数
}

void delay_ms(uint32_t ms)
{   
    uint32_t start = g_ms;

    while ((g_ms - start) < ms)
    {
        // 阻塞等待延时结束
    }
}
