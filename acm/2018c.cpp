#include <algorithm>
#include <iostream>
using namespace std;
int main()
{

    freopen("2018c.txt","r",stdin);
    long long ans = 1;
    int cnt = 0;
    long long x;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            cin>>x;
            cout<<ans<<" ";
            ans*=x;
            while(ans%10==0 && ans!=0){
                ans/=10;
                cnt++;
            }
            ans%=10000;
        }
        cout<<endl;
    }
    cout<<cnt;
    return 0;
}
