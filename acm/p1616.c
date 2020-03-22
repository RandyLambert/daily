#include<stdio.h>
int t,m;
int a[10002],b[10002],mn[100002];
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
        for(int j = a[i];j <= t;j++){
            mn[j] = max(mn[j-a[i]]+b[i],mn[j]);
        }
    }

    printf("%d",mn[t]);
    return 0;
}
