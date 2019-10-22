#include <bits/stdc++.h>
using namespace std;
int f[110];
struct node{
public:
    int x,y,w;
    bool operator<(node &b){
        return w < b.w;
    }
}q[11000];
int findf(int x){
    if(x == f[x]){
        return x;
    }
    else return f[x] = findf(f[x]);
}

int main(){
    int n,cnt = 0,y;
    scanf("%d",&n);
    for(int i = 0;i <= n;i++){
        f[i] = i;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i < j){
                q[cnt].x = i;
                q[cnt].y = j;
                scanf("%d",&q[cnt].w);
                cnt++;
            }
            else{
                scanf("%d",&y);
            }
        }
    }

    sort(q,q+cnt);

    int cnn = 0,ans = 0;
    for(int i = 0;i < cnt;i++){
        int x = findf(q[i].x);
        int y = findf(q[i].y);
        if(x!=y){
            f[x] = y;
            ans+=q[i].w;
            cnn++;
            if(cnn == n-1){
                break;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}

