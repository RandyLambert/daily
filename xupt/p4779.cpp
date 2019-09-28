#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int maxn = 100010;
struct qnode
{
    int v,c;
    qnode(int _v = 0,int _c = 0):v(_v),c(_c){}
    bool operator < (const qnode& a) const
    {
        return c > a.c;
    }
};

struct edge{
    int v,cost;
    edge(int _v = 0,int _cost = 0):v(_v),cost(_cost){}
};

vector <edge> e[maxn];
bool vis[maxn];
int dist[maxn];
//点的编号从1开始
//

void disa(int n,int start)
{
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++)
        dist[i] = inf;
    priority_queue<qnode>que;
    while(!que.empty())
        que.pop();
    dist[start] = 0;
    que.push(qnode(start,0));
    
    qnode tmp;

    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])
            continue;
        vis[u] = 1;

        for(int i = 0;i < e[u].size();i++)
        {
            int v = e[tmp.v][i].v;
            int cost = e[u][i].cost;
            if(!vis[v]&&dist[v] > dist[u]+cost)
            {
                dist[v] = dist[u] + cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    e[u].push_back(edge(v,w));
}

int main(){
    int n,m,s,v1,v2,w;
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d",&v1,&v2,&w);
        addedge(v1,v2,w);
        /* addedge(v2,v1,w); */
    }
    disa(n,s);
    for(int i = 1;i <= n;i++)
        printf("%d ",dist[i]);
    putchar('\n');
    return 0;
}
