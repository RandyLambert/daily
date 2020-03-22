#include<bits/stdc++.h>
using namespace std;
char _map[1001][1001];//_map数组保存地图 
int flag[1001][1001],a[1000001];//a数组要开大一点，刚开始开a[1001]错了3个点 
//flag数组保存各个点所在的连通图，以及是否已经处理过，a数组保存各个连通图的大小
struct mg
{
    int x,y;
}q[1000001];
int main()
{
    int sx,sy,i,j,n,m,l,nx,ny,k,f,r,sum,d;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};//四个方向
    scanf("%d %d",&n,&m);//n是正方形地图边长，m是数据组数 
    memset(a,0,sizeof(a));
    memset(flag,0,sizeof(flag)); //你可以无视这两行memset
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>_map[i][j];//读入地图 
    d=0;//d用来保存当前是在第几个连通图中 
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(flag[i][j]==0)//如果当前位置不在已知连通图中（还未处理过） 
            {
                d++;//记录当前所在连通图数 
                f=1;
                r=1;
                q[f].x=i;
                q[f].y=j;
                flag[i][j]=d;
                sum=1;//初始化
                while(f<=r)
                {
                    for(k=0;k<4;k++)
                    {
                        nx=q[f].x+dx[k];
                        ny=q[f].y+dy[k];
                        if(flag[nx][ny]==0&&nx>=1&&nx<=n&&ny>=1&&ny<=n&&((_map[nx][ny]=='1'&&_map[q[f].x][q[f].y]=='0')||(_map[nx][ny]=='0'&&_map[q[f].x][q[f].y]=='1')))
                        //如果新位置能走且在地图上 
                        {
                            r++;
                            sum++;//计数器累加 
                            flag[nx][ny]=d;//标记新位置在第d个连通图中 
                            q[r].x=nx;
                            q[r].y=ny;//更新位置 
                        }
                    }
                    f++;
                }
                a[d]=sum;//保存当前连通图能移动到多少格 
            }
    for(i=1;i<=m;i++)
    {
        cin>>sx>>sy;//读入询问 
        cout<<a[flag[sx][sy]]<<endl;//直接查找答案并输出 
    }
    return 0;
}
