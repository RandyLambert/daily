#include <bits/stdc++.h>
using namespace std;
class Base1{
public:
    int m_A;
    Base1():m_A(10){}
};
class Base2{
public:
    int m_B;
    int m_A;
    Base2():m_B(10),m_A(20){}
};

class Son: public Base1,public Base2
{
public:
    int m_C,m_D;
    void print(){
        cout<<Base1::m_A<<endl;
        cout<<Base2::m_A<<endl;
    }
};
//多继承语法，打印父类中数据时，应该说明是哪一个父类的数据，不然就会可能出现两个父类数据重名
void test01(){
    cout<<sizeof(Son)<<endl;
    Son ccc;
    cout<<sizeof(ccc)<<endl;
}
int main(){
    
    test01();

    return 0;
}
