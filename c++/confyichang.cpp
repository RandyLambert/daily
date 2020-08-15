#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
using namespace std;
template <class T>
T getHeader(const string &key, const T &def = T()) //根据头域返回值
{
    try
    {
        return boost::lexical_cast<T>(key);
    }
    catch (...)
    {
        return def;
    }
}
int main()
{
//    LOG_DEBUG << confData["log"]("level");
//    LOG_INFO << confData["log"]("level");
//    LOG_WARN << confData["log"]("level");
//    LOG_ERROR << confData["log"]("level");
//
//    LOG_INFO << confData("worker_processes");
//    LOG_INFO << confData["log"]("roll_size");
//    LOG_INFO << confData["log"]("flush_second");
//
//    sleep(1000000);

    int a = getHeader<int>("ddda");
    cout << a<<endl;
}
