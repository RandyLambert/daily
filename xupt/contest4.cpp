#include <bits/stdc++.h>
using namespace std;
int shu[11][11],he[11][11];
int dp[10];
int main(){
    int n,k,len,a;
    scanf("%d%d",&n,&k);
    scanf("%d",&a);
    for(int i = n;i > 0;i--){
        shu[i][i] = a%10;
        a=a/10;
    }
    
    for(int i = 1;i < n;i++){
        for(int j = i+1;j<=n;j++){
            shu[i][j] = shu[i][j-1]*10+shu[j][j];
        }
    }
    for(int i = 1;i<=n;i++){
        he[i][0] = shu[1][i];
    }

    for(int i = 1;i <= k;i++){
        for(int j = i+1;j<=n;j++){
            for(int k = 1;k<j;k++){
                he[j][i] = max(he[j][i],he[k][i-1]*shu[k+1][j]);
            }
        }
    }
    printf("%d",he[n][k]);
    return 0;
}

