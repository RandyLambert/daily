#include<stdio.h>
int a,v = 0;
int ce[1000002];
int main(){
    scanf("%d",&a);
    getchar();
    for(int x = 0;x < a;x++){
        int n = 0,m = 0;
        scanf("%d%d",&n,&m);
        getchar();
        for(int x = 1;x <= n;x++){
            ce[x] = x;
        }
        int i = 0,j = 0,flag = 0,t;
        long long int sum = 0;
        while(m--){
            i = 1;
            j = n;
            t = ce[i];
            ce[i] = ce[j];
            ce[j] = t;
            flag++;
            if(flag==n/2){
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(ce[i]>ce[j]){
                    sum++;
                }
            }
        }
    printf("%lld\n",sum);
    }
}
