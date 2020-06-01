#include <iostream>
using namespace std;
void func(void *data);
class test
{
public:
    void * data;
    void (*p)(void *data);
    void fun()
    {
        p(data);
    }
};

class father
{
public:
    father(){
        i = 1000;
        a.p = func;
        a.data = this;
    } 
    test a;
    int i;
};

void func(void *data)
{
    auto a = static_cast<father *>(data);
    a->i = 22222;
    cout << a->i <<endl;
}

int main(){
    father h;
    h.a.fun();
    cout << h.i;
    

    return 0;
}

