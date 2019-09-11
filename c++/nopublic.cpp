#include <bits/stdc++.h>
using namespace std;
class Base
{
private:
        virtual void f(){cout<<"dd"<<endl;}
};

class Derive:public Base
{
    
};

typedef void(*fun)(void);

int main(){

    Derive d;
    
    fun pfun = (fun)*((int*)*(int*)(&d)+0);

    pfun();

    return 0;
}

