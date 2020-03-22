#include <iostream>
#include <queue>

using namespace std;

int a[11][11] = {
     {1,1,1,1,1,1,1,1,1,1},
     {1,0,0,1,0,0,0,1,0,1},
     {1,0,0,1,0,0,0,1,0,1},
     {1,0,0,0,0,1,1,0,0,1},
     {1,0,1,1,1,0,0,0,0,1},
     {1,0,0,0,1,0,0,0,0,1},
     {1,0,1,0,0,0,1,0,0,1},
     {1,0,1,1,1,0,1,1,0,1},
     {1,1,0,0,0,0,0,0,0,1},
     {1,1,1,1,1,1,1,1,1,1}
};
int b[11][11];
int xx[4] = {-1,0,1,0};
int yy[4] = {0,1,0,-1};
int ex = 8,ey = 8;

struct node{
    int x;
    int y;
    int step;
};

void bfs(){
    node start;
    start.x = 1;
    start.y = 1;
    start.step = 0;
    b[1][1] = 0;

    queue <node> q;
    while(!q.empty()) q.pop();

    q.push(start);

    while(!q.empty()){
        node temp;

        temp = q.front();
        q.pop();

        if(temp.x == 8 && temp.y == 8){
            printf("\n\n    : %d\n\n",temp.step);
            //break; 结束就停止
        }
        else{
            for(int i = 0;i < 4;i++){
                int nx = temp.x + xx[i];
                int ny = temp.y + yy[i];

                if(ny >= 1&& nx>= 1 && ny <=8 && nx<=8 && a[nx][ny] == 0 && b[nx][ny] == 0){

                    b[nx][ny] = 1;
                    node tp;
                    tp.step=temp.step+1;
                    printf("%d\n",tp.step);

                    tp.x=nx;
                    tp.y=ny;
                    q.push(tp);

                }
            }
        }
    }    
}
int main(){
    bfs();
     for(int i=1;i<=8;i++)//可以通过输出b数组来观察bfs的实现过程
            {
                for(int j=1;j<=8;j++)
                {
                    printf("%5d",b[i][j]);
                }
                cout<<endl;
            }

    return 0;
}
