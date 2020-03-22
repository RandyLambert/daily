#include <stdio.h>
int main(){
    char a = 127;
    unsigned char b = 255;
    a++,b++;
    printf("%d %d\n",a,b);
    return 0;
}
