#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int a = 1;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++ ){
        a*=i;
        while(a%10==0){
            a/=10;
        }
        a = a%10000000;
    }
    printf("%lld",a%10);
    return 0;
}
