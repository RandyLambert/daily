#include <bits/stdc++.h>
using namespace std;
long long dp[32][32][32][32][32];
int pnum[6];
int main(){
    int k;
    scanf("%d",&k);
    for(int i = 1;i <= k;i++){
        scanf("%d",&pnum[i]);
    }

    dp[0][0][0][0][0]  = 1;

    for(int i = 0;i <= pnum[1];i++)
        for(int j = 0;j <= min(i,pnum[2]);j++)
            for(int k = 0;k <= min(j,pnum[3]);k++)
                for(int h = 0;h <= min(k,pnum[4]);h++)
                    for(int g = 0;g <= min(h,pnum[5]);g++){
                        long long &v = dp[i][j][k][h][g];
                        if(i && i-1 >= j) v+=dp[i-1][j][k][h][g];
                        if(j && j-1 >= k) v+=dp[i][j-1][k][h][g];
                        if(k && k-1 >= h) v+=dp[i][j][k-1][h][g];
                        if(h && h-1 >= g) v+=dp[i][j][k][h-1][g];
                        if(g) v+=dp[i][j][k][h][g-1];
                    }


    printf("%lld\n",dp[pnum[1]][pnum[2]][pnum[3]][pnum[4]][pnum[5]]);

    return 0;
}
