# 问题的出现及其解决

## 09.27

把其他没关的东西去除掉：spi time 

我把test所有的有关gpio.c去掉，发现，没毛病，能烧录

下一步，测试编译过程。换种方法编译

或者把.c文件去掉，用.h文件。这个得问问师兄，优先这一步，测试官方的库，是否有毛病

## 09.28

今天去问了下师兄，发现还有一个问题：stm8s.h的文件，原来有移植教程，但是我直接用删除的方式搞掉了那些东西，可能这个影响烧录，所以，现在我用师兄的教程，来试一试。

一个半小时过去了，还是没发现问题在哪里，总而言之，我觉得，问题是编译的顺序弄错了，别人一个c文件，什么问题都没有，连接两个文件，有点多问题.

## 09,29

这次可以烧录了，两个c文件都可以。以下是解决思路（这是10.08写的，所以只有思路）：

1. 库函数文件里面增加编译器的修改，添加SDCC编译器选项，具体教程在下面网站。

   https://blog.csdn.net/qq_40833810/article/details/105584401?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522160213322919725255523906%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=160213322919725255523906&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v28-1-105584401.pc_first_rank_v2_rank_v28&utm_term=sdcc+stm8&spm=1018.2118.3001.4187

2. makefile。

   ```makefile
   build/stm8s_spi.rel: source/FWLIB/src/stm8s_spi.c
   	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_spi.c -o build/stm8s_spi.rel 
   
   build/main.ihx: source/USER/main.c build/74hc595.rel
   	sdcc -mstm8 $(C_DEFS) $(C_INCLUDES) \
   source/USER/main.c \
   build/stm8s_gpio.rel \
   build/stm8s_clk.rel \
   build/74hc595.rel \
   build/stm8s_spi.rel \
   -o build/main.ihx 
   ```

   *编译spi时，如果使用到clk.h,一定要把clk.h的路径加入编译，否则，不能烧录*

## 10.08

昨天焊接好板子，师兄的电路设计有点缺陷，但无妨，只是灯会不稳定。有待我的spi改良。







