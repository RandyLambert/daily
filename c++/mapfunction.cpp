#include <iostream>
#include <functional>
#include <map>
using namespace std;
typedef function<int (const string&,string &)> func;
int test01(const string &str,string &x)
{
    cout<<str<<"   "<<x<<endl;
    return 1;

}
int main(){
    std::map<int,func> mp;
    mp[0] = bind(test01,placeholders::_1,placeholders::_2);
    string q = "dsda";
    string x = "aaaadsda";
    mp[0](x,q);


    return 0;
}

