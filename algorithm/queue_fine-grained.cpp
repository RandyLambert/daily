#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
template<typename T>
class A {
    struct node {
        std::shared_ptr<T> val;
        std::unique_ptr<node> next;
    };
    std::unique_ptr<node> head;
    node* tail;
    std::mutex hm; // head mutex
    std::mutex tm; // tail mutex
    std::condition_variable cv;

    node* get_tail()
    {
        std::lock_guard<std::mutex> l(tm);
        return tail;
    }

    std::unique_ptr<node> pop_head()
    {
        std::unique_ptr<node> oldHead = std::move(head);
        head = std::move(oldHead->next);
        return oldHead;
    }

    std::unique_lock<std::mutex> wait_for_data()
    {
        std::unique_lock<std::mutex> l(hm);
        cv.wait(l, [&] { return head.get() != get_tail(); });
        return std::move(l);
    }

    std::unique_ptr<node> wait_pop_head()
    {
        std::unique_lock<std::mutex> l(wait_for_data());
        return pop_head();
    }

    std::unique_ptr<node> wait_pop_head(T& x)
    {
        std::unique_lock<std::mutex> l(wait_for_data());
        x = std::move(*head->val); // 即*(head->val)，->优先级高于*
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head()
    {
        std::lock_guard<std::mutex> l(hm);
        if (head.get() == get_tail()) return std::unique_ptr<node>();
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head(T& x)
    {
        std::lock_guard<std::mutex> l(hm);
        if (head.get() == get_tail()) return std::unique_ptr<node>();
        x = std::move(*head->val);
        return pop_head();
    }
public:
    A() : head(new node), tail(head.get()) {}
    A(const A&) = delete;
    A& operator=(const A&) = delete;
    void push(T x)
    {
        std::shared_ptr<T> newVal(std::make_shared<T>(std::move(x)));
        std::unique_ptr<node> p(new node);
        {
            std::lock_guard<std::mutex> l(tm);
            tail->val = newVal;
            node* const newTail = p.get();
            tail->next = std::move(p);
            tail = newTail;
        }
        cv.notify_one();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_ptr<node> oldHead = wait_pop_head();
        return oldHead->val;
    }

    void wait_and_pop(T& x)
    {
        std::unique_ptr<node> oldHead = wait_pop_head(x);
    }

    std::shared_ptr<T> try_pop()
    {
        std::unique_ptr<node> oldHead = try_pop_head();
        return oldHead ? oldHead->val : std::shared_ptr<T>();
    }

    bool try_pop(T& x)
    {
        std::unique_ptr<node> oldHead = try_pop_head(x);
        return oldHead ? true : false;
    }

    bool empty()
    {
        std::lock_guard<std::mutex> l(hm);
        return head.get() == get_tail();
    }
};

int main()
{
    A<int> a;
    std::thread th([&a]{
                   sleep(10);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
                   });
    int c;
    bool x;
    a.wait_and_pop(c);
    cout<<c<<endl;
    x = a.try_pop(c);
    cout<<c<<endl;
    x = a.try_pop(c);
    cout<<c<<endl;
    x = a.try_pop(c);
    cout<<c<<endl;
    x = a.try_pop(c);
    cout<<c<<endl;
    x = a.try_pop(c);
    cout << a.try_pop(c) <<endl;
    cout<<c<<endl;
    th.join();
    return 0;
}
