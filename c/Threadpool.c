#include "Threadpool.h"
int main(){
    //pool init
    threadpool_t *thp = threadpool_create(10,100,100);//创建线程池，池中最小5个最多100个，任务队列最大100个
    
    int *num = (int *)malloc(sizeof(int)*20);

    for(int i = 0;i < 20;i++){
        num[i] = i;
        printf("新加任务\n");

        threadpool_add(thp,process,(void *)&num[i]);//向线程池中添加任务,借助回调处理任务
    }
    
    sleep(5);//模拟线程处理任务
    threadpool_destory(thp);
    return 0;
}

