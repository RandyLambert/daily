#include <iostream>
using namespace std;
class Exception
{
public:
    virtual void printferror() = 0;
};

class outofrange:public Exception
{
public:
    virtual void printferror(){
        cout<<"outofrange"<<endl;
    }
};
class isnullpointer:public Exception
{
public:
    virtual void printferror(){
        cout<<"is_null_pointer"<<endl;
    }
};

void dowork()
{
    throw isnullpointer();
}

void test01(){
    try{
        dowork();
    }
    catch(Exception & e){
        e.printferror();
    }
}
int main(){
    test01();

    return 0;
}

