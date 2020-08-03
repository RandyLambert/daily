#include <stdio.h>
char *fun(char p1[],char p2[])
{
    char *p3,*p4,*ans = NULL;
    p3 = p1;
    p4 = p2;
    while(*p3=='\0' || *p4=='\0'){
        if(*p3 < *p4){
            ans = p1;
        }
        else if(*p3 > *p4){
            ans = p2;
        }
        else if(*p3 == *p4){
            p3++;
            p4++;
        }
    }
    if(ans == NULL){
        if(*p3 == '\0'){
            ans = p2; 
        }
        else{
            ans = p1;
        }
    }
    return ans;
}
int main(){
    char *c = fun("211111\0","1111\0");
    printf("%s\n",c);
    
    return 0;
}

