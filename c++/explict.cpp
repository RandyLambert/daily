#include <iostream>
using namespace std;
class test
{
public:
    explicit test(int x,int y,string z):x_(x),y_(y),z_(z){} //禁止隐式转换
private:
    int x_;
    int y_;
    string z_;
};
int main(){
    double x = 10;
    double y = 10;
    const char *z = "dasdasdasdas"; 

    test(x,y,z);


    return 0;
}

