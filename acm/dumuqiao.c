#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
int main(){
    int i,renshu,daxiao,changdu,maxv=0,minv=0;
    scanf("%d",&changdu);
    scanf("%d",&renshu);
    for(i = 1;i <= renshu; i++){

        scanf("%d",&daxiao);
        maxv = max(maxv,max(changdu-daxiao+1,daxiao));
        minv = max(minv,min(changdu-daxiao+1,daxiao));
    }
    printf("%d %d",minv,maxv);
    return 0;
}
