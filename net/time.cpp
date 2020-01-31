#include <iostream>
using namespace std;
int main(){
    /* static_assert(-1,"dsdas"); */
    static_assert(sizeof(void *) == 8, "64-bit code generation is not supported.");
    return 0;
}

