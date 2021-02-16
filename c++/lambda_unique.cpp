#include<iostream>
#include<memory>
#include<string>
int main()
{
    auto str = std::make_unique<std::string>("my string");
    auto lambda = [capturedStr = std::move(str)] {
        std::cout << *capturedStr.get() << std::endl;
    //    auto str2 = std::move(capturedStr);
    //    std::cout << *str2 << std::endl;
    };
    lambda();
    return 0;
}
