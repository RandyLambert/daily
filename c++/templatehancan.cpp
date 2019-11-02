#include <bits/stdc++.h>
using namespace std;
//类模板当做参数的三种传入方法,常用第一种，比较简单，另外两个过于复杂，需要配合函数模板
template<class NAMETYPE,class AGETYPE = int>
class Person{
public:
    NAMETYPE nametype;
    AGETYPE age;
    Person(NAMETYPE nametype,AGETYPE age){
        this->age = age;
        this->nametype = nametype;
    }
};

//指定穿进去的参数
void doWork(Person<string,int> &a)
{
    cout<<"daSDASDASDASDASDASD"<<endl;
}

//2参数模板化
template<class T1,class T2>
void doWork1(Person<T1,T2> &a){
    cout<<typeid(T1).name()<<endl;
    cout<<typeid(T2).name()<<endl;
    cout<<"dasdasdasdasdawsdasd"<<endl;
}

//3整个类模板化
template<class T>
void doWork2(T &a){
    cout<<typeid(T).name()<<endl;
    cout<<"sdasdawsdasd"<<endl;
}
void test01()
{
    Person<string,int>p1("aaa",10);
    doWork(p1);
    doWork1<string,int>(p1);
    doWork2<Person<string,int>>(p1);
}

int main(){

    test01();

    return 0;
}
