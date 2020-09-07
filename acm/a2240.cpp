#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500010;
ll arr[N];
bool isF[N];
int main()
{
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>arr[i];
    }
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    sort(arr+1,arr+n+1);
    int x = n/2;
    int cnt = x+1;
    int ans = 0;
    int i;
    for(i = 1;i <= x;i++){
        // cout<<ans<<endl;
        while(arr[i]*2 > arr[cnt] && cnt <= n){
            cnt++;
            ans+=2;
        }
        if(cnt != n+1){
            ans--;
        }
        else{
            if(arr[i]*2 >= arr[cnt]){
                ans += 2;
                // cout<<"dasdasd"<<endl;
            }
            break;
        }
    }
    // cout << i << cnt <<endl;
    // ans = ans + (x - i + n - cnt + 1) * 2;
    cout<<ans<<endl;
    return 0;
}
