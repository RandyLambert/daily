#include <unordered_map>
// nc93
class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> ans;
        list<pair<int,int>> lis;
        unordered_map<int,list<pair<int,int>>::iterator> mp;
         
        for(unsigned i = 0;i < operators.size();i++){
//             cout<<operators[i][0]<<endl;
            if(operators[i][0] == 1){
                if(lis.size() < static_cast<unsigned>(k)){
                    lis.push_front(make_pair(operators[i][1], operators[i][2]));
                    mp[lis.begin()->first] = lis.begin();
                     
                } else {
                    mp.erase(lis.back().first);
                    lis.pop_back();
                    lis.push_front(make_pair(operators[i][1], operators[i][2]));
                    mp[lis.begin()->first] = lis.begin();
                }
                 
            }else if(operators[i][0] == 2){
                if(mp.count(operators[i][1]) == 0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(mp[operators[i][1]]->second);
                    pair<int,int> tmp = *mp[operators[i][1]];
                    lis.erase(mp[operators[i][1]]);
                    lis.push_front(tmp);
                }
                 
            }
        }
        return ans;
    }
};
