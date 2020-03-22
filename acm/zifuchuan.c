#include<stdio.h>
#include<string.h>
char str[1001],temp[101];
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    getchar();
    while(n--){
        memset(str,0,sizeof(str));
        gets(str);
        i = 1;
        k = 0;
        while(str[k]!='\0'){
            if(str[k]!=' '){
                temp[i++] = str[k];
                if(str[k+1]==' ')
                    temp[0] = ' ';
            }
            else{
                for(j = i - 1;j >= 0;j --)
                    printf("%c",temp[j]);
                    i = 1;
            }

            if(str[k+1]=='\0'){
                    for(j = i - 1;j > 0;j --)
                    printf("%c",temp[j]);
            }

            k++;
        }
      printf("\n");
    }
    return 0;
}
