#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[] = "LinuxGroup";                               
    char *p = str;                                      
    char x[] = "LinuxGroup\t\106F\bamily";
    printf("%zu %zu %zu\n",sizeof(str),sizeof(p),strlen(x));
	return 0;
} 
