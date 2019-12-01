#include <bits/stdc++.h>
using namespace std;
class Animal{
public:
    Animal(){
        cout<<"动物构造"<<endl;
    }
    /* virtual ~Animal(){ */ //虚析构写法
    /*     cout<<"动物析构"<<endl; */
    /* } */
    virtual ~Animal() = 0;//纯虚析构写法，类内声明类外定义
    virtual void speak(){
        cout<<"动物在说话\n";
    }
};

Animal::~Animal(){
    cout<<"动物析构"<<endl;
}

class Cat: public Animal{
public:
    Cat() = default;
    Cat(const char * name){
        cout<<"猫构造\n";
        namedata = new char[strlen(name+1)];
        strcpy(namedata,name);
    }
    ~Cat(){
        cout<<"猫析构\n";
        if(namedata != nullptr){
            delete namedata; 
        }
    }
    virtual void speak(){
        if(namedata!=nullptr)
            cout<<namedata<<"小猫在说话\n";
        else
            cout<<"小猫在说话\n";

    }
    char * namedata;
};
int main(){

    shared_ptr<Animal> a(new Cat("hhhh"));
    /* a = new Cat("hhhh"); */
    a->speak(); //如果不声明父类析构函数是虚函数，则只进行父类的析构函数
    //而不进行子类的析构，如果子类中没有堆区空间，则无所谓，如果有内存当场泄露
    /* delete a; */

    return 0;
}
