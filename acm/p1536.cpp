#include <stdio.h>
int f[1005],n = 1,m,nn,mm;
int find(int x){
    while(x!=f[x]){
        x = f[x];
    }
    return f[x];
}
int main(){
    while(scanf("%d%d",&n,&m)){
        if(n==0){
            break;
        }
        for(int i = 0;i <= n;i++){
            f[i] = i;
        }
        int sum = 1;
        for(int i =  0;i < m;i++){
            scanf("%d%d",&nn,&mm);
            int xx = find(nn); int yy = find(mm);
            if(xx!=yy){
                f[xx] = f[yy];
                sum++;
            }
        }
        printf("%d\n",n-sum);
    }

    return 0;
}
