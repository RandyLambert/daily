#include <iostream>
#include <fstream>//文件操作的头文件
#include <cstring>
using namespace std;
//面向对象的文件操作
//操作文件三大类
//ofstream 写文件
//ifstream 读操作
//fstream 读写操作都可以

//操作步骤
//创建对象
//ofstream ofs;
//打开文件
//ofs.open("文件路径",打开方式);
//写数据
//ofs<<"写入的数据"
//关闭文件
//ofs.close();
//
//读文件
//创建流对象
//ifstream ifs;
//和上面差不多
//但是需要判断是否打开成功


//打开方式有
//前加ios::
//in 为读文件
//out 为写文件
//ate 初始位置文件尾
//app 追加的方式写文件
//trunc 如果文件存在先删除，在创建
//binary 二进制
//多个用位或


//二进制文件读写操作
//写文件可以写我们自定义的


class Person{
public:
    char m_Name[64];
    int m_Age;
    //二进制读写文件用c语言的char比较简单好用
    Person(char *a,int x){
        strcpy(m_Name,a);
        m_Age = x;
    }
    Person() = default;
};
void test01(){
    //1.包含头文件 fstream
    //2.创建流文件
    //
    ofstream ofs;

    //3.指定打开方式
    //往外面文件写用out用ofstream，往里面读用in用istream
    ofs.open("test.cpp",ios::out|ios::app);
    ofs<<"//hhhhhhhhhhhh"<<endl;
    ofs<<"//hhhhhhhhhhhh"<<endl;
    ofs.close();
}

void test02(){
    ifstream ifs;
    ifs.open("test.cpp",ios::in);

    //返回值bool类型判断是否打开成功
    if(!ifs.is_open()){
        cout<<"失败"<<endl;
    }
    else{
        cout<<"成功"<<endl;
    }

    //读数据
    char buf[2024] = {0};
    //第一种，一行一行数据读到buf中
    while(ifs>>buf){
        cout<<buf<<endl;
    }
    ifs.seekg(0,ios::beg);
    
    //第二种
    char buf1[2024] = {0};
    while(ifs.getline(buf1,sizeof(buf1))){//最多读多少
        cout<<buf1<<endl;
    }
    ifs.seekg(0,ios::beg);
    
    //第三种
    string buf2;
    //string类读取，使用getline读
    while(getline(ifs,buf2)){
        cout<<buf2<<endl;
    }
    ifs.seekg(0,ios::beg);


    //第四种
    //一个字符一个字符读，不推荐,开销大
    char c;
    while((c = ifs.get())!=EOF){
        cout<<c<<endl;
    }
    ifs.seekg(0,ios::beg);
    ifs.close();

}
using namespace std;
int main(){
    test01();
    test02();
    ofstream ofs;
    ofs.open("Person.txt",ios::out | ios::binary);
    Person p((char *)"dasssd",12);
    ofs.write((const char *)&p,sizeof(p));
    ofs.close();

    ifstream ifs;
    ifs.open("Person.txt",ios::in | ios::binary);
    if(ifs.is_open()){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    Person p1;
    ifs.read((char *)&p1,sizeof(p1));
    cout<<p1.m_Age<<" "<<p1.m_Name<<endl;
    ifs.close();

    return 0;
}
