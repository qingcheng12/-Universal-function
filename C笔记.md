# 1. 可变参数宏

``` 
#define debug(fmt, ...) printf(fmt, __VA_ARGS__)  // GCC
__VA_ARGS__替换可变参数

#define debug2(fmt, args...) printf(fmt, args)   // GNU

#define debug3(fmt, ...) printf(fmt, ##__VA_ARGS__)  //可以接受无参数(变参为空), ## 屏蔽逗号

#define C(x)  #x   // 一个#将参数字符串化

``` 

# 2. vim IDE配置

https://blog.csdn.net/u012385733/article/details/79038973

https://blog.csdn.net/namecyf/article/details/7787479?utm_source=blogxgwz0

https://blog.csdn.net/guyue35/article/details/54412428

https://blog.csdn.net/eric_sunah/article/details/51028874

https://github.com/DemonCloud/dotfile


# 3. #Pragma 指令
在所有的预处理指令中，#Pragma 指令可能是最复杂的了，它的作用是设定编译器的状态或者是指示编译器完成一些特定的动作。#pragma指令对每个编译器给出了一个方法，在保持与C和C++语言完全兼容的情况下，给出主机或操作系统专有的特征。依据定义，编译指示是机器或操作系统专有的，且对于每个编译器都是不同的。

其格式一般为: #pragma  para。其中para为参数，下面来看一些常用的参数。

## (1) message参数
其使用方法为：  
   	 #pragma  message("消息文本")  
    当编译器遇到这条指令时就在编译输出窗口中将消息文本打印出来。  
    当我们在程序中定义了许多宏来控制源代码版本的时候，我们自己有可能都会忘记有没有正确的设置这些宏，
此时我们可以用这条指令在编译的时候就进行检查。假设我们希望判断自己有没有在源代码的什么地方定义了_X86这个宏,
可以用下面的方法:
!+




