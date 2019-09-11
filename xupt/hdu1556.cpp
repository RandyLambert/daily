#include <bits/stdc++.h>
using namespace std;
int bit[100010],n;
int lowbit(int x){
    return x&(-x);
}

int update(int p,int x){    
    while(p <= 100010){
        bit[p] = bit[p] + x;
        p = p + lowbit(p);
    }
}

int query(int p){
    int ans = 0;
    while(0 < p){
        ans = ans + bit[p];
        p = p - lowbit(p);
    }
    return ans;
}
int main(){

    int a,b;
    while(cin>>n && n){
        memset(bit,0,sizeof(bit));
        int tmp = n;
        while(n--){
            cin>>a>>b;
            update(a,1);
            update(b+1,-1);

        }
        for(int i = 1;i < tmp;i++){
            cout<<query(i)<<" ";
        }
        cout<<query(tmp);
        putchar('\n');
    }

    return 0;
}

