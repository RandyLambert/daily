#include <bits/stdc++.h>
using namespace std;
int ad[3];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        memset(ad,0,sizeof(ad));
        scanf("%d",&n);
        int ans = 0;
        int x;
        for(int i = 0;i < n;i++){
            scanf("%d",&x);
            ad[x%3]++;
        }
        if(ad[1]>ad[2]){
            ans = ad[2]+ans;
            if(ad[1]-ad[2]>=3){
                ans = ans+(ad[1]-ad[2])/3;
            }
        }
        else{
            ans = ad[1]+ans;
            if(ad[2]-ad[1]>=3){
                ans = ans+(ad[2]-ad[1])/3;
            }
        }
        ans = ad[0]+ans;
        printf("%d\n",ans);
    }
    return 0;
}

