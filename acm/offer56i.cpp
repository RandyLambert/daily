class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {

        vector<int> ans;
        int cnt = 0;
        for(int num : nums){
            cnt^=num;
        }

        int f = 1;
        while((f&cnt) == 0){
                f<<=1;
        }

        int a = 0;
        int b = 0;
        for(int num : nums){
            if(f&num){
                a^=num;
            } else {
                b^=num;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
