#include <stdio.h>
const int ii = 10;
int i = 10;
int main(){
    int x = 10;
    int xx[x];
    printf("%p %p %p\n",&ii,&i,&x);
    return 0;
}

