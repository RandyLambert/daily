#include <iostream>
/* struct Foo {} */
int main(){
    long double ld = 3.1415926;
    /* int a{ld},b = {ld};//错误未执行，因为存在丢失信息的风险 */
    int c(ld),d = ld;//成功执行但是丢失信息

    return 0;
}

