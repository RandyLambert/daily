#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp;
char ch[50];
vector<int>p[50];
int chu[50],ru[50];
bool vis[50];
void dfs(int x){
    vis[mp[ch[x]]] = true;
    cout<<ch[x];
    for(size_t i = 0;i < p[x].size();i++){
        if(vis[mp[ch[p[x][i]]]]==false){
            dfs(p[x][i]);   
        }
    }
}

void bfs(){

    queue<int>que;
    que.push(mp[ch[1]]);
    vis[mp[ch[1]]] = true;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        cout<<ch[x];
        for(const auto &a : p[x]){
            if(vis[mp[ch[a]]]==false)
                que.push(a);
            vis[mp[ch[a]]] = true;
        }
    }
}
int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    for(int i = 1;i <= n;i++){
        char xx;
        scanf("%c",&xx);
        mp[xx]=i;
        ch[i] = xx;
    }
    getchar();

    for(int i=1;i<=m;i++){
        char u,v;
        scanf("%c%c",&u,&v);
        getchar();
        p[mp[u]].push_back(mp[v]);
        chu[mp[u]]++;
        ru[mp[v]]++;
    }

    for(int i = 1;i <= n;i++){
        cout<<ch[i]<<" "<<chu[i]<<" "<<ru[i]<<" "<<chu[i]+ru[i]<<"\n";
    }
    memset(vis,0,sizeof(vis));
    dfs(1);
    putchar('\n');
    memset(vis,0,sizeof(vis));
    bfs();
    putchar('\n');

    return 0;
}
