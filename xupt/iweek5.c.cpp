#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
 
const int MaxN = 10005;
const double eps = 1e-8;
int t, n, v[MaxN];
double P, p[MaxN], dp[MaxN];
 
void solve()
{
    scanf("%lf%d", &P, &n); 
    P = 1.0 - P;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%lf", &v[i], &p[i]);
        p[i] = 1.0 - p[i]; sum += v[i];
    }
    
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = sum; j >= v[i]; j--)
            dp[j]=max(dp[j], dp[j-v[i]] * p[i]);   
    for(int i = 0;i < sum;i++){
        printf("%lf ",p[i]);
    }
    for (int i = sum; i >= 0; i--)
        if (dp[i] - P > eps)
    {
        printf("%d\n", i); break;
    }
}
 
int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
