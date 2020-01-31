#include <iostream>
void foo(int x){

}
class B{  
public:
    virtual void foo(){

    }
};
class D: public B{
public:
    void foo(int x){

    }
};
int main(){

    std::is_same<int,double>();//判断int和double是不是同一种类型
    int n;
    double d = 1.23;
    n = d;
    B* pb;
    D* pq = nullptr;
    pb = pq;
    //down_cast 向下转型
    //implicit_cast 饮食转型

    return 0;
};

