#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

void *th_fun(void *arg){
    int *p = (int *)arg;
    printf("pid = %d\n",getpid());
    printf("thread id= %x\n",(unsigned int)pthread_self());
    printf("thread *arg = %d\n",*p);
    /* pthread_detach(pthread_self()); */
    return NULL;
}

int is_thread_alive(pthread_t tid)
{
    int pthread_kill_err;
    pthread_kill_err = pthread_kill(tid,0);
    if(pthread_kill_err == ESRCH)
    {
        printf("线程不存在\n");
        return 0;
    }
    else if(pthread_kill_err == EINVAL)
    {
        printf("线程不合法\n");
        return 0;
    }
    else
        return 1;
}
int main(){
    pthread_t tid;
    int n = 10;

    pthread_create(&tid,NULL,th_fun,(void *)&n);
    pthread_detach(tid);
    printf("mainpid = %d\n",getpid());
    printf("not main thread id= %x\n",(unsigned int)tid);
    printf("main thread id= %x\n",(unsigned int)pthread_self());
    
    sleep(5);
    is_thread_alive(tid);
    int err = pthread_join(tid,NULL);
    fprintf(stderr, "thread %s\n", strerror(err));
    is_thread_alive(tid);

    return 0;
}

