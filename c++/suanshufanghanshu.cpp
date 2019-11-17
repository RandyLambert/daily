#include <bits/stdc++.h>
using namespace std;
//内建函数对象 算数仿函数
//
//negate 一元仿函数 取反仿函数

void test01(){
    negate <int>n;

    cout<<n(31212)<<endl;
    //取反仿函数
    //
    plus<int>p;

    cout<<p(10,20)<<endl;
}
int main(){
    test01();

    return 0;
}
