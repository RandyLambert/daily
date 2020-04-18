#include <iostream>
using namespace std;
//提供一种代理来控制对其他对象的访问
class abstractCommonInterface
{
public:
    virtual void run() = 0;
};

//我已经写好的系统
class mySystem : public abstractCommonInterface
{
public:
    virtual void run()
    {
        cout << "系统启动..." << endl;
    }
};
//系统有一个run方法,但是必须要有权限验证,不是所有人都能来启动我的系统,必须提供用户名和密码
//通过代理类来启动

//必须有要权限验证,不是所有人都能来启动我的启动,提供用户名和密码
class mySystemProxy : public abstractCommonInterface
{
public:
    mySystemProxy(string username, string password) : mUsername_(username),
                                                      mPassword_(password),
                                                      pSystem_(new mySystem)
    {
    }
    virtual void run()
    {
        if (checkUsernameAndPassword())
        {
            cout << "输入正确" << endl;
            pSystem_->run();
        }
        else
        {
            cout << "输入错误,启动失败" << endl;
        }
    }

    bool checkUsernameAndPassword()
    {
        if (mUsername_ == "admin" && mPassword_ == "admin")
            return true;
        else
        {
            return false;
        }
    }

    ~mySystemProxy()
    {
        if (pSystem_ != NULL)
            delete pSystem_;
    }

private:
    mySystem *pSystem_;
    string mUsername_;
    string mPassword_;
};
int main()
{
    return 0;
}