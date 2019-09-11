#include<stdio.h>
int step;
int a[1000];
int m,n;
void dfs(int nx,int m){
    if(nx != n && m == 0){
        step++;
    }
    else if(nx == n && m != 0){
       return;
    }
    else if(nx == n &&m == 0){
        step++;
    }
    else{
        if(m >= a[nx]){
            dfs(nx+1,m-a[nx]);
            dfs(nx+1,m);
        }
        else{
            dfs(nx+1,m);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,m);
    printf("%d",step);
    return 0;
}
