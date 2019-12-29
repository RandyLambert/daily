#ifndef TU_ALOG_H_
#define TU_ALOG_H_

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
const int MAXN = 1100;   //最大点数
const int MAXM = 100000; //最大边数
const int INF = 0x3f3f3f3f;
int F[MAXN]; //并查集使用

struct Edge_Krus
{
    int u, v, w;
    Edge_Krus(int _u = 0, int _v = 0,int _w = 0) : u(_u),v(_v), w(_w) {}
    bool operator<(const Edge_Krus &r){ 
        return w < r.w;
    }
} edge_Krus[MAXM]; //存储边的信息,包括起点/终点/权值
int tol;           //边数,加边前赋值为 0

struct Edge_Dijk
{
    int v;
    int cost;
    Edge_Dijk(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
std::vector<Edge_Dijk> E_Dijk[MAXN];

struct qnode
{
    int v;
    int c;
    qnode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator<(const qnode &r) const
    {
        return c > r.c;
    }
};
bool vis[MAXN];
int dist[MAXN];

void Addedge_Krus(int u, int v, int w); //加边
void Addedge_Dijk(int u, int v, int w); //加边

template <typename T>
bool cmp(T a, T b)
{ //排序函数
    return a < b;
}

int find(int x); //并查集查找

int Kruskal(int n); //传入点数,返回最小生成树的权值,如果不连通返回 -1

//点的编号从 1 开始
void Dijkstra(int n, int start);
#endif
