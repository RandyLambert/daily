#include <stdio.h>
int main()
{

    int i,j;char s[100]="abklcdcckk",c;
    c = 'a';
    printf("%s\n",s);
    for(i = 0;s[i]!='\0';i++)
        if(s[i] == c)
            for(j=i;s[j]!='\0';j++)
                s[j]=s[j]+1;
        else i++;
    printf("%s\n",s);
    return 0;
}

