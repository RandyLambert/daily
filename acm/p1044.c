#include<stdio.h>
int n,sum;
int a[20],c[20];
void dfs(int dd){
    if(dd==n){
        sum++;
        for(int i = 0;i < n;i++){
            //if(a[i] == 1)
           printf("%d ",c[i]);

        }
        putchar('\n');
        /* for(int i = 0;i <= n;i++) */
            /* printf("   %d ",a[i]); */
    }
    else{
        for(int i = 1;i <= n;i++){
            if(a[i]==0){
                a[i] = 1;
                c[dd] = i;
                dfs(dd+1);
                a[i] = 0;

            }
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(0);
    printf("%d",sum);
    return 0;
}
