#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void myfunc(int no){
    printf("%d\n",no);
    sleep(3);
    printf("week up\n");
}
int main(){

    //函数原型个第一个捕捉的参数，第二个是一个结构体，第三个是上一次函数的处理，一般传null
    
    //在第二个参数的结构体里
    //需要在结构体里面做设置
    //结构体里面第一个参数就是signal的第二个参数，第二个函数指针用的不多,两个函数指针二选一
    //一般选择第一个
    //在结构体里第二个参数中给可以添加信号，使该信号在处理函数执行过程中，临时屏蔽指定信号
    //处理结束时接触屏蔽
    
    struct sigaction act;
    act.sa_flags = 0;//只有在用第二个回调函数的时候用赋值 
    sigemptyset(&act.sa_mask);//清零mask
    //可以在这里添加回调函数执行时的临时屏蔽函数
    sigaddset(&act.sa_mask,SIGQUIT); //添加屏蔽信号
    act.sa_handler = myfunc; 
    sigaction(2,&act,NULL);
    while(1){};
    
    return 0;
}
