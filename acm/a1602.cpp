#include <iostream>
using namespace std;
int a[1010];
int main() {
    for(int i = 1; i <= 1000;i++){
        if(i % 3 == 0){
            a[i]++;
        }
        if(i % 5 == 0){
            a[i]++;
        }
        if(i % 7 == 0){
            a[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if(a[i] == 0 || a[i] == 2){
            ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}