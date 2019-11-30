#include <bits/stdc++.h>
using namespace std;
class Base{
public:
    Base(){
        cout<<"父类"<<endl;
    }
    /* virtual void ss(); */
    ~Base(){
        cout<<"父类析构"<<endl;
    }
};

class Zi:public Base{
public:
    Zi(){
        cout<<"子类"<<endl;
    }
    ~Zi(){
        cout<<"子类析构"<<endl;
    }
};

int main(){
    Zi a;
    /* Base b; */

    return 0;
}
