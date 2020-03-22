/* 预备知识： */
/* 二叉树的存储。 */
/* 二叉树有很多存储方式，这里介绍一种竞赛中常用的方法。 */
/* 用数组来存二叉树的每个结点。 */
/* 每个父亲结点i(即A[i])的左右儿子分别为2*i(A[2*i])和2*i+1(A[2*i+1) */
/* 注意的点： */
/* 开四倍空间(2^k-1) */

#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN = 50010;
int sum[MAXN],lazy[MAXN];

/* 重要操作：Pushup */
/* 需要操作的地方：1.建树(build) 2.更新(update) */
/* 作用：将子结点的值向上传递给父结点。 */
void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}


/* 建树 */
/* 从根节点（一般设为1）不断二分构建左右子树 */
void build(int l,int r,int rt){
    //l == r时表示的区间为[l,r]，也就是单点
    //
    if(l == r){
        scanf("%d",&sum[rt]);
        return ;
    }

    int m = (l+r)>>1;
    build(lson); //lson l,m,rt<<1
    build(rson); //rson m+1,r,rt<<1|1
    pushup(rt); //勿忘
}


//单点更新
void update(int p,int add,int l,int r,int rt){
//同建树，此时为单点
    if(l==r) {
        sum[rt]+=add;
        return ;
    }
    int m = (l+r)>>1;
    //若p这个点在左子树，更新左子树
    if(p<=m) update(p,add,lson);
    //否则更新右子树
    else update(p,add,rson);
    //仍然需要pushup
    pushup(rt);
    
}


/* 区间查询[L,R]（针对单点更新） */
int query(int L,int R,int l,int r,int rt) {
    //当当前节点的区间[l,r]包含在[L,R]之内
    if(L<=l && r<=R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    int ret=0;
    //注意和更新的区别
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);

    return ret;
}

/* 进行区间更新，并保持复杂度不变 */
/* Lazy标记的引入。 */
/* Lazy标记标记的是当前点是否被修改。 */
/* 原本的单点更新，将更新的单点所影响的结点都进行了更新， */
/* 而Lazy标记则不进行更新，而是在更新或者查询的时候才将标记下传到子节点。 */

/* 为了完成将Lazy标记下传的操作，我们引入另一个和pushup相似的操作：Pushdown */
/* 左子树的区间长度为(m-(m>>1)) */
/* 右子树的区间长度为m>>1 */
void pushdown(int rt,int m){
    //是否有lazy标记
    if(lazy[rt]) {
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = lazy[rt]*(m-(m>>1));
        sum[rt<<1|1] = lazy[rt]*(m>>1);
        lazy[rt] = 0;
    }
}

int main()
{

    return 0;
}
