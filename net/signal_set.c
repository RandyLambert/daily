#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>
int main(){
    //可以手动屏蔽内核信号
    //自定义一个内核信号集
    //
    sigset_t myset;
    //集合清空
    sigemptyset(&myset);
    //添加要阻塞的信号
    sigaddset(&myset,SIGINT); //crtl+c
    sigaddset(&myset,SIGQUIT); //crtl+/
    sigaddset(&myset,SIGKILL); //kill,不允许阻塞
    //sig_block 相当于mask|set,set表示需要屏蔽的信号,常用
    //sig_unblock 相当于mask&~set，set表示需要解除屏蔽的信号
    //sig_setmask 当how设置为此，set表示用于替代原始屏蔽集的新屏蔽集，相当于覆盖mask = set
    
    //只是设置到自定义信号集里面，通过自定义信号集和数据设置给内核的阻塞信号集
    sigprocmask(SIG_BLOCK,&myset,NULL);

    //每隔一秒读取一次内存中的未决信号集
    //当恩了以后就存在未决信号集里面了
    while(1)
    {
        sigset_t pendset;
        sigpending(&pendset);//可以读取内核中的信号集
        //1-31
        for(int i=1;i<32;i++){
            //对每一个信号进行一次判断，是否处于未决信号集
            if(sigismember(&pendset,i)){
                printf("1");
            }
            else{
                printf("0");
            }
        }
        putchar('\n');
        sleep(1);
    }
    return 0;
}
