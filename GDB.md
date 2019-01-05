编译加-g

gcc -g -o xxx xxx.c 需要让二进制有调试信息
断点

    break 行号
    break 函数名
    info break 查看断点信息
    break xxx if xxx 条件断点
    condition 1 if xxx 条件断点

单步调试

    step 会进入函数内部，相当于VS的
    next 不会进入函数，相当于VS的

查看变量

    print xxx 打印变量出来
    watch xxx 当这个变量变化时会stop，并将变量打印出来

info

    info break
    info watch
    info locals

参考链接

https://www.ibm.com/developerworks/cn/linux/sdk/gdb/index.html 
https://zhuanlan.zhihu.com/p/29468840 
https://blog.csdn.net/taoyanqi8932/article/details/53385022
https://www.cnblogs.com/mingcaoyouxin/p/4225619.html
http://blog.jobbole.com/107759/

