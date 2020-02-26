#include <iostream>
#include <any>
int main()
{
    std::any i = 42;
    const auto ptr = std::any_cast<int>(&i);
    if (ptr)
    {
        std::cout << ptr << std::endl;
    }
 
    return 0;
}
