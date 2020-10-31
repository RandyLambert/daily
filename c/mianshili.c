#include <stdio.h>
int main(int argc,char* argv[])
{                              
    int array[2][2] = {{1,2},{3,4}};
    int* ptr;                             
    ptr = array[0];
    printf("%d\n",ptr[1]);
    return 0;             
}   
