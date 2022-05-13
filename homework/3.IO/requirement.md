### homework 3

#### 1. 写一个拷贝函数

利用 Linux 系统调用(内核提供的函数) 写一个拷贝函数 `copy.c` 并使用`./src/english.txt`文件测试 , 可能使用的函数如下:

`open、close、read、write、perror`



#### 2. 模拟Linux下 `ls -l` 操作

使用 Linux 系统调用 `stat` 函数模拟`ls -l`操作，终端打印形如：`drwxrwxr-x 5 liu liu  4096 3月  23 08:55 desktop`



#### 3. 递归获取某个目录下所以普通文件个数

系统调用提示：`opendir、 readdir、 closedir`

