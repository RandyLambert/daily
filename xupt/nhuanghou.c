#include<stdio.h>
int n;
int vis[14][14];
int ci;
int panduan(int x,int y){
    int flag = 1;
    for(int i = 1;i <= n;i++ ){
        if(vis[i][y]==1||vis[x][i]==1){
            flag = 0;
        }
        if(x-i>=1&&y-i>=1){
            if(vis[x-i][y-i]==1)
                flag = 0;
        }
        if(x+i<=n&&y+i<=n){
            if(vis[x+i][y+i]==1)
                flag = 0;
        }
        if(x-i>=1&&y+i<=n){
            if(vis[x-i][y+i]==1)
                flag = 0;
        }
        if(x+i<=n&&y-i>=1){
            if(vis[x+i][y-i]==1)
                flag = 0;
        }
    }
    return flag;
}
void dfs(int x,int y){
    if(x == n){
        ci++;

        if(ci<=15){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    printf("%d ",vis[i][j]);
                }
                printf("\n");

            }
            printf("\n");
        }
    }
    else{
        for(int i = 1;i <= n;i++){
            
            if(panduan(x,y)){
                vis[x][i] = 1;
                dfs(x+1,1);
            }
        }
    }

}
int main(){

    scanf("%d",&n);
    dfs(1,1);
    printf("%d",ci);
    return 0;
}
