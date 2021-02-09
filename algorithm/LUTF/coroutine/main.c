/*
 * @Date: 2020-11-30 21:54:37
 * @LastEditors: OBKoro1
 * @LastEditTime: 2020-12-02 17:45:17
 * @FilePath: /LibraryCodeComments/coroutine/main.c
 * @Auther: SShouxun
 * @GitHub: https://github.com/RandyLambert
 */
#include "coroutine.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
/**********************************************************************************/

struct args {
	int n;
};

static void
foo(struct schedule * S, void *ud) { // 协程运行函数
	struct args * arg = ud;
	int start = arg->n;
	int i;
	for (i=0;i<5;i++) {
		printf("coroutine %d : %d\n",coroutine_running(S) , start + i);
		// 切出当前协程
//		sleep(10);
		coroutine_yield(S);
	}
}

static void
test(struct schedule *S) {
	struct args arg1 = { 0 };
	struct args arg2 = { 100 };

	// 创建两个协程
	int co1 = coroutine_new(S, foo, &arg1);
	int co2 = coroutine_new(S, foo, &arg2);

	printf("main start\n");
	while (coroutine_status(S,co1) && coroutine_status(S,co2)) { // 当两个协程状态不为结束就不停的 resume 和 yield 
		// 使用协程co1
		coroutine_resume(S,co1);
		// 使用协程co2
		coroutine_resume(S,co2);
	} 
	printf("main end\n");
}
int main() {
	// 创建一个协程调度器s,此调度器用来统一管理全部的协程
	struct schedule * S = coroutine_open();
	//在test函数中创建两个协程co1和co2,不断反复的进行yield和resume协程,直到两个协程执行完毕
//	test(S);

	// 关闭协程调度器
//	coroutine_close(S);

/**************************************************/

    struct args arg1 = { 0 };
    struct args arg2 = { 100 };

    // 创建两个协程
    int co1 = coroutine_new(S, foo, &arg1);
    int co2 = coroutine_new(S, foo, &arg2);

    printf("main start\n");
    while (coroutine_status(S,co1) && coroutine_status(S,co2)) { // 当两个协程状态不为结束就不停的 resume 和 yield
        // 使用协程co1
        coroutine_resume(S,co1);
        // 使用协程co2
        coroutine_resume(S,co2);
    }
    printf("main end\n");

    printf("process id is %d  %p %p\n",getpid(), thread1, thread2);

    // 为两个线程分配stack空间。
    // 注意，线程的stack空间一定要独立，不然函数调用会冲突的。
    stack1 = (unsigned char *)calloc(1, 4096);
    stack2 = (unsigned char *)calloc(1, 4096);

    struct sigaction act;
    union sigval mysig;
    mysig.sival_ptr = S;

    int sig = SIGALRM;
    pid_t pid = getpid();
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = sig_schedule; // 三参数信号处理函数
    act.sa_flags = SA_SIGINFO;  // 信息传递开关

    if(sigaction(sig,&act,NULL) < 0) {
        printf("install sigal error\n");
    }

    signal(SIGINT, sig_start);
//    signal(SIGALRM, sig_schedule);
    pc[0] = (unsigned long)thread1;
    pc[1] = (unsigned long)thread2;

//    wait_start();
    while(1) {
        printf("wait for the signal\n");
        sigqueue(pid,sig,mysig);//向本进程发送信号，并传递附加信息
        sleep(2);
    }
	return 0;
}

