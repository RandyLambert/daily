#include <bits/stdc++.h>
using namespace std;
int n,t,f[100005],tem[2*100005];
struct node{
    int x,y,e;
}a[100001];
bool cmp(node a,node b)
{
    return a.e > b.e;
}
inline int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int main(){
    scanf("%d",&t);
    while(t--)
    {
        int flag = 1,tot = 0;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        memset(tem,0,sizeof(tem));
        cin>>n;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].e);
            tem[++tot] = a[i].x;
            tem[++tot] = a[i].y;
        }
        sort(tem+1,tem+tot+1);
        sort(a+1,a+n+1,cmp);
        int xx = unique(tem+1,tem+tot+1)-tem-1;
        for(int i = 1;i <= xx;i++)
        {
            f[i] = i;
        }

        for(int i = 1;i <= n;i++)
        {
            a[i].x = lower_bound(tem+1,tem + xx + 1,a[i].x)-tem;
            a[i].y = lower_bound(tem+1,tem + xx + 1,a[i].y)-tem;
            int r1 = find(a[i].x);
            int r2 = find(a[i].y);
            if(a[i].e)
            {
               f[r1] = r2;
            }
            else if(r1==r2)
            {
                printf("NO\n");
                flag = 0;
                break;
            }
        }
            if(flag) printf("YES\n");
    }
    
    return 0;
}
