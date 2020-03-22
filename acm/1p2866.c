#include<stdio.h>
int a[100],ans,m,n,top = 0;
int main(){

    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        while(top >= 1 && m >= a[top]){
            top--;
        }

        ans = ans + top;
        a[++top] = m;
    }
    printf("%d",ans);
    return 0;
}
