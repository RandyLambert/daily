class Solution {
public:
    int f[1010];
    int find(int x)
    {
        if (f[x] != x) f[x] = find(f[x]);
        return f[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        for(int i = 0;i < 1010;i++){
            f[i] = i;
        }

        for(int i = 0;i < edges.size();i++){
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
                
            if(x != y){
                f[x] = y;
                       
            }
            else{
                ans = edges[i];
            }
        }

        return ans;
    }
};
