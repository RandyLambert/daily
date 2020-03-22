#include <bits/stdc++.h>

using namespace std;
long long int a[1002];
long long int ci[1002];
int main(){
    long long int n,mx = 0,mn;
    cin>>n;
    mn = 1000000000;
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    
    printf("%lld",mx-mn-n+1);
    return 0;
}
