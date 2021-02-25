class Solution {
public:
    int dp1[101];
    int dp2[101];
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        dp1[1] = nums[1];
        for(int i = 1;i < nums.size();i++){
            if(i >= 2) {
                if(i >= 3){
                    dp1[i] = max(dp1[i-1],nums[i] + dp1[i-2]);
                } else {
                    dp1[i] = max(dp1[i-1],nums[i]);
                }   
            }
        }
        dp2[0] = nums[0];
        for(int i = 0;i < nums.size() - 1;i++){
            if(i >= 1) {
                if(i >= 2){
                    dp2[i] = max(dp2[i-1],nums[i] + dp2[i-2]);
                } else {
                    dp2[i] = max(dp2[i-1],nums[i]);
                }   
            }
        }
        return max(dp1[nums.size()-1],dp2[nums.size()-2]);
    }
};
