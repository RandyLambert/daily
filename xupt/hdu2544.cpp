#include <bits/stdc++.h>
using namespace std;
int mp[105][105];
int ans[105],mx = 0xfffffff;
int vis[105];
int main()
{
    int n,m,x,y,z;
    while(scanf("%d%d",&n,&m),n||m)
    {

        memset(vis,0,sizeof(vis));

        /* if(n == 0 && m == 0) */
        /* { */
        /*     return 0; */
        /* } */
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                mp[i][j] = mx;
            }
        }

        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            mp[x][y] = mp[y][x] = z;
        }

        for(int i = 1;i <= n;i++)
        {
            ans[i] = mp[1][i];
        }
        vis[1] = 1;
        ans[1] = 0;
        
        for(int i = 1;i <= n;i++)
        {
            int pos;
            int mi = mx;
            for(int j = 1;j <= n;j++)
            {
                if(mi > ans[j] && vis[j]==0)
                {
                    mi = ans[j];
                    pos = j;
                }
            }
            vis[pos] = 1;
            
            for(int k = 1;k<=n;k++)
            {
                if(ans[k] > ans[pos] + mp[pos][k] && !vis[k])
                {
                    ans[k] = ans[pos] + mp[pos][k];
                }
            }
        }
        printf("%d\n",ans[n]);
    }

    return 0;
}
