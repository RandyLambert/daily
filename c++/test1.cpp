#include<bits/stdc++.h>
using namespace std;
void funcVec(vector<int>& vec){
    unordered_map<int,int> mp;
    for(const auto& key : vec){
        mp[key]++;
    }
    int i = 0;
    vector<int>::iterator it2;
    for(auto it = vec.begin();it != vec.end();){
        if(mp[*it] > 1){
            it = vec.erase(it);
        } else {
            it++;
        }
    }
    return ;
}
void funcMap(map<int,int>& mp){
    unordered_map<int,int> ump;
    for(const auto& x : mp){
        ump[x.second]++;
    }
    for(auto it = mp.begin();it != mp.end();){
        if(ump[it->second] > 1){
            it = mp.erase(it);
        } else {
            it++;
        }
    }
    return ;
}

int main()
{
    vector<int> vec{1,2,3,2,2,4};
    funcVec(vec);
    for(const auto& key : vec){
        cout<<key<<endl;
    }
    map<int,int> mp{{1,3},{2,3},{3,1},{4,1},{5,4}};
    
    funcMap(mp);
    for(const auto& key : mp){
        cout<<key.first<<" "<<key.second<<endl;
    }
    
    return 0;
}