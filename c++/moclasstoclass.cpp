#include <iostream>
using namespace std;
template <class T>
class A{

public:
    A(T a = 10):a(a){}
    T a;
};

template<class T>
class C:public A<T>{
public:
    C(T c,T a) : A<T>(a){this->c = c;}
    T c;
    void print(){cout << c<<"\n";}
};

int main(){

    C<int> a(100,200);

    a.print();
    
    return 0;
}

