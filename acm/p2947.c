#include<stdio.h>
long long int num,ans[100000],a[100000];
long long int top = 0,n,m;

int main(){
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&m);
        while(top >= 1 && m <= a[top]){
            top--;
        }
        ans[i] = top;
        a[++top] = m;

    }

    for(int i = 1;i <= n;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
