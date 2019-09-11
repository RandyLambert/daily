#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define PERMDS 0666
#define DUMMY 0
#define BUFSIZE 1024
int main(int argc,char *argv[]){
    
    int source_fd,target_id,num;
    char iobuffer[BUFSIZE];

    if(argc!=3){
        printf("this chengxu error\n");
        exit(1);
    }

    if((source_fd = open(*(argv+1),O_RDONLY,DUMMY))==-1){
        printf("source file open error!\n");
        exit(1);
    }

    if((target_id = open(*(argv+2),O_WRONLY|O_CREAT,PERMDS))==-1){
        printf("target file open error!\n");
        exit(1);
    }
    
    while((num = read(source_fd,iobuffer,BUFSIZE))>0){
        if(write(target_id,iobuffer,num)!=num){
            printf("target FILE open error\n");
            exit(0);
        }
    }
    close(target_id);
    close(source_fd);
    return 0;
}

