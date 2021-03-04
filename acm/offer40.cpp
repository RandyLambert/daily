#include <unordered_set>
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        std::unordered_set<int> mp;
        for(const auto& x : data){
            if(mp.count(x) == 0){
                mp.insert(x);
            } else {
                mp.erase(x);
            }
        }
        vector<int> ans;
        for(const auto& x : mp){
//             *num1 = x;
            ans.push_back(x);
        }
        *num1 = ans[0];
        *num2 = ans[1];
    }
};
