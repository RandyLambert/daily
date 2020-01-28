#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //初始化锁，也可以用init函数初始化
//互斥量使用步骤
//初始化
//加锁
//执行逻辑--操作共享数据
//解锁
//注意事项
//加锁需要最小粒度，不要一直占用临界区

int sum = 0;
void *thr1(void *arg){
    while(1){

        //先上锁
        pthread_mutex_lock(&mutex);
        printf("hello");
        sleep(rand()%3);
        printf("would\n");
        //中间是临界区资源
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);//锁的粒度要大，如果sleep在解锁里面的话，
                        //相当于一上锁解锁，在直接上锁，所以另一个线程很难抢到资源
        //释放锁
    }
}

void *thr2(void *arg){
    while(1){

        pthread_mutex_lock(&mutex);
        printf("HELLO");
        sleep(rand()%3);
        printf("WOULD\n");
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
}
int main(){
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,thr1,NULL);
    pthread_create(&tid[1],NULL,thr2,NULL);


    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    
    return 0;
}
