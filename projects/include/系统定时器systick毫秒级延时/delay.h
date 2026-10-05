#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"
#include "core_cm3.h"


/**
 * @brief 初始化延时基准
 */
void delay_init(void);

/**
 * @brief  毫秒级延时
 * 
 * @param ms 延时的毫秒数
 */
void delay_ms(uint32_t ms);


#endif
