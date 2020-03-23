#include <iostream>
#include <map>
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

int func(int a,int b)
{
    cout<<a<<b<<endl;
    return a+b;
}


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

class myPair
{
public:
    double a_;
    double b_;
    double mult(){ return a_*b_; }
};

int main(){
    test a1;
    a1.testfunc2();
    a1.t1();
    int (*add)(int x,int y) = func; 

    auto mod = [=](int i,int j)->int{return i%j;};
    map<string,function<int(int,int)>> han = {
        {"+",add},//函数指针
        {"-",std::minus<int>()},//标准库函数对象
        {"/",func},//用户自定义函数
        {"*",[](int i,int j)->int{ return i*j;}},//匿名的lambda表达式
        {"%",mod}//具名的lambda表达式
    }; 
    han["+"](123,32);
    han["-"](123,32);
    han["%"](123,32);

    Foo a2;
    function<void(int a)> f1;
    f1 = bind(&Foo::memperfunc,&a2,placeholders::_1,2,3);
    f1(1);


    function<void(int,int)> f2 = bind(&func,std::placeholders::_1,std::placeholders::_2);
    f2(1,2);

    myPair test{1,2};
    auto x = bind(&myPair::mult,placeholders::_1);
    x(test);
    

    return 0;
}

