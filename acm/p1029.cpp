#include <bits/stdc++.h>
using namespace std;
long long int  gcd(long long int a,long long int b){
    if(b==0) return a;
    else gcd(b,a%b);
}
int main(){
    long long int x,y;
    int sum = 0;
    scanf("%lld%lld",&x,&y);
    for(int i = 1;i < sqrt(x*y);i++){
        if((x*y)%i == 0 && gcd(i,(x*y)/i)==x) sum++;
    }
    printf("%d\n",sum*2);



    return 0;
}
