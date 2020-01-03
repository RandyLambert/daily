#ifndef TU_ALOG_H_
#define TU_ALOG_H_

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include "myString.h" 
#include "Template_Tool.hpp"
using std::cout;
using std::cin;
using std::endl;
extern std::unordered_map<int, myString> mp;

class Kruskal
{
    friend class my_MySql;
private:
    static const int MAXN = 1100;   //最大点数
    static const int MAXM = 100000; //最大边数
    int tol;                        //边数,加边前赋值为 0
    int *F;                    //并查集使用
    struct Edge_Krus
    {
        int u, v, w;
        Edge_Krus(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
        bool operator<(const Edge_Krus &r)
        {
            return w < r.w;
        }
    } *edge_Krus; //存储边的信息,包括起点/终点/权值

    void Addedge_Krus(int u, int v, int w); //加边
    int find(int x);                        //并查集查找
    Kruskal();
    Kruskal(const Kruskal &x){}
    ~Kruskal();
    static Kruskal* kruskal;
public:
    int solve(int n); //传入点数,返回最小生成树的权值,如果不连通返回 -1
    static Kruskal * getInstance(){ return kruskal;};
};


/*****************************************************/

class Dijkstra
{
    friend class my_MySql;
private:
    static const int INF = 0x3f3f3f3f;
    static const int MAXN = 1100;   //最大点数
    static const int MAXM = 100000; //最大边数
    bool *vis;                 //标志有无
    int *dist;                 //最短路径
    struct Edge_Dijk
    {
        int v;
        int cost;
        Edge_Dijk(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
    };
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
    std::vector<Edge_Dijk> E_Dijk[MAXN];
    static Dijkstra * dijkstra;
    
    Dijkstra();
    Dijkstra(const Dijkstra &c){}
    ~Dijkstra();

    void Addedge_Dijk(int u, int v, int w); //加边
public:
    void solve(int n, int start); //点的编号从1开始
    void Print_All();
    void Print_Dan();
    static Dijkstra *getInstance(){return dijkstra; }
};


#endif
