#include <iostream>
using namespace std;
//类模板
//template下面紧跟的内容是类，那么这个类就是类模板
//
//
//类模板与函数模板的区别
//类模板可以有默认值
//类模板只能使用显示类型推导，不能用隐式
//类模板的类型 也可以有默认参数
//泛型编程思想 将类型参数化
//
//类模板成员函数的创建时机，创建出来两个类
//
//
template<class NAMETYPE,class AGETYPE = int>
class Person
{
public:
    NAMETYPE name;
    AGETYPE age;
    Person(NAMETYPE name,AGETYPE age){
        this->age = age;
        this->name = name;
    }

};
int main(){

    return 0;
}
