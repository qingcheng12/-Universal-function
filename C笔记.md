# 1. 可变参数宏

``` 
#define debug(fmt, ...) printf(fmt, __VA_ARGS__)  // GCC
__VA_ARGS__替换可变参数

#define debug2(fmt, args...) printf(fmt, args)   // GNU

#define debug3(fmt, ...) printf(fmt, ##__VA_ARGS__)  //可以接受无参数(变参为空), ## 屏蔽逗号

#define C(x)  #x   // 一个#将参数字符串化

``` 
