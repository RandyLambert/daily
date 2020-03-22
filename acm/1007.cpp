#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fish[100000+10];

queue<ll>q;

bool cmp(ll a,ll b){
    return a > b;
}
int main(){

    ll t,n,k;
    scanf("%lld",&t);
    while(t--){
        if(!q.empty()) q.pop();

        memset(fish,0,sizeof(fish));
        scanf("%lld%lld",&n,&k);
        
        for(int i = 0;i < n;i++){
            scanf("%lld",&fish[i]);
        }
        
        sort(fish,fish+n,cmp);

        ll cnt = 0,ans = k;

        q.push(fish[cnt]);
        while(cnt < n){
            ll x = q.front();

            if(cnt != k - 1)
                ans = ans + max(x,k);
            else 
                ans += x;
            
            q.pop();

            int y = x/k;
            for(int i = 0;i < y;i++){
                cnt++;
                q.push(fish[cnt]);
            }

            if(y == 0){
                cnt++;
                q.push(fish[cnt]);
                ans += k;
            }
        }

        while(!q.empty()){
            ans = ans + q.front();
            q.pop();
        }

        printf("%lld\n",ans);

    }
    return 0;
}

