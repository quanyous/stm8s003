# makefile学习笔记

makefile是用于一键make命令的小工具，可以批量执行许多命令，这样就能省下很多一行一行敲命令的时间。这都得益于makefile开发者的强大，也很感谢带（hai) 我入坑的师兄。现在开始学习！

## makefile的基本语法

```makefile
target ... : prerequisites ...
command
...
...
```

* target : 我所要生成的文件
* prerequisites : 目标文件，就是源文件
* command ：命令

## 变量的运用

```makefile
objects — main.o kbd.o comand-o display.o 
filez. o 
edit S(objects) 
cc —o S (objects) 
```

##  自动推导之隐晦规则：

![](https://i.loli.net/2020/10/08/jhp6r8VkCoJ7s5y.png)

## 常用的一键删除功能

![](https://i.loli.net/2020/10/08/OSseFbdh3zvuNX2.png)

## 应用其他的makefile(功能很强大，但现在暂时用不上)

![](https://i.loli.net/2020/10/08/L4j1BTFg2YuzOiK.png)



## *3个通配符*

![](https://i.loli.net/2020/10/08/1zW7wjhTn4l6AbY.png)

## 变量与通配符之间的展开误解

![](https://i.loli.net/2020/10/08/P26ueFrlWf4I3OV.png)



## 文件搜寻

1. 第一种：

![](https://i.loli.net/2020/10/08/CBq1W2IkzfYgmoF.png)

2. 第二种：

   ![](https://i.loli.net/2020/10/08/CNx3cermYRtS2Bj.png)

## 一个很迷的自动化$@:

![](https://i.loli.net/2020/10/08/bzDfC36NAjldvrs.png)



## 静态模式：

* 现在只知道用于一个同名字的文件进行处理编译。

![](https://i.loli.net/2020/10/08/vpRMSNkTfxlX26K.png)