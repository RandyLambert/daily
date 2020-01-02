#include <bits/stdc++.h>
using namespace std;
class Person
{

public:
    Person(int a=0,int b=0):m_A(a),m_B(b){}
    int m_A,m_B;
    /* Person operator+ (const Person &a) const */
    /* { */
    /*     Person temp; */
    /*     temp.m_A = m_A+a.m_A; */
    /*     temp.m_B = m_B+a.m_B; */
    /*     return temp; */
    /* } */
    //本质是p3 = p1.operator(p2)
};
Person operator+(const int b,const Person &p1)
{
    Person temp;
    temp.m_A = p1.m_A + b;
    return temp;
}
Person operator+(const Person b,const Person &p1)
{

}
Person operator+(const Person &p1,const int b)
{
    Person temp;
    temp.m_A = p1.m_A + b;
    return temp;
}
void test01()
{
    string a = "dsadsa";
    Person a(10,11),b(20,25);
    a = b+a; 
    a = 1+a;
    a = a+1;
    cout<<a.m_A<<" "<<a.m_B<<endl;
}

//运算符的重载

int main(){
    test01();
    return 0;
}
