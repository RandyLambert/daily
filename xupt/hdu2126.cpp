#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int dp[510],g[510],w[510];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++){
            scanf("%d",&w[i]);
        }
        for(int i = 1;i <= m;i++){
            g[i] = 0,dp[i] = -99999999;//dp[i] 不能写成0，因为要写成在那个时候恰好为最大值而不是最多为多少的最大值
                                        //初始状态写为0，其他为-无穷
        }
        g[0] = 1;
        dp[0] = 0;
        

        for(int i = 1;i <= n;i++){
            for(int j = m;j >= w[i];j--){
                int t = max(dp[j],dp[j-w[i]]+1);
                int s = 0;

                if(t == dp[j]) s += g[j];
                if(t == dp[j-w[i]]+1) s += g[j-w[i]];
                dp[j] = t;
                g[j] = s;
            }
        }

        int maxw = -1;
        for(int i = 0;i <= m;i++) maxw = max(maxw,dp[i]);
        int res = 0;
        for(int i = 0;i <= m;i++){
            /* printf("%d %d\n",g[i],dp[i]); */
            if(maxw == dp[i])
            {
                res += g[i];
            }
        }
        if(maxw == 0){
            printf("Sorry, you can't buy anything.\n");
        }
        else
            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",res,maxw);
    }

    return 0;
}
