#include <iostream>
using namespace std;
int main(){
    int dis[500005],u[500005],v[500005],w[500005];
    int flag,inf = 2147483647,n,m,s;
    scanf("%d%d%d",&n,&m,&s);

    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        if(i<=n)
            dis[i] = inf;
    }
    dis[s] = 0;
    for(int k = 1;k <= n-1;k++){
        flag = 0;
        for(int i = 1;i <= m;i++){
            if(dis[v[i]] > dis[u[i]]+w[i]){
                dis[v[i]] = dis[u[i]] + w[i];
                flag = 1;
            }
        }
        if(flag==0) break;
    }
    for(int i = 1;i <= n;i++){
        printf("%d ",dis[i]);
    }
    return 0;
}
