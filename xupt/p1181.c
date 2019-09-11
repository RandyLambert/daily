#include<stdio.h>
int main(){
    int shu,duan,a[1000],ci = 0,temp = 0;
    scanf("%d%d",&shu,&duan);

    for(int i = 0;i < shu;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < shu;i++){

            temp+=a[i];
        if(temp <= duan){
        }
        else{
            ci++;
            temp = a[i];
        }
    }
    printf("%d",ci+1);
    return 0;
}
