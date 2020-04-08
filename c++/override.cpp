#include <iostream>
class B
{
public:
    virtual void f() const;
};

class D:public B
{
public:
    /* virtual void f() override; 因为加了override关键字，是该函数的作用是作为覆盖父函数的函数，而没加const没有覆盖任何一个函数*/
    virtual void f() const override;//正确，使用override，声明该函数是作为继承使用的函数，所以在此如果像上面一样错误使用会导致报错
    virtual void f();//错误，这个会覆盖B基类里的函数，而不是重载函数，因为const也算在函数签名中
};
int main()
{

    return 0;
}

