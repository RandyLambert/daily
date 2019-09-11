#include <bits/stdc++.h>
using namespace std;
int a[200050];
int main(){
    int n,ans = 0,x=1,ii=1;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    while(x<=n){
        if(a[x] >= ii){
            ans++;
            x++;
            ii++;
        }
        else{
            x++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
