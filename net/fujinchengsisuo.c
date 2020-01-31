#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
//多线程+多进程死锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *doit(void * arg){
    printf("pid = %d begin doit...\n",static_cast<int>(getpid()));
    pthread_mutex_lock(&mutex);
    struct timespec ts{2,0};
    nanosleep(&ts,NULL);
    pthread_mutex_unlock(&mutex);
    printf("pid = %d end doit ...\n",static_cast<int>(getpid()));
    return NULL;
}
int main(){
    printf("pid = %d Entering main...\n",static_cast<int>(getpid()));
    pthread_t tid;
    pthread_create(&tid,NULL,doit,NULL);
    //首先创建线程，线程调用了函数doit，在函数doit中获取了互斥量，
    //所以现在的锁阻塞在这里，线程睡眠两秒，其他线程如果进入这个函数会阻塞，这时
    //主线程在这之后睡眠一秒，这时子线程还没醒，依旧阻塞在子线程，而这时
    //主线程fork(),生成了子进程，这时的子进程的互斥量直接复制主进程的
    //所以状态是阻塞，他在去调用doit(),由于现在的子进程和父进程已经是两块
    //数据了，所以子进程没法被唤醒，导致死锁,出去ps一下就好了
    struct timespec ts = {1,0};
    nanosleep(&ts,NULL);
    if(fork() == 0){
        doit(NULL);
    }
    pthread_join(tid,NULL);
    printf("pid = %d exiting main...\n",static_cast<int>(getpid()));
    return 0;
}

