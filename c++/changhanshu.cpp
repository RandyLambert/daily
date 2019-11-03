#include <bits/stdc++.h>
using namespace std;

class Person{
public:
    //成员函数声明后面加上const代表常函数，不可以修改成员属性了
    Person(){
        x=1;
        y=10;
    }
    void show2() 
    {
        cout<<"dasdwas"<<endl;
    }
    void show() const 
    {

        //this指针是一个指针常量 指针的指向是不可以修改的指针指向的值是可以修改的 Person const * this
        /* this->x = 1010312; */
        /* this = nullptr; */
        this->y = 13123;
        //写了const之后就不能修改成员属性了
        /* cout<<this->x<<endl; */
    }
    mutable int y;  //加上他之后，就算是加上了const，也可以去修改他
    int x;

};

void test01(){
    Person a;
    a.show();
}

void test02(){
    const Person p1; //常对象,需要自己写构造函数，不能用默认的构造函数
    //在没有用户提供的默认构造（fixit可用）的情况下，对const类型为“const person”的对象进行默认初始化
    
    //常对象也不可以修改内部属性
    
    /* p1.x = 100; */
    p1.y = 13123;//y是特殊属性，就是常对象和常函数都可以修改
    /* p1.show();//常对象可以调用常函数 */
    /* p1.show2(); *////常对象不能调用普通函数
}
int main(){
    test02();

    return 0;
}
