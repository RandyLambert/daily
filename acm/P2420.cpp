#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
    int v,w;
};
vector<node>mp[maxn];
int dfn[maxn],fa[maxn];
bool vis[maxn];

int findf(int x){
    if(x == fa[x])
        return x;
    else return fa[x] = findf(fa[x]);
}
void dfs(int u){

    vis[u] = 1;
    for(auto &qid : mp[u]){
        if(qid.v == )
    }
}
int main(){
    int n,m,u,v,w;
    scanf("%d",&n);
    for(int i = 0;i < n-1;i++){
        scanf("%d%d%d",&u,&v,&w);
        node temp;
        temp.w = w;
        temp.v = v;
        mp[u].push_back(temp);
        temp.w = w;
        temp.v = u;
        mp[v].push_back(temp);
    }

    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&u,&v);
    }

    return 0;
}
