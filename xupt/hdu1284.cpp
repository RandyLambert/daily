#include <bits/stdc++.h>
using namespace std;
long long dp[32800];
int main(){
    int t;
    while(~scanf("%d",&t)){
        memset(dp,0,sizeof(dp));

        dp[0] = dp[1] = 1;
        for(int i = 1;i <= 3;i++){
            for(int j = 2;j <= t;j++){
                dp[j] = dp[j-i]+dp[j];
            }
        }
        printf("%lld\n",dp[t]);
    }
    return 0;
}
