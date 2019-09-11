#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char hh[100][1000],yy[100][1000];
int a1[1000],b1[1000];
char a[1000],b[1000];
int add[10000];
int app[10000];
void add1(char a[],char b[]){
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
    putchar('\n');
}
void app1(char a1[],char b1[]){
int flag = 0;
    int along = strlen(a1);
    int blong = strlen(b1);
        memset(add,0,sizeof(add));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    
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
    putchar('\n');
}
int main(){
    int cntt;
    scanf("%d",&cntt);
    for(int i = 0;i < cntt;i++){
        scanf("%s",hh[i]);
        scanf("%s",yy[i]);
    }
    for(int i = 0;i < cntt;i++){
        add1(hh[i],yy[i]);
    }
    for(int i = 0;i < cntt;i++){
        app1(hh[i],yy[i]);
    }
    return 0;
}
