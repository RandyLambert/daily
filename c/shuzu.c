#include <stdio.h>
void test01(int a[])
{
    for(int i = 0;i < 10;i++)
        a[i]+=5;
}
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    test01(a);
    printf("%d\n",a[0]);
    
    return 0;
}

