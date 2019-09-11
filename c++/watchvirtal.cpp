#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void f(){cout << "Base1::f"<<endl;}
    virtual void g(){cout << "Base1::g"<<endl;}
    virtual void h(){cout << "Base1::h"<<endl;}

};

class Base2{
public:
    virtual void f(){cout <<"Base2::f"<<endl;}
    virtual void g(){cout <<"Base2::g"<<endl;}
    virtual void h(){cout <<"Base2::h"<<endl;}
};

class Base3{
public:
    virtual void f(){cout<<"Base3::f"<<endl;}
    virtual void g(){cout<<"Base3::g"<<endl;}
    virtual void h(){cout<<"Base3::h"<<endl;}
};

class Derive : public Base2,public  Base1,public Base3{
public:
    virtual void f(){cout<<"Derive::f"<<endl;}
    virtual void g1(){cout<<"derive::g1"<<endl;}
    virtual void h(){cout<<"Derive::h"<<endl;}
};

typedef void(*Fun)(void);

int main(){
    /* Fun pFun = NULL; */

    Derive d;

    /* int ** pVtab = (int**)&d; */
    //Base1s vtable
    //pFun = (Fun)*((int *)*(int*)((int*)&d+0)+0);
    
    /* pFun = (Fun)pVtab[0][0]; */

    /* pFun(); */

    d.g1();
    d.f();
    d.Base1::f();
    d.Base1::g();
    d.Base1::h();
    d.Base2::g();

    return 0;
}

