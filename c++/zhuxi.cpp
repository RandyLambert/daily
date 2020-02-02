#include <bits/stdc++.h>

//单例模式 -- 主线类
//一个类中只有唯一的一个实例对象
//私有化
//默认构造函数
//拷贝构造函数
//唯一的主席指针 编程只读状态
//对外提供公共借口
//static chairman * getinstance()
//测试
using namespace std;
//静态函数在编译阶段已经调用了
class Chairman{
public:
    //返回主席指针
    static Chairman * getInstance()
    {
        return singleMan;
    }
    /* Chairman(const Chairman& a) = delete; */
    /* Chairman(const Chairman& a); */

private:
    //将构造函数私有化，不可创建多个对象
    static Chairman * singleMan;
    Chairman(){cout<< "chairman 的默认构造看书调用\n";}
    Chairman(const Chairman& a){}
    //数据是共享的，而且只需要拿到一个主席对象的指针即可
    

};

Chairman * Chairman::singleMan = new Chairman;


void test01()
{
    /* Chairman c1; */
    /* Chairman c2; */
    /* Chairman *c3 = new Chairman; */
    /* Chairman * c1 = Chairman::singleMan; */
    /* Chairman * c2 = Chairman::singleMan; */

    Chairman * c1 = Chairman::getInstance();
    Chairman * c2 = Chairman::getInstance();

    /* Chairman *c3 = new Chairman(*c1); */
    
    if(c1 == c2)
        cout<<"c1 == c2"<<endl;
    else
        cout<<"c1 != c2"<<endl;
}
int main(){

    test01();
    cout<<"main 函数调用"<<endl;

    /* Chairman::singleMan = NULL; */
    return 0;
}
