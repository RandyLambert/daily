#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // for(int i = 0;i < text1.size();i++){
        //     for(int j = 0;j < text2.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i = 0;i < text1.size();i++){
            for(int j = 0;j < text2.size();j++){
                if(i > 0 && j > 0){
                    if(text1[i] == text2[j]){
                        dp[i][j] = max(max(dp[i-1][j-1] + 1,dp[i-1][j]),dp[i][j-1]);
                    } else {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
                else if(i > 0){
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else if(j > 0){
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                } else if(i == 0 && j == 0){
                    if(text2[0] == text1[0]) {
                        dp[0][0] = 1;
                    } else {
                        dp[0][0] = 0;
                    }
                }
            }
        }

        // for(int i = 0;i < text1.size();i++){
        //     for(int j = 0;j < text2.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<dp.size()<<text1.size()<<endl;
        return dp[text1.size()-1][text2.size()-1];
    }
};
using namespace std;
int main()
{
    Solution a;
    cout<<a.longestCommonSubsequence("bl","ybl")<<endl;
    return 0;
}