#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int N = 10010;
int a[N];
int main(){
    int n;
    int ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    for(int i = 1;i <= n;i++){
        if(i!=a[i]){
            for(int j = i+1;j <= n;j++){
                if(a[j] == i){
                    int t;
                    t = a[j];
                    a[j] = a[i];
                    a[i] = t;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
