#include "unp.h"
void Time_Get(){

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket\n");
    }

    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13); //daytime server
    if(inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr) <= 0){
        perror("inet_pton\n");
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0)
        perror("connect error\n");

    return ;
}

void Read_Time(char recvline[]){
    int n = 0;
    while((n = read(sockfd,recvline,MAXLEN)) > 0){
        recvline[n] = 0;
        if(fputs(recvline,stdout) == EOF){
            perror("fput error\n");
        }
    }
    if(n < 0){
        perror("read error\n");
    }

}
