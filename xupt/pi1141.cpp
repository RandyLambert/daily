#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

struct node{
    int x;
    int y;
};

int step;
int n,m,t1,t2;
char mp[1001][1001];
bool vis[1001][1001];
int xx[4] = {0,1,-1,0};
int yy[4] = {1,0,0,-1};

int main(){
    scanf("%d%d",&n,&m);
    while(getchar()!='\n');
    int i,j;
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            scanf("%c",&mp[i][j]);
        }
        while(getchar()!='\n');
    }
    while(m--){
        scanf("%d%d",&t1,&t2);
        queue<node>q;
        node start;
        start.x = t1;
        start.y = t2;
        step++;
        vis[t1][t2] = 1;
        q.push(start);

        while(!q.empty()){
            node temp;
            temp = q.front();
            q.pop();
            
            for(int i = 0;i < 4;i++){
                int nx = temp.x + xx[i];
                int ny = temp.y + yy[i];
                if(mp[nx][ny]!=mp[temp.x][temp.y]&&vis[nx][ny]!=1&&nx<=n&&ny<=n&&nx>=1&&ny>=1){
                    vis[nx][ny] = 1;
                    node nw;
                    nw.x = nx;
                    nw.y = ny;
                    step++;
                    q.push(nw);
                }
            }
        }
        printf("%d\n",step);
        memset(vis,0,sizeof(vis));
        step = 0;
    }
    return 0;
}
