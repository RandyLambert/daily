#include <iostream>
/* struct Foo {} */
struct Foo {
    int a;
    int b;
};
int main(){
    Foo a{};
    Foo b;
    std::cout <<a.a<<" "<<a.b<<std::endl;
    std::cout <<b.a<<" "<<b.b<<std::endl;
    long double ld = 3.1415926;
    /* int a{ld},b = {ld};//错误未执行，因为存在丢失信息的风险 */
    int c(ld),d = ld;//成功执行但是丢失信息

    return 0;
}

