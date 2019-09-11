#include<bits/stdc++.h>
using namespace std;
int v[1005],a[1005],n;
void dfs(int c)
{
    if(c==n){
        printf("%d",a[0]);
        for(int i=1;i<n;i++)printf(" %d",a[i]);
        printf("\n");
    }
    else{
        for(int i=1;i<=n;i++){
            if(!v[i]){
                v[i]=1;
                a[c]=i;
                dfs(c+1);
                v[i]=0;
            }
        }
    }
}
int main()
{
    while(~scanf("%d",&n)){
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        dfs(0);
    }
    return 0;
}
