#include <thread>
#include <cassert>
#include <future>
#include <iostream>
using namespace std;

int f()
{
    return 1;
}
int main()
{
    int x = 10;
    std::future<int> ft = std::async([](int a,int b){return a*b;},std::ref(x),4);
    std::cout<<ft.get()<<std::endl;
    
    // 函数必须异步执行，即运行在不同的线程上
    auto ft1 = std::async(std::launch::async, f);
    // 函数只在返回的期值调用get或wait时运行
    auto ft22 = std::async(std::launch::deferred, f);
    // 不指定时的默认启动策略是对两者进行或运算的结果
    // auto ft3 = std::async(f)等价于
    auto ft3 = std::async(std::launch::async | std::launch::deferred, f);


    // 除了std::async，还可以用std::packaged_task让std::future与任务关联
    std::packaged_task<int()> pt(f);
    auto ft4 = pt.get_future();
    pt(); // 调用std::packaged_task对象，将std::future设为就绪
    std::cout << ft4.get() << endl;


    // std::promise可以显式设置值
    std::promise<int> ps;
    std::future<int> ftx = ps.get_future();
    ps.set_value(42); // set_value还会将状态设置为就绪
    std::cout << ftx.get(); // 42
    
    // 在线程间对状态发送信号
    /*
    void f(std::promise<void> ps)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ps.set_value();
    }

    int main()
    {
        std::promise<void> ps;
        std::future<void> ft = ps.get_future();
        std::thread t(f, std::move(ps));
        ft.wait(); // 阻塞直到set_value，相当于没有返回值的get
        t.join();
    }
    */

    // std::future调用get后就无法再次get，也就是说只能获取一次数据，此外还会导致所在线程与其他线程数据不同步。std::shared_future就可以解决此问题
    std::promise<int> ps2;
    std::future<int> ft2(ps2.get_future());
    assert(ft2.valid());
    std::shared_future<int> sf2(std::move(ft2));
    assert(!ft2.valid());
    assert(sf2.valid());

    // 直接构造
    std::promise<int> ps3;
    // std::future隐式转换为std::shared_future
    std::shared_future<int> sf3(ps3.get_future());

    // 用std::future::share可以直接生成std::shared_future，这样就可以直接用auto简化声明std::shared_future
    std::promise<int> ps4;
    auto sf4 = ps4.get_future().share();
    
    return 0;
}
