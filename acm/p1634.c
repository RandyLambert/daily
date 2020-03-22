#include<stdio.h>
int main(){
    int a,b,max = 1;
    scanf("%d%d",&a,&b);
    for(int i = 0;i < b;i++){
        max = max + max*a; 
    }
    printf("%d",max);
    return 0;
}
