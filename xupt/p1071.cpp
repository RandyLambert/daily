#include<stdio.h>
#include<string.h>
char st1[105];
char st2[105];	
char st3[105];	
int book[27];
char m[27];
char y[27];
int main(void)
{
    scanf("%s%s%s",st1,st2,st3);
    int x = strlen(st1);
    for(int i=0;i<x;i++)
    {
        if(book[st2[i]-'A'+1]>=1)
        {
            if(m[st2[i]-'A'+1]!=st1[i]){printf("Failed");return 0;} 
            if(y[st1[i]-'A'+1]!=st2[i]){printf("Failed");return 0;} 
        }
        else
        {
            m[st2[i]-'A'+1]=st1[i];
            y[st1[i]-'A'+1]=st2[i];
            book[st2[i]-'A'+1]++;
        }
    }
    for(int i=1;i<=26;i++)
    {
        if(book[i]==0)
        {printf("Failed");return 0;} 
    }
    int  k=0;
    while(*st3)
    {
        printf("%c",y[*st3-'A'+1+k]);
        k++;
    }	
    return 0;
}

