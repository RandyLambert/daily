#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int ans[5010];
struct node{
    int x1,x2;
}a[5010];
int main(){

    int n,m,x1,x2,y1,y2;

    while(cin>>n){
        if(n==0){
            break;
        }
        cin>>m>>x1>>y1>>x2>>y2;

        memset(ans,0,sizeof(ans));
        memset(a,0,sizeof(a));

        a[0].x1 = x1;
        a[0].x2 = x1;
        a[n+1].x1 = x2;
        a[n+1].x2 = x2;
        for(int i = 1;i <= n;i++){
            cin>>a[i].x1>>a[i].x2;
        }

        int x3,y3;

        for(int ii = 0;ii < m;ii++){
            cin>>x3>>y3;
            for(int i = 1;i <= n+1;i++){
                int t1 = a[i].x1 - x3;
                int t2 = y1 - y3;

                int t3 = a[i].x2 - x3;
                int t4 = y2 - y3;

                int t11 = a[i-1].x1 - x3;
                int t22 = y1 - y3;

                int t33 = a[i-1].x2 - x3;
                int t44 = y2 - y3;

                if(t1*t4 - t2*t3 < 0 && t11*t44 - t22*t33 > 0){
                    ans[i-1]++;
                    break;
                }
            }
        }

        for(int i = 0;i <= n;i++)
            printf("%d: %d\n",i,ans[i]);
	putchar('\n');
    }
	
    return 0;
}

