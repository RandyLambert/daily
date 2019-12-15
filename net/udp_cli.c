#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
int main(int argv,char *argc[]){
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd == -1){
        perror("socket error");
        exit(0);
    }

    //初始化服务器的ip和端口
    struct sockaddr_in serv;
    memset(&serv,0,sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(atoi(argc[1]));
    inet_pton(AF_INET,"127.0.0.1",&serv.sin_addr.s_addr);
    //通信
    while(1){
        char buf[1024];
        scanf("%s",buf);
        //发送给谁不清楚，所以与send的区别就是sendto多了一个，因为不清楚地址的大小，还要对地址进行sizeof()
        sendto(fd,buf,strlen(buf)+1,0/*flag位*/,(struct sockaddr *)&serv,sizeof(serv));

        recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
        printf("recv buf:%s\n",buf);
    }

    close(fd);
    return 0;
}
