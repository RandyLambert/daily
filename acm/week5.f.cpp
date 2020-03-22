#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
map<int,int>xx;
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int w[1000010],f[1000010],w1[1000010],f1;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0){
        int cnt = 0;
        memset(w,0,sizeof(w));
        memset(w1,0,sizeof(w1));
        memset(f,0,sizeof(f));

        for(int i = 0;i < n;i++)
        {
            scanf("%d",&w[i]);
        }
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&f1);
            for(int j = 1;j <= f1;j = j<<1)
            {
                w1[cnt++] = j*w[i];
                f1 = f1-j;
            }
            if(f1){
                w1[cnt++] = w[i]*f1;
            }
        }

        for(int i = 0;i < cnt;i++){
            for(int j = m;j >= w1[i];j--){
                f[j] = max(f[j-w1[i]]+w1[i],f[j]);
                xx[f[i]]=1;
            }
        }
        int sum = 0;
        for(int i = 0;i < xx.size();i++){
            if(xx[i]==1)
                sum++;
        }
        printf("%lu",sum);
        xx.clear();
    }
    
    return 0;
}
