#include<bits/stdc++.h>
using namespace std;
int dp[2][5001];
char str1[5001],str2[5001];
int main()
{
    int n;
    scanf("%s",str1+1);
    n = strlen(str1+1);
    for(int i = 1; i <= n; i++)
        str2[i] = str1[n-i+1];       
    for(int i = 1; i<=n; i++)
        for(int j = 1; j <= n; j++)
            if(str1[i] == str2[j])
                dp[i&1][j] = dp[i-1 & 1][j-1] + 1;
            else
                dp[i&1][j] = max(dp[i-1 & 1][j], dp[i & 1][j-1]);  
    printf("%d\n", n-dp[n&1][n]);                         
    return 0;                                        
}
