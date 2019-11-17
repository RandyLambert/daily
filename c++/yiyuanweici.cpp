#include <bits/stdc++.h>
using namespace std;
//返回bool类型的仿函数叫做谓词
//若果operator（）接受一个参数，那么叫做一元谓词
//如果operator（）接受两个参数，那么叫做二元谓词

class GreaterFive
{

public:
    bool operator()(int val){
        if(val > 5)
            return true;
    }
};


class Mycomp{
public:
    bool operator()(int a,int b){
        return a > b;
    }
};

bool Mycomp1(int a,int b){
    return a > b;
}
void test01(){
    vector<int>v;
    for(int i = 0;i < 10;i++){
        v.push_back(i);
    }
    //查找容器中，又没有大于5的数字
    auto it = find_if(v.begin(),v.end(),GreaterFive());


    if(it == v.end()){
        cout <<"没有大于5"<<endl;
    }
    else{
        cout<<"有"<<endl;
    }
    
    sort(v.begin(),v.end(),Mycomp());
    sort(v.begin(),v.end(),Mycomp1);

}
int main(){
    test01();

    return 0;
}

