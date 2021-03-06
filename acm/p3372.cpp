#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long sum,l,r,tag;
}t[400010];
long long num[100010];

/* 建树操作 */
void build(int p,int l,int r)
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)
    {
        t[p].sum=num[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
}
/* 懒标记（区间求和） */
void lazy(int p)
{
    if(t[p].tag)
    {
        t[2*p].sum+=t[p].tag*(t[p*2].r-t[p*2].l+1);
        t[2*p+1].sum+=t[p].tag*(t[p*2+1].r-t[p*2+1].l+1);
        t[2*p].tag+=t[p].tag;
        t[2*p+1].tag+=t[p].tag;
        t[p].tag=0;
    }
}

/* 区间修改（加/减） */
void change1(int p,int x,int y,int z)
{
    if(t[p].l>=x&&t[p].r<=y)
    {
        t[p].sum+=1LL*z*(t[p].r-t[p].l+1);
        t[p].tag+=z;
        return ;
    }
    int mid=(t[p].l+t[p].r)/2;
    lazy(p);
    if(x<=mid)
    {
        change1(p*2,x,y,z);
    }
    if(y>mid)
    {
        change1(p*2+1,x,y,z);
    }
    t[p].sum=t[2*p].sum+t[p*2+1].sum;
    return ;
}

/* 区间求和 */
long long sum(int p,int x,int y)
{
    if(t[p].l>=x&&t[p].r<=y)
    {
        return t[p].sum;
    }
    int mid=(t[p].l+t[p].r)/2;
    long long ans=0;
    lazy(p);
    if(x<=mid)
    {
        ans+=sum(p*2,x,y);
    }
    if(mid<y)
    {
        ans+=sum(p*2+1,x,y);
    }
    return ans;
}

/* 单点查询 */
long long single_sum(int p,int x)
{
    {
        if(t[p].l==t[p].r&&t[p].l==x)
        {
            return t[p].sum;
        }
        int mid=(t[p].l+t[p].r)/2;
        lazy(p);
        long long ans=0;
        if(mid>=x)
        {
            ans+=single_sum(2*p,x);
        }
        if(mid<x)
        {
            ans+=single_sum(2*p+1,x);
        }
        return ans;
    }
}

/* 单点修改（加/减） */
void single_change (int p,int x,int z)
{
    if(t[p].l==t[p].r&&t[p].l==x)
    {
        t[p].sum+=z;
        return ;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(mid>=x)
    {
        single_change(2*p,x,z);
    }
    if(mid<x)
    {
        single_change(2*p+1,x,z);
    }
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

/* 区间修改（更改数值） */
/* void lazy(int p) */
/* { */
/*     if(t[p].tag) */
/*     { */
/*         t[2*p].sum=t[p].tag*(t[p*2].r-t[p*2].l+1);//少了一个+号 */
/*         t[2*p+1].sum=t[p].tag*(t[p*2+1].r-t[p*2+1].l+1);//少了一个+号 */
/*         t[2*p].tag=t[p].tag; */
/*         t[2*p+1].tag=t[p].tag; */
/*         t[p].tag=0; */
/*     } */
/* } */
/* void change(int p,int x,int y,int z) */
/* { */
/*     if(t[p].l>=x&&t[p].r<=y) */
/*     { */
/*         t[p].sum=1LL*z*(t[p].r-t[p].l+1);//少了一个+号 */
/*         t[p].tag=z; */
/*         return ; */
/*     } */
/*     int mid=(t[p].l+t[p].r)/2; */
/*     lazy(p); */
/*     if(x<=mid) */
/*     { */
/*         change(p*2,x,y,z); */
/*     } */
/*     if(y>mid) */
/*     { */
/*         change(p*2+1,x,y,z); */
/*     } */
/*     t[p].sum=t[2*p].sum+t[p*2+1].sum; */
/*     return ; */
/* } */

//最大最小是另一张表
/* const int maxn = 200000+200; */
/* struct node */
/* { */
/*     int l,r,maxx,minn; */
/* }t[maxn<<2]; */
/* int num[maxn]; */
/* void build(int p,int l,int r) */
/* { */
/*     t[p].l=l; */
/*     t[p].r=r; */
/*     if(l==r) */
/*     { */
/*         t[p].maxx=num[l]; */
/*         t[p].minn=num[l]; */
/*         return ; */
/*     } */
/*     int mid=(l+r)>>1; */
/*     build(p<<1,l,mid); */
/*     build(p<<1|1,mid+1,r); */
/*     t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx); */
    /* t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn); */
/* } */
/* 区间最大值，最小值 */
/* int search_max(int pos,int x,int y) */
/* { */
/*     if(x<=t[pos].l&&y>=t[pos].r) */
/*     { */
/*         return t[pos].maxx; */
/*     } */
/*     int ans=-1; */
/*     int mid=(t[pos].l+t[pos].r)>>1; */
/*     if(x<=mid) ans=max(ans,search_max(pos<<1,x,y)); */
/*     if(y>mid) ans=max(ans,search_max(pos<<1|1,x,y)); */
/*     return ans; */
/* } */
/* int search_min(int pos,int x,int y) */
/* { */
/*     if(x<=t[pos].l&&y>=t[pos].r) */
/*     { */
/*         return t[pos].minn; */
/*     } */
/*     int ans=10000000+1; */
/*     int mid=(t[pos].l+t[pos].r)>>1; */
/*     if(x<=mid) ans=min(ans,search_min(pos<<1,x,y)); */
/*     if(y>mid) ans=min(ans,search_min(pos<<1|1,x,y)); */
/*     return ans; */
/* } */


int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 1;i <= n;i++){
        scanf("%lld",&num[i]);
    }
    build(1,1,n);

    int x,y,z;
    for(int i = 0;i < m;i++){
        scanf("%d",&x);
        if(x == 2){
            scanf("%d%d",&y,&z);
            printf("%lld\n",sum(1,y,z));
        }
        else{
            scanf("%d%d%d",&x,&y,&z);
            change1(1,x,y,z);
        }
    }
    return 0;
}

