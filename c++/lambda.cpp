#include <bits/stdc++.h>
using namespace std;
void fcn3()
{
    size_t v1 = 42;//局部变量
    //f可以改变它所捕获变量的值
    auto f = [v1]() mutable {return v1++;};
    int x= f();
    cout<<x<<endl;
}

void fcn4()
{
//当返会值不确定的时候，需要显示指定返回值类型
    vector<int>a1 = {1,2,3,4,5,6,7,8,9,0};
    vector<int>a2(10);
    transform(a1.begin(),a1.end(),a2.begin(),[](int i)
              {
                    if(i>0)
                        return -i;
                    else
                        return i;
              });

    for_each(a2.begin(),a2.end(),[](int i){cout<<i<<" ";});
}
int main()
{
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
    std::for_each(begin(some_list1), end(some_list1), [&, value](int x)
                  {
                  total += x * value;
                  });


    fcn4();
    return 0;
}
