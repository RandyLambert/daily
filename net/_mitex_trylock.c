#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
pthread_mutex_t mutex;

void *thr(void *arg){
    
    while(1){
        pthread_mutex_lock(&mutex);
        printf("hello word\n");
        sleep(5);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_mutex_init(&mutex,NULL);    
    pthread_t tid;
    pthread_create(&tid,NULL,thr,NULL);
    sleep(1);

    while(1){
        int ret = pthread_mutex_trylock(&mutex);
        if(ret > 0){
            printf("ret = %d,errors %s\n",ret,strerror(ret));
        }
        sleep(1);
    }
    return 0;
}

