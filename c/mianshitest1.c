#include <stdio.h>
int i;
int main(int argc, char *argv[])
{
i--;
if((int)sizeof(i) < -1)
{
printf(">\n");
}
else
{
printf("<\n");
}
return 0;
}
