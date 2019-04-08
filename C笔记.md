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

![效果图](https://github.com/qingcheng12/Universal-function/blob/master/image/1.jpg)

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
