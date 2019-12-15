#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(int argc,const char * argv[]){
    if(argc < 2){
        printf("eg:./a.out port\n");
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    int port = atoi(argv[1]);
    int socketfd = socket(AF_INET,SOCK_STREAM,0);


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
    
    bind(socketfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    listen(socketfd,8);
    //最大的文件描述符
    int maxfd = socketfd;
    struct sockaddr_in cli_addr;
    //reads原始的，temp临时的
    fd_set reads,temp;
    socklen_t cli_len = sizeof(cli_addr);
    memset(&reads,0,sizeof(fd_set));
    memset(&temp,0,sizeof(fd_set));

    FD_SET(socketfd,&reads);
    while(1){
        temp = reads;
        int ret = select(maxfd+1,&temp,NULL,NULL,NULL);
        if(ret == -1){
            perror("select error\n");
            exit(1);
        }


        //客户端发起了新的链接
        if(FD_ISSET(socketfd,&temp)){
            printf("dasdadddddddddddddddddd\n");
            //接受连接请求 accept不阻塞
            int cfd = accept(socketfd,(struct sockaddr *)&cli_addr,&cli_len);
            if(cfd == -1){
                perror("accept\n");
                exit(-1);
            }
            
            //将cfd加入到到带检测的妒忌和中 在喜爱一次记就可以检测到
            
            FD_SET(cfd,&reads);
            maxfd = maxfd < cfd ? cfd:maxfd;
        }
        //已经链接的客户端有数据到达
        for(int i = socketfd+1;i <= maxfd;i++){
            char buf[1];
            if(FD_ISSET(socketfd,&temp)){
                
                int len = read(i,buf,sizeof(buf));

                if(len == -1){
                    perror("recv error\n");
                    exit(0);
                }
                else if(len == 0){
                    printf("客户端已经断开链接了\n");
                    close(i);
                    FD_CLR(i,&reads);
                }
            }
            else{
                printf("recv buf:%s\n",buf);
                /* write(i,buf,strlen(buf)+1); */
            }

        }

    }
    return 0;
}
