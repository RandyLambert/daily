#include <bits/stdc++.h>
/*
 * Prim 求 MST
 * 耗费矩阵 cost[][],标号从 0 开始,0 ∼ n-1
 * 返回最小生成树的权值,返回 -1 表示原图不连通
 */
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=5010;
bool vis[MAXN];
long long dist[MAXN];
int lowc[MAXN];
struct node1{

    long long x,y;
    long long operator* (const node1 &b) const {
        return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
    }

}q1[5005];

void Prim(int n){

    memset(dist,INF,sizeof(dist));
    memset(vis,false,sizeof(vis));
    dist[1] = 0;
    vis[0]=true;
    for(int i=1;i<=n-1;i++){
        int x = 0;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && (x==0 || dist[j] < dist[x]))
                x = j;
        }
        vis[x] = 1;
        for(int y = 1;y <= n;y++){
            if(!vis[y])
                dist[y] = min(dist[y],q1[x]*q1[y]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <=n;i++){
        scanf("%lld%lld",&q1[i].x,&q1[i].y);
    }
    Prim(n);
    double ans= 0;
    for(int i = 1;i<=n;i++){
        ans+=sqrt((double)dist[i]);
    }
    printf("%.2lf\n",ans);

    return 0;
}
