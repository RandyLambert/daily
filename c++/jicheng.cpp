#include <iostream>
using namespace std;
class A{
public:
    //同一个作用域重载
    void func1(){}
    void func1(int a){}
    void func2(){}
    virtual void func3(){}
};

class B: public A{
public:
    //重定义基类的func，隐藏了基类的func2方法
    void func1(){}
    //重写基类的func2（），也可以覆盖基类的func3（）
    virtual void func3(){}
};


//改变个别成员的可访问性
//有时候需要改变派生类继承的某个名字的访问级别，通过using声明
class Base{
public:
    size_t size() const{ return n; }
protected:
    size_t n;

};

class Derived : private Base //private继承
{
public:
    //保持对象尺寸相关成员的访问级别
    using Base::size;
protected:
    using Base::n;
};
int main(){
    Derived a;
    a.size();

    return 0;
}
