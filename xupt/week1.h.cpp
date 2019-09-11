#include <cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int zhi[1500];
bool su[10001];
struct node{
    int x,step;
};
queue<node>q;
inline void sushu(){
    int cnt = 0;
    memset(su,1,sizeof(su));
    su[0] = su[1] = 0;
    for(int i = 2;i < 10001;i++)
    {
        if(su[i])
            zhi[cnt++]=i;
        for(int j = 0;j < cnt&&zhi[j]*i < 10001;j++)
        {
            su[zhi[j]*i] = 0;
            if(i%zhi[j] == 0) break;
        }
    }
}
int main(){
    sushu();
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        while(!q.empty()) q.pop();
        int flag = 0;
        scanf("%d%d",&n,&m);
        node start;
        start.x = n;
        start.step = 0;
        q.push(start);
        while(!q.empty())
        {
            node temp = q.front();
            q.pop();
            if(temp.x == m)
            {
                flag = 1;
                printf("%d\n",temp.step);
                break;
            }
            for(int i = 1;i <= 9;i+=2)
            {
                if((temp.x/10)*10 + i!=temp.x&&su[(temp.x/10)*10 + i] == 1){
                    node nx;
                    nx.x = i + (temp.x/10)*10;
                    nx.step = temp.step+1;
                    q.push(nx);
                } 
            }
            for(int i = 0;i <= 9;i++)
            {
                if(temp.x - (temp.x/10%10)*10 + i*10!=temp.x&&su[temp.x - (temp.x/10%10)*10 + i*10] == 1){
                    node nx;
                    nx.x = temp.x - (temp.x/10%10)*10 + i*10;
                    nx.step = temp.step+1;
                    q.push(nx);
                } 
            }
            for(int i = 0;i <= 9;i++)
            {
                if(temp.x - (temp.x/100%10)*100 + i*100!=temp.x&&su[temp.x - (temp.x/100%10)*100 + i*100] == 1){
                    node nx;
                    nx.x = temp.x - (temp.x/100%10)*100 + i*100;
                    nx.step = temp.step+1;
                    q.push(nx);
                } 
            }
            for(int i = 1;i <= 9;i++)
            {
                if(i*1000 + temp.x - (temp.x/1000)*1000!=temp.x&&su[i*1000 + temp.x - (temp.x/1000)*1000] == 1){
                    node nx;
                    nx.x = i*1000 + temp.x - (temp.x/1000)*1000;
                    nx.step = temp.step+1;
                    q.push(nx);
                } 
            }
        }
        if(flag==0)
            printf("Impossible\n");
    }
    return 0;
}
