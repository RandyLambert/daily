#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int dp[maxn*2][maxn][maxn];
int mp[maxn][maxn];
int main(){
    int n,x,y,v;
    scanf("%d",&n);
    while(scanf("%d%d%d",&x,&y,&v)){
        if(x ==0 && y == 0 && v  == 0){
            break;
        }
        mp[x][y] = v;
    }

    for(int i = 1;i <= n*2;i++)
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= n;k++){
                if(i-j > 0 && i-j <= n && i-k > 0 && i - k <= n){
                    int xx = i-j;
                    int yy = i-k;
                    int w = mp[j][xx];
                    if(xx!=yy) w+=mp[k][yy];
                    dp[i][j][k] = max(dp[i-1][j-1][k-1]+w,max(dp[i-1][j-1][k]+w,max(dp[i-1][j][k-1]+w,dp[i-1][j][k]+w)));

                }
            }

    printf("%d\n",dp[n*2][n][n]);

    return 0;
}
