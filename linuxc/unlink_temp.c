#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void my_err(char *string,int hang){
    fprintf(stderr,"error in %d",hang);
    perror(string);
    exit(1);
}
int main(){
    int fd;
    char buf[32];

    if((fd = open("tempp",O_RDWR|O_CREAT,S_IRWXU)) < 0){
        my_err("open",__LINE__);
    }
    if(unlink("tempp") < 0){
        my_err("unlink",__LINE__);
    }

    printf("unlink accept\n");

    if(write(fd,"dada",5)<0){
        my_err("write",__LINE__);
    }

    if(read(fd,buf,5)<0){
        my_err("read",__LINE__);
    }

    printf("%s\n",buf);
    return 0;
}

