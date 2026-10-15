# rookie32

用于记录学习嵌入式的过程中的各个项目 

## 快速开始

- **项目**, 进入`/projects`目录, 选择对应的开发板目录, 双击即可看到对应开发板下的项目 
- **烧录**, 每个项目都提供了`.uvprojx`文件, 可双击打开使用`keil`进行编译和烧录; 同时每个项目的`Firmware/`文件夹中提供了已经编译好的`.hex`文件, 可以使用串口方式直接烧录

## 开发环境

- **MCU**, STM32F103xxx 
- **IDE**, Keil MDK 5, Visual Studio Code 
- **Library**, STM32F10x Standard Peripheral Library 
- **Compiler**, ARMCC / ARMCLANG

## 项目

见`projects/` 

按照开发板的型号分为了不同文件夹, 在对应文件夹下查找项目即可 

本仓库中所有项目都是通过`Keil`开发的, `.uvprojx`工程文件随源码一起提交至github; 推荐使用Keil进行开发与调试, 同时也提供了`.hex`文件以供串口方式烧录, 可以在每个项目的`Firmware/`文件夹中找到 

## 工具

见`tools/` 

## 文档

见`docs/` 
