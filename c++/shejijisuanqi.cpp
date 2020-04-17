#include <iostream>
using namespace std;
//写一个抽象基类,开闭原则
class AbstractCaculator
{
public:
    virtual int getResult() = 0;
    virtual void setOperatorNumber(int a, int b) = 0;
};

//加法计算器类
class PlusCaculaor : public AbstractCaculator
{
public:
    virtual void setOperatorNumber(int a, int b) override
    {
        a_ = a, b_ = b;
    }
    int getResult() override
    {
        return a_ + b_;
    }

private:
    int a_;
    int b_;
};

class DivCaculaor : public AbstractCaculator
{
public:
    virtual void setOperatorNumber(int a, int b) override
    {
        a_ = a, b_ = b;
    }
    int getResult() override
    {
        return a_ - b_;
    }

private:
    int a_;
    int b_;
};

void test01()
{
    AbstractCaculator *p = new PlusCaculaor();
    p->setOperatorNumber(1, 2);
    cout << p->getResult() << endl;
}
int main()
{
    test01();
}