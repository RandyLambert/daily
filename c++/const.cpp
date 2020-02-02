#include <iostream>
#include <string>
using namespace std;
void test01()
{
    const int m_a = 10; //没有分配内存，存储在符号表
    int *p = (int *)&m_a; //会分配临时内存
}

void test02()
{
    int a = 10;
    const int b = a; //会分配内存,所以可以改掉里面的值
    int *p = (int *)&b;
    *p = 100;
    cout<<b<<endl;//改掉了
}

void test03()
{
    struct node{
        string a;
        int b;
    };

    const node aaa = {"32121",1};
    node *bbb = (node *)&aaa;
    bbb->b = 100;
    bbb->a = "dadsa";//分配内存了，所以也可以改掉

}

int& dowork()
{
    static int a = 10;
    return a;
}
void test05()
{
    int &ret = dowork();
    //如果函数的返回值是引用，则这个函数可以作为左值
    //引用是一个指针常量int * const aref = &a;
    cout<<ret<<endl;
    cout<<ret<<endl;
    cout<<ret<<endl;
    cout<<ret<<endl;
    cout<<ret<<endl;
}
//引用显示不修改
void showvalue(const int &val){
    cout<<val<<endl; 
}

void test06()
{
    /* int &ref = 10; //引用的不合法的内存，不可以 */
    const int &ref = 10; //加入const之后，编译器处理方式为 int tmp = 10;const int &ref = tmp;
    //相当于还是分配了内存，只要分配了内存，就说明这个可以改
    
    int *p = (int *)&ref;
    *p = 1000;
    cout << ref<< endl;
}

int main(){
    test02();
    return 0;
}

