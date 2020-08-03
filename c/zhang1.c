#include <stdio.h>
#include <string.h>
void fun (char s[],int n)
{
    char a[80],*p;
    int i;


    p = s;
    for(i = 0;i < n;i++)
        a[i] = '*';
    printf("%s\n",a);
    int j = 0;
    do{
        a[j] = *p;
        j++;
        i++;
    }while(*p++);

    a[i] = 0;
    strcpy(s,a);

}
int main(){
    char a[80] = {"312321321412412431241"};
    fun(a,80);
    printf("%s",a);
    
    
    return 0;
}

