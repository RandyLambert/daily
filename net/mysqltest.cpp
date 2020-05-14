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
    /* shared_ptr<ssxrver::net::MySQL> mysqltest(new ssxrver::net::MySQL()); */
    ssxrver::net::MySQLsOps mysqltest;
    /* ssxrver::net::MySQL *mysqlptr = &mysqltest; */
     CJsonObject obj1;
     obj1.AddEmptySubArray("what");
     obj1["what"].Add("*");
     obj1.AddEmptySubArray("op");
     obj1["op"].Add("=");
     obj1["op"].Add("=");
     obj1.Add("tableName","user");
     obj1.AddEmptySubObject("data");
     obj1["data"].Add("userName","'管理员'");
     obj1["data"].Add("passWord","'123456'");
     cout<<obj1.ToFormattedString()<<endl;

    int x = MySQLsOps::QUERYUSER;
    if (x > MySQLsOps::MIN && x < MySQLsOps::MID)
    {
        mysqltest.queryNoResult(x, obj1);
    }
    else if (x > MySQLsOps::MID && x < MySQLsOps::MAX)
    {
        CJsonObject reback;
        mysqltest.queryHasResult(x, obj1, reback);
        reback.Add("state",200);
        reback.Add("message","传递信息");
        cout<<reback.ToFormattedString()<<endl;
    }
    return NULL;
}

void initPthread(pthread_t *tid)
{
    int n = 10;
    pthread_create(tid, NULL, th_fun, static_cast<void *>(&n));
}
int main()
{
    pthread_t tid1, tid2;
    initPthread(&tid1);
    initPthread(&tid2);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
