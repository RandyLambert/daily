#include<cstdio> 
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

vector<pair<int,int>>bridge;
vector<int> g[10010];
int dfn[10010],low[10010];
int deep,root,n,m,ans;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
int tarjan(int u,int fa)
{
    int lowu;
    lowu=dfn[u]=++deep;
    int sz=g[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            int lowv=tarjan(v,u);
            lowu=min(lowu,lowv);
            if(lowv>dfn[u])
            {
                int from,to;
                from=u;
                to=v;
                if(from>to)
                {
                    swap(from,to);
                }
                bridge.push_back(make_pair(from,to));
            }
        }
        else
        {
            if(v!=fa&&dfn[v]<dfn[u])
            {
                lowu=min(lowu,dfn[v]);
            }
        } 
    }
    low[u]=lowu;
    return lowu;
} 

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int from,to;
        scanf("%d%d",&from,&to);
        g[from].push_back(to);
        g[to].push_back(from);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            root=i;
            tarjan(i,-1);
        }
    }
    sort(bridge.begin(),bridge.end(),cmp);
    for(int i=0;i<bridge.size();i++)
    {
        printf("%d %d\n",bridge[i].first,bridge[i].second);
    }
}
