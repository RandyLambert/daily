#include <iostream>
using namespace std;

class Cstr
{
public:
    int *a;
    Cstr()
    {
        a = new int[3];
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
    }
    /* Cstr(const Cstr &sr); */
    ~Cstr();
};

/* Cstr::Cstr(const Cstr &sr) */
/* { */
/*     this->a = new int[3]; */
/*     this->a[0] = sr.a[0]; */
/*     this->a[2] = sr.a[2]; */
/*     this->a[1] = sr.a[1]; */

/* }; */
Cstr::~Cstr()
{
    cout<<"hhhhhhhh"<<endl;
    delete[] a;
}

class cOpy
{
public:
    cOpy(const cOpy&);
    cOpy(); //申明了就要实现，不然就是未定义引用
    int a;
};
void test01()
{
    cOpy a;
    a.a = 10;
    cOpy b = a;
    cout<<b.a<<endl;

}
int main(){
    Cstr st;
    cout<<st.a[0]<<" "<<st.a[1]<<" "<<st.a[2]<<endl;

    Cstr a = st;
    /* Cstr a(st); */

    cout<<a.a[0]<<" "<<a.a[1]<<" "<<a.a[2]<<endl;

    return 0;
}

