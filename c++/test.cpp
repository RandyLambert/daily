#include <bits/stdc++.h>
using namespace std;
class a /*final*/{
public:
    int a1 = 10;
    /* a(){ */
    /*     a1 = 10; */
    /* } */
    a(int x){}
    a()= default;
    virtual void c(){};
};
class b : public/*private*/ a{
/* protected: */
public:
    void hhh(){
        cout<<a1<<endl;
    }
    void yyyy(){
        cout<<"da"<<endl;
    }
};
int main(){

    printf("%lf\n",(3.14+1e20)-1e20);
    printf("%lf",3.14+(1e20-1e20));
    b x;
    x.hhh();
    x.c();
    cout<<x.a1<<endl;


    return 0;
}

