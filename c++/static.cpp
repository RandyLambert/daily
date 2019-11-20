#include <iostream>
//结论一：不能通过类名来调用类的非静态成员函数
//结论二：的对象可以使用静态成员函数和非静态成员函数。
//结论三：静态成员函数中不能引用非静态成员。
//结论四：类的非静态成员可以调用静态成员函数，但反之不能。

class A
{
public:
    A(){i = 0;}
    void print(){std::cout <<i<<std::endl;}
    void set(int ii) {i = ii;}//非静态可以调用静态，编译通过
    static void say(int ii) {std::cout << ii << i <<std::endl;}
    /* static void say1(int ii) {std::cout << ii << i << test <<std::endl;}//此处编译错误  静态成员函数中不能引用非静态成员 */
    //因为静态成员函数属于整个类，在类实例化对象之前就已经分配空间
    //了，而类的非静态成员必须在类实例化对象后才有内存空间，
    //所以这个调用就会出错，就好比没有声明一个变量却提前使用它一样。

    static int i;
    int test = 10;
};
int A::i = 10;
//类外初始化静态变量，可以不带static
int main(){

    A a,b;

    a.set(10);
    b.print();
    a.say(0);
    A::say(0);//通过类名调用静态成员函数和非静态成员函数
    /* A::printf(); *///此处编译错误    非静态成员函数必须和对象对应
    std::cout<<a.i<<std::endl;
    return 0;
}
