class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(b.begin(),b.end());
        sort(a.begin(),a.end());
        long long ans = 2147483647;
        for(const auto &x : a){
            // cout<<b.lower_bound(x)<<endl;
            // cout <<  <<endl;
            auto f = lower_bound(b.begin(),b.end(),x);
            if(f != b.end()){
                ans = min(ans,abs(x - static_cast<long long>(*f)));
                            // cout<<abs(*f-x)<<endl;
            } else {
                ans = min(ans,abs(x - static_cast<long long>(b.back())));
            }
            // cout<<ans<<endl;
        }

        for(const auto &x : b){
            // cout<<b.lower_bound(x)<<endl;
            // cout <<  <<endl;
            auto f = lower_bound(a.begin(),a.end(),x);
            if(f != a.end()){
                ans = min(ans,abs(x - static_cast<long long>(*f)));
                            // cout<<abs(*f-x)<<endl;
            } else {
                ans = min(ans,abs(x - static_cast<long long>(a.back())));
            }
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};
