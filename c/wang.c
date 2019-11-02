#include <stdio.h>
int main(){
    int i,j,x;
    printf("please input x= \n");
    scanf("%d",&x);
    for(i = 1;i <= x;i++){
        for(j = 1;j<=2*x-1;j++){
            if(x==1)
                printf("*");
            if((j==x-i+1) || (j==x+i-1))
                printf("*");
            else
                printf(" ");
        }
        putchar('\n');
    }
    
    return 0;
}
