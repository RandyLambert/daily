#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)
 
typedef long long ll;
const int maxn = 205;
const ll mod = 1e9+7;
const ll INF = 1e18;
const double eps = 1e-9;
 
int n,x;
int sum[maxn];
int dp[maxn][maxn];
 
int main()
{
    while(~scanf("%d",&n))
    {
        sum[0]=0;
        mst(dp,0x3f);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
            dp[i][i]=0;
        }
        for(int len=2;len<=n;len++)
        for(int i=1;i<=n;i++)
        {
            int j=i+len-1;
            if(j>n) continue;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
        printf("%d\n",dp[1][n]);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                printf("%d ",dp[i][j]);
            }
            putchar('\n');
        }

    }
    return 0;
}
