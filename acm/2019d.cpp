#include <iostream>
#include <algorithm>
using namespace std;
bool check(int x){
    while(x){
        if(x%10 == 2 || x%10 == 4){
            return false;
        }
        x/=10;
    }

    return true;
}
int main()
{
    int ans = 0;
    int x;
    cin>>x;
    for(int i = 1;i < x-2;i++){
        for(int j = i+1;j < x-i+2;j++){
            for(int k = j+1;k < x-i-j+2;k++){
                if(check(i) && check(j) && check(k) && i+j+k == x && i!=j && j!=k && k!=i){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
