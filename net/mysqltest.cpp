#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <memory>
#include "MySQL.h"
using namespace std;
void *th_fun(void *arg)
{
    shared_ptr<ssxerver::net::MySQL> q(new ssxerver::net::MySQL()); 
    string p = "INSERT INTO studio VALUES(NULL,'IMAX大厅',5,7,'IMAX影厅,3D电影');";
    q->mysqlInit();
    /* cout<< q->queryHasResult(p) <<endl; */
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

