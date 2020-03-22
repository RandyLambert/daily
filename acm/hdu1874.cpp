#include <bits/stdc++.h>
using namespace std;
#define N 205
int dist[210],vis[210],cnt[210];//vis在对列的标志 cnt每个点的如队列次数
const int inf = 10000000;
int mp[N][N];
void spfa(int start,int n)
{
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i++)
        dist[i] = inf;

    queue<int>que;
    vis[start] = 1;
    dist[start] = 0;
    que.push(start);
    while(!que.empty())
    {
        int temp = que.front();
        que.pop();

        vis[temp] = 0;

         for(int i = 0; i < n; i++)
            if(dist[i] > mp[temp][i]+dist[temp])
            {
               dist[i] = dist[temp] + mp[temp][i];
                if(!vis[i])
                {
                    //cout<<i<<endl;
                    que.push(i);
                    vis[i] =1;
                }
            }
    }
}
int main(){

    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mp[i][j] = mp[j][i] = inf;

        for(int i = 0;i < m;i++){
	    int a,b,x;
            scanf("%d%d%d",&a,&b,&x);
	if(mp[a][b] > x)
            mp[a][b] = mp[b][a] = x;

        }

        int start,end;
        scanf("%d%d",&start,&end);
        spfa(start,n);
	if(dist[end] == inf) printf("%d\n",-1);
        else printf("%d\n", dist[end]);
 
    }
    return 0;
}
