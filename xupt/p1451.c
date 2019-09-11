#include<stdio.h>
char map[501][501],ce[501][501];
int a,b,step;
int xx[4] = {1,0,-1,0},yy[4] = {0,1,0,-1};
int panduan(int x,int y){
    if(x>=1 && y>=1 && x<=a && y<=b &&map[x][y] != '0') return 1; 
    else        return 0;
}
void dfs(int x,int y){
    for(int i = 0;i < 4;i++){
        int nx = xx[i]+x;
        int ny = yy[i]+y;
        if(!ce[nx][ny]&&panduan(nx,ny)){
            ce[nx][ny] = 1;
            dfs(nx,ny);
           }
    }
}
int main(){
    scanf("%d%d",&a,&b);
    getchar();
    for(int i = 1;i <= a;i++){
        for(int j = 1;j <=b;j++){
            scanf("%c",&map[i][j]);
        }
        if(i != a)
        getchar();
    }
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            if(map[i][j]!='0'&&ce[i][j]==0){
                ce[i][j] = 1;
                step++;
                dfs(i,j);
            }
        }
    }
    printf("%d",step);

    /* for(int i = 1;i <= a;i++){ */
    /*     for(int j = 1;j <= a;j++){ */
    /*         printf("%d ",ce[i][j]); */
    /*     } */
    /*     printf("\n"); */
    /* } */

    return 0;
}
