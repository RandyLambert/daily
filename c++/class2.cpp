#include <iostream>
using namespace std;
template<class T>
class A{
public:
    A(T a):a(a){};
    void print(){cout<<a<<endl;}
private:
        T a;


};

class B:public A<int>
{
public:
    B(int a = 10,const int b = 20) : A(b){
        this->b = a;
    } 
    void print(){cout<<"hhhhhhhhhhh"<<endl;}
    int b;

};
//子模板派生时，需要具体化模板类，c++编译器需要知道，弗雷的数据类型，
//要知道弗雷站的内存大小，才知道如何分配内存
int main(){

    B a(120,100);
    a.print();
    a.A<int>::print();
    return 0;
}

