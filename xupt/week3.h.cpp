#include <bits/stdc++.h>
using namespace std;
const int num = 1e6+10;
int n,c = 0;
long long int ans = 0;
bool color[num];
vector<int>q[num];
void dfs(int u,int v)
{
    color[v] = !color[u];
    if(color[v]==1) c++;
     for(int i=0;i<q[v].size();i++)
    if(q[v][i]!=u)dfs(v,q[v][i]);
}
void DFS(int u,int v)
{
    if(color[v]==1) ans = ans + (n-c-q[v].size());
    for(int i = 0;i < q[v].size();i++)
    {
        if(q[v][i]!=u)
            DFS(v,q[v][i]);
    }
}
int main(){
    int u,v;
    cin>>n;
    for(int i = 0;i < n-1;i++)
    {
        cin>>u>>v;
        q[u].push_back(v);
        q[v].push_back(u);
    }
    color[0]=0;
    dfs(0,1);
    DFS(0,1);
    printf("%lld\n",ans);
    return 0;
}
