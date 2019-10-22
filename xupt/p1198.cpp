#include<iostream>
#include<algorithm>
#define maxn 200010
#define INF 0x3f3f3f3f
#define lint long long
#define P pair<int,int>
#define MID(l,r) (l+(r-l)/2)
#define lson(o) (o<<1)
#define rson(o) (o<<1|1)
using namespace std;

lint a[maxn];
lint ans_min,ans_max,ans_sum;
struct node{
    lint l,r;
    lint maxx,minx,sum;
}tree[maxn<<2];
void build(lint o,lint l,lint r)
{
    tree[o].l = l;
    tree[o].r = r;
    if(l == r){
        tree[o].maxx = tree[o].minx = tree[o].sum = a[l];
        return ;
    }
    lint m = MID(l,r);
    lint lc = lson(o),rc = rson(o);
    build(lc,l,m);
    build(rc,m+1,r);
    tree[o].maxx = max(tree[lc].maxx, tree[rc].maxx);
    tree[o].minx = min(tree[lc].minx, tree[rc].minx);
    tree[o].sum = tree[lc].sum + tree[rc].sum;
}
void update(lint o,lint p,lint v)
{
    if(tree[o].l == tree[o].r){
        tree[o].maxx = v;  //视情况而定
        tree[o].minx = v;
        tree[o].sum = v;
        return ;
    }
    lint m = MID(tree[o].l,tree[o].r);
    lint lc = lson(o),rc = rson(o);
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
void query(lint o,lint l,lint r)
{
    if(tree[o].l == l && tree[o].r == r){
        ans_max = max(ans_max, tree[o].maxx);
        ans_min = min(ans_min, tree[o].minx);
        ans_sum += tree[o].sum;
        return;
    }
    lint m = MID(tree[o].l,tree[o].r);
    lint lc = lson(o),rc = rson(o);
    if(r<=m) query(lc,l,r);
    else if(l>m) query(rc,l,r);
    else{
        query(lc,l,m);
        query(rc,m+1,r);
    }
}
int main()
{
    int n,m,x;
    cin>>n>>m;
    build(1,1,200010);
    int len = 0,t = 0;
    while(n--){
        char c;
        cin>>c>>x;
        if(c == 'Q'){
            query_init();
            query(1,len-x+1,len);
            printf("%lld\n",ans_max);
            t = ans_max;

        }
        else{
            x=(x+t)%m;
            /* printf("\n\n%d %d %d %d %d\n\n",x,t,(x+t)%m,m,x+t); */
            len++;
            update(1,len,x);
        }
    }
    return 0;
}

