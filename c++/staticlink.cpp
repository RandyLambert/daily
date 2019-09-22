#include <iostream>
//多态
//分为静态多态－－－函数重载，运算符重载
//动态多态－－－父子之间继承＋虚函数
//弗雷指正或者引用，指向子类的对象
using namespace std;
//对于有父子关系的两个类，ｃ＋＋不需要强制类型转换
//惊涛离岸边　－－地址早都绑定好了
class Animal
{
public:
    virtual void speak()
    {
        cout<< "动物在说话"<<endl;
    }

};

class Cat : public Animal
{
public:

    virtual void speak()
    {
        cout << "cat jiao"<<endl;
    }
};
//利用动态联编,利用多态，调用的时候才决定
//多态的满足条件
//父类要有虚函数
//自雷要重写新函数
//在使用阶段，弗雷的指针或者引用来指向自雷的对象
//
//重写，自雷重新写弗雷的函数
//
//自雷中在做重写关键字客家可不加
void doSpeak(Animal & animal){
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
}
int main(){

    test01();

    return 0;
}

