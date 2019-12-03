#include <iostream>
using namespace std;
/* 虚基类成员的可见性： */
/* 因为在每个共享的虚基类中只有唯一一个共享的子对象，所以该基类的成员可以被直接访问，并且不会产生二义性，此外，如果虚基类的成员只被一条派生路径覆盖，则我们仍然可以直接访问这个被覆盖的成员，但是如果成员被多于一个基类覆盖，则一般情况下派生类必须为该成员自定义一个新的版本。 */
/* 例如，假定B定义了一个名为x的成员，D1和D2都是从B虚继承得到的，D继承了D1和D2，则在D的作用域中，x通过D的俩个基类都是可见的，如果我们通过D的对象使用x，有三种可能性： */
/* 1.如果在D1和D2中都没有x的定义，则x将被解析为B的成员，此时不存在二义性，一个D的对象只含有x的一个实例 */
/* 2.如果x是B的成员，同时是D1和D2中某一个的成员，则同样没有二义性，派生类的x比共享虚基类B的x优先级更高 */
/* 3.如果在D1和D2中都有x的定义，则直接访问x将产生二义性问题 */
/* 与非虚的多重继承体系一样，解决这种二义性问题最好的方法是在派生类中为成员自定义新的实例 */

class M
{
public:
	int a=8;
};
 
class A :virtual public M
{
public:
	int a=9;
};
 
class B :virtual public M
{
public:
	int a=10;
};
 
class C : public A,public B
{
public:
	void func();
	/* int a = 11;  //C必须定义自己版本的a，不然会产生错误 */
    void print(){
        cout<<A::a<<endl;
        cout<<B::a<<endl;
    }
};
 
int main()
{
	C c;
	/* cout << c.a << endl; */
    c.print();
    A a;
    B b;
    cout<<a.a<<" "<<b.a<<endl;
	return 0;
}
