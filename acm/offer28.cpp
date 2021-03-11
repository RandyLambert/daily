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
    bool dfs(TreeNode *left,TreeNode*right){
        if(left == NULL && right == NULL){
            return true;
        } else if(left == nullptr || right == nullptr || left->val != right->val){
            return false;
        } else {
            return dfs(left->left,right->right) && dfs(right->left,left->right);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return dfs(root->left,root->right);
    }
};
