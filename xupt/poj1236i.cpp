///POJ1236
///时间复杂度也是O(N+M)
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <iostream>
#define repu(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#define N 105            /// 题目中可能的最大点数
stack<int>sta;            /// 存储已遍历的结点
vector<int>gra[N];        /// 邻接表表示图
int dfn[N];        /// 深度优先搜索访问次序
int low[N];        /// 能追溯到的最早的次序
int InStack[N];
/// 检查是否在栈中(2：在栈中，1：已访问，且不在栈中，0：不在)
vector<int> Component[N]; /// 获得强连通分量结果
int InComponent[N];          /// 记录每个点在第几号强连通分量里
int Index,ComponentNumber;/// 索引号，强连通分量个数
int n, m;          /// 点数，边数
int d[N][N],chu[N],ru[N];

void init()///清空容器，数组
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(chu, 0, sizeof(chu));
    memset(ru, 0, sizeof(ru));
    memset(InStack, 0, sizeof(InStack));
    Index = ComponentNumber = 0;
    for (int i = 1; i <= n; ++ i)
    {
        gra[i].clear();
        Component[i].clear();
    }
    repu(i,1,n+1)
    repu(j,1,n+1)
    d[i][j] = 0;
    while(!sta.empty())
        sta.pop();
}
void tarjan(int u)
{
    InStack[u] = 2;
    low[u] = dfn[u] = ++ Index;
    sta.push(u);///寻找u所在的强连通分量
    for (int i = 0; i < gra[u].size(); ++ i)
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
            Component[ComponentNumber].push_back(j);
            ///用vector存储第ComponentNumber个强连通分量
            InComponent[j]=ComponentNumber;
            ///记录每个点在第几号强连通分量里
            if (j == u)
                break;
        }
    }
}
void input()
{
    repu(i,1,n+1)
    {
        while(scanf("%d",&m) &&m)
            d[i][m] = 1,gra[i].push_back(m);///有向图才有强连通分量
    }
}

void solve(void)
{
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);
    if(ComponentNumber == 1)
    {
        printf("1\n0\n");
        return;
    }
    ///缩点
    for(int i=1; i<=ComponentNumber; i++)
    {
        for(int j = 0; j < Component[i].size(); j++)
        {
            for(int k = 1; k<=n; k++)
            {
                if(d[k][Component[i][j]] && k != Component[i][j])
                {
                    int s = InComponent[k];
                    int t = InComponent[Component[i][j]];
                    if(s!=t)
                    {
                        chu[s]++;
                        ru[t]++;
                    }
                }
            }
        }
    }
    int sum = 0,num = 0;
    for(int i=1; i<=ComponentNumber; i++)
    {
        if(!chu[i])
            sum++;
        if(!ru[i])
            num++;
    }
    printf("%d\n%d\n",num,max(sum,num));
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        input();
        solve();
        /*每一个强连通分量的具体数字
        for(int i = 1; i <= ComponentNumber; i++)
        {
            for(int j = 0; j < Component[i].size(); j++)
                if(!j)
                    cout << Component[i][j];
                else
                    cout <<"-->"<< Component[i][j];
            cout<<endl;
        }
        */
    }
    return 0;
}
