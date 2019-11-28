#include <stdio.h>
//特殊符号,与链接脚本有关
extern char __executable_start[];
extern char etext[],_etext[],__etext[];
extern char edata[],_edata[];
extern char end[],_end[];
int main(){

    printf("程序起始入口，注意，不是入口地址，是程序开始的地址 %X\n",__executable_start);
    printf("代码结束地址即代码段最后末尾位置%X %X %X\n",__etext,_etext,etext);
    printf("数据段结束地址，即数据段最末尾的地址%X %X\n",edata,_edata);
    printf("程序结束位置%X %X\n",_end,end);
    
    return 0;
}

