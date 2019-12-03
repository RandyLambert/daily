#include <iostream>
using namespace std;

class Person{
public:
    Person(int age){
        cout<<"Person对象构造\n";
        m_Age = age;
    }

    void showAge(){
        cout<<"年龄为： "<<this->m_Age<<endl;
    }
    //智能指针 用来托管new出来对象的释放
    ~Person()
    {
        cout<<"析构函数调用\n";
    }
private:
    int m_Age;//年龄

};

//智能指针 用来托管new出来对象的释放
class SmartPointer{
public:
    SmartPointer(Person *person){
        cout<< "SmartPointer构造函数调用"<<endl;
        this->person = person;
    }

    //重载指针运算符
    Person* operator->()
    {
        return person;
    }

    //重载*运算符
    Person& operator*(){
        return *this->person;
    }

    ~SmartPointer(){
        if(person!=nullptr){
            cout<<"SmartPointer析构函数调用"<<endl;
            delete person;
            person = nullptr;
        }
    }
private:
    Person *person;
};

void test01(){

    /* Person * p = new Person(18); */
    /* p->showAge(); */
    /* (*p).showAge(); */
    /* delete(p); */

    SmartPointer pi(new Person(18));
    pi->showAge();
    /* pi.operator->ShowAge(); */
    (*pi).showAge();

}
int main(){
    test01();

    return 0;
}
