#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
struct myClass{
    int operator()(int x,int y){
        cout<<x<<y<<endl;
        return x+x*y;
    }
}myClassObj;

class test
{
public:
    int mains(){return 1;}
    int mans(){return 1;}
    int mais(){return 1;}
    int ais(){return 1;}
    int mis(){return 1;}
    int b;
};
int main()
{
    int x = 100;
    vector<int> a(10,0);
    for(int i = 0;i < 10;i++)
        a[i] = i;
    myClass();
    cout<<"daaaassssssssssssssssssss"<<endl;
    myClassObj(1,2);

    cout<<accumulate(begin(a),end(a),x,myClass())<<endl;//匿名对象
    cout<<accumulate(begin(a),end(a),x,myClassObj)<<endl;//传进去一个可以当函数的类

    test a1;
    cout<<sizeof(a1)<<endl;
    cout<<typeid(a1).name()<<endl;

    return 0;
}

