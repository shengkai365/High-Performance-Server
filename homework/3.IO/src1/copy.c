/*  
    #include <unistd.h>
    ssize_t read(int fd, void *buf, size_t count);
        参数：
            - fd：文件描述符，open得到的，通过这个文件描述符操作某个文件
            - buf：需要读取数据存放的地方，数组的地址（传出参数）
            - count：指定的数组的大小
        返回值：
            - 成功：
                >0: 返回实际的读取到的字节数
                =0：文件已经读取完了
            - 失败：-1 ，并且设置errno

    #include <unistd.h>
    ssize_t write(int fd, const void *buf, size_t count);
        参数：
            - fd：文件描述符，open得到的，通过这个文件描述符操作某个文件
            - buf：要往磁盘写入的数据，数据
            - count：要写的数据的实际的大小
        返回值：
            成功：实际写入的字节数
            失败：返回-1，并设置errno
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // open
#include <stdio.h> // perror
#include <unistd.h>// read、write

int main()
{
    // 1.读取源文件
    int src_fd = open("english.txt", O_RDONLY);
    if (src_fd == -1)
    {
        perror("open");
    }

    // 2.创建拷贝文件
    int cp_fd = open("copy.txt", O_WRONLY | O_CREAT, 0666);
    if (cp_fd == -1)
    {
        perror("open");
    }

    // 3.循环拷贝
    char buf[1024] = {0};
    int len = 0;
    while (len = read(src_fd, buf, sizeof(buf)))
    {
        write(cp_fd, buf, len);
    }

    // 4.关闭文件
    close(src_fd);
    close(cp_fd);

    return 0;
}