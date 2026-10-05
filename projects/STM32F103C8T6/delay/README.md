# delay

## 循环计数延时

在之前的 `LED` 示例中, 我们点亮了开发板上的 PC13 引脚, 并通过循环计数实现延时, 使 LED 闪烁起来 

```c
for (int i = 0; i < 1000000; i++);
```

这种方式实现简单, 但是存在一些问题 

- 无法准确控制延时时间, 例如想实现 500 ms 延时, 只能通过不断调整循环次数进行估算 

- 同一段延时代码, 在不同主频或不同设备上运行时, 实际延时时间可能不同 

- CPU 在循环过程中一直处于工作状态, 无法有效执行其他任务 

因此, 需要一种基于硬件时钟、能够提供稳定时间基准的延时方式 

--- 

## SysTick 系统定时器

Cortex-M3提供了一个`SysTick`系统定时器, 一个24位`向下递减计数器` 

- 计数器从重装载值开始向下计数

- 每经过一个时钟周期, 计数器减 1

- 当计数器减到 0 时, 重新装载重装载值

- 如果开启 SysTick 中断, 则计数到 0 后产生 SysTick 异常

- CPU 自动进入 `SysTick_Handler()` 中断服务函数

SysTick 主要涉及以下几个寄存器

```text
SysTick->CTRL
SysTick->LOAD
SysTick->VAL
SysTick->CALIB
```

其中实现基本定时功能主要使用: 

```text
CTRL    控制寄存器
LOAD    重装载寄存器
VAL     当前计数值
```

---

## 时钟频率

频率表示单位时间内周期性事件发生的次数, 单位为 Hz

例如 STM32F103C8T6 的系统时钟配置为 72 MHz: 

```text
72 MHz = 72,000,000 Hz
```

表示系统时钟每秒产生 7200 万个时钟周期

因此一个时钟周期的时间为: 

```text
T = 1 / 72,000,000
  ≈ 13.89 ns
```

也就是说, SysTick 如果使用 72 MHz 的时钟源, 那么每经过约 13.89 ns, 计数器减 1

---

## 使用 SysTick 建立 1 ms 时间基准

如果希望 SysTick 每 1 ms 产生一次中断, 那么需要让 SysTick 在 1 ms 内完成一次完整计数

系统时钟为: 

```text
72 MHz
```

因此: 

```text
1 ms = 0.001 s
```

1 ms 内的时钟周期数量: 

```text
72,000,000 × 0.001 = 72,000
```

因此可以配置: 

```c
SysTick_Config(SystemCoreClock / 1000);
```

当: 

```text
SystemCoreClock = 72 MHz
```

时: 

```text
72000000 / 1000 = 72000
```

`SysTick_Config()` 会根据这个值配置 SysTick, 使其产生约 1 ms 一次的周期性中断

可以简单理解为: 

```text
72 MHz
  ↓
每 13.89 ns 一个时钟周期
  ↓
72000 个时钟周期
  ↓
1 ms
  ↓
SysTick 中断
```

---

## SysTick 中断

配置完成后, SysTick 会不断运行

当计数器从重装载值递减到 0 时, 如果开启了中断, Cortex-M3 会自动响应 SysTick 异常, 并执行: 

```c
void SysTick_Handler(void)
{
    // SysTick 中断服务程序
}
```

`SysTick_Handler()` 不需要在 `main()` 中手动调用

它是由硬件产生 SysTick 异常后, CPU 根据中断向量表自动进入的

例如: 

```text
SysTick 计数器
      ↓
计数到 0
      ↓
产生 SysTick 异常
      ↓
CPU 响应异常
      ↓
SysTick_Handler()
      ↓
执行中断处理代码
      ↓
返回原来的程序
```

---

## 使用 SysTick 建立系统毫秒计数器

可以在 `SysTick_Handler()` 中维护一个全局毫秒计数器: 

```c
volatile uint32_t g_ms = 0;

void SysTick_Handler(void)
{
    g_ms++;
}
```

因为 SysTick 每 1 ms 进入一次中断, 所以: 

```text
经过 1 ms   g_ms + 1
经过 2 ms   g_ms + 2
经过 3 ms   g_ms + 3
...
经过 500 ms g_ms + 500
```

因此, `g_ms` 可以作为系统运行时间的毫秒计数器

`volatile` 用于告诉编译器, 该变量可能在中断服务程序中被异步修改, 因此每次使用时都需要重新读取

---

## 实现阻塞式毫秒延时

有了 `g_ms` 之后, 可以通过比较时间差实现延时: 

```c
void delay_ms(uint32_t ms)
{
    uint32_t start = g_ms;

    while ((uint32_t)(g_ms - start) < ms)
    {
    }
}
```

例如: 

```c
delay_ms(500);
```

执行过程: 

```text
假设开始时: 

g_ms = 1000

start = 1000
```

之后 SysTick 每 1 ms 触发一次: 

```text
1 ms    g_ms = 1001
2 ms    g_ms = 1002
3 ms    g_ms = 1003
...
499 ms  g_ms = 1499
500 ms  g_ms = 1500
```

此时: 

```text
g_ms - start
= 1500 - 1000
= 500
```

满足: 

```text
500 < 500
```

为假, 因此退出 `while`, `delay_ms(500)` 执行结束

---

## 完整实现

见`delay/` 

---

## delay_ms(500) 实际发生了什么

假设: 

```text
SystemCoreClock = 72 MHz
SysTick 周期 = 1 ms
```

调用: 

```c
delay_ms(500);
```

之后: 

```text
                    STM32F103
                        │
                        ↓
                  SysTick 开始计数
                        │
                        ↓
              LOAD = 71999
                        │
                        ↓
              VAL 逐渐递减
                        │
                        ↓
                    VAL = 0
                        │
                        ↓
                SysTick 异常
                        │
                        ↓
              SysTick_Handler()
                        │
                        ↓
                    g_ms++
                        │
                        ↓
                  返回主程序
                        │
                        ↓
                SysTick 再次计数
                        │
                        ↓
                    重复
                        │
                        ↓
                     500 次
                        │
                        ↓
              g_ms - start = 500
                        │
                        ↓
              delay_ms(500) 返回
```
