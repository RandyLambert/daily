#include <bits/stdc++.h>
using namespace std;
int a;
int dd[7];
int cal (int x) {
    if (x == 4) return 1;
    if (x == 8) return 2;
    if (x == 15) return 3;
    if (x == 16) return 4;
    if (x == 23) return 5;
    if (x == 42) return 6;
}
int main(){
    long long ans=0;
    long long n,x = 0;
    scanf("%lld",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a);
        /* printf("%d",cal(a)); */
        if(cal(a) == 1){
            dd[1]++;
        }
        else{
            if(dd[cal(a)-1] > dd[cal(a)] ){
                dd[cal(a)]++;
            }
            else{
                ans++;
            }
        }
    }
    x = *min_element(dd+1,dd+7);
    for(int i = 1;i < 7;i++){
        if(dd[i]>x){
            ans = ans + (dd[i]-x);
        }
    }
    /* for(int i = 1;i < 7;i++) */
    /*     printf("%d ",dd[i]); */
    printf("%lld\n",ans);

    return 0;
}

