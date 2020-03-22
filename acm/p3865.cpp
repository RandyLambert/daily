#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<utility>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define maxn 500005
#define INF 0x3f3f3f3f
#define MID(l,r) (l+(r-l)/2)
#define lson(o) (o<<1)
#define rson(o) (o<<1|1)
using namespace std;
 
int a[maxn];
int ans_min,ans_max,ans_sum;
struct node{
    int l,r;
    int maxx,minx,sum;
}tree[maxn<<2];
void build(int o,int l,int r)
{
    tree[o].l = l;
    tree[o].r = r;
    if(l == r){
        tree[o].maxx = tree[o].minx = tree[o].sum = a[l];
        return ;
    }
    int m = MID(l,r);
    int  lc = lson(o),rc = rson(o);
    build(lc,l,m);
    build(rc,m+1,r);
    tree[o].maxx = max(tree[lc].maxx, tree[rc].maxx);
    tree[o].minx = min(tree[lc].minx, tree[rc].minx);
    tree[o].sum = tree[lc].sum + tree[rc].sum;
}
void update(int o,int p,int v)
{
    if(tree[o].l == tree[o].r){
        tree[o].maxx = v;  //视情况而定
        tree[o].minx = v;
        tree[o].sum = v;
        return ;
    }
    int m = MID(tree[o].l,tree[o].r);
    int lc = lson(o),rc = rson(o);
    if(p<=m) update(lc,p,v);
    else update(rc,p,v);
    tree[o].maxx = max(tree[lc].maxx, tree[rc].maxx);
    tree[o].minx = min(tree[lc].minx, tree[rc].minx);
    tree[o].sum = tree[lc].sum + tree[rc].sum;
}
void query_init()//查询前，将全局变量初始化
{
    ans_max = -INF;
    ans_min = INF;
    ans_sum = 0;
}
void query(int o,int l,int r)
{
    if(tree[o].l == l && tree[o].r == r){
        ans_max = max(ans_max, tree[o].maxx);
        ans_min = min(ans_min, tree[o].minx);
        ans_sum += tree[o].sum;
        return;
    }
    int m = MID(tree[o].l,tree[o].r);
    int lc = lson(o),rc = rson(o);
    if(r<=m) query(lc,l,r);
    else if(l>m) query(rc,l,r);
    else{
        query(lc,l,m);
        query(rc,m+1,r);
    }
}
int main()
{
    int n,m,x,y;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        while(m--){
            cin>>x>>y;
            query_init();//查询前初始化全局变量
            query(1,x,y);
            printf("%d\n",ans_max);
        }
    }
    return 0;
}
