#include<stdio.h>
int a[35],b[35],min = 9999999,n;
void dfs(int vx,int step){
    if(step == n+1){
        if(min > vx){
            min = vx;
        }
    }
    else{
        for(int i = 0;i < n;i++){
            if(vx >= a[i]&&b[i]==0){
                b[i] = 1;
                dfs(vx-a[i],step+1);
                b[i] = 0;
            }
            else{
                dfs(vx,step+1);
            }
                
        }
    }
}
int main(){
    int v;
    scanf("%d%d",&v,&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    dfs(v,1);
    printf("%d",min);
    return 0;
}
