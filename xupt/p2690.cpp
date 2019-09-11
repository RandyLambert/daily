#include <bits/stdc++.h>
using namespace std;
int f[10005][110];
int a[10005];
int n,w;
int dfs(int i,int be,int ci)
{
    if(i > n) return 0;
    if(f[i][ci] != -1) return f[i][ci];
    f[i][ci] = 0;
    if(a[i] == be)
        f[i][ci] = dfs(i+1,a[i],ci)+1;
    else{
        f[i][ci] = dfs(i+1,be,ci);
        if(ci < w)
            f[i][ci] = max(dfs(i+1,a[i],ci+1) + 1,f[i][ci]);
    }
    return f[i][ci];

}
int main(){
    scanf("%d%d",&n,&w);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(f,-1,sizeof(f));
    printf("%d\n",dfs(1,1,0));
    return 0;
}
