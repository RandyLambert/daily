#include<stdio.h>
#include<string.h>
int sum[10000];
int f[10000];
int d;
int main(){
    int a,b,c,flag;
    sum[0] = 0;
    scanf("%d",&a);
    while(a--){
        scanf("%d%d",&b,&c);
        for(int i = 1;i <= b;i++){
            scanf("%d",&d);
            sum[i] = sum[i-1] + d;
            int wei = sum[i]%c;
            f[wei]++;
            if(f[wei]%2==0) flag = 1;
        }
        if(flag == 1||f[0]){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
         memset(sum,0,sizeof(sum));
         memset(f,0,sizeof(f));
         flag = 0;
    }

    return 0;
}
