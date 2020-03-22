#include<stdio.h>
long long int num,ans = 0;
int stack[100000],top = 0,n;

int main(){
    scanf("%d",&n);

    for(int i = 1;i <= n;i++){
        scanf("%lld",&num);
        while(top >= 1 && stack[top] <= num){
            top--;
        }

        ans = ans + top;

        stack[++top] = num;
    }

    printf("%lld",ans);
    return 0;
}
