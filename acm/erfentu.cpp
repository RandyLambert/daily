#include <bits/stdc++.h>
using namespace std;
const int maxn = 5100;
typedef long long ll;
vector<int>q[maxn];
int match[maxn],book[maxn];
int dfs(int u)
{
    for(size_t i = 0;i < q[u].size();i++)
    {
        int t = q[u][i];
        if(book[t] == 0)
        {
            book[t] = 1;
            if(match[t] == 0 || dfs(match[t]))
            {
                match[t] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){

    int k,n,m,a,b,sum = 0;
    while(scanf("%d",&k)&&k){
        for(int i = 0;i < maxn;i++)
            q[i].clear();
        memset(book,0,sizeof(book));
        memset(match,0,sizeof(match));

        scanf("%d%d",&n,&m);
        for(int i = 0;i < k;i++)
        {
            scanf("%d%d",&a,&b);
            q[a].push_back(b);
        }
        
        for(int i = 0;i <= n;i++)
            match[i] = 0;

        for(int i = 1;i <= n;i++)
        {
            memset(book,0,sizeof(book));
            if(dfs(i))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
