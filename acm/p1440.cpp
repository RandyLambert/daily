#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2000010;
int b[2000010];
int dp[MAXN][2];
int mm[MAXN];
int y;
void initRMQ(int n,int b[]){
    mm[0] = -1;
    for(int i = 1;i <= n;i++){
        mm[i] = ((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        dp[i][0] = b[i];
    }

    for(int j = 1;j <= mm[n];j++){
        for(int i = 1;i + (1<<j) - 1 <= n;i++){
            dp[i][j&1] = min(dp[i][j-1&1],dp[i+(1<<(j-1))][j-1&1]);
        }
    }
}

int rmq(int x,int y){
    int k = mm[y-x+1];
    return min(dp[x][k&1],dp[y-(1<<k)+1][k&1]);
}
int main(){

    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>b[i];
    }

    initRMQ(n,b);

    for(int i = 1;i <= n;i++){
        if(i == 1){
            cout<<0<<"\n";
        }
        else if(i-m-1 <= 0){
            cout<<rmq(1,i-1)<<"\n";
        }
        else{
            cout<<rmq(i-m,i-1)<<"\n";
        }
    }
    return 0;
}
