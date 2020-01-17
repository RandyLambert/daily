#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define false 0
#define true 1
#define DEFAULT_TIME 10 //十秒检查一次
#define MIN_WAIT_TASK_NUM 10 //如果queue_size > MIN_WAIT_TASK_NUM添加新的线程到线程池
#define DEFAULT_THREAD_VARY 10 //每次创建销毁线程的个数
#define true 1
#define false 0


/*各子线程任务结构体*/  
typedef struct{
    void *(*function)(void *); //函数指针做回调函数
    void *arg;
}threadpool_task_t;


/*线程池结构体*/
struct threadpool_t {
    pthread_mutex_t lock;   /*用于锁住本结构体*/
    pthread_mutex_t thread_counter ;    /*记录忙状态线程个数de琐-- busy_thr_num*/

    pthread_cond_t queue_not_full;    /*当任务队列满时,添加任务的线程阻塞*/
    pthread_cond_t queue_not_empty;    /*任务队列里不为空时,通知等待任务的线程*/
    pthread_t *threads;    /*存放线程池中每个线程的tid。数组*/
    pthread_t adjust_tid;    /*存管理线程tid */
    threadpool_task_t *task_queue;    /*任务队列(数组首地址) */

    int min_thr_num;    /*线程池最小线程数*/
    int max_thr_num;    /* 线程池最大线程数*/
    int live_thr_num;    /*当前存活线程个数*/
    int busy_thr_num;    /*忙状态线程个数*/
    int wait_exit_thr_num;    /*要销毁的线程个数*/
    int queue_front;    /* task_queue队头下标*/
    int queue_rear;    /* task_queue队尾下标*/
    int queue_size;    /* task_queue队中实际任务数*/
    int queue_max_size;    /* task_queue队列可容纳任务数上限*/
    int shutdown;        /*标志位,线程池使用状态, true或false */

};

void *threadpool_thread(void *threadpool);
void *adjust_thread(void *threadpool);
int is_thread_alive(pthread_t tid);
int threadpool_free(threadpool_t *pool);

//threadpool create(3, 100,100);




threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size){

    threadpool_t *pool = NULL;      /*线程池结构体*/

    do {
        if((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL) {
            printf("malloc threadpool fail");
            break;
            /*跳出do while*/
        }

        pool->min_thr_num = min_thr_num;
        pool->max_thr_num = max_thr_num;
        pool->busy_thr_num = 0;
        pool->live_thr_num = min_thr_num;       /*活着的线程数初值=最小线程数*/
        pool->wait_exit_thr_num = 0;
        pool->queue_size= 0;                    /*有0个产品*/
        pool->queue_max_size = queue_max_size;  /*最大任务队列数*/
        pool->queue_front = 0;
        pool->queue_rear = 0;
        pool->shutdown = false;              /*不关闭线程池*/

        /*根据最大线程上限数，给工作线程数组开辟空间，并清零*/
        pool->threads = (pthread_t *)malloc(sizeof(pthread_t)*max_thr_num);
        if (pool->threads == NULL) {
            printf("malloc threads fail");
            break; 
        }
        
        //初始化互斥锁，条件变量
        if(pthread_mutex_init(&(pool->lock),NULL)!=0
           ||pthread_mutex_init(&(pool->thread_counter),NULL)!=0
           ||pthread_cond_init(&(pool->queue_not_empty),NULL)!=0
           ||pthread_cond_init(&(pool->queue_not_full),NULL)!=0)
        {
            perror("init lock or cond error\n");
            break;
        }
        //启动min_thr_num 个 work thread
        for(int i = 0;i < min_thr_num;i++){
            pthread_create(&(pool->threads[i]),NULL,threadpool_thread,(void *)pool); //pool指向当前线程池
            printf("start thread 0x%X...\n",(unsigned int)pool->threads[i]);
        }

        pthread_create(&(pool->adjust_tid),NULL,adjust_thread,(void *)pool);  //创建管理者线程

        return pool;
        
    }while(0);   //相当于只进行一次的while循环，如果前面某一步出现问题，都会退出
    threadpool_free(pool); //前面的代码调用失败，释放poll存储空间
    return NULL;
}
#endif
