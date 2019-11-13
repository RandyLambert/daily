#include <stdio.h>
int main(){

    int a[5] = {4,5,2,3,1};
    int i,j;
    for(i = 4;i >= 0;i--)
    {
        for(j = 3;j >= 0;j--)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    for(i = 0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
