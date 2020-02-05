#include <iostream>
using namespace std;
class A{
public:
    A(string a):a_(a){}
    /* A()=default;//加了这个构造函数，说明加了所有的默认构造函数 */
    A(A&)=default;//如果没加第一个构造函数，只写单个这个，只申请这一个默认构造函数，其他的都没有
    A(A&&)=default;
    string a_;
    void print(){
        cout<<a_<<endl;
    }
};
int main(){
    A a("ddsaas");
    A b(a);
    b.print();
    A c(std::move(a));
    /* A d; */
    c.print();
    a.print();


    return 0;
}
