#include <stdlib.h>
#include <stdio.h>

int main()
{
    int len = 4;
    int *pt = (int*)malloc(len*sizeof(int));
    int *p = pt;
    for(int i = 0;i < len;i++)
    {
        p++;
    }
    *p = 5;
    printf("the value of p equal;%d\n",*p);
}
