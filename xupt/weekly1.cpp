#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,x;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&x);
        if(x%3==0){
            printf("%lld\n",(x/3)*(x/3)*(x/3));
        }
        else if(x%4==0){
            printf("%lld\n",(x/4)*(x/4)*(x/2));
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}

