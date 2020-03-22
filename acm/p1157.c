#include<stdio.h>
int book[22] = {0};
int ce[22];
int n,r;
void dfs(int h){
    if(h == r+1){
        for(int i = 1;i <= r;i++)
            printf("%d",ce[i]);
        printf("\n");
    }
    else{
        for(int i = 1;i <= n;i++){
            if(book[i] == 0 && ce[h-1] < i){
                book[i] = 1;
                ce[h] = i; 
                dfs(h+1);
                book[i] = 0;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&r);
    dfs(1);
    return 0;
}
