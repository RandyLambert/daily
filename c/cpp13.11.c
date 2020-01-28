#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,int **argv){
        FILE *fp;
        char a[256];
        if(argc != 2){
                printf("fa");
                exit(1);
        }
        if((fp = fopen(argv[1],"r"))==NULL){
                printf("fa");
                exit(1);      
        }
        while(fgets(a,256,a[1]) != NULL){
                if (strstr(a,argv[1])!=NULL) {
                        fputs(a,stdout);
                }
                
        }
        return 0;       
}