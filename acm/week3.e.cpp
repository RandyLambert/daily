#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0,1,-1,0};
int yy[4] = {1,0,0,-1};
int m,n,mp[105][105],vis[105][105];
struct node{
    int x,y,step;
};
queue <node> q;
int main(){
    int t,x1,y1,x2,y2,tou;
    scanf("%d",&t);
    while(getchar()!='\n');
    while(t--)
    {
        while(!q.empty()) q.pop();
        int flag = 0;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&m,&n);
        while(getchar()!='\n');

        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                scanf("%c",&mp[i][j]);
            }
            while(getchar()!='\n');
        }

        /* for(int i = 1;i <= m;i++) */
        /* { */
        /*     for(int j = 1;j <= n;j++) */
        /*     { */
        /*         printf("%c ",mp[i][j]); */
        /*     } */
        /*     putchar('\n'); */
        /* } */

        cin>>tou>>y1>>x1>>y2>>x2;
        vis[x1][y1] = 1;
        node start;
        start.x = x1;
        start.y = y1;
        start.step = -1;
        q.push(start);
        
        while(!q.empty())
        {
            node temp = q.front();
            q.pop();
            if(temp.x==x2&&temp.y==y2&&temp.step<=tou)
            {
                flag = 1;
                printf("yes\n");
                break;
            }
            for(int i = 0;i < 4;i++)
            {
                node nw;
                nw = temp;
                nw.x = xx[i] + nw.x;
                nw.y = yy[i] + nw.y;
                while(nw.x<=m&&nw.x>=1&&nw.y<=n&&nw.y>=1&&mp[nw.x][nw.y]=='.')
                {
                    if(!vis[nw.x][nw.y])
                    {
                        nw.step = temp.step+1;
                        vis[nw.x][nw.y] = 1;
                        if(nw.x==x2&&nw.y==y2&&nw.step<=tou)
                        {
                            flag = 1;
                            printf("yes\n");
                            break;

                        }
                        q.push(nw);
                    }
                    nw.x = nw.x + xx[i];
                    nw.y = nw.y + yy[i];
                }
            }
        }
        if(flag==0)
            printf("no\n");
        /* else */
            /* printf("yes\n"); */
        /* for(int i = 1;i <= n;i++){ */
        /*     for(int j = 1;j <= m;j++){ */
        /*         printf("%d ",vis[i][j]); */
        /*     } */
        /*     putchar('\n'); */
        /* } */
    }
    return 0;
}
