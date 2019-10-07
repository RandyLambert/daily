#include <bits/stdc++.h>
using namespace std;
long long dp[101000],w[101000],v[101000];
int main(){

    int n,k;
    cin>>n>>k;
        for(int i = 1;i <= n;i++){
            cin>>v[i]>>w[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = w[i];j <= k;j++){
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[k]<<"\n";
    return 0;
}

