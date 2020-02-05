#include <bits/stdc++.h>
using namespace std;
//使用动态内存的三种原因
//1.程序不清楚自己需要多少对象
//2.程序不清楚所需对象的准确类型
//3.程序需要在多个对象之间共享数据

//智能指针的优点
//就算程序块提前结束，智能指针也内存在不需要时进行释放


//shared_ptr的拷贝
/* shared_ptr<int> clone(int p){ */
/*     return new int(p); //隐式的转换为shared——ptr，错误 */
/* } */
shared_ptr<int> clone(int p){
    return shared_ptr<int>(new int(p)); //显式的转换为shared——ptr，正确
}

//unique_ptr的拷贝
unique_ptr<int> clone1(int p){
    //正确：从int*创建一个unique_ptr<int>
    return unique_ptr<int>(new int(p));
}

//还可以返回一个局部对象的拷贝
unique_ptr<int> clone2(int p){
    //正确：从int*创建一个unique_ptr<int>
     unique_ptr<int> ptr(new int(p));
     return ptr;
}
//由于编译器知道返回的对象将要被销毁，编译器执行一种特殊的拷贝，移动构造



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
    //缺点，调用者要自己通过delete释放内存
    //1.容易忘记释放
    //2.已经在一个地方释放，又在另一个地方重新释放
    //3.使用已经释放的内存
    //
    //
    int *pi1 = new int;//如果分配失败，new跑出std::bad::alloc
    int *pi2 = new(nothrow) int; //如果new分配失败，new返回一个空指针

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

    /* shared_ptr 和new的结合使用 */
    //由于智能指针的构造函数是explicit的
    //所以只能使用直接初始化
    /* shared_ptr<int>p1 = new int(1024);//错的 */
    shared_ptr<int> p2(new int(42));
    p2.reset(new int(1024));
    //p2指向新对象
    if(!p2.unique())//获取是不是唯一引用计数
        p2.reset(new int(3212));//不是可以重新绑定
    else
        *p2 += 12;//是，可以更改值了
    
    //智能指针的规范处理
    //1.不使用相同的内置指针初始化（或reset）多个智能指针
    //2.不delete get（）返回指针
    //不要使用get初始化另一个智能指针或者为智能指针赋值
    //get函数返回一个内置指针，但是使用get()返回的指针不能delete此指针，不然这块内存会二次释放
    shared_ptr<int> p (new int(42));
    int *qq = p.get();
    //使用q不要让他管理的指针被释放掉
    {
        //新程序块
        //未定义：两个队里的shared_ptr指向相同的内存
        /* shared_ptr<int> (q); */
        //程序块结束，q被销毁，它指向的内存被释放
    }
    int fooo = *p;//未定义，内存已被释放
    //3.如果使用了智能指针管理的资源不是new分配的资源，记住要穿进去一个删除器
    
    //总结
    //r指向的int只有一个引用计数
    //递减r原来指向对象的引用计数
    //r原来指向的对象已没有引用者，会自动释放
    //他是通过析构函数去完成销毁工作的、
    //shared_ptr的析构函数会销毁对象，并释放他占用的内存
    //如果不使用shared_ptr，记得删除，不然还是会占用内存


    //unique_ptr拥有他所指的对象,当一个unique_ptr被释放，那么他就被释放了
    //与shaped_ptr的不同
    //1.定义一个unique_ptr，某个时刻只能有一个unique_ptr指定一个给定对象
    //2.当定义一个unique_ptr绑定到一个new返回的指针上，他没有类似make_shared的标准库函数返回一个unigue_ptr
    //3.unique_ptr不支持赋值和拷贝
    //4.管理删除器的方式不同，unique_ptr需要相比较
    
    unique_ptr<double> px;///可以定义一个指向double的unique_ptr
    /* px = new double(12);//不支持赋值 */
    /* unique_ptr<string> py(px);//不支持拷贝 */
    /* px = py;//不支持赋值 */
    unique_ptr<int> py(new int(42));
    py = nullptr;//释放，指向为空
    unique_ptr<int> pz(py.release());//release将py的指针置为空
    unique_ptr<int> pi(new int(42));
    //将所有权从pi转移给pz
    /* pi.release(); //错，pi不会释放内存，而且我们会丢了指针 */
    //不能拷贝或赋值unique_ptr,但可以通过调用release或reset将指针的所有权从一个（非const）
    //unique_ptr转移给另一个unique
    pz.reset(pi.release());//reset释放了pz之前指的资源,pi转移给pz
    cout<<*pz<<endl;
    //重载一个unique_ptr中的删除器会影响到unique_ptr类型以及如何构造（reset）
    //该类型的对象，所以我们必须在尖括号中unique_ptr指向类型之后提供删除器类型
    
    
    //p指向一个类型为objT的对象，并使用一个类型delT的对象释放objT对象
    //它会调用一个名为fcn的delT类型的对象
    /* unique_ptr<obj,delT>p(new objT,fcn); */

    //重连例子
    //shared_ptr和unique_ptr两个

    //weak_ptr是一种不控制指针生存周期的智能指针
    //创建weak_ptr需要用一个shared_ptr,把一个weak_ptr绑定到shared_ptr上
    //shared_ptr不进行引用计数的增长
    
    auto pp = make_shared<int>(42);
    weak_ptr<int>wp(pp);//弱共享，没有增加引用计数

    //如果最后一个shared_ptr被释放，那么weak_ptr指向也就不存在了
    //所以每次在用的时候需要先判断一下
    
    if(shared_ptr<int> np = wp.lock()){//如果np不为空，则条件成立
        printf("还在\n");
    }
    else 
        printf("没了\n");




    //不能拷贝unique_ptr的规则有一个例外：我们可以拷贝或赋值一个将要被销
    //毁的unique_ptr,最常见的例子是从函数返回一个unique_ptr
    //见函数
    //
    //
    vector<shared_ptr<int>> v;//避免使用匿名的临时的shard_ptr
    shared_ptr<int> sha(new int);
    v.push_back(sha);//内部也要在构造一次
    cout<<sha.use_count()<<endl;//所以use_count等于2

    vector<unique_ptr<int>> v1;
    unique_ptr<int> u(new int);

    v1.push_back(std::move(u));
    //unique_ptr不能放进去,vector是const的，但是unique重载的运算符=是非const的，是需要把之前的值释放的,但是可以使用std::move使用
    //通过std::move就可以放进去了
    cout<<u.get()<<endl;

    return 0;
}
