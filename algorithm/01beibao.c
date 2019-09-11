#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a1[1000],b1[1000],c1[1000];

int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    int a,b,i,j;
    scanf("%d%d",&a,&b);
    for(i = 0;i < a;i++ ){
        scanf("%d%d",&a1[i],&b1[i]);
    }
    for(int i = 0;i<a;i++ ){
        for(j = b;j >=a1[i] ;j--){
            c1[j] = max(c1[j],c1[j-a1[i]] + b1[i]);
        }
    }
    printf("%d\n",c1[b]);
    return 0;
}
