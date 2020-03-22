#include<stdio.h>
#include<queue>
using namespace std;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
char mp[1010][1010];
int vis[1010][1010];
int m,n;
int chux,chuy;
int ans;
struct node
{
    int a;
    int b;
};
void bfs(int a,int b)
{
    struct node tmp = {a,b};
    queue<struct node> que;
    que.push(tmp);
    while(que.size())
    {
        struct node flag = que.front();
        que.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int nx = flag.a+xx[i];
            int ny = flag.b+yy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n &&vis[nx][ny]==0 && mp[nx][ny]=='P')
            {
                struct node dd = {nx,ny};
                vis[nx][ny] = 1;
                que.push(dd);
                ans++;
            }
        }
        }
}
int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%s",mp[i]);
        for(int j = 0 ; j < n ; j++)
        if(mp[i][j] == 'Z')
        {
            chux = i;
            chuy = j;
        }
    }
    bfs(chux,chuy);
    printf("%d",ans+1);
    return 0;
}
