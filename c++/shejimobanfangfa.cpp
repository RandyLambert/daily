#include <iostream>
using namespace std;
//抽象模板
class drinktemplate
{
public:
    virtual void BoilWater() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void AddSomething() = 0;

    //模板方法
    void Make()
    {
        this->BoilWater();
        this->Brew();
        this->PourInCup();
        this->AddSomething();
    }
};

class cafe : public drinktemplate
{
public:
    virtual void BoilWater() override
    {
    }
    virtual void Brew() override
    {
    }
    virtual void PourInCup() override
    {
    }
    virtual void AddSomething() override
    {
    }
};
void test01()
{
    cafe a;
    a.Make();
}
int main()
{
    test01();
    return 0;
}