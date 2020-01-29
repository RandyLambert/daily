#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
sem_t blank,xfull;
#define _SEM_CNT_ 5
int queue[_SEM_CNT_]; //模拟饼框
int beginnum = 100;

void *thr_producter(void *arg){
    int i = 0;
    while(1){
        sem_wait(&blank); //申请资源 blank++
        printf("=====%s====self==%lu===num===%d\n",__FUNCTION__,pthread_self(),beginnum);  
        queue[(i++)%_SEM_CNT_] = beginnum++;  
        sem_post(&xfull); //xfull++
        sleep(rand()%3);
    }
    return NULL; 
}

void *thr_customer(void *arg){

    int num= 0;
    int i = 0;
    while(1){
        sem_wait(&xfull);
        num = queue[(i++)%_SEM_CNT_];
        printf("----%s----self--%lu----num----%d\n",__FUNCTION__,pthread_self(),num);
        sem_wait(&blank);
        sleep(rand()%3);
    }
    return NULL;
}


int main(){
    sem_init(&blank,0,_SEM_CNT_);
    sem_init(&xfull,0,0);//消费者默认没有产品
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,thr_producter,NULL);
    pthread_create(&tid[1],NULL,thr_customer,NULL);

    
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    sem_destroy(&blank);
    sem_destroy(&xfull);
    return 0;
}

