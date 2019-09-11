#include <cstdio>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
int xx[6] = {1,0,-1,0,0,0};
int yy[6] = {0,1,0,-1,0,0};
int zz[6] = {0,0,0,0,-1,1};
char mp[32][32][32];
int vis[32][32][32];
struct node{
    int x,y,z,step;
};
int main(){
    int l=1,r=1,c=1,t1,t2,t3,t4,t5,t6;
    while(scanf("%d%d%d",&l,&r,&c)&&l!=0&&r!=0&&c!=0){
        for(int i = 1;i <= l;i++){
            for(int j = 1;j <= r;j++){
                for(int k = 1;k <= c;k++){
                    cin>>mp[i][j][k];
                    if(mp[i][j][k] == 'S'){
                        t1 = i;
                        t2 = j;
                        t3 = k;
                    }
                    if(mp[i][j][k] == 'E'){
                        t4 = i;
                        t5 = j;
                        t6 = k;
                    }

                }
            }
        }
        
        queue<node>q;
        while(!q.empty()) q.pop();
        node start;
        start.x = t1;
        start.y = t2;
        start.z = t3;
        start.step = 0;
        vis[t1][t2][t3] = 1;
        q.push(start);
        
        int ste = -1;
        while(!q.empty()){
            node temp = q.front();
            q.pop();
            if(temp.x == t4&&temp.y == t5&&temp.z == t6){
                printf("Escaped in %d minute(s).\n",temp.step);
                ste = temp.step;
                break;
            }
            else{
                for(int i = 0;i < 6;i++){
                    int nx = temp.x + xx[i];
                    int ny = temp.y + yy[i];
                    int nz = temp.z + zz[i];
                    if(nx>=1&&ny>=1&&nz>=1&&vis[nx][ny][nz]!=1&&mp[nx][ny][nz]!='#'&&nx<=l&&ny<=r&&nz<=c){
                        node nw;
                        nw.x = nx;
                        nw.y = ny;
                        nw.z = nz;
                        nw.step = temp.step+1;
                        q.push(nw);
                        vis[nx][ny][nz] = 1;
                    }
                }
            }
        }
        if(ste == -1){
            printf("Trapped!\n");
        }
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
    }
    return 0;
}
