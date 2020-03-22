#include <bits/stdc++.h>
using namespace std;
bool mp[25][25];
long long dp[25][25];
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    mp[x][y] = 1;
    mp[x+1][y+2] = 1;
    if(x>=1)
        mp[x-1][y+2] = 1;
    mp[x+2][y+1] = 1;
    if(y>=1)
        mp[x+2][y-1] = 1;
    if(y>=2)
        mp[x+1][y-2] = 1;
    if(x>=1 && y >= 2)
        mp[x-1][y-2] = 1;
    if(x>=2 && y >= 1)
        mp[x-2][y-1] = 1;
    if(x>=2)
        mp[x-2][y+1] = 1;

    dp[0][0] = 1;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(mp[i][j]==0){
                if(i > 0 && mp[i-1][j]==0)
                    dp[i][j] += dp[i-1][j];
                if(j > 0 && mp[i][j-1]==0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
