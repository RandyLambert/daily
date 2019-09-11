#include<stdio.h>
int map[151][151];
int ce[151][151];
int max;
int po,m,n;
int i=1,j=1;
int panduan(int x,int y){
    int i = x,j = y;
    int flag = 0;
    while(i>=1&&j>=1){
        if(ce[i][j]!=1){
            i--;
            j--;
        }
    }
    if(i == 0||j == 0){
        flag++;
    }
    i = x,j = y;

    while(i<=m&&j>=1){
        if(ce[i][j]!=1){
            i++;
            j--;
        }
    }
    if(i == m+1||j == 0){
        flag++;
    }

    i = x,j = y;

    while(i>=1&&j<=m){
        if(ce[i][j]!=1){
            i--;
            j++;
        }
    }
    if(i == 0||j == m+1){
        flag++;
    }

    i = x,j = y;

    while(i<=m&&j<=m){
        if(ce[i][j]!=1){
            i++;
            j++;
        }
    }
    if(i == m+1||j == m+1){
        flag++;
    }

    if(flag == 4){
        return 1;
    }
    else{
        return 0;
    }
}
void dfs(int x,int y,int step){
    printf("%d\n",step);
    if(x == n && y == n){
        /* if(map[n][n] != 1 && panduan(n,n)){ */
            /* ce[n][n] = 1; */
            /* step++; */
        /* } */

        if(max < step){
            printf("%d\n",step);
            max = step;
        }
    }
    else{
        for(;i <= n;i++){
            for(;j <= n;j++){
                if(map[i][j] != 1 && panduan(i,j)){

                ce[i][j] = 1;
                dfs(x,y,step+1);
                 ce[i][j] = 0;

                }
            }
        }
    }
}

int main(){
    int t1,t2,i;
    scanf("%d%d",&n,&m);
    for(i = 0;i < m;i++){
        scanf("%d%d",&t1,&t2);
        map[t1][t2] = 1;
    }
    /* for(int i = 1;i <= n;i++){ */
        /* for(int j = 1;j <= n;j++){ */
            /* printf("%d  ",map[i][j]); */
        /* } */
        /* printf("\n"); */
    /* } */
    dfs(1,1,1);
    printf("%d",max);


    return 0;
}
