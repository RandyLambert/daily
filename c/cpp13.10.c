#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
        int b;
        char d[80];
        int a = 10;
        char ch;
        FILE *fp;
        do{
                printf("qing shuru wenjian weizhiming");
                scanf("%s",d);
                printf("qing shuru wenjian weizhi");
                scanf("%d",&b);
                if((fp = fopen(d,"r")) != NULL){
                        printf("cuo;");
                        exit(1);
                }
                fseek(fp,b,SEEK_SET);
                int i = ftell(fp);
                while((ch = fgetc(fp))!='\n'){
                        putchar(ch);
                }
                fclose(fp);
        }while((scanf("%d",&a))>0);
}