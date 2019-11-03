#include <stdio.h>
int main(){
    
    int number;
unsigned mask;
mask = 1u << 31;
scanf("%d", &number);
while(mask)
{
printf("%d", (number & mask) ? 1 : 0);
mask >>= 1;
}
    return 0;
}
