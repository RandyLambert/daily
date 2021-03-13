/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<TreeNode *,int>> qu;
        qu.push({root,0});
        while(!qu.empty()){
            auto x = qu.front();
            qu.pop();
            
            if(ans.size() <= x.second){
                ans.push_back(vector<int>());
            }
            ans[x.second].push_back(x.first->val);
            if(x.first->left != nullptr){
                qu.push({x.first->left,x.second+1});
            }
            if(x.first->right != nullptr){
                qu.push({x.first->right,x.second+1});
            }
        }
        return ans;
    }
};
