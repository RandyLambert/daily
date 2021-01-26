/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> ans;
    void pre(TreeNode *root,vector<int>& temp){
        if(root != nullptr){
            temp.push_back(root->val);
        }
        if(root->left != nullptr){
            pre(root->left,temp);
        }
        if(root->right != nullptr){
            pre(root->right,temp);
        }
        return ;
    }
    void mid(TreeNode *root,vector<int>& temp){

        if(root->left != nullptr){
            mid(root->left,temp);
        }
        if(root != nullptr){
            temp.push_back(root->val);    
        }
        if(root->right != nullptr){
            mid(root->right,temp);
        }
    }
    void backWhile(TreeNode *root,vector<int>& temp){
        
        stack<TreeNode *> st;
        TreeNode *xx = root;
        while(root != nullptr && !st.empty()){
            if(xx->left != nullptr){
                st.push(xx->left);
                xx = xx->left;
                continue ;
            }
            if(xx->right != nullptr){
                st.push(xx->right);
                xx = xx->right;
                continue ;
            }
            if(xx != nullptr){
                cout<<"xxx"<<endl;
                TreeNode* x = st.top();
                st.pop();
                temp.push_back(x->val);
                continue ;
            }
        }

    }
     void preWhile(TreeNode *root,vector<int>& temp){
        if(root != nullptr){
            temp.push_back(root->val);
        }
        if(root->left != nullptr){
            pre(root->left,temp);
        }
        if(root->right != nullptr){
            pre(root->right,temp);
        }
        return ;
    }
    void midWhile(TreeNode *root,vector<int>& temp){

        if(root->left != nullptr){
            mid(root->left,temp);
        }
        if(root != nullptr){
            temp.push_back(root->val);    
        }
        if(root->right != nullptr){
            mid(root->right,temp);
        }
    }
    void back(TreeNode *root,vector<int>& temp){
        if(root->left != nullptr){
            back(root->left,temp);
        }
        if(root->right != nullptr){
            back(root->right,temp);
        }
        if(root != nullptr){
            temp.push_back(root->val);    
        }
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<int> temp;
//         preWhile(root,temp);
//         ans.push_back(std::move(temp));
//         midWhile(root,temp);
//         ans.push_back(std::move(temp));
        backWhile(root,temp);
        ans.push_back(std::move(temp));
        return ans;
    }
};
