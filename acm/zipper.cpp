#include <bits/stdc++.h>
using namespace std;
char a[205],b[205],c[405];
int n,flag = 0,cll,con=1;
int f[205][205];
void dfs(int al,int bl,int cl)
{   
    if(f[al][bl]==1)
        return;
    if(cll == cl){
        flag=1;
        return;
    }
    if(a[al]!='\0'&&a[al] == c[cl]){
        dfs(al+1,bl,cl+1);
        /* printf("%d\n",cl); */
    }    
    if(b[bl]!='\0'&&b[bl] == c[cl]){
        dfs(al,bl+1,cl+1);
        /* printf("%d\n",cl); */
    }
    /* f[al][bl] = 1; */
}
int main(){
    scanf("%d",&n);
    for(int u = 0;u < n;u++)
    {   
        flag = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        scanf("%s%s%s",a,b,c);
        cll = strlen(c);
        dfs(0,0,0);

        /* for(int i = 0;i < 10;i++){ */
        /*     for(int j = 0;j < 10;j++){ */
        /*         printf("%d",f[i][j]); */
        /*     } */
        /*     putchar('\n'); */
        /* } */

        printf("Data set %d: %s\n",con++,flag?"yes":"no");
    }
    return 0;
}
