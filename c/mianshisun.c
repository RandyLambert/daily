#include <stdio.h>
int main(int argc,char *argv[]){
    int a = 0, b = 2020;
    if(b++ || a++){
        printf("XiuLinuxGroup%d\n",b);
        printf("Waiting for y%du!\n",a);
    }
    if(a++ && b++){
        printf("XiuLinuxGroup%d\n",b);
        printf("Waiting for y%du!\n",a);
    }
    return 0;
}
