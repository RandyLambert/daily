#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    int m,n,t,k,ans=9999999;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t,&k);
        for(int j=t;j<=k;j++){
            ans=min(ans,a[j]);
        }
        printf("%d ",ans);
        ans=9999999;
    }
    return 0;
}
