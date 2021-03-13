class Solution {
public:
    bool vis[1000010] = {false};
    int ans = 999999999;
    void dfs(int num,int cnt,vector<unordered_set<int>>& rou, int target){
        if(rou[cnt].count(target) == 1){
            ans = min(num,ans);
            return ;
        }
        for(int i = 0;i < rou.size();i++){
            
            if(vis[i] != true){
                int flag = false;
                for(auto x : rou[i]){
                    if(rou[cnt].count(x) == 1){
                        flag = true;
                        break;
                    }
                }
                if(flag == true){
                    vis[i] = true;
                    dfs(num+1,i,rou,target);
                    vis[i] = false;
                }
            }
        }
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        vector<unordered_set<int>> rou;
        for(int i = 0;i < routes.size();i++){
            rou.push_back(unordered_set<int>());
            for(int j = 0;j < routes[i].size();j++){
                rou[i].insert(routes[i][j]);
            }
        }

        for(int i = 0;i < rou.size();i++){
            if(rou[i].count(source) == 1){
                memset(vis,0,sizeof(vis));
                vis[i] = true;
                dfs(1,i,rou,target);
            }    
        }
        if(ans == 999999999){
            return -1;
        }
        return ans;    
    }
};
