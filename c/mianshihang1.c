#include <stdio.h>
int main(int argc , char *argv[])
{
    puts((char*)(int const[]){0X6F796958,0X6E694C75,0X72477875,0X3270756F,0X313230,0X00000A});
    unsigned char a = 255;
    char ch = 128;
    a -= ch;
    printf("%d %d\n",ch,a);
    return 0;
}

