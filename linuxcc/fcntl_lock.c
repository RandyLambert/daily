#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void my_err(const char * err_string,int line){
    fprintf(stderr,"line: %d ", line);
    perror(err_string);
    exit(1);
}

int lock_set(int fd,struct flock * lock){
    if(fcntl(fd,F_SETLK,lock) == 0){
        if(lock->l_type == F_RDLCK){
            printf("set read lock");
        }
    }
}
int main(){
    

    return 0;
}

