#include <iostream>
using namespace std;

int atk = 1000;
void test01(){

    int atk = 2000;
    cout<<"局部攻击力: "<<atk<<endl;
    //::作用于运算符，如果前面有啥，就是在哪里的作用域，如果前面没有任何作用域，则表示全局作用域
    cout<<"全局攻击力: "<<::atk <<endl;
}
int main(){
    test01();

    return 0;
}
