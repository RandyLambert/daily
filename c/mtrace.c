#include <stdlib.h>
#include <stdio.h>
#include <mcheck.h>
// https://zhuanlan.zhihu.com/p/83547768
int main()
{
    //其中 mtrace() 用于开启内存分配跟踪，muntrace() 用于取消内存分配跟踪
    mtrace();
    char *p = malloc(16);

    free(p);

    p = malloc(32);
    muntrace();

    return 0;
}
