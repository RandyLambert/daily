#include <iostream>
#include "myString.h"
using namespace std;
int main(){
    std::pair<int, myString> ls{1, "aaa"} ;
    std:: cout << ls.first << "    " << ls.second << std::endl ;
    myString a("aaaaaaaaa");
    myString b = "aaaa";
    myString c(10,'c');
    myString aa;
    cin>>aa;
    cout<<aa<<endl;

    getline(cin,aa);
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
    myString *pptr = new myString("dasdsa");
    iTerator<myString> it(pptr) ;
    iTerator<myString> it1(pptr) ;

    if(it == it1){
        cout<<"it == it1 equal"<<endl;
    }
    cout<<*it<<endl;;
    cout<<*(it++)<<endl;
    cout<<*(it--)<<endl;

    for(;it != pptr->end();it++)
        cout<<*it<<" "<<endl;

    if(it > it1){
        cout<<"itda"<<endl;
    }

    if(it >= it1){
        cout<<"itda"<<endl;
    }


    if(it1 < it){
        cout<<"it1xiao"<<endl;
    }

    if(it1 <= it){
        cout<<"it1xiao"<<endl;
    }

    cout<<*(it1+1)<<endl;
    cout<<*(it1+2)<<endl;
    cout<<*(it1+3)<<endl;
    cout<<endl;
    cout<<*(it-3)<<endl;
    cout<<*(a.data()+3)<<endl;


    return 0;
}
