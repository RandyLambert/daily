#include <bits/stdc++.h>
using namespace std;
int dp[1000010];
int n,sum = 0;
int main(){

    /* int jia = 1; */
    /* for(int i = 0;i < 21;i++){ */
    /*     m[i] = jia<<i; */
    /* } */
    
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i = 2;i <= n;i++){
            if(i&1){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = (dp[i-1]+dp[i>>1])%1000000000;
            }
        }
        printf("%d\n",dp[n]);
    }
            


    /* for(int i = 0;i < n;i++){ */
    /*     int sum = 0; */
    /*     for(int j = m[i];j <= n;j++){ */
    /*         mp[j] = max(mp[j],mp[j-m[i]] + m[i]); */
    /*         sum = sum + mp[j]; */
    /*     } */
    /*         for(int k = 0;k < n;k++){ */
    /*             printf("%d+",mp[k]); */
    /*     } */
    /* } */

    return 0;
}
