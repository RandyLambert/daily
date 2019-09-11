#include<stdio.h>
int a;
int b[10];
int c[10];
void dfs(int i){
    int k;
    if(i == a+1){
        for(int j = 1;j <= a;j++){
            printf("%5d",b[j]);
        }
        putchar('\n');
        return;
    }
    for(k = 1;k <= a;k++){
        if(c[k] == 0){
            b[i] = k;
            c[k] = 1;
            dfs(i+1);
            c[k] = 0;
        }
    }
    return;
}
int main(){
    scanf("%d",&a);
    dfs(1);
    return 0;
}
