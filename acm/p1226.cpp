#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int b,p,k,sum = 1;
    cin>>b>>p>>k;
    long long int b1 = b,p1 = p,k1 = k; 
    while(p!=0){
        if(p&1){
            sum*=b;
            sum%=k;
        }
        b=b*b;
        b%=k;
        p = p>>1;
    }
    printf("%lld^%lld mod %lld=%lld\n",b1,p1,k1,sum%k);
    return 0;
}
