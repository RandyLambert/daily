#include <bits/stdc++.h>
using namespace std;
int ra[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int ra1[12] = {13,44,73,104,134,165,195,226,257,287,318,348};
int pa[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int pa1[12] = {13,44,72,103,133,164,194,225,256,286,317,347};
int week[7] = {1,2,3,4,5,6,7};
int main(){
    int x,len = 0,y = 1998,ans = 0,flag = 0;
    scanf("%d",&x);
    if(x==1998){
        printf("1998年有3个黑色星期五\n");
        return 0;
    }
    while(y < x){
        if((y%4==0&&y%100!=0)||(y%100==0&&y%400==0)){
            len = len + 366;
            y++;
        }
        else{
            len = len + 365;
            y++;
        }
    }
    if((y%4==0&&y%100!=0)||(y%100==0&&y%400==0)){
        ans = 366;
        flag = 0;
    }
    else{
        ans = 365;
        flag = 1;
    }
    int kk;
    kk = (len%7+4)%7;
    //printf("%d\n\n",kk);
    int daan = 0;
    for(int i = 0;i < 12;i++){
        if(flag == 0){
            if((ra1[i]%7+kk-1)%7 == 5){
                daan++;
            }
            //printf("%d\n",(ra1[i]%7+kk-1)%7);
        }
        if(flag == 1){
            if((pa1[i]%7+kk-1)%7 == 5){
                daan++;
            }
            //printf("%d\n",((pa1[i]-1)%7+kk)%7);
        }
    }
    printf("%d年有%d个黑色星期五\n",x,daan);
    return 0;
}

