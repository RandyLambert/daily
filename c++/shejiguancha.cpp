#include <iostream>
#include <list>
using namespace std;
//抽象英雄 抽象的观察者
class AbstractHero
{
public:
    virtual void Update() = 0;
};

//具体的英雄  具体观察者
class HearA : public AbstractHero
{
public:
    HearA()
    {
        cout << "英雄a在打boss" << endl;
    }

    virtual void Update() override
    {
        cout << "英雄a停止打boss" << endl;
    }
};

class HearB : public AbstractHero
{
public:
    HearB()
    {
        cout << "英雄B在打boss" << endl;
    }

    virtual void Update() override
    {
        cout << "英雄b停止打boss" << endl;
    }
};

class HearC : public AbstractHero
{
public:
    HearC()
    {
        cout << "英雄C在打boss" << endl;
    }

    virtual void Update() override
    {
        cout << "英雄C停止打boss" << endl;
    }
};

//观察目标抽象
class AbstractBoss
{
public:
    //添加观察者
    virtual void addHero(AbstractHero *hero) = 0;
    //删除观察者
    virtual void deleteHero(AbstractHero *hero) = 0;
    //通知所有观察者
    virtual void notify() = 0;
};

//具体的观察者 BossA
class bossA : public AbstractBoss
{
public:
    //添加观察者
    virtual void addHero(AbstractHero *hero) override
    {
        heros_.push_back(hero);
    }
    //删除观察者
    virtual void deleteHero(AbstractHero *hero) override
    {
        heros_.remove(hero);
    }
    //通知所有观察者
    virtual void notify()
    {
        for (auto const key : heros_)
        {
            key->Update();
        }
    }

private:
    list<AbstractHero *> heros_;
};

void test01()
{
    //创建观察者
    AbstractHero *heroa = new HearA;
    AbstractHero *herob = new HearB;
    AbstractHero *heroc = new HearC;
    //创建观察目标
    AbstractBoss *bossa = new bossA;
    //添加观察者
    bossa->addHero(heroa);
    bossa->addHero(herob);
    bossa->addHero(heroc);

    cout << "heroc阵亡,就不需要给c通知了" << endl;
    bossa->deleteHero(heroc);

    cout << "Boss死了..通知其他英雄停止攻击,抢装备" << endl;
    bossa->notify();
}
int main()
{
    test01();
    return 0;
}
