#include <iostream>
class A
{
public:
    A(){i = 0;}
    void print(){std::cout <<i<<std::endl;}
    void set(int ii) {i = ii;}
    static void say(int ii) {std::cout << ii << i << std::endl;}
    static int i;
};
int A::i;
int main(){

    A a,b;

    a.set(10);
    b.print();
    a.say(0);
    A::say(0);
    std::cout<<a.i<<std::endl;
    return 0;
}
