#include <iostream>
#include <memory>
using namespace std;
int main()
{
    unique_ptr<int> a;
    if(a==nullptr){
        cout<<"first"<<endl;
    }
    a.reset(new int(1));
    if(a==nullptr){
        cout<<"second"<<endl;
    }
    unique_ptr<int>&b = a;
    if(b==nullptr){
        cout<<"thired"<<endl;
    }
    a.reset();
    if(a==nullptr){
        cout<<"finish"<<endl;
    }
    if(b==nullptr){
        cout<<"access"<<endl;
    }

}

