#include<stdio.h>
int v,n;
int vi[20001],n1[35],fl[35];
int max(int x,int y){
    if(x>y) return x;
    else return y;
}
int main(){
    scanf("%d%d",&v,&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&n1[i]);
    }

    for(int i = 0;i < n;i++){
        for(int j = v;j > 0;j--){
            if(j >= n1[i]){
               vi[j] = max(vi[j-n1[i]] + n1[i],vi[j]);
            }
            else{
                vi[j] = vi[j-1];
            }
        }
    }
    printf("%d",v-vi[v]);
    return 0;
}
