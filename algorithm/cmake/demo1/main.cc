#include <iostream>
#include <pthread.h>
#include <functional>
#include "boost/get_pointer.hpp"
using namespace std;
void *func(int a,int b,void *arg)
{
    cout<<pthread_self()<<a<<b<<endl;
    return NULL;
}
void *func1(void *arg)
{
    cout<<pthread_self()<<endl;
    return NULL;
}
int main(){
    pthread_t tid;


    function<void(void*)>a;
    a = bind(func,1,2,std::placeholders::_1);
    pthread_create(&tid,NULL,func1,NULL);

    pthread_join(tid,NULL);
    
    return 0;
}

