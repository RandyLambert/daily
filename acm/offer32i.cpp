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
    vector<int> ans;
    vector<int> levelOrder(TreeNode* root) {
        if(root == NULL){
            return ans;
        }

        queue<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.front();
            st.pop();

            ans.push_back(node->val);
            if(node->left != NULL){
                st.push(node->left);
            }
            if (node->right != NULL){
                st.push(node->right);
            }
        }
        return ans;
    }
};
