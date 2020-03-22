#include <bits/stdc++.h>
using namespace std;
long long int x;
int judge(long long int mid){
    if((mid*(mid+1))/2<=x){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++){
        scanf("%lld",&x);
        long long int ans = 0;
        long long int l = 1,r = 10000000000;
        while(l<=r){
            long long int mid = (r+l)/2;
            if(judge(mid)){
                ans = ((mid+1)*mid)/2;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}

