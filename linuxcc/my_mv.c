#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){
    if(argc!=3){
        fprintf(stderr,"cuole\n");
        exit(1);
    }

    if(rename(*(argv+1),*(argv+2))<0){
        perror("rename");
        exit(1);
    }
    return 0;
}

