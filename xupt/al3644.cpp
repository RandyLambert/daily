#include <bits/stdc++.h>
using namespace std;
int vis[100000+10],f[100000+10];
int findf(int x){
    if(x == f[x])
        return f[x];
    else
    {
        f[x] = findf(f[x]);
        return f[x];
    }
}
int main(){
    int n,m;

    while(scanf("%d",&n)){
        int ans = 0;
        for(int i = 0;i <= 100009;i++)
            f[i] = i;
        if(n==-1)
        {
            break;
        }
        while(n!=-1)
        {
            scanf("%d",&m);
            int x = findf(n);
            int y = findf(m);
            if(x == y){
                ans++;
            }
            else{
                f[x] = y;
            }
            scanf("%d",&n);
        }
        printf("%d\n",ans);
    }

    return 0;
}

