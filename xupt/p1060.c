#include<stdio.h>

int pi[50],ai[50],ci[30001],di[50];
int n,m;
int max(int x,int y){
    if(x>y) return x;
    else return y;
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&pi[i],&ai[i]);
        di[i] = pi[i]*ai[i];
    }

    for(i = 0;i < m;i++){
        for(int j = n;j >= pi[i];j--){
            if(j>=pi[i]){
                ci[j] = max(ci[j-pi[i]]+di[i],ci[j]);
            }
        }
    }
    printf("%d",ci[n]);
    return 0;
}
