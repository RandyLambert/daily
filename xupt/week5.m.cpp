#include <bits/stdc++.h>
using namespace std;
int sum[105];
int f[105][105];
int f1[105][105];
int main(){
    int n,s;
    while(scanf("%d",&n)!=EOF){
        memset(f,1000000,sizeof(f));
        memset(f1,0,sizeof(f1));
        memset(sum,0,sizeof(sum));

        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&s);
            sum[i] = s + sum[i-1];
            f[i][i] = 0;
        }
        
        for(int len = 2;len <= n;len++)
        {
            for(int i = 1;i <= n;i++)
            {
                int j = len + i - 1;
                if(j>n) break;
                for(int k = i;k < j;k++)
                {
                    f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + sum[j] - sum[i-1]);
                }
            }
        }

        for(int len = 2;len <= n;len++)
        {
            for(int i = 1;i <= n;i++)
            {
                int j = len + i - 1;
                if(j>n) break;
                for(int k = i;k < j;k++)
                {
                    f1[i][j] = max(f1[i][j],f1[i][k] + f1[k+1][j] + sum[j] - sum[i-1]);
                }
            }
        }

        printf("%d %d\n",f[1][n],f1[1][n]);

    }
    return 0;
}
