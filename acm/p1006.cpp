#include <bits/stdc++.h>
using namespace std;
const int maxn = 52;
int dp[maxn][maxn][maxn][maxn];
int mp[maxn][maxn];
int main(){
    int n,m,x,y,v;
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++){
            scanf("%d",&mp[i][j]);
        }

    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++)
            for(int h = 1;h <= m;h++)
                for(int k = 1;k <= n;k++){
                    int w = 0;
                    if(i == h && j == k){
                        w+=mp[i][j];
                    }
                    else{
                        w = mp[i][j] + mp[h][k];
                    }
                    dp[i][j][h][k] = max(dp[i-1][j][h-1][k]+w,max(dp[i-1][j][h][k-1]+w,max(dp[i][j-1][h][k-1]+w,dp[i][j-1][h-1][k]+w)));
                }

    printf("%d\n",dp[m][n][m][n]);

    return 0;
}
