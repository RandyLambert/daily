#include <queue>
#include <cstdio>
using namespace std;
int a[6][6];
int vis[6][6];
struct node {
    int x,y,step;
};
int lu[2][100];
int xx[4] = {-1,0,1,0};
int yy[4] = {0,-1,0,1};
void bfs(){
    queue <node> q;
    while(!q.empty()) q.pop();
    node start;
    start.x = 1;
    start.y = 1;
    start.step = 0;
    vis[1][1] = 1;
    lu[0][0] = 1;
    lu[1][0] = 1;
    q.push(start);

    while(!q.empty()){
        node temp = q.front();
        q.pop();

        if(temp.x == 5 && temp.y == 5){
            for(int i = 0;i < temp.step;i++){
                printf("(%d, %d)\n",lu[0][i]-1,lu[1][i]-1);
            }
            printf("(4, 4)\n");
            return;
        }
        else{
            for(int i = 0;i < 4;i++){
                int nx = temp.x + xx[i];
                int ny = temp.y + yy[i];
                if(nx<=5&&ny<=5&&nx>=1&&ny>=1&&a[nx][ny]==0&&vis[nx][ny]==0){
                    node nw;
                    nw.x = nx;
                    nw.y = ny;
                    nw.step = temp.step+1;
                    q.push(nw);
                    vis[nx][ny] = 1;
                    lu[0][nw.step] = nx;
                    lu[1][nw.step] = ny;
                }
            }
        }
    }
    
}
int main(){
    for(int i = 1;i < 6;i++){
        for(int j = 1;j < 6;j++){
            scanf("%d",&a[i][j]);
        }
    }

    bfs();
    return 0;
}
