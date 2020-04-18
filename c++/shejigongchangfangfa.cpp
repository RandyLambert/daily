#include <iostream>
using namespace std;
//工厂方法模式就是简单工厂模式加上开闭原则
//缺点就是类太多了
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
class abstractFruitFactory
{
public:
    virtual abstractFruit *createFruit() = 0;
};

class appleFactory : public abstractFruitFactory
{
public:
    virtual abstractFruit *createFruit() override
    {
        return new apple;
    }
};

class liFactory : public abstractFruitFactory
{
public:
    virtual abstractFruit *createFruit() override
    {
        return new li;
    }
};
class bananaFactory : public abstractFruitFactory
{
public:
    virtual abstractFruit *createFruit() override
    {
        return new banana;
    }
};

//工厂方法模式
void test01()
{
    abstractFruitFactory *factory = new appleFactory;
    abstractFruit *fruit = factory->createFruit();
    fruit->showName();
    delete fruit;
}
int main()
{
    test01();
    return 0;
}