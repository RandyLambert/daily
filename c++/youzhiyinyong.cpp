#include <iostream>
#include <cstring>
using namespace std;
class strVec{
public:
    int x;
    int * ptr;
    strVec(){x=0;ptr=nullptr;} //默认的构造
    strVec(int x,int y){ //自定以的拷贝构造函数
        this->ptr = new int;
        *this->ptr = y;
        this->x = x;
    }
    strVec(strVec &a):x(a.x){
        if(a.ptr == nullptr){
            this->ptr = nullptr;
        }
        else{
            this->ptr = new int;
            *this->ptr = *a.ptr;
        }
    } //拷贝构造，里面必须需要引用,如果使用指针申请空间需要深拷贝

    strVec(strVec &&a) noexcept //移动构造，不应该抛出异常，使编译器更容易优化,如果在类外定义这个方法，需要在声明和定义处都写上noexcept
        :x(a.x),ptr(a.ptr){//使用成员初始化器接管对象a中资源
            a.ptr = nullptr;//令a进入这样的状态————对其运行析构函数是安全的
        }
    ~strVec(){
        if(ptr!=nullptr){
            delete ptr;
        }
    }
};
int main(){
    int i = 42;
    int &r = i; //r引用i
    /* int &&rr = i;  //右值引用不能用到左值上 */
    /* int &r1 = i*42; //错误 i×42是一个右值 */
    int &&r2 = i * 42; //正确 可以将i×42的结果绑定
    const int &r3 = i * 42; //正确可以用const的引用绑定在右值上
    //变量是一个没有运算符的运算表达式，变量表达式也有左值和右值属性，
    //变量表达式都是左值
    //所以
    /* int &&r4 = r2; //错误，表达式r2是左值 */
    int &&r4 = std::move(r2); //正确，显示转化左值为右值
    int &&r5 = std::move(i);
    cout<<r4<<endl;
    cout<<r2<<endl; //错误，调用move后，就意味着承诺，除了对r2赋值或销毁外，不能在使用它，
    //调用move后，我们不能对原对象的值进行假设
    cout<<r5<<endl;

    char *a = "dasdsad";
    cout<<strlen(a)<<endl;
    return 0;
}
