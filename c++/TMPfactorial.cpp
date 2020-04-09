#include <iostream>
template<unsigned n> //一般情况下Factorial<n>的值是n乘以Factorial<n-1>的值
struct Factorial{
    enum{value = n* Factorial<n-1>::value};
};

template<>
struct Factorial<0>{//特殊情况下
    enum{value = 1};
};
int main()
{
    std::cout<<Factorial<20>::value<<std::endl;
    return 0;
}

