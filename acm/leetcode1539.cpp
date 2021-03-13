class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int cnt = 0;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] - i - 1 >= k){
                return k+i;
            }
        }
        return k + arr.size();
    }
};
