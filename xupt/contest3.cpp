#include<bits/stdc++.h>
using namespace std;
struct shu{
    char name[35];
    int  no;
    char zhuozhe[35];
    char chubanshe[35];
    int nian,yue,ri;
    double jiage;
}a[25];
int main(){
    int x,i,y;
    scanf("%d",&x);
    memset(a,0,sizeof(a));
    for(i = 1;i <= x;i++){
        scanf("%d%s%s%s%d-%d-%d%lf",&a[i].no,a[i].name,a[i].zhuozhe,a[i].chubanshe,&a[i].nian,&a[i].yue,&a[i].ri,&a[i].jiage);
    }
    int flag = 0;
    scanf("%d",&y);
    scanf("%d%s%s%s%d-%d-%d%lf",&a[i].no,a[i].name,a[i].zhuozhe,a[i].chubanshe,&a[i].nian,&a[i].yue,&a[i].ri,&a[i].jiage);
    printf("编号 书名 作者 出版社 出版日期 价格\n");
    for(int i = 1;i <= x;i++){
        if(i != y||flag==1)
            printf("%d %s %s %s %d年%d月%d日 %.2lf\n",a[i].no,a[i].name,a[i].zhuozhe,a[i].chubanshe,a[i].nian,a[i].yue,a[i].ri,a[i].jiage);
        if(i == y&&flag==0){
            printf("%d %s %s %s %d年%d月%d日 %.2lf\n",a[x+1].no,a[x+1].name,a[x+1].zhuozhe,a[x+1].chubanshe,a[x+1].nian,a[x+1].yue,a[x+1].ri,a[x+1].jiage);
            i--;
            flag = 1;
        }
    }
    return 0;
}
