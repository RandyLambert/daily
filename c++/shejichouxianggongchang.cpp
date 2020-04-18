#include <iostream>
using namespace std;
//抽象工厂对应的是产品族,而不是产品等级结构
//产品族:同一产地或者同一厂商,功能不同
//产品等级:功能相同,产地或者厂商不同

//抽象苹果
class abstractApple
{
public:
    virtual void showName() = 0;
};

//抽象梨
class abstractLi
{
public:
    virtual void showName() = 0;
};

//中国苹果
class chinaApple : public abstractApple
{
public:
    virtual void showName() override
    {
        cout << "china苹果" << endl;
    }
};

//美国苹果
class meiguoApple : public abstractApple
{
public:
    virtual void showName() override
    {
        cout << "美国苹果" << endl;
    }
};

//日本苹果
class ribenApple : public abstractApple
{
public:
    virtual void showName() override
    {
        cout << "日本苹果" << endl;
    }
};

//中国梨
class chinaLi : public abstractLi
{
public:
    virtual void showName() override
    {
        cout << "chinali" << endl;
    }
};

//美国梨
class meiguoLi : public abstractLi
{
public:
    virtual void showName() override
    {
        cout << "美国li" << endl;
    }
};

//日本梨
class ribenLi : public abstractLi
{
public:
    virtual void showName() override
    {
        cout << "日本苹果" << endl;
    }
};

class abstractFactory
{
public:
    virtual abstractApple *createApple() = 0;
    virtual abstractLi *createLi() = 0;
};

class chinaFactory : public abstractFactory
{
public:
    virtual abstractApple *createApple() override
    {
        return new chinaApple;
    }
    virtual abstractLi *createLi() override
    {
        return new chinaLi;
    }
};

class meiguoFactory : public abstractFactory
{
public:
    virtual abstractApple *createApple() override
    {
        return new meiguoApple;
    }
    virtual abstractLi *createLi() override
    {
        return new meiguoLi;
    }
};

class ribenFactory : public abstractFactory
{
public:
    virtual abstractApple *createApple() override
    {
        return new ribenApple;
    }
    virtual abstractLi *createLi() override
    {
        return new ribenLi;
    }
};

void test01()
{
    abstractFactory *factory = new chinaFactory;
    abstractApple *apple = new chinaApple;
    abstractLi *li = new chinaLi;
    apple = factory->createApple();
    li = factory->createLi();
}
int main()
{
    test01();
    return 0;
}
