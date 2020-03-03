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

class classb
{
public:
    classb(string a):a_(a){}
    classb() = default;
    string a_;
};
int main(){
    A a(string("dasdsadsa"));
    string x = "dddsas";
    A b(x);
    A c(std::move(x));
    test01(string("dsdas"));
    string d = "das";
    test01(d);


    classb bs("ddsadsadsa");
    classb by = std::move(bs);
    cout<<bs.a_<<endl;
    cout<<by.a_<<endl;


    string s2("asdsadas");
    string s3("sddsadas");
    s2 + s3 = s2;  //可以通过编译，但是右值不能放到左值

    string() = "dasdsd";

    string &&xx = "dasdsada";
    /* string &&zz = s2;//可以绑定一个右值，然后把这个右值已给别的左值 */

    string yy = std::forward<string>(xx);
    cout<<xx<<endl;
    cout<<yy<<endl;

    return 0;
}

