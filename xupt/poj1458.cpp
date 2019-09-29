#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1010],b[1010];
int dp[1010][1010];
int main(){
    while(scanf("%s%s",a,b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        
        int la = strlen(a);
        int lb = strlen(b);
        for(int i = 1;i <= la;i++)
            for(int j = 1;j <= lb;j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        printf("%d\n",dp[la][lb]);
    }

    return 0;
}

