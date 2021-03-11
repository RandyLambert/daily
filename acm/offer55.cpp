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
    int dfs(int cnt,TreeNode *node){
        if(node != nullptr){
            int left = dfs(cnt+1,node->left);
            if(left == -1){
                return -1;
            }
            int right = dfs(cnt+1,node->right);
            if(right == -1){
                return -1;
            }
            if(abs(left-right) > 1){
                return -1;
            } else {
                return max(right,left) + 1;
            }
        } else {
            return 0;
        }   
    }
    bool isBalanced(TreeNode* root) {
        int ans = dfs(0,root);
        if(ans == -1){
            return false;
        }
        return true;
    }
};
