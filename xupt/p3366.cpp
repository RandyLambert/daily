#include <bits/stdc++.h>
using namespace std;
struct node{
    int qi,zhong,jia;
}aa[200005];
int f[5005];
bool cmp(node a,node b){
    return a.jia < b.jia;
}

int find(int x){
    while(x!=f[x]){
        x=f[x]=f[f[x]];
    }
    return x;
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&aa[i].qi,&aa[i].zhong,&aa[i].jia);
    }
    sort(aa,aa+m,cmp);
    
    int root = 0,sum = 0;
    for(int i = 0;i < m;i++){

        if(find(aa[i].qi)!=find(aa[i].zhong)){
            sum+=aa[i].jia;
            root++;
            f[find(aa[i].zhong)] = f[find(aa[i].qi)];
        }

        if(root == n-1){
            printf("%d\n",sum);
            break;
        }
    }


    return 0;
}
