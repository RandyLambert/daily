#include <iostream>
#include <set>
using namespace std;
class Message
{
public:
    ~Message()
    {
        cout << this << endl;
        messagesPtr_->erase(this);
    }
    set<Message *>* messagesPtr_;
};

class Person
{
public:
    set<Message *> messages_;
};

int main()
{
    Person test;
    Message *a;
    a = new Message();
    cout<<a<<endl;
    test.messages_.insert(a);
    a->messagesPtr_ = &test.messages_;
    delete a;

    return 0;
}

