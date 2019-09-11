#include<stdio.h>
int a[1000],c[1000],d[1000],b;
int max = -10000;
int maxa(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    scanf("%d",&b);
    for(int i = 1;i <= b;i++){
        scanf("%d",&c[i]);
        a[i] = a[i-1]+c[i];
    }
    for(int j = 1;j <= b;j++){
        d[j] = maxa(a[j+1],c[j]);
        max = maxa(max,d[j]);
    }
    printf("%d",max);
    return 0;
}
