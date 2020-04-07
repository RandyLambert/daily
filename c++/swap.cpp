#include <iostream>
#include <algorithm>
namespace std1
{
template <typename T>
void swap(T& a,T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

class WidgetImpl
{
};

class Widget //这个class使用pimpl技法
{
public:
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs)//复制Widget时，令他复制WidgetImpl对象
    {                                   //关于operator=的一般性实现
        *pImpl = *(rhs.pImpl);
    }
    void swap(Widget& other)
    {
        using std::swap; //这个声名必要
        swap(pImpl,other.pImpl); //若要置换Widget就要置换器pimpl指针
    }
private:
    WidgetImpl* pImpl; //指针，所指的兑现内含widget数据``
};
namespace std
{
template<typename T>
void swap(T& a,T& b) //std::swap的实现
{
    T temp(a);
    a = b;
    b = temp;
}
template<>
void swap<Widget>(Widget& a,Widget& b) //这是针对std::swap“T是Widget的特化版本，目前无法通过编译”
{
    /* swap(a.pImpl,b.pImpl); */
    a.swap(b);//若要置换Widget调用swap成员函数，所有多少天了容器都是使用这种方式
}
}
}
int main()
{

    return 0;
}

