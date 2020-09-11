#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nx[30];
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        strcpy(nx,"qwertyuiopasdfghjklzxcvbnm");
        queue<pair<string,int>> a;
        a.push({beginWord,1});
        map<string,bool> st;
        for_each(wordList.begin(),wordList.end(),
        [&st](const string& x) {
            st.insert({x,false});
        });
        int ans = 0;
        if(st.count(endWord) == 0){
            return 0;
        }
        while(!a.empty()){
            auto top = a.front();
            a.pop();
            if(top.first == endWord){
                ans = top.second;
                break;
            }
//            bool flag = false;
            auto anoTop = top;
            for(auto &x : top.first){
                char temp = x;
                for(int i = 0;i < 26;i++){
                
                    x = nx[i];
                    if(st.count(top.first) == 1 && top.first != anoTop.first){
                        if(st[top.first] == false){
                            cout<<top.first<<endl;

                            st[top.first] = true;
//                            flag = true;
                            a.push({top.first,top.second+1});
                        }
                    }
                }
                x = temp;
            }
  //          if(flag == false){
    //            break;
      //      }
        }

        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> vec = {"hot","dot","dog","lot","log","cog"};
    int ans = a.ladderLength("hit","cog",vec);
    cout <<ans <<endl;
}
