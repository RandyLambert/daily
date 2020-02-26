#include <iostream>
#include <functional>
using namespace std;
class test
{
public:
    void testfunc(int a,int b){
        cout<<a<<b<<endl;
    }

    void testfunc2(){
        t1 = bind(&test::testfunc,this,1,1);
    }
public:
    function<void()> t1;
};


class Foo
{
public:
    void memperfunc(int a,int b,int c)
    {
        a_ = a;
        b_ = b;
        c_ = c;
        cout<<a_<<" "<<b_<<" "<<c_<<" "<<endl;
    }
private:
    int a_;
    int b_;
    int c_;
};
int main(){
    test a1;
    a1.testfunc2();
    a1.t1();

    Foo a2;
    function<void(int a)> f1;
    f1 = bind(&Foo::memperfunc,&a2,placeholders::_1,2,3);
    f1(1);
    

    return 0;
}

