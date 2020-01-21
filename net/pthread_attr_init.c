#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
void *th_fun(void *arg){
    int n = 10;
    while(n--){
        printf("%x %d\n",pthread_self(),n);
        sleep(1);
    }
    return (void *)1;
}
int main(){
    pthread_t tid;
    pthread_attr_t attr; //attr里面是垃圾值

    pthread_attr_init(&attr); //attr里面保存的是创建线程的默认属性
    //int detachrstate : PTHREAD_CREADE_DETACHED PTHREAD_CREADE_JOINABLE
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED); //设置线程为分离属性

    pthread_create(&tid,&attr,th_fun,NULL);

    int err = pthread_join(tid,NULL);
    while(1){
        if(err != 0){
            printf("%s\n",strerror(err));
            pthread_exit((void*)1);
        }
    }

    return 0;
}
