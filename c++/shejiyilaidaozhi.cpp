#include <iostream>
using namespace std;
//银行工作人员
class bankWorker
{
public:
    void saveService()
    {
        cout << "办理存款业务..." << endl;
    }
    void payService()
    {
        cout << "pay存款业务..." << endl;
    }
    void tranService()
    {
        cout << "tran存款业务..." << endl;
    }
};

void dosaveServer(bankWorker *worker)
{
    worker->saveService();
}

class abustractWorker
{
public:
    virtual void working() = 0;
};

class savebanker : public abustractWorker
{
public:
    virtual void working() override
    {
        cout << "save" << endl;
    }
};

class paybanker : public abustractWorker
{
public:
    virtual void working() override
    {
        cout << "pay" << endl;
    }
};

class tranbanker : public abustractWorker
{
public:
    virtual void working() override
    {
        cout << "tran" << endl;
    }
};

//中层业务
void donewbuness(abustractWorker *worker)
{
    worker->working(); //依赖一个
}
void test01()
{
    bankWorker *worker = new bankWorker;
    dosaveServer(worker);
}

void test02()
{
    abustractWorker *ab = new tranbanker;
    donewbuness(ab);
    //依赖与抽象层,不依赖某一个具体实现
}

int main()
{
    return 0;
}