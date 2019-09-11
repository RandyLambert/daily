#include <iostream>
#include <queue>

using namespace std;

int a[31][31],b[31][31];
int kuan;

int nx[4] = {0,1,-1,0};
int ny[4] = {1,0,0,-1};
struct node{
    int x;
    int y;
};


void bfs(int x,int y){
    queue <node> q;
    while(!q.empty()) q.pop();

    node start;
    start.x = x;
    start.y = y;
    a[x][y] = -1;
    
    q.push(start);

    while(!q.empty()){
        node temp;
        temp = q.front();
        q.pop(); 
        for(int i = 0;i < 4;i++){
            int xx = temp.x + nx[i];
            int yy = temp.y + ny[i];
            if(xx>=1 && yy>=1 && xx<=kuan && yy<=kuan && a[xx][yy] == 0){
                node nex;
                nex.x = xx;
                nex.y = yy;
                a[xx][yy] = -1;
                q.push(nex);
            }
        }
    }
}

void bfs2(int x,int y){
    queue <node> q;
    while(!q.empty()) q.pop();

    node start;
    start.x = x;
    start.y = y;
    a[x][y] = 2;
    
    q.push(start);

    while(!q.empty()){
        node temp;
        temp = q.front();
        q.pop(); 
        for(int i = 0;i < 4;i++){
            int xx = temp.x + nx[i];
            int yy = temp.y + ny[i];
            if(xx>=1 && yy>=1 && xx<=kuan && yy<=kuan && a[xx][yy] == 0){
                node nex;
                nex.x = xx;
                nex.y = yy;
                a[xx][yy] = 2;
                q.push(nex);
            }
        }
    }
}

int main(){
        scanf("%d",&kuan);
        if(kuan>1){
            for(int i = 1;i <= kuan;i++){
                for(int j = 1;j <= kuan;j++){
                    scanf("%d",&a[i][j]);
                }
            }

            for(int i = 1;i <= kuan;i++){
                for(int j = 1;j <= kuan;j++){
                    if(i == 1 || j == 1 || i == kuan ||j == kuan){
                        if(a[i][j] == 0)
                            bfs(i,j);
                    }
                }
            }


            for(int i = 2;i < kuan;i++){
                for(int j = 2;j < kuan;j++){
                        if(a[i][j] == 0)
                            bfs2(i,j);
                    }
                }



            for(int i = 1;i <= kuan;i++ ){
                for(int j = 1;j <= kuan;j++){
                    if(a[i][j] != -1)
                        printf("%d ",a[i][j]);
                    else
                        printf("%d ",0);
                }
                printf("\n");
            }
        }
        else{
            printf("%d",2);
        }

    return 0;
}
