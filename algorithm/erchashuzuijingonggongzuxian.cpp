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
    unordered_map<TreeNode*,TreeNode*> mp;
    unordered_map<TreeNode*,bool> vis;
    void dfs(TreeNode *root){
        if(root->left != nullptr){
            mp[root->left] = root;
            dfs(root->left);
        }
        if(root->right != nullptr){
            mp[root->right] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        vis[p] = true;
        while(p != nullptr){
            if(mp.count(p) == 1){
                vis[mp[p]] = true;
                p = mp[p];
            } else {
                p = nullptr;
            }
        }
        if(vis[q] == true){
            return q;
        }
        while(q != nullptr){
            if(mp.count(q) == 1){
                if(vis[mp[q]] == true){
                    return mp[q];
                }
                q = mp[q];
            } else {
                q = nullptr;
            }
        }
        return nullptr;
    }
};
