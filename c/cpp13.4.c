#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,int  *argv[]){
        FILE *fp1;
        char b[256];
        memset(b,0,256);
        for(int i = 1;i<argc;i++){
                if((fp1 = fopen(argv[i],"r"))==NULL){
                        printf("cuo l");
                }
                while(fgets(b,256,fp1)!=NULL){
                        fputs(b,stdout);
        }
        putchar('\n');
        }
        fclose(fp1);
}