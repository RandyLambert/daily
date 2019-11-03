#include <bits/stdc++.h>
using namespace std;
class Animal{
public:
    int age;
};
class sheep :virtual public Animal
{
public:
};
class Tuo :virtual public Animal
{
public:
};

//加上virtual是虚继承，animal类属于虚基类
//在sheep和tuo类中继承的内容Wiecbptr 虚基类指针
//v = virtual
//b = base
//ptr = pointer
//vbptr 指针指向的是虚基类表 vbtable
//vbtable中有偏移量，通过偏移量可以找到唯一的一份数据 
//解决了菱形继承会浪费一份内存

class Sheeptuo:public sheep,public Tuo
{
public:

};
int main(){
    
    Sheeptuo a;
    //访问父类数据必须加作用域，不然会导致二义性
    //如果是虚继承的话，就可以不加
    /* a.Tuo::age = 10; */
    /* a.sheep::age = 20; */
    a.age = 30;
    
    cout<<a.sheep::age;
    cout<<a.Tuo::age;
    cout<<a.age;
    return 0;
}
