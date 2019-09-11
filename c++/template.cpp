#include <iostream>
using namespace std;
template <class T>
void swap1(T& a,T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void Base1()
{

    T h = 2.2;

    cout<<h<<endl;
}
int main(){

    int a = 1,b = 2;
    float c = 1.1,d = 2.2;

    cout<<a<<b<<"\n";
    cout<<c<<d<<"\n";

    swap1(a,b);
    swap1(c,d);

    cout<<a<<b<<"\n";
    cout<<c<<d<<"\n";
    

    Base1<int>();
    
    return 0;
}
