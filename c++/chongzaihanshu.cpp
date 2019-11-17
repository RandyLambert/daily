#include <bits/stdc++.h>
using namespace std;
class myfunc
{
public:
    int a = 10;

    /* void operator()(string x){ */
    /*     cout<<x<<endl; */
    /* } */
    int operator()(int x){
        return x*a;
    }

};

void test01(){
    myfunc f;
    cout<<f(1)<<endl;

    //还可以调用匿名函数对象
    cout<<myfunc()(1)<<endl;

}
int main(){
    test01();

    return 0;
}
