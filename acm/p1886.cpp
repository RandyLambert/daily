#include <bits/stdc++.h>
using namespace std;
//最大最小是另一张表
const int maxn = 1000000+200;
struct node
{
    int l,r,maxx,minn;
}t[maxn<<2];
int num[maxn];
void build(int p,int l,int r)
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)
    {
        t[p].maxx=num[l];
        t[p].minn=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);
    t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);
}
//区间最大值，最小值
int search_max(int pos,int x,int y)
{
    if(x<=t[pos].l&&y>=t[pos].r)
    {
        return t[pos].maxx;
    }
    int ans=-2147483647;
    int mid=(t[pos].l+t[pos].r)>>1;
    if(x<=mid) ans=max(ans,search_max(pos<<1,x,y));
    if(y>mid) ans=max(ans,search_max(pos<<1|1,x,y));
    return ans;
}
int search_min(int pos,int x,int y)
{
    if(x<=t[pos].l&&y>=t[pos].r)
    {
        return t[pos].minn;
    }
    int ans=2147483646;
    int mid=(t[pos].l+t[pos].r)>>1;
    if(x<=mid) ans=min(ans,search_min(pos<<1,x,y));
    if(y>mid) ans=min(ans,search_min(pos<<1|1,x,y));
    return ans;
}

int main(){

    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        
        memset(num,0,sizeof(num));
        memset(t,0,sizeof(t));
        for(int i = 1;i <= n;i++){
            scanf("%d",&num[i]);
        }
        build(1,1,n);
        for(int i = 1;i <= n-m+1;i++){
            printf("%d ",search_min(1,i,i+m-1));
        }
        putchar('\n');
        for(int i = 1;i <= n-m+1;i++){
            printf("%d ",search_max(1,i,i+m-1));
        }
        putchar('\n');

    }

    return 0;
}
