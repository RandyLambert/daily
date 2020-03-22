#include <bits/stdc++.h>
using namespace std; 
long long ans[100000+10];
int main(){

    int n,k;
    cin>>n>>k;
    ans[1] = 1;
    for(int i = 1;i <= n+1;i++)
        for(int j = 1;j <= k;j++){
            if(i >= j){
                ans[i] = (ans[i-j]+ans[i])%100003;
            }
        }
    /* for(int i = 1;i <= n+1;i++) */
        cout<<ans[n+1]<<endl;
    return 0;
}

