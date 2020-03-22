#include  <stdio.h>
void fun (char  *s, char  *t);
int main()
{  char   s[100], t[100];
  scanf("%s", s);
  fun(s, t);
  printf("The result is: %s\n", t);
  return 0;
}
void fun(char *s,char *t){
    int i = 0;
    while(s[i]!='\0'){
        t[i] = s[i];
        i++;
    }
    int x = i;
    i=i-1;
    while(i){
        t[x] = s[i];
        x++;
        i--;
    }
    t[x] = s[0];
    t[x+1] = '\0';
}
