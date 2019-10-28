#include <stdio.h>
int main(int argc,char *argv[])
{
    /*const*/ char a[] = "XiyouLinux";
    char *b = "XiyouLinux";
    a[5] = '\0';
    /* b[5] = '\0'; */
    printf("%s\n",a);
    /* printf("%s\n",b); */
    return 0;
}
