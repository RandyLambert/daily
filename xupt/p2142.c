#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[110005],b[110005],add[110006];
char a1[110005],b1[110005];
int main(){
    int flag = 0;
    scanf("%s%s",a1,b1);
    int along = strlen(a1);
    int blong = strlen(b1);
    
    for(int i = 0,k = along-1;i < along;i++,k--){
        a[i] = a1[k] - '0';
    }
    for(int i = 0,k = blong-1;i < blong;i++,k--){
        b[i] = b1[k] - '0';
    }
    if(a[0] == 0&&b[0] == 0 && along == 1 && blong == 1){
        printf("%d",0);
        exit(0);
    }

    if(along > blong){
        flag=1;
    }
    else if(along == blong){
        flag = strcmp(a1,b1);
    }
    else{
        flag = -1;
    }

    if(flag >= 0){
        for(int i = 0;i < along;i++){
            add[i] = a[i] - b[i] + add[i];
            if(add[i] < 0){
                add[i] = 10 + add[i];
                add[i+1] = add[i+1]-1;
            }
        }

        int aa = along;
        while(add[aa] == 0){
            aa--;
        }
        if(aa<0) aa = 0;

        for(int i = aa;i >= 0 ;i--){
            printf("%d",add[i]);
        }
    }
    else if(flag < 0){
        for(int i = 0;i < blong;i++){
            add[i] = b[i] - a[i] + add[i];
            if(add[i] < 0){
                add[i] = 10 + add[i];
                add[i+1] = add[i+1]-1;
            }
        }
        int aa = blong;
        while(add[aa] == 0){
            aa--;
        }
        printf("-");
        for(int i = aa;i >= 0 ;i--){
            printf("%d",add[i]);
        }
    }
    

    return 0;
}
