#include <iostream>
using namespace std;

class A{
public:
    A():i(10){}
    virtual void f(){cout<<"A::f()"<<i<<endl;}
    int i;
};
int main(){

    A a,b;
    a.f();

    cout<<sizeof(a)<<endl;

    int *p = (int *)&a;
    int *q = (int *)&b; 
    cout<< *p << *q <<endl;

    return 0;
}

