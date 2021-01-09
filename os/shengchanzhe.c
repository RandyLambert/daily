#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
int a = 0;
int Max = 100;
void *xiao(void *arg){
    int x = 1000;
    while(x--){
        pthread_mutex_lock(&mutex);
        while(a <= 0){
            pthread_cond_wait(&cond,&mutex);  
        }
        usleep(500000);

        a--;
        printf("xiaofeizhe %d\n",a);
        if(a <= 100){
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);
        usleep(500000);
    }
}

void *sheng(void *arg){
    int x = 1000;
    while(x--){
        pthread_mutex_lock(&mutex);
        while(a >= Max){
            pthread_cond_wait(&cond,&mutex);
        }
        usleep(500000);
        a++;
        if(a > 0){
            pthread_cond_signal(&cond);
        }
        printf("shengchanzhe %d\n",a);
        pthread_mutex_unlock(&mutex);
        usleep(500000);
    }
}
int main()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t threadxiao;
    pthread_t threadsheng;
    pthread_create(&threadxiao,NULL,xiao,NULL);
    pthread_create(&threadsheng,NULL,sheng,NULL);
    pthread_join(threadxiao,NULL);
    pthread_join(threadsheng,NULL);
    printf("the answar %d\n",a);
    return 0;
}
