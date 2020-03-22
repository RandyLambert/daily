#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int a;
    int k;
    scanf("%lld%d",&a,&k);
    while(k--)
    {
        if(a%10==0){
            a = a/10;
        }
        else if(a%10!=0){
            a = a-1;
        }
    }
    printf("%lld\n",a);
    return 0;
}
