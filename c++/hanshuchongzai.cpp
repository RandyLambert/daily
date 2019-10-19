#include <iostream>
using namespace std;
class Myfunc{
    public:
        void operator()( string text ){
            cout<< text << endl;
        }

};

class Myadd
{
public:
    int operator()(int a,int b){
        return a+b;
    }
};
void test01(){

    Myfunc a;  //重载小括号的较做仿函数
    a("hellow");//调用很像函数

    Myadd b;
    int c = b(1,2);

    //匿名的函数对象，使用完就结束了
    cout<<Myadd()(10,10)<<endl;
}


int main(){

    test01();

    return 0;
}

