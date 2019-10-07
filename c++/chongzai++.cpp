#include <bits/stdc++.h>
using namespace std;

class Myinter{
    friend ostream& operator<<(ostream &cout,Myinter &myint);
private:
    int m_Num;
public:

    Myinter()
    {
        this->m_Num = 0;
    }
    //重载前置++
    Myinter& operator++()
    {
        //先++,后返回
        m_Num++;
        return *this;
    }
    //temo不能返回引用，出函数会调用拷贝构造函数  
    Myinter operator++(int)
    {
        //先返回
        //后return
        //
        Myinter temp = *this;
        this->m_Num++;
        return temp;
    }
};

ostream & operator<<(ostream &cout,Myinter &myint){
    cout<<myint.m_Num;
    return cout;
}
int main(){

    Myinter a;
    cout<<++a<<endl;
    cout<<++(++a)<<endl;
    /* cout<< a++ <<endl; */
    cout<<a<<endl;
    //为避免连续++操作，所以返回的是指针

    
    return 0;
}

