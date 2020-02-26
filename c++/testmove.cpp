#include <iostream>
using namespace std;
class test
{
public:
    test(){cout<<"gouzao"<<endl;}
    ~test(){cout<<"xigou"<<endl;}
};

void func(test a)
{
    test x = std::move(a);
}
int main(){
    func(test());
    test *x = nullptr;
    if(x){
        cout<<"dsadsa"<<endl;
    }

    return 0;
}

