#ifndef TEMPLATE_TOOL_HPP_
#define TEMPLATE_TOOL_HPP_
#include <iostream>
#include <cstring>
#include <cstdlib>

template <typename T>
bool cmp(T a, T b)
{ //排序函数
    return a < b;
}

//交换
template <typename T>
T mySwap(T &a, T &b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

//快拍
template <typename T>
void mySort(T &arr, size_t l, size_t r)
{

    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];

    while (i < j)
    {
        do
            j--;
        while (arr[j] > x);
        do
            i++;
        while (arr[i] < x);
        if (i < j)
            mySwap<T>(arr[i], arr[j]);
        else
            mySort<T>(arr, l, j), mySort(arr, j + 1, r);
    }
}

#endif
