class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<pair<pair<int,int>,int>> st;
        if(nums.empty()){
            return ans;
        } else if (nums.size() == 1 && nums[0] == 0) {
            return ans;
        } else{
            sort(nums.begin(),nums.end());
            for(int i = 0;i < nums.size()-1;i++){

                int left  = i+1;
                int right = nums.size()-1;
                while(left != right){
                    if(nums[i] + nums[left] + nums[right] == 0){
                        if(st.count({{nums[i],nums[left]},nums[right]}) == 0) {
                            st.insert({{nums[i],nums[left]},nums[right]});
                            ans.push_back({nums[i],nums[left],nums[right]});
                        }
                        while(left != right) {
                            left++;
                            if(nums[left-1] != nums[left])
                                break;
                        }
                        while(left != right) {
                            right--;
                            if(nums[right+1] != nums[right])
                                break;
                        }
                    } else if(nums[i] + nums[left] + nums[right] > 0){
                        right--;
                    } else if(nums[i] + nums[left] + nums[right] < 0) {
                        left++;
                    }
                }
            }
            return ans;
        }
    }

    //     vector<vector<int>> ans;
    //     set<pair<pair<int,int>,int>> ansSet;
    //     if(nums.empty()){
    //         return ans;
    //     } else if (nums.size() == 1 && nums[0] == 0) {
    //         return ans;
    //     } else{
    //         sort(nums.begin(),nums.end());
    //         for(auto i = 0;i < nums.size()-1;i++){
    //             for(auto j = i+1;j < nums.size();j++){
                    
    //                 int temp = nums[i]+nums[j];
    //                 auto x = lower_bound(nums.begin(),nums.end(),-temp);
    //                 if(x != nums.end()){
    //                     int cnt = x - nums.begin();
    //                     if(cnt != i && cnt != j && nums[cnt] == -temp) {
    //                         vector<int> tm;
    //                         tm.push_back(nums[cnt]);
    //                         tm.push_back(nums[i]);
    //                         tm.push_back(nums[j]);
    //                         sort(tm.begin(),tm.end());
    //                         if(ansSet.count({{tm[0],tm[1]},tm[2]}) == 0){
    //                             ansSet.insert({{tm[0],tm[1]},tm[2]});
    //                             ans.push_back({tm[0],tm[1],tm[2]});
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //         return ans;
    //     }
    // }

};
