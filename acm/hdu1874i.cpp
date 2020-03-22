#include <bits/stdc++.h>
using namespace std;
int dist[210],vis[210],cnt[210];//vis在对列的标志 cnt每个点的如队列次数
const int inf = 0x3f3f3f3f;
struct edge{
    int v;
    int cost;
    edge(int _v = 0,int _cost=0):v(_v),cost(_cost){};
};

vector<edge>e[210];

void addedge(int u,int v,int w)
{
    e[u].push_back(edge(v,w));
}

bool spfa(int start,int n)
{
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i++)
        dist[i] = inf;
    vis[start] = 1;
    dist[start] = 0;
    queue<int>que;

    while(!que.empty()) que.pop();
    que.push(start);

    memset(cnt,0,sizeof(cnt));
    cnt[start] = 1;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        vis[u] = 0;

        for(int i = 0; i < e[u].size();i++ )
        {
            int v = e[u][i].v;
            if(dist[v] > dist[u] + e[u][i].cost){
                dist[v] = dist[u] + e[u][i].cost;
                if(!vis[v]){
                    vis[v] = 1;
                    que.push(v);
                    if(++cnt[v] > n)
                        return false;
                    //cnt[i]为入队列次数，用来判定是否存在负环回路
                }
            }
        }
    }
    return true;
}
int main(){

    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0;i < n;i++)
            e[i].clear();
        int a,b,x;
        for(int i = 0;i < m;i++){
            scanf("%d%d%d",&a,&b,&x);
            addedge(a,b,x);
            addedge(b,a,x);
        }

        int start,end;
        scanf("%d%d",&start,&end);
        spfa(start,n);
        if(dist[end] == inf)
            printf("-1\n");
        else
            printf("%d\n",dist[end]);
    }
    return 0;
}

