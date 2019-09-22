#include <bits/stdc++.h>
using namespace std;
int main(){

    string a1;
    stringstream st;
    while(getline(cin,a1))
    {
        if(a1.size()==0){
            break;
        }
        int x;
        st<<a1;
        while(st>>x){
            cout<<" "<<x;
        }
    }

    return 0;
}

