//
// Created by randylambert on 2020/8/9.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char lu[100000+10];
ll ans = 0;
int main() {
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    vector<pair<ll,ll>> vec;
    while(t--){
        vec.clear();

        ll n,k,x=0,y=0;
        memset(lu,0, sizeof(lu));
        cin>>n>>k;
        cin>>lu;
        ans = 0;

        for(int i = 0;i < n;i++){
            if(lu[i] == 'R'){
                x+=1;
                y+=0;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});
            }
            else if(lu[i] == 'U'){
                x+=0;
                y+=1;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});

            }
            else if(lu[i] == 'L'){
                x-=1;
                y+=0;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});
            }
            else if(lu[i] == 'D'){
                x+=0;
                y-=1;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});
            }
        }
        x = (k-1)*x;
        y = (k-1)*y;
        for(int i = 0;i < n;i++){
            if(lu[i] == 'R'){
                x+=1;
                y+=0;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});
            }
            else if(lu[i] == 'U'){
                x+=0;
                y+=1;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});

            }
            else if(lu[i] == 'L'){
                x-=1;
                y+=0;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});
            }
            else if(lu[i] == 'D'){
                x+=0;
                y-=1;
                ans = max(ans,abs(x)+abs(y));
//                vec.push_back({x,y});
            }
        }

        cout<<ans<<endl;
    }
}

