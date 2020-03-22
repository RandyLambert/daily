#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);

    if(n%2 == 0)
        printf("%d\n",a[n/2]);
    else
        printf("%d\n",a[n/2+1]);

    return 0;
}

