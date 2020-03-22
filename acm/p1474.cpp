#include <bits/stdc++.h>
using namespace std;
long long dp[10010];
long long qian[30];
int main(){
    int v,n;
    scanf("%d%d",&v,&n);
    for(int i = 1;i <= v;i++){
        scanf("%lld",&qian[i]);
    }
    dp[0] = 1;

    for(int i = 1;i <= v;i++)
        for(int j = qian[i];j <= n;j++)
        {
            dp[j] = dp[j] + dp[j-qian[i]];
        }

    printf("%lld\n",dp[n]);
    return 0;
}

