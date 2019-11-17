#include <bits/stdc++.h>
using namespace std;
//内建函数对象关系仿函数
//大于greater
//
template <class T>
class MyCompare
{
public:
    bool operator()(T a,T b){
        return a < b;
    }
};
void test01(){

    vector<int>v;

    v.push_back(312);
    v.push_back(12);
    v.push_back(32);
    v.push_back(31);
    v.push_back(2);

    for(auto &x : v){
        cout<<x<<endl;
    }

    //greater是内建的仿函数
    sort(v.begin(),v.end(),greater<int>());
    for(auto &x : v){
        cout<<x<<endl;
    }
    sort(v.begin(),v.end(),MyCompare<int>());
    for(auto &x : v){
        cout<<x<<endl;
    }
}
int main(){
test01();
    return 0;
}
