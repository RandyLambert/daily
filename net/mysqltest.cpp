#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <memory>
#include "MySQLop.h"
using namespace std;
void *th_fun(void *arg)
{
    shared_ptr<ssxerver::net::MySQLop> q(new ssxerver::net::MySQLop()); 
    string p = "select * from user";
    q->mysqlInit();
    cout<< q->queryHasResult(p) <<endl;
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

