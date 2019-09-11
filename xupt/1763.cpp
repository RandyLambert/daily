#include<stdio.h>
#include<queue>

using namespace std;
int xx[4] = {1,0,-1,0};
int yy[4] = {0,-1,0,1};
int n,m;
char ap[1004][1004];
int lie,hang;

struct node{
    int x;
    int y;
};

long long int cishu = 0;

void bfs(){
    queue<node>q;
    node frist;
    frist.x = lie;
    frist.y = hang;

    while(!q.empty()) q.pop();
    q.push(frist);

    while(!q.empty()){
        node temp;
        temp = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            node ne;
            int nx = temp.x + xx[i];
            int ny = temp.y + yy[i];

            if(nx<=n&&ny<=m&&nx>=1&&ny>=1&&ap[nx][ny]!='U'){
                cishu++;
                ne.x = nx;
                ne.y = ny;
                ap[nx][ny] = 'U';
                q.push(ne);
            }
        }
    }
}
int main(){
    
    scanf("%d%d",&n,&m);
    getchar();
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                scanf("%c",&ap[i][j]);
                if(ap[i][j]=='Z'){
                    lie = i;
                    hang = j;
                }
            }
           while( getchar()!='\n');
        }
        bfs();
        if(cishu != 0)
            printf("%lld",cishu);
        else
            printf("%d",1);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                printf("%c",ap[i][j]);
            }
            printf("\n");
        }
    return 0;
}
