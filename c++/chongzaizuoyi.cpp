#include <bits/stdc++.h>
using namespace std;
class Person
{
    //将全局函数 <<运算符重载声明放进去
    friend ostream& operator<<(ostream &cout,Person &p1);
public:
    Person(){}
    Person(int a,int b):m_A(a),m_B(b){}
    //左移运算符不能用成员函数
private:
    int m_A,m_B;
};

ostream& operator<<(ostream &cout,Person &p1)
{
    cout<<"m_a = "<<p1.m_A;
    return cout;
}
void test01()
{
    Person p1(10,10);
    cout<<p1<<endl;
}
int main(){
    //cout是输出流对象
    test01();
    return 0;
}

