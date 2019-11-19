#include <bits/stdc++.h>
using namespace std;

//常用的拷贝和替换算法 copy
//常用的拷贝替换算法 replace
//常用替换算法replace_if
//常用替换算法swap
template <class T,class T2 = int>
class myprint
{
public:
    void operator()(T &a){
        cout<<a<<endl;
    }
};

template <class T = double,class T2 = int>
class myreplace{
public:
    bool operator()(T &a){
        return a >= 30;
    }
};
void test01(){
    vector<int>v1;
    for(int i  = 0;i < 10;i++)
    {
        v1.push_back(i);
    }

    vector<int>v2;

    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    for_each(v2.begin(),v2.end(),myprint<int>());
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(123);
    v1.push_back(1);
    v1.push_back(3123);
    v1.push_back(10);

    //把所有的10变成2000
    replace(v1.begin(),v1.end(),10,2000);
    for_each(v1.begin(),v1.end(),myprint<int>());

    replace_if(v1.begin(),v1.end(),myreplace<int,int>(),3000);
    for_each(v1.begin(),v1.end(),myprint<int>());

    swap(*(v1.begin()+1),*(v1.end()-2));
    for_each(v1.begin(),v1.end(),myprint<int>());
}
int main(){
    test01();

    return 0;
}
