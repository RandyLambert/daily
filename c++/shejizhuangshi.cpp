#include <iostream>
#include <algorithm>
using namespace std;
//一般用继承实现类的功能拓展
//装饰模式  可以动态的给一个类增加功能

//抽象英雄
class abstractHero
{
public:
    virtual void showStatus() = 0;

public:
    int mHp_;
    int mMp_;
    int mAt_;
    int mDf_;
};

//具体英雄
class heroA : public abstractHero
{
public:
    heroA()
    {
        mHp_ = 0;
        mMp_ = 0;
        mAt_ = 0;
        mDf_ = 0;
    }

    virtual void showStatus() override
    {
        cout << mHp_ << endl;
        cout << mMp_ << endl;
        cout << mAt_ << endl;
        cout << mDf_ << endl;
    }
};

//英雄穿上某个装饰物  那么他还是英雄
class abstractEquipment : public abstractHero
{
public:
    abstractEquipment(abstractHero *hero) : pHero_(hero)
    {
    }

    virtual void ShowStatus() {}

protected:
    abstractHero *pHero_;
};

//狂徒
class KuangtuEquipment : public abstractEquipment
{
public:
    KuangtuEquipment(abstractHero *hero) : abstractEquipment(hero) {}
    //增加额外功能,感觉可以放到构造函数里面
    void AddKuangtu()
    {
        cout << "英雄穿上狂徒之后" << endl;
        this->mHp_ = this->pHero_->mHp_;
        this->mMp_ = this->pHero_->mMp_;
        this->mAt_ = this->pHero_->mAt_;
        this->mDf_ = this->pHero_->mDf_ + 1000;

        delete this->pHero_;
    }
    virtual void showStatus() override
    {
        AddKuangtu();
        cout << mHp_ << endl;
        cout << mMp_ << endl;
        cout << mAt_ << endl;
        cout << mDf_ << endl;
    }
};

void test01()
{
    abstractHero *hero = new heroA;
    hero->showStatus();

    cout << "-------------------" << endl;

    //给裸奔的英雄穿上衣服
    hero = new KuangtuEquipment(hero);
    hero->showStatus();
}
int main()
{
    test01();
    return 0;
}
