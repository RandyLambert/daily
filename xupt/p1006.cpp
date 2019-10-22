#include <bits/stdc++.h>
using namespace std;
int dp[105][105][200][200];
int mp[105][105];
int main(){

    int n,m;
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++){
            scanf("%d",&mp[i][j]);
        }

    int c = n+m-2;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= c;k++){
                for(int f = 1;f <= c;f++){
                    dp[i][j][k][f] = max(dp[i][j][k][f],dp[i][j-1][k][f-1] + mp[i][j]);
                    dp[i][j][k][f] = max(dp[i][j][k][f],dp[i-1][j][k-1][f] + mp[i][j]);
                    dp[i][j][k][f] = max(dp[i][j][k][f],dp[i][j-1][k-1][f] + mp[i][j]);
                    dp[i][j][k][f] = max(dp[i][j][k][f],dp[i-1][j][k][f-1] + mp[i][j]);
                }
            }
        }
    }

    printf("%d\n",dp[m][n][c][c]);
    
    return 0;
}
