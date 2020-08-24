#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
using namespace std;
int main()
{
    int fd = open("/home/",O_RDWR);
    if(-1 == fd){
        perror("Error:"),exit(-1);
    }
    puts("打开文件成功");
    char buf[4096];
    memset(buf,0,sizeof(buf));
    int size = read(fd,buf,sizeof(buf));
    cout<<buf<<endl;
    close(fd);
    return 0;
}
