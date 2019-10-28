#include <bits/stdc++.h>
using namespace std;
int dp[1510][1510][2],mp[1510][1510];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }

    int ans = -1;

    for(int i= 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(mp[i][j]==1){
                dp[i][j][1] = min(dp[i-1][j-1][1],min(dp[i-1][j][0],dp[i][j-1][0]))+1;
                ans = max(ans,dp[i][j][1]);
            }
            else{
                dp[i][j][0] = min(dp[i-1][j-1][0],min(dp[i-1][j][1],dp[i][j-1][1]))+1;
                ans = max(ans,dp[i][j][0]);

            }
        }
    }

    printf("%d\n",ans);

    return 0;
}

