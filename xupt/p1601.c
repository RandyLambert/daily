#include<stdio.h>
#include<string.h>
int a1[1000],b1[1000];
char a[1000],b[1000];
int add[10000];
int main(){
    scanf("%s",a);
    scanf("%s",b);
    int len1 = strlen(a);
    int len2 = strlen(b);
    if(a[0] != '0'&&b[0] != '0'){
        int max;
        if(len1>len2){
            max = len1+1;
        }
        else{
            max = len2+1;
        }
        memset(add,0,sizeof(add));
        memset(a1,0,sizeof(a1));
        memset(b1,0,sizeof(b1));
        for(int i = 0,j = len1-1;i < len1;i++,j--){
            a1[i] = a[j]-'0';
        }
        for(int i = 0,j = len2-1;i < len2;i++,j--){
            b1[i] = b[j]-'0';
        }
        for(int i = 0;i < max;i++){
                add[i] = a1[i] + b1[i];
        }

        for(int i = 0;i < max;i++){
            if(add[i]>=10){
               add[i+1]=add[i+1] + 1;
                add[i]=add[i]%10;
            }
        }
        while(add[max]==0){
            max--;
        }

        for(int i = max;i>=0;i--){
            printf("%d",add[i]);
        }
    }
    else{
        printf("%d",0);
    }
    return 0;
}
