#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <memory>
#include "MySQL.h"
#include "CJsonObject.hpp"
using namespace std;
using namespace ssxrver::net;
void *th_fun(void *arg)
{
    /* shared_ptr<ssxrver::net::MySQL> mysqltest(new ssxrver::net::MySQL()); */
    ssxrver::net::MySQL mysqltest;
    mysqltest.mysqlInit();
    /* ssxrver::net::MySQL *mysqlptr = &mysqltest; */
    CJsonObject p;
    /* p.Add("") */
    int x = 1;
    if (x > mysqltest.returnMin() && x < mysqltest.returnMid())
    {
        mysqltest.useNoResultMap(x, p);
    }
    else if (x > mysqltest.returnMid() && x < mysqltest.returnMax())
    {
        CJsonObject reback;
        mysqltest.useHasResultMap(x, p, reback);
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
