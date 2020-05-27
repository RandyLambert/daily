#include <iostream>
using namespace std;
/* const string &shorterstring(const string &s1,const string &s2){ */
/*     return s1.size() <= s2.size() ? s1: s2; */
/* } */

/* string& shortstring(string &s1,string &s2){ */
/*     const string& r = shorterstring(const_cast<const string&>(s1),const_cast<const string &>(s2)); */
/*     return const_cast<string &>(r); */
/* } */

/* const string &test(const string& x){ */
/*     return x; */
/* } */

const string &manip(){
    string ret = "dfdsfdsfdsfds\0";
    string &rett=ret;
    return rett;
}

/* const string &manip(){ */
/*     string ret = "dasdsa\n"; */
/*     return ret; */
/* } */

int main(){
    const string x = manip();
    const string y = x;
    const string z = x;
    string g = x;
    g = "a";
    cout << g.compare(x) <<endl;
    string k("ssssssssssssss");
    const char* str1 = "dadsadsadasd";
    const char *p1 = str1;
    const char *p2 = str1+5;
    k.append(p1,p2);
    k.append(p1,p2);
    cout<<k<<endl;
    cout<<k<<endl;
    cout<<k<<endl;




    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    cout<<x<<endl;


    string a;
    a.push_back('1');
    cout<<a<<endl;


    return 0;
}

