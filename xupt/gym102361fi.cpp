#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 998244353;//取模
const int maxn = 3e5+10;//点的数量
const int maxm = 10e5+10;//边的数量,注意双向边要弄两倍的
struct edge
{
    int to,pre;
}edges[maxm];//邻接表
int head[maxn],dfn[maxn],dfs_clock,tot;
LL num;//BCC数量 
int Stack[maxn],Top;//模拟栈 
vector<int>bcc[maxn];//缩点之后的图
int bccnum[maxn];//存每个合点中包含点的数量
inline int Min(int a,int b){
    if(a>b)return b;
    else return a;
}//注意min是自己写的
/* inline LL qpow(LL x) { */
/*     LL res = 1, temp = 2; */
/*     while (x) { */
/*         if (x & 1) { */
/*             res = (res * temp) % mod; */
/*         } */
/*         temp = (temp * temp) % mod; */
/*         x >>= 1; */
/*     } */
/*     return res % mod; */
/* } */
int tarjan(int u,int fa)
{
    int lowu=dfn[u]=++dfs_clock;
    for(int i=head[u];i;i=edges[i].pre)
        if(!dfn[edges[i].to])
        {
            Stack[++Top]=edges[i].to;//搜索到的点入栈 
            int lowv=tarjan(edges[i].to,u);
            lowu=Min(lowu,lowv);
            if(lowv>=dfn[u])//是割点或根 
            {
                num++;
                while(Stack[Top]!=edges[i].to){
                    /* Top--; */
                    bcc[num].push_back(Stack[Top--]);//图
                    bccnum[num]++;//点的加法
                }
                /* Top--; */
                bccnum[num]++;
                bccnum[num]++;

                bcc[num].push_back(Stack[Top--]);//目标点出栈 
                bcc[num].push_back(u);//不要忘了将当前点存入bcc 
            }
        }
        else if(edges[i].to!=fa)
            lowu=Min(lowu,dfn[edges[i].to]);
    return lowu;
}
inline void add(int x,int y)//邻接表存边 
{
    edges[++tot].to=y;
    edges[tot].pre=head[x];
    head[x]=tot;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    for(int i=1;i<=n;i++)//遍历n个点tarjan 
        if(!dfn[i])
        {
            Stack[Top=1]=i;
            tarjan(i,i);
        }
    for(int i=1;i<=num;i++)
    {
        printf("BCC#%d: \n",i);
        printf("该缩点点的个数：%d\n",bccnum[i]);
        printf("是哪一个点：\n");
        for(size_t j=0;j<bcc[i].size();j++){
            printf("%d ",bcc[i][j]);
        }
        printf("\n");
    }
    return 0;
}
