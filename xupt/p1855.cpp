#include <bits/stdc++.h>
using namespace std;
int dp[250][250],m1[250],t1[250];
int main(){
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&m1[i],&t1[i]);
    }

    for(int i = 1;i <= n;i++)
        for(int j = m;j >= m1[i];j--)
            for(int k = t;k >= t1[i];k--){
                dp[j][k] = max(dp[j][k],dp[j-m1[i]][k-t1[i]]+1);
            }
    printf("%d\n",dp[m][t]);

    return 0;
}

