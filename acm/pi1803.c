#include<stdio.h>
void sort(int a[],int b[],int n)
{
    int i,j,t;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n-1;j++)
        {
            if(b[i]>b[j])
            {
                t=b[i];
                b[i]=b[j];
                b[j]=t;
 
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
 
int main()
{
    int a[105],b[105],time;
    int n,i,j,sum;
    scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d %d",&a[i],&b[i]); 
        sort(a,b,n);
        putchar('\n');
        for(int i = 1; i <= n; i++){
            printf("%d %d\n",a[i],b[i]);
        }
        putchar('\n');
        sum=1;
        time=b[1];
        for(j=1;j<=n;j++)
        {
            if(a[j]>=time)
            {
                sum++;
                time=b[j];
            }
        }
        printf("%d\n",sum);
}
