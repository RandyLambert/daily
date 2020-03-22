#include <bits/stdc++.h>
using namespace std;
int n,m;
/* int dp[31][31]; */
int dfs(int wei,int ci){
    if(ci==m) return wei==1?1:0;
    else if(wei!=1&&wei!=n) return dfs(wei-1,ci+1) + dfs(wei+1,ci+1);
    else if(wei==1) return dfs(wei+1,ci+1) + dfs(n,ci+1);
    else if(wei == n) return dfs(wei-1,ci+1) + dfs(1,ci+1);
}
int main(){
    scanf("%d%d",&n,&m);
    printf("%d",dfs(1,0));

    return 0;
}

