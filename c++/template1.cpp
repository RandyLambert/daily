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
int main(){

    return 0;
}

