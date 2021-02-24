class Solution {
public:
    int dp[102][102];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp[0][0] = 1;
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1){
            return 0;
        }
        for(int i = 0;i < obstacleGrid.size();i++){
            for(int j = 0;j < obstacleGrid[i].size();j++){
                if(i != 0){
                    if(obstacleGrid[i-1][j] != 1){
                        dp[i][j] += dp[i-1][j];
                    }
                }
                if(j != 0){
                    if(obstacleGrid[i][j-1] != 1){
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        // for(int i = 0;i < obstacleGrid.size();i++){
        //     for(int j = 0;j < obstacleGrid[i].size();j++){
        //         cout<< dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
