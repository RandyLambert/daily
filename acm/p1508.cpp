#include <bits/stdc++.h>
using namespace std;
int dp[250][250];
int main(){

    int n,m;
    cin>>m>>n;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            cin>>dp[i][j];
        }
    }

    
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            int x = dp[i-1][j-1]+dp[i][j];
            int y = dp[i-1][j]+dp[i][j];
            int z = dp[i-1][j+1]+dp[i][j];
            dp[i][j] = max(max(x,y),z);
        }
    }

       int ans = max(dp[m][n/2+2],max(dp[m][n/2+1],dp[m][n/2]));

    cout<<ans<<endl;
    return 0;
}
