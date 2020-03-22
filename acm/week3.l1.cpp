#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100010
int v[maxn],pre[maxn];
int ok;
int find(int x)
{
    int r=x;
    while(r!=pre[r])
    {
        r=pre[r];
    }
    int i=x;
    int j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    if(r1!=r2)
    pre[r2]=r1;
    else ok=0;
}
int main()
{
   int a,b;
   while(~scanf("%d%d",&a,&b))
   {
       if(a==0&&b==0)
       {
            printf("Yes\n");
            continue;
       }
       for(int i=0;i<maxn;i++)
       {
           pre[i]=i;
           v[i]=0;
       }
       if(a==-1&&b==-1)
       break;
       join(a,b);
       ok=1;
       v[a]=1;
       v[b]=1;
       while(scanf("%d%d",&a,&b)&&a+b)
       {
           join(a,b);
           v[a]=1;
           v[b]=1;
       }
       if(ok==0)
       {
           printf("No\n");
           continue;
       }
       else
       {
           int cont=0;
           for(int i=0;i<maxn;i++)
           {
               if(v[i]&&pre[i]==i)
               cont++;
           }
           if(cont==1)
           printf("Yes\n");
           else
           printf("No\n");
       }
 
   }
    return 0;
}
 

