#include <bits/stdc++.h>
using namespace std;
int main(){
    string mx = "";
    string tmp;
    int x,ans = 0;
    cin>>x;
    for(int i = 1;i <= x;i++){
        cin>>tmp;
        if(tmp.size() > mx.size()){
            ans = i;
            mx = tmp;
        }
        else if(tmp.length() == mx.length()){
            if(tmp > mx){
                ans = i;
                mx = tmp;
            }
        }
    }
    cout<<ans<<"\n"<<mx<<"\n";

    return 0;
}

