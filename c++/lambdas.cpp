#include <iostream>
using namespace std;

auto i = []{
        cout<<"hello lambet"<<endl;

};
int main(){
    int id = 9;
    auto f = [id]()mutable{//这里相当于复制了id的值，和外面的值没关系
        cout<<"id"<<id<<endl;
        id++;
    };


    auto x = [&id](){//这里相当于是id的引用，和外面的值没关系
        cout<<"id"<<id<<endl;
        id++;
    };

    []{
        cout<<"hello lambet"<<endl;
    }();//括号直接调用，相当与一个临时对象，但是可以直接写代码，碎叶这个作用也不大
    /* []{ */
    /*     cout<<"hello lambet"<<endl; */
    /* }; 类型，类似一个函数，但是直接写就没用，可以直接把这个写到调用的里面*/
    i();//调用，这个常用
   
    /* []()mutable throw->retType{} */
    return 0;
}

