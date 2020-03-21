#include <stdio.h>
void my_init(void)
{
    printf("hello ");
}

typedef void (*ctor_t)(void);
//.ctors段里添加一个函数指针
ctor_t __attribute__((section (".ctors"))) my_init_p = &my_init;
int main()
{
    printf("world!\n");
    return 0;
}

