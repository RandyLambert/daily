#include <iostream>
#include <memory>
using namespace std;
class Foo
{
public:
    Foo(){cout<<"构造函数"<<endl;}
    ~Foo(){cout<<"析构函数"<<endl;}
};
shared_ptr<Foo> factory(Foo foo)
{
    return make_shared<Foo>(foo);
}

void use_factory(Foo foo)
{
    shared_ptr<Foo> p = factory(foo);
    //使用p
    //p离开作用域，他指向的内存会被自动释放掉
    shared_ptr<Foo> q = p;
}
int main()
{
    shared_ptr<int> q(new int(1));
    int* p;
    {
        p = q.get();
        cout<<q.use_count()<<endl;
        /* cout<<*p<<endl; */
        /* shared_ptr<int> q1(q); */
        /* cout<<q.use_count()<<endl; */
        /* cout<<q1.use_count()<<endl; */
        shared_ptr<int> q1(q.get()); //不能使用这种初始化方法，这会导致q指向的内存在离开范围后被q1释放掉，释放了之后在使用q，会出现问题，但是表面上看q的内存没有被释放
        cout<<q.use_count()<<endl;
        cout<<q1.use_count()<<endl;

        /* p = new int(100); */
        /* shared_ptr<int> q2(p); */
        /* cout<<q2.use_count()<<endl; */
        /* cout<<*q2<<endl; */
        /* cout<<*p<<endl; */
    }
    cout<<q.use_count()<<endl;
    cout<<*p<<endl;

    return 0;
}

