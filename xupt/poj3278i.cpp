#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n,k,vis[100005];

struct node{
    int tim;
    int bu;
} 
bool panduan(int x){
    if(x >= 0 && x <= 100000 && vis[x]!=1){
        return 1;
    }
    else{
        return 0;
    }
}

void bfs(){
    queue <node> q;
    q.push();
    memset(vis,0,sizeof(vis));    
    vis[n] = 1;

    while(!q.empty()){
        
        int temp = q.front();
        q.pop();
        if(temp == k){
            printf("%d",T[temp]);
            return;
        }
            int nwei = temp - 1;
            if(panduan(nwei)){
                vis[nwei] = 1;
                q.push(nwei);
                T[nwei] = T[temp]+1;
            }
            nwei = temp + 1;
            if(panduan(nwei)){
                vis[nwei] = 1;
                T[nwei] = T[temp] + 1;
                q.push(nwei);
            }
            nwei = temp * 2;
            if(panduan(nwei)){
                vis[nwei] = 1;
                T[nwei] = T[temp] + 1;
                q.push(nwei);
        }
    }
}


int main(){
    
    scanf("%d%d",&n,&k);

    bfs();

    return 0;
}
