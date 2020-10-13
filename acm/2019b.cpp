#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    map<int,char> mp;
    for(int i = 'A';i <= 'Z';i++){
        mp[i-'A'+1] = i;
    }

    int x = 0;
    cin>>x;
    stack<char> st;

    while(x){
        st.push(mp[x%26]);
        x = x/26;
    }

    while(!st.empty()){
        char x = st.top();
        st.pop();
        cout<<x;
    }
    cout<<endl;
    return 0;
}
