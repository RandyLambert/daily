#include <bits/stdc++.h>
using namespace std;
//最常用的遍历算法 for_each
//普通函数
template <class T>
void print01(T  x){
    cout<<x<<endl;
}
//仿函数
template <class T>
class print02{
public:
    void operator()(T x){
        cout<<x<<endl;
    }
};

void test01(){

    vector<int>v;
    for(int i = 0;i < 10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print02<int>());
    for_each(v.begin(),v.end(),print01<int>);

}

//常用遍历算法transform
//
template <class T>
class Transform{
public:
    T operator()(T x){
        return x*10;
    }  
};

template <class T>
T Transform2(T x){
    return x*10;
}
void test02(){

    vector<int>v;

    for(int i = 0;i < 10;i++){
        v.push_back(i);
    }

    vector<int>v2;
    v2.resize(v.size());//目标容器需要提前开辟空间
    transform(v.begin(),v.end(),v2.begin(),Transform<int>());//需要遍历的元素开始，需要遍历的元素结尾，存储元素的开头
    transform(v.begin(),v.end(),v2.begin(),Transform2<int>);

    for_each(v2.begin(),v2.end(),print02<int>());
    for_each(v2.begin(),v2.end(),print01<int>);

}
int main(){
    test01();
    test02();

    return 0;
}
