#include <bits/stdc++.h>
using namespace std;

void My_print(int x){
    cout<<x<<endl;
}
void test01()
{
    vector<int>v1;
    vector<int>v2;
    for(int i = 0;i < 10;i++){
        v1.push_back(i);
        v2.push_back(i+4);
    }

    vector<int>v3(20,0);

    //目标容器需要提前开辟容器
    //最特殊情况 大容器包含小容器 开辟空间 去较小的容器size即可
    //
    v3.resize(min(v1.size(),v2.size()));
    //y是结束迭代器
    //求两个vector的公共集合，并集
    auto y = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    /* for(auto &x : v3){ */
    /*     cout<<x<<endl; */
    /* } */
    for_each(v3.begin(),y,My_print);
    //z是结束迭代器
    //求两个vector的交集
    v3.clear();
    v3.resize(v1.size()+v2.size());
    //v3取极大值
    
    auto z = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),z,My_print);

    //求两个集合的差集
    //分为两种，一种是v1和v2的差集，另一种是v2和v1的差集
    //v1和v2是v1中不是交集部分，v2和v1是v2不是交集的部分；
    
    v3.clear();
    v2.resize(min(v1.size(),v2.size()));
    
    z = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),z,My_print);
    v3.clear();
    v2.resize(min(v1.size(),v2.size()));
    
    z = set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),v3.begin());
    for_each(v3.begin(),z,My_print);
}
int main(){
    test01();

    return 0;
}
