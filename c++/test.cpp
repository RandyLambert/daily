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

class c{
public:
    /* int a; */
    void aa(){}
    void aaa(){}
};
int main(){
    //浮点数的存储
    printf("%lf\n",(3.14+1e20)-1e20);
    printf("%lf",3.14+(1e20-1e20));
    b x;
    x.hhh();
    x.c();
    cout<<x.a1<<endl;
    cout<<sizeof(c)<<endl; //当一个类没有一个数据成员定义的时候，这个类大小为1，有了之后是数据大小
    string y = string(10,'x');
    cout<<y<<endl;

    return 0;
}

//hhhhhhhhhhhh
//hhhhhhhhhhhh
//hhhhhhhhhhhh
//hhhhhhhhhhhh
//hhhhhhhhhhhh
//hhhhhhhhhhhh
//hhhhhhhhhhhh
//hhhhhhhhhhhh
