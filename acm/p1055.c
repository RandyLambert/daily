#include<string.h>
#include<stdio.h>
char a[14];
int c = 0;
int n = 0;
int main(){
    scanf("%s",a);
    int b = strlen(a);
    for(int i = 0;i < b-1;i++){
        if(i == 1||i == 5||i == 11);
        else{
            c++;
          n = n + (a[i]-'0')*c;
        }
    }
    if(a[12]-'0' == n%11 ){
        printf("Right");
    }
    else if(n%11 == 10){
        if(a[12] == 'X'){
            printf("Right");
        }
            else{
            a[12] = n%11 + '0';
            for(int i = 0;i < b; i++){
                printf("%c",a[i]);
            }

        }
    }
    else{
        if(n%11 != 10){
            a[12] = n%11 + '0';
            for(int i = 0;i < b; i++){
                printf("%c",a[i]);
            }
        }
        else{
            a[12] = 'X';
            for(int i = 0;i < b; i++){
                printf("%c",a[i]);
            }
        }
    }

    return 0;
}  
