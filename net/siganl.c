#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void myfunc(int no){
    printf("catch you signal:%d\n",no);
    /* sleep(3); */
}
int main(){
    //第一个参数是屏蔽的信号，第二个参数是函数指针，siganl去调用
    //信号产生就调用
    //捕捉ctrl+c
    //注册捕捉函数
    //那个函数指针是typedef void(*sighandler_t)(int)
    //sighandler_t signal (int signum,sighandler_t handler);
    signal(SIGINT,myfunc);
    /* signal(SIGINT,SIG_DFL);//默认处理 */
    /* signal(SIGINT,SIG_IGN);//忽略 */


    while(1){};
    
    return 0;
}

