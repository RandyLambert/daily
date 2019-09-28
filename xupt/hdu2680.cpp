#include <bits/stdc++.h>
using namespace std;
const int inf = 0xffffff1;
int mp[1010][1010];
int ans[1010];
bool vis[1010];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,s,p,q,t;
    while(cin>>n>>m>>s)
    {
        memset(vis,0,sizeof(vis));

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(i == j)
                    mp[i][j] = 0;
                else
                    mp[i][j] = inf;
            }
        }

        for(int i = 0;i < m;i++)
        {
            cin>>p>>q>>t;
            if(t < mp[q][p])
                mp[q][p] = t;
        }

        for(int i = 1;i <= n;i++)
        {
            ans[i] = mp[s][i];
        }

        ans[s] = 0;
        vis[s] = 1;
        
        for(int i = 1;i <= n;i++ )
        {
            int pos,mi = inf;

            for(int j = 1;j <= n;j++)
            {
                if(mi > ans[j] && vis[j] == 0)
                {
                    mi = ans[j];
                    pos = j;
                }
            }

            vis[pos] = 1;
            for(int j = 1;j <= n;j++)
            {
                if(mp[pos][j] != inf && ans[j] > ans[pos] + mp[pos][j] && vis[j] == 0)
                {
                    ans[j] = ans[pos] + mp[pos][j];
                }
            }
        }
        int x,y,an = inf;
        cin>>x;
        for(int i = 0;i < x;i++)
        {
            cin>>y;
            if(ans[y] < an)
                an = ans[y];
        }

        if(an == inf)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<an<<endl;
        }
    }

    return 0;
}

