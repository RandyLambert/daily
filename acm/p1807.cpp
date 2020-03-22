#include <bits/stdc++.h>
using namespace std;
int q[1505][1505];
/* int find(int x) */
/* { */
/*     if(x==f[x]) */
/*     { */
/*         return x; */
/*     } */
/*     else */
/*     { */
/*         return f[x] = find(f[x]); */
/*     } */
/* } */

int main(){
    int n,m,a,b,v;
    scanf("%d%d",&n,&m);
    for(int i  = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            if(i==j)
            {
                q[i][j] = 0;
            }
            else{
                q[i][j] = -199999;
            }
        }
    }
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d",&a,&b,&v);
        if(v>q[a][b])
        {
            q[a][b] = v;
        }
    }

    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(q[i][j]<q[i][k]+q[k][j])
                {
                    q[i][j] = q[i][k]+q[k][j];
                }
            }
        }
    }
    if(q[1][n]<-1000)
        printf("-1\n");
    else
        printf("%d\n",q[1][n]);
    return 0;
}
