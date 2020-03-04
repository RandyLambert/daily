#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int main(){
    int fd;
    /* if((fd = open("example_62.c",O_CREAT|O_EXCL,S_IRUSR |S_IWUSR)) == -1){ */
    /*     /1* if((fd = creat("example_62.c",S_IRWXU)) == -1){ *1/ */
    /*         perror("open"); */
    /*         /1* printf("open:%s    with errno:%d\n",strerror(errno),errno); *1/ */
    /*         exit(1); */
    /* } */
    /* else{ */
    /*         printf("creat accept\n"); */
    /* } */
    /* close(fd); */


    if((fd = open("test",O_WRONLY,0777)) == -1)
    {
        perror("errno open");
    }
    close(fd);
    return 0;
}

