#include <stdio.h>
using namespace std;
int n;
int a[30],dp[30];
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        dp[i] = 1;
    }
    for(int i = 2;i <= n;i++)
    {
        int temp = 1;
        for(int j = 1;j < i;j++)
        {
            if(a[i]<=a[j]&&temp < dp[i]+dp[j])
            {
                temp = dp[i]+dp[j];
            }
        }
        dp[i] = temp;
    }
    int res = 0;
    for(int i = 1;i <= n;i++)
    {
        if(res < dp[i])
        {
            res = dp[i];
        }
    }
    printf("%d\n",res);
    return 0;
}
