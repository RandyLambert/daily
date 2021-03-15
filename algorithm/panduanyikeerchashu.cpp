#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
const int N = 500010;
struct tree {
    int lch,rch;
} tree[N];
bool isW = true;
bool isF = true;
int pre = -1;
void dfs(int root){
    if(isW == false){
        return ;
    }
    if(tree[root].lch != 0){
        dfs(tree[root].lch);
    }
    if(pre == -1){
        pre = root;
    } else {
        if(root < pre){
            isW = false;
        }
        pre = root;
    }
    if(tree[root].rch != 0){
        dfs(tree[root].rch);
    }
}
int main()
{
    int n, root,fa,lch,rch;
    scanf("%d%d",&n,&root);
    while(n--){
        scanf("%d%d%d",&fa,&lch,&rch);
        tree[fa].lch = lch;
        tree[fa].rch = rch;
    }
    dfs(root);
    queue<int> qu;
    qu.push(root);
    bool isS = true;
    while(!qu.empty()){
        auto x = qu.front();
        qu.pop();
        int l = tree[x].lch;
        int r = tree[x].rch;
        if(isS == false){
            if(l != 0 || r != 0){
                isF = false;
                break;
            }
        }
        if(l == 0 && r != 0){
            isF = false;
            break ;
        }
        if(l != 0 && r == 0){
            isS = false;
            if(tree[l].lch != 0 || tree[l].rch != 0){
                isF = false;
                break ;
            }
        }
        if(l != 0){
            qu.push(l);
        }
        if(r != 0){
            qu.push(r);
        }
    }
    if(isW == false){
        cout<<"false"<<endl;
    } else {
        cout<<"true"<<endl;
    }
    if(isF == false){
        cout<<"false"<<endl;
    } else {
        cout<<"true"<<endl;
    }
    return 0;
}
