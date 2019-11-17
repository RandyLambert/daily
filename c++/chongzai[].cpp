#include <bits/stdc++.h>
using namespace std;
//系统会默认给一个类四个函数，默认构造，拷贝构造，析构，operator=
//重载=时记得返回值
class myArry{
public:
    int len;
    int *pAddress;
    //如果函数返回值想作为函数的左值，只能使用引用,c++特性
    int& operator[](const int a){
        return this->pAddress[a];
    }
    //解决a[x] = 1000这种情况
};
int main(){

    return 0;
}
