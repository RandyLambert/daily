#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(x!=0)
        return gcd(y%x,x);
    else
        return y;
}
int main(){
    int t,n,a,b;

    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        scanf("%d%d%d",&n,&a,&b);
        if(gcd(a,b)==1)
        {
            if(n%2==0)
                printf("Case #%d: Iaka\n",i);
            else
                printf("Case #%d: Yuwgna\n",i);
        }
        else
        {
            int xx = gcd(a,b);
            if(n/xx%2==0)
                printf("Case #%d: Iaka\n",i);
            else
                printf("Case #%d: Yuwgna\n",i);
        }
    }
    return 0;
}
