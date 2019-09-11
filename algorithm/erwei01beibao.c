#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int x,int v){
    if(x<v) return v;
    else{
        return x;
    }
} 
int a1[100][100],b1[100],c1[100];
int main(){
    int a,b,i,j;
    scanf("%d%d",&a,&b);
    for(i = 1;i < b;i++){
        scanf("%d%d",&b1[i],&c1[i]);
    }
    for(i = 1;i < b;i ++){
        for(j = 1;j <= a;j++){
            if(j < c1[i]){
                a1[i][j] = a1[i-1][j];
            }
            else{
                a1[i][j] = max(a1[i-1][j],a1[i-1][j-c1[i]]+b1[i]);
            }
        }
        printf("%d",a1[b][a]);
    } 
    return 0;
}
