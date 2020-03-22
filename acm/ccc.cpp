#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
    int cun1;
    int cun2;
    int mon;
}aa[300];
int f[300],du[300];
bool cmp(node a,node b){
    return a.mon < b.mon;
}

int find(int x){
    while(x!=f[x]){
        x = f[x];
    }
    return f[x];
}
int main(){
    int n = 99;
    while(scanf("%d",&n)&&n){
        for(int i = 1;i <= n;i++){
            f[i] = i;
            du[i] = 0;
        }
        for(int i = 0;i < n*(n-1)/2;i++){
            scanf("%d%d%d",&aa[i].cun1,&aa[i].cun2,&aa[i].mon);
        }

        sort(aa,aa+n,cmp);
        int sum = 0;
        for(int i = 0;i < n*(n-1)/2;i++){
            if(find(aa[i].cun1)!=find(aa[i].cun2)){
                sum = sum + aa[i].mon;
                f[find(aa[i].cun1)] = f[find(aa[i].cun2)];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
