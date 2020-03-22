#include <bits/stdc++.h>
using namespace std;
long long dp[110];
long long f[110][110];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)){
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        if(n==0 && m==0)
            break;
        else{
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= m;j++){
                    scanf("%lld",&f[i][j]);
                }
            }

            for(int i = 1;i <= n;i++){
                for(int j = m;j > 0;j--){
                    for(int k = 1;k <= m;k++){
                        if(j>=k)
                            dp[j] = max(dp[j],dp[j-k]+f[i][k]);
                    }
                }
            }
            printf("%lld\n",dp[m]);
        }
    }

    return 0;
}
