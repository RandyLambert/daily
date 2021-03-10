#include <queue>
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;

        if(arr.size() == 0 || k == 0){
            return ans;
        }

        priority_queue<int> a;
        for(const auto& x : arr){
            if(a.size() < k){
                a.push(x);
            } else {
                if(a.top() > x){
                    a.pop();
                    a.push(x);
                }
            }
        }

        while(!a.empty()){
            ans.push_back(a.top());
            a.pop();
        }
        return ans;
    }
};
