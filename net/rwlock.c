#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
int beginnum = 1000;

void *thr_write(void *arg){

    while(1){
        pthread_rwlock_wrlock(&rwlock);
        printf("----%s----self----%lu----%d\n",__FUNCTION__,pthread_self(),++beginnum);
        usleep(3000); //模拟占用时间
        pthread_rwlock_unlock(&rwlock);
        usleep(4000); 
    }
    return NULL;
}

void *thr_read(void *arg){
    while(1){
        pthread_rwlock_rdlock(&rwlock);
        printf("----%s----self----%lu----%d\n",__FUNCTION__,pthread_self(),beginnum);
        usleep(2000); //模拟占用时间
        pthread_rwlock_unlock(&rwlock);
        usleep(2000);
    }
    return NULL;
}
int main(){
    int n = 8,i = 0;
    pthread_t tid[8]; //5-read,3-write
    for(i = 0;i < 5;i++){
        pthread_create(&tid[i],NULL,thr_read,NULL);
    } 
    for(;i<n;i++){
        pthread_create(&tid[i],NULL,thr_write,NULL);
    }

    for(int i = 0;i < 8;i++){
        pthread_join(tid[i],NULL);
    }
    return 0;
}

