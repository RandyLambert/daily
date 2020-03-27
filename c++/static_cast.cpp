#include <iostream>
using namespace std;
int main()
{
    char a = 'a';
    const char *pc  = &a;
    char *p = const_cast<char *>(pc);
    *p = 'p';//去const

    cout<<*p<<" "<<a<<" "<<*pc<<endl;

    int j  = 100;
    const int i = j;
    /* int *ip = &i; const不能赋值*/

    const char* cp = "ddd";
    //错误：static_cast不能转换掉const的性质
    /* char *q = static_cast<char *o>(cp); */
    string s = static_cast<string>(cp);//正确，字符串字面值转为string类型
    /* const_cast<string>(cp); 错误，const_cast只改变了常量属性*/

    return 0;
}

