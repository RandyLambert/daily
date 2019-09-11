#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
    int n,m,x,y,ans = 0;
    scanf("%d%d",&n,&m);
    /* for(int i = 0;i < 105;i++) */
    /*     for(int j= 0;j < 105;j++){ */
    /*         if(i==j) */
    /*             a[i][j] = 0; */
    /*         else */
    /*             a[i][j] = 999999999; */
    /*     } */
    for(int i = 0;i < m;i++){
        scanf("%d%d",&x,&y);
            a[x][y] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(a[j][i]&&a[i][k]==1)
                    a[j][k] = 1;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        int flag = 1;
        for(int j = 1;j <= n;j++){
            if(i==j) continue;
            else{
                flag = flag&&(a[i][j]||a[j][i]);
            }
            /* printf("%d ",a[i][j]); */
        }
            ans+=flag;
        /* putchar('\n'); */
    }
    printf("%d\n",ans);

    return 0;
}

