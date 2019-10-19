#include <stdio.h>
int main(int argc,char *argv[]){
    
    /*const*/ char a[] = "XiyouLinux\0";
    char *b = "XiyouLinux\0";
    a[5] = '\0';
    /* b[5] = '\0'; */
    printf("%s\n",a);
    /* printf("%s\n",b); */
    return 0;
}

