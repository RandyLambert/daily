#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int ans[5010],ans1[5100];
struct node{
    int x1,x2;
}a[5010];

struct node1{
    int x33,y33;
}x[5010];
bool cmp(node1 p,node1 q)
{
    if(p.x33 == q.x33){
        return p.y33 < q.y33;
    }
    else{
        return p.x33 < q.x33;
    }
}
bool cmp1(node p,node q)
{
    if(p.x1 == q.x1){
        return p.x2 < q.x2;
    }
    else{
        return p.x1 < q.x1;
    }
}
int main(){

    int n,m,x1,x2,y1,y2;

    while(cin>>n){
        if(n==0){
            break;
        }
        cin>>m>>x1>>y1>>x2>>y2;

        memset(ans,0,sizeof(ans));
        memset(ans1,0,sizeof(ans1));
        memset(a,0,sizeof(a));
        memset(x,0,sizeof(x));

        a[0].x1 = x1;
        a[0].x2 = x1;
        a[n+1].x1 = x2;
        a[n+1].x2 = x2;
        for(int i = 1;i <= n;i++){
            cin>>a[i].x1>>a[i].x2;
        }
        sort(a+1,a+n+1,cmp1);

        for(int i = 0;i < m;i++)
            cin>>x[i].x33>>x[i].y33;
        sort(x,x+m,cmp);

        for(int ii = 0;ii < m;ii++){
            int& x3 = x[ii].x33;
            int& y3 = x[ii].y33;
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

        printf("Box\n");
        for(int i = 0;i <= n;i++)
            ans1[ans[i]]++;
        for(int i = 1;i <= m;i++)
            if(ans1[i]!=0)
                printf("%d: %d\n",i,ans1[i]);
	/* putchar('\n'); */
    }
	
    return 0;
}

