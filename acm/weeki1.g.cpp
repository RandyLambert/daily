#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

bool flag;
char s[1005];

void dfs(int mod,int d,int n)
{
    if(d>100) return ;
    if(mod==0)
    {
        flag=true;
        s[d]=0;
        return ;
    }
    if(!flag)
    {
        s[d]='0';
        dfs((mod*10)%n,d+1,n);
    }
    if(!flag)
    {
        s[d]='1';
        dfs((mod*10+1)%n,d+1,n);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        memset(s,0,sizeof(s));
        s[0]='1';
        flag=false;
        dfs(1,1,n);
        printf("%s\n",s);
    }
    return 0;
}
