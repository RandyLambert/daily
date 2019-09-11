#include <iostream>
#include <string>

template <class T>
class stack{
public:
    stack(unsigned int size = 100);
    ~stack();
    void push(T value);
    T pop();
private:
    unsigned int size;
    unsigned int sp;
    T *data;
};


template <class T>
stack<T>::stack(unsigned int size)
{
    this->size = size;
    data = new T[size];
    sp = 0;
}
template <class T>
stack<T>::~stack()
{
    delete  []data;
}

template <class T>
void stack<T>::push(T value)
{
    data[sp++] = value;
}
template <class T>
T stack<T>::pop()
{
    return data[--sp];
}

int main(){

    stack<int>a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    std::cout<<a.pop()<<std::endl;
    std::cout<<a.pop()<<std::endl;
    std::cout<<a.pop()<<std::endl;
    std::cout<<a.pop()<<std::endl;
    std::cout<<a.pop()<<std::endl;
    return 0;
}

