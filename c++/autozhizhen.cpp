#include <bits/stdc++.h>
using namespace std;
class Person
{
public:
    Person(int age){
        m_Age = age;
    }

    void showAge()
    {
        cout<<"年龄为："<<this->m_Age<<endl;
    }

    ~Person()
    {
        cout<<"析构韩式"<<endl;
    }
private:
    int m_Age;
};
//智能指针 用来托管new出来对象的释放
//
class SmartPointer
{
public:
    SmartPointer(Person *person){
        this->person = person;
    }


    //重载指针运算符
    Person *operator->(){
        return this->person;
    }

    //重载×运算符
    Person& operator *(){
        return *person;
    }

    ~SmartPointer(){
        if(this->person!=NULL){
            delete this->person;
            this->person = NULL;
        }
    }
private:
    Person *person;

};
void test01()
{

    Person * p = new Person(18);
    delete p;

    //指针托管用户对象
    SmartPointer pp = SmartPointer(new Person(188));
    pp->showAge(); //按道理需要两个箭头，但是编译器优化掉了
    (*pp).showAge();
}
int main(){
    
    test01();

    return 0;
}
