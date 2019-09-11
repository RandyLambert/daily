#include <bits/stdc++.h>
using namespace std;
struct node{
    int cun1,cun2,mon;
}aa[50*99+10];
int f[105],sum;
bool cmp(node a,node b){
    return a.mon < b.mon;
}
int find(int x){
    if(x==f[x]) return x;
    else return find(f[x]);
}
int main(){
    int n = 99;
    while(scanf("%d",&n)&&n){
        for(int i = 1;i <= n;i++){
            f[i] = i;
        }
        int m =  n*(n-1)/2;
        for(int i = 0;i < m;i++){
            scanf("%d%d%d",&aa[i].cun1,&aa[i].cun2,&aa[i].mon);
        }

        sort(aa,aa+m,cmp);
        sum = 0;
        for(int i = 0;i < m;i++){
            int fx = find(aa[i].cun1);
            int fy = find(aa[i].cun2);
            if(fx!=fy){
                f[fy] = fx;
                sum = sum + aa[i].mon;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
