#include <iostream>
#include <stdexcept>
using namespace std;
class person{
public:
    person(string name,int age){
        this->age_ = age;
        if(age > 200){
            throw out_of_range("年龄越界了");
        }
    }
    string m_name_;
    int age_;
};

void test01(){
    try{
        person a = person("das",1000);

    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    
}
int main(){
    test01();

    return 0;
}

