#include <bits/stdc++.h>
using namespace std;
int dp[205][10];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    dp[1][1] = 1;
    for(int i = 0;i < 205;i++){
        dp[i][1] = 1;
    }
    for(int i = 2;i<=n;i++)
        for(int j = 2;j<=k;j++)
            if(j>i)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
        printf("%d\n",dp[n][k]);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            printf("%d ",dp[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

