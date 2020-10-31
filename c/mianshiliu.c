#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
    printf("%d\n",printf("XiyouLinux\n"));
    printf("%d\n",printf("Xiyou\0Linux\n"));
    return 0;
}
