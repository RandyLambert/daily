class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        dp[0] = nums[0];
        for(int i = 0;i < nums.size();i++){
            if(i != 0){
                if(i >= 2){
                dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
                } else {
                    dp[i] = max(dp[i-1],nums[i]);
                }
            }
        }
        return dp[nums.size()-1];
    }
};
