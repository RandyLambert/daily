#include<stdio.h>
#include <time.h>

inline void PrintString(char * str)
{
    printf("%s\n", str);
}

int main(void)
{
    PrintString("This is the first line info.");
    PrintString("This is the second line info.");

    return 0;
}

