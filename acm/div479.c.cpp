#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n==1){
        if(a[n] < f)
        printf("-1\n");
        return 0;
    }
    if(a[k]!=a[k+1])
        printf("%d\n",a[k]+1);
    else
        printf("%d\n",-1);
    return 0;
}
