#include <stdio.h>
#include <string.h>
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
int main(){
    char a[25],b[25];
    scanf("%s%s",a,b);
    int lena = strlen(a);
    int lenb = strlen(b);
    int x = min(lena,lenb);
    char d = '=';
    int i;
    for(i = 0;i < x;i++){
        if(a[i]>b[i]){
            d = '>';
        }
        else if(a[i]<b[i]){
            d = '<';
        }
    }
    if(i==x){
        if(d == '='&&lena > lenb)
            d = '>';
        else if(d == '='&&lena < lenb)
            d = '<';
        else if(d == '='&&lena == lenb)
            d = '=';
    }
    /* strcmp(a,b); */
    printf("%c\n",d);
    printf("%d",strcmp(a,b));
    return 0;
}

