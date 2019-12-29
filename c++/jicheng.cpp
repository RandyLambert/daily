#include <iostream>
using namespace std;
class A{
    int xxxx;
public:
    //同一个作用域重载
    void func1(){}
    void func1(int a){}
    void func2(){cout<<xxxx<<endl;}
    virtual void func3(){}
};

/* C++类的protected与private有何区别 */

/* 这两个是访问类中成员权限的限制符.在类外如果想使用类中的成员,只能直接使用public类型的, */
/* protected和private都是不能访问的,对于类外使用而言,这两个是完全相同的. */
/* 但是在基类的派生类中,可以直接访问继承而来的protected成员,但是不能访问private限制的成员 */
/* .所以在派生类中,可以访问基类继承而来的public和proected两种类型的成员.在public公有派生下, */
/* 继承而来的成员访问权限不变.protected派生下,public和protected都变成protected,private */
/* 派生下,所有的继承下来都是private了. */

class B: /*private*/ A{//什么都不写默认是私有继承
public:
    //重定义基类的func，隐藏了基类的func2方法
    void func1(){cout << "dsadas\n"; func2();}
    /* void func4(){xxxx = 100;} //父类中的私有方法，无法使用 */
    void func4(){func1();} //无论是私有继承还是public继承都是可以在类中使用的
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

    B x;
    /* x.xxxx;// 因为xxxx是父类中的私有成员，无法继承 */
    x.func1();
    /* x.func1(312);//因为已经有了b中func1，直接匹配的是b中发func1，不会去找a中func1 */ 
    string fa;

    return 0;
}
