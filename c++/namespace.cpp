#include <iostream>
using namespace std;
//命名空间的大用途，解决命名冲突 
//命名空间下可以存放变量，函数，结构体，类。。。。
namespace a{

    int a = 10;
    void give(int a){
        cout<<a<<endl;
    }
}//命名空间只能声明在全局作用域之下
namespace b{
    int a = 100;
    void give(int a){
        cout<<a<<endl;
    }
    namespace c{//命名空间是可以嵌套的
        int d  = 2000; 
    }
}
namespace b{
    int x = 100;
}//命名空间不会覆盖，会合并,可随时添加新成员

//命名空间可以匿名，只不过是不常用 
namespace {
    //类似与全局变量，只不过在前面默认加了一个static
    int h = 312,i = 312;
    //static int h = 312;
    //static int i = 312;
}

//命名空间可以起别名
namespace dfasdasdasdasda{
    int m = 214;
}

//using声明和using编译指令有区别
void test02(){
    //2using编译指令
    int x = 1100;

    //如果有就近原则，则优先使用就近原则
    using namespace b;
    using namespace a;
    //如果开了两个命名空间，需要加作用域区分
    cout<<x<<endl;
}
int main(){
    b::give(b::a);
    a::give(b::a);
    cout<<b::c::d<<endl;
    namespace ss =  dfasdasdasdasda;
    using ss::m; //using 声明
    //当就近原则和using声明同时出现时，需要避免二义性
    //编译会不通过
    cout<<m<<endl;
    test02();
    return 0;
}
