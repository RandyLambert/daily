#include <bits/stdc++.h>
using namespace std;

//find查找 内置数据类型
//find_if查找if(啥啥啥)
//adjacent_find查找重复相邻的
//二分查找binary_search
//count统计算法    必须重载==
//count_if统计如果    必须重载==
class My_class{
public:
    int x,y;
    My_class(int _x,int _y){
        x = _x,y = _y;
    }
    
    bool operator==(const My_class & a)const{
        if(a.x == x && a.y == y)
            return true;
        else
            return false;
    }

};
template <class T>
bool Great(T x){
    if(x.x > 5){
        return true;
    }
}

template <class T>
class Count{
public:
    bool operator()(const T &y){
    
       return y.y > 10; 
    }
};
void test01(){

    vector<My_class> q;
    for(int i = 0;i < 10;i++){
        q.push_back(My_class(i,i*10));
    }

    //当比较的是自定义类型，需要自己写比较函数
    auto x = find(q.begin(),q.end(),My_class(0,0));
    cout<<x->x<<" "<<x->y<<endl;
    auto y = find_if(q.begin(),q.end(),Great<My_class>);
    cout<<y->x<<" "<<y->y<<endl;

    vector<int>aa;
    aa.push_back(11);
    aa.push_back(1);
    aa.push_back(1);
    aa.push_back(111);
    aa.push_back(123);
    aa.push_back(1113);
    aa.push_back(1341);
    auto z = adjacent_find(aa.begin(),aa.end()); 
    cout<<*z<<endl;

    sort(aa.begin(),aa.end());
    //必须是有序的
    auto zz = binary_search(aa.begin(),aa.end(),111);
    if(zz == true){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    int num = count(q.begin(),q.end(),My_class(0,0));
    cout<<num<<endl;
    int num1 = count_if(q.begin(),q.end(),Count<My_class>());
    cout<<num1<<endl;
}
int main(){

    test01();

    return 0;
}
