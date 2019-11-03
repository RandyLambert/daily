#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
int a = 1;
printf("%d\n", *(char *)&a);
}
