#include<stdio.h>
inline long long int daan(long long int x){
    long long int ans = 0;
    for(long long int i = 1;i < x;i++)
        if(x%i==0){
            ans = i + ans;
        }
        return ans;
}
int main(){
    long long int yy,xx;
    scanf("%lld",&xx);
    for(long long int i = 1;i <= xx;i++){
        yy=daan(i);
        if(yy > i){
            if(daan(yy)==i){
                printf("(%lld,%lld)",i,yy);
            }
        }
    }
}
