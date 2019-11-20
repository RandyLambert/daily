#include <iostream>
using namespace std;

template <class T>
class Base1
{
public:
    Base1(){}
    ~Base1(){}
    Base1(int){}
    Base1(const Base1 &){}
    Base1& operator=(const Base1&){}
    T& operator[](int){}
private:
    T* m_elements;
    int m_size;
};

//当编译器用一个名字来表示类型时，必须使用typename而不能用class
template <typename T>
typename T::value_type top(const T& c){
    if(!c.empty())
        return c.back();
    else
        return typename T::value_type();
}
int main(){

    return 0;
}

