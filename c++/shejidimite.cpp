#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//迪米特法则 有叫最少知识原则
class abstractBuilding
{
public:
    virtual void sale() = 0;
    virtual string returnQulity() = 0;
};

class buildingA : public abstractBuilding
{
public:
    buildingA()
    {
        mQulity = "高品质";
    }
    virtual void sale() override
    {
        cout << "卖了" << mQulity << endl;
    }
    virtual string returnQulity() override
    {
        return mQulity;
    }

private:
    string mQulity;
};

class buildingB : public abstractBuilding
{
public:
    buildingB()
    {
        mQulity = "低品质";
    }
    virtual void sale() override
    {
        cout << mQulity << endl;
    }
    virtual string returnQulity() override
    {
        return mQulity;
    }

private:
    string mQulity;
};

//中介类
class Mediator
{
public:
    Mediator()
    {
        abstractBuilding *buinding = new buildingA;
        vBuilding.push_back(buinding);
        buinding = new buildingB;
        vBuilding.push_back(buinding);
    }

    void shifang(abstractBuilding *p)
    {
        delete p;
    }
    ~Mediator()
    {
        //for_each(vBuilding.begin(), vBuilding.end(), &Mediator::shifang);
    }

    //需要对外提供接口
    abstractBuilding *findMyBuiliding(const string &Qulity)
    {
        for (const auto key : vBuilding)
        {
            if (key->returnQulity() == Qulity)
            {
                return key;
            }
        }
        return nullptr;
    }

private:
    vector<abstractBuilding *> vBuilding;
};
//客户端
void test01()
{
    buildingA *ba = new buildingA;
    ba->sale();
    buildingB *bb = new buildingB;
    bb->sale();
}

//客户端2
void test02()
{
    Mediator *mediator = new Mediator;

    abstractBuilding *building = mediator->findMyBuiliding("高品质");
    if (building == nullptr)
    {
        cout << "没找到" << endl;
    }
    else
    {
        building->sale();
    }
}

int main()
{
    test01();
    test02();
}
