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
    int n,shu,weight;
    scanf("%d",&n);
    while(n--){
        memset(mon,0,sizeof(mon));
        scanf("%d%d",&shu,&weight);
        for(int i = 0;i < shu;i++){
            scanf("%d",&aaa[i].qian);
        }
        for(int i = 0;i < shu;i++){
            scanf("%d",&aaa[i].bei);
        }
        
        for(int i = 0;i < shu;i++){
            for(int j = weight;j >= aaa[i].bei;j--){
                mon[j] = max(mon[j-aaa[i].bei] + aaa[i].qian,mon[j]);
            }
        }
        printf("%lld\n",mon[weight]);
    }
    return 0;
}
