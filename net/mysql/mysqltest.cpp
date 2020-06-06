#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <memory>
#include "MySQLsOps.h"
#include "CJsonObject.hpp"
using namespace std;
using namespace ssxrver::net;
void *th_fun(void *arg)
{
    ssxrver::net::MySQLsOps mysqltest;

    CJsonObject obj1;
    /****************************登录*/
    /* obj1.AddEmptySubArray("what"); */
    /* obj1["what"].Add("*"); */
    /* obj1["what"].Add("userName"); */
    /* obj1["what"].Add("PassWord"); */
    /* obj1["what"].Add("sex"); */
    /* obj1.AddEmptySubArray("op"); */
    /* obj1["op"].Add("="); */
    /* obj1["op"].Add("="); */
    /* obj1.Add("tableName","user"); */
    /* obj1.AddEmptySubObject("data"); */
    /* obj1["data"].Add("userName","'管理员'"); */
    /* obj1["data"].Add("passWord","'123456'"); */
    /*****************************用户注册*/
    /* obj1.Add("tableName","user"); */
    /* obj1.AddEmptySubArray("data"); */
    /* CJsonObject obj2; */
    /* obj2.Add("uid","NULL"); */
    /* obj2.Add("userName","'ttt'"); */
    /* obj2.Add("passWord","'123456'"); */
    /* obj2.Add("sex","'m'"); */
    /* obj2.Add("phoneNumber","'13777777777'"); */
    /* obj2.Add("mibao","'1234567'"); */
    /* obj2.Add("power","3"); */
    /* obj1["data"].Add(obj2); */
    /* obj2.Clear(); */
    /* obj2.Add("uid","NULL"); */
    /* obj2.Add("userName","'sky'"); */
    /* obj2.Add("passWord","'123456'"); */
    /* obj2.Add("sex","'m'"); */
    /* obj2.Add("phoneNumber","'13666666666'"); */
    /* obj2.Add("mibao","'1234567'"); */
    /* obj2.Add("power","3"); */
    /* obj1["data"].Add(obj2); */
    /* obj2.Clear(); */
    /**********************************用户注销*/
    /* obj1.AddEmptySubArray("op"); */
    /* obj1["op"].Add(">"); */
    /* obj1["op"].Add("="); */
    /* obj1.Add("tableName","user"); */
    /* obj1.AddEmptySubObject("data"); */
    /* obj1["data"].Add("uid","100"); */
    /* obj1["data"].Add("passWord","'123456'"); */
    /**********************************用户信息修改*/
    /* obj1.AddEmptySubArray("op"); */
    /* obj1["op"].Add("="); */
    /* obj1["op"].Add("="); */
    /* obj1.Add("tableName","user"); */
    /* obj1.AddEmptySubObject("set"); */
    /* obj1["set"].Add("userName","'sky'"); */
    /* obj1["set"].Add("passWord","'123456'"); */
    /* obj1.AddEmptySubObject("data"); */
    /* obj1["data"].Add("uid","5"); */
    /* obj1["data"].Add("userName","'sky'"); */
    obj1.Add("tableName","seat");
    obj1.AddEmptySubArray("what");
    obj1["what"].Add("COUNT(*)");
    /* obj1.Add("limit","1,10"); */
    /* obj1 = string("{\"data\":{\"passWord\":\"'123456'\",\"uid\":\"3\"},\"op\":[\"=\",\"=\"],\"tableName\":\"user\",\"what\":[\"*\"]}"); */
    cout<<obj1.ToFormattedString()<<endl;
    cout<<obj1["op"].IsEmpty()<<endl;

    int x = MySQLsOps::QUERYUSER;
    cout<<x<<endl;
    CJsonObject reback;
    if (x > MySQLsOps::MIN && x < MySQLsOps::MID)
    {
        if(mysqltest.queryNoResult(x, obj1) == -1)
        {
            reback.Add("state",400);
            reback.Add("message","传递信息");
        }
        else
        {
            reback.Add("state",200);
            reback.Add("message","传递信息");
        }
    }
    else if (x > MySQLsOps::MID && x < MySQLsOps::MAX)
    {
        if(mysqltest.queryHasResult(x, obj1, reback) == -1)
        {
            reback.Add("state",400);
            reback.Add("message","传递信息");
        }
        else
        {
            reback.Add("state",200);
            reback.Add("message","传递信息");
        }
    }
    cout<<reback.ToFormattedString()<<endl;
    return NULL;
}

void initPthread(pthread_t *tid)
{
    int n = 10;
    pthread_create(tid, NULL, th_fun, static_cast<void *>(&n));
}
int main()
{
    pthread_t tid1;
    initPthread(&tid1);
    pthread_join(tid1, NULL);

    return 0;
}
