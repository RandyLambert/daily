#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct node{
    int x;
    int y;
}q[1000001];
int xx[4] = {0,1,-1,0};
int yy[4] = {1,0,0,-1};

char mp[1001][1001];
int vis[1001][1001];
int a[1000001];

int main(){
    int i,j,d,f,r,step,n,m,t1,t2;
    scanf("%d%d",&n,&m);
    while(getchar()!='\n');
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            scanf("%c",&mp[i][j]);
        }
        while(getchar()!='\n');
    }

    d = 0;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(vis[i][j]==0)
            {
                d++;
                f=1;
                r=1;
                q[f].x=i;
                q[f].y=j;
                vis[i][j]=d;
                step=1;
            while(f <= r){
                for(int i = 0;i < 4;i++){
                    int nx = q[f].x + xx[i];
                    int ny = q[f].y + yy[i];
                if(vis[nx][ny]==0&&nx>=1&&nx<=n&&ny>=1&&ny<=n&&((mp[nx][ny]=='1'&&mp[q[f].x][q[f].y]=='0')||(mp[nx][ny]=='0'&&mp[q[f].x][q[f].y]=='1'))){
                    step++;
                    r++;
                    vis[nx][ny] = d;
                    q[r].x = nx;
                    q[r].y = ny;
                    }
                }
                f++;
            }
            a[d] = step;
       }
    for(i=1;i<=m;i++){
         cin>>t1>>t2;
         cout<<a[vis[t1][t2]]<<endl;
     }

    return 0;
}
