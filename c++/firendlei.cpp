#include <bits/stdc++.h>
using namespace std;
//友元关系不能被继承
//友元关系是单向的，类a是类b的朋友，但类b不一定是类a的朋友
//友元关系不具有传递性，类b和类a的朋友，类c是类b的朋友，但类c不一定是类a的朋友
class Building;

class goodday
{
public:
    goodday();
    string a;
    void visit();
private:
     Building * building;
};

class Building
{
    //告诉编译器，他俩互相之间是好朋友，可以访问到building中的好朋友，可以访问到私有内容
    friend goodday;
public:
    Building();
public:
    string m_sittingroom;
private:
    string m_badroom;
};
goodday::goodday()
{
    this->building  = new Building;
}

void goodday::visit()
{
    cout<<"zia fangwen zhengzia"<<this->building->m_sittingroom<<endl;
    cout<<"zia fangwen zhengzia"<<this->building->m_badroom<<endl;
}
Building::Building(){
    this->m_badroom = "bad\0";
    this->m_sittingroom = "sit\0";
}


void test01(){
    goodday gg;
    gg.visit();
}
int main(){
    test01();


    return 0;
}
