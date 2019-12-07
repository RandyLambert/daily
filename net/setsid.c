#include "unp.h"
void func(int no){

    int fd;
    if((fd = open("text.txt",O_CREAT|O_WRONLY|O_APPEND,0664)) == -1){
        perror("open\n");
        exit(0);
    }
    time_t curtime;
    time(&curtime);

    char *pt = ctime(&curtime);

    /* Read_Time(readline); */
    int len = 0;
    while((len = write(fd,pt,strlen(pt)+1)) > 0){

    }
    if(len < 0){
        perror("write\n");
    }
    close(fd);
}
int main(){

    //守护进程
    //不依赖与终端，抛弃终端，指定任务让他们一直干什么事情，
    //在后台进行运行，而且不受登录和注销的影响
    
    //创建一个会话
    //会话不能是父进程直接创造
    pid_t pid = fork();
    if(pid > 0){
        exit(1);
        /* raise(SIGKILL); */
        /* kill(getpid(),SIGKILL); */
        /* abort(); */
    }
    else if(pid == 0){

        /* Time_Get(); */
        /* chdir("/home");//改变工作目录 */
        /* close(0); */
        /* close(1); */
        /* close(2); */
        umask(0);//传一个八进制数
        //变成会长
        //会长是一个守护进程
        setsid();
        //让子进程一直活着
        signal(SIGALRM,func);

        struct itimerval new_val;
        //第一次时间
        new_val.it_value.tv_sec = 0;
        new_val.it_value.tv_usec = 0;

        //周期性定时
        new_val.it_interval.tv_sec = 2;
        new_val.it_interval.tv_usec = 0;

        setitimer(ITIMER_REAL,&new_val,NULL);
       
        while(1){
        }

        //tip
        //守护进程工作，改变工作目录chdir，去在别的目录进行活动
        //不是必须改变，但是建议改变，切换到不可卸载的目录下面，进程就可以一直运行
        
        //重设文件掩码
        //umask(0),传一个八进制数
        //增加子进程的操作灵活数
        //不然子进程继承了父进程的权限
        
        //关闭文件描述符
        //close(0)
        //close(1)
        //close(2)
        //释放资源
        //因为他已经脱离终端了，不需要输出，节省资源，不一定强制进行
        
        //执行核心工作
        //必须写

    }
    return 0;
}
