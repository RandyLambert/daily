#include <stdio.h>
#include <string.h>
inline int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int w[100010],f[100010],w1[1000010],f1,xx[100010];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0){
        int cnt = 0;
        memset(w,0,sizeof(w));
        memset(w1,0,sizeof(w1));
        memset(f,0,sizeof(f));
        memset(xx,0,sizeof(xx));

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
                xx[f[j]] = 1;
            }
        }
        int sum = 0;
        for(int i = 0;i <= m;i++){
            if(xx[i]==1)
                sum++;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
