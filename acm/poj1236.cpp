#include <bits/stdc++.h>
using namespace std;
/*
 * Tarjan 算法
 * 复杂度 O(N+M)
 */
const int MAXN = 20010;//点数
const int MAXM = 50010;//边数
struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN]; /// 能追溯到的最早的次序
int DFN[MAXN]; /// 深度优先搜索访问次序
int Stack[MAXN]; //模拟栈
int Belong[MAXN];//Belong 数组的值是1 ∼ scc,代表每一个点所在的强连通点是哪一个
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN]; //判断是否在栈中
int num[MAXN];//各个强连通分量包含点的个数,数组编号 1 ∼ scc
//num 数组不一定需要,结合实际情况
void addedge(int u,int v){
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
vector<int> Component[MAXN]; /// 获得强连通分量结果
int iN[MAXN],out[MAXN];
void Tarjan(int u){
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u];i != - 1;i = edge[i].next){
        v = edge[i].to;
        if( !DFN[v] ){
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]){
        scc++;
        do{
            v = Stack[ -- top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
            Component[scc].push_back(v);
        }while( v != u);
    }
}
void solve(int N){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    memset(iN,0,sizeof(iN));
    memset(out,0,sizeof(out));

    Index = scc = top = 0;
    for(int i = 1;i <= N;i++)
        if(!DFN[i])
            Tarjan(i);
}
void init(){
    tot = 0;
    memset(head, - 1,sizeof(head));
}
int main(){
    int n,x;
    scanf("%d",&n);
    init();
    for(int i = 1;i <= n;i++){
        while(scanf("%d",&x)&&x){
            addedge(i,x);
        }
    }
    
    solve(n);
    if(scc == 1){
        printf("1\n0\n");
    }
    else{
        int in0 = 0,out0 = 0;
        for(int i = 1;i <= n;i++){
            for(size_t j = 0; j < Component[i].size();j++){
                int v = Component[i][j];
                if(num[i] != num[v]){
                    iN[i]++;
                    out[v]++;
                }
            }
        }

        for(int i = 1;i <= scc;i++){
            if(iN[i] == 0) in0++;
            if(out[i] == 0) out0++;
        }
        printf("%d\n%d\n",in0,max(in0,out0));
    }
    return 0;
}

