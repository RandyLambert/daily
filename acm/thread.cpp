//
// Created by randylambert on 2020/8/9.
//

#include <thread>
#include <any>
#include <tuple>
#include <functional>
#include <iostream>
#include <memory>
using namespace std;

//template <typename T, typename ...  Args>
//void call_thread(T&& func, Args&& ... args) {
//    // Do something
//    std::any a = std::forward<T>(func);
//    std::tuple<std::decay_t<Args>...>  b = std::make_tuple(std::forward<Args>(args)...);
////    std::thread t1(std::forward<T>(func), std::forward<Args>(args)...);
//    std::thread t1(a,b);
//    t1.
//
//    t1.join();
//}

//template<typename... Arg>
//void syszuxPrint(Arg&&... arg){
//    std::any a(std::forward<Arg>(arg)...);
//    //thread Thread = thread(std::forward<Arg>(arg)...);
//    thread Thread = thread();
//    Thread.join();
//}
thread_local int a = 10;

class Thread
{
    using func = function<void()>;
public:
    Thread(func fun):fun_(fun),thread_(nullptr){}
    void start(){
        thread_ = make_unique<thread>(thread(fun_));
    }
    ~Thread(){
        if(thread_->joinable())
            thread_->join();
    }
private:
    unique_ptr<thread> thread_;
    func fun_;
};
void func(int a,double b){
    cout<<a<<" "<<b;
}
int main(){
//    thread thr(func,1,2);
//    thr.join();
    Thread a(bind(&func,1,2));
    a.start();

//    auto tt = Thread([](int a=1,double b=10.1){
//        cout<<a<<" "<<b<<endl;
//    });
//
//    tt.start();

//    call_thread(func,1,33.2);
}
