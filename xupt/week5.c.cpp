#include <stdio.h>
#include <string.h>
double mon[1000005];
double max(double a,double b){
    if(a>b)return a;
    else return b;
}
struct node{
    int qian;
    double bei;
}aaa[1000005];
int main(){
    int cnt,m;
    double n;
    scanf("%d",&cnt);
    while(cnt--){
        memset(mon,0,sizeof(mon));
        int sum = 0;
        scanf("%lf%d",&n,&m);
        for(int i = 0;i < m;i++){
            scanf("%d%lf",&aaa[i].qian,&aaa[i].bei);
            aaa[i].bei = 1 - aaa[i].bei;
            sum = sum + aaa[i].qian;
        }
        
        mon[0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = sum;j >= aaa[i].qian;j--){
                mon[j] = max(mon[j-aaa[i].qian]*aaa[i].bei,mon[j]);
            }
        }
        for(int i = sum;i >= 0;i--){
            if(mon[i] > 1 - n ){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
