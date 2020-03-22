#include<bits/stdc++.h>
 
using namespace std;
 
char a[205], b[205], c[405];
int f[205][205]= {0},flag=0;
 
void dfs(int i,int j,int k)
{
    /* if(f[i][j]==1) */
        /* return; */
    if(c[k]=='\0')
    {
        flag=1;
        return;
    }
    if(a[i]!='\0'&&c[k]==a[i])
        dfs( i+1, j, k+1 );
    if(b[j]!='\0'&&c[k]==b[j])
        dfs( i, j+1, k+1 );
    /* f[i][j]=1; */
}
int main()
{
    int n,con=1;
    cin>>n;
    while(n--)
    {
        flag=0;
        for(int i=0; i<205; i++)
            for(int j=0; j<205; j++)
              f[i][j]=0;
        scanf("%s %s %s",a,b,c);
        dfs(0,0,0);
        printf("Data set %d: %s\n",con++,flag?"yes":"no");
    }
    return 0;
}
