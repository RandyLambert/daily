#include<stdio.h>
int t,m;
int a[101],b[101],mn[1000];
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    scanf("%d%d",&t,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i = 0;i < m;i++){
        for(int j = t;j >= a[i];j--){
            mn[j] = max(mn[j-a[i]]+b[i],mn[j]);
        }
    }

    printf("%d",mn[t]);
    return 0;
}
