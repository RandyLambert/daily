#include "text.h"
using namespace std;
extern const int x;
void text::hhh(map<int,myString> &x){
    
    cout<<"hhhhhhh"<<endl;
    x[0] = "sdads";
    x[1] = "scsadsa";
}

int main(){
    string a("4324");
    cout<<*a.begin()<<a.front()<<endl;
    int *c = new int;

    char xxxx[10] = "dd";
    const char xx = xxxx[0];
    cout<<a.back()<<endl;
    text aaa;
    map<int,myString> xxx;

    aaa.hhh(xxx);
    cout<<xxx[0]<<endl;
    cout<<x<<endl;


    return 0;
}
