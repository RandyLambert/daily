#include <stdio.h>
#include <stdlib.h>

union test{
    char b;
    int a;
}x;
int main(){
    x.b = 'c';
    x.a = 1000;  
    printf("%c\n",x.b);
    
    return 0;
}

