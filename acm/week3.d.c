#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int parent[1000],casei[1000];
int find(int x){
    if(parent[x] == x)
        return x;
    else{
        parent[x] = find(parent[x]);
        return parent[x];
    }
}
int unionr(int x,int y){
    int xroot = find(x);
    int yroot = find(y);

    if(xroot != yroot)
        parent[yroot] = xroot;
}
int main(){
    int n,m,x,y,h = 0;
    while(scanf("%d%d",&n,&m)&&n&&m){
        h++;
        int sum = 0;
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
        for(int i = 0;i < m;i++){
            scanf("%d%d",&x,&y);
            unionr(x,y);
        }   

        /* for(int i = 1;i <= n;i++){ */
        /*     printf("%d  ",parent[i]); */
        /* } */

        for(int i = 1;i <= n ;i++){
            if(parent[i]==i){
                sum++;
            }
        }
        casei[h] = sum;
    }
    for(int i = 1;i <= h;i++){
        printf("Case %d: %d\n",i,casei[i]);
    }
    return 0;
}
