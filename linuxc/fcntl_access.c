#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void my_err(const char * err_string,int line){
    fprintf(stderr,"lind:%d ",line);
    perror(err_string);
    exit(1);
}
int main(){
    int ret,access_mode,fd;

    if((fd = open("example_64",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU)) == -1){
        my_err("open",__LINE__);
    }

    //设置打开方式
    if((ret = fcntl(fd,F_SETFL,O_APPEND)) < 0){
        my_err("fcntl",__LINE__);
    }

    //获取文件打开方式
    
    if((ret = fcntl(fd,F_GETFL,0)) < 0){
        my_err("fcntl",__LINE__);
    }

    access_mode = ret & O_ACCMODE;
    if(access_mode == O_RDONLY){
        printf("example_64 accessmode :readonly");
    }
    else if(access_mode == O_WRONLY){
        printf("example_64 accessmode :writeonly");
    }
    else if(access_mode == O_RDWR){
        printf("example_64 accessmode :write+read");     
    }

    if(ret & O_APPEND){
        printf( " ,append" );
    }
    if(ret & O_NONBLOCK){
        printf(" ,noblock");
    }
    if(ret & O_SYNC){
        printf(" ,sync");
    }

    putchar('\n');
    
    return 0;
}

