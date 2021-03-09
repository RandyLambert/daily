int dparr[370] = {0};
class Solution {
public:
    set<int> st;
    vector<int> costs1; 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto const& x : days) {
            st.insert(x);
        }
        for(int i = 0;i < costs.size();i++){
            costs1.push_back(costs[i]);
        }
        memset(dparr,-1,sizeof(dparr));

        return dp(1);
    }

    int dp(int n){
        if(n >= 366){
            return 0;
        } else if(dparr[n] != -1){
            return dparr[n];
        }
        else {
            if(st.count(n) != 0){
                dparr[n] = min(dp(n+30)+costs1[2],min(dp(n+1)+costs1[0],dp(n+7)+costs1[1]));
            } else {
                dparr[n] = dp(n+1);
            }
            return dparr[n];
        }
    }
};

// class Solution {
//     unordered_set<int> dayset;
//     vector<int> costs;
//     int memo[366] = {0};

// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         this->costs = costs;
//         for (int d: days) {
//             dayset.insert(d);
//         }
//         memset(memo, -1, sizeof(memo));
//         return dp(1);
//     }

//     int dp(int i) {
//         if (i > 365) {
//             return 0;
//         }
//         if (memo[i] != -1) {
//             return memo[i];
//         }
//         if (dayset.count(i)) {
//             memo[i] = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
//         } else {
//             memo[i] = dp(i + 1);
//         }
//         return memo[i];
//     }
// };
