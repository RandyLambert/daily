#include <iostream>
#include <memory>
#include <boost/any.hpp>
#include <any>
using namespace std;
class test
{
public:
    test(){cout<<"ddddd"<<endl;}
    ~test(){cout<<"ddddd"<<endl;}
};
int main()
{
    boost::any i = 42;
    const auto ptr = boost::any_cast<int>(&i);
    if (ptr)
    {
        std::cout << ptr << std::endl;
    }
    auto x = test();
    getchar();

    /* shared_ptr<boost::any> q(new boost::any(test())); */

 
    return 0;
}
