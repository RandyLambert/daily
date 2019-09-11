 #include<cstdio>
using namespace std;
int n,m,k,f[33][33];
int main()
{
    scanf("%d%d",&n,&m);
    f[1][0]=1;k=f[1][0];
    for(int i=1;i<=m;i++)
    {
        f[1][i]=f[2][i-1]+f[n][i-1];
        f[n][i]=f[1][i-1]+f[n-1][i-1];
        for(int j=2;j<n;j++)
        f[j][i]=f[j-1][i-1]+f[j+1][i-1];
        if(f[1]==k)k=i,break;
    }
    printf("%d",f[1][m%k]);
}
