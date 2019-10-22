#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <iostream>
#define repu(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#define N 10005            /// 题目中可能的最大点数
stack<int>sta;            /// 存储已遍历的结点
vector<int>gra[N];        /// 邻接表表示图
int dfn[N];        /// 深度优先搜索访问次序
int low[N];        /// 能追溯到的最早的次序
int InStack[N];  // 检查是否在栈中(2：在栈中，1：已访问，且不在栈中，0：不在)
vector<int> Component[N]; /// 获得强连通分量结果
int InComponent[N];          /// 记录每个点在第几号强连通分量里
int Index,ComponentNumber;/// 索引号，强连通分量个数
int n,m;          // 点数，边数
int chu[N];         //出度
int dianquan[N];   //点权
int dianquan2[N];
int dp[N];
int vis[N];
int ru[N];           //入度
int num[N]; //各个强连通分量包含点的个数,数组编号 1 ∼ scc
void init() //清空容器，数组
{

    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    memset(dianquan2, 0, sizeof(dianquan2));
    memset(dianquan ,0, sizeof(dianquan));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(chu, 0, sizeof(chu));
    memset(InStack, 0, sizeof(InStack));
    Index = ComponentNumber = 0;
    for (int i = 1; i <= n; ++ i)
    {
        gra[i].clear();
        Component[i].clear();
    }
    while(!sta.empty())
        sta.pop();
}
void tarjan(int u)
{
    InStack[u] = 2;
    low[u] = dfn[u] = ++ Index;
    sta.push(u);///寻找u所在的强连通分量
    for (size_t i = 0; i < gra[u].size(); ++ i)
    {
        int t = gra[u][i];
        if (dfn[t] == 0)///不在的继续递归
        {
            tarjan(t);///递归到头了就
            low[u] = min(low[u], low[t]);
        }
        else if (InStack[t] == 2)///在栈里
        {
            low[u] = min(low[u], dfn[t]);
        }
    }
    if(low[u] == dfn[u])///sta出栈就是一个强连通分量的
    {
        ++ComponentNumber;///强连通分量个数
        while (!sta.empty())
        {
            int j = sta.top();
            sta.pop();
            InStack[j] = 1;///已访问但不在栈中
            /* Component[ComponentNumber].push_back(j); */
            ///用vector存储第ComponentNumber个强连通分量
            InComponent[j]=ComponentNumber;
            dianquan2[ComponentNumber]+=dianquan[j];
            ///记录每个点在第几号强连通分量里
            num[ComponentNumber]++;
            if (j == u)
                break;
        }
    }
}
void input()
{
    int x,y;
    scanf("%d%d",&n,&m);

    repu(i,1,n+1)
    {
        scanf("%d",&dianquan[i]);
    }

    repu(i,1,m+1)
    {
        scanf("%d%d",&x,&y);        
        gra[x].push_back(y);///有向图才有强连通分量
    }
}

int dfs(int u){

    if(dp[u]){
        return dp[u];
    }
    else{
        dp[u] = dianquan2[u];
        for(size_t i = 0;i < Component[u].size();i++){
            int y = Component[u][i];
            dp[u] = max(dp[u],dfs(y)+dianquan2[u]);
        }
        return dp[u];
    }
}
void solve()
{
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);
    //缩点
    for(int i = 1;i <= n;i++){
        for(size_t j = 0;j < gra[i].size();j++){
            if(InComponent[i] != InComponent[gra[i][j]]){
                Component[InComponent[gra[i][j]]].push_back(InComponent[i]); 
            }
        }
    }
    int aans = 0;
    for(int i = 1;i <= ComponentNumber;i++){
        memset(dp,0,sizeof(dp));
        aans = max(dfs(i),aans);
        /* printf("%d ",dianquan2[i]); */
    }
    printf("%d\n",aans);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}
