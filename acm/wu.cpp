//
// Created by randylambert on 2020/8/10.
//

#include <bits/stdc++.h>
using namespace std;
const int N=100010;
const int INF=0x3f3f3f3f;
int n,m;
int H[N];
int head[N],cnt;
bool vis[N];
struct node{
    int to,nex,w;
}edge[N*4];
struct node1{
    int	value,fa;
    node1(int value,int fa)
    {
        this->value=value;
        this->fa=fa;
    }
    node1() = default;
}lowc[N];

void init()
{
    memset(head,-1,sizeof(head));
    memset(lowc,INF,sizeof(lowc));
    memset(vis,false,sizeof(vis));
    cnt=0;
}
void addedge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].nex=head[u];
    edge[cnt].w=w;
    head[u]=cnt++;
}
int prim()
{
    int ans=1;
    lowc[1]=node1(0,0);
    vis[1]=0;
    for(int i=head[1];i!=-1;i=edge[i].nex)
    {
        int v=edge[i].to;
        if(H[1]>=H[v])
        {
            lowc[v].value=edge[i].w;
            lowc[v].fa=1;
        }
    }
    while(1)
    {
        int minn=INF,k=-1;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&lowc[i].value<minn)
            {
                minn=lowc[i].value;
                k=i;
            }
        if(k==-1) break;
        vis[k]=true;
        ans++;
        for(int i=head[k];i!=-1;i=edge[i].nex)
        {
            if(!vis[i]&&lowc[i].value>edge[i].w)
            {
                lowc[edge[i].to]=node1(edge[i].w,k);
            }
        }
    }
    return ans;
}
int main()
{
    int x,y,w,number;
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++)
        cin>>H[i];
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        addedge(x,y,w);
        addedge(y,x,w);
    }
    number=prim();

}