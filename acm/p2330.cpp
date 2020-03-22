#include <bits/stdc++.h>
using namespace std;
int f[310];
struct node{
public:
    int x,y,w;
    bool operator<(node &b){
        return w < b.w;
    }
}q[100010];
int findf(int x){
    if(x == f[x]){
        return x;
    }
    else return f[x] = findf(f[x]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i <= n;i++){
        f[i] = i;
    }

    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].w);
    }

    sort(q,q+m);

    int cnn = 0,ans = 0;
    for(int i = 0;i < m;i++){
        int x = findf(q[i].x);
        int y = findf(q[i].y);
        if(x!=y){
            f[x] = y;
            ans=q[i].w;
            cnn++;
            if(cnn == n-1){
                break;
            }
        }
    }
    printf("%d %d\n",cnn,ans);

    return 0;
}
