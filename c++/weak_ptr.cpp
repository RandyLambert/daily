#include <iostream>
#include <memory>
using namespace std;

class x
{
public:
    x()
    {
        cout<<"xx"<<endl;
    }
    ~x()
    {
        cout<<"~xx"<<endl;
    }
};
int main(){
    weak_ptr<x> p;

    {
        shared_ptr<x> p2(new x);
        cout<<p2.use_count()<<endl;
        p = p2;
        cout<<p2.use_count()<<endl;

        shared_ptr<x> p3 = p.lock();
        if(!p3)
        {
            cout<<"object is destory"<<endl;
        }
        else
        {
            cout<<"object is not destory"<<endl;
        }
    }

    shared_ptr<x>p4 = p.lock();
    if(!p4)
    {
        cout<<"object is destory"<<endl;
    }
    else
    {
        cout<<"object is not destory"<<endl;
    }

    return 0;
}
