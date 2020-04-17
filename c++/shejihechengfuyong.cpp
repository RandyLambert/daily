#include <iostream>
using namespace std;
class abstractCar
{
public:
    virtual void run() = 0;
};

//大众车
class daZhong : public abstractCar
{
public:
    virtual void run() override
    {
        cout << "dazhong" << endl;
    }
};

//tuolaji
class tuoLaJi : public abstractCar
{
public:
    virtual void run() override
    {
        cout << "tuolaji" << endl;
    }
};

class people
{
public:
    void setCar(abstractCar *c)
    {
        Car_ = c;
    }
    void doufeng()
    {
        Car_->run();
    }

    ~people()
    {
        if (Car_ != nullptr)
            delete Car_;
    }

private:
    abstractCar *Car_;
};

void test01()
{
    people p;
    p.setCar(new daZhong);
    p.doufeng();
}
int main()
{
    test01();
}
