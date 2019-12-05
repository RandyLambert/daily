#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>
int main(){
    //一个程序运行一秒，实际上在用户态上不是一秒，
    //在进行系统调用时在内核态用的时间也很长
    //time的一秒是用户+内核
    //当printf时，在用户区和内核区进行多次切换，进行文件io操作，优化代码的重点，是优化的瓶颈，内核区占得时间长

    /* pid_t pid; */
    /* pid = fork(); */

    //alarm设置定时器（每个进程只有一个定时器）
    //使用了自然定时法
    //不受进程状态影响
    //参数为秒，当时间到达发出一个信号，slgalrm,终止进程
    //可以设置信号捕捉函数，进行其他事情
    int ret = alarm(5);
    printf("%d\n",ret);
    sleep(2);
    //重新设置定时器,在等两秒打印一下
    ret = alarm(1);
    printf("%d\n",ret);
    int i = 0;
    while(1){
        printf("%d\n",i++);
    }
    return 0;
}
