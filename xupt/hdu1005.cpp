#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct node{
    ull x[2][2];
};
const int mod = 7;
node mux(node a,node b){
    
    node t;
    memset(t.x,0,sizeof(t.x));
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 2;j++)
            for(int k = 0;k < 2;k++){
                t.x[i][j] = (t.x[i][j]%mod + (a.x[i][k]*b.x[k][j])%mod)%mod;
            }

    return t;

}

node quick(ull n,node a){

    node t;
    memset(t.x,0,sizeof(t));

    t.x[0][0] = t.x[1][1] = 1;
    t.x[0][1] = t.x[1][0] = 0;
    while(n){
        if(n&1)
            t = mux(t,a);
        a = mux(a,a);
        n=n>>1;
    }
    return t;
}


int main(){

    ull a,b,n;
    while(cin>>a>>b>>n){
        if(a == 0 && b == 0 && n == 0){
            exit(0);
        }

        if(n == 1 || n == 2){
            cout<<1<<"\n";
            continue;
        }
        
        node a1;
        a1.x[0][0] = a;
        a1.x[0][1] = 1;
        a1.x[1][0] = b;
        a1.x[1][1] = 0;
        node ans = quick(n-2,a1);

        cout<<(ans.x[0][0] + ans.x[1][0])%mod<<"\n";

    }

    return 0;
}

