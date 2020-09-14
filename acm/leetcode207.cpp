class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> ru(10010);
       vector<int> mp[10010];
       for(const auto& value: prerequisites){
           ru[value[0]]++;
           mp[value[1]].push_back(value[0]);
       }

       queue<int> que;
       int ans = 0; 
       for(int i = 0;i < numCourses;i++){
           if(ru[i] == 0){
               que.push(i);
                ans++;
           }
       }

       while(!que.empty()){
           int top = que.front();
           que.pop();

           for(auto& x: mp[top]){
               ru[x]--;
               if(ru[x] == 0){
                   ans++;
                   que.push(x);
               }
           }
       }

       if(ans < numCourses){
           return false;
       }
       else return true;

    }
};
