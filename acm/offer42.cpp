class Solution {
public:
    int dp[100010] = {0};
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int ans = -99999999;
        for(int i = 0;i < nums.size();i++){
            if(i >= 1)
                dp[i] = max(nums[i],dp[i-1]+nums[i]);
            else 
                dp[i] = nums[0];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
