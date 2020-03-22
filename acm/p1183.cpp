#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
    int n,ans = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d%d",&a[i],&b[i]);
    a[n] = a[0],b[n] = b[0];
    for(int i = 0;i < n;i++)
        ans = ans + (a[i]*b[i+1]-a[i+1]*b[i]);
    printf("%d\n",ans/2);
    return 0;
}
