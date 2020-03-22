#include <bits/stdc++.h>
using namespace std;
const int HASH = 10007;
const int MAXN = 2010;
struct HASHMAP
{
    int head[HASH],next[HASH],size;
    unsigned long long state[MAXN];
    int f[MAXN];
    void init()
    {
        size = 0;
        memset(head,-1,sizeof(head));
    }
    int insert(unsigned long long val,int _id)
    {
        int h = val%HASH;
        for(int i = head[h]; i != -1; i = next[i])
            if(val == state[i])
            {
                int tmp = f[i];
                f[i] = _id;
                return tmp;
            }
        f[size] = _id;
        state[size] = val;
        next[size] = head[h];
        head[h] = size++;
        return 0;
    }       
}H;

const int SEED = 13331;
unsigned long long P[MAXN];
unsigned long long S[MAXN];
char str1[MAXN];
int ans[MAXN][MAXN];

int main(){
    P[0] = 1;
    for(int i = 1; i < MAXN; i++)
        P[i] = P[i-1] * SEED;
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str1);
        int n = strlen(str1);
        S[0] = 0;
         for(int i = 1; i <= n; i++)
            S[i] = S[i-1]*SEED + str1[i-1];
        memset(ans,0,sizeof(ans));
        for(int L = 1; L <= n; L++)
        {
            H.init();
            for(int i = 1; i + L - 1 <= n; i++)
            {
                int l = H.insert(S[i+L-1] - S[i-1]*P[L],i);
                ans[i][i+L-1]++;
                ans[l][i+L-1]--;
            }
        }
        for(int i = n; i >= 0; i--)
            for(int j = i; j <= n; j++)
                ans[i][j] += ans[i+1][j] + ans[i][j-1] - ans[i+1][j-1];
        int m,u,v;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",ans[u][v]);
        }
    }
    return 0;
}

