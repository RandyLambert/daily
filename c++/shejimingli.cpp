#include <iostream>
#include <queue>
#include <unistd.h>
using namespace std;

//协议处理类
class handleClientProtocol
{
public:
    //处理增加金币
    void addMoney()
    {
        cout << "给玩家增加金币" << endl;
    }

    void addDiamond()
    {
        cout << "给玩家增加钻石" << endl;
    }
    void addLevel()
    {
        cout << "给玩家增加等级" << endl;
    }
};

//命令结口
class AbstractCommand
{
public:
    virtual void handle() = 0; //处理客户端请求的接口
};

//处理增加金币请求
class addMoneyCommend : public AbstractCommand
{
public:
    addMoneyCommend(handleClientProtocol *protocol) : pProtocol(protocol)
    {
    }

    virtual void handle()
    {
        pProtocol->addMoney();
    }

private:
    handleClientProtocol *pProtocol;
};

//处理增加金币请求
class addDiamondCommend : public AbstractCommand
{
public:
    addDiamondCommend(handleClientProtocol *protocol) : pProtocol(protocol)
    {
    }

    virtual void handle()
    {
        pProtocol->addDiamond();
    }

private:
    handleClientProtocol *pProtocol;
};

//处理增加等级请求
class addLevelCommend : public AbstractCommand
{
public:
    addLevelCommend(handleClientProtocol *protocol) : pProtocol(protocol)
    {
    }

    virtual void handle()
    {
        pProtocol->addLevel();
    }

private:
    handleClientProtocol *pProtocol;
};

//服务器程序
class Server
{
public:
    void addRequest(AbstractCommand *command)
    {
        mCommand_.push(command);
    }

    void startHandle()
    {
        while (!mCommand_.empty())
        {
            usleep(20000);
            AbstractCommand *command = mCommand_.front();
            command->handle();
            mCommand_.pop();
        }
    }

private:
    queue<AbstractCommand *> mCommand_; //放了所有发过来的协议
};

void test01()
{
    handleClientProtocol *protocol = new handleClientProtocol;
    //客户端增加金币的请求
    AbstractCommand *addmoney = new addMoneyCommend(protocol);
    //客户端增加钻石的请求
    AbstractCommand *adddiamond = new addDiamondCommend(protocol);
    //客户端升级请求
    AbstractCommand *addlevel = new addLevelCommend(protocol);

    Server *server = new Server;
    server->addRequest(addmoney);
    server->addRequest(adddiamond);
    server->addRequest(addlevel);
    //服务端进行处理请求
    server->startHandle();
}
int main()
{
    test01();
    return 0;
}