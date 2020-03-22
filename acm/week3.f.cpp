#include <stdio.h>
using namespace std;
int n = 1,m,f[30005];
int find(int x){
    if(x==f[x]) return x;
    else return f[x] = find(f[x]);
}
int main(){
    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0){
            break;
        }
        for(int i = 0;i < n;i++) f[i] = i;
        int one,shu,temp,ans = 0;
        for(int j = 0;j < m;j++){
        scanf("%d%d",&shu,&one);
            for(int i = 0;i < shu-1;i++){
                scanf("%d",&temp);
                int fx = find(one);
                int fy = find(temp);
                if(fx!=fy) f[fy] = fx;
            }
        }
        for(int i = 0;i < n;i++){
            if(find(0)==find(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
