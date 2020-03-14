#include <iostream>
#include <functional>
using namespace std;
void test1()
{
    cout<<"test1"<<endl;
}

void test2(int x)
{
    cout<<"test1"<<" "<< x <<endl;
}

class A
{
    typedef function<void ()> testFunc;
public:
    A():aFunc_(bind(&A::defaultRun,this)){}

    void setFunc(testFunc cb)
    {
        aFunc_ = std::move(cb);
    }

    void run()
    {
        aFunc_();
    }

private:
    void defaultRun()
    {
        cout<<"defaultRun"<<endl;
    }

    testFunc aFunc_;
};

class B
{
    typedef function<void ()> testFunc;
public:
    B()
    {
        a_.setFunc(bind(&B::bFunc,this));
        /* a_.setFunc(test1); */
        /* a_.setFunc(bind(test2,1)); */
    }

    void run()
    {
        a_.run();
    }

    B(A *ptra):ptra_(ptra)
    {
        /* ptra_->setFunc(bind(&B::bFunc,this)); */
        /* ptra_->setFunc(test1); */
        ptra_->setFunc(bind(test2,1));
    }
    void bFunc()
    {
        cout<<"bFunc"<<endl;
    }

private:
    A a_;
    A *ptra_;
};

int main(){
    A a;
    B b1;
    b1.run();
    B b2(&a);
    a.run();


    return 0;
}

