#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/stat.h>
int main(int argc,char *argv[])
{
    if(argc < 2){
        printf("eg:./a.out port\n");
        exit(1);
    }

    int port = atoi(argv[1]);
    //创建一个套接字
    int fd = socket(AF_INET,SOCK_STREAM,0);
    
    //链接服务器
    struct sockaddr_in serv;
    memset(&serv,0,sizeof(serv));

    //int inet_pton(int af,const char *src,void *dst) 第一个参数AF_INFT 第二个是ip地址点分十进制 第三个是存储网络字节序的数字
    serv.sin_port = htons(port); //从电脑转成网络字节序 小转到大
    inet_pton(AF_INET,"127.0.0.1",&serv.sin_addr.s_addr);
    serv.sin_family = AF_INET;
    
    if(connect(fd,(struct sockaddr*)&serv,sizeof(serv)) < 0){
        perror("connect\n");
        exit(1);
    }

    while(1){
        
        //发送数据
        char buf[1024];
        fgets(buf,sizeof(buf),stdin);
        ssize_t len;
        while((len = write(fd,buf,sizeof(buf))) > 0){

        }

        if(len == -1){
            perror("write\n");
            exit(1);
        }

        while((len = read(fd,buf,sizeof(buf))) > 0){
            printf("%s",buf);
        }

        if(len == -1){
            perror("read\n");
            exit(1);
        }
    }
    return 0;
}
