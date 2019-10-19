#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int fa[maxn];
bool vis[maxn];
vector <int> q[maxn];//q存的是问题
vector <int> g[maxn];//g存的是图

struct node{
    int x,y,lca;
}p[maxn];

int findf(int x){
    if(x == fa[x]) return x;
    else return fa[x] = findf(fa[x]); 
} 

void dfs(int u){//从树根开始遍历
    vis[u] = 1; //标记走过该点
    for(auto qid : q[u]){ //判断树该点的所有询问 qid为问题的id号
        if(p[qid].x == u){  //两个if判断该点创建询问节点时，u点存入的是x还是y
            if(vis[p[qid].y]){
                p[qid].lca = findf(p[qid].y);//判断之后发现是正确的，将答案输入，不正确的话退出
            }
        }
        else if(p[qid].y == u){
            if(vis[p[qid].x]){
                p[qid].lca = findf(p[qid].x);
            }
        }
    }
    for(auto v : g[u]){ //遍历整个子树
        if(vis[v]) //标记数组标记过的就不在进行第二次遍历
            continue;
        dfs(v);
        fa[v] = u; //必须等该点的所有子树全遍历完才能改这点的父节点为他的父节点，之前他的父节点是他自己
    }
}
int main()
{
    
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    int x,y;
    for(int i = 1;i < n;i++){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1;i <= m;i++ ){
        scanf("%d%d",&p[i].x,&p[i].y);
        q[p[i].x].push_back(i); //p表示的是询问，把询问的记号存下来
        q[p[i].y].push_back(i);
    }

    for(int i = 0;i <= n;i++){
        fa[i] = i;
    }

    dfs(s);

    for(int i = 1;i <= m;i++){
        printf("%d\n",p[i].lca);
    }

    return 0; 
}
