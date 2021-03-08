#include <queue>
#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> priority;
        for(const auto& x : nums){
            mp[x]++;
        }
        
        for(const auto& x: mp){
            priority.push({x.second,x.first});
        }

        while(k--){
            ans.push_back(priority.top().second);
            priority.pop();
        }
        return ans;
    }
};
