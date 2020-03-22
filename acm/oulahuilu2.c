#include<stdio.h>
#include<string.h>
int xx[10005];
int main(){
    int m,n;
    int i,j,k;
    while(scanf("%d%d",&n,&m)&&n){
        memset(xx,0,sizeof(xx));
        int flag = 1;
        for(i = 0;i < m;i++){
            scanf("%d%d",&j,&k);
            xx[k]++;
            xx[j]++;
        }

        for(i = 1;i <= m;i++){
            if(xx[i]%2||!xx[i]){
                flag = 0;
                break;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
