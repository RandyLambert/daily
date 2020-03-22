#include<stdio.h>
int xx[8] = {0,1,0,-1,1,1,-1,-1};
int yy[8] = {1,0,-1,0,-1,1,1,-1};
char map[102][102];
int m = 0,n = 0;

int panduan(int x,int y){
    if(x>=1&&y>=1&&x<=m&&y<=n&&map[x][y]!='*'){
        return 1;
    }
    else{
        return 0;
    }
}
void dfs(int x,int y){
    for(int i = 0;i < 8;i++){
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(panduan(nx,ny)){
            map[nx][ny] = '*';
            dfs(nx,ny);
        }
    }
}
int main(){

    while(1){
        int sum = 0;
        scanf("%d%d",&m,&n);
        getchar();
        if(m == 0 || n == 0){
            break;
        }
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                scanf("%c",&map[i][j]);
            }
            while(getchar()!='\n');
        }

        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(map[i][j] == '@'){
                    map[i][j] = '*';
                    dfs(i,j);
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
