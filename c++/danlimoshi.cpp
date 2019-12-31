#include <iostream>
using namespace std;
class ChairMan
{
public:
    //返回主席的指针
    int xx;
    static ChairMan * getInstance()
    {
        return singleMan;
    }

private:
    //构造函数私有化，不可以创建多个对象
    ChairMan(){ xx = 100;cout<<"默认构造函数"<<endl; };
    ChairMan(const ChairMan &x){};
    //数据是共享的，而且只需拿到一个主席的对象的指针即可
//public:
    static ChairMan* singleMan;
};

ChairMan * ChairMan::singleMan = new ChairMan; //唯一的主席类指针
int main(){

    ChairMan *c1 = ChairMan::getInstance();
    cout<<c1->xx;


    return 0;
}
