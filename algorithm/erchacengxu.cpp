/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */
 // nc 15
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ans;
    void ceng(TreeNode* root,int cen){
         
        while(ans.size() <= cen){
            ans.push_back(vector<int>());
//             cout<<"s"<<endl;
        }//cout<<"s"<<endl;
        ans[cen].push_back(root->val);
//         cout<<"s"<<endl;
        if(root->left != nullptr){
            ceng(root->left,cen+1);
        }
        if(root->right != nullptr){
            ceng(root->right,cen+1);
        }
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        if(root != nullptr)
            ceng(root, 0);
        return ans;
         
    }
};
