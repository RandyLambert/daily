#include <iostream>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;
int m;
int aa[1000005];

struct node{
    int x,step;
};
queue <node> q;
void bfs(int qi){
    node start;
    start.x = qi;
    start.step = 0;
    aa[qi] = 1;
    q.push(start);
    while(!q.empty()){
        node temp;
        temp = q.front();
        q.pop();

        if(temp.x == m){
            printf("%d\n",temp.step);
            return;
        }
        
        int nx = temp.x + 1;
        if(nx >= 0 && nx <= 100000 && aa[nx]!=1){
            node nw;
            nw.step = temp.step + 1;
            nw.x = nx;
            aa[nx] = 1;
            q.push(nw);
        }
        nx = temp.x - 1;
        if(nx >= 0 && nx <= 100000 && aa[nx]!=1){
            node nw;
            nw.step = temp.step + 1;
            nw.x = nx;
            aa[nx] = 1;
            q.push(nw);
        }
         nx = temp.x * 2;
        if(nx >= 0 && nx <= 100000 && aa[nx]!=1){
            node nw;
            nw.step = temp.step + 1;
            nw.x = nx;
            aa[nx] = 1;
            q.push(nw);
        }
    }
}
int main(){
    int n;
    while(~scanf("%d%d",&n,&m))
    {
        memset(aa,0,sizeof(aa));
        bfs(n);
    }
    return 0;
}
