#include <bits/stdc++.h>
using namespace std;
//使用动态内存的三种原因
//1.程序不清楚自己需要多少对象
//2.程序不清楚所需对象的准确类型
//3.程序需要在多个对象之间共享数据


//一个函数，返回一个shared_ptr,指向一个foo类型的动态分配的对象
//对象是通过一个类型为T的参数初始化的
class Foo
{
public:
    const int test;
    //const成员必须使用列表初始化
    Foo():test(0){};
    //如果不是const，定义了自己使用的构造函数，想继续使用默认的构造函数，加下面的代码
    /* Foo() = default; */
    Foo(int i):test(i){}
};
template <typename T>
shared_ptr <Foo> factory(T argg){
    //恰当的处理
    //share_ptr负责释放内存
    return make_shared<Foo>(argg);
}

template <typename T>
shared_ptr <Foo> use_factory(T argg){
    shared_ptr<Foo> p = factory(argg); 
    //使用p
    return p; //返回p，引用计数+1，对于代码来说，这个像是
    //p离开了作用域，但是由于引用计数+1，所以不会释放内存，有点想指针
}

template <typename T>
void use_factory(T argg){
    shared_ptr<Foo> p = factory(argg); 
    //使用p
    //离开作用域，整个就结束了
}
int main(){
    //普通指针
    Foo obj;
    auto p1 = new auto(obj); //p指向一个与obj类型相同的对象，该对象用obj进行初始化
    /* auto p2 = new auto(1,2,3);//错误，括号中只能有单个初始化器 */

    const int *pci = new const int (1024);
    //分配并初始化一个const int为1024，出于变量初始化相同的原因，对动态分配的对象最好进行初始化
    const string * pcs = new const string;//底层层const不准改里面值了，可以该指向
    string * const pcsi = new string;//顶层const不准该指向了，可以改值

    string a = "dasdsa";
    /* *pcs = "dasdsa"; */ //底层const，可以改指向不能改值
    pcs = &a;           //该指向
    *pcsi = "dasdsadas";//改值
    /* pcsi = &a; */ //顶层const，不允许改变指向


    //最安全的分配和动态使用内存的方法
    shared_ptr<int> p3 = make_shared<int>(42);
    //指向了一个42int的shape——ptr
    shared_ptr<string> p4 = make_shared<string>(10,'9');
    //指向了一个“99999999”的string
    shared_ptr<int> p5 = make_shared<int>();
    //p5是一个指向值初始化的int，初始值0
    /* vector<string>(2); */
    auto r = make_shared<int>(42);
    r = p5;
    //r指向的int只有一个引用计数
    //递减r原来指向对象的引用计数
    //r原来指向的对象已没有引用者，会自动释放
    //他是通过析构函数去完成销毁工作的、
    //shared_ptr的析构函数会销毁对象，并释放他占用的内存
    //如果不使用shared_ptr，记得删除，不然还是会占用内存

    return 0;
}
