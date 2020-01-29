#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
//生产者消费者模型需要条件变量和锁互相配合使用
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
typedef struct _ProdInfo{
    int num;
    struct _ProdInfo *next;
}ProdInfo;

ProdInfo *head = NULL;
int begin = 0;
void *thr_producter(void *arg){
    //负责在链表上添加数据
    while(1){
        ProdInfo *prod = (ProdInfo *)malloc(sizeof(ProdInfo));
        prod->num = begin++;
        pthread_mutex_lock(&mutex);
        //add to list
        prod->next = head;
        head = prod;
        printf("------%s------self=%lu----%d\n",__FUNCTION__,pthread_self(),prod->num);
        pthread_mutex_unlock(&mutex);
        //发起通知
        pthread_cond_signal(&cond);
        sleep(1);
    }
    return NULL;
}

void *thr_customer(void *arg){
    ProdInfo *prod = NULL;
    while(1){
        //取链表数据
        pthread_mutex_lock(&mutex);
        while(head == NULL){ //多线程去吃饼的话，如果被别的线程吃到了饼，这里就为空了，所以要一直判断
            pthread_cond_wait(&cond,&mutex);
        }
        prod = head;
        head = head->next;
        printf("------%s------self=%lu----%d\n",__FUNCTION__,pthread_self(),prod->num);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%4);
        free(prod);
    }
    return NULL;
}
int main(){
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,thr_producter,NULL);
    pthread_create(&tid[1],NULL,thr_customer,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}

