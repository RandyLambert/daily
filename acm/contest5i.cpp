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
int  judge(int a)                           
{
	if(a%4==0  &&  a%100!=0 || a%400==0) return 1;
	else return 0;
}

int ra[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int pa[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int week[7] = {1,2,3,4,5,6,7};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int year,month,day,n;
        scanf("%d-%d-%d",&year,&month,&day);
        cin >> n;
		int i=month,sum=0;
        int tmpa=day;
        int suma=0;
        for(int i=1900;i<year;i++)
        {
            if(judge(i)) suma+=366;
            else suma+=365;
        }
        if(judge(year))
        {
            pa[2]=29;
            for(int i=1;i<month;i++)
            {
                suma+=pa[i];
            }
        }
        suma+=day;
        tmpa=suma%7;
		while(i)
		{
		    day++;
		    if(judge(year)) pa[2]=29;
		    else pa[2]=28;
		    if(i==12&&day>31)
            {
                i=1;year++;month=1;day=1;
            }
		    if(day>pa[i])
            {
               month++;day=1;i++;
            }
		   sum++;
		   if(n==sum)break;
	    }
        int ans;
       ans = CaculateWeekDay(year,month,day);
        printf("%d年%02d月%02d日 星期",year,month,day);
        daan(ans);
        putchar('\n');
    }
    return 0;
}
