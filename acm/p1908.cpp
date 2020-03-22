#include <bits/stdc++.h>
using namespace std;
int bit[500010],r[500010],n;
struct node{
    int num,v;
}a[500010];
int getx(int p){
    return p&-p;
}
bool cmp(node q,node w)
{
    if(q.v == w.v)
        return q.num<w.num;
    return q.v<w.v;
}
void add(int p,int x)
{
    while(p <= n){
        bit[p]+=x;
        p+=getx(p);
    }
}
int query(int p)
{
    int sum=0;
    while(p){
        sum+=bit[p];
        p-=getx(p);
    }
    return sum;
}
int main(){
    long long ans = 0; 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].num=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        r[a[i].num]=i;
    }
    for(int i=1;i<=n;i++){
        add(r[i],1);
        ans+=i-query(r[i]);
    }
    printf("%lld\n",ans);
    return 0;
} 
