#include <iostream>
using namespace std;
//模板不常写，但是常用，很多时候要去使用别人的模板
class Person
{
public:
    string my_Name;
    int m_Age;
    Person(string name,int age)
    {
        this->my_Name = name;
        this->m_Age = age;
    }

    bool operator==(Person &b) const
    {
        if(my_Name == b.my_Name && m_Age == b.m_Age){
            return true;
        }
        else{
            return false;
        }
    }
};

template <class T>
bool myCompare(T &a,T &b){
    if(a == b){
        return true;
    }
    else{
        return false;
    }
}

template<>bool myCompare<Person>(Person &a,Person &b){
    if(a.my_Name == b.my_Name && a.m_Age == b.m_Age){
        return true;
    }
    else return false;
}
int main(){

    return 0;
}
