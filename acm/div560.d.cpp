#include <bits/stdc++.h>
using namespace std;
int a[310];
map<int,int>q;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        int flag=0,ans = 0;
        long long int temp,ans = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            q[a[i]] = 1;
        }
        sort(a,a+n);
        temp = a[0]*a[n-1];
        int i,j;
        for(i = 1;i <= temp;i++){
            for(j = 0;i < n;i++){
                ans++;
                if(q[i*a[j]]!=1){
                    break;
                }
            }   
        }
        if(flag!=1)
            printf("%lld\n",ans);
    }
    return 0;
}
