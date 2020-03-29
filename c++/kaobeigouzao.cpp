#include <iostream>
using namespace std;
class test
{
public:
    test(const test& a)
    { 
        cout<< "拷贝构造" <<endl;
        a_ = a.a_;
    }
    test() = default;
    /* test(const test& a) = delete; */
    test &operator=(const test& a)
    {
        cout<<"="<<endl;
        a_ = a.a_;
        return *this;
    }
    void setNum(int a)
    {
        a_ = a;
    }
    void print()
    {
        cout<<a_<<endl;
    }
private:
    int a_;
};
int main()
{
    test a;
    a.setNum(10);
    test b;
    b = a;
    test c = a;
    c.print();
    
    

    
    return 0;
}

