#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n,k,mp[10][10],vis[10],cnt = 0,sum = 0;
void dfs(int ceng,int shu)
{
    int flag = 0;
    if(shu==k)
    {
        sum++;
        return;
    }
    if(ceng>=n+1)
    {
        return;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            if(vis[i]!=1 && mp[ceng][i]=='#')
            {
                flag=1;
                vis[i] = 1;
                dfs(ceng+1,++shu);
                vis[i] = 0;
                shu--;
            }
        }
    }
    dfs(ceng+1,shu);
}
int main(){
    while(scanf("%d%d",&n,&k)&&n!=-1&&k!=-1)
    {
        while(getchar()!='\n');
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                scanf("%c",&mp[i][j]);
            }
            while(getchar()!='\n');
        }
        /* for(int i = 1;i <= n;i++) */
        /* { */
        /*     for(int j = 1;j <= n;j++) */
        /*     { */
        /*         printf("%c",mp[i][j]); */
        /*     } */
            /* putchar('\n'); */
        /* } */
        cnt = 0,sum = 0;
        dfs(1,0);
        printf("%d\n",sum);
    }
    return 0;
}
