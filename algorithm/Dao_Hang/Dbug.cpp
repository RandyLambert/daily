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
    d = a+b;
    cout<<d<<endl;

    if(d == a){
        cout<<"aadadad"<<endl;
    }
    if(d != a){
        cout<<"ccccccc"<<endl;
    }
    if(d > a){
        cout<<"ddddddddd"<<endl;
    }
    if(d < a){
        cout<<"aaaaaaaa"<<endl;
    }
    if(d <= a){
        cout<<"aaaaaaaa"<<endl;
    }
    if(d >= a){
        cout<<"ddddddddd"<<endl;
    }

    const char *e = "dsadasasdddsdasfsafddddddddd";
    myString f = myString(e,5);
    cout<<f<<" "<<f.size()<<endl;
    myString h = myString(e,17);
    cout<<h<<" "<<h.size()<<endl;

    cout<<h.front()<<" "<<h.back()<<endl;

    cout<<b.compare("dads")<<endl;

    return 0;
}

