#include <stdio.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argv,char *argc[]){

    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd == -1){
        perror("socket");
    }

    struct sockaddr_in  serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(atoi(argc[1]));
    inet_pton(AF_INET,"127.0.0.1",&serv.sin_addr.s_addr);

    bind(fd,(struct sockaddr *)&serv,sizeof(serv));

    while(1){
        char buf[1024] = {0};
        struct sockaddr_in recv;
        socklen_t socketlen;
        ssize_t recvlen = recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr *)&recv,&socketlen);
        write(STDOUT_FILENO,buf,sizeof(buf));
        putchar('\n');
        char ip[64] = {0};
        printf("new client ip : %s\n port: %d\n",
               inet_ntop(AF_INET,&recv.sin_addr.s_addr,ip,sizeof(ip)),ntohs(recv.sin_port));
        //会写数据
        
        sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr *)&recv,sizeof(recv));
    }

    close(fd);
    
    return 0;
}

