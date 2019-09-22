#include <bits/stdc++.h>
using namespace std;
class B;

class A
{
public:
    /* weak_ptr<B> pb; */
    shared_ptr<B> pb;
    ~A()
    {
        cout<<"A delete\n";
    }
};

class B
{
public:
    shared_ptr<A> pa;
    ~B()
    {
        cout<<"B delete\n";
    }
};

int main(){

    /* shared_ptr<B> pb(new B()); */
    /* shared_ptr<A> pa(new A()); */
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    pb->pa = pa;
    pa->pb = pb;
    cout<<pb.use_count()<<endl;
    cout<<pa.use_count()<<endl;

    return 0;
}

