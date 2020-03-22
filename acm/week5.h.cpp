#include <bits/stdc++.h>
using namespace std;
int vis[105][105];
int mp[105][105];
int xx[4] = {-1,0,1,0};
int yy[4] = {0,-1,0,1};
int n,m;
int dfs(int x,int y){
    if(vis[x][y]){
        return vis[x][y];
    }
    int res = 1;
    for(int i = 0;i < 4;i++){
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx<=n&&ny>=1&&ny<=m&&nx>=1&&mp[x][y]<mp[nx][ny]){
            res = max(dfs(nx,ny)+1,res);
        }
    }
    vis[x][y] = res;
    return res;
}
int main(){
    int mx=0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            scanf("%d",&mp[i][j]);
        }
    }
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            mx = max(dfs(i,j),mx);
        }
    }
    printf("%d\n",mx);
    return 0;
}
