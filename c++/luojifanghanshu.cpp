#include <bits/stdc++.h>
using namespace std;

void test01(){

    vector<bool>v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    vector<bool>v2;
    v2.resize(v.size());//获取元素的得提前知道大小
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());

    for(auto x = v.begin();x!=v.end();x++){
        cout<<*x<<endl;
    }
}
int main(){
    test01();

    return 0;
}
