#include <bits/stdc++.h>
using namespace std;
int n,m,zu;
int a[1010],b[1010],shu[100],dp[1010],zushu[100][20],cn,mx;
int main(){
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&a[i],&b[i],&cn);
        mx = max(mx,cn);
        shu[cn]++;
        zushu[cn][shu[cn]] = i;
    }
    for(int i = 1;i <= mx;i++){
        for(int j = m;j >= 0;j--){
            for(int k = 1;k <= shu[i];k++){
                if(j>=a[zushu[i][k]]){
                    dp[j] = max(dp[j],dp[j-a[zushu[i][k]]]+b[zushu[i][k]]);
                }
            }
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}
