# 项目简介
基于esp32的nes游戏机，搭载mpu6050六轴加速度传感器，锂电池充放电管理，一个扬声器和功放芯片
<img src=picture/b4WdAGLRhJRCBX920GnRzPvmZdyYzCkslnxCK8W9.jpeg width=50% />
## 项目链接
### 立创开源平台链接：https://oshwhub.com/expert/esp32-nesemu
## 关于硬件
硬件采用嘉立创eda标准版设计，使用嘉立创eda标准版导入工程，仅主板有原理图，其余的pcb作为外壳使用，无原理图

## 关于软件和固件
本次的esp32软件分为两种不同的运行模式<br>
在hardware中的arduino代码烧录后使掌机运行在多功能手柄模式，具有蓝牙手柄，陀螺仪，WiFi投屏（需要配合上位机），串口监视器等功能。 <br>
<img src=picture/vHtI32REUVqj9z9X0yRDOxBjzrMCevPyyQuKQvT4.jpeg width=50% /><br>
在firmware中的nes游戏模拟器程序需要使用flashdownload-tools烧录，烧录后掌机运行在nes游戏模拟器模式，可以玩小游戏，具体的烧录教程参考：https://oshwhub.com/micespring/esp32-nesemu <br>
<img src=picture/wXkzmnB4Afzmn9jooHWbkSYQvjiZScMLIh3SqnrT.jpeg width=50% /><br>
## 关于外壳
外壳可以使用3d打印制作，如果你没有3d打印机的话也可以使用我hardware中的pcb作为外壳使用
<img src=picture/VfWKDiLhfaSmxtNrcTYDa89VPPqzpJ4SmHIMbbz3.jpeg width=50% />

## 参考工程
### https://oshwhub.com/micespring/esp32-nesemu
