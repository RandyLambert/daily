#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int dp[210][210];
        memset(dp,0,sizeof(dp));

        int x,y,ans = -10;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(i == 0 || j == 0){
                    if(matrix[i][j] == 0){
                        dp[i][j] = 1;
                    }
                }

                if(matrix[i][j] == 0){
                    if(matrix[i-1][j] > 0 && matrix[i][j-1] > 0){
                        if(matrix[i-1][j] >= matrix[i][j-1]){
                            matrix[i][j] = matrix[i-1][j]+1;
                            if(ans < matrix[i][j]){
                                ans = matrix[i][j];
                                x = i;
                                y = j;
                            }
                        }
                        else{
                            matrix[i][j] = matrix[i-1][j]+1;
                                if(ans < matrix[i][j]){
                                ans = matrix[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
        }
        vector<int> ans1{x,y,ans};
        //  cout<<x <<" "<<y<<" "<<ans<<endl;
        return ans1;
    }
};
int main(){
    Solution a;

    return 0;
}
