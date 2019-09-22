#include <iostream>
using namespace std;

template <class T>
class A{
public:
    A(T a = 0){
        this->a = a;
    }
    void print(){
        cout<<a<<endl;
    }
private:
    T a;

};


void Hanshu(A<int> a){
    a.print();
}
int main(){

    A<int> a(100);
    A<double> b(1.111);
    a.print();
    b.print();
    Hanshu(a);
    return 0;
}

