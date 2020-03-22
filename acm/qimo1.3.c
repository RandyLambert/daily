#include <stdio.h>

int IsDigit(char x);

int main()
{
    char x;
    scanf(" %c", &x);
    if (IsDigit(x))
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}
int IsDigit(char x){
    if(x>= '0'&&x <= '9')
        return 1;
    else 
        return 0;
}
