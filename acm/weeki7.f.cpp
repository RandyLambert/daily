#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
const int maxn = 55;
int n;
int t[maxn][maxn],dist[maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dp[maxn][maxn];
 
struct node{
    int x,y;
}p,q;
 
void bfs(){
    queue<node>Q;
    p.x=n;
    p.y=n;
    dist[n][n]=t[n][n]; //因为深搜是记忆化搜索，所以倒过来，把原先的终点先加入队列当中
    Q.push(p);
    while (!Q.empty()){
       p=Q.front();
       Q.pop();
       for (int i=0;i<4;i++){
           q.x=p.x+dx[i];
           q.y=p.y+dy[i];
          if (q.x<1 || q.y<1 || q.x>n || q.y>n) continue;
          if (dist[q.x][q.y]>dist[p.x][p.y]+t[q.x][q.y] || dist[q.x][q.y]==-1){
               dist[q.x][q.y]=dist[p.x][p.y]+t[q.x][q.y];
               Q.push(q);
          }
       }
    }
}
 
int dfs(int x, int y){
    if (dp[x][y]) return dp[x][y];
    for (int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if (xx<1 || yy<1 || xx>n || yy>n) continue;
        if (dist[xx][yy]>=dist[x][y]) continue;
        dp[x][y]+=dfs(xx,yy);
    }
    return dp[x][y];
}
 
int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> n){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) cin >> t[i][j];
        }
        memset(dp,0,sizeof(dp));
        dp[n][n]=1;
        memset(dist,-1,sizeof(dist));
 
        bfs();
        cout<<dfs(1,1)<<endl;
    }
    return  0;
}
