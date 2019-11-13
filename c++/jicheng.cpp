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
int main(){

    return 0;
}
