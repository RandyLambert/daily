#include "Tu_Alog.h"

int Kruskal:: find(int x) //并查集查找
{
    if (x == F[x])
    {
        return x;
    }
    else
        return F[x] = find(F[x]);
}


void Kruskal:: Addedge_Krus(int u, int v, int w) //加边
{
    edge_Krus[tol].u = u;
    edge_Krus[tol].v = v;
    edge_Krus[tol++].w = w;
}
int Kruskal:: solve(int n) //传入点数,返回最小生成树的权值,如果不连通返回 -1
{
    memset(F, - 1, sizeof(F));
    mySort(edge_Krus,0,tol);     
    /* std::sort(edge_Krus, edge_Krus + tol,cmp<Edge_Krus>); */
    int cnt = 0; //计算加入的边数
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge_Krus[i].u;
        int v = edge_Krus[i].v;
        int w = edge_Krus[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if (t1 != t2)
        {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    if (cnt < n - 1)
        return -1; //不连通
    else
        return ans;
}



void Dijkstra:: Addedge_Dijk(int u, int v, int w) //加边
{
    E_Dijk[u].push_back(Edge_Dijk(v, w));
}

void Dijkstra:: solve(int n, int start) //点的编号从 1 开始
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    std::priority_queue<qnode> que;

    while (!que.empty())
        que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while (!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (size_t i = 0; i < E_Dijk[u].size(); i++)
        {
            int v = E_Dijk[tmp.v][i].v;
            int cost = E_Dijk[u][i].cost;
            if (!vis[v] && dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}

