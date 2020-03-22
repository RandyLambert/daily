#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,cow[1000];
bool vis[1000];
vector <int> q[205];
bool dfs(int x)
{
    for(int i = 0;i < q[x].size();i++)
    {
        if(!vis[q[x][i]]){
            vis[q[x][i]] = 1;
            if(cow[q[x][i]]==0||dfs(cow[q[x][i]])){
                cow[q[x][i]] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&u);
        for(int j = 0;j < u;j++)
        {
            scanf("%d",&v);
            q[i].push_back(v);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
