#include <bits/stdc++.h>
using namespace std;
int n,c,cnt = 0;
int a[100005],ans[100005];
map<int,int>q;
int main()
{
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&c);
        q[c] = i;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&c);
        a[i] = q[c];
    }

    /* for(int i = 1;i <= n;i++) */
    /* { */
    /*     printf("%d ",a[i]); */
    /* } */

    ans[1] = a[1];
    int len = 1;
    for(int i = 2;i <= n;i++)
    {
        if(ans[len] < a[i])
        {
            ans[++len] = a[i];
        }
        else
        {
            int pos = lower_bound(ans+1,ans+len+1,a[i]) - ans;
            ans[pos] = a[i];
        }
    }
    printf("%d\n",len);
    return 0;
}
