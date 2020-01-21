#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *th_fun(void *arg){
    int *p = (int *)arg;
    printf("pid = %d\n",getpid());
    printf("thread id= %x\n",(unsigned int)pthread_self());
    printf("thread *arg = %d\n",*p);
    while(1){
        sleep(1);
    }
}
int main(){
    pthread_t tid;
    int n = 10;

    pthread_create(&tid,NULL,th_fun,(void *)&n);
    printf("mainpid = %d\n",getpid());
    printf("main thread id= %x\n",(unsigned int)pthread_self());
    pthread_cancel(tid); //不会直接退出线程tid，等待下一次系统调用才会死，如果没有进行系统调用，那么就一直会卡着
                        //或者使用pthread_testcancel()函数
    pthread_testcancel();
    while(1)
        sleep(10);
    return 0;
}

