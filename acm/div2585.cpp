#include <bits/stdc++.h>
using namespace std;
int up[200000+10];
int main(){

    long long n,m;
    long long ne = 0,po = 0;
    scanf("%lld",&n);
    up[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&m);
        if(m > 0)
        {
            up[i] = up[i-1];
        }
        else
        {
            up[i] = 1 - up[i-1];
        }
    }

    long long f1 = 0,f2 = 0;
    for(int i = 0;i<=n;i++)
    {
        if(up[i] == 1){
            f1++;
        }
        else{
            f2++;
        }
    }

    ne = f1*f2;
    po = (n+1)*n/2-ne;
    printf("%lld %lld\n",ne,po);
    return 0;
}

