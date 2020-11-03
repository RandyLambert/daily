//4 优化选择排序 
#include<stdio.h>
#include<string.h>
int main(void)
{
    char Char[100];
    int key;
    char t;
    fgets(Char,100,stdin);

    for(int i=0;i<strlen(Char)-1;i++){
        key=i;
        for(int j=i+1;j<strlen(Char);j++){
            if(Char[key]>Char[j]){
                key=j;
            }
        } 
        t=Char[key];
        Char[key]=Char[i];
        Char[i]=t;
    }

    puts(Char);
    return 0;
}

