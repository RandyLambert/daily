#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 100010;
int num[N];
int gcd(int a,int b){
    while(a){
        int t = a;
        a=b%a;
        b=t;
    }
    return b;
}
int main(){
    
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    int ans = gcd(num[0],num[1]);
    for(int i = 2;i < n;i++){
        ans = gcd(ans,num[i]);
        cout<<ans<<endl;
    }
    cout<<ans<<endl;

    
    return 0;
}
