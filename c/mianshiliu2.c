#include<stdio.h>
int main()
{

    char ch[17]="Xiyou_Linux_Group";
    char *str="Xiyou_Linux_Group";
    printf("%s\n%s\n",ch,str);
    *ch='x';
    printf("Hello");
    *str='x';
    printf("World");
    return 0;

}
