#include <bits/stdc++.h>
using namespace std;
class Buliding
{
public:
    //客厅
    friend void goodDay(Buliding &buliding);
    //加了friend之后，该函数就可以访问私有的内容
    string msiting;
    Buliding(){
        msiting = "客厅";
        bedroom = "卧室";
    }
private:
    string bedroom;

};

void goodDay(Buliding &buliding){
    cout << "goode  faafda"<< buliding.msiting<<endl;
    cout << "goode  faafda"<< buliding.bedroom<<endl;
}

void test01(){
    Buliding a;
    goodDay(a);
}
int main(){

    return 0;
}
