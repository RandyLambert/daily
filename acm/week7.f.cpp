#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f;
struct node{
    int x,y;
    long long step;
};
queue <node> q;
long long n = 0,mp[55][55],we[55][55],vis2[55][55];
int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};
long long dfs(int x,int y)
{
    if(!vis2[x][y]){
        for(int i = 0;i < 4;i++){
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx<=n&&ny<=n&&nx>=1&&ny>=1){
                if(we[x][y] > we[nx][ny])
                vis2[x][y] = dfs(nx,ny) + vis2[x][y];
            }
        }
    }
    return vis2[x][y];
}
int main(){
    while(~scanf("%lld",&n))
    {
        memset(mp,0,sizeof(mp));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                scanf("%lld",&mp[i][j]);
                we[i][j] = INF;
                vis2[i][j] = 0;
            }
        }
        while(!q.empty()) q.pop();
        node start;
        we[n][n] = mp[n][n];
        start.x = n,start.y = n,start.step=mp[n][n];
        q.push(start);
        while(!q.empty()){
            node temp;
            temp = q.front();
            q.pop();
            /* if(temp.x==n&&temp.y==n){ */
                /* for(int i = 1;i<=n;i++){ */
                /*     for(int j = 1;j<=n;j++){ */
                /*         printf("%d ",we[i][j]); */
                /*     } */
                /*     putchar('\n'); */
                /* } */
                /* printf("%d\n",temp.step); */
                /* mi = temp.step; */
            /* } */
            for(int i = 0;i < 4;i++){
                node nx;
                nx.x = xx[i] + temp.x;
                nx.y = yy[i] + temp.y;
                if(nx.x<=n&&nx.y>=1&&nx.y<=n&&nx.y>=1)
                {
                    if(we[nx.x][nx.y] > temp.step + mp[nx.x][nx.y])
                    {
                        we[nx.x][nx.y] = temp.step + mp[nx.x][nx.y];
                        nx.step = temp.step + mp[nx.x][nx.y];
                        q.push(nx);
                    }
                }
            }
        }
                for(int i = 1;i<=n;i++){
                    for(int j = 1;j<=n;j++){
                        printf("%lld ",we[i][j]);
                    }
                    putchar('\n');
                }
        vis2[n][n] = 1;
        cout<<dfs(1,1)<<endl;
                for(int i = 1;i<=n;i++){
                    for(int j = 1;j<=n;j++){
                        printf("%lld ",vis2[i][j]);
                    }
                    putchar('\n');
                }
    }
    return 0;
}
