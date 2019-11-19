#include <bits/stdc++.h>
using namespace std;
void test01(){
    multiset<int,less<int>>q;
    set<int,greater<int>>p;
    for(int i = 0;i < 100;i++){
        q.insert(i%5);
    }

    for(auto &z : q){
        cout<<z<<endl;
    }
    cout<<q.count(3)<<endl;
}
int main(){
    test01();

    return 0;
}
