#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <memory>
#include "MySQL.h"
using namespace std;
void *th_fun(void *arg)
{
    /* shared_ptr<ssxrver::net::MySQL> mysqltest(new ssxrver::net::MySQL()); */ 
    ssxrver::net::MySQL mysqltest; 
    mysqltest.mysqlInit();
    string p = "INSERT INTO studio VALUES(NULL,'IMAX大厅',5,7,'IMAX影厅,3D电影');";
    int x = 1;
    if(x > mysqltest.returnMin() && x < mysqltest.returnMid())
    {
        mysqltest.useNoResultMap(x,p);
    }
    else if(x > mysqltest.returnMid() && x < mysqltest.returnMax())
    {
        string reback;
        mysqltest.useHasResultMap(x,"query",reback);
    }
    return NULL;

}
void initPthread(pthread_t* tid)
{
    int n;
    pthread_create(tid,NULL,th_fun,static_cast<void *>(&n));

}
int main()
{
    pthread_t tid1,tid2;
    initPthread(&tid1);
    initPthread(&tid2);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);


    return 0;
}

