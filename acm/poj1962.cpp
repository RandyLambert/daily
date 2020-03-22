#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 200010;
int d[N],F[N];
void init(int x)
{
    for(int i =0;i<=x;i++)
    {
        F[i] = i;
        d[i]=0;
    }
}
int findset(int x)
{
    if(F[x]!=x)
    {
        int root = findset(F[x]);
        d[x] = d[x]+d[F[x]];
        return F[x] = root;
    }
    else return x;
}
int main()
{
    int T;
    char s[10];
    scanf("%d",&T);
    while(T--)
    {
        int n,u,v;
        scanf("%d",&n);
        init(n);
        while(scanf("%s",s) && s[0]!='O')
        {
            if(s[0] == 'E')
            {
                scanf("%d",&u);
                findset(u);
                printf("%d\n",d[u]);
            }
            else
            {
                scanf("%d%d",&u,&v);
                F[u] = v;
                d[u] = abs(u-v)%1000;      
            }
        }
    }
    return 0;
}
