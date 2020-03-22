#include <iostream>
#include <cstdio>

using namespace std;
int p,q,flag = 0;
int xx[8] = {1,-1,2,-2,1,-1,2,-2};
int yy[8] = {2,-2,1,-1,-2,2,-1,1};

int vis[27][27],path[88][2];

int panduan(int x,int y){
    if(x<=p&&y<=q&&x>=1&&y>=1&&!vis[x][y]){
        return 1;
    }
    else{
        return 0;
    }
}
void dfs(int x,int y,int step){

    path[step][0] = x;
    path[step][1] = y;
    if(step == q*p){
        flag = 1;
        return;
    }
    else{
        for(int i = 0;i < 8;i++){
            int fx = x + xx[i];
            int fy = y + yy[i];
            if(panduan(fx,fy)){
                vis[fx][fy] = 1;
                dfs(fx,fy,step+1);
                vis[fx][fy] = 0;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&p,&q);
        dfs(1,1,1);
        if(flag){
            for(int i = 1; i <= p * q; i++)
                printf("%c%d",path[i][1] - 1 + 'A',path[i][0]);
        }
        else
            printf("impossible");
        printf("\n");
        flag = 0;
    }
    return 0;
}
