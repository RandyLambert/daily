#include <bits/stdc++.h>
using namespace std;
const int mod = 100003;
const int INF=0x3f3f3f3f;
const int MAXN=1000010;
struct qnode{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const{
        return c>r.c;
    }
};
struct Edge{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
int ans[MAXN];
//点的编号从 1 开始
void Dijkstra(int n,int start){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty()){
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(decltype(E[u].size()) i=0;i<E[u].size();i++){
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v] > dist[u]+cost){
                dist[v]=dist[u]+cost;
                ans[v] = (ans[u]+ans[v])%mod;
                que.push(qnode(v,dist[v]));
            }
            else if(dist[v] == dist[u]+1){
                ans[v] = (ans[u]+ans[v])%mod;
            }
        }
    }
}
void addedge(int u,int v,int w){
    E[u].push_back(Edge(v,w));
}


int main(){
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    ans[1] = 1;
    for(int i = 1;i <= m;i++){
        scanf("%d%d",&x,&y);
        addedge(x,y,1);
        addedge(y,x,1);
    }
    Dijkstra(n,1);
    for(int i = 1;i <= n;i++)
        printf("%d\n",ans[i]);

    return 0;
}
