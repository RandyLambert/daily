#include <stdio.h>
int main()
{
    int a[2][3] = {{5,7},{5,8}};
    int b[2][3] = {5,7,5,8};

    int c[2][2] = {{5,7},{5,8}};
    int d[2][2] = {5,7,5,8};

    printf("%d %d\n",a[1][1],b[1][1]);
    printf("%d %d\n",c[1][1],d[1][1]);
    
    return 0;
}
