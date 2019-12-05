#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
int main(){

    pid_t pid;
    pid = fork();

    if(pid == 0){
        sleep(2);
        kill(getppid(),9);
        //所有进程pid都大于0
        //当第一个参数为0时，杀死同一进程组的所有进程
        //当第一个参数大与0时，杀死了该进程，不能杀死你权限不够的进程
        //当小于-1时，杀死绝对值里面的组里面进程
        //当为-1时，杀死所有能杀的进程
        //子进程无条件杀死父进程
    }
    else{
        while(1){
            printf("ffffffpid = %d\n",getpid());
            usleep(100000);
        };
    }
    
    return 0;
}
