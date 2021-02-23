/**
 * leetcode 94
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<bool,TreeNode*>> st;
        st.push({false,root});
        vector<int> ans;
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            if(x.second == nullptr){
                continue ;
            }
            if(x.first == false){
                st.push({false,x.second->right});
                st.push({true,x.second});
                st.push({false,x.second->left});
            } else {
                ans.push_back(x.second->val);
            }
        }
        return ans;
    }
};
