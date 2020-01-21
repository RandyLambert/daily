#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *th_fun(void *arg){
    int *p = (int *)arg;
    printf("pid = %d\n",getpid());
    printf("thread id= %x\n",(unsigned int)pthread_self());
    printf("thread *arg = %d\n",*p);
}
int main(){
    pthread_t tid;
    int n = 10;

    pthread_create(&tid,NULL,th_fun,(void *)&n);
    printf("mainpid = %d\n",getpid());
    printf("main thread id= %x\n",(unsigned int)pthread_self());
    sleep(10);
    return 0;
}

