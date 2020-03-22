#include <iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL G[550][550];
int main()
{
    int n,i,j,k;
    LL a[550],dp[550],maxn,x;
    scanf("%d",&n);
    memset(G,0,sizeof(G));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&x);
            G[i][j]=G[i-1][j]+x;//每行的前缀和
        }
    }
    maxn=0;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            dp[0]=0;
            for(k=1;k<=n;k++)
            {
                a[k]=G[j][k]-G[i-1][k];
                dp[k]=max(a[k],a[k]+dp[k-1]);
                maxn=max(maxn,dp[k]);
            }
        }
    }
    printf("%lld",maxn);
    return 0;
}
