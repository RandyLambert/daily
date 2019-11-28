#include <bits/stdc++.h>
using namespace std;
int main(){
    std::vector<int> some_list;
    int total = 0;
    for (int i = 0; i < 5; ++i)
        some_list.push_back(i);
    std::for_each(begin(some_list), end(some_list), [&total](int x)
                  {
                  total += x;
                  });
    //此例计算 list 中所有元素的总和。变量 total 被存为 Lambda 函数闭包的一部分。因为它是栈变量（局部变量）total 引
    //用，所以可以改变它的值。

    std::vector<int> some_list1;
    int total1 = 0;
    int value = 5;
    for (int i = 0; i < 5; ++i)
        some_list1.push_back(i);
    std::for_each(begin(some_list1), end(some_list1), [&, value, this](int x)
                  {
                  total += x * value * this->some_func();
                  });
    return 0;
}
