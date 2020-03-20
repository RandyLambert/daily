#include "Threadpool.h"
//主程序创建线程池
//向线程池中添加任务，借助回调处理任务
//销毁线程池
int main(){
    //pool init
    threadpool_t *thp = threadpool_create(5,10,2000);//创建线程池，池中最小5个最多100个，任务队列最大100个
    
    int *num = (int *)malloc(sizeof(int)*2000);

    for(int i = 0;i < 30;i++){
        num[i] = i;
        printf("新加任务\n");

        threadpool_add(thp,process,(void *)&num[i]);//向线程池中添加任务,借助回调处理任务
    }
    
    sleep(15);//模拟线程处理任务
    threadpool_destroy(thp);
    printf("线程全部摧毁\n");
    return 0;
}

