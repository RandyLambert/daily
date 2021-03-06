#include <stdlib.h>
// https://www.ibm.com/developerworks/cn/linux/l-cn-valgrind/index.html
void func()
{
    int *p = (int*)malloc(10*sizeof(int));
    p[10] = 0;
}

int main()
{
    func();
    return 0;
}
