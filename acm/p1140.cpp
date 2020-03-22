#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
const int mp[5][5]={
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int a1[110],b1[110];
int main(){

    int la,lb;
    string a,b;
    cin>>la>>a>>lb>>b;

    for(int i = 1;i <= la;i++){
        if(a[i-1]=='A') a1[i]=0;
        if(a[i-1]=='C') a1[i]=1;
        if(a[i-1]=='G') a1[i]=2;
        if(a[i-1]=='T') a1[i]=3;
    }
     for(int i=1;i<=lb;i++){
        if(b[i-1]=='A') b1[i]=0;
        if(b[i-1]=='C') b1[i]=1;
        if(b[i-1]=='G') b1[i]=2;
        if(b[i-1]=='T') b1[i]=3;
    }
    for(int i=1;i<=la;i++)
        for(int j=1;j<=lb;j++)
            dp[i][j]=-2e8;
     

    for(int i=1;i<=la;i++) dp[i][0]=dp[i-1][0]+mp[a1[i]][4];
    for(int i=1;i<=lb;i++) dp[0][i]=dp[0][i-1]+mp[b1[i]][4];
    
    for(int i = 0;i <= la;i++){
        for(int j = 0;j <= lb;j++){
            printf("%d ",dp[i][j]);
        }
        putchar('\n');
    }
    for(int i = 1;i <= la;i++){
         for(int j = 1;j <= lb;j++){
             dp[i][j] = max(dp[i][j],dp[i][j-1] + mp[b1[j]][4]);
             dp[i][j] = max(dp[i][j],dp[i-1][j] + mp[a1[i]][4]);
             dp[i][j] = max(dp[i][j],dp[i-1][j-1] + mp[a1[i]][b1[j]]);
         }
     }
    printf("%d\n",dp[la][lb]);
    return 0;
}
