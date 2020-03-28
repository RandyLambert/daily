#include <iostream>
#include <memory>
using namespace std;
int main()
{
    string *ps1 = new string;
    string *ps = new string();//两个都是初始化为空的
    int *a = new int; //错误未定义
    int *b = new int(); //正确定义为0

    auto p1 = new auto(string());//p1指向一个与括号里的string（）类型相同的对象，并用他进行初始化
    /* auto p2 = new auto(string(),string());//错误，只能有一个 */
    //用new分配const对象是合法的
    //分配并默认初始化一个const int
    const int *pci = new const int(1024); 
    //分配并默认初始化一个const的空string
    const string *pcs = new const string;

    //内存耗尽
    int *p11 = new int; //分配失败，new抛出std::bad_alloc
    int *p2 = new (nothrow) int; //如果分配失败，new返回一个空指针
    

    return 0;
}

