#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int m,flag=0;
char s[15];
void dfs(int mod,int n,int wei)
{
    if(wei>100)
        return;
    if(mod==0){
        flag = 1;
        s[wei]=0;
        return;
    }
    if(flag==0)
    {
        s[wei] = '0';
        dfs((mod*10)%n,n,wei+1);
    }
    if(flag==0)
    {
        s[wei] = '1';
        dfs(((mod*10)+1)%n,n,wei+1);
    }

}
int main(){
    int n = 1;
    while(scanf("%d",&n)&&n!=0)
    {
        memset(s,0,sizeof(s));
        flag = 0;
        s[0] = '1';
        dfs(1,n,1);
        printf("%s\n",s);
    }
    

    return 0;
}
