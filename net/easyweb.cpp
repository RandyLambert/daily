#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sendfile.h>
#include <assert.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string.h>
#define MYPORT 8888
#define BUFSIZE 1025
using std::cout;
using std::cin;
using std::endl;

int main(){

    struct sockaddr_in ads; //设置地址
    bzero(&ads,sizeof(ads));
    ads.sin_family = AF_INET; //ipv4
    ads.sin_port = htons(MYPORT); //将主机字节序转换为网络字节序 小端转大端
    ads.sin_addr.s_addr = htonl(INADDR_ANY); //本机地址
    int sid = socket(AF_INET,SOCK_STREAM,0); //设置套接字
    assert(sid >= 0); //如果失效
    cout<< "socket successful" <<endl;


    int bind_ok = bind(sid,(struct sockaddr *)&ads,sizeof(struct sockaddr));
    //绑定了ip地址和套接字 那就可以接收了
    assert(bind_ok != -1);
    int listen_ok = listen(sid,10); //开始监听是否有链接
    assert(listen_ok != -1);
    cout<< "listen successful" <<endl;


    while(1){ //不断执行
        struct sockaddr_in client;
        socklen_t client_addrlength = sizeof(client);
        int connfd = accept(sid,(struct sockaddr *)&client, &client_addrlength);
        //一直接收，那个地址存储接受的信息来自的地址
        if(connfd < 0){
            std::cerr<<"errno"<<endl;
        }
        else{
            char res[BUFSIZE];
            std::string now = "hhhhhhhh";
            recv(connfd,res,1024,0);  //存储的在这里面，在这里接受信息
            cout<<"successful"<<endl;
            char buf[520] = "HTTP/1.1 200 ok\r\nconnection: close\r\n\r\n";//HTTP响应
            int s = send(connfd, buf,strlen(buf),0); //发送响应
            /* send(connfd,now.c_str(),sizeof(now.c_str()),0); */
            int fd = open("hello.html",O_RDONLY); //消息体 也可以线程别的文件

            /*
             *O_RDONLY read only 只读
             *O_WRONLY writr only 只写
             *O_RDWR read write 可读可写
             *O_TRUNC 若文件存在这长度结尾0（属性不变）
             */
            sendfile(connfd,fd,NULL,2500); //0拷贝发送消息体 
            close(connfd);
        }
   }

    return 0;
}

