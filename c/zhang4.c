#include <stdio.h>
double fun(int n)
{
    double s = 0;
    int i,x = 0;
    for(i = 1;i <= n;i++){
        x+=i;
        s += 1/(double)x;
    }
    return s;

}
int main()
{
    printf("%lf\n",fun(11));
    
    return 0;
}

