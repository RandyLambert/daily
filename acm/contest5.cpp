#include <bits/stdc++.h>
using namespace std;
int CaculateWeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return iWeek+1;
}

void daan(int x){
    if(x==1){
        printf("一");
    }
    else if(x==2){
        printf("二");
    }
    else if(x==3){
        printf("三");
    }
    else if(x==4){
        printf("四");
    }
    else if(x==5){
        printf("五");
    }
    else if(x==6){
        printf("六");
    }
    else if(x==7){
        printf("七");
    }
}
int ra[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int pa[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int week[7] = {1,2,3,4,5,6,7};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,len = 0,y = 1900,ans = 0,flag = 0,nian,yue,ri,hh = 0;
        int xinnian,xinyue,xinri;
        scanf("%d-%d-%d",&nian,&yue,&ri);
        scanf("%d",&x);
        if((nian%4==0 && nian%100!=0) || ( nian%100==0 && nian%400==0)){
            flag = 0;
            if(x > (ra[yue]-ri)){
                x = x - (ra[yue]-ri);
            }
            
            else{
                xinnian = nian;
                hh = 1;
                xinri = ri + x;
                xinyue = yue;
                x = 0;
            }
        }
        else{
            flag = 1;
            if(x > (pa[yue]-ri)){
                x = x - (pa[yue]-ri);
            }
            else{
                xinnian = nian;
                hh = 1;
                xinri = ri + x;
                xinyue = yue;
                x = 0;
            }
        }
        
        for(int i = yue;i < 12;i++){
            if(flag == 1){
                if(x-pa[i] > 0)
                    x = x - pa[i];
                else{
                    xinnian = nian;
                    hh = 1;
                    xinyue = i+1;
                    if(x!=0)
                    xinri = x;
                    x = 0;
                    break;
                }
            }
            if(flag == 0){
                if(x-ra[i] > 0)
                    x = x - ra[i];
                else{
                    xinnian = nian;
                    hh = 1;
                    xinyue = i+1;
                    if(x!=0)
                    xinri = x;
                    x = 0;
                    break;
                }
            }
        }
       int ni = nian; 
        while(1){
            if((ni%4==0 && ni%100!=0) || ( ni%100==0 && ni%400==0)){
                if(x>=366){
                    x = x-366;
                    ni = ni + 1;
                }
                else{
                    if(hh == 0)
                        ni = ni+1;
                    break;
                }
            }
            else{
                if(x>=365){
                    x = x-365;
                    ni = ni + 1;
                }
                else{
                    if(hh == 0)
                        ni = ni + 1;
                    break;
                }
            }
        }
        xinnian = ni;
        if((nian%4==0 && nian%100!=0) || ( nian%100==0 && nian%400==0)){
            for(int i = 0;i < 12;i++){
                if(x>ra[i]){
                    x = x-ra[i];
                }
                else if(x == ra[i]){
                    xinri = ra[i];
                    xinyue = i+1;
                    break;
                }
                else if(x!=0){
                    xinri = x;
                    xinyue = i+1;
                    break;
                }
            }
        }
        else{
            for(int i = 0;i < 12;i++){
                if(x>pa[i]){
                    x = x-pa[i];
                }
                else if(x == pa[i]){
                    xinri = pa[i];
                    xinyue = i+1;
                    break;
                }
                else if(x!=0){
                    xinri = x;
                    xinyue = i+1;
                    break;
                }
            }
        }
       ans = CaculateWeekDay(xinnian,xinyue,xinri);
        printf("%d年%02d月%02d日 星期",xinnian,xinyue,xinri);
        daan(ans);
        putchar('\n');
    }
    return 0;
}
