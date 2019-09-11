#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 101000
#define MAXM 201000

vector<int> vec[MAXN];//vector存储图
queue<int> que;//拓扑排序的队列
int n,m,u,v,ans;//ans记录答案
int in[MAXN],out[MAXN],f[MAXN];
//in数组记录入度
//out数组记录出度
//f数组记录到i这个点有多少条食物链

void topo_sort()//拓扑排序
{
    for (int i = 1 ; i <= n ; ++ i)
    {
        if (! in[i]) que.push(i),f[i] = 1;
        printf("%d\n",f[i]);
    }
    while (! que.empty())
    {
        int x = que.front();
        que.pop();
        for (int i = 0 ; i < vec[x].size() ; ++ i)
        {
            -- in[vec[x][i]];
            f[vec[x][i]] += f[x];
            if (! in[vec[x][i]] && ! out[vec[x][i]])//入度和出度都为0，++ ans
            {
                ans += f[vec[x][i]];
            }
            else if (! in[vec[x][i]])//入度为0，加入到队列里
            {
                que.push(vec[x][i]);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);//存边
        ++ in[v];++ out[u];
    }
    topo_sort();
    printf("%d", ans);//输出答案
    return 0;
}
