#include <bits/stdc++.h>
using namespace std;
long long test[50010];
inline bool judge(int mid){

}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i = 2;i <= 50000;i++){
        test[i]  = (long long)(i*i*i);
        /* cout<<test[i]<<endl; */
    }

    long long l = 2,r = 100000000000000,ans = 0;
    while(l <= r){
        long long mid = (l+r)>>1;
        if(judge(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    return 0;
}
