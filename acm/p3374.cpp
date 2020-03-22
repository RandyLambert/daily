#include <bits/stdc++.h>
using namespace std;
int bit[500010],n;
inline int lowbit(int x){
    return x&-x;
}
int query(int x){
    int ans = 0;
 
    while(x){
        ans+=bit[x];
        x-=lowbit(x);
    }

    return ans;
}
void add(int x,int y){
    while(x<=n){
        bit[x]+=y;
        x+=lowbit(x);
    }  
}

int main(){
    ios::sync_with_stdio(false);
    int m,a,b,c;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a;
        add(i,a);
    }
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        if(a==1){
            add(b,c);
        }
        if(a==2){
            int ans = query(c) - query(b-1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}

