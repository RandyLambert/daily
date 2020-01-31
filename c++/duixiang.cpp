#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
using namespace std;
class Foo
{
public:
    void memberFunc(double d,int i,int j){
        cout<<d<<endl;//0.5
        cout<<i<<endl;//100
        cout<<j<<endl;//10
    }
};
int main(){

    Foo foo;
    boost::function<void (int)> fp = boost::bind(&Foo::memberFunc,&foo,0.5,_1,10);
    fp(100);
    return 0;
}

