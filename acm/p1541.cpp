#include <bits/stdc++.h>
using namespace std;
int mp[360],num[5],dp[45][45][45][45];
int main(){
    int n,m,x;

    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>mp[i];
    for(int i = 0;i < m;i++){
        cin>>x;
        num[x]++;
    }

    
    dp[0][0][0][0] = mp[1];
    
    for(int i = 0;i <= num[1];i++){
        for(int j = 0;j <= num[2];j++){
            for(int k = 0;k <= num[3];k++){
                for(int x = 0;x <= num[4];x++){
                    int r = 1+i+j*2+k*3+x*4;

                    if(i!=0) dp[i][j][k][x] = max(dp[i][j][k][x],dp[i-1][j][k][x] + mp[r]);
                    if(j!=0) dp[i][j][k][x] = max(dp[i][j][k][x],dp[i][j-1][k][x] + mp[r]);
                    if(k!=0) dp[i][j][k][x] = max(dp[i][j][k][x],dp[i][j][k-1][x] + mp[r]);
                    if(x!=0) dp[i][j][k][x] = max(dp[i][j][k][x],dp[i][j][k][x-1] + mp[r]);
                }
            }
        }
    }

    cout<<dp[num[1]][num[2]][num[3]][num[4]]<<endl;
    return 0;
}
