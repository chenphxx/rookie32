# 环境配置

在开始之前, 你还需要配置基本的嵌入式开发环境, 本项目的所有工程目前均使用`Keil V5`与`Visual Studio Code`进行开发: keil提供开发与编译环境, vscode提供代码编辑与补全功能; 若后续环境更新, 本文档也会同步更新 

## Keil V5环境配置

### 软件下载

下载链接: [MDK-ARM Version 5.43a Evaluation Software Request](https://www.keil.com/demo/eval/arm.htm) 

![](assets/images/6aa8d1a98ac51900caba6b35d7cd7412f68b6724.png)

下载之前需要填写一些信息, 随意填写即可, 不会影响软件下载; 填写好之后点击`Submit`提交, 然后点击链接则会下载 

![](assets/images/98460d52e15acd84da61f4251fd73cd7d09a400f.png)

### 注册机keygen

下载链接: [keygen_new2032.exe](https://pan.baidu.com/s/171hUzcuUhGikQJNFgEMxoYpmZ5TDFWcQUZlm==?linksource=zhihu&_at_=1794124624618) 

下载软件之后, 以管理员身份安装, 此外软件还需要激活才能够正常使用, 我们需要用到`keygen`注册机进行激活 

初次下载keygen会被windows拦截, 选择`允许在设备上`即可, 该程序打开会有很大的声音, 注意电脑音量 

![](assets/images/da26b5f7ad6cb7f4d85e1242c2e04ec022c3dfd5.png)

Target选择`ARM` 

<img src="assets/images/c4434621b8ecddc1b14c8b19844a7ff052d6e630.png" title="" alt="" width="272" />

打开keil, 选择File->License Management, 复制CID, 填入keygen中点击生成, 将生成的密钥填入keil即可 

![](assets/images/9ca7676f80e675e268869d3223193e9539a0ecbd.png)

![](assets/images/79e99e83cbbe53a99fc84989ffd1a7f9b2345e7b.png)

![](assets/images/b9e40449a07219cbb4990ff5ec3d5ee4a9c07745.png)

### 芯片包下载

安装并注册好软件之后, 如果要正常开发编译项目, 则还需要下载对应芯片的芯片包, 打开项目后, keil会自动检测并提示需要下载的芯片包, 可在软件内直接下载, 也可直接在官网下载对应的芯片包安装 

![](assets/images/f8958a9d10cf5b5ed68c203f4ac02cde314ca99d.png)

官网下载链接: [Arm Keil | Devices](https://www.keil.arm.com/devices/) 

这里我们搜索项目使用的开发板即可, 以`STM32F103C8T6`为例 

![](assets/images/e84ffa979e3260d3b1f9a4bf3017913d68903993.png)

![](assets/images/6735ef5020e71bd6d9dccc8c97d5442e887d4307.png)

![](assets/images/f3f495ed5536e1feeba61a81784e21aa1e0dd33b.png)

点击下载并安装即可 

### AC5编译器配置

经过上述的配置, 应该能够正常打开keil项目了, 不过编译还是会报错, 这是编译器的原因 

打开options我们可以看到, 这里缺少了`ARM Compiler Version 5`, 新版Keil默认不再包含ARM Compiler Version 5的编译链, 但是大部分工程还是使用的AC5编译的, 我们需要手动添加AC5的编译链 

![](assets/images/c6004f3551a05f13ca09407f01c6e84f737eb3cb.png)

ARM Compiler Version 5下载地址: 

1. gitcode地址: [ARM Compiler Version5](https://gitcode.com/open-source-toolkit/bd0dd/blob/main/ARMCC.zip) 

2. github地址: [XingheXia11/ArmComplier5.06](https://github.com/XingheXia11/ArmComplier5.06)

在keil v5的安装目录下, 找到ARM文件夹, 在其中新建文件夹`ARMCC` 

![](assets/images/cac2e5cddf27b510f55fb18b56fc8e5ae9414c33.png)

将下载好的AC5解压并复制入该文件夹中 

![](assets/images/dec0b899f04b399b073d273e50bf2ed719373cd4.png)

随后在keil v5中添加AC5编译器 

![](assets/images/d417b67dc44adddfa6d9adccbfa8c3268d7243e7.png)

<img src="assets/images/98f1d35eaf8c0244952d2e40462c7dba155bb718.png" title="" alt="" width="282" />

选择`ARMCC`文件夹即可, 添加完成后, keil即可使用AC5编译器进行编译 

![](assets/images/cd1dd7382cd1a1f123db7e739490c8763e7376eb.png)

## Visual Studio Code环境配置

vscode中的配置相对简单, 首先需要配置好keil v5环境(vscode本质还是使用keil环境进行编译), 下载插件即可 

![](assets/images/6719dfb06b41982d49ffac99bac91dabe0a16f3b.png)

在vscode插件市场搜索`Keil Assistant`安装即可, 安装完成后使用vscode打开工程目录, 即可在左下角使用插件, 可对工程进行编译以及下载 

![](assets/images/7ae5390b4785d0b9df6844db57a68586aa14b121.png)


