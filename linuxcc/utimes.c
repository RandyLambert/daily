#include <stdio.h>
#include <utime.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **argv){
    
    int fd;
    struct stat statbuf;
    struct utimbuf times;

    if(argc!=2){
        fprintf(stderr,"argc not enough");
        exit(0);
    }

    if((fd = open(*(argv+1),O_RDWR))==-1){
        printf("%s open failed.\n",argv[1]);
        exit(0);
    }

    if(stat(argv[1],&statbuf)<0)
        exit(0);

    if(ftruncate(fd,0)<0){ //jie duan wenjian
        exit(0);
    }

    printf("%s is truncated now\n",argv[1]);

    times.actime = statbuf.st_atime;
    times.modtime = statbuf.st_mtime;

    if(utime(argv[1],&times)==0){
        printf("utime() call successful\n");
    }
    else{
        printf("ERROR:utime( call failed )\n");
    }

    return 0;
}

