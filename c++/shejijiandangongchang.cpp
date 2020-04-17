#include <iostream>
using namespace std;

class abstractFruit
{
public:
    virtual void showName() = 0;
};

//Pingguo
class apple : public abstractFruit
{
public:
    virtual void showName() override
    {
        cout << "我是苹果" << endl;
    }
};

//li
class li : public abstractFruit
{
public:
    virtual void showName() override
    {
        cout << "我是li" << endl;
    }
};

//banana
class banana : public abstractFruit
{
public:
    virtual void showName() override
    {
        cout << "我是banana" << endl;
    }
};

//水果工厂
//简单工厂,不散在23种设计模式的原因是不符合开闭原则,增加水果需要修改代码
//而且单个类的功能太重了,不符合单一职责.
//所以简单工厂适合在已经确定了数量的类里,而且类型不多
class fruitFactory
{
public:
    static abstractFruit *createFruit(string flag)
    {
        if (flag == "apple")
            return new apple;
        else if (flag == "li")
            return new li;
        else if (flag == "banana")
            return new banana;
        else
        {
            return nullptr;
        }
    }
};

void test01()
{
    fruitFactory *factory = new fruitFactory;
    abstractFruit *fruit = factory->createFruit("apple");
    fruit->showName();
    delete fruit;
}
int main()
{
    test01();
    return 0;
}