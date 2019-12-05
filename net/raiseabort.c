#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
int main(){

    pid_t pid;
    pid = fork();

    if(pid == 0){
        sleep(1);
        /* raise(9); */
        //子进程给自己发信号
        //调用abort()函数，abort函数所在进程就死了
        //
        while(1){
            abort();
            //6 异常终止信号，直接死
        }
    }
    else{
        //父进程，回收子进程资源
        //raise,给自己发信号
        //kill给谁都能发
        //父进程可以回收子进程的pcb
        //当子进程死了就能查看子进程当时状态
        int s;
        pid_t wpid = wait(&s);
        printf("child is died %d\n",wpid);
        if(WIFSIGNALED(s)){//是否被信号弄死的
            printf("died by signal %d\n",WTERMSIG(s));
        }
    }
    
    return 0;
}
