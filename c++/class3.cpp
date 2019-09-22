#include <iostream>
using namespace std;
template<class T>
class Complex
{
    friend ostream & operator<< <T>(ostream &out,Complex &c3);
public:
    Complex(T a,T b);
    Complex operator+(Complex &c2);
    void printCom();

private:
    int a;
    int b;
};
//构造函数写到了类的外面
template <class T>
Complex<T>::Complex(T a,T b)
{
    this->a = a;
    this->b = b;
}
template<class T>
void Complex<T>::printCom()
{
    cout<<"a:"<<a<<"b:"<<b<<endl;
}
//本质是模板是两次编译生成，第一次生成的是函数头，和第二次生成的函数头不相等，所以很可能不能根据正常写法实现
template<class T>
Complex<T> Complex<T>::operator+ (Complex<T> &c2)
{
    Complex<T> tmp(a+c2.a,b+c2.b);
    return tmp;
}

template <class T>
ostream & operator<<(ostream &out,Complex<T> &c3)
{
    out<< "a:"<<c3.a <<"b:"<<c3.b<<endl;
    return out; 
}
//由于函数写在类的外部，所以
//
//运算符重载的正规方法
//重载<< >>只能用有元函数，其他运算符重载，都要写成成员函数，不要滥用有元
/* ostream & operator<<(ostream &out,Complex &c3) */
/* { */
/*     out<< "a:"<<c3.a <<"b:"<<c3.b<<endl; */
/*     return out; */ 
/* } */
int main(){
    Complex<int> c1(1,2);
    Complex<int> c2(3,4);
    
    Complex<int> c3 = c1 + c2;

    cout<< c3 <<endl;
    return 0;
}

