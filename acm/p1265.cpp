#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll f[5005];
struct node1{
    int x,y;
}q1[5005];
struct node{
public:
    int x,y;
    double w;
    bool operator<(node &b){
        return w < b.w;
    }
}q[5005*5005];
int findf(int x){
    if(x == f[x]){
        return x;
    }
    else return f[x] = findf(f[x]);
}

int main(){
    int n,cnt = 0;
    scanf("%d",&n);
    for(int i = 0;i <= n;i++){
        f[i] = i;
    }
    for(int i = 1;i <=n;i++){
        scanf("%d%d",&q1[i].x,&q1[i].y);
    }
    for(int i = 1;i <=n;i++){
        for(int j = 1;j<=n;j++){
            if(i!=j){
                q[cnt].x = i;
                q[cnt].y = j;
                q[cnt++].w = sqrt((q1[i].x - q1[j].x)*(q1[i].x - q1[j].x) + (q1[i].y - q1[j].y)*(q1[i].y - q1[j].y));
            }
        }
    }

    sort(q,q+cnt);

    int cnn = 0;
    double ans = 0;
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
    printf("%.2lf\n",ans);
    return 0;
}
