***  
# 1. 可变参数宏

``` C
#define debug(fmt, ...) printf(fmt, __VA_ARGS__)  // GCC
__VA_ARGS__替换可变参数  

#define debug2(fmt, args...) printf(fmt, args)   // GNU

#define debug3(fmt, ...) printf(fmt, ##__VA_ARGS__)  //可以接受无参数(变参为空), ## 屏蔽逗号

#define C(x)  #x   // 一个#将参数字符串化

``` 
*** 
# 2. vim IDE配置
[vim + winmanager] : https://blog.csdn.net/u012385733/article/details/79038973

[vim配置及插件安装管理（超级详细)] : https://blog.csdn.net/namecyf/article/details/7787479?utm_source=blogxgwz0

[Vim 实用插件推荐] : https://blog.csdn.net/guyue35/article/details/54412428

[Ubuntu 下 vim+Ctags+Taglist+WinManager工具的安装] : https://blog.csdn.net/eric_sunah/article/details/51028874

[配置实例] : https://github.com/DemonCloud/dotfile

***  
# 3. #Pragma 指令
在所有的预处理指令中， '#Pragma' 指令可能是最复杂的了，它的作用是设定编译器的状态或者是指示编译器完成一些特定的动作。#pragma指令对每个编译器给出了一个方法，在保持与C和C++语言完全兼容的情况下，给出主机或操作系统专有的特征。依据定义，编译指示是机器或操作系统专有的，且对于每个编译器都是不同的。  
其格式一般为:  
``` c
#pragma  para  
``` 
其中para为参数，下面来看一些常用的参数。  

## (1) message参数
其使用方法为：  
   	 #pragma  message("消息文本")  
    当编译器遇到这条指令时就在编译输出窗口中将消息文本打印出来。  
    当我们在程序中定义了许多宏来控制源代码版本的时候，我们自己有可能都会忘记有没有正确的设置这些宏，
此时我们可以用这条指令在编译的时候就进行检查。假设我们希望判断自己有没有在源代码的什么地方定义了_X86这个宏,
可以用下面的方法:

<div align=center><img src="https://github.com/qingcheng12/Universal-function/blob/master/image/1.jpg" /></div>

我们定义了_X86这个宏以后，应用程序在编译时就会在编译输出窗口里显示"_86  macro  activated!"。

<div align=center><img src="https://github.com/qingcheng12/Universal-function/blob/master/image/2.jpg" /></div>

## (2) once参数

``` #pragma one``` 用于保证头文件只被编译一次  
``` #pragma one``` 与编译器相关，不一定被支持
在工程中的使用：
``` c
#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_

#pragma once

// source code
	
#endif
``` 

## (3) warning参数  
``` c
#pragma  warning( disable: 4507 34; once: 4385; error: 164 )
    等价于：  
    #pragma  warning( disable: 4507 34 )    //  不显示4507和34号警告信息  
    #pragma  warning( once: 4385 )          //  4385号警告信息仅报告一次  
    #pragma  warning( error: 164 )          //  把164号警告信息作为一个错误。 
同时这个pragma  warning  也支持如下格式：  
    #pragma  warning( push [, n ] )  
    #pragma  warning( pop )  
    这里n代表一个警告等级(1---4)。  
    #pragma  warning( push )保存所有警告信息的现有的警告状态。  
    #pragma  warning( push, n )保存所有警告信息的现有的警告状态，并且把全局警告等级设定为n。    
    #pragma  warning( pop )向栈中弹出最后一个警告信息，在入栈和出栈之间所作的一切改动取消。
例如：  
    #pragma  warning( push )  
    #pragma  warning( disable: 4705 )  
    #pragma  warning( disable: 4706 )  
    #pragma  warning( disable: 4707 )  
    //.......  
    #pragma  warning(  pop  )    
    在这段代码的最后，重新保存所有的警告信息(包括4705，4706和4707)。 
``` 
[#pragma的用法] : https://www.cnblogs.com/fnlingnzb-learner/p/5854494.html  
[#pragma使用分析] : https://blog.csdn.net/jacob__lei/article/details/79475926#t7

***  
# 4. GDB调试器  
``` c
list(l)行号：显示某行源代码，每次列十行（上5行下5行）  
list(l) 函数名：列出某函数源代码（上2行下8行）  
break(b) 行号：在某一行设置断点  
break(b) 函数名：在某个函数开头设置断点  
info break：查看断点信息  
info(i) breakpoints：查看当前设置了哪些断点
delete(del) breakpoints：删除所有断点
delete(del) breakpoints n：删除序号为n的断点
disable breakpoints：禁用断点
enable breakpoints：启用断点
run(r)：运行程序
next(n)：单条执行
step(s)：进入函数调用
continue(c)：继续执行，非单步执行
p 变量：打印变量值
breaktrace(bt)：查看函数堆栈
frame 0：查看栈顶
frame 1：查看第二层栈
disassemble 函数名：查看函数汇编
quit(q)：退出gdb调试
list　　 显示当前行后面的源程序
list -   显示当前行前面的源程序
``` 
***  
# 5. 调试打印 
```c
// control  print switch
#ifdef debug
#define __DEBUG
#endif

#ifdef __DEBUG

#define d_printf(f, a...)                                       \
    do {                                                          \
        { fprintf(stderr, "%s(%d): " f, __func__, __LINE__, ## a); } \
    } while (0)
#else
#define d_printf(f, a...)
#endif

#define ERR_EXIT(m)	\
	do	\
	{	\
		perror(m);	\
		exit(EXIT_FAILURE);	\
	} while(0)

// debug宏作为调试开关
#ifdef DEBUG
#define DBGprint(...) printf(__VA_ARGS__)
#else
#define DBGprint(...)
#endif

int main(void)
{
    int i, sum;


    for (i = 1, sum = 0; i <= 5; i++)
    {
        sum += i;
        DBGprint("sum += %d is %d\n", i, sum);
    }
    printf("total sum is %d\n", sum);
}


//  一些调试输出的宏
#define ERROR(...) /   
do{ /   
    fprintf(stderr, "[ERROR  ]%s %s(Line %d): ",__FILE__,__FUNCTION__,__LINE__); /   
    fprintf(stderr, __VA_ARGS__); /   
}while(0)   


#define WARNING(...) /   
do{ /   
    fprintf(stdout, "[WARNING]%s %s(Line %d): ",__FILE__,__FUNCTION__,__LINE__); /   
    fprintf(stdout, __VA_ARGS__); /   
}while(0)   


#define INFO(...) /   
do{ /   
    fprintf(stdout, "[INFO  ]%s %s(Line %d): ",__FILE__,__FUNCTION__,__LINE__); /   
    fprintf(stdout, __VA_ARGS__); /   
}while(0)   
```
***  

# 6. gcc的as汇编工具
## （1） 宏
as也支持宏。但是，汇编程序中所包含的头文件不能包含C语言中的函数、 数据结构等内 容 ， 而只能定义常盘、汇编指令等汇编器认识的内容。  
宏的存在说明 as 在编译时存在预处理这一步骤 ， 这一点与编译 C 程序时的预处理是相似的。但读者需要注意 ， 如果所编写的汇编代码中包含宏指令的话，则一定要将源文件的后缀名使用大写的 S。汇编文件的后缀不能是s。

## （2） 汇编指令
由于AT&T格式中操作数内存大小是通过在汇编指令后面加上一个字母来表示的，因此读者在查看 x86 处理器的指令手册时需要根据情况除去后面的那个字母， 否则无论如何在孚册中也找不到对应的指令。后缀字母“b(byte）”、“w(word）＂、“ l（long）”、“q(quardruple）”分别表示单字节、 双字节、 四字节和八字节。  

|差异点|AT&T语法|Intel语法|
|------|---|---|
|寄存器立即数的表达|总是在寄存器名前加一个“%”||
|常数和立即数的表达|pushl $4|push 4|
|操作数的源与目的的表达|addl $4, %eax|add eax, 4|
|操作数内存大小的表达|movb foo, %al|mov al , byte ptr foo|
|内存引用方式|movl -4(%esp), %ecx|mov ecx, [esp-4]|
|内存引用方式|movl 4(%esp), %ecx|mov ecx, [esp+4]|

# 7. 程序的结构
程序，是被分成段（ section ）加以管理的 。 在程序被加载到内存中运行之前，各段是放在程序文件中的。  
当程序文件中所必需的段被加载到内存中后 ， 将通过运行指令来处理相应的数据。有些数据来源于程序文件中的段，有些则是动态生成的。动态生成的数据可以来自栈（stack）或堆（heap)。  

## （1） 段（section）  
一个程序一般会有这几个段 ： `.text`、 `.data` 和`.bss` 段。  
### 指令段
编译所生成的指令，就是存放在.text 段中。从C源程序的角度来看，.text中存放的是函数的机器指令实现。如果处理器有内存管理单元，那么可执行程序被加载到内存以后，通常会将.text 段所在的内存空间设置为只读，以保护 .text 中的代码不会因为程序出错。
### 数据段
处理器处理的数据是放在`.data、.bss 和J.rdata`段的。  
对于初始化不为0的变量，编译器会将它放入.data 段中，而对于初始化为0的变量会被放入.bss段中。实际上，没有初始化的变量也像初始化为0的变量那样被入.bss 段中。当程序被引导加载器加载以后，引导加载器将执行权交给被加载程序之前，它会把.bss 段所在的内存区全部初始化为 0。这就是为什么没有设置初始化值的全局变母其值却总是为0的缘故。  
.rdata 是用来存放只读的已初始化变量的。当在源程序中的 g_char 变量前面加了const后编译器就知道这个字符串是只读的，所以将其分配到.rdata 段中。与.data 段不同的是，对于有内存管理单元的系统，.rdata段通常也会采用内存管理单元进行只读保护。

程序中的内容是通过段进行分类管理的 。 在传统的三个段中， .text 段用于存放处理器指令， .data 段用于存放初始化的全局和静态变量， .bss 段则用于存放初始化为 0 和未初始化的全局和静态变量。 一个程序不管有多少个段 ， 各段都属于和序、数据和调试信息三大类中的一种。  

栈为函数参数和局部变量提供存储空间 。 局部变量所占用的内存空间是由编译者苦生成的指令自动分配与释放的， 因此不存在像堆那样的内存泄漏问题。在多任务环境中 ， 由于各任务的函数调用路径可以不同，所以每一个任务都有属于自己的战空间。

堆中的内存在没有被分配出来之前，是斗在个系统所共卒的。要从堆中获得内存，必须通过函数调用来实现。 如果从堆中所分配获得的内存不再需要使用了，则必须调用相应的函数进行释放，否则会产生内存泄漏。


# 7. Linux工具快速教程
书籍的分类也非常不错，分为了三个大目录  
第一部分为基础篇，介绍我们工作中常用的工具的高频用法；  
第二部分为进阶篇，介绍的工具更多的适合程序员使用，分为程序构建、程序调试及程序优化；  
第三部分是工具参考篇，主要介绍实用工具的用法和实例；相比第一二部分，这里针对每个工具的介绍更全面；  
https://linuxtools-rst.readthedocs.io/zh_CN/latest/index.html  
https://github.com/me115/linuxtools_rst  
