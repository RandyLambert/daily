#include <bits/stdc++.h>
using namespace std;
int n = 1,m = 1;
struct node{
    int x,y,w;
}q[5000];
bool cmp(struct node x,struct node y){
    return x.w < y.w;
}
int f[105];
int find(int x){
    if(x == f[x]){
        return f[x];
    }
    else{

        f[x] = find(f[x]);
        return f[x];
    }
}
void init(){
    for(int i = 0;i <= n;i++){
        f[i] = i;
    }
}
int main(){

    while(scanf("%d%d",&n,&m)&&(n!=0||m!=0)){
        for(int i = 0;i < m;i++)
            scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].w);
        sort(q,q+m,cmp);
        int flag1 = 0,da = 999999999;
        for(int j = 0;j < m;j++){
            
            init();
            int ans = 0;
            int len = 0,flag = 0;

            for(int i = j;i < m;i++){
                        
                int f1 = find(q[i].x);
                int f2 = find(q[i].y);

                if(f1!=f2){
                    len++;
                    f[f1] = f2;
                }
                if(len == n-1){
                    ans = q[i].w - q[j].w;
                    flag = 1;
                    flag1 = 1;
                    break;
                }
            }
            if(flag == 1)
                da = min(da,ans);
        }
        if(flag1 == 0)
            printf("-1\n");
        else
            printf("%d\n",da);
    }
    return 0;
}

