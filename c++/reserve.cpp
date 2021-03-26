#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a;
    a.reserve(100);
    a.resize(50);
    cout<<a.size()<<"  "<<a.capacity()<<endl;
        //50  100
    a.resize(150);
    cout<<a.size()<<"  "<<a.capacity()<<endl;
        //150  200
    a.reserve(50);
    cout<<a.size()<<"  "<<a.capacity()<<endl;
        //150  200
    a.resize(50);
    cout<<a.size()<<"  "<<a.capacity()<<endl;
        //50  200    
}
