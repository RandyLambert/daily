#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0] = a[0];
    int ans = 0;
    for(int i = 1;i < n;i++)
    {
        if(a[i] > b[ans])
        {
            b[++ans] = a[i];
        }
        else
        {
            int pos = lower_bound(b,b+ans,a[i])-b;
            b[pos] = a[i];
        }
    }
    printf("%d\n",ans+1);
    return 0;
}
