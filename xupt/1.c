#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int flag = 0;
        for(int i=m;i<=n;i++)
        {
            int sum=0;
            int a=i;
            while(a)
            {
                int g=a%10;
                sum+=g*g*g;
                a/=10;
            }
            if(sum==i)
            {
                printf("%d ",i);
                flag=1;
            }
        }
        if(flag==0)
            printf("no");
        printf("\n");
    }
    return 0;
}
