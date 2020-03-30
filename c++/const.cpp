#include <iostream>
#include <string>
#include <vector>
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
    dowork() = 100;
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

void test07()
{
    int i = 0;
    int j = 10;
    int* const p1 = &i; //不能改变p1的值，这是一个顶层const
    /* p1 = &j; */
    *p1 = 100;
    const int b = i;//不能改变b的值，这是一个顶层const（一般变量前const顶层const）
    const int* p2 = &b; //可以改变p2的值，这是一个底层const（对象是个const，所以可以底层执行顶层）
    p2 = &j; //可以改变地址
    /* *p2 = 1000;//底层const不能改变值 */
    int* const p4 = &j;
    /* p4 = &i; //不能改变指针的指向 */
    *p4 = 100; //可以改变指针指向的位置的值
    const int* const p3 = p2; //靠右边的是顶层const，靠左边的是底层const
    const int& some = i; //用于声明引用的都是底层const
}

void test08()
{
    int i = 0;
    const int ci = i,&cr = ci;
    auto e = &ci; //e是一个指向整数常量的指针（对常量取地址是一种底层const）
    int j = 10;
    e = &j;
}
void test09()
{       
    vector<int> vec;

    const vector<int>::iterator iter = vec.begin(); //iter的作用像一个t× const
    *iter = 10l; //可以改变值
    /* ++iter; //错误，iter是const */

    vector<int>::const_iterator cIter = vec.begin(); //cIter的作用像是个const T×
    /* *cIter = 10l; //错误，×cIter是const */
    ++cIter; //正确
}

int main()
{
    test02();
    return 0;
}

