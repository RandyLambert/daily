#include<stdio.h>
#include<string.h>
double next[10000];
int main(){
    int a,b;
    next[1] = 1.0;
    scanf("%d",&a);
    for(int i = 0;i<a;i++){
        scanf("%d",&b);
        for(int j = 2;j <= b;j++){
            next[j] = next[j - 1] + (double)b/(j-1);
        }
        printf("%lf\n",next[b]);
        memset(next,0,10000);
        next[1] = 1.0;
    }
    return 0;
}
