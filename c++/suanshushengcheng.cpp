#include <bits/stdc++.h>
using namespace std;

//常用的算数生成算法
//
template <class T>
void acc(T x){

}
void test01()
{
    vector<int>v;
    for(int i = 0;i <= 100;i++){
        v.push_back(i);
    }

    //参数3是一个起始点累加值
    //主要计算累加和
    int x=accumulate(v.begin(),v.end(),100);
    cout<<x<<endl;
    vector<int>z(10,1000);
    //10个数，每个数1000
    for(auto &a : z){
        cout<<a<<endl;
    }
    fill(z.begin(),z.end(),100);
    //给容器填满100
    for(auto &a : z){
        cout<<a<<endl;
    }
}


int main(){
    test01();

    return 0;
}
