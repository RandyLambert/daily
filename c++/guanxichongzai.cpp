#include <bits/stdc++.h>
using namespace std;
struct Person
{
public:
    string m_name;
    int m_age;

    Person(string name,int age)
    {
        this->m_age = age;
        this->m_name = name;
    }
    bool operator==(const Person& a) const
    {
        if(a.m_age == m_age && a.m_name == m_name){
            return true;
        }
        else
            return false;
    }
    bool operator < (const Person& a) const
    {
        if(a.m_age < m_age && a.m_name < m_name){
            return true;
        }
        else
            return false;
    }

};

void test01()
{
    int a = 10;
    int b = 10;

    if(a == b)
    {
        cout<<"a==b"<<endl;
    }
    
    Person p1("tom",10);
    Person p2("tom",10);

    if(p1 == p2)
        cout<<"p1 == p2\n";

}
int main(){
    test01();

    return 0;
}

