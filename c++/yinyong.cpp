#include <iostream>
using namespace std;
class test
{
public:
    test(int x,int y):x_(x),y_(y){}
    int x_;
    int y_;
};

test func(){
    test a(1,2);
    return a;
}

int main(){

    const test &b = func();
    cout<<b.x_<<b.y_;
    cout<<b.x_<<b.y_;
    cout<<b.x_<<b.y_;


    return 0;
}

