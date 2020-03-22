#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 5500;
vector<int>q[maxn];
int book[maxn],match[maxn];
bool dfs(int u)
{
    for(int i = 0;i < q[u].size();i++)
    {
        int v = q[u][i];
        if(!book[v]){
            book[v] = 1;
            if(match[v] == 0 || dfs(match[v]))
            {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i < maxn;i++)
            q[i].clear();
        memset(match,0,sizeof(match));

        for(int i = 1;i <= n;i++)
        {
            int m,x,y;
            scanf("%d",&m);
            for(int j = 0;j < m;j++)
            {
                scanf("%d%d",&x,&y);
                x = x*12 + y;
                q[i].push_back(x);
            }
        }

        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            memset(book,0,sizeof(book));
            if(dfs(i))
                ans++;
        }

        printf("%d\n",ans);
    }
    return 0;
}

