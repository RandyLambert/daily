class Solution {
public:
    bool cmp(int a,int b){
        return a < b;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int,vector<int>,greater<int>> pl;
        vector<int> ans;
         
        if(k > input.size()){
            return ans;
        }
        for(const auto &x : input){
            pl.push(x);
        }
         
        for(int i = 0;i < k;i++){
            ans.push_back(pl.top());
            pl.pop();
        }
        return ans;
    }
};

