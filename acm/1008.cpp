#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fish[100010];
int main(){

    int t;
    ll n,k;
    scanf("%d",&t);
    while(t--){
        memset(fish,0,sizeof(fish));
        scanf("%lld%lld",&n,&k);
        ll ans = k;
        for(int i = 0;i < n;i++){
            scanf("%lld",&fish[i]);
            ans = ans + fish[i];
        }


    }

    return 0;
}

