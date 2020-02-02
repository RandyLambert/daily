#include <iostream>
using namespace std;
class base{
public:
    virtual void test() = 0;
    virtual ~base(){};
};

class son1 :public base
{
public:
    virtual void test(){
        cout<<"son1"<<endl;
    }
};
class son2 :public base
{
public:
    virtual void test(){
       cout<<"son2"<<endl;
    }
};

class son3 :public base
{
public:
    virtual void test(){
       cout<<"son3"<<endl;
    }
};
int main(){
    base *q;
    son1 c;
    q = &c;
    q->test();//多态直接识别
    //本来只有父类指子类是安全的，子类指父类是不安全的
    //但是dynamic_cast可以做安全的向下转型,要在虚函数下使用
    if(dynamic_cast<son1 *>(q)){
        cout<<"son1hhhhh"<<endl;
        son1 *p = dynamic_cast<son1 *>(q);
        p->test();
    }
    if(dynamic_cast<son2 *>(q)){
        cout<<"son2"<<endl;
    }
    if(dynamic_cast<son3 *>(q)){
        cout<<"son3"<<endl;
    }


    cout<<typeid(*q).name()<<endl;
    cout<<typeid(c).name()<<endl;
    
    if(typeid(*q).name()==typeid(c).name()){
        cout<<"两种是同一种类型"<<endl;
    }
    return 0;
}
