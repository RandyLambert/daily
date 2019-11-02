#include <iostream>
using namespace std;


class Person1
{
public:
    void showPerson1()
    {
        cout<< "Person 1 show"<<endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout<< "Person 2 show"<<endl;
    }
};
template<class T>
class myClass
{
public:
    T obj;
    void fuc1()
    {
        obj.showPerson1();
    }
    //语法通过，他还不清楚传进去的参数是否可以有这些函数  
    //因为要编译两次
    void fuc2()
    {
        obj.showPerson2();
    }
};

void test01(){
    myClass<Person1>a;
    a.fuc1();
    /* a.fuc2();//这里其实是不能实现的，因为里面a根本没这个函数 */
}
int main(){
    test01();

    return 0;
}
