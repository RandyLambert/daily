  #include <bits/stdc++.h>                                                                                                              
  using namespace std;
  int n,m;
  int dp[31][31];
  void dfs(int wei,int ci){
      dp[wei][ci] = 0;
      if(wei==1&&ci==m) dp[wei][ci] = 1; 
      
      if(ci != m){
          if(dp[wei%n+1][ci+1]==-1){
              dfs(wei%n+1,ci+1);
          }
          if(wei!=1){
              if(dp[wei-1][ci+1]==-1)
                  dfs(wei-1,ci+1);
          }
          else if(wei==1){
            if(dp[n][ci+1]==-1)
                dfs(n,ci+1);
          }
          dp[wei][ci] = dp[wei%n+1][ci+1] + dp[wei!=1?wei-1:n][ci+1];
      } 
 }
  int main(){
      memset(dp,-1,sizeof(dp));
      scanf("%d%d",&n,&m);
      dfs(1,0);
      for(int i = 1;i < 4;i++){
          for(int j = 0;j < 4;j++){
              printf("%d  ",dp[i][j]);
          }
          putchar('\n');
      }
      printf("%d",dp[1][0]);
  
      return 0;
  }

