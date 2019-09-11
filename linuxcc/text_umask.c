#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){

    umask(0); //不屏蔽任何权限
    if(creat("exam_681.text",S_IRWXU|S_IRWXG|S_IRWXO)<0){
        perror("creat");
        exit(1);
    }

    umask(S_IRWXO);
    if(creat("exam_682.text",S_IRWXG|S_IRWXU|S_IRWXO)<0){
        perror("creat");
        exit(1);
    }
    return 0;
}

