#include <iostream>
using namespace std;
class bitNode
{
public:
    bitNode(char ch):ch_(ch),left_(nullptr),right_(nullptr){}
    char ch_;
    bitNode *left_;
    bitNode *right_;
};

void Create(bitNode **root){
    char ch;
    cin>>ch;
    if(ch == '*'){
        *root = nullptr;
    } else {
        *root = new bitNode(ch);
        Create((*root)->left_);
        Create((*root)->right_);
    }
    return ;
}

int Depth(bitNode *root){
    if(root == nullptr){
        return 0;
    } else {
        int l = Depth(root->left_);
        int r = Depth(root->right_);
        if(l < r){
            return r+1;
        } else {
            return l+1;
        }
    }

}


int main() {
    bitNode *root = nullptr;
    Create(&root);
    cout << Depth(root)<< endl;
    return 0;
}