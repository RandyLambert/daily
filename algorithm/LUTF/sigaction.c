#include <signal.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coroutine/coroutine.h"
struct xxx{
    int a;
};
void func(int signum,siginfo_t *info,void *myact)
{
	printf("sssss %zu\n ",((struct schedule*)((*info).si_ptr)));
}

void func2(int signum,siginfo_t *info,void *myact)
{
    printf("%s\n ",(char*)((*info).si_ptr));
}

int main(int argc,char**argv)
{
    // 创建一个协程调度器s,此调度器用来统一管理全部的协程
    struct schedule *S = coroutine_open();

    struct sigaction act;
//	struct xxx b;
//	b.a = 12;
	union sigval mysig;
//	mysig.sival_ptr = "this is the data !\n";
//    mysig.sival_ptr = &b;
	mysig.sival_ptr = S;
	printf("%d\n",S->cap);
	int sig = 2; 
	pid_t pid = pid=getpid();

	sigemptyset(&act.sa_mask);
	act.sa_sigaction=func;//三参数信号处理函数
	act.sa_flags=SA_SIGINFO;//信息传递开关

	if(sigaction(sig,&act,NULL) < 0) {
		printf("install sigal error\n");
	}
	
	while(1) {
		sleep(1);
		printf("wait for the signal\n");
		sigqueue(pid,sig,mysig);//向本进程发送信号，并传递附加信息
	}
}

