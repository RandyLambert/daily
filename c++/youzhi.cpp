#include <iostream>
#include <string_view>
#include <string>
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
    a = "test02...";
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

/* void stringtest(const string& a){ */
/*     cout<<"stringbyref"<<endl; */
/* } */
/* void stringtest(const string&& a){ */
/*     cout<<"stringrightbyref"<<endl; */
/* } */
/* void stringtest(const char * a){ */
/*     cout<<"stringbystr"<<endl; */
/* } */
void stringtest(string_view a){
    cout<<"string_view"<<endl;
}

int main(){

    string xxx = "dads";
    test02(xxx);
    cout<<xxx<<endl;

    string text = "312232";
    stringtest(text);
    const char *y = "dasdsa";
    stringtest(y);
    stringtest("dasdsdasd");
    stringtest(string("dasdsa"));

    string_view xxx = y;
    string yyy;
    yyy = xxx;
    cout<<yyy.back()<<endl;


    /****************************/
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
    /* string yy = xx; */
    cout<<xx<<endl;
    cout<<yy<<endl;

    return 0;
}

