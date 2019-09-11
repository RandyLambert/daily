#include <iostream>
#include <cstdio>
using namespace std;
char a[5005], b[5005];
int n, dp[5005][2];	  //dp[i][0]代表当前的状态，dp[i][1]代表过去的状态
int main()
{
    while(~scanf("%d", &n)) 
    {
		scanf("%s",a);
		for(int i = 0; i < n; i++)
            b[i] = a[n-i-1];
 
		for(int i = 0; i <= n; i++)	
        {
			dp[i][0] = dp[i][1] = 0;
		}	
 
		for(int i = 1; i <= n; i++) 
        {
			for(int j = 1; j <= n; j++) 
            {
				if(a[i-1] == b[j-1])	
                    dp[j][0] = dp[j-1][1] + 1;
				else
                    dp[j][0] = max(dp[j-1][0], dp[j][1]);
			}
			for(int j = 1; j <= n; j++)
                dp[j][1] = dp[j][0];
		}
		printf("%d\n", n - dp[n][0]);
    }
    return 0;
}
