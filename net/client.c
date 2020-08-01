#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
int main()
{
    uint32_t socketfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(4508);
    connect(socketfd,(struct sockaddr*)&serv_addr,sizeof serv_addr);
    char buf[1024];
    memset(buf,0,sizeof(buf));
    while(1){
        int i = 0;
        scanf("%d",&i);
        getchar();
        i = write(socketfd,&i,sizeof i);
        if (i == -1){
            perror("write");
        }
        int b = 0;
        read(socketfd,&b,sizeof i);
        printf("read %d\n",b);
        memset(buf,0,1024);
    }
    return 0;
}

