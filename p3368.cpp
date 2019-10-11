#include <bits/stdc++.h>
using namespace std;
long long bit[500000+10],n;
inline int getbit(int x){
    return x&-x;
}
long long qury(int x){
    int ans;
    while(x){
        ans = ans + bit[x];
        x -= getbit(x);
    }
    return ans;
}

void add(int x,int y){
    while(x<=n){
        bit[x]+=y;
        x+=getbit(x);
    }
}
int main(){
    int m;
    long long now,last = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>now;
        add(i,now-last);
        last = now;
    }
    int f,l,r;
    for(int i = 0;i < m;i++){
        cin>>f;
        if(f==1){
            cin>>l>>r>>now;
            add(l,now);
            add(r + 1,-now);
        }
        else{
            cin>>now;
            cout<<qury(now)<<"\n";
        }
    }
    return 0;
}
