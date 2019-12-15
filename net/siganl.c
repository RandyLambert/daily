#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
void myfunc(int signo){
    int pid;
    int stat;

    /* pid = wait(&stat); */
    /* printf("catch you signal:%d\n,child %d terminated,stat %d\n",signo,pid,stat); */

    //正确版本,防止阻塞住影响并发，使只有一两个可以被正常wait
    while( (pid = waitpid(-1,&stat,WNOHANG)) > 0 ){
        printf("catch you signal:%d\n,child %d terminated,stat %d\n",signo,pid,stat);
    }
    return ;
    /* sleep(3); */
}
int main(){
    //第一个参数是屏蔽的信号，第二个参数是函数指针，siganl去调用
    //信号产生就调用
    //捕捉ctrl+c
    //注册捕捉函数
    //那个函数指针是typedef void(*sighandler_t)(int)
    //sighandler_t signal (int signum,sighandler_t handler);
    
    signal(SIGCHLD,myfunc);

    int a = fork();
    if(a == 0){
        kill(getpid(),9);
    }
    else{
    }
    /* signal(SIGINT,SIG_DFL);//默认处理 */
    /* signal(SIGINT,SIG_IGN);//忽略 */

    while(1){};
    
    return 0;
}

