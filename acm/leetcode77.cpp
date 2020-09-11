#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n_,k_;
    void dfs(int k,int n,vector<bool> &isUsed,vector<int>& oneAns,vector<vector<int>>& ans){
        if(k == k_+1){
            ans.push_back(oneAns);

//            for(int i = 0;i < k_;i++)
  //              cout<< oneAns[i];
    //        cout<<endl;

            return ;
        }

        for(int i = n;i <= n_;i++){
            if(isUsed[i] == false){
                oneAns.push_back(i);
                isUsed[i] = true;
                dfs(k+1,n+1,isUsed,oneAns,ans);
                isUsed[i] = false;
                oneAns.pop_back();

                //dfs(k,n+1,isUsed,oneAns,ans);
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        vector<vector<int>> ans;
        vector<int> oneAns;
        vector<bool> isUsed(n+10);

        dfs(1,1,isUsed,oneAns,ans);

        return ans;
    }
};

int main()
{

    Solution a;
    auto x = a.combine(4,2);
/*  for_each(x.begin(),x.end(),[](const auto &ans){
        for(const auto &value : ans){
            cout<<value<<endl;        
        }
    });
    cout<<<<endl;
  */  
    return 0;
}
