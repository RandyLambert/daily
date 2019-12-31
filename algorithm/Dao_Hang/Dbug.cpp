#include "Template_Tool.hpp"
#include <cstring>
using namespace std;
int main(){
    myString a("aaaaaaaaa");
    myString b = "aaaa";
    myString c(10,'c');
    myString aa;
    cin>>aa;
    cout<<aa<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    char x = a.at(1);
    cout<<x<<endl;
    cout<<a.length()<<endl;
    cout<<a.size()<<endl;

    a.swap(b);
    /* mySwap(a,b); */
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a.length()<<endl;
    cout<<b.size()<<endl;

    cout<<a.at(0)<<endl;
    const char *ptr = b.c_str();
    cout<<ptr<<endl;

    const char *ptr2 = b.fastfind(a);
    const char *ptr1 = b.find(a);
    cout<<ptr2<<"  "<<ptr1<<endl;

    a.append(b);
    a+=b;
    a+="dasda";
    a+='c';
    cout<<a<<" "<<a.length()<<endl;

    myString d(a);
    d.size();
    cout<<d<<endl;
    return 0;
}

