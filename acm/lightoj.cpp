#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct mat{
    ll a[10][10];
};

mat qpow(mat a,mat b){
    mat c;
    for(int i = 1;i<= 2;i++){
        for(int j = 1;j <= 2;j++){
            for(int k = 1;k <= 2;k++){
                c.a[i][k] = c.a[i][k] + a.a[i][j] * b.a[j][k];
            }
        }
    }
    return c;
}

mat powq(mat b,ll n){
    mat a;
    a.a[1][1] = a.a[2][2] = 1;

    while(n){
        if(n&1) a = qpow(a,b);
        b = qpow(b,b);
        n = n>>1;
    }
    return a;
}

int main(){

    ll t,p,q,n,i;
    scanf("%lld",&t);
    while(t--){

        scanf("%lld%lld%lld",&p,&q,&n);

    }

    return 0;
}

