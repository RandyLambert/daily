#include <stdio.h>
int main(int argc,char *argv[])
{
	int a = 10;
	printf("%d\n",*((char *)&a));
    return 0;
}
