#include<stdio.h>
int main(){
    double f[100] = {0};
    double h[100] = {0};
    f[1] = 1.0;
    h[1] = 1.0;
    for(int i = 2;i <= 15;i++){
        f[i] = (6 - f[i-1])/6 + f[i - 1];
        
    }
    for(int i = 2;i <= 6;i++){
        h[i] = h[i-1] + 6.0/(i - 1);
    }
    /* for(int i = 2;i) */
    printf("%lf\n",f[15]);
    printf("%lf",h[6]);
    return 0;
}
