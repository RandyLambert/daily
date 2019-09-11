#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int v[1010],w[1010],f[1010][1010];
int main(){
    int n,m,k,s;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        memset(f,0,sizeof(f));
        int cnt = 0;
        for(int i = 0;i < k;i++){
            scanf("%d%d",&v[i],&w[i]);
        }
        
        for(int i = 1;i <= m;i++){
            for(int j = 0;j < k;j++)
                for(int d = 1;d <= s;d++)
                    if(w[j]<=i)
                        f[i][d]=max(f[i][d],f[i-w[j]][d-1]+v[j]);
            if(f[i][s]>=n){
                printf("%d\n",m-i);
                cnt = 1;
                break;
            }
        }
        if(cnt==0)printf("-1\n");
    }
    return 0;
}
