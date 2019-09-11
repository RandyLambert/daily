#include <stdio.h>
#include<string.h>
int a[101];
int n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                a[i] = a[i];
            }
            else{
                if(a[j] == 0){
                    a[j] = 1;
                }
                else{
                    a[j] = 0;
                }
            }
        }
        for(int k = 0;k < n;k++){
            printf("%d",a[k]);
        }
        putchar('\n');
    }
}  
