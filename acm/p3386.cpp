#include <bits/stdc++.h>
using namespace std;
int n,m,e;
vector<int>q[2010];
int match[2010];
bool used[2010];
int dfs(int s)
{
    for(size_t i = 0;i < q[s].size();i++)
    {
        int v = q[s][i];
        if(used[v] == 0){
            used[v] = 1;
            if(match[v] == 0 || dfs(match[v])){
                match[v] = s;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&e);
    for(int i = 0;i < e;i++){
        int a1,a2;
        scanf("%d%d",&a1,&a2);
        if(a1 > n || a2 > m)
            continue;
        q[a1].push_back(a2);
    }
    int ans = 0;
    memset(match,0,sizeof(match));

    for(int i = 1;i <= n;i++){
        memset(used,0,sizeof(used));
        if(dfs(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
