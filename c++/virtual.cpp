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

class virtual_test
{
public:
    virtual_test() = default;
    virtual int func(){return 1;}
    virtual int func1() = 0;
    virtual int func2(){return 1;};
};

class virtual_test_son : public virtual_test
{
public:
    virtual int func1(){return 1;}
    virtual int func2(){return 2;}
};

struct B1
{
    virtual void f1(int)
    {
        cout<<"B1"<<endl;
    }
    virtual void f2(int)
    {
        cout<<"f2"<<endl;
    }
    virtual void f3(int) final
    {
        cout<<"f3"<<endl;
    }
    virtual void f4(int) = 0;
};

class A1 final//a1类无法被继承了
{
};

struct B2 : public B1
{
    void f1(int) override
    {
        cout<<"B2"<<endl;
    }
    /* void f2() override; //说明是继承，但是父类没有相应函数.所以使用错误 */
    /* void f3(int);//只要虚函数可以加final修饰，修饰后就不能在被继承了 */
    void f4(int) final
    {
        cout<<"f3"<<endl;
    }
};

struct B3: B2
{
    /* void f4(int); 因为f4是final*/
};


int main(){

    A a,b;
    a.f();

    cout<<sizeof(a)<<endl;

    int *p = (int *)&a;
    int *q = (int *)&b; 
    cout<< *p << *q <<endl;

    /* virtual_test test; */
    virtual_test_son test_son;
    B2 b2;
    b2.B1::f1(1);//回避虚函数机制
    b2.B2::f1(1);


    return 0;
}

