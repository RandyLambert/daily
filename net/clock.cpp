#include <chrono>
#include <future>
#include <iostream>
#include <iomanip>
using namespace std; 
int f()
{
    return 42;
}
// 使用绝对的时间点来设置等待时间
std::condition_variable cv;
bool done;
std::mutex m;
bool wait_loop()
{
    const auto timeout = std::chrono::steady_clock::now() + std::chrono::milliseconds(500);
    std::unique_lock<std::mutex> l(m);
    while (!done)
    {
        if (cv.wait_until(l, timeout) == std::cv_status::timeout) break;
    }
    return done;
}
int main()
{
    // 当前时间
    std::chrono::system_clock::now();
    // 表示时间的类型
    //std::chrono::time_point xx = std::chrono::system_clock::now();
    // 时钟节拍(一个嘀嗒的周期) : 一般一秒有 25 个节拍,一个周期为 std::ratio
    // 通过时钟节拍确定时钟是否稳定(steady,匀速)
    std::cout << std::chrono::steady_clock::is_steady << std::endl; // 稳定时钟,代表系统时钟的真实时间
    std::cout << std::chrono::system_clock::is_steady << std::endl; // 一般因为时钟可调节而不稳定,即使是为了考虑本地时钟偏差的自动调节
    std::cout << std::chrono::high_resolution_clock::is_steady << std::endl; // 最小节拍最高精度的时钟

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now); // 转为整数
    std::cout << std::put_time(std::localtime(&now_c), "%F %T") <<endl; // %F即%Y-%m-%d，%T即%H:%M:%S
    
    // 标准库提供了表示时间间隔类型的 std::chrono::duration
    // 比如将表示秒的类型定义为
    std::chrono::duration<int> second; // 即std::chrono::seconds
    // 表示分的类型可以定义为
    std::chrono::duration<int,std::ratio<60>> min; // 即std::chrono::minutes
    // 表示毫秒的类型可定义为
    std::chrono::duration<int,std::ratio<1,1000>> millisecond; // 即std::chrono::milliseconds

    //using namespace std::chrono_literals;
    auto x = 45min; // 等价于std::chrono::minutes(45)
    std::cout << x.count() << std::endl; // 45
    auto y = std::chrono::duration_cast<std::chrono::seconds>(x);
    std::cout << y.count() << std::endl; // 2700
    auto z = std::chrono::duration_cast<std::chrono::hours>(x);
    std::cout << z.count() << std::endl; // 0（转换会截断）
    auto b = std::chrono::duration_cast<std::chrono::milliseconds>(x);
    std::cout << b.count() << std::endl; // 0（转换会截断）
    
    //标准库通过字面值运算符模板实现此后缀功能
    //constexpr std::chrono::minutes operator ""min(unsigned long long m)
    //{
    //    return std::chrono::minutes(m);
    //}
    //
    // duration 支持四则运算
    //using namespace std::chrono_literals;
    auto xx = 1h;
    auto yy = 15min;
    auto zz= xx - 2 * yy;
    std::cout << zz.count() << std::endl; // 30

    // 使用 duration 即可设置等待时间
    
    auto ft = std::async(f);
    if(ft.wait_for(1s) == std::future_status::ready)
    {
        std::cout << ft.get() << std::endl;
    }

    // time_point是表示时间的类型，值为从某个时间点（比如unix时间戳：1970年1月1日0时0分）开始计时的时间长度
    // 第一个模板参数为开始时间点的时钟类型,第二个为时间单位
    // std::chrono::time_point<std::chrono::system_clock,std::chrono::seconds>
    
    // time_point 可以加减dutation
    auto xxx = std::chrono::high_resolution_clock::now();
    auto yyy = xxx + 1s;
    std::cout << std::chrono::durtion_cast<std::chrono::milliseconds>(yyy - xxx).count() << std::endl;
    
    // 两个time_point也能相减
    auto start = std::chrono::high_resolution_clock::now();
    doSomething();
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    return 0;
}
