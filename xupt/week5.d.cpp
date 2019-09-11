#include <stdio.h>
#include <string.h>
long long int mon[1000005];
long long int max(long long int a,long long int b){
    if(a>b)return a;
    else return b;
}
struct node{
    int qian;
    int bei;
}aaa[1005];
int main(){
    int shu,weight;
    while(scanf("%d",&shu)!=EOF){
        memset(mon,0,sizeof(mon));
        for(int i = 0;i < shu;i++){
            scanf("%d%d",&aaa[i].qian,&aaa[i].bei);
        }
        scanf("%d",&weight);
        for(int i = 0;i < shu;i++){
            for(int j = aaa[i].bei;j<= weight;j++){
                mon[j] = max(mon[j-aaa[i].bei] + aaa[i].qian,mon[j]);
            }
        }
        printf("%lld\n",mon[weight]);
    }
    return 0;
}
