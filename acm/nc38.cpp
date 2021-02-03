class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if(matrix.size() == 0){
            return ans;
        }
        int left = 0,right = matrix[0].size()-1,down = 0,high = matrix.size()-1;

        while(left <= right && down <= high){
            for(int i = left;i <= right;i++){
                ans.push_back(matrix[down][i]);
            }
            down++;
            for(int i = down;i <= high;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(high >= down)
            for(int i = right;i >= left;i--){
                ans.push_back(matrix[high][i]);
            }
            high--;
            if(right >= left)
            for(int i = high;i >= down;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
