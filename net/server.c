#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int socketfd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_port = htons(4508);
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
    /* serv_addr.sin_addr.s_addr = INADDR_ANY; */

    if(bind(socketfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0){
        perror("bind");
    }
    listen(socketfd,8);

    struct sockaddr_in cli_addr;
    memset(&cli_addr,0,sizeof cli_addr);
    uint32_t cli_len;
    uint32_t fd = accept(socketfd,(struct sockaddr*)&cli_addr,&cli_len);

    char buf[1024];
    memset(buf,0,1024);
    while(1){
        int i;
        uint32_t len = read(fd,&i,4);
        
        if(len == 0){
            /* shutdown(fd,0); */
            close(fd);
        }else if(len < 0){
            perror("read\n");
        }else{
            printf("read :%d\n",i);
        }

        int x;
        printf("请输入你要发送的数字");
        scanf("%d",&x);
        getchar();
        len = write(fd,&x,sizeof(x));

    }

    return 0;
}

