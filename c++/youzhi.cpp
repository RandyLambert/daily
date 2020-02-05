#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    A(string &&b):b_(b)//以后写析构函数写两个一个右值引用
    {//std::forward可以实现完美转交
        cout<<"&&"<<endl;
    }
    A(string &b):b_(b)//一个左值引用，在赋值的时候也要写两个
    {
        cout<<"&"<<endl;
    }
    string b_;
};

void test02(string &a){
    cout<<"02&"<<endl;
}
void test02(string &&a){
    cout<<"02&&"<<endl;
}
void test01(string &&a){
    cout<<"&&"<<endl;
    /* test02(a); */
    /* test02(std::forward<string&>(a)); */
    test02(std::forward<string&&>(a));
}
void test01(string &a){
    cout<<"&"<<endl;
}
int main(){
    A a(string("dasdsadsa"));
    string x = "dddsas";
    A b(x);
    A c(std::move(x));
    test01(string("dsdas"));
    string d = "das";
    test01(d);
    return 0;
}

