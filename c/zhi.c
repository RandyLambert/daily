#include <stdio.h>
#include <stdlib.h>
void test01(int **a){
    *a = (int *)malloc(sizeof(int));
    **a = 100;
    printf("%d\n",**a);

}
int main(){
    int *a = (int *)malloc(sizeof(int));
    *a = 1000;
    printf("%d\n",*a);
    test01(&a);
    printf("%d\n",*a);
    return 0;
}
