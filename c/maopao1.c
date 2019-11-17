#include <stdio.h>
int main()
{
    int i,j,k,n,p,t;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        p=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                p=1;

            }
        }
        if(p==0)
        break;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}
