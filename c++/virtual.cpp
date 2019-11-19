#include <iostream>
using namespace std;
//基类和派生类的虚函数必须要有相同的形参列表
//如果基类与派生类的虚函数接受的实参不同，则我们就无法通过基类的引用或指针调用派生类的虚函数
class A{
public:
    A():i(10){}
    virtual void f(){cout<<"A::f()"<<i<<endl;}
    int i;
};
class B :public A{
public:
    void f(int);//形参列表与base中的f不一致
    //隐藏了基类的函数f，这里的f函数
    //B继承了A::f()的定义
    virtual void f2();//一个新的虚函数，在Base中不存在
    
};

class C : public B{
public:
    void f(int);  //非虚函数，隐藏了B::中的f函数
    void f(); //覆盖了A中的虚函数f
    void f2(); //覆盖了B的虚函数f2
};
int main(){

    A a,b;
    a.f();

    cout<<sizeof(a)<<endl;

    int *p = (int *)&a;
    int *q = (int *)&b; 
    cout<< *p << *q <<endl;

    return 0;
}

