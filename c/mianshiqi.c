//4 优化选择排序 
#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[100];
    int key;
    char t;
    fgets(str,100,stdin);

    for(int i=0;i<strlen(str)-1;i++){
        key=i;
        for(int j=i+1;j<strlen(str);j++){
            if(str[key]>str[j]){
                key=j;
            }
        } 
        t=str[key];
        str[key]=str[i];
        str[i]=t;
    }

    puts(str);
    return 0;
}

