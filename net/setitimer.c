#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
//setitimer--定时器，并实现周期性定时
int main(){

    //设计定时器
    //三个参数，第一个哪一种定时法则，第二个设置定时器，第三个上一次定时器的信息
    struct itimerval new_val;
    //第一次触发的时间
    new_val.it_value.tv_sec = 2; //秒
    new_val.it_value.tv_usec = 0;//微秒，两个都得赋值

    //周期性定时
    new_val.it_interval.tv_sec = 1;
    new_val.it_interval.tv_usec = 0;

    //倒计时两秒
    setitimer(ITIMER_REAL,&new_val,NULL);
    while(1){
        printf("hello world\n");
        sleep(1);
        //要进行捕捉，才可以不死，进行周期性操作
    }
    
    return 0;
}

