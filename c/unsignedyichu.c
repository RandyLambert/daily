#include <stdio.h>
int main(int argc,char **argv)
{
    int a = 0;
    while(1){
        a++;
        if(a<0){
            break;
        }
    }
    printf("%d\n",a);
    
    return 0;
}
