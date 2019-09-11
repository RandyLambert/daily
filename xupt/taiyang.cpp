#include<bits/stdc++.h>
using namespace std;
int mp[505][505];
int vis[505][505];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int num;
void solve(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==0&&mp[xx][yy]==0)
		{
			num++;
			vis[xx][yy]=1;
			solve(xx,yy);
		}
	}
}
int main()
{

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		scanf("%d",&mp[i][j]);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==0&&vis[i][j]==0)
			{
				vis[i][j]=1;
				num=1;
				solve(i,j);
				ans=max(ans,num);
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
